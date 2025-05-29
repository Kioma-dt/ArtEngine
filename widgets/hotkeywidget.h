#ifndef HOTKEYWIDGET_H
#define HOTKEYWIDGET_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class HotKeyWidget;
}

class HotKeyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HotKeyWidget(bool ct, bool al, bool sh, Qt::Key k, QWidget *parent = nullptr);
    ~HotKeyWidget();

private:
    Ui::HotKeyWidget *ui;
    bool ctrl, alt, shift;
    Qt::Key key;
    bool getingKey = false;

    QFont labelFont;

    void keyPressEvent(QKeyEvent* event) override;

private slots:
    void SlotChange();
    void SlotExit();
    void SlotGetHotKey();

signals:
    void SignalChangeHotKey(bool ctrl, bool alt, bool shift, Qt::Key key);

};

#endif // HOTKEYWIDGET_H
