/********************************************************************************
** Form generated from reading UI file 'time.ui'
**
** Created: Fri 29. May 17:57:37 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIME_H
#define UI_TIME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Time
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *timeLabel;

    void setupUi(QWidget *Time)
    {
        if (Time->objectName().isEmpty())
            Time->setObjectName(QString::fromUtf8("Time"));
        Time->resize(168, 66);
        horizontalLayout = new QHBoxLayout(Time);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        timeLabel = new QLabel(Time);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        timeLabel->setFont(font);

        horizontalLayout->addWidget(timeLabel);


        retranslateUi(Time);

        QMetaObject::connectSlotsByName(Time);
    } // setupUi

    void retranslateUi(QWidget *Time)
    {
        Time->setWindowTitle(QApplication::translate("Time", "Form", 0, QApplication::UnicodeUTF8));
        timeLabel->setText(QApplication::translate("Time", "T:I:M:E", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Time: public Ui_Time {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIME_H
