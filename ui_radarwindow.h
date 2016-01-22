/********************************************************************************
** Form generated from reading UI file 'radarwindow.ui'
**
** Created: Sun 31. May 18:36:39 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADARWINDOW_H
#define UI_RADARWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "radarview.h"

QT_BEGIN_NAMESPACE

class Ui_RadarWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *showGroupBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *navPointsCheckBox;
    QCheckBox *RWYCheckBox;
    QCheckBox *TMACheckBox;
    QCheckBox *CTRCheckBox;
    QLabel *label;
    QSpinBox *flightHistorySpinBox;
    QLabel *label_2;
    QSpinBox *flightPredictionSpinBox;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpacerItem *horizontalSpacer;
    RadarView *MapView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RadarWindow)
    {
        if (RadarWindow->objectName().isEmpty())
            RadarWindow->setObjectName(QString::fromUtf8("RadarWindow"));
        RadarWindow->resize(800, 600);
        centralwidget = new QWidget(RadarWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        showGroupBox = new QGroupBox(centralwidget);
        showGroupBox->setObjectName(QString::fromUtf8("showGroupBox"));
        horizontalLayout = new QHBoxLayout(showGroupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        navPointsCheckBox = new QCheckBox(showGroupBox);
        navPointsCheckBox->setObjectName(QString::fromUtf8("navPointsCheckBox"));

        horizontalLayout->addWidget(navPointsCheckBox);

        RWYCheckBox = new QCheckBox(showGroupBox);
        RWYCheckBox->setObjectName(QString::fromUtf8("RWYCheckBox"));

        horizontalLayout->addWidget(RWYCheckBox);

        TMACheckBox = new QCheckBox(showGroupBox);
        TMACheckBox->setObjectName(QString::fromUtf8("TMACheckBox"));

        horizontalLayout->addWidget(TMACheckBox);

        CTRCheckBox = new QCheckBox(showGroupBox);
        CTRCheckBox->setObjectName(QString::fromUtf8("CTRCheckBox"));

        horizontalLayout->addWidget(CTRCheckBox);

        label = new QLabel(showGroupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        flightHistorySpinBox = new QSpinBox(showGroupBox);
        flightHistorySpinBox->setObjectName(QString::fromUtf8("flightHistorySpinBox"));

        horizontalLayout->addWidget(flightHistorySpinBox);

        label_2 = new QLabel(showGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        flightPredictionSpinBox = new QSpinBox(showGroupBox);
        flightPredictionSpinBox->setObjectName(QString::fromUtf8("flightPredictionSpinBox"));

        horizontalLayout->addWidget(flightPredictionSpinBox);

        spinBox = new QSpinBox(showGroupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);

        spinBox_2 = new QSpinBox(showGroupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout->addWidget(spinBox_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(showGroupBox);

        MapView = new RadarView(centralwidget);
        MapView->setObjectName(QString::fromUtf8("MapView"));

        verticalLayout->addWidget(MapView);

        RadarWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RadarWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        RadarWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RadarWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RadarWindow->setStatusBar(statusbar);

        retranslateUi(RadarWindow);

        QMetaObject::connectSlotsByName(RadarWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RadarWindow)
    {
        RadarWindow->setWindowTitle(QApplication::translate("RadarWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        showGroupBox->setTitle(QApplication::translate("RadarWindow", "Show", 0, QApplication::UnicodeUTF8));
        navPointsCheckBox->setText(QApplication::translate("RadarWindow", "VOR/DME/NDB", 0, QApplication::UnicodeUTF8));
        RWYCheckBox->setText(QApplication::translate("RadarWindow", "RWY", 0, QApplication::UnicodeUTF8));
        TMACheckBox->setText(QApplication::translate("RadarWindow", "TMA", 0, QApplication::UnicodeUTF8));
        CTRCheckBox->setText(QApplication::translate("RadarWindow", "CTR", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RadarWindow", "HIST:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RadarWindow", "Prediction:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RadarWindow: public Ui_RadarWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADARWINDOW_H
