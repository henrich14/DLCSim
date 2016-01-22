/********************************************************************************
** Form generated from reading UI file 'label.ui'
**
** Created: Fri 29. May 17:57:37 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABEL_H
#define UI_LABEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Label
{
public:
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_4;
    QLabel *callSign;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *FLlabel_current;
    QComboBox *FLcomboBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *FLQNH;
    QLabel *RADIALlabel_current;
    QPushButton *RADIALbutton;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *FreqComboBox;
    QCheckBox *freqNextUnit;
    QGroupBox *MESSAGESgroupBox;
    QGridLayout *gridLayout;
    QRadioButton *VRrb;
    QRadioButton *ALTrb;
    QRadioButton *PTrb;
    QRadioButton *FLrb;
    QRadioButton *RADrb;
    QRadioButton *TMrb;
    QRadioButton *ROUTErb;
    QComboBox *MessageComboBox;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *RATElabel;
    QLabel *TIMElabel;
    QLabel *RADIALlabel;
    QLabel *ALTITUDElabel;
    QLabel *DISTANCElabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *RATElineEdit;
    QLineEdit *TIMElineEdit;
    QLineEdit *RADIALlineEdit;
    QLineEdit *ALTITUDElineEdit;
    QLineEdit *DISTANCElineEdit;
    QComboBox *trackComboBox;
    QComboBox *pointComboBox;
    QPushButton *uplinkButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *resumeOwnNavigationButton;
    QPushButton *disregardButton;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *rogerButton;
    QPushButton *affirmButton;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *negativeButton;
    QPushButton *logOnButton;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *contactRequestButton;
    QPushButton *contactRequestVoiceButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Label)
    {
        if (Label->objectName().isEmpty())
            Label->setObjectName(QString::fromUtf8("Label"));
        Label->resize(390, 863);
        horizontalLayout_9 = new QHBoxLayout(Label);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        callSign = new QLabel(Label);
        callSign->setObjectName(QString::fromUtf8("callSign"));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(true);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        callSign->setFont(font);
        callSign->setTextFormat(Qt::AutoText);

        verticalLayout_4->addWidget(callSign);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        FLlabel_current = new QLabel(Label);
        FLlabel_current->setObjectName(QString::fromUtf8("FLlabel_current"));
        QFont font1;
        font1.setPointSize(10);
        FLlabel_current->setFont(font1);

        horizontalLayout->addWidget(FLlabel_current);

        FLcomboBox = new QComboBox(Label);
        FLcomboBox->setObjectName(QString::fromUtf8("FLcomboBox"));
        FLcomboBox->setMinimumSize(QSize(70, 35));
        FLcomboBox->setFont(font1);

        horizontalLayout->addWidget(FLcomboBox);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        FLQNH = new QCheckBox(Label);
        FLQNH->setObjectName(QString::fromUtf8("FLQNH"));
        FLQNH->setFont(font1);

        verticalLayout->addWidget(FLQNH);


        horizontalLayout_2->addLayout(verticalLayout);

        RADIALlabel_current = new QLabel(Label);
        RADIALlabel_current->setObjectName(QString::fromUtf8("RADIALlabel_current"));
        RADIALlabel_current->setFont(font1);
        RADIALlabel_current->setLayoutDirection(Qt::LeftToRight);
        RADIALlabel_current->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(RADIALlabel_current);

        RADIALbutton = new QPushButton(Label);
        RADIALbutton->setObjectName(QString::fromUtf8("RADIALbutton"));
        RADIALbutton->setMinimumSize(QSize(0, 35));
        RADIALbutton->setFont(font1);

        horizontalLayout_2->addWidget(RADIALbutton);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        FreqComboBox = new QComboBox(Label);
        FreqComboBox->setObjectName(QString::fromUtf8("FreqComboBox"));
        FreqComboBox->setMinimumSize(QSize(0, 35));
        FreqComboBox->setFont(font1);

        horizontalLayout_3->addWidget(FreqComboBox);

        freqNextUnit = new QCheckBox(Label);
        freqNextUnit->setObjectName(QString::fromUtf8("freqNextUnit"));
        freqNextUnit->setFont(font1);

        horizontalLayout_3->addWidget(freqNextUnit);


        verticalLayout_4->addLayout(horizontalLayout_3);

        MESSAGESgroupBox = new QGroupBox(Label);
        MESSAGESgroupBox->setObjectName(QString::fromUtf8("MESSAGESgroupBox"));
        gridLayout = new QGridLayout(MESSAGESgroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        VRrb = new QRadioButton(MESSAGESgroupBox);
        VRrb->setObjectName(QString::fromUtf8("VRrb"));
        VRrb->setFont(font1);

        gridLayout->addWidget(VRrb, 0, 0, 1, 1);

        ALTrb = new QRadioButton(MESSAGESgroupBox);
        ALTrb->setObjectName(QString::fromUtf8("ALTrb"));
        ALTrb->setFont(font1);

        gridLayout->addWidget(ALTrb, 0, 1, 1, 1);

        PTrb = new QRadioButton(MESSAGESgroupBox);
        PTrb->setObjectName(QString::fromUtf8("PTrb"));
        PTrb->setFont(font1);

        gridLayout->addWidget(PTrb, 1, 0, 1, 1);

        FLrb = new QRadioButton(MESSAGESgroupBox);
        FLrb->setObjectName(QString::fromUtf8("FLrb"));
        FLrb->setFont(font1);

        gridLayout->addWidget(FLrb, 1, 1, 1, 1);

        RADrb = new QRadioButton(MESSAGESgroupBox);
        RADrb->setObjectName(QString::fromUtf8("RADrb"));
        RADrb->setFont(font1);

        gridLayout->addWidget(RADrb, 2, 0, 1, 1);

        TMrb = new QRadioButton(MESSAGESgroupBox);
        TMrb->setObjectName(QString::fromUtf8("TMrb"));
        TMrb->setFont(font1);

        gridLayout->addWidget(TMrb, 2, 1, 1, 1);

        ROUTErb = new QRadioButton(MESSAGESgroupBox);
        ROUTErb->setObjectName(QString::fromUtf8("ROUTErb"));
        ROUTErb->setFont(font1);

        gridLayout->addWidget(ROUTErb, 3, 0, 1, 1);


        verticalLayout_4->addWidget(MESSAGESgroupBox);

        MessageComboBox = new QComboBox(Label);
        MessageComboBox->setObjectName(QString::fromUtf8("MessageComboBox"));
        MessageComboBox->setMinimumSize(QSize(370, 35));
        MessageComboBox->setFont(font1);

        verticalLayout_4->addWidget(MessageComboBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        RATElabel = new QLabel(Label);
        RATElabel->setObjectName(QString::fromUtf8("RATElabel"));
        RATElabel->setFont(font1);

        verticalLayout_3->addWidget(RATElabel);

        TIMElabel = new QLabel(Label);
        TIMElabel->setObjectName(QString::fromUtf8("TIMElabel"));
        TIMElabel->setFont(font1);

        verticalLayout_3->addWidget(TIMElabel);

        RADIALlabel = new QLabel(Label);
        RADIALlabel->setObjectName(QString::fromUtf8("RADIALlabel"));
        RADIALlabel->setFont(font1);

        verticalLayout_3->addWidget(RADIALlabel);

        ALTITUDElabel = new QLabel(Label);
        ALTITUDElabel->setObjectName(QString::fromUtf8("ALTITUDElabel"));
        ALTITUDElabel->setFont(font1);

        verticalLayout_3->addWidget(ALTITUDElabel);

        DISTANCElabel = new QLabel(Label);
        DISTANCElabel->setObjectName(QString::fromUtf8("DISTANCElabel"));
        DISTANCElabel->setFont(font1);

        verticalLayout_3->addWidget(DISTANCElabel);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        RATElineEdit = new QLineEdit(Label);
        RATElineEdit->setObjectName(QString::fromUtf8("RATElineEdit"));
        RATElineEdit->setMinimumSize(QSize(0, 30));
        RATElineEdit->setFont(font1);

        verticalLayout_2->addWidget(RATElineEdit);

        TIMElineEdit = new QLineEdit(Label);
        TIMElineEdit->setObjectName(QString::fromUtf8("TIMElineEdit"));
        TIMElineEdit->setMinimumSize(QSize(0, 30));
        TIMElineEdit->setFont(font1);

        verticalLayout_2->addWidget(TIMElineEdit);

        RADIALlineEdit = new QLineEdit(Label);
        RADIALlineEdit->setObjectName(QString::fromUtf8("RADIALlineEdit"));
        RADIALlineEdit->setMinimumSize(QSize(0, 30));
        RADIALlineEdit->setFont(font1);

        verticalLayout_2->addWidget(RADIALlineEdit);

        ALTITUDElineEdit = new QLineEdit(Label);
        ALTITUDElineEdit->setObjectName(QString::fromUtf8("ALTITUDElineEdit"));
        ALTITUDElineEdit->setMinimumSize(QSize(0, 30));
        ALTITUDElineEdit->setFont(font1);

        verticalLayout_2->addWidget(ALTITUDElineEdit);

        DISTANCElineEdit = new QLineEdit(Label);
        DISTANCElineEdit->setObjectName(QString::fromUtf8("DISTANCElineEdit"));
        DISTANCElineEdit->setMinimumSize(QSize(0, 30));
        DISTANCElineEdit->setFont(font1);

        verticalLayout_2->addWidget(DISTANCElineEdit);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_4);

        trackComboBox = new QComboBox(Label);
        trackComboBox->setObjectName(QString::fromUtf8("trackComboBox"));
        trackComboBox->setMinimumSize(QSize(0, 35));
        trackComboBox->setFont(font1);

        verticalLayout_4->addWidget(trackComboBox);

        pointComboBox = new QComboBox(Label);
        pointComboBox->setObjectName(QString::fromUtf8("pointComboBox"));
        pointComboBox->setMinimumSize(QSize(0, 35));
        pointComboBox->setFont(font1);

        verticalLayout_4->addWidget(pointComboBox);

        uplinkButton = new QPushButton(Label);
        uplinkButton->setObjectName(QString::fromUtf8("uplinkButton"));
        uplinkButton->setMinimumSize(QSize(0, 35));

        verticalLayout_4->addWidget(uplinkButton);

        cancelButton = new QPushButton(Label);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMinimumSize(QSize(0, 35));

        verticalLayout_4->addWidget(cancelButton);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        resumeOwnNavigationButton = new QPushButton(Label);
        resumeOwnNavigationButton->setObjectName(QString::fromUtf8("resumeOwnNavigationButton"));
        resumeOwnNavigationButton->setMinimumSize(QSize(0, 35));

        horizontalLayout_8->addWidget(resumeOwnNavigationButton);

        disregardButton = new QPushButton(Label);
        disregardButton->setObjectName(QString::fromUtf8("disregardButton"));
        disregardButton->setMinimumSize(QSize(0, 35));

        horizontalLayout_8->addWidget(disregardButton);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        rogerButton = new QPushButton(Label);
        rogerButton->setObjectName(QString::fromUtf8("rogerButton"));
        rogerButton->setMinimumSize(QSize(0, 35));

        horizontalLayout_7->addWidget(rogerButton);

        affirmButton = new QPushButton(Label);
        affirmButton->setObjectName(QString::fromUtf8("affirmButton"));
        affirmButton->setMinimumSize(QSize(0, 35));

        horizontalLayout_7->addWidget(affirmButton);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        negativeButton = new QPushButton(Label);
        negativeButton->setObjectName(QString::fromUtf8("negativeButton"));
        negativeButton->setMinimumSize(QSize(0, 35));

        horizontalLayout_6->addWidget(negativeButton);

        logOnButton = new QPushButton(Label);
        logOnButton->setObjectName(QString::fromUtf8("logOnButton"));
        logOnButton->setMinimumSize(QSize(0, 35));

        horizontalLayout_6->addWidget(logOnButton);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        contactRequestButton = new QPushButton(Label);
        contactRequestButton->setObjectName(QString::fromUtf8("contactRequestButton"));
        contactRequestButton->setMinimumSize(QSize(0, 35));

        horizontalLayout_5->addWidget(contactRequestButton);

        contactRequestVoiceButton = new QPushButton(Label);
        contactRequestVoiceButton->setObjectName(QString::fromUtf8("contactRequestVoiceButton"));
        contactRequestVoiceButton->setMinimumSize(QSize(0, 35));

        horizontalLayout_5->addWidget(contactRequestVoiceButton);


        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_9->addLayout(verticalLayout_4);


        retranslateUi(Label);

        QMetaObject::connectSlotsByName(Label);
    } // setupUi

    void retranslateUi(QWidget *Label)
    {
        Label->setWindowTitle(QApplication::translate("Label", "Form", 0, QApplication::UnicodeUTF8));
        callSign->setText(QApplication::translate("Label", "CallSign", 0, QApplication::UnicodeUTF8));
        FLlabel_current->setText(QApplication::translate("Label", "FL", 0, QApplication::UnicodeUTF8));
        FLQNH->setText(QApplication::translate("Label", "QNH", 0, QApplication::UnicodeUTF8));
        RADIALlabel_current->setText(QApplication::translate("Label", "RADIAL", 0, QApplication::UnicodeUTF8));
        RADIALbutton->setText(QApplication::translate("Label", "RADIAL", 0, QApplication::UnicodeUTF8));
        freqNextUnit->setText(QApplication::translate("Label", "Next Unit", 0, QApplication::UnicodeUTF8));
        MESSAGESgroupBox->setTitle(QApplication::translate("Label", "MESSAGES", 0, QApplication::UnicodeUTF8));
        VRrb->setText(QApplication::translate("Label", "Vertical Rate", 0, QApplication::UnicodeUTF8));
        ALTrb->setText(QApplication::translate("Label", "Altitude", 0, QApplication::UnicodeUTF8));
        PTrb->setText(QApplication::translate("Label", "Point", 0, QApplication::UnicodeUTF8));
        FLrb->setText(QApplication::translate("Label", "Flight Level", 0, QApplication::UnicodeUTF8));
        RADrb->setText(QApplication::translate("Label", "Radial", 0, QApplication::UnicodeUTF8));
        TMrb->setText(QApplication::translate("Label", "Time", 0, QApplication::UnicodeUTF8));
        ROUTErb->setText(QApplication::translate("Label", "Route", 0, QApplication::UnicodeUTF8));
        RATElabel->setText(QApplication::translate("Label", "Vertical Rate:", 0, QApplication::UnicodeUTF8));
        TIMElabel->setText(QApplication::translate("Label", "Time:", 0, QApplication::UnicodeUTF8));
        RADIALlabel->setText(QApplication::translate("Label", "Radial:", 0, QApplication::UnicodeUTF8));
        ALTITUDElabel->setText(QApplication::translate("Label", "Altitude:", 0, QApplication::UnicodeUTF8));
        DISTANCElabel->setText(QApplication::translate("Label", "Distance:", 0, QApplication::UnicodeUTF8));
        uplinkButton->setText(QApplication::translate("Label", "UPLINK", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Label", "CANCEL", 0, QApplication::UnicodeUTF8));
        resumeOwnNavigationButton->setText(QApplication::translate("Label", "RESUME OWN NAVIGATION", 0, QApplication::UnicodeUTF8));
        disregardButton->setText(QApplication::translate("Label", "DISREGARD", 0, QApplication::UnicodeUTF8));
        rogerButton->setText(QApplication::translate("Label", "ROGER", 0, QApplication::UnicodeUTF8));
        affirmButton->setText(QApplication::translate("Label", "AFFIRM", 0, QApplication::UnicodeUTF8));
        negativeButton->setText(QApplication::translate("Label", "NEGATIVE", 0, QApplication::UnicodeUTF8));
        logOnButton->setText(QApplication::translate("Label", "LOG ON", 0, QApplication::UnicodeUTF8));
        contactRequestButton->setText(QApplication::translate("Label", "CONTACT REQUEST", 0, QApplication::UnicodeUTF8));
        contactRequestVoiceButton->setText(QApplication::translate("Label", "CONTACT REQUEST VOICE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Label: public Ui_Label {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABEL_H
