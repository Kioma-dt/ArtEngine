#ifndef FINDWIDGET_H
#define FINDWIDGET_H

#include <QWidget>
#include <stdexcept>
#include <QMessageBox>

namespace Ui {
class FindWidget;
}

class FindWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FindWidget(QWidget *parent = nullptr);
    ~FindWidget();

private:
    Ui::FindWidget *ui;

    QFont labelFont;


private slots:
    void SlotStart();
    void SlotExit();

signals:
    void SignalFind(int targetValue,  uintptr_t startAddress, uintptr_t endAddress);
};

#endif // FINDWIDGET_H
