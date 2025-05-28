#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include <QTableWidget>
#include <QKeyEvent>
#include <vector>
#include <QHBoxLayout>
#include <windows.h>
#include <psapi.h>
#include <QRadioButton>
#include "findwidget.h"
#include "memoryreader.h"
#include "filtrwidget.h"
#include "globalkey.h"
#include "hotkeywidget.h"

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

    HotKey currentHotKey;

    FindWidget* findwidget;
    FiltrWidget* filtrwidget;
    HotKeyWidget* hotkeywidget;

    void PrintArrayToTable(const std::vector<std::pair<uintptr_t, int>>& array, QTableWidget *table, int addressColumn, int valueColumn);
    void GetArrayFromTable(std::vector<std::pair<uintptr_t, int>>& array, QTableWidget *table, int addressColumn, int valueColumn);

    QString GetHotKeyString(HotKey hotKey);

    DWORD GetProcessID();
private slots:
    void SlotSearch();
    void SlotFiltr();
    void SlotFix();
    void SlotUnFix();
    void SlotChange();
    void SlotUpdateProcesses();
    void SlotChangeHotKey();

    void SlotFindValue(int targetValue,  uintptr_t startAddress, uintptr_t endAddress);
    void SlotFiltrArray(int targetValue);
    void SlotReHot(bool ctrl, bool alt, bool shift, Qt::Key key);
};
#endif // MAINWINDOW_H
