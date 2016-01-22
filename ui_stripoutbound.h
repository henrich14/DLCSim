/********************************************************************************
** Form generated from reading UI file 'stripoutbound.ui'
**
** Created: Fri 29. May 17:57:37 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRIPOUTBOUND_H
#define UI_STRIPOUTBOUND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_StripOutbound
{
public:
    QFrame *frame;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QLineEdit *time_lineEdit;
    QLabel *flightLevel_actual_label;
    QLineEdit *flightLevel_lineEdit;
    QComboBox *point_comboBox;
    QFrame *frame_5;
    QGridLayout *gridLayout_4;
    QLabel *outboundPoint_label;
    QLineEdit *ETD_lineEdit;
    QFrame *frame_4;
    QGridLayout *gridLayout_3;
    QLabel *track_label;
    QLabel *rwy_label;
    QFrame *frame_3;
    QGridLayout *gridLayout_2;
    QLabel *CallSign_label;
    QLabel *equipment_label;
    QLabel *squawk_label;
    QLabel *cruiseLevel_label;
    QLabel *aircraftType_label;
    QLabel *category_label;
    QLabel *depAirport_label;
    QLabel *destAirport_label;
    QFrame *frame_6;
    QGridLayout *gridLayout_5;
    QLineEdit *comment1_lineEdit;
    QLineEdit *comment2_lineEdit;
    QLineEdit *comment3_lineEdit;

    void setupUi(QDialog *StripOutbound)
    {
        if (StripOutbound->objectName().isEmpty())
            StripOutbound->setObjectName(QString::fromUtf8("StripOutbound"));
        StripOutbound->resize(840, 80);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StripOutbound->sizePolicy().hasHeightForWidth());
        StripOutbound->setSizePolicy(sizePolicy);
        frame = new QFrame(StripOutbound);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 50, 80));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(StripOutbound);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(50, 0, 220, 80));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        time_lineEdit = new QLineEdit(frame_2);
        time_lineEdit->setObjectName(QString::fromUtf8("time_lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(time_lineEdit->sizePolicy().hasHeightForWidth());
        time_lineEdit->setSizePolicy(sizePolicy1);
        time_lineEdit->setMaximumSize(QSize(50, 16777215));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        time_lineEdit->setFont(font);
        time_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(time_lineEdit, 1, 0, 1, 1);

        flightLevel_actual_label = new QLabel(frame_2);
        flightLevel_actual_label->setObjectName(QString::fromUtf8("flightLevel_actual_label"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        flightLevel_actual_label->setFont(font1);
        flightLevel_actual_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(flightLevel_actual_label, 1, 1, 2, 1);

        flightLevel_lineEdit = new QLineEdit(frame_2);
        flightLevel_lineEdit->setObjectName(QString::fromUtf8("flightLevel_lineEdit"));
        sizePolicy1.setHeightForWidth(flightLevel_lineEdit->sizePolicy().hasHeightForWidth());
        flightLevel_lineEdit->setSizePolicy(sizePolicy1);
        flightLevel_lineEdit->setMaximumSize(QSize(50, 16777215));
        flightLevel_lineEdit->setFont(font);
        flightLevel_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(flightLevel_lineEdit, 2, 0, 1, 1);

        point_comboBox = new QComboBox(frame_2);
        point_comboBox->setObjectName(QString::fromUtf8("point_comboBox"));
        point_comboBox->setMinimumSize(QSize(115, 23));
        point_comboBox->setFont(font1);

        gridLayout->addWidget(point_comboBox, 0, 0, 1, 2);

        frame_5 = new QFrame(StripOutbound);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(640, 0, 100, 80));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        outboundPoint_label = new QLabel(frame_5);
        outboundPoint_label->setObjectName(QString::fromUtf8("outboundPoint_label"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        outboundPoint_label->setFont(font2);
        outboundPoint_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(outboundPoint_label, 0, 0, 1, 1);

        ETD_lineEdit = new QLineEdit(frame_5);
        ETD_lineEdit->setObjectName(QString::fromUtf8("ETD_lineEdit"));
        ETD_lineEdit->setFont(font2);
        ETD_lineEdit->setLayoutDirection(Qt::LeftToRight);
        ETD_lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(ETD_lineEdit, 1, 0, 1, 1);

        frame_4 = new QFrame(StripOutbound);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(490, 0, 150, 80));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        track_label = new QLabel(frame_4);
        track_label->setObjectName(QString::fromUtf8("track_label"));
        track_label->setFont(font1);
        track_label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(track_label, 0, 0, 1, 1);

        rwy_label = new QLabel(frame_4);
        rwy_label->setObjectName(QString::fromUtf8("rwy_label"));
        rwy_label->setFont(font1);
        rwy_label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(rwy_label, 1, 0, 1, 1);

        frame_3 = new QFrame(StripOutbound);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(270, 0, 220, 80));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        CallSign_label = new QLabel(frame_3);
        CallSign_label->setObjectName(QString::fromUtf8("CallSign_label"));
        CallSign_label->setMinimumSize(QSize(0, 23));
        CallSign_label->setFont(font1);

        gridLayout_2->addWidget(CallSign_label, 0, 0, 1, 3);

        equipment_label = new QLabel(frame_3);
        equipment_label->setObjectName(QString::fromUtf8("equipment_label"));
        equipment_label->setFont(font);
        equipment_label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(equipment_label, 0, 3, 1, 1);

        squawk_label = new QLabel(frame_3);
        squawk_label->setObjectName(QString::fromUtf8("squawk_label"));
        squawk_label->setFont(font);
        squawk_label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(squawk_label, 1, 1, 1, 2);

        cruiseLevel_label = new QLabel(frame_3);
        cruiseLevel_label->setObjectName(QString::fromUtf8("cruiseLevel_label"));
        cruiseLevel_label->setFont(font);
        cruiseLevel_label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(cruiseLevel_label, 1, 3, 1, 1);

        aircraftType_label = new QLabel(frame_3);
        aircraftType_label->setObjectName(QString::fromUtf8("aircraftType_label"));
        aircraftType_label->setFont(font);
        aircraftType_label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(aircraftType_label, 2, 0, 1, 1);

        category_label = new QLabel(frame_3);
        category_label->setObjectName(QString::fromUtf8("category_label"));
        category_label->setFont(font);
        category_label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(category_label, 2, 1, 1, 1);

        depAirport_label = new QLabel(frame_3);
        depAirport_label->setObjectName(QString::fromUtf8("depAirport_label"));
        depAirport_label->setFont(font);
        depAirport_label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(depAirport_label, 2, 2, 1, 1);

        destAirport_label = new QLabel(frame_3);
        destAirport_label->setObjectName(QString::fromUtf8("destAirport_label"));
        destAirport_label->setFont(font);
        destAirport_label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(destAirport_label, 2, 3, 1, 1);

        frame_6 = new QFrame(StripOutbound);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(740, 0, 100, 80));
        sizePolicy.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy);
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        comment1_lineEdit = new QLineEdit(frame_6);
        comment1_lineEdit->setObjectName(QString::fromUtf8("comment1_lineEdit"));
        comment1_lineEdit->setFont(font);

        gridLayout_5->addWidget(comment1_lineEdit, 0, 0, 1, 1);

        comment2_lineEdit = new QLineEdit(frame_6);
        comment2_lineEdit->setObjectName(QString::fromUtf8("comment2_lineEdit"));
        comment2_lineEdit->setFont(font);

        gridLayout_5->addWidget(comment2_lineEdit, 1, 0, 1, 1);

        comment3_lineEdit = new QLineEdit(frame_6);
        comment3_lineEdit->setObjectName(QString::fromUtf8("comment3_lineEdit"));
        comment3_lineEdit->setFont(font);

        gridLayout_5->addWidget(comment3_lineEdit, 2, 0, 1, 1);


        retranslateUi(StripOutbound);

        QMetaObject::connectSlotsByName(StripOutbound);
    } // setupUi

    void retranslateUi(QDialog *StripOutbound)
    {
        StripOutbound->setWindowTitle(QApplication::translate("StripOutbound", "Dialog", 0, QApplication::UnicodeUTF8));
        flightLevel_actual_label->setText(QApplication::translate("StripOutbound", "050", 0, QApplication::UnicodeUTF8));
        outboundPoint_label->setText(QApplication::translate("StripOutbound", "TAKOSS", 0, QApplication::UnicodeUTF8));
        track_label->setText(QApplication::translate("StripOutbound", "DEDIS1A", 0, QApplication::UnicodeUTF8));
        rwy_label->setText(QApplication::translate("StripOutbound", "01", 0, QApplication::UnicodeUTF8));
        CallSign_label->setText(QApplication::translate("StripOutbound", "TVQ6159", 0, QApplication::UnicodeUTF8));
        equipment_label->setText(QApplication::translate("StripOutbound", "N", 0, QApplication::UnicodeUTF8));
        squawk_label->setText(QApplication::translate("StripOutbound", "5110", 0, QApplication::UnicodeUTF8));
        cruiseLevel_label->setText(QApplication::translate("StripOutbound", "350", 0, QApplication::UnicodeUTF8));
        aircraftType_label->setText(QApplication::translate("StripOutbound", "A330", 0, QApplication::UnicodeUTF8));
        category_label->setText(QApplication::translate("StripOutbound", "M", 0, QApplication::UnicodeUTF8));
        depAirport_label->setText(QApplication::translate("StripOutbound", "LZKZ", 0, QApplication::UnicodeUTF8));
        destAirport_label->setText(QApplication::translate("StripOutbound", "LZIB", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StripOutbound: public Ui_StripOutbound {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRIPOUTBOUND_H
