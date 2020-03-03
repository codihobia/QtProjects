/********************************************************************************
** Form generated from reading UI file 'Clock.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCK_H
#define UI_CLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClockClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *start;
    QPushButton *pause;
    QPushButton *reset;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ClockClass)
    {
        if (ClockClass->objectName().isEmpty())
            ClockClass->setObjectName(QString::fromUtf8("ClockClass"));
        ClockClass->resize(725, 647);
        verticalLayout = new QVBoxLayout(ClockClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        start = new QPushButton(ClockClass);
        start->setObjectName(QString::fromUtf8("start"));

        horizontalLayout->addWidget(start);

        pause = new QPushButton(ClockClass);
        pause->setObjectName(QString::fromUtf8("pause"));

        horizontalLayout->addWidget(pause);

        reset = new QPushButton(ClockClass);
        reset->setObjectName(QString::fromUtf8("reset"));

        horizontalLayout->addWidget(reset);


        verticalLayout->addLayout(horizontalLayout);

        lcdNumber = new QLCDNumber(ClockClass);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(lcdNumber);

        verticalSpacer = new QSpacerItem(20, 539, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(ClockClass);
        QObject::connect(start, SIGNAL(clicked()), ClockClass, SLOT(OnStart()));
        QObject::connect(pause, SIGNAL(clicked()), ClockClass, SLOT(OnPause()));

        QMetaObject::connectSlotsByName(ClockClass);
    } // setupUi

    void retranslateUi(QWidget *ClockClass)
    {
        ClockClass->setWindowTitle(QApplication::translate("ClockClass", "Clock", nullptr));
        start->setText(QApplication::translate("ClockClass", "\345\274\200\345\247\213", nullptr));
        pause->setText(QApplication::translate("ClockClass", "\346\232\202\345\201\234", nullptr));
        reset->setText(QApplication::translate("ClockClass", "\347\275\2560", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClockClass: public Ui_ClockClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCK_H
