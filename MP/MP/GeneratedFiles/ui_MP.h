/********************************************************************************
** Form generated from reading UI file 'MP.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MP_H
#define UI_MP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MPClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *lastBtn;
    QPushButton *pauseBtn;
    QPushButton *playBtn;
    QPushButton *nextBtn;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QSlider *volumeSlider;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *addBtn;
    QPushButton *removeBtn;
    QListWidget *list;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MPClass)
    {
        if (MPClass->objectName().isEmpty())
            MPClass->setObjectName(QString::fromUtf8("MPClass"));
        MPClass->resize(624, 400);
        centralWidget = new QWidget(MPClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lastBtn = new QPushButton(centralWidget);
        lastBtn->setObjectName(QString::fromUtf8("lastBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MP/last.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        lastBtn->setIcon(icon);
        lastBtn->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(lastBtn);

        pauseBtn = new QPushButton(centralWidget);
        pauseBtn->setObjectName(QString::fromUtf8("pauseBtn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/MP/timgGMZT1SW1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pauseBtn->setIcon(icon1);
        pauseBtn->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(pauseBtn);

        playBtn = new QPushButton(centralWidget);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/MP/play.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        playBtn->setIcon(icon2);
        playBtn->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(playBtn);

        nextBtn = new QPushButton(centralWidget);
        nextBtn->setObjectName(QString::fromUtf8("nextBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/MP/next.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        nextBtn->setIcon(icon3);
        nextBtn->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(nextBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        volumeSlider = new QSlider(centralWidget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setValue(99);
        volumeSlider->setOrientation(Qt::Vertical);

        verticalLayout_3->addWidget(volumeSlider);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        addBtn = new QPushButton(centralWidget);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        verticalLayout->addWidget(addBtn);

        removeBtn = new QPushButton(centralWidget);
        removeBtn->setObjectName(QString::fromUtf8("removeBtn"));

        verticalLayout->addWidget(removeBtn);


        horizontalLayout_2->addLayout(verticalLayout);

        list = new QListWidget(centralWidget);
        list->setObjectName(QString::fromUtf8("list"));

        horizontalLayout_2->addWidget(list);


        verticalLayout_2->addLayout(horizontalLayout_2);

        MPClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MPClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 624, 23));
        MPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MPClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MPClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MPClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MPClass->setStatusBar(statusBar);

        retranslateUi(MPClass);

        QMetaObject::connectSlotsByName(MPClass);
    } // setupUi

    void retranslateUi(QMainWindow *MPClass)
    {
        MPClass->setWindowTitle(QApplication::translate("MPClass", "MP", nullptr));
        lastBtn->setText(QString());
        pauseBtn->setText(QString());
        playBtn->setText(QString());
        nextBtn->setText(QString());
        label->setText(QApplication::translate("MPClass", "Volume", nullptr));
        addBtn->setText(QApplication::translate("MPClass", "+", nullptr));
        removeBtn->setText(QApplication::translate("MPClass", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MPClass: public Ui_MPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MP_H
