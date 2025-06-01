#include "findwidget.h"
#include "ui_findwidget.h"

FindWidget::FindWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FindWidget)
{
    ui->setupUi(this);
    this->setFixedSize(570, 330);

    ui->lineStartAddress->setText(QString::number(0x000000000000, 16).toUpper());
    ui->lineEndAddress->setText(QString::number(0x7fffffffffff, 16).toUpper());

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
    ui->buttonExit->setStyleSheet(buttonStyle);
    ui->buttonStart->setStyleSheet(buttonStyle);

    labelFont.setPointSize(14);
    ui->labelTextValue->setFont(labelFont);
    ui->lineValue->setFont(labelFont);
    ui->labelTextStart->setFont(labelFont);
    ui->lineStartAddress->setFont(labelFont);
    ui->labelTextEnd->setFont(labelFont);
    ui->lineEndAddress->setFont(labelFont);

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
            throw std::runtime_error("Неверный формат искомого значения");
        }
        startAddressUser = ui->lineStartAddress->text().toULongLong(&ok_start, 16);
        if(!ok_start){
            throw std::runtime_error("Неверный формат начального адреса");
        }
        endAddressUser = ui->lineEndAddress->text().toULongLong(&ok_end, 16);
        if(!ok_end){
            throw std::runtime_error("Неверный формат конечного адреса");
        }

        if(startAddressUser > endAddressUser){
            throw std::runtime_error("Начальный адрес должен быть не больше конечного");
        }

        startAddress = startAddress >= startAddressUser ? startAddress : startAddressUser;
        endAddress = endAddress <= endAddressUser ? endAddress : endAddressUser;

        this->SlotExit();
        emit SignalFind(targetValue, startAddress, endAddress);
    }
    catch(const std::runtime_error& ex){
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
