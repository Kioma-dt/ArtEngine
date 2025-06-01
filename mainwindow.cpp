#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1400, 680);
    this->setWindowTitle("ArtEngine");
    this->setWindowIcon(QIcon("images/icon.ico"));

    ui->buttonSearch->setIcon(QIcon("images/loop.png"));
    ui->buttonFiltr->setIcon(QIcon("images/filtr.png"));
    ui->buttonChange->setIcon(QIcon("images/change.png"));
    ui->buttonChangeHotKey->setIcon(QIcon("images/hotkey.png"));
    ui->buttonFix->setIcon(QIcon("images/arrow.png"));
    ui->buttonUnFix->setIcon(QIcon("images/crossed.png"));

    labelFont.setPointSize(12);
    buttonFont.setPointSize(10);
    buttonFont.setBold(true);
    tableFont.setPointSize(12);

    ui->labelHotKey->setFont(labelFont);
    ui->labelHotKey->setAlignment(Qt::AlignCenter);
    ui->labelTextHotKey->setFont(labelFont);
    ui->comboBoxProcessID->setFont(labelFont);

    QString buttonStyle = R"(
    QPushButton {
        background-color: rgb(100, 150, 200);
        color: white;
        border: none;
        border-radius: 8px;
        padding: 8px 16px;
        font-size: 16px;
        font-weight: bold;
    }

    QPushButton:hover {
        background-color: rgb(70, 110, 150);
    }

    QPushButton:pressed {
        background-color: rgb(30, 70, 110);
    }

    QPushButton:disabled {
        background-color: rgb(100, 100, 100);
        color: rgb(180, 180, 180);
    }
    )";
    ui->buttonSearch->setStyleSheet(buttonStyle);
    ui->buttonFiltr->setStyleSheet(buttonStyle);
    ui->buttonChange->setStyleSheet(buttonStyle);
    ui->buttonChangeHotKey->setStyleSheet(buttonStyle);
    ui->buttonUpdateProcesses->setStyleSheet(buttonStyle);
    ui->buttonFix->setStyleSheet(buttonStyle);
    ui->buttonUnFix->setStyleSheet(buttonStyle);

    QString tableStyle = R"(
    QHeaderView::section {
        background-color: rgb(0, 72, 128);
        color: rgb(252, 209, 22);
        padding: 4px;
        border: 1px solid rgb(30, 30, 30);
        font-size: 20px;
        font-weight: bold;
    }
    )";
    ui->tableFounded->setStyleSheet(tableStyle);
    ui->tableFixed->setStyleSheet(tableStyle);
    ui->tableFixed->setFont(tableFont);
    ui->tableFounded->setFont(tableFont);

    QString comboBoxStyle = (R"(
    QComboBox {
        background-color: rgb(0, 72, 128);
        color: rgb(252, 209, 22);
        border: 1px solid rgb(50, 70, 100);
        padding: 4px;
        font-size: 20px;
        font-weight: bold;
        border-radius: 4px;
    }

    QComboBox QAbstractItemView {
        background-color: rgb(70, 100, 130);
        color: rgb(252, 209, 22);
        selection-background-color: rgb(90, 120, 150);
        selection-color: yellow;
        font-size: 20px;
    }
    )");
    ui->comboBoxProcessID->setStyleSheet(comboBoxStyle);


    memoryReader = new MemoryReader();

    globalKeyProcessor = new GlobalKey(this);
    globalKeyProcessor->installHook();
    connect(globalKeyProcessor, &GlobalKey::SignalHotKeyPressed, this, &MainWindow::SlotChange);

    addressFounded = std::vector<std::pair<uintptr_t, int>>();
    addressFixed = std::vector<std::pair<uintptr_t, int>>();
    processes = std::vector<std::pair<QString, DWORD>>();
    findwidget = new FindWidget();
    findwidget->setWindowTitle("Поиск");
    filtrwidget = new FiltrWidget();
    filtrwidget->setWindowTitle("Фильтрация");

    currentHotKey.ctrl = 0;
    currentHotKey.alt = 1;
    currentHotKey.shift = 0;
    currentHotKey.key = Qt::Key_F4;
    globalKeyProcessor->setCurrentHotKey(currentHotKey);
    ui->labelHotKey->setText(this->GetHotKeyString(currentHotKey));

    hotkeywidget = new HotKeyWidget(currentHotKey.ctrl, currentHotKey.alt, currentHotKey.shift, currentHotKey.key);
    hotkeywidget->setWindowTitle("Горячая Клавиша");

    ui->tableFounded->setColumnCount(3);
    ui->tableFounded->setHorizontalHeaderLabels(QStringList() << "" << "Адрес" << "Значение");
    ui->tableFounded->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableFounded->horizontalHeader()->setStretchLastSection(true);
    ui->tableFounded->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableFounded->resizeColumnsToContents();
    ui->tableFounded->resizeRowsToContents();
    ui->tableFounded->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    ui->tableFixed->setColumnCount(4);
    ui->tableFixed->setHorizontalHeaderLabels(QStringList() << "" << "Название" << "Адрес" << "Значение");
    ui->tableFixed->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableFixed->horizontalHeader()->setStretchLastSection(true);
    ui->tableFixed->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableFixed->resizeColumnsToContents();
    ui->tableFixed->resizeRowsToContents();
    ui->tableFixed->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    this->SlotUpdateProcesses();

    connect(ui->buttonSearch, &QPushButton::clicked, this, &MainWindow::SlotSearch);
    connect(ui->buttonFiltr, &QPushButton::clicked, this, &MainWindow::SlotFiltr);
    connect(ui->buttonFix, &QPushButton::clicked, this, &MainWindow::SlotFix);
    connect(ui->buttonUnFix, &QPushButton::clicked, this, &MainWindow::SlotUnFix);
    connect(ui->buttonChange, &QPushButton::clicked, this, &MainWindow::SlotChange);
    connect(ui->buttonUpdateProcesses, &QPushButton::clicked, this, &MainWindow::SlotUpdateProcesses);
    connect(ui->buttonChangeHotKey, &QPushButton::clicked, this, &MainWindow::SlotChangeHotKey);

    connect(findwidget, &FindWidget::SignalFind, this, &MainWindow::SlotFindValue);
    connect(filtrwidget, &FiltrWidget::SignalFiltr, this, &MainWindow::SlotFiltrArray);
    connect(hotkeywidget, &HotKeyWidget::SignalChangeHotKey, this, &MainWindow::SlotReHot);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PrintArrayToTable(const std::vector<std::pair<uintptr_t, int> > &array, QTableWidget* table, int addressColumn, int valueColumn, bool add)
{
    QTableWidgetItem* item;
    int row;

    if(!add){
        table->clearContents();
        table->setRowCount(array.size());
        row = 0;
    }
    else{
        row = table->rowCount();
        table->setRowCount(row + array.size());
    }


    for(auto [address, value] : array){
        QRadioButton* temp_button = new QRadioButton();
        QWidget* cell_widget = new QWidget();
        QHBoxLayout* temp_layout = new QHBoxLayout(cell_widget);
        temp_layout->addWidget(temp_button);
        temp_layout->setAlignment(Qt::AlignCenter);
        temp_layout->setContentsMargins(0,0,0,0);
        cell_widget->setLayout(temp_layout);
        table->setCellWidget(row, 0, cell_widget);

        item = new QTableWidgetItem(QString::number(address, 16).toUpper());
        item->setTextAlignment(Qt::AlignCenter);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        table->setItem(row, addressColumn, item);

        item = new QTableWidgetItem(QString::number(value));
        item->setTextAlignment(Qt::AlignCenter);
        table->setItem(row, valueColumn, item);

        if(table != ui->tableFixed){
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        }

        row++;
    }
}

void MainWindow::GetArrayFromTable(std::vector<std::pair<uintptr_t, int> > &array, QTableWidget *table, int addressColumn, int valueColumn, bool all)
{
    QTableWidgetItem* item;
    uintptr_t address;
    int value;
    bool ok_addr = true;
    bool ok_value = true;


    for(int i = 0; i < table->rowCount(); i++){
        QWidget* cell_widget = table->cellWidget(i, 0);
        QRadioButton* radioButton = cell_widget->findChild<QRadioButton*>();
        if(radioButton->isChecked() || all){
            item = table->item(i, addressColumn);
            address = item->text().toULongLong(&ok_addr, 16);
            item = table->item(i, valueColumn);
            value = item->text().toInt(&ok_value);
            if(!ok_value && !all){
                throw std::runtime_error(QString("Неверное значение в ячейке с номером %0").arg(i + 1).toStdString());
            }
            array.push_back(std::make_pair(address, value));
        }
    }
}

QString MainWindow::GetHotKeyString(HotKey hotKey)
{
    QString hotKeyString = "";
    if(hotKey.ctrl){
        hotKeyString += "CTRL + ";
    }
    if(hotKey.alt){
        hotKeyString += "ALT + ";
    }
    if(hotKey.shift){
        hotKeyString += "SHIFT + ";
    }
    hotKeyString += QKeySequence(hotKey.key).toString(QKeySequence::NativeText);

    return hotKeyString;
}

DWORD MainWindow::GetProcessID()
{
    size_t index = ui->comboBoxProcessID->currentIndex();
    if(processes.size() <= index){
        throw std::runtime_error("Неверное ID процесса (Поробуйте Обновить Процессы)");
    }
    return processes.at(index).second;
}
void MainWindow::SlotSearch()
{
    findwidget->setWindowModality(Qt::ApplicationModal);
    findwidget->show();
}

void MainWindow::SlotFiltr()
{
    filtrwidget->setWindowModality(Qt::ApplicationModal);
    filtrwidget->show();
}

void MainWindow::SlotFix()
{
    addressFixed.clear();
    this->GetArrayFromTable(addressFixed, ui->tableFounded, 1, 2);
    this->PrintArrayToTable(addressFixed, ui->tableFixed, 2, 3, true);
}

void MainWindow::SlotUnFix()
{
    int i = 0;
    while(i < ui->tableFixed->rowCount()){
        QWidget* cell_widget = ui->tableFixed->cellWidget(i, 0);
        QRadioButton* radioButton = cell_widget->findChild<QRadioButton*>();
        if(radioButton->isChecked()){
            ui->tableFixed->removeRow(i);
        }
        else{
            i++;
        }
    }
}

void MainWindow::SlotChange()
{
    try{
        DWORD processID;
        processID = this->GetProcessID();

        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
        if(hProcess == NULL){
            throw std::runtime_error("Не удалось открыть процесс (Попробуйте запустить приложение от имени администратора)");
        }

        std::vector<std::pair<uintptr_t, int>>temp_vector;
        this->GetArrayFromTable(temp_vector, ui->tableFixed, 2, 3);
        memoryReader->Write(hProcess, temp_vector);

        CloseHandle(hProcess);
    }
    catch(const std::runtime_error& ex){
        QMessageBox::warning(this, "Нельзя изменить", ex.what());
    }
}

void MainWindow::SlotUpdateProcesses()
{
    processes = memoryReader->GetAllProcesses();
    ui->comboBoxProcessID->clear();

    for(auto process : processes){
        QString item = QString("%1 PID: %2").arg(process.first).arg(process.second);
        ui->comboBoxProcessID->addItem(item);
    }
}

void MainWindow::SlotChangeHotKey()
{
    hotkeywidget->setWindowModality(Qt::ApplicationModal);
    hotkeywidget->show();
}


void MainWindow::SlotFindValue(int targetValue, uintptr_t startAddress, uintptr_t endAddress)
{
    try{
        DWORD processID;
        processID = this->GetProcessID();

        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
        if(hProcess == NULL){
            throw std::runtime_error("Не удалось открыть процесс (Попробуйте запустить приложение от имени администратора)");
        }

        addressFounded = memoryReader->Find(hProcess, targetValue, startAddress, endAddress);
        this->PrintArrayToTable(addressFounded, ui->tableFounded, 1, 2);
        CloseHandle(hProcess);
    }
    catch(const std::runtime_error& ex){
        QMessageBox::warning(this, "Нельзя начать поиск", ex.what());
    }
}

void MainWindow::SlotFiltrArray(int targetValue)
{
    try{
        DWORD processID;
        processID = this->GetProcessID();

        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
        if(hProcess == NULL){
            throw std::runtime_error("Не удалось открыть процесс (Попробуйте запустить приложение от имени администратора)");
        }

        addressFounded = memoryReader->Filter(hProcess, addressFounded, targetValue);
        PrintArrayToTable(addressFounded, ui->tableFounded, 1, 2);

        CloseHandle(hProcess);
    }
    catch(const std::runtime_error& ex){
        QMessageBox::warning(this, "Нельзя начать фильтрацию", ex.what());
    }
}

void MainWindow::SlotReHot(bool ctrl, bool alt, bool shift, Qt::Key key)
{
    currentHotKey.ctrl = ctrl;
    currentHotKey.alt = alt;
    currentHotKey.shift = shift;
    currentHotKey.key = key;

    globalKeyProcessor->setCurrentHotKey(currentHotKey);
    ui->labelHotKey->setText(this->GetHotKeyString(currentHotKey));
}

