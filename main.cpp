#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qRegisterMetaType<std::vector<std::pair<uintptr_t, int> >>("std::vector<std::pair<uintptr_t, int>>");
    qRegisterMetaType<uintptr_t>("uintptr_t");
    qRegisterMetaType<DWORD>("DWORD");
    w.show();
    return a.exec();
}
