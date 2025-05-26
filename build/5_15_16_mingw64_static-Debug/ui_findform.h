/********************************************************************************
** Form generated from reading UI file 'findform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDFORM_H
#define UI_FINDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindWindow
{
public:
    QPushButton *buttonStart;
    QPushButton *buttonExit;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelTextValue;
    QLineEdit *lineValue;
    QLabel *labelTextStart;
    QLineEdit *lineStartAddress;
    QLabel *labelTextEnd;
    QLineEdit *lineEndAddress;

    void setupUi(QWidget *FindWindow)
    {
        if (FindWindow->objectName().isEmpty())
            FindWindow->setObjectName(QString::fromUtf8("FindWindow"));
        FindWindow->resize(467, 422);
        buttonStart = new QPushButton(FindWindow);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        buttonStart->setGeometry(QRect(50, 330, 121, 31));
        buttonExit = new QPushButton(FindWindow);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));
        buttonExit->setGeometry(QRect(250, 330, 90, 29));
        layoutWidget = new QWidget(FindWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 60, 371, 231));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelTextValue = new QLabel(layoutWidget);
        labelTextValue->setObjectName(QString::fromUtf8("labelTextValue"));

        gridLayout->addWidget(labelTextValue, 0, 0, 1, 2);

        lineValue = new QLineEdit(layoutWidget);
        lineValue->setObjectName(QString::fromUtf8("lineValue"));

        gridLayout->addWidget(lineValue, 0, 2, 1, 1);

        labelTextStart = new QLabel(layoutWidget);
        labelTextStart->setObjectName(QString::fromUtf8("labelTextStart"));

        gridLayout->addWidget(labelTextStart, 1, 0, 1, 2);

        lineStartAddress = new QLineEdit(layoutWidget);
        lineStartAddress->setObjectName(QString::fromUtf8("lineStartAddress"));

        gridLayout->addWidget(lineStartAddress, 1, 2, 1, 1);

        labelTextEnd = new QLabel(layoutWidget);
        labelTextEnd->setObjectName(QString::fromUtf8("labelTextEnd"));

        gridLayout->addWidget(labelTextEnd, 2, 0, 1, 1);

        lineEndAddress = new QLineEdit(layoutWidget);
        lineEndAddress->setObjectName(QString::fromUtf8("lineEndAddress"));

        gridLayout->addWidget(lineEndAddress, 2, 2, 1, 1);


        retranslateUi(FindWindow);

        QMetaObject::connectSlotsByName(FindWindow);
    } // setupUi

    void retranslateUi(QWidget *FindWindow)
    {
        FindWindow->setWindowTitle(QCoreApplication::translate("FindWindow", "Form", nullptr));
        buttonStart->setText(QCoreApplication::translate("FindWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\237\320\276\320\270\321\201\320\272", nullptr));
        buttonExit->setText(QCoreApplication::translate("FindWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        labelTextValue->setText(QCoreApplication::translate("FindWindow", "\320\230\321\201\320\272\320\276\320\274\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265: ", nullptr));
        labelTextStart->setText(QCoreApplication::translate("FindWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\271 \320\260\320\264\321\200\320\265\321\201\321\201: ", nullptr));
        labelTextEnd->setText(QCoreApplication::translate("FindWindow", "\320\232\320\276\320\275\320\265\321\207\320\275\321\213\320\271 \320\260\320\264\321\200\320\265\321\201\321\201: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindWindow: public Ui_FindWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFORM_H
