/********************************************************************************
** Form generated from reading UI file 'stripinbound.ui'
**
** Created: Fri 29. May 17:57:37 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRIPINBOUND_H
#define UI_STRIPINBOUND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StripInbound
{
public:
    QFrame *frame;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *time1_lineEdit;
    QLabel *flightLevel_actual_label;
    QLineEdit *flightLevel1_lineEdit;
    QComboBox *point1_comboBox;
    QVBoxLayout *verticalLayout_2;
    QComboBox *point2_comboBox;
    QLineEdit *time2_lineEdit;
    QLineEdit *flightLevel2_lineEdit;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QLabel *CallSign_label;
    QLabel *equipment_label;
    QLabel *squawk_label;
    QLabel *cruiseLevel_label;
    QLabel *aircraftType_label;
    QLabel *category_label;
    QLabel *depAirport_label;
    QLabel *destAirport_label;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout;
    QComboBox *track_comboBox;
    QLineEdit *rwy_lineEdit;
    QFrame *frame_5;
    QGridLayout *gridLayout_3;
    QLineEdit *comment1_lineEdit;
    QLineEdit *comment2_lineEdit;
    QLineEdit *comment3_lineEdit;

    void setupUi(QDialog *StripInbound)
    {
        if (StripInbound->objectName().isEmpty())
            StripInbound->setObjectName(QString::fromUtf8("StripInbound"));
        StripInbound->resize(740, 80);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StripInbound->sizePolicy().hasHeightForWidth());
        StripInbound->setSizePolicy(sizePolicy);
        frame = new QFrame(StripInbound);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 50, 80));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(StripInbound);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(50, 0, 220, 80));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        time1_lineEdit = new QLineEdit(frame_2);
        time1_lineEdit->setObjectName(QString::fromUtf8("time1_lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(time1_lineEdit->sizePolicy().hasHeightForWidth());
        time1_lineEdit->setSizePolicy(sizePolicy1);
        time1_lineEdit->setMaximumSize(QSize(50, 16777215));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        time1_lineEdit->setFont(font);
        time1_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(time1_lineEdit, 1, 0, 1, 1);

        flightLevel_actual_label = new QLabel(frame_2);
        flightLevel_actual_label->setObjectName(QString::fromUtf8("flightLevel_actual_label"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        flightLevel_actual_label->setFont(font1);
        flightLevel_actual_label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(flightLevel_actual_label, 1, 1, 2, 1);

        flightLevel1_lineEdit = new QLineEdit(frame_2);
        flightLevel1_lineEdit->setObjectName(QString::fromUtf8("flightLevel1_lineEdit"));
        sizePolicy1.setHeightForWidth(flightLevel1_lineEdit->sizePolicy().hasHeightForWidth());
        flightLevel1_lineEdit->setSizePolicy(sizePolicy1);
        flightLevel1_lineEdit->setMaximumSize(QSize(50, 16777215));
        flightLevel1_lineEdit->setFont(font);
        flightLevel1_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(flightLevel1_lineEdit, 2, 0, 1, 1);

        point1_comboBox = new QComboBox(frame_2);
        point1_comboBox->setObjectName(QString::fromUtf8("point1_comboBox"));
        point1_comboBox->setMinimumSize(QSize(115, 23));
        point1_comboBox->setFont(font1);

        gridLayout_2->addWidget(point1_comboBox, 0, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        point2_comboBox = new QComboBox(frame_2);
        point2_comboBox->setObjectName(QString::fromUtf8("point2_comboBox"));
        point2_comboBox->setMinimumSize(QSize(0, 22));
        point2_comboBox->setFont(font);
        point2_comboBox->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_2->addWidget(point2_comboBox);

        time2_lineEdit = new QLineEdit(frame_2);
        time2_lineEdit->setObjectName(QString::fromUtf8("time2_lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(time2_lineEdit->sizePolicy().hasHeightForWidth());
        time2_lineEdit->setSizePolicy(sizePolicy2);
        time2_lineEdit->setFont(font);
        time2_lineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(time2_lineEdit);

        flightLevel2_lineEdit = new QLineEdit(frame_2);
        flightLevel2_lineEdit->setObjectName(QString::fromUtf8("flightLevel2_lineEdit"));
        flightLevel2_lineEdit->setFont(font);
        flightLevel2_lineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(flightLevel2_lineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        frame_3 = new QFrame(StripInbound);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(270, 0, 220, 80));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CallSign_label = new QLabel(frame_3);
        CallSign_label->setObjectName(QString::fromUtf8("CallSign_label"));
        CallSign_label->setMinimumSize(QSize(0, 23));
        CallSign_label->setFont(font1);

        gridLayout->addWidget(CallSign_label, 0, 0, 1, 3);

        equipment_label = new QLabel(frame_3);
        equipment_label->setObjectName(QString::fromUtf8("equipment_label"));
        equipment_label->setFont(font);
        equipment_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(equipment_label, 0, 3, 1, 1);

        squawk_label = new QLabel(frame_3);
        squawk_label->setObjectName(QString::fromUtf8("squawk_label"));
        squawk_label->setFont(font);
        squawk_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(squawk_label, 1, 1, 1, 2);

        cruiseLevel_label = new QLabel(frame_3);
        cruiseLevel_label->setObjectName(QString::fromUtf8("cruiseLevel_label"));
        cruiseLevel_label->setFont(font);
        cruiseLevel_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(cruiseLevel_label, 1, 3, 1, 1);

        aircraftType_label = new QLabel(frame_3);
        aircraftType_label->setObjectName(QString::fromUtf8("aircraftType_label"));
        aircraftType_label->setFont(font);
        aircraftType_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(aircraftType_label, 2, 0, 1, 1);

        category_label = new QLabel(frame_3);
        category_label->setObjectName(QString::fromUtf8("category_label"));
        category_label->setFont(font);
        category_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(category_label, 2, 1, 1, 1);

        depAirport_label = new QLabel(frame_3);
        depAirport_label->setObjectName(QString::fromUtf8("depAirport_label"));
        depAirport_label->setFont(font);
        depAirport_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(depAirport_label, 2, 2, 1, 1);

        destAirport_label = new QLabel(frame_3);
        destAirport_label->setObjectName(QString::fromUtf8("destAirport_label"));
        destAirport_label->setFont(font);
        destAirport_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(destAirport_label, 2, 3, 1, 1);

        frame_4 = new QFrame(StripInbound);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(490, 0, 150, 80));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        track_comboBox = new QComboBox(frame_4);
        track_comboBox->setObjectName(QString::fromUtf8("track_comboBox"));
        track_comboBox->setMinimumSize(QSize(135, 0));
        track_comboBox->setFont(font1);

        verticalLayout->addWidget(track_comboBox);

        rwy_lineEdit = new QLineEdit(frame_4);
        rwy_lineEdit->setObjectName(QString::fromUtf8("rwy_lineEdit"));
        rwy_lineEdit->setFont(font1);
        rwy_lineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(rwy_lineEdit);

        frame_5 = new QFrame(StripInbound);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(640, 0, 100, 80));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        comment1_lineEdit = new QLineEdit(frame_5);
        comment1_lineEdit->setObjectName(QString::fromUtf8("comment1_lineEdit"));
        comment1_lineEdit->setFont(font);

        gridLayout_3->addWidget(comment1_lineEdit, 0, 0, 1, 1);

        comment2_lineEdit = new QLineEdit(frame_5);
        comment2_lineEdit->setObjectName(QString::fromUtf8("comment2_lineEdit"));
        comment2_lineEdit->setFont(font);

        gridLayout_3->addWidget(comment2_lineEdit, 1, 0, 1, 1);

        comment3_lineEdit = new QLineEdit(frame_5);
        comment3_lineEdit->setObjectName(QString::fromUtf8("comment3_lineEdit"));
        comment3_lineEdit->setFont(font);

        gridLayout_3->addWidget(comment3_lineEdit, 2, 0, 1, 1);


        retranslateUi(StripInbound);

        QMetaObject::connectSlotsByName(StripInbound);
    } // setupUi

    void retranslateUi(QDialog *StripInbound)
    {
        StripInbound->setWindowTitle(QApplication::translate("StripInbound", "Dialog", 0, QApplication::UnicodeUTF8));
        flightLevel_actual_label->setText(QApplication::translate("StripInbound", "050", 0, QApplication::UnicodeUTF8));
        CallSign_label->setText(QApplication::translate("StripInbound", "TVQ6159", 0, QApplication::UnicodeUTF8));
        equipment_label->setText(QApplication::translate("StripInbound", "N", 0, QApplication::UnicodeUTF8));
        squawk_label->setText(QApplication::translate("StripInbound", "5110", 0, QApplication::UnicodeUTF8));
        cruiseLevel_label->setText(QApplication::translate("StripInbound", "350", 0, QApplication::UnicodeUTF8));
        aircraftType_label->setText(QApplication::translate("StripInbound", "A330", 0, QApplication::UnicodeUTF8));
        category_label->setText(QApplication::translate("StripInbound", "M", 0, QApplication::UnicodeUTF8));
        depAirport_label->setText(QApplication::translate("StripInbound", "LZKZ", 0, QApplication::UnicodeUTF8));
        destAirport_label->setText(QApplication::translate("StripInbound", "LZIB", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StripInbound: public Ui_StripInbound {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRIPINBOUND_H
