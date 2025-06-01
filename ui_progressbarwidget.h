/********************************************************************************
** Form generated from reading UI file 'progressbarwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSBARWIDGET_H
#define UI_PROGRESSBARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgressBarWidget
{
public:
    QLabel *label;

    void setupUi(QWidget *ProgressBarWidget)
    {
        if (ProgressBarWidget->objectName().isEmpty())
            ProgressBarWidget->setObjectName(QString::fromUtf8("ProgressBarWidget"));
        ProgressBarWidget->resize(400, 300);
        label = new QLabel(ProgressBarWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 120, 301, 61));

        retranslateUi(ProgressBarWidget);

        QMetaObject::connectSlotsByName(ProgressBarWidget);
    } // setupUi

    void retranslateUi(QWidget *ProgressBarWidget)
    {
        ProgressBarWidget->setWindowTitle(QCoreApplication::translate("ProgressBarWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("ProgressBarWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgressBarWidget: public Ui_ProgressBarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSBARWIDGET_H
