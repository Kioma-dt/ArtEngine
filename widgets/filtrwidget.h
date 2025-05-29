#ifndef FILTRWIDGET_H
#define FILTRWIDGET_H

#include <QWidget>
#include <stdexcept>
#include <QMessageBox>

namespace Ui {
class FiltrWidget;
}

class FiltrWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FiltrWidget(QWidget *parent = nullptr);
    ~FiltrWidget();

private:
    Ui::FiltrWidget *ui;

    QFont labelFont;

private slots:
    void SlotStart();
    void SlotExit();

signals:
    void SignalFiltr(int targetValue);
};

#endif // FILTRWIDGET_H
