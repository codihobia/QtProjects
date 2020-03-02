/********************************************************************************
** Form generated from reading UI file 'Chip.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHIP_H
#define UI_CHIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChipClass
{
public:
    QAction *actionInit;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *fileName;
    QPushButton *read;
    QSpacerItem *horizontalSpacer;
    QPushButton *reset;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *start;
    QPushButton *pause;
    QPushButton *lastStep;
    QPushButton *nextStep;
    QRadioButton *wash;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChipClass)
    {
        if (ChipClass->objectName().isEmpty())
            ChipClass->setObjectName(QString::fromUtf8("ChipClass"));
        ChipClass->resize(758, 674);
        actionInit = new QAction(ChipClass);
        actionInit->setObjectName(QString::fromUtf8("actionInit"));
        actionInit->setCheckable(true);
        centralWidget = new QWidget(ChipClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 381, 58));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        fileName = new QLineEdit(layoutWidget);
        fileName->setObjectName(QString::fromUtf8("fileName"));

        horizontalLayout->addWidget(fileName);

        read = new QPushButton(layoutWidget);
        read->setObjectName(QString::fromUtf8("read"));
        read->setEnabled(false);

        horizontalLayout->addWidget(read);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        reset = new QPushButton(layoutWidget);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setEnabled(false);

        horizontalLayout->addWidget(reset);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        start = new QPushButton(layoutWidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setEnabled(false);

        horizontalLayout_2->addWidget(start);

        pause = new QPushButton(layoutWidget);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setEnabled(false);

        horizontalLayout_2->addWidget(pause);

        lastStep = new QPushButton(layoutWidget);
        lastStep->setObjectName(QString::fromUtf8("lastStep"));
        lastStep->setEnabled(false);

        horizontalLayout_2->addWidget(lastStep);

        nextStep = new QPushButton(layoutWidget);
        nextStep->setObjectName(QString::fromUtf8("nextStep"));
        nextStep->setEnabled(false);

        horizontalLayout_2->addWidget(nextStep);

        wash = new QRadioButton(layoutWidget);
        wash->setObjectName(QString::fromUtf8("wash"));
        wash->setEnabled(false);

        horizontalLayout_2->addWidget(wash);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        ChipClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChipClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 758, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        ChipClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChipClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ChipClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ChipClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ChipClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionInit);
        mainToolBar->addAction(actionInit);

        retranslateUi(ChipClass);

        QMetaObject::connectSlotsByName(ChipClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChipClass)
    {
        ChipClass->setWindowTitle(QApplication::translate("ChipClass", "Chip", nullptr));
        actionInit->setText(QApplication::translate("ChipClass", "Init", nullptr));
#ifndef QT_NO_TOOLTIP
        actionInit->setToolTip(QApplication::translate("ChipClass", "\345\210\235\345\247\213\350\256\276\347\275\256", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("ChipClass", "\346\226\207\344\273\266\345\220\215", nullptr));
        fileName->setText(QApplication::translate("ChipClass", "testcasewash.txt", nullptr));
        read->setText(QApplication::translate("ChipClass", "\350\257\273\345\217\226", nullptr));
        reset->setText(QApplication::translate("ChipClass", "\345\244\215\344\275\215", nullptr));
        start->setText(QApplication::translate("ChipClass", "\345\205\250\351\203\250\346\222\255\346\224\276", nullptr));
        pause->setText(QApplication::translate("ChipClass", "\346\232\202\345\201\234", nullptr));
        lastStep->setText(QApplication::translate("ChipClass", "\344\270\212\344\270\200\346\255\245", nullptr));
        nextStep->setText(QApplication::translate("ChipClass", "\344\270\213\344\270\200\346\255\245", nullptr));
        wash->setText(QApplication::translate("ChipClass", "\346\270\205\346\264\227", nullptr));
        menu->setTitle(QApplication::translate("ChipClass", "\345\210\235\345\247\213\345\214\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChipClass: public Ui_ChipClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHIP_H
