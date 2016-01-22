/********************************************************************************
** Form generated from reading UI file 'strip.ui'
**
** Created: Fri 29. May 17:57:37 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRIP_H
#define UI_STRIP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Strip
{
public:
    QTextEdit *strip_1;
    QTextEdit *strip_3;
    QTextEdit *strip_2;
    QTextEdit *strip_4;
    QTextEdit *strip_5;
    QTextEdit *strip_6;
    QTextEdit *strip_7;
    QTextEdit *strip_9;
    QTextEdit *strip_8;
    QTextEdit *strip_10;
    QTextEdit *strip_11;
    QTextEdit *strip_12;

    void setupUi(QDialog *Strip)
    {
        if (Strip->objectName().isEmpty())
            Strip->setObjectName(QString::fromUtf8("Strip"));
        Strip->resize(850, 120);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Strip->sizePolicy().hasHeightForWidth());
        Strip->setSizePolicy(sizePolicy);
        Strip->setMinimumSize(QSize(850, 120));
        Strip->setMaximumSize(QSize(850, 120));
        strip_1 = new QTextEdit(Strip);
        strip_1->setObjectName(QString::fromUtf8("strip_1"));
        strip_1->setGeometry(QRect(0, 0, 150, 60));
        sizePolicy.setHeightForWidth(strip_1->sizePolicy().hasHeightForWidth());
        strip_1->setSizePolicy(sizePolicy);
        strip_3 = new QTextEdit(Strip);
        strip_3->setObjectName(QString::fromUtf8("strip_3"));
        strip_3->setGeometry(QRect(150, 0, 160, 40));
        sizePolicy.setHeightForWidth(strip_3->sizePolicy().hasHeightForWidth());
        strip_3->setSizePolicy(sizePolicy);
        strip_2 = new QTextEdit(Strip);
        strip_2->setObjectName(QString::fromUtf8("strip_2"));
        strip_2->setGeometry(QRect(0, 60, 150, 60));
        sizePolicy.setHeightForWidth(strip_2->sizePolicy().hasHeightForWidth());
        strip_2->setSizePolicy(sizePolicy);
        strip_4 = new QTextEdit(Strip);
        strip_4->setObjectName(QString::fromUtf8("strip_4"));
        strip_4->setGeometry(QRect(150, 40, 160, 80));
        sizePolicy.setHeightForWidth(strip_4->sizePolicy().hasHeightForWidth());
        strip_4->setSizePolicy(sizePolicy);
        strip_5 = new QTextEdit(Strip);
        strip_5->setObjectName(QString::fromUtf8("strip_5"));
        strip_5->setGeometry(QRect(310, 0, 120, 60));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(strip_5->sizePolicy().hasHeightForWidth());
        strip_5->setSizePolicy(sizePolicy1);
        strip_6 = new QTextEdit(Strip);
        strip_6->setObjectName(QString::fromUtf8("strip_6"));
        strip_6->setGeometry(QRect(310, 60, 120, 60));
        strip_7 = new QTextEdit(Strip);
        strip_7->setObjectName(QString::fromUtf8("strip_7"));
        strip_7->setGeometry(QRect(430, 0, 200, 80));
        sizePolicy.setHeightForWidth(strip_7->sizePolicy().hasHeightForWidth());
        strip_7->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        strip_7->setFont(font);
        strip_9 = new QTextEdit(Strip);
        strip_9->setObjectName(QString::fromUtf8("strip_9"));
        strip_9->setGeometry(QRect(630, 0, 160, 120));
        sizePolicy.setHeightForWidth(strip_9->sizePolicy().hasHeightForWidth());
        strip_9->setSizePolicy(sizePolicy);
        strip_8 = new QTextEdit(Strip);
        strip_8->setObjectName(QString::fromUtf8("strip_8"));
        strip_8->setGeometry(QRect(430, 80, 260, 40));
        sizePolicy.setHeightForWidth(strip_8->sizePolicy().hasHeightForWidth());
        strip_8->setSizePolicy(sizePolicy);
        strip_10 = new QTextEdit(Strip);
        strip_10->setObjectName(QString::fromUtf8("strip_10"));
        strip_10->setGeometry(QRect(790, 0, 60, 40));
        sizePolicy.setHeightForWidth(strip_10->sizePolicy().hasHeightForWidth());
        strip_10->setSizePolicy(sizePolicy);
        strip_11 = new QTextEdit(Strip);
        strip_11->setObjectName(QString::fromUtf8("strip_11"));
        strip_11->setGeometry(QRect(790, 40, 60, 40));
        strip_12 = new QTextEdit(Strip);
        strip_12->setObjectName(QString::fromUtf8("strip_12"));
        strip_12->setGeometry(QRect(790, 80, 60, 40));

        retranslateUi(Strip);

        QMetaObject::connectSlotsByName(Strip);
    } // setupUi

    void retranslateUi(QDialog *Strip)
    {
        Strip->setWindowTitle(QApplication::translate("Strip", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Strip: public Ui_Strip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRIP_H
