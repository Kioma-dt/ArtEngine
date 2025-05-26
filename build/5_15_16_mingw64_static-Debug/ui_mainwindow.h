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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *buttonSearch;
    QPushButton *buttonFind;
    QTableWidget *tableFounded;
    QTableWidget *tableFixed;
    QPushButton *buttonFix;
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTextProcessID;
    QLineEdit *lineProcessID;
    QWidget *widget1;
    QVBoxLayout *layoutProgressBar;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelTextTimePass;
    QLabel *labelTimePass;
    QLabel *labelTextTimeLeft;
    QLabel *labelTimeLeft;
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
        buttonFind = new QPushButton(centralwidget);
        buttonFind->setObjectName(QString::fromUtf8("buttonFind"));
        buttonFind->setGeometry(QRect(200, 70, 161, 31));
        tableFounded = new QTableWidget(centralwidget);
        tableFounded->setObjectName(QString::fromUtf8("tableFounded"));
        tableFounded->setGeometry(QRect(30, 170, 321, 321));
        tableFixed = new QTableWidget(centralwidget);
        tableFixed->setObjectName(QString::fromUtf8("tableFixed"));
        tableFixed->setGeometry(QRect(440, 170, 331, 321));
        buttonFix = new QPushButton(centralwidget);
        buttonFix->setObjectName(QString::fromUtf8("buttonFix"));
        buttonFix->setGeometry(QRect(370, 250, 41, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(670, 510, 90, 29));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(420, 70, 209, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelTextProcessID = new QLabel(widget);
        labelTextProcessID->setObjectName(QString::fromUtf8("labelTextProcessID"));

        horizontalLayout->addWidget(labelTextProcessID);

        lineProcessID = new QLineEdit(widget);
        lineProcessID->setObjectName(QString::fromUtf8("lineProcessID"));

        horizontalLayout->addWidget(lineProcessID);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(50, 530, 461, 81));
        layoutProgressBar = new QVBoxLayout(widget1);
        layoutProgressBar->setObjectName(QString::fromUtf8("layoutProgressBar"));
        layoutProgressBar->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(widget1);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        layoutProgressBar->addWidget(progressBar);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelTextTimePass = new QLabel(widget1);
        labelTextTimePass->setObjectName(QString::fromUtf8("labelTextTimePass"));

        horizontalLayout_2->addWidget(labelTextTimePass);

        labelTimePass = new QLabel(widget1);
        labelTimePass->setObjectName(QString::fromUtf8("labelTimePass"));

        horizontalLayout_2->addWidget(labelTimePass);

        labelTextTimeLeft = new QLabel(widget1);
        labelTextTimeLeft->setObjectName(QString::fromUtf8("labelTextTimeLeft"));

        horizontalLayout_2->addWidget(labelTextTimeLeft);

        labelTimeLeft = new QLabel(widget1);
        labelTimeLeft->setObjectName(QString::fromUtf8("labelTimeLeft"));

        horizontalLayout_2->addWidget(labelTimeLeft);


        layoutProgressBar->addLayout(horizontalLayout_2);

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
        buttonFind->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\204\320\270\320\273\321\214\321\202\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        buttonFix->setText(QCoreApplication::translate("MainWindow", "Fix", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        labelTextProcessID->setText(QCoreApplication::translate("MainWindow", "ID \320\237\321\200\320\276\321\206\320\265\321\201\321\201\320\260: ", nullptr));
        labelTextTimePass->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\210\320\273\320\276 \320\222\321\200\320\265\320\274\320\265\320\275\320\270: ", nullptr));
        labelTimePass->setText(QString());
        labelTextTimeLeft->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\273\320\276\321\201\321\214 \320\222\321\200\320\265\320\274\320\265\320\275\320\270: ", nullptr));
        labelTimeLeft->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
