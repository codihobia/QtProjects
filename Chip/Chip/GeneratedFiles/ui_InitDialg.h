/********************************************************************************
** Form generated from reading UI file 'InitDialg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITDIALG_H
#define UI_INITDIALG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InitDialg
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Y;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *X;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *IN;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *OUT;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *OK;
    QPushButton *Cancel;

    void setupUi(QDialog *InitDialg)
    {
        if (InitDialg->objectName().isEmpty())
            InitDialg->setObjectName(QString::fromUtf8("InitDialg"));
        InitDialg->resize(795, 103);
        verticalLayout_3 = new QVBoxLayout(InitDialg);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(InitDialg);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        Y = new QLineEdit(InitDialg);
        Y->setObjectName(QString::fromUtf8("Y"));

        horizontalLayout->addWidget(Y);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(InitDialg);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        X = new QLineEdit(InitDialg);
        X->setObjectName(QString::fromUtf8("X"));

        horizontalLayout_2->addWidget(X);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(InitDialg);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        IN = new QLineEdit(InitDialg);
        IN->setObjectName(QString::fromUtf8("IN"));

        horizontalLayout_3->addWidget(IN);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(InitDialg);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        OUT = new QLineEdit(InitDialg);
        OUT->setObjectName(QString::fromUtf8("OUT"));

        horizontalLayout_4->addWidget(OUT);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        OK = new QPushButton(InitDialg);
        OK->setObjectName(QString::fromUtf8("OK"));

        horizontalLayout_5->addWidget(OK);

        Cancel = new QPushButton(InitDialg);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        horizontalLayout_5->addWidget(Cancel);


        verticalLayout_3->addLayout(horizontalLayout_5);


        retranslateUi(InitDialg);

        QMetaObject::connectSlotsByName(InitDialg);
    } // setupUi

    void retranslateUi(QDialog *InitDialg)
    {
        InitDialg->setWindowTitle(QApplication::translate("InitDialg", "InitDialg", nullptr));
        label->setText(QApplication::translate("InitDialg", "\350\241\214\346\225\260", nullptr));
        Y->setText(QApplication::translate("InitDialg", "8", nullptr));
        label_2->setText(QApplication::translate("InitDialg", "\345\210\227\346\225\260", nullptr));
        X->setText(QApplication::translate("InitDialg", "8", nullptr));
        label_3->setText(QApplication::translate("InitDialg", "\350\276\223\345\205\245\347\253\257\345\217\243", nullptr));
        IN->setText(QApplication::translate("InitDialg", "(1,5)(4,8)", nullptr));
        label_4->setText(QApplication::translate("InitDialg", "\350\276\223\345\207\272\347\253\257\345\217\243", nullptr));
        OUT->setText(QApplication::translate("InitDialg", "(8,3)", nullptr));
        OK->setText(QApplication::translate("InitDialg", "\347\241\256\345\256\232", nullptr));
        Cancel->setText(QApplication::translate("InitDialg", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitDialg: public Ui_InitDialg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITDIALG_H
