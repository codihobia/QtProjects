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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClockClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *start;
    QPushButton *pause;
    QPushButton *reset;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClockClass)
    {
        if (ClockClass->objectName().isEmpty())
            ClockClass->setObjectName(QString::fromUtf8("ClockClass"));
        ClockClass->resize(600, 400);
        centralWidget = new QWidget(ClockClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));

        horizontalLayout->addWidget(start);

        pause = new QPushButton(centralWidget);
        pause->setObjectName(QString::fromUtf8("pause"));

        horizontalLayout->addWidget(pause);

        reset = new QPushButton(centralWidget);
        reset->setObjectName(QString::fromUtf8("reset"));

        horizontalLayout->addWidget(reset);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 291, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        ClockClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ClockClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        ClockClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ClockClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ClockClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ClockClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ClockClass->setStatusBar(statusBar);

        retranslateUi(ClockClass);

        QMetaObject::connectSlotsByName(ClockClass);
    } // setupUi

    void retranslateUi(QMainWindow *ClockClass)
    {
        ClockClass->setWindowTitle(QApplication::translate("ClockClass", "Clock", nullptr));
        start->setText(QApplication::translate("ClockClass", "start", nullptr));
        pause->setText(QApplication::translate("ClockClass", "pause", nullptr));
        reset->setText(QApplication::translate("ClockClass", "reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClockClass: public Ui_ClockClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCK_H
