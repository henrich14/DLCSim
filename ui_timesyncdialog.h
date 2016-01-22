/********************************************************************************
** Form generated from reading UI file 'timesyncdialog.ui'
**
** Created: Fri 29. May 17:57:37 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESYNCDIALOG_H
#define UI_TIMESYNCDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TimeSyncDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpinBox *hourSpinBox;
    QLabel *label;
    QSpinBox *minuteSpinBox;
    QLabel *label_2;
    QSpinBox *secondSpinBox;
    QPushButton *syncButton;

    void setupUi(QDialog *TimeSyncDialog)
    {
        if (TimeSyncDialog->objectName().isEmpty())
            TimeSyncDialog->setObjectName(QString::fromUtf8("TimeSyncDialog"));
        TimeSyncDialog->resize(184, 80);
        verticalLayout = new QVBoxLayout(TimeSyncDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        hourSpinBox = new QSpinBox(TimeSyncDialog);
        hourSpinBox->setObjectName(QString::fromUtf8("hourSpinBox"));

        horizontalLayout->addWidget(hourSpinBox);

        label = new QLabel(TimeSyncDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        minuteSpinBox = new QSpinBox(TimeSyncDialog);
        minuteSpinBox->setObjectName(QString::fromUtf8("minuteSpinBox"));

        horizontalLayout->addWidget(minuteSpinBox);

        label_2 = new QLabel(TimeSyncDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        secondSpinBox = new QSpinBox(TimeSyncDialog);
        secondSpinBox->setObjectName(QString::fromUtf8("secondSpinBox"));

        horizontalLayout->addWidget(secondSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        syncButton = new QPushButton(TimeSyncDialog);
        syncButton->setObjectName(QString::fromUtf8("syncButton"));

        verticalLayout->addWidget(syncButton);


        retranslateUi(TimeSyncDialog);

        QMetaObject::connectSlotsByName(TimeSyncDialog);
    } // setupUi

    void retranslateUi(QDialog *TimeSyncDialog)
    {
        TimeSyncDialog->setWindowTitle(QApplication::translate("TimeSyncDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TimeSyncDialog", ":", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TimeSyncDialog", ":", 0, QApplication::UnicodeUTF8));
        syncButton->setText(QApplication::translate("TimeSyncDialog", "SYNC", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TimeSyncDialog: public Ui_TimeSyncDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESYNCDIALOG_H
