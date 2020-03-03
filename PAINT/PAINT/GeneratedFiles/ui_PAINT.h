/********************************************************************************
** Form generated from reading UI file 'PAINT.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINT_H
#define UI_PAINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PAINTClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PAINTClass)
    {
        if (PAINTClass->objectName().isEmpty())
            PAINTClass->setObjectName(QString::fromUtf8("PAINTClass"));
        PAINTClass->resize(893, 808);
        centralWidget = new QWidget(PAINTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        PAINTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PAINTClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 893, 23));
        PAINTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PAINTClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PAINTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PAINTClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PAINTClass->setStatusBar(statusBar);

        retranslateUi(PAINTClass);

        QMetaObject::connectSlotsByName(PAINTClass);
    } // setupUi

    void retranslateUi(QMainWindow *PAINTClass)
    {
        PAINTClass->setWindowTitle(QApplication::translate("PAINTClass", "PAINT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PAINTClass: public Ui_PAINTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINT_H
