/********************************************************************************
** Form generated from reading UI file 'directwidget.ui'
**
** Created: Sun 31. May 21:01:04 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIRECTWIDGET_H
#define UI_DIRECTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DirectWidget
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *Point_comboBox;
    QPushButton *UPLINK_pushButton;
    QPushButton *CANCEL_pushButton;

    void setupUi(QWidget *DirectWidget)
    {
        if (DirectWidget->objectName().isEmpty())
            DirectWidget->setObjectName(QString::fromUtf8("DirectWidget"));
        DirectWidget->resize(75, 66);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DirectWidget->sizePolicy().hasHeightForWidth());
        DirectWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(DirectWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Point_comboBox = new QComboBox(DirectWidget);
        Point_comboBox->setObjectName(QString::fromUtf8("Point_comboBox"));

        verticalLayout->addWidget(Point_comboBox);

        UPLINK_pushButton = new QPushButton(DirectWidget);
        UPLINK_pushButton->setObjectName(QString::fromUtf8("UPLINK_pushButton"));

        verticalLayout->addWidget(UPLINK_pushButton);

        CANCEL_pushButton = new QPushButton(DirectWidget);
        CANCEL_pushButton->setObjectName(QString::fromUtf8("CANCEL_pushButton"));

        verticalLayout->addWidget(CANCEL_pushButton);


        retranslateUi(DirectWidget);

        QMetaObject::connectSlotsByName(DirectWidget);
    } // setupUi

    void retranslateUi(QWidget *DirectWidget)
    {
        DirectWidget->setWindowTitle(QApplication::translate("DirectWidget", "Form", 0, QApplication::UnicodeUTF8));
        UPLINK_pushButton->setText(QApplication::translate("DirectWidget", "UPLINK", 0, QApplication::UnicodeUTF8));
        CANCEL_pushButton->setText(QApplication::translate("DirectWidget", "CANCEL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DirectWidget: public Ui_DirectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRECTWIDGET_H
