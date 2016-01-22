/********************************************************************************
** Form generated from reading UI file 'cflwidget.ui'
**
** Created: Sun 31. May 16:59:00 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CFLWIDGET_H
#define UI_CFLWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CFLWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *FL1_pushButton;
    QPushButton *plus_pushButton;
    QPushButton *FL2_pushButton;
    QPushButton *FL3_pushButton;
    QPushButton *FL4_pushButton;
    QPushButton *FL5_pushButton;
    QPushButton *FL6_pushButton;
    QGridLayout *gridLayout_3;
    QPushButton *FL7_pushButton;
    QPushButton *five_pushButton;
    QGridLayout *gridLayout_2;
    QPushButton *FL8_pushButton;
    QPushButton *minus_pushButton;
    QPushButton *FL9_pushButton;
    QPushButton *FL10_pushButton;
    QPushButton *FL11_pushButton;
    QPushButton *FL12_pushButton;
    QPushButton *FL13_pushButton;
    QPushButton *UPLINK_pushButton;
    QPushButton *CANCEL_pushButton;

    void setupUi(QWidget *CFLWidget)
    {
        if (CFLWidget->objectName().isEmpty())
            CFLWidget->setObjectName(QString::fromUtf8("CFLWidget"));
        CFLWidget->resize(72, 305);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CFLWidget->sizePolicy().hasHeightForWidth());
        CFLWidget->setSizePolicy(sizePolicy);
        CFLWidget->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(CFLWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        FL1_pushButton = new QPushButton(CFLWidget);
        FL1_pushButton->setObjectName(QString::fromUtf8("FL1_pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(50);
        sizePolicy1.setVerticalStretch(20);
        sizePolicy1.setHeightForWidth(FL1_pushButton->sizePolicy().hasHeightForWidth());
        FL1_pushButton->setSizePolicy(sizePolicy1);
        FL1_pushButton->setMinimumSize(QSize(50, 20));
        FL1_pushButton->setMaximumSize(QSize(50, 16777215));
        FL1_pushButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        FL1_pushButton->setAutoDefault(false);
        FL1_pushButton->setDefault(false);
        FL1_pushButton->setFlat(true);

        gridLayout->addWidget(FL1_pushButton, 0, 0, 1, 1);

        plus_pushButton = new QPushButton(CFLWidget);
        plus_pushButton->setObjectName(QString::fromUtf8("plus_pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(20);
        sizePolicy2.setVerticalStretch(180);
        sizePolicy2.setHeightForWidth(plus_pushButton->sizePolicy().hasHeightForWidth());
        plus_pushButton->setSizePolicy(sizePolicy2);
        plus_pushButton->setMinimumSize(QSize(20, 130));
        plus_pushButton->setMaximumSize(QSize(20, 16777215));
        plus_pushButton->setFlat(true);

        gridLayout->addWidget(plus_pushButton, 0, 1, 6, 1);

        FL2_pushButton = new QPushButton(CFLWidget);
        FL2_pushButton->setObjectName(QString::fromUtf8("FL2_pushButton"));
        sizePolicy1.setHeightForWidth(FL2_pushButton->sizePolicy().hasHeightForWidth());
        FL2_pushButton->setSizePolicy(sizePolicy1);
        FL2_pushButton->setMinimumSize(QSize(50, 20));
        FL2_pushButton->setMaximumSize(QSize(50, 16777215));
        FL2_pushButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        FL2_pushButton->setAutoDefault(false);
        FL2_pushButton->setDefault(false);
        FL2_pushButton->setFlat(true);

        gridLayout->addWidget(FL2_pushButton, 1, 0, 1, 1);

        FL3_pushButton = new QPushButton(CFLWidget);
        FL3_pushButton->setObjectName(QString::fromUtf8("FL3_pushButton"));
        sizePolicy1.setHeightForWidth(FL3_pushButton->sizePolicy().hasHeightForWidth());
        FL3_pushButton->setSizePolicy(sizePolicy1);
        FL3_pushButton->setMinimumSize(QSize(50, 20));
        FL3_pushButton->setMaximumSize(QSize(50, 16777215));
        FL3_pushButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        FL3_pushButton->setAutoDefault(false);
        FL3_pushButton->setDefault(false);
        FL3_pushButton->setFlat(true);

        gridLayout->addWidget(FL3_pushButton, 2, 0, 1, 1);

        FL4_pushButton = new QPushButton(CFLWidget);
        FL4_pushButton->setObjectName(QString::fromUtf8("FL4_pushButton"));
        sizePolicy1.setHeightForWidth(FL4_pushButton->sizePolicy().hasHeightForWidth());
        FL4_pushButton->setSizePolicy(sizePolicy1);
        FL4_pushButton->setMinimumSize(QSize(50, 20));
        FL4_pushButton->setMaximumSize(QSize(50, 16777215));
        FL4_pushButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        FL4_pushButton->setAutoDefault(false);
        FL4_pushButton->setDefault(false);
        FL4_pushButton->setFlat(true);

        gridLayout->addWidget(FL4_pushButton, 3, 0, 1, 1);

        FL5_pushButton = new QPushButton(CFLWidget);
        FL5_pushButton->setObjectName(QString::fromUtf8("FL5_pushButton"));
        sizePolicy1.setHeightForWidth(FL5_pushButton->sizePolicy().hasHeightForWidth());
        FL5_pushButton->setSizePolicy(sizePolicy1);
        FL5_pushButton->setMinimumSize(QSize(50, 20));
        FL5_pushButton->setMaximumSize(QSize(50, 16777215));
        FL5_pushButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        FL5_pushButton->setAutoDefault(false);
        FL5_pushButton->setDefault(false);
        FL5_pushButton->setFlat(true);

        gridLayout->addWidget(FL5_pushButton, 4, 0, 1, 1);

        FL6_pushButton = new QPushButton(CFLWidget);
        FL6_pushButton->setObjectName(QString::fromUtf8("FL6_pushButton"));
        sizePolicy1.setHeightForWidth(FL6_pushButton->sizePolicy().hasHeightForWidth());
        FL6_pushButton->setSizePolicy(sizePolicy1);
        FL6_pushButton->setMinimumSize(QSize(50, 20));
        FL6_pushButton->setMaximumSize(QSize(50, 16777215));
        FL6_pushButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        FL6_pushButton->setAutoDefault(false);
        FL6_pushButton->setDefault(false);
        FL6_pushButton->setFlat(true);

        gridLayout->addWidget(FL6_pushButton, 5, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        FL7_pushButton = new QPushButton(CFLWidget);
        FL7_pushButton->setObjectName(QString::fromUtf8("FL7_pushButton"));
        sizePolicy1.setHeightForWidth(FL7_pushButton->sizePolicy().hasHeightForWidth());
        FL7_pushButton->setSizePolicy(sizePolicy1);
        FL7_pushButton->setMinimumSize(QSize(50, 20));
        FL7_pushButton->setMaximumSize(QSize(50, 16777215));
        FL7_pushButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        FL7_pushButton->setAutoDefault(false);
        FL7_pushButton->setDefault(false);
        FL7_pushButton->setFlat(true);

        gridLayout_3->addWidget(FL7_pushButton, 0, 0, 1, 1);

        five_pushButton = new QPushButton(CFLWidget);
        five_pushButton->setObjectName(QString::fromUtf8("five_pushButton"));
        five_pushButton->setMinimumSize(QSize(20, 0));
        five_pushButton->setFlat(true);

        gridLayout_3->addWidget(five_pushButton, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        FL8_pushButton = new QPushButton(CFLWidget);
        FL8_pushButton->setObjectName(QString::fromUtf8("FL8_pushButton"));
        sizePolicy1.setHeightForWidth(FL8_pushButton->sizePolicy().hasHeightForWidth());
        FL8_pushButton->setSizePolicy(sizePolicy1);
        FL8_pushButton->setMinimumSize(QSize(50, 20));
        FL8_pushButton->setMaximumSize(QSize(50, 16777215));
        FL8_pushButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        FL8_pushButton->setAutoDefault(false);
        FL8_pushButton->setDefault(false);
        FL8_pushButton->setFlat(true);

        gridLayout_2->addWidget(FL8_pushButton, 0, 0, 1, 1);

        minus_pushButton = new QPushButton(CFLWidget);
        minus_pushButton->setObjectName(QString::fromUtf8("minus_pushButton"));
        sizePolicy2.setHeightForWidth(minus_pushButton->sizePolicy().hasHeightForWidth());
        minus_pushButton->setSizePolicy(sizePolicy2);
        minus_pushButton->setMinimumSize(QSize(20, 130));
        minus_pushButton->setMaximumSize(QSize(20, 16777215));
        minus_pushButton->setFlat(true);

        gridLayout_2->addWidget(minus_pushButton, 0, 1, 6, 1);

        FL9_pushButton = new QPushButton(CFLWidget);
        FL9_pushButton->setObjectName(QString::fromUtf8("FL9_pushButton"));
        sizePolicy1.setHeightForWidth(FL9_pushButton->sizePolicy().hasHeightForWidth());
        FL9_pushButton->setSizePolicy(sizePolicy1);
        FL9_pushButton->setMinimumSize(QSize(50, 20));
        FL9_pushButton->setMaximumSize(QSize(50, 16777215));
        FL9_pushButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        FL9_pushButton->setAutoDefault(false);
        FL9_pushButton->setDefault(false);
        FL9_pushButton->setFlat(true);

        gridLayout_2->addWidget(FL9_pushButton, 1, 0, 1, 1);

        FL10_pushButton = new QPushButton(CFLWidget);
        FL10_pushButton->setObjectName(QString::fromUtf8("FL10_pushButton"));
        sizePolicy1.setHeightForWidth(FL10_pushButton->sizePolicy().hasHeightForWidth());
        FL10_pushButton->setSizePolicy(sizePolicy1);
        FL10_pushButton->setMinimumSize(QSize(50, 20));
        FL10_pushButton->setMaximumSize(QSize(50, 16777215));
        FL10_pushButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        FL10_pushButton->setAutoDefault(false);
        FL10_pushButton->setDefault(false);
        FL10_pushButton->setFlat(true);

        gridLayout_2->addWidget(FL10_pushButton, 2, 0, 1, 1);

        FL11_pushButton = new QPushButton(CFLWidget);
        FL11_pushButton->setObjectName(QString::fromUtf8("FL11_pushButton"));
        sizePolicy1.setHeightForWidth(FL11_pushButton->sizePolicy().hasHeightForWidth());
        FL11_pushButton->setSizePolicy(sizePolicy1);
        FL11_pushButton->setMinimumSize(QSize(50, 20));
        FL11_pushButton->setMaximumSize(QSize(50, 16777215));
        FL11_pushButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        FL11_pushButton->setAutoDefault(false);
        FL11_pushButton->setDefault(false);
        FL11_pushButton->setFlat(true);

        gridLayout_2->addWidget(FL11_pushButton, 3, 0, 1, 1);

        FL12_pushButton = new QPushButton(CFLWidget);
        FL12_pushButton->setObjectName(QString::fromUtf8("FL12_pushButton"));
        sizePolicy1.setHeightForWidth(FL12_pushButton->sizePolicy().hasHeightForWidth());
        FL12_pushButton->setSizePolicy(sizePolicy1);
        FL12_pushButton->setMinimumSize(QSize(50, 20));
        FL12_pushButton->setMaximumSize(QSize(50, 16777215));
        FL12_pushButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        FL12_pushButton->setAutoDefault(false);
        FL12_pushButton->setDefault(false);
        FL12_pushButton->setFlat(true);

        gridLayout_2->addWidget(FL12_pushButton, 4, 0, 1, 1);

        FL13_pushButton = new QPushButton(CFLWidget);
        FL13_pushButton->setObjectName(QString::fromUtf8("FL13_pushButton"));
        sizePolicy1.setHeightForWidth(FL13_pushButton->sizePolicy().hasHeightForWidth());
        FL13_pushButton->setSizePolicy(sizePolicy1);
        FL13_pushButton->setMinimumSize(QSize(50, 20));
        FL13_pushButton->setMaximumSize(QSize(50, 16777215));
        FL13_pushButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        FL13_pushButton->setAutoDefault(false);
        FL13_pushButton->setDefault(false);
        FL13_pushButton->setFlat(true);

        gridLayout_2->addWidget(FL13_pushButton, 5, 0, 1, 1);

        UPLINK_pushButton = new QPushButton(CFLWidget);
        UPLINK_pushButton->setObjectName(QString::fromUtf8("UPLINK_pushButton"));

        gridLayout_2->addWidget(UPLINK_pushButton, 6, 0, 1, 2);

        CANCEL_pushButton = new QPushButton(CFLWidget);
        CANCEL_pushButton->setObjectName(QString::fromUtf8("CANCEL_pushButton"));

        gridLayout_2->addWidget(CANCEL_pushButton, 7, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_2);

        plus_pushButton->raise();
        FL1_pushButton->raise();
        FL2_pushButton->raise();
        FL3_pushButton->raise();
        FL5_pushButton->raise();
        FL4_pushButton->raise();
        FL6_pushButton->raise();
        plus_pushButton->raise();
        FL7_pushButton->raise();

        retranslateUi(CFLWidget);

        QMetaObject::connectSlotsByName(CFLWidget);
    } // setupUi

    void retranslateUi(QWidget *CFLWidget)
    {
        CFLWidget->setWindowTitle(QApplication::translate("CFLWidget", "Form", 0, QApplication::UnicodeUTF8));
        FL1_pushButton->setText(QApplication::translate("CFLWidget", "120", 0, QApplication::UnicodeUTF8));
        plus_pushButton->setText(QApplication::translate("CFLWidget", "+", 0, QApplication::UnicodeUTF8));
        FL2_pushButton->setText(QApplication::translate("CFLWidget", "110", 0, QApplication::UnicodeUTF8));
        FL3_pushButton->setText(QApplication::translate("CFLWidget", "100", 0, QApplication::UnicodeUTF8));
        FL4_pushButton->setText(QApplication::translate("CFLWidget", "90", 0, QApplication::UnicodeUTF8));
        FL5_pushButton->setText(QApplication::translate("CFLWidget", "80", 0, QApplication::UnicodeUTF8));
        FL6_pushButton->setText(QApplication::translate("CFLWidget", "70", 0, QApplication::UnicodeUTF8));
        FL7_pushButton->setText(QApplication::translate("CFLWidget", "60", 0, QApplication::UnicodeUTF8));
        five_pushButton->setText(QApplication::translate("CFLWidget", "5", 0, QApplication::UnicodeUTF8));
        FL8_pushButton->setText(QApplication::translate("CFLWidget", "50", 0, QApplication::UnicodeUTF8));
        minus_pushButton->setText(QApplication::translate("CFLWidget", "-", 0, QApplication::UnicodeUTF8));
        FL9_pushButton->setText(QApplication::translate("CFLWidget", "40", 0, QApplication::UnicodeUTF8));
        FL10_pushButton->setText(QApplication::translate("CFLWidget", "30", 0, QApplication::UnicodeUTF8));
        FL11_pushButton->setText(QApplication::translate("CFLWidget", "25", 0, QApplication::UnicodeUTF8));
        FL12_pushButton->setText(QApplication::translate("CFLWidget", "20", 0, QApplication::UnicodeUTF8));
        FL13_pushButton->setText(QApplication::translate("CFLWidget", "10", 0, QApplication::UnicodeUTF8));
        UPLINK_pushButton->setText(QApplication::translate("CFLWidget", "UPLINK", 0, QApplication::UnicodeUTF8));
        CANCEL_pushButton->setText(QApplication::translate("CFLWidget", "CANCEL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CFLWidget: public Ui_CFLWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFLWIDGET_H
