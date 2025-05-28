#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    memoryReader = new MemoryReader();

    globalKeyProcessor = new GlobalKey(this);
    globalKeyProcessor->installHook();
    connect(globalKeyProcessor, &GlobalKey::SignalHotKeyPressed, this, &MainWindow::SlotChange);

    addressFounded = std::vector<std::pair<uintptr_t, int>>();
    addressFixed = std::vector<std::pair<uintptr_t, int>>();
    processes = std::vector<std::pair<QString, DWORD>>();
    findwidget = new FindWidget();
    filtrwidget = new FiltrWidget();

    currentHotKey.ctrl = 0;
    currentHotKey.alt = 1;
    currentHotKey.shift = 0;
    currentHotKey.key = Qt::Key_F4;
    globalKeyProcessor->setCurrentHotKey(currentHotKey);
    ui->textHotKey->setText(this->GetHotKeyString(currentHotKey));

    hotkeywidget = new HotKeyWidget(currentHotKey.ctrl, currentHotKey.alt, currentHotKey.shift, currentHotKey.key);

    ui->tableFounded->setColumnCount(3);
    ui->tableFounded->setHorizontalHeaderLabels(QStringList() << "" << "Адрес" << "Значение");
    ui->tableFounded->resizeColumnsToContents();
    ui->tableFounded->resizeRowsToContents();
    ui->tableFounded->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableFounded->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ui->tableFixed->setColumnCount(4);
    ui->tableFixed->setHorizontalHeaderLabels(QStringList() << "" << "Название" << "Адрес" << "Значение");    
    ui->tableFixed->resizeColumnsToContents();
    ui->tableFixed->resizeRowsToContents();
    ui->tableFixed->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableFixed->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

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

void MainWindow::PrintArrayToTable(const std::vector<std::pair<uintptr_t, int> > &array, QTableWidget* table, int addressColumn, int valueColumn)
{
    table->setRowCount(array.size());


    QTableWidgetItem* item;
    int row = 0;
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

void MainWindow::GetArrayFromTable(std::vector<std::pair<uintptr_t, int> > &array, QTableWidget *table, int addressColumn, int valueColumn)
{
    QTableWidgetItem* item;
    uintptr_t address;
    int value;
    bool ok;


    for(int i = 0; i < table->rowCount(); i++){
        QWidget* cell_widget = table->cellWidget(i, 0);
        QRadioButton* radioButton = cell_widget->findChild<QRadioButton*>();
        if(radioButton->isChecked()){
            item = table->item(i, addressColumn);
            address = item->text().toULongLong(&ok, 16);
            item = table->item(i, valueColumn);
            value = item->text().toInt();
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
    int index = ui->comboBoxProcessID->currentIndex();
    return processes.at(index).second;
}
void MainWindow::SlotSearch()
{
    try{
        bool ok_id = true;
        if(!ok_id){
            throw QException();
        }
        findwidget->show();
    }
    catch(const QException& ex){
        QMessageBox::warning(this, "Нельзя начать поиск", ex.what());
    }
}

void MainWindow::SlotFiltr()
{
    try{
        bool ok_id = true;
        if(!ok_id){
            throw QException();
        }
        filtrwidget->show();
    }
    catch(const QException& ex){
        QMessageBox::warning(this, "Нельзя начать поиск", ex.what());
    }
}

void MainWindow::SlotFix()
{
    this->GetArrayFromTable(addressFixed, ui->tableFounded, 1, 2);
    this->PrintArrayToTable(addressFixed, ui->tableFixed, 2, 3);
}

void MainWindow::SlotUnFix()
{
    addressFixed.clear();
    QTableWidgetItem* item;
    uintptr_t address;
    int value;
    bool ok;

    for(int i = 0; i < ui->tableFixed->rowCount(); i++){
        QWidget* cell_widget = ui->tableFixed->cellWidget(i, 0);
        QRadioButton* radioButton = cell_widget->findChild<QRadioButton*>();
        if(!radioButton->isChecked()){
            item = ui->tableFixed->item(i, 2);
            address = item->text().toULongLong(&ok, 16);
            item = ui->tableFixed->item(i, 3);
            value = item->text().toInt();
            addressFixed.push_back(std::make_pair(address, value));
        }
    }

    this->PrintArrayToTable(addressFixed, ui->tableFixed, 2, 3);
}

void MainWindow::SlotChange()
{
    try{
        DWORD processID;
        bool ok_id = true;
        processID = this->GetProcessID();
        if(!ok_id){
            throw QException();
        }

        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
        if(hProcess == NULL){
            throw QException();
        }

        std::vector<std::pair<uintptr_t, int>>temp_vector;
        this->GetArrayFromTable(temp_vector, ui->tableFixed, 2, 3);
        memoryReader->Write(hProcess, temp_vector);

        CloseHandle(hProcess);
    }
    catch(const QException& ex){
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
    hotkeywidget->show();
}


void MainWindow::SlotFindValue(int targetValue, uintptr_t startAddress, uintptr_t endAddress)
{
    try{
        DWORD processID;
        bool ok_id = true;
        processID = this->GetProcessID();
        if(!ok_id){
            throw QException();
        }

        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
        if(hProcess == NULL){
            throw QException();
        }

        addressFounded = memoryReader->Find(hProcess, targetValue, startAddress, endAddress);
        this->PrintArrayToTable(addressFounded, ui->tableFounded, 1, 2);
        CloseHandle(hProcess);
    }
    catch(const QException& ex){
        QMessageBox::warning(this, "Нельзя начать поиск", ex.what());
    }
}

void MainWindow::SlotFiltrArray(int targetValue)
{
    try{
        DWORD processID;
        bool ok_id = true;
        processID = this->GetProcessID();
        if(!ok_id){
            throw QException();
        }

        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
        if(hProcess == NULL){
            throw QException();
        }

        addressFounded = memoryReader->Filter(hProcess, addressFounded, targetValue);
        PrintArrayToTable(addressFounded, ui->tableFounded, 1, 2);

        CloseHandle(hProcess);
    }
    catch(const QException& ex){
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
    ui->textHotKey->setText(this->GetHotKeyString(currentHotKey));
}

