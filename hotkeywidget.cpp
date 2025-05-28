#include "hotkeywidget.h"
#include "ui_hotkeywidget.h"

HotKeyWidget::HotKeyWidget(bool ct, bool al, bool sh, Qt::Key k, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HotKeyWidget),
    ctrl(ct), alt(al), shift(sh), key(k)
{
    ui->setupUi(this);

    ui->checkAlt->setChecked(alt);
    ui->checkCtrl->setChecked(ctrl);
    ui->checkShift->setChecked(shift);
    ui->buttonGetHotKey->setText(QKeySequence(key).toString(QKeySequence::NativeText));

    connect(ui->buttonChange, &QPushButton::clicked, this, &HotKeyWidget::SlotChange);
    connect(ui->buttonExit, &QPushButton::clicked, this, &HotKeyWidget::SlotExit);
    connect(ui->buttonGetHotKey, &QPushButton::clicked, this, &HotKeyWidget::SlotGetHotKey);
}

HotKeyWidget::~HotKeyWidget()
{
    delete ui;
}

void HotKeyWidget::keyPressEvent(QKeyEvent *event)
{
    if(getingKey){
        key = static_cast<Qt::Key>(event->key());
        ui->buttonGetHotKey->setText(QKeySequence(key).toString(QKeySequence::NativeText));
        getingKey = false;
    }
}

void HotKeyWidget::SlotChange()
{
    this->SlotExit();
    ctrl = ui->checkCtrl->isChecked();
    alt = ui->checkAlt->isChecked();
    shift = ui->checkShift->isChecked();
    emit SignalChangeHotKey(ctrl, alt, shift, key);
}

void HotKeyWidget::SlotExit()
{
    this->close();
}

void HotKeyWidget::SlotGetHotKey()
{
    ui->buttonGetHotKey->setText("Введите клавишу");
    getingKey = true;
}
