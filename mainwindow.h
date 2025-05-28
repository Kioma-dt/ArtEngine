#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include <QTableWidget>
#include <QKeyEvent>
#include <QThread>
#include <vector>
#include <windows.h>
#include <psapi.h>
#include <QRadioButton>
#include "findwidget.h"
#include "memoryreader.h"
#include "filtrwidget.h"
#include "globalkey.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<std::pair<uintptr_t, int>> addressFounded;
    std::vector<std::pair<uintptr_t, int>> addressFixed;
    std::vector<std::pair<QString, DWORD>> processes;

    MemoryReader* memoryReader;
    GlobalKey* globalKeyProcessor;
    QThread* threadFind;

    FindWidget* findwidget;
    FiltrWidget* filtrwidget;

    void ProgressBarHide();
    void ProgressBarShow();

    void PrintArrayToTable(const std::vector<std::pair<uintptr_t, int>>& array, QTableWidget *table, int addressColumn, int valueColumn);
    void GetArrayFromTable(std::vector<std::pair<uintptr_t, int>>& array, QTableWidget *table, int addressColumn, int valueColumn);

    DWORD GetProcessID();

    void keyPressEvent(QKeyEvent* event) override;

private slots:
    void SlotSearch();
    void SlotFiltr();
    void SlotFix();
    void SlotChange();
    void SlotUpdateProcesses();

    void SlotProgressBarUpdate(int percent);

    void SlotFinishFind(std::vector<std::pair<uintptr_t, int>> founded);

    void SlotFindValue(int targetValue,  uintptr_t startAddress, uintptr_t endAddress);
    void SlotFiltrArray(int targetValue);
};
#endif // MAINWINDOW_H
