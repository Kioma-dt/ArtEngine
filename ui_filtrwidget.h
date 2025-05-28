/********************************************************************************
** Form generated from reading UI file 'filtrwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTRWIDGET_H
#define UI_FILTRWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FiltrWidget
{
public:
    QPushButton *buttonExit;
    QPushButton *buttonStart;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTextValue;
    QLineEdit *lineValue;

    void setupUi(QWidget *FiltrWidget)
    {
        if (FiltrWidget->objectName().isEmpty())
            FiltrWidget->setObjectName(QString::fromUtf8("FiltrWidget"));
        FiltrWidget->resize(601, 393);
        buttonExit = new QPushButton(FiltrWidget);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));
        buttonExit->setGeometry(QRect(390, 270, 90, 29));
        buttonStart = new QPushButton(FiltrWidget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        buttonStart->setGeometry(QRect(70, 270, 171, 31));
        widget = new QWidget(FiltrWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 50, 441, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelTextValue = new QLabel(widget);
        labelTextValue->setObjectName(QString::fromUtf8("labelTextValue"));

        horizontalLayout->addWidget(labelTextValue);

        lineValue = new QLineEdit(widget);
        lineValue->setObjectName(QString::fromUtf8("lineValue"));

        horizontalLayout->addWidget(lineValue);


        retranslateUi(FiltrWidget);

        QMetaObject::connectSlotsByName(FiltrWidget);
    } // setupUi

    void retranslateUi(QWidget *FiltrWidget)
    {
        FiltrWidget->setWindowTitle(QCoreApplication::translate("FiltrWidget", "Form", nullptr));
        buttonExit->setText(QCoreApplication::translate("FiltrWidget", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        buttonStart->setText(QCoreApplication::translate("FiltrWidget", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\244\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\216", nullptr));
        labelTextValue->setText(QCoreApplication::translate("FiltrWidget", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\264\320\273\321\217 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\320\270: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FiltrWidget: public Ui_FiltrWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTRWIDGET_H
