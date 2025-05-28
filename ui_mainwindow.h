/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *buttonSearch;
    QPushButton *buttonFiltr;
    QTableWidget *tableFounded;
    QTableWidget *tableFixed;
    QPushButton *buttonFix;
    QPushButton *buttonChange;
    QComboBox *comboBoxProcessID;
    QPushButton *buttonUpdateProcesses;
    QPushButton *buttonUnFix;
    QTextEdit *textHotKey;
    QPushButton *buttonChangeHotKey;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(864, 674);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        buttonSearch = new QPushButton(centralwidget);
        buttonSearch->setObjectName(QString::fromUtf8("buttonSearch"));
        buttonSearch->setGeometry(QRect(40, 70, 90, 29));
        buttonFiltr = new QPushButton(centralwidget);
        buttonFiltr->setObjectName(QString::fromUtf8("buttonFiltr"));
        buttonFiltr->setGeometry(QRect(200, 70, 161, 31));
        tableFounded = new QTableWidget(centralwidget);
        tableFounded->setObjectName(QString::fromUtf8("tableFounded"));
        tableFounded->setGeometry(QRect(30, 170, 321, 321));
        tableFixed = new QTableWidget(centralwidget);
        tableFixed->setObjectName(QString::fromUtf8("tableFixed"));
        tableFixed->setGeometry(QRect(440, 170, 331, 321));
        buttonFix = new QPushButton(centralwidget);
        buttonFix->setObjectName(QString::fromUtf8("buttonFix"));
        buttonFix->setGeometry(QRect(370, 250, 41, 41));
        buttonChange = new QPushButton(centralwidget);
        buttonChange->setObjectName(QString::fromUtf8("buttonChange"));
        buttonChange->setGeometry(QRect(670, 510, 90, 29));
        comboBoxProcessID = new QComboBox(centralwidget);
        comboBoxProcessID->setObjectName(QString::fromUtf8("comboBoxProcessID"));
        comboBoxProcessID->setGeometry(QRect(400, 70, 291, 31));
        buttonUpdateProcesses = new QPushButton(centralwidget);
        buttonUpdateProcesses->setObjectName(QString::fromUtf8("buttonUpdateProcesses"));
        buttonUpdateProcesses->setGeometry(QRect(700, 70, 151, 31));
        buttonUnFix = new QPushButton(centralwidget);
        buttonUnFix->setObjectName(QString::fromUtf8("buttonUnFix"));
        buttonUnFix->setGeometry(QRect(370, 340, 41, 41));
        textHotKey = new QTextEdit(centralwidget);
        textHotKey->setObjectName(QString::fromUtf8("textHotKey"));
        textHotKey->setGeometry(QRect(80, 540, 141, 41));
        textHotKey->setTextInteractionFlags(Qt::NoTextInteraction);
        buttonChangeHotKey = new QPushButton(centralwidget);
        buttonChangeHotKey->setObjectName(QString::fromUtf8("buttonChangeHotKey"));
        buttonChangeHotKey->setGeometry(QRect(290, 540, 221, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 864, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonSearch->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\272\320\260\321\202\321\214", nullptr));
        buttonFiltr->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\204\320\270\320\273\321\214\321\202\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        buttonFix->setText(QCoreApplication::translate("MainWindow", "Fix", nullptr));
        buttonChange->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        buttonUpdateProcesses->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 \320\237\321\200\320\276\321\206\320\265\321\201\321\201\321\213", nullptr));
        buttonUnFix->setText(QCoreApplication::translate("MainWindow", "UnFix", nullptr));
        buttonChangeHotKey->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \320\223\320\276\321\200\321\217\321\207\321\203\321\216 \320\232\320\273\320\260\320\262\320\270\321\210\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
