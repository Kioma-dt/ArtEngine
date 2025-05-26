#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);

    addressFounded = std::vector<std::pair<uintptr_t, int>>();
    addressFixed = std::vector<std::pair<uintptr_t, int>>();
    findwidget = new FindWidget();
    filtrwidget = new FiltrWidget();

    ui->tableFounded->setColumnCount(3);
    ui->tableFounded->setHorizontalHeaderLabels(QStringList() << "" << "Адрес" << "Значение");

    ui->tableFixed->setColumnCount(4);
    ui->tableFixed->setHorizontalHeaderLabels(QStringList() << "" << "Название" << "Адрес" << "Значение");

    this->ProgressBarHide();

    connect(ui->buttonSearch, &QPushButton::clicked, this, &MainWindow::SlotSearch);
    connect(ui->buttonFiltr, &QPushButton::clicked, this, &MainWindow::SlotFiltr);
    connect(ui->buttonFix, &QPushButton::clicked, this, &MainWindow::SlotFix);
    connect(ui->buttonChange, &QPushButton::clicked, this, &MainWindow::SlotChange);

    connect(findwidget, &FindWidget::SignalFind, this, &MainWindow::SlotFindValue);
    connect(filtrwidget, &FiltrWidget::SignalFiltr, this, &MainWindow::SlotFiltrArray);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ProgressBarShow()
{
    ui->progressBar->show();
    ui->labelTextTimePass->show();
    ui->labelTextTimeLeft->show();
    ui->labelTimePass->show();
    ui->labelTimeLeft->show();
}

void MainWindow::ProgressBarHide()
{
    ui->progressBar->hide();
    ui->labelTextTimePass->hide();
    ui->labelTextTimeLeft->hide();
    ui->labelTimePass->hide();
    ui->labelTimeLeft->hide();
}


void MainWindow::PrintArrayToTable(const std::vector<std::pair<uintptr_t, int> > &array, QTableWidget* table, int addressColumn, int valueColumn)
{
    table->setRowCount(array.size());


    QTableWidgetItem* item;
    int row = 0;
    for(auto [address, value] : array){
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
    array.clear();
    QTableWidgetItem* item;
    uintptr_t address;
    int value;
    bool ok;
    for(int i = 0; i < table->rowCount(); i++){
        item = table->item(i, addressColumn);
        address = item->text().toULongLong(&ok, 16);
        item = table->item(i, valueColumn);
        value = item->text().toInt();
        array.push_back(std::make_pair(address, value));
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_L){
        this->SlotChange();
    }
}

void MainWindow::SlotSearch()
{
    try{
        bool ok_id = true;
        ui->lineProcessID->text().toULong(&ok_id);
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
        ui->lineProcessID->text().toULong(&ok_id);
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
    for(auto pair : addressFounded){
        addressFixed.push_back(pair);
    }
    this->PrintArrayToTable(addressFixed, ui->tableFixed, 2, 3);
}

void MainWindow::SlotChange()
{
    try{
        DWORD processID;
        bool ok_id = true;
        processID = ui->lineProcessID->text().toULong(&ok_id);
        if(!ok_id){
            throw QException();
        }

        HANDLE hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_ALL_ACCESS | PROCESS_QUERY_INFORMATION, FALSE, processID);
        if(hProcess == NULL){
            throw QException();
        }

        this->GetArrayFromTable(addressFixed, ui->tableFixed, 2, 3);
        MemoryReader::Write(hProcess, addressFixed);
    }
    catch(const QException& ex){
        QMessageBox::warning(this, "Нельзя изменить", ex.what());
    }
}

void MainWindow::SlotFindValue(int targetValue, uintptr_t startAddress, uintptr_t endAddress)
{
    try{
        DWORD processID;
        bool ok_id = true;
        processID = ui->lineProcessID->text().toULong(&ok_id);
        if(!ok_id){
            throw QException();
        }

        HANDLE hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_ALL_ACCESS | PROCESS_QUERY_INFORMATION, FALSE, processID);
        if(hProcess == NULL){
            throw QException();
        }

        addressFounded.clear();
        addressFounded = MemoryReader::Find(hProcess, targetValue, startAddress, endAddress);
        PrintArrayToTable(addressFounded, ui->tableFounded, 1, 2);
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
        processID = ui->lineProcessID->text().toULong(&ok_id);
        if(!ok_id){
            throw QException();
        }

        HANDLE hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_ALL_ACCESS | PROCESS_QUERY_INFORMATION, FALSE, processID);
        if(hProcess == NULL){
            throw QException();
        }

        addressFounded = MemoryReader::Filter(hProcess, addressFounded, targetValue);
        PrintArrayToTable(addressFounded, ui->tableFounded, 1, 2);
    }
    catch(const QException& ex){
        QMessageBox::warning(this, "Нельзя начать фильтрацию", ex.what());
    }
}

