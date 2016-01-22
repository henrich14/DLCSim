/********************************************************************************
** Form generated from reading UI file 'metar.ui'
**
** Created: Fri 29. May 17:57:37 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_METAR_H
#define UI_METAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Metar
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *TIMELabel;
    QLabel *QNHLabel;
    QLabel *WindLabel;

    void setupUi(QWidget *Metar)
    {
        if (Metar->objectName().isEmpty())
            Metar->setObjectName(QString::fromUtf8("Metar"));
        Metar->resize(258, 264);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Metar->sizePolicy().hasHeightForWidth());
        Metar->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Metar);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        TIMELabel = new QLabel(Metar);
        TIMELabel->setObjectName(QString::fromUtf8("TIMELabel"));

        verticalLayout->addWidget(TIMELabel);

        QNHLabel = new QLabel(Metar);
        QNHLabel->setObjectName(QString::fromUtf8("QNHLabel"));
        QNHLabel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(QNHLabel);

        WindLabel = new QLabel(Metar);
        WindLabel->setObjectName(QString::fromUtf8("WindLabel"));

        verticalLayout->addWidget(WindLabel);


        retranslateUi(Metar);

        QMetaObject::connectSlotsByName(Metar);
    } // setupUi

    void retranslateUi(QWidget *Metar)
    {
        Metar->setWindowTitle(QApplication::translate("Metar", "Form", 0, QApplication::UnicodeUTF8));
        TIMELabel->setText(QApplication::translate("Metar", "TIME", 0, QApplication::UnicodeUTF8));
        QNHLabel->setText(QApplication::translate("Metar", "QNH", 0, QApplication::UnicodeUTF8));
        WindLabel->setText(QApplication::translate("Metar", "Wind", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Metar: public Ui_Metar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METAR_H
