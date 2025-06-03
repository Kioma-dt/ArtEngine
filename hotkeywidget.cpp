#include "hotkeywidget.h"
#include "ui_hotkeywidget.h"

HotKeyWidget::HotKeyWidget(bool ct, bool al, bool sh, Qt::Key k, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HotKeyWidget),
    ctrl(ct), alt(al), shift(sh), key(k)
{
    ui->setupUi(this);
    this->setFixedSize(600, 420);

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
    ui->buttonChange->setStyleSheet(buttonStyle);
    ui->buttonExit->setStyleSheet(buttonStyle);

    QString keyboardCaptureButtonStyle = R"(
    QPushButton {
        background-color: rgb(60, 90, 120);
        color: rgb(252, 209, 22);
        border: none;
        border-radius: 8px;
        padding: 8px 16px;
        font-size: 20px;
        font-weight: bold;
    }

    QPushButton:hover {
        background-color: rgb(45, 75, 105);
    }

    QPushButton:pressed {
        background-color: rgb(20, 45, 70);
    }

    QPushButton:disabled {
        background-color: rgb(70, 70, 70);
        color: rgb(150, 150, 150);
    }
    )";
    ui->buttonGetHotKey->setStyleSheet(keyboardCaptureButtonStyle);


    labelFont.setPointSize(14);
    ui->checkCtrl->setFont(labelFont);
    ui->checkAlt->setFont(labelFont);
    ui->checkShift->setFont(labelFont);

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
    if (event->key() == Qt::Key_Shift || event->key() == Qt::Key_Control ||
        event->key() == Qt::Key_Alt || event->key() == Qt::Key_Meta ||
        event->key() == Qt::Key_CapsLock || event->key() == Qt::Key_NumLock ||
        event->key() == Qt::Key_ScrollLock || event->key() == Qt::Key_Space) {
        return;
    }
    if(getingKey && event->key()){
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

    if (key == Qt::Key(0)) {
        QMessageBox::warning(this, "Нельзя поменять горячую клавишу", "Необходимо выбрать клавишу.");
        return;
    }


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
