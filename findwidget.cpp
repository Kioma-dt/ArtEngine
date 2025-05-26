#include "findwidget.h"
#include "ui_findwidget.h"

FindWidget::FindWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FindWidget)
{
    ui->setupUi(this);

    ui->lineStartAddress->setText(QString::number(0x000000000000, 16).toUpper());
    ui->lineEndAddress->setText(QString::number(0x7fffffffffff, 16).toUpper());

    connect(ui->buttonStart, &QPushButton::clicked, this, &FindWidget::SlotStart);
    connect(ui->buttonExit, &QPushButton::clicked, this, &FindWidget::SlotExit);
}

FindWidget::~FindWidget()
{
    delete ui;
}

void FindWidget::SlotStart()
{
    int targetValue;
    uintptr_t startAddressUser, endAddressUser;
    uintptr_t startAddress = 0x000000000000;
    uintptr_t endAddress =   0x7fffffffffff;
    bool ok_value = true, ok_start = true, ok_end = true;

    try{
        targetValue = ui->lineValue->text().toInt(&ok_value);
        if(!ok_value){
            throw QException();
        }
        startAddressUser = ui->lineStartAddress->text().toULongLong(&ok_start, 16);
        if(!ok_start){
            throw QException();
        }
        endAddressUser = ui->lineEndAddress->text().toULongLong(&ok_end, 16);
        if(!ok_end){
            throw QException();
        }

        startAddress = startAddress >= startAddressUser ? startAddress : startAddressUser;
        endAddress = endAddress <= endAddressUser ? endAddress : endAddressUser;

        this->SlotExit();
        emit SignalFind(targetValue, startAddress, endAddress);
    }
    catch(const QException& ex){
        QMessageBox::warning(this, "Нельзя Начать Поиск", ex.what());
    }
}

void FindWidget::SlotExit()
{
    ui->lineStartAddress->setText(QString::number(0x000000000000, 16).toUpper());
    ui->lineEndAddress->setText(QString::number(0x7fffffffffff, 16).toUpper());
    ui->lineValue->clear();
    this->close();
}
