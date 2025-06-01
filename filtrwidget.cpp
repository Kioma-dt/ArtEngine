#include "filtrwidget.h"
#include "ui_filtrwidget.h"

FiltrWidget::FiltrWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FiltrWidget)
{
    ui->setupUi(this);
    this->setFixedSize(470, 320);

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

    connect(ui->buttonStart, &QPushButton::clicked, this, &FiltrWidget::SlotStart);
    connect(ui->buttonExit, &QPushButton::clicked, this, &FiltrWidget::SlotExit);
}

FiltrWidget::~FiltrWidget()
{
    delete ui;
}

void FiltrWidget::SlotStart()
{
    int targetValue;
    bool ok_value = true;

    try{
        targetValue = ui->lineValue->text().toInt(&ok_value);
        if(!ok_value){
            throw std::runtime_error("Неверный формат искомого числа");
        }

        this->SlotExit();
        emit SignalFiltr(targetValue);
    }
    catch(const std::runtime_error& ex){
        QMessageBox::warning(this, "Нельзя Начать Фильтрацию", ex.what());
    }
}

void FiltrWidget::SlotExit()
{
    ui->lineValue->clear();
    this->close();
}
