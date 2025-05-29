/********************************************************************************
** Form generated from reading UI file 'findwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDWIDGET_H
#define UI_FINDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelTextValue;
    QLineEdit *lineValue;
    QLabel *labelTextStart;
    QLineEdit *lineStartAddress;
    QLabel *labelTextEnd;
    QLineEdit *lineEndAddress;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonStart;
    QPushButton *buttonExit;

    void setupUi(QWidget *FindWidget)
    {
        if (FindWidget->objectName().isEmpty())
            FindWidget->setObjectName(QString::fromUtf8("FindWidget"));
        FindWidget->resize(572, 331);
        verticalLayout = new QVBoxLayout(FindWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelTextValue = new QLabel(FindWidget);
        labelTextValue->setObjectName(QString::fromUtf8("labelTextValue"));

        gridLayout->addWidget(labelTextValue, 0, 0, 1, 2);

        lineValue = new QLineEdit(FindWidget);
        lineValue->setObjectName(QString::fromUtf8("lineValue"));

        gridLayout->addWidget(lineValue, 0, 2, 1, 1);

        labelTextStart = new QLabel(FindWidget);
        labelTextStart->setObjectName(QString::fromUtf8("labelTextStart"));

        gridLayout->addWidget(labelTextStart, 1, 0, 1, 2);

        lineStartAddress = new QLineEdit(FindWidget);
        lineStartAddress->setObjectName(QString::fromUtf8("lineStartAddress"));

        gridLayout->addWidget(lineStartAddress, 1, 2, 1, 1);

        labelTextEnd = new QLabel(FindWidget);
        labelTextEnd->setObjectName(QString::fromUtf8("labelTextEnd"));

        gridLayout->addWidget(labelTextEnd, 2, 0, 1, 1);

        lineEndAddress = new QLineEdit(FindWidget);
        lineEndAddress->setObjectName(QString::fromUtf8("lineEndAddress"));

        gridLayout->addWidget(lineEndAddress, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonStart = new QPushButton(FindWidget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));

        horizontalLayout->addWidget(buttonStart);

        buttonExit = new QPushButton(FindWidget);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));

        horizontalLayout->addWidget(buttonExit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FindWidget);

        QMetaObject::connectSlotsByName(FindWidget);
    } // setupUi

    void retranslateUi(QWidget *FindWidget)
    {
        FindWidget->setWindowTitle(QCoreApplication::translate("FindWidget", "Form", nullptr));
        labelTextValue->setText(QCoreApplication::translate("FindWidget", "\320\230\321\201\320\272\320\276\320\274\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265: ", nullptr));
        labelTextStart->setText(QCoreApplication::translate("FindWidget", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\271 \320\260\320\264\321\200\320\265\321\201\321\201: ", nullptr));
        labelTextEnd->setText(QCoreApplication::translate("FindWidget", "\320\232\320\276\320\275\320\265\321\207\320\275\321\213\320\271 \320\260\320\264\321\200\320\265\321\201\321\201: ", nullptr));
        buttonStart->setText(QCoreApplication::translate("FindWidget", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\237\320\276\320\270\321\201\320\272", nullptr));
        buttonExit->setText(QCoreApplication::translate("FindWidget", "\320\222\321\213\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindWidget: public Ui_FindWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDWIDGET_H
