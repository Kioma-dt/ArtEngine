#include "filtrwidget.h"
#include "ui_filtrwidget.h"

FiltrWidget::FiltrWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FiltrWidget)
{
    ui->setupUi(this);

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
            throw QException();
        }

        this->SlotExit();
        emit SignalFiltr(targetValue);
    }
    catch(const QException& ex){
        QMessageBox::warning(this, "Нельзя Начать Фильтрацию", ex.what());
    }
}

void FiltrWidget::SlotExit()
{
    ui->lineValue->clear();
    this->close();
}
