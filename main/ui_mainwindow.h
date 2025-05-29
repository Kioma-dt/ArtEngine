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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QLabel *labelIcon;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tableFounded;
    QVBoxLayout *verticalLayout;
    QPushButton *buttonFix;
    QPushButton *buttonUnFix;
    QTableWidget *tableFixed;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBoxProcessID;
    QPushButton *buttonUpdateProcesses;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTextHotKey;
    QLabel *labelHotKey;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonChangeHotKey;
    QPushButton *buttonSearch;
    QPushButton *buttonFiltr;
    QPushButton *buttonChange;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 680);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelIcon = new QLabel(centralwidget);
        labelIcon->setObjectName(QString::fromUtf8("labelIcon"));
        labelIcon->setGeometry(QRect(40, 30, 141, 111));
        labelIcon->setPixmap(QPixmap(QString::fromUtf8("images/icon.ico")));
        labelIcon->setScaledContents(true);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 150, 1211, 371));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        tableFounded = new QTableWidget(widget);
        tableFounded->setObjectName(QString::fromUtf8("tableFounded"));

        horizontalLayout_4->addWidget(tableFounded);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        buttonFix = new QPushButton(widget);
        buttonFix->setObjectName(QString::fromUtf8("buttonFix"));

        verticalLayout->addWidget(buttonFix);

        buttonUnFix = new QPushButton(widget);
        buttonUnFix->setObjectName(QString::fromUtf8("buttonUnFix"));

        verticalLayout->addWidget(buttonUnFix);


        horizontalLayout_4->addLayout(verticalLayout);

        tableFixed = new QTableWidget(widget);
        tableFixed->setObjectName(QString::fromUtf8("tableFixed"));

        horizontalLayout_4->addWidget(tableFixed);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(190, 30, 1061, 111));
        horizontalLayout_5 = new QHBoxLayout(widget1);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        comboBoxProcessID = new QComboBox(widget1);
        comboBoxProcessID->setObjectName(QString::fromUtf8("comboBoxProcessID"));

        horizontalLayout_5->addWidget(comboBoxProcessID);

        buttonUpdateProcesses = new QPushButton(widget1);
        buttonUpdateProcesses->setObjectName(QString::fromUtf8("buttonUpdateProcesses"));

        horizontalLayout_5->addWidget(buttonUpdateProcesses);

        horizontalLayout_5->setStretch(0, 10);
        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(41, 541, 1211, 71));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelTextHotKey = new QLabel(widget2);
        labelTextHotKey->setObjectName(QString::fromUtf8("labelTextHotKey"));

        horizontalLayout->addWidget(labelTextHotKey);

        labelHotKey = new QLabel(widget2);
        labelHotKey->setObjectName(QString::fromUtf8("labelHotKey"));

        horizontalLayout->addWidget(labelHotKey);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        buttonChangeHotKey = new QPushButton(widget2);
        buttonChangeHotKey->setObjectName(QString::fromUtf8("buttonChangeHotKey"));

        horizontalLayout_2->addWidget(buttonChangeHotKey);

        buttonSearch = new QPushButton(widget2);
        buttonSearch->setObjectName(QString::fromUtf8("buttonSearch"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        buttonSearch->setPalette(palette);

        horizontalLayout_2->addWidget(buttonSearch);

        buttonFiltr = new QPushButton(widget2);
        buttonFiltr->setObjectName(QString::fromUtf8("buttonFiltr"));

        horizontalLayout_2->addWidget(buttonFiltr);

        buttonChange = new QPushButton(widget2);
        buttonChange->setObjectName(QString::fromUtf8("buttonChange"));

        horizontalLayout_2->addWidget(buttonChange);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 25));
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
        labelIcon->setText(QString());
        buttonFix->setText(QString());
        buttonUnFix->setText(QString());
        buttonUpdateProcesses->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 \320\237\321\200\320\276\321\206\320\265\321\201\321\201\321\213", nullptr));
        labelTextHotKey->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\223\320\276\321\200\321\217\321\207\320\260\321\217 \320\232\320\273\320\260\320\262\320\270\321\210\320\260: ", nullptr));
        labelHotKey->setText(QCoreApplication::translate("MainWindow", "label hotkey", nullptr));
        buttonChangeHotKey->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \320\223\320\276\321\200\321\217\321\207\321\203\321\216 \320\232\320\273\320\260\320\262\320\270\321\210\321\203", nullptr));
        buttonSearch->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\272\320\260\321\202\321\214", nullptr));
        buttonFiltr->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\204\320\270\320\273\321\214\321\202\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        buttonChange->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
