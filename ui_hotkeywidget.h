/********************************************************************************
** Form generated from reading UI file 'hotkeywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTKEYWIDGET_H
#define UI_HOTKEYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HotKeyWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkCtrl;
    QCheckBox *checkShift;
    QCheckBox *checkAlt;
    QPushButton *buttonGetHotKey;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonChange;
    QPushButton *buttonExit;

    void setupUi(QWidget *HotKeyWidget)
    {
        if (HotKeyWidget->objectName().isEmpty())
            HotKeyWidget->setObjectName(QString::fromUtf8("HotKeyWidget"));
        HotKeyWidget->resize(600, 420);
        verticalLayout = new QVBoxLayout(HotKeyWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkCtrl = new QCheckBox(HotKeyWidget);
        checkCtrl->setObjectName(QString::fromUtf8("checkCtrl"));

        horizontalLayout->addWidget(checkCtrl);

        checkShift = new QCheckBox(HotKeyWidget);
        checkShift->setObjectName(QString::fromUtf8("checkShift"));

        horizontalLayout->addWidget(checkShift);

        checkAlt = new QCheckBox(HotKeyWidget);
        checkAlt->setObjectName(QString::fromUtf8("checkAlt"));

        horizontalLayout->addWidget(checkAlt);


        verticalLayout->addLayout(horizontalLayout);

        buttonGetHotKey = new QPushButton(HotKeyWidget);
        buttonGetHotKey->setObjectName(QString::fromUtf8("buttonGetHotKey"));

        verticalLayout->addWidget(buttonGetHotKey);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        buttonChange = new QPushButton(HotKeyWidget);
        buttonChange->setObjectName(QString::fromUtf8("buttonChange"));

        horizontalLayout_2->addWidget(buttonChange);

        buttonExit = new QPushButton(HotKeyWidget);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));

        horizontalLayout_2->addWidget(buttonExit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(HotKeyWidget);

        QMetaObject::connectSlotsByName(HotKeyWidget);
    } // setupUi

    void retranslateUi(QWidget *HotKeyWidget)
    {
        HotKeyWidget->setWindowTitle(QCoreApplication::translate("HotKeyWidget", "Form", nullptr));
        checkCtrl->setText(QCoreApplication::translate("HotKeyWidget", "CTRL", nullptr));
        checkShift->setText(QCoreApplication::translate("HotKeyWidget", "SHIFT", nullptr));
        checkAlt->setText(QCoreApplication::translate("HotKeyWidget", "ALT", nullptr));
        buttonGetHotKey->setText(QCoreApplication::translate("HotKeyWidget", "\320\222\320\262\320\265\321\201\321\202\320\270 \320\241\320\270\320\274\320\262\320\276\320\273", nullptr));
        buttonChange->setText(QCoreApplication::translate("HotKeyWidget", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \320\223\320\276\321\200\321\217\321\207\321\203\321\216 \320\232\320\273\320\260\320\262\320\270\321\210\321\203", nullptr));
        buttonExit->setText(QCoreApplication::translate("HotKeyWidget", "\320\222\321\213\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HotKeyWidget: public Ui_HotKeyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTKEYWIDGET_H
