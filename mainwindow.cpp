#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>
#include <QDebug>
#include <QTime>
#include <QSound>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("CPDLC ATC/Pilot Login");

    timeSyncDialog = new TimeSyncDialog(this);
    timeSyncDialog->setWindowTitle("Time Synchronization");

    radarMainWindow = new RadarWindow(this);
    radarMainWindow->setWindowTitle("RADAR");

    setFixedSize(800,500);

    QNHChecked_status = false;

    QRegExp rx("[A-Z0-9]+");
    QRegExpValidator *regExpValidator = new QRegExpValidator(rx,this);
    ui->CallSignLineEdit->setValidator(regExpValidator);

    QPixmap pixmap(":/icons/images/Wallpaper.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, pixmap);
    qApp->setPalette(palette);

    QString loginbutton = QString("QPushButton {background-color: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #00ffff stop: 1 #000066);"
                                  "color: white;"
                                  "border-style: outset;"
                                  "border-width: 1px;"
                                  "border-radius: 4px;"
                                  "border-color: beige;"
                                  "border-style: solid;"
                                  "padding: 1px;"
                                  "font:  bold 16px 'MS Shell Dlg 2';}"
                     "QPushButton:pressed {background-color: white;"
                                  "border-style: inset;}"
                     "QPushButton:hover {background-color: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffffff stop: 1 #99ccff);"
                                  "color: black;}"
                     "QPushButton:focus:pressed {background-color: yellow;}");

    QString introLabel = QString("QLabel {font: bold 14px 'MS Shell Dlg 2';"
                                 "color: white;}");
    QString introLineEdit = QString("QLineEdit {background-color: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffffff stop: 1 #99ccff);"
                                    "font: bold 14px 'MS Shell Dlg 2';"
                                    "color: black;"
                                    "border-width: 1px;"
                                    "border-radius: 4px;}");
    QString introGroupBox = QString("QGroupBox {font: bold 14px 'MS Shell Dlg 2';"
                                    "color: white;}");
    QString introRadioButton = QString("QRadioButton {font: bold 14px 'MS Shell Dlg 2';"
                                       "color: white;}");
    QString ATCbutton = QString("QPushButton {background-color: QLinearGradient( x1: 0, y1: 1, x2: 1, y2: 1, stop: 0 #00ff00 stop: 0.2 #000000  stop: 0.8 #000000 stop: 1 #00ff00);"
                                "color: white;"
                                "border-style: outset;"
                                "border-width: 1px;"
                                "border-radius: 4px;"
                                "border-color: beige;"
                                "border-style: solid;"
                                "padding: 1px;"
                                "font: bold 14px 'MS Shell Dlg 2';}"
                   "QPushButton:pressed {background-color: white;"
                                "border-style: inset;}"
                   "QPushButton:hover {background-color: QLinearGradient( x1: 0, y1: 1, x2: 1, y2: 1, stop: 0 #999999 stop: 0.5 #00ff00 stop: 1 #999999);"
                                "color: black;}"
                   "QPushButton:focus:pressed {background-color: yellow;}");
    QString ATClabel = QString("QLabel {font: bold 14px 'MS Shell Dlg 2';"
                               "color: black;}");

    QString ATCLineEdit = QString("QLineEdit {background-color: white;"
                                  "font: bold 14px 'MS Shell Dlg 2';"
                                  "color: black;"
                                  "border-style: outset;"
                                  "border-color: black;"
                                  "border-width: 1px;"
                                  "border-radius: 2px;}");


    ui->ATCToLabel->setStyleSheet(ATClabel);
    ui->ATCSendLineEdit->setStyleSheet(ATCLineEdit);
    ui->ATCSendButton->setStyleSheet(ATCbutton);
    ui->ATCTimeButton->setStyleSheet(ATCbutton);

    ui->ATCRadioButton->setStyleSheet(introRadioButton);
    ui->PilotRadioButton->setStyleSheet(introRadioButton);
    ui->groupBox->setStyleSheet(introGroupBox);
    ui->HostNameLineEdit->setStyleSheet(introLineEdit);
    ui->CallSignLineEdit->setStyleSheet(introLineEdit);
    ui->STRIPdataFrom->setStyleSheet(introLineEdit);
    ui->label->setStyleSheet(introLabel);
    ui->label_2->setStyleSheet(introLabel);
    ui->STRIPdataFromLabel->setStyleSheet(introLabel);
    ui->LoginButton->setStyleSheet(loginbutton);


    history = false;
    stbyclicked = false;
    ui->ATCTextEdit->setReadOnly(true);
    ui->ATCTextEdit->setEnabled(true);
    ui->pilotTextEdit->setReadOnly(true);
    ui->pilotTextEdit->setEnabled(true);

    QPalette p = ui->FMCTimeLineEdit->palette();
    p.setColor(QPalette::Base, QColor("black"));
    p.setColor(QPalette::Text, QColor("lime"));
    ui->FMCCallSignLineEdit->setPalette(p);
    ui->FMCMsgLineEdit->setPalette(p);
    ui->FMCTimeLineEdit->setPalette(p);
    ui->FMCCallSignLineEdit->setAlignment(Qt::AlignCenter);
    ui->FMCMsgLineEdit->setAlignment(Qt::AlignCenter);
    ui->FMCTimeLineEdit->setAlignment(Qt::AlignCenter);
    msg = false;


    ui->fmcButton_L1->setText("");
    ui->fmcButton_L2->setText("");
    ui->fmcButton_L3->setText("");
    ui->fmcButton_L4->setText("");
    ui->fmcButton_R1->setText("");
    ui->fmcButton_R2->setText("");
    ui->fmcButton_R3->setText("");
    ui->fmcButton_R4->setText("");

    ui->fmcLabel_L1->setText("");
    ui->fmcLabel_L1->setStyleSheet("QLabel {background-color: black; color: white;}");
    ui->fmcLabel_L2->setText("");
    ui->fmcLabel_L2->setStyleSheet("QLabel {background-color: black; color: white;}");
    ui->fmcLabel_L3->setText("");
    ui->fmcLabel_L3->setStyleSheet("QLabel {background-color: black; color: white;}");
    ui->fmcLabel_L4->setText("");
    ui->fmcLabel_L4->setStyleSheet("QLabel {background-color: black; color: white;}");
    ui->fmcLabel_R1->setText("");
    ui->fmcLabel_R1->setStyleSheet("QLabel {background-color: black; color: white;}");
    ui->fmcLabel_R2->setText("");
    ui->fmcLabel_R2->setStyleSheet("QLabel {background-color: black; color: white;}");
    ui->fmcLabel_R3->setText("");
    ui->fmcLabel_R3->setStyleSheet("QLabel {background-color: black; color: white;}");
    ui->fmcLabel_R4->setText("");
    ui->fmcLabel_R4->setStyleSheet("QLabel {background-color: black; color: white;}");
    ui->fmcLabel_main->setText("");
    ui->fmcLabel_main->setStyleSheet("QLabel {background-color: black; color: white;}");
    ui->fmcLabel_main->setAlignment(Qt::AlignCenter);

    setSTATUS("WELCOME");

    QString buttonString = QString(
    "QPushButton {background-color: black;"
                 "border-image: url(:/icons/images/button_1.png);"
                 "color: white;"
                 "border-style: outset;"
                 "border-width: 0px;"
                 "border-radius: 5px;"
                 "border-color: beige;"
                 "border-style: solid;"
                 "padding: 0px;"
                 "width: 48px;"
                 "height: 30px;"
                 "font:  bold 18px 'Courier';}"
    "QPushButton:pressed {border-image: url(:/icons/images/button_2.png);}");

    QString keyPadString = QString(
                "QPushButton {background-color: black;"
                             "border-image: url(:/icons/images/button6+.png);"
                             "color: white;"
                             "border-style: outset;"
                             "border-width: 0px;"
                             "border-radius: 5px;"
                             "border-color: beige;"
                             "border-style: solid;"
                             "padding: 0px;"
                             "width: 42px;"
                             "height: 42px;"
                             "font:  bold 18px 'Courier';}"
                "QPushButton:pressed {border-image: url(:/icons/images/button5+.png);}");

    QString numPadString = QString(
                "QPushButton {background-color: black;"
                             "border-image: url(:/icons/images/button3+.png);"
                             "color: white;"
                             "border-style: outset;"
                             "border-width: 0px;"
                             "border-radius: 5px;"
                             "border-color: beige;"
                             "border-style: solid;"
                             "padding: 0px;"
                             "width: 42px;"
                             "height: 42px;"
                             "font:  bold 18px 'Courier';}"
                "QPushButton:pressed {border-image: url(:/icons/images/button4+.png);}");

    QString longPadString = QString(
                "QPushButton {background-color: black;"
                             "border-image: url(:/icons/images/button8+.png);"
                             "color: white;"
                             "border-style: outset;"
                             "border-width: 0px;"
                             "border-radius: 5px;"
                             "border-color: beige;"
                             "border-style: solid;"
                             "padding: 0px;"
                             "width: 55px;"
                             "height: 35px;"
                             "font:  bold 18px 'Courier';}"
                "QPushButton:pressed {border-image: url(:/icons/images/button7+.png);}");

    QString menuPadString = QString(
                "QPushButton {background-color: black;"
                             "border-image: url(:/icons/images/button9+.png);"
                             "color: white;"
                             "border-style: outset;"
                             "border-width: 0px;"
                             "border-radius: 0px;"
                             "border-style: solid;"
                             "padding: 0px;"
                             "width: 50px;"
                             "height: 30px;"
                             "font:  bold 16px 'Courier';}"
                "QPushButton:pressed {border-image: url(:/icons/images/button10+.png);}");

    ui->pilotMenuButton->setStyleSheet(longPadString);
    ui->pilotMenuButton->setText("MENU");
    ui->pilotHistoryButton->setStyleSheet(longPadString);
    ui->pilotHistoryButton->setText("HIST");
    ui->pilotMessageButton->setStyleSheet(longPadString);
    ui->pilotMessageButton->setText("MSG");

    ui->fmcWILCObutton->setStyleSheet(menuPadString);
    ui->fmcROGERbutton->setStyleSheet(menuPadString);
    ui->fmcUNABLEbutton->setStyleSheet(menuPadString);
    ui->fmcSTANDBYbutton->setStyleSheet(menuPadString);
    ui->fmcSENDbutton->setStyleSheet(menuPadString);
    ui->fmcCANCELbutton->setStyleSheet(menuPadString);
    ui->fmcMODIFYbutton->setStyleSheet(menuPadString);
    ui->fmcOKbutton->setStyleSheet(menuPadString);
    ui->fmcPERFORMANCEbutton->setStyleSheet(menuPadString);
    ui->fmcWEATHERbutton->setStyleSheet(menuPadString);
    ui->fmcDISCARDbutton->setStyleSheet(menuPadString);

    ui->FMCCallSignLineEdit->setEnabled(false);
    ui->FMCTimeLineEdit->setEnabled(false);
    ui->FMCMsgLineEdit->setEnabled(false);
    ui->fmcWILCObutton->hide();
    ui->fmcROGERbutton->hide();
    ui->fmcSTANDBYbutton->hide();
    ui->fmcUNABLEbutton->hide();
    ui->fmcSENDbutton->hide();
    ui->fmcCANCELbutton->hide();
    ui->fmcMODIFYbutton->hide();
    ui->fmcDISCARDbutton->hide();
    ui->fmcOKbutton->hide();
    ui->fmcWEATHERbutton->hide();
    ui->fmcPERFORMANCEbutton->hide();
    messageClicked = "NONE";

    ui->keyPad_1->setText("A");
    ui->keyPad_2->setText("B");
    ui->keyPad_3->setText("C");
    ui->keyPad_4->setText("D");
    ui->keyPad_5->setText("E");
    ui->keyPad_6->setText("F");
    ui->keyPad_7->setText("G");
    ui->keyPad_8->setText("H");
    ui->keyPad_9->setText("I");
    ui->keyPad_10->setText("J");
    ui->keyPad_11->setText("K");
    ui->keyPad_12->setText("L");
    ui->keyPad_13->setText("M");
    ui->keyPad_14->setText("N");
    ui->keyPad_15->setText("O");
    ui->keyPad_16->setText("P");
    ui->keyPad_17->setText("Q");
    ui->keyPad_18->setText("R");
    ui->keyPad_19->setText("S");
    ui->keyPad_20->setText("T");
    ui->keyPad_21->setText("U");
    ui->keyPad_22->setText("V");
    ui->keyPad_23->setText("W");
    ui->keyPad_24->setText("X");
    ui->keyPad_25->setText("Y");
    ui->keyPad_26->setText("Z");
    ui->keyPad_27->setText("SP");
    ui->keyPad_28->setText("DEL");
    ui->keyPad_29->setText("/");
    ui->keyPad_30->setText("CLR");
    ui->keyPad_1->setStyleSheet(keyPadString);
    ui->keyPad_2->setStyleSheet(keyPadString);
    ui->keyPad_3->setStyleSheet(keyPadString);
    ui->keyPad_4->setStyleSheet(keyPadString);
    ui->keyPad_5->setStyleSheet(keyPadString);
    ui->keyPad_6->setStyleSheet(keyPadString);
    ui->keyPad_7->setStyleSheet(keyPadString);
    ui->keyPad_8->setStyleSheet(keyPadString);
    ui->keyPad_9->setStyleSheet(keyPadString);
    ui->keyPad_10->setStyleSheet(keyPadString);
    ui->keyPad_11->setStyleSheet(keyPadString);
    ui->keyPad_12->setStyleSheet(keyPadString);
    ui->keyPad_13->setStyleSheet(keyPadString);
    ui->keyPad_14->setStyleSheet(keyPadString);
    ui->keyPad_15->setStyleSheet(keyPadString);
    ui->keyPad_16->setStyleSheet(keyPadString);
    ui->keyPad_17->setStyleSheet(keyPadString);
    ui->keyPad_18->setStyleSheet(keyPadString);
    ui->keyPad_19->setStyleSheet(keyPadString);
    ui->keyPad_20->setStyleSheet(keyPadString);
    ui->keyPad_21->setStyleSheet(keyPadString);
    ui->keyPad_22->setStyleSheet(keyPadString);
    ui->keyPad_23->setStyleSheet(keyPadString);
    ui->keyPad_24->setStyleSheet(keyPadString);
    ui->keyPad_25->setStyleSheet(keyPadString);
    ui->keyPad_26->setStyleSheet(keyPadString);
    ui->keyPad_27->setStyleSheet(keyPadString);
    ui->keyPad_28->setStyleSheet(keyPadString);
    ui->keyPad_29->setStyleSheet(keyPadString);
    ui->keyPad_30->setStyleSheet(keyPadString);

    ui->numPad_1->setText("1");
    ui->numPad_2->setText("2");
    ui->numPad_3->setText("3");
    ui->numPad_4->setText("4");
    ui->numPad_5->setText("5");
    ui->numPad_6->setText("6");
    ui->numPad_7->setText("7");
    ui->numPad_8->setText("8");
    ui->numPad_9->setText("9");
    ui->numPad_10->setText(".");
    ui->numPad_11->setText("0");
    ui->numPad_12->setText("+/-");
    ui->numPad_1->setStyleSheet(numPadString);
    ui->numPad_2->setStyleSheet(numPadString);
    ui->numPad_3->setStyleSheet(numPadString);
    ui->numPad_4->setStyleSheet(numPadString);
    ui->numPad_5->setStyleSheet(numPadString);
    ui->numPad_6->setStyleSheet(numPadString);
    ui->numPad_7->setStyleSheet(numPadString);
    ui->numPad_8->setStyleSheet(numPadString);
    ui->numPad_9->setStyleSheet(numPadString);
    ui->numPad_10->setStyleSheet(numPadString);
    ui->numPad_11->setStyleSheet(numPadString);
    ui->numPad_12->setStyleSheet(numPadString);


    ui->fmcButton_L1->setStyleSheet(buttonString);
    ui->fmcButton_L2->setStyleSheet(buttonString);
    ui->fmcButton_L3->setStyleSheet(buttonString);
    ui->fmcButton_L4->setStyleSheet(buttonString);
    ui->fmcButton_R1->setStyleSheet(buttonString);
    ui->fmcButton_R2->setStyleSheet(buttonString);
    ui->fmcButton_R3->setStyleSheet(buttonString);
    ui->fmcButton_R4->setStyleSheet(buttonString);

    QPalette pal = ui->pilotTextEdit->palette();
    pal.setColor(QPalette::Base, QColor("black"));
    ui->ATCTextEdit->setPalette(pal);
    ui->pilotTextEdit->setPalette(pal);

    PilotsListWidget_overflight = new QListWidget(this);
    PilotListWidget_inbound = new QListWidget(this);
    PilotListWidget_outbound = new QListWidget(this);
    AtcListWidget = new QListWidget(this);

    createDockWindow();
    metar->layout()->setSpacing(0);         // nastavenie vzdialenosti medzi jednotlivymi widgetmi v dockwidget
    dock->layout()->setSpacing(0);
    pilotListDock->layout()->setSpacing(0);

    ui->PilotRadioButton->setChecked(true);
    if(ui->ATCRadioButton->isChecked() == true)
    {
        ui->STRIPdataFrom->show();
        ui->STRIPdataFromLabel->show();
        ui->CallSignLineEdit->setText("LZKZ");
    }
    else
    {
        ui->STRIPdataFrom->hide();
        ui->STRIPdataFromLabel->hide();
        ui->CallSignLineEdit->setText("CSA900");
    }

    RADIAL = "";
    POINT = "";
    ALTITUDE = "";
    VERTICALRATE = "";
    TIME = "";
    DISTANCE = "";
    TRACK = "";
    LEVEL = "";
    newMessage = "";
    ui->STRIPdataFrom->setText("STRIP.txt");
    StripDataFrom = ui->STRIPdataFrom->text();

    hashList.clear();

    TIMEtime = QTime::currentTime();
    TIMEstring = TIMEtime.toString("h:mm:ss");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(setCurrentTime()));
    timer->start(100);

    newMessageTimer = new QTimer(this);
    connect(newMessageTimer, SIGNAL(timeout()), this, SLOT(newMessageTimeout()));

    sentMessageTimer = new QTimer(this);
    connect(sentMessageTimer, SIGNAL(timeout()), this, SLOT(sentMessageTimeout()));

    ui->HostNameLineEdit->setText("localhost");
    ui->stackedWidget->setCurrentWidget(ui->loginPage);

    socket = new QTcpSocket(this);

    connect(this, SIGNAL(messageFromFlightSim(QString,QString)), radarMainWindow, SLOT(dataFromFlightSim(QString,QString)));
    connect(this, SIGNAL(sendSTRIPDataFrom(QString)), radarMainWindow, SLOT(getSTRIPDataFrom(QString)));
    connect(radarMainWindow, SIGNAL(closed_connection(QString)), this, SIGNAL(terminate_clicked(QString)));
    connect(radarMainWindow, SIGNAL(CFLclicked(QString,QString,QString)), this, SLOT(CFLclicked_slot(QString,QString,QString)));
    connect(radarMainWindow, SIGNAL(NextPointETE(QString,QString,double)), this, SLOT(overwriteNextPointETE(QString,QString,double)));
    connect(radarMainWindow, SIGNAL(sendDirectWP(QString,QString)), this, SLOT(changeDirectWP_slot(QString,QString)));

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(ui->ATCSendLineEdit, SIGNAL(returnPressed()), ui->ATCSendButton, SLOT(animateClick()));
    connect(ui->HostNameLineEdit, SIGNAL(returnPressed()), ui->LoginButton, SLOT(animateClick()));
    connect(ui->CallSignLineEdit, SIGNAL(returnPressed()), ui->LoginButton, SLOT(animateClick()));
    connect(ui->LoginButton, SIGNAL(clicked()), this, SLOT(loginButton_clicked()));
    connect(ui->ATCSendButton, SIGNAL(clicked()), this, SLOT(ATCSendButton_clicked()));
    connect(AtcListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ATCListWidget_clicked(QListWidgetItem*)));
    connect(PilotsListWidget_overflight, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(pilotListWidget_OF_clicked(QListWidgetItem*)));
    connect(PilotsListWidget_overflight, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(showStrip_OF()));
    connect(PilotsListWidget_overflight, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(showLabel_OF()));
    connect(PilotListWidget_inbound, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(pilotListWidget_IN_clicked(QListWidgetItem*)));
    connect(PilotListWidget_inbound, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(showStrip_IN()));
    connect(PilotListWidget_inbound, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(showLabel_IN()));
    connect(PilotListWidget_outbound, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(pilotListWidget_OU_clicked(QListWidgetItem*)));
    connect(PilotListWidget_outbound, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(showStrip_OU()));
    connect(PilotListWidget_outbound, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(showLabel_OU()));
    connect(ui->ATCRadioButton, SIGNAL(clicked()), this, SLOT(ATCPilotRadioButtonChanged()));
    connect(ui->PilotRadioButton, SIGNAL(clicked()), this, SLOT(ATCPilotRadioButtonChanged()));
    connect(ui->ATCTimeButton, SIGNAL(clicked()), this, SLOT(initTimeSync()));
    connect(ui->pilotHistoryButton, SIGNAL(clicked()), this, SLOT(history_clicked()));
    connect(ui->pilotMenuButton, SIGNAL(clicked()), this, SLOT(pilotMenuButton_clicked()));
    connect(ui->pilotMessageButton, SIGNAL(clicked()), this, SLOT(pilotMSGButton_clicked()));
    connect(ui->fmcWILCObutton, SIGNAL(clicked()), this, SLOT(WILCObutton_clicked()));
    connect(ui->fmcROGERbutton, SIGNAL(clicked()), this, SLOT(ROGERbutton_clicked()));
    connect(ui->fmcUNABLEbutton, SIGNAL(clicked()), this, SLOT(UNABLEbutton_clicked()));
    connect(ui->fmcSTANDBYbutton, SIGNAL(clicked()), this, SLOT(STANDBYbutton_clicked()));
    connect(ui->fmcSENDbutton, SIGNAL(clicked()), this, SLOT(SENDbutton_clicked()));
    connect(ui->fmcCANCELbutton, SIGNAL(clicked()), this, SLOT(CANCELbutton_clicked()));
    connect(ui->fmcDISCARDbutton, SIGNAL(clicked()), this, SLOT(DISCARDbutton_clicked()));
    connect(ui->fmcMODIFYbutton, SIGNAL(clicked()), this, SLOT(MODIFYbutton_clicked()));
    connect(ui->fmcOKbutton, SIGNAL(clicked()), this, SLOT(OKbutton_clicked()));
    connect(ui->fmcPERFORMANCEbutton, SIGNAL(clicked()), this, SLOT(PERFORMANCEbutton_clicked()));
    connect(ui->fmcWEATHERbutton, SIGNAL(clicked()), this, SLOT(WEATHERbutton_clicked()));
    connect(ui->ATCTextEdit, SIGNAL(textChanged()), this, SLOT(autosave()));

    connect(metar, SIGNAL(metarSend(QString)), label, SLOT(getMetarData(QString)));

    connect(timeSyncDialog,SIGNAL(setTime_signal(QString)), this, SLOT(getInitTime(QString)));

    connect(label, SIGNAL(FLchange_pending(const QString&)), this, SLOT(FLChange_pending(const QString&)));
    connect(label, SIGNAL(change_uplink()), ui->ATCSendButton, SLOT(animateClick()));
    connect(label, SIGNAL(change_cancelled(const QString&)), this, SLOT(change_cancelled(const QString&)));
    connect(label, SIGNAL(frequencyChange_pending(const QString&)), this, SLOT(labelChange_pending(const QString&)));
    connect(label, SIGNAL(RADIALchange_pending(const QString&)), this, SLOT(RADIALChange_pending(const QString&)));
    connect(label, SIGNAL(messageChanged(const QString&)), this, SLOT(messageChange_slot(const QString&)));
    connect(label, SIGNAL(pointChange_pending(const QString&)), this, SLOT(POINTchange_pending(const QString&)));
    connect(label, SIGNAL(trackChange_pending(const QString&)), this, SLOT(TRACKchange_pending(const QString&)));
    connect(label, SIGNAL(DISTANCEchange_pending(const QString&)), this, SLOT(DISTANCEchanged_pending(const QString&)));
    connect(label, SIGNAL(ALTITUDEchange_pending(const QString&)), this, SLOT(ALTITUDEchanged_pending(const QString&)));
    connect(label, SIGNAL(TIMEchange_pending(const QString&)), this, SLOT(TIMEchange_pending(const QString&)));
    connect(label, SIGNAL(RATEchange_pending(const QString&)), this, SLOT(RATEchange_pending(const QString&)));
    connect(label, SIGNAL(roger_signal(QString)), this, SLOT(SpecialButtonClicked(QString)));
    connect(label, SIGNAL(disregard_signal(QString)), this, SLOT(SpecialButtonClicked(QString)));
    connect(label, SIGNAL(affirm_signal(QString)), this, SLOT(SpecialButtonClicked(QString)));
    connect(label, SIGNAL(negative_signal(QString)), this, SLOT(SpecialButtonClicked(QString)));
    connect(label, SIGNAL(contactRequest_signal(QString)), this, SLOT(SpecialButtonClicked(QString)));
    connect(label, SIGNAL(contactRequestVoice_signal(QString)), this, SLOT(SpecialButtonClicked(QString)));
    connect(label, SIGNAL(logOn_signal(QString)), this, SLOT(SpecialButtonClicked(QString)));
    connect(label, SIGNAL(resumeOwnNavigation_signal(QString)), this, SLOT(SpecialButtonClicked(QString)));

    connect(this, SIGNAL(timeToMetar(QString)), metar, SLOT(setTime(QString)));
    connect(this, SIGNAL(timeToTime(QString)), time, SLOT(setTime(QString)));

    connect(ui->fmcButton_L1, SIGNAL(clicked()), this, SLOT(fmcButtonL1clicked()));
    connect(ui->fmcButton_L2, SIGNAL(clicked()), this, SLOT(fmcButtonL2clicked()));
    connect(ui->fmcButton_L3, SIGNAL(clicked()), this, SLOT(fmcButtonL3clicked()));
    connect(ui->fmcButton_L4, SIGNAL(clicked()), this, SLOT(fmcButtonL4clicked()));
    connect(ui->fmcButton_R1, SIGNAL(clicked()), this, SLOT(fmcButtonR1clicked()));
    connect(ui->fmcButton_R2, SIGNAL(clicked()), this, SLOT(fmcButtonR2clicked()));
    connect(ui->fmcButton_R3, SIGNAL(clicked()), this, SLOT(fmcButtonR3clicked()));
    connect(ui->fmcButton_R4, SIGNAL(clicked()), this, SLOT(fmcButtonR4clicked()));

    connect(ui->keyPad_1, SIGNAL(clicked()), this, SLOT(keyPad_1_clicked()));
    connect(ui->keyPad_2, SIGNAL(clicked()), this, SLOT(keyPad_2_clicked()));
    connect(ui->keyPad_3, SIGNAL(clicked()), this, SLOT(keyPad_3_clicked()));
    connect(ui->keyPad_4, SIGNAL(clicked()), this, SLOT(keyPad_4_clicked()));
    connect(ui->keyPad_5, SIGNAL(clicked()), this, SLOT(keyPad_5_clicked()));
    connect(ui->keyPad_6, SIGNAL(clicked()), this, SLOT(keyPad_6_clicked()));
    connect(ui->keyPad_7, SIGNAL(clicked()), this, SLOT(keyPad_7_clicked()));
    connect(ui->keyPad_8, SIGNAL(clicked()), this, SLOT(keyPad_8_clicked()));
    connect(ui->keyPad_9, SIGNAL(clicked()), this, SLOT(keyPad_9_clicked()));
    connect(ui->keyPad_10, SIGNAL(clicked()), this, SLOT(keyPad_10_clicked()));
    connect(ui->keyPad_11, SIGNAL(clicked()), this, SLOT(keyPad_11_clicked()));
    connect(ui->keyPad_12, SIGNAL(clicked()), this, SLOT(keyPad_12_clicked()));
    connect(ui->keyPad_13, SIGNAL(clicked()), this, SLOT(keyPad_13_clicked()));
    connect(ui->keyPad_14, SIGNAL(clicked()), this, SLOT(keyPad_14_clicked()));
    connect(ui->keyPad_15, SIGNAL(clicked()), this, SLOT(keyPad_15_clicked()));
    connect(ui->keyPad_16, SIGNAL(clicked()), this, SLOT(keyPad_16_clicked()));
    connect(ui->keyPad_17, SIGNAL(clicked()), this, SLOT(keyPad_17_clicked()));
    connect(ui->keyPad_18, SIGNAL(clicked()), this, SLOT(keyPad_18_clicked()));
    connect(ui->keyPad_19, SIGNAL(clicked()), this, SLOT(keyPad_19_clicked()));
    connect(ui->keyPad_20, SIGNAL(clicked()), this, SLOT(keyPad_20_clicked()));
    connect(ui->keyPad_21, SIGNAL(clicked()), this, SLOT(keyPad_21_clicked()));
    connect(ui->keyPad_22, SIGNAL(clicked()), this, SLOT(keyPad_22_clicked()));
    connect(ui->keyPad_23, SIGNAL(clicked()), this, SLOT(keyPad_23_clicked()));
    connect(ui->keyPad_24, SIGNAL(clicked()), this, SLOT(keyPad_24_clicked()));
    connect(ui->keyPad_25, SIGNAL(clicked()), this, SLOT(keyPad_25_clicked()));
    connect(ui->keyPad_26, SIGNAL(clicked()), this, SLOT(keyPad_26_clicked()));
    connect(ui->keyPad_27, SIGNAL(clicked()), this, SLOT(keyPad_27_clicked()));
    connect(ui->keyPad_28, SIGNAL(clicked()), this, SLOT(keyPad_28_clicked()));
    connect(ui->keyPad_29, SIGNAL(clicked()), this, SLOT(keyPad_29_clicked()));
    connect(ui->keyPad_30, SIGNAL(clicked()), this, SLOT(keyPad_30_clicked()));

    connect(ui->numPad_1, SIGNAL(clicked()), this, SLOT(numPad_1_clicked()));
    connect(ui->numPad_2, SIGNAL(clicked()), this, SLOT(numPad_2_clicked()));
    connect(ui->numPad_3, SIGNAL(clicked()), this, SLOT(numPad_3_clicked()));
    connect(ui->numPad_4, SIGNAL(clicked()), this, SLOT(numPad_4_clicked()));
    connect(ui->numPad_5, SIGNAL(clicked()), this, SLOT(numPad_5_clicked()));
    connect(ui->numPad_6, SIGNAL(clicked()), this, SLOT(numPad_6_clicked()));
    connect(ui->numPad_7, SIGNAL(clicked()), this, SLOT(numPad_7_clicked()));
    connect(ui->numPad_8, SIGNAL(clicked()), this, SLOT(numPad_8_clicked()));
    connect(ui->numPad_9, SIGNAL(clicked()), this, SLOT(numPad_9_clicked()));
    connect(ui->numPad_10, SIGNAL(clicked()), this, SLOT(numPad_10_clicked()));
    connect(ui->numPad_11, SIGNAL(clicked()), this, SLOT(numPad_11_clicked()));
    connect(ui->numPad_12, SIGNAL(clicked()), this, SLOT(numPad_12_clicked()));

    connect(metar, SIGNAL(sendQNH(QString)), label, SLOT(getQNH(QString)));
    connect(metar, SIGNAL(sendQNH(QString)), this, SLOT(getQNH(QString)));
    connect(label, SIGNAL(QNHChecked(bool)), this, SLOT(QNHChecked_slot(bool)));

    MetarAction = new QAction(QIcon(":/icons/images/metar-icon.png"),tr("metar"),this);
    MetarAction->setShortcut(tr("Alt+M"));
    MetarAction->setToolTip("Show Metar");
    MetarAction->setStatusTip("Show hidden Metar dock widget");
    connect(MetarAction, SIGNAL(triggered()), this, SLOT(showMetarDock()));

    PostsAction = new QAction(QIcon(":/icons/images/posts-icon.png"),tr("posts"),this);
    PostsAction->setShortcut(tr("Alt+P"));
    PostsAction->setToolTip("Show Posts");
    PostsAction->setStatusTip("Show hidden Posts dock widget");
    connect(PostsAction, SIGNAL(triggered()), this, SLOT(showPostsDock()));

    AboutAction = new QAction(QIcon(":/icons/images/about-icon.png"),tr("posts"),this);
    AboutAction->setShortcut(tr("Alt+A"));
    AboutAction->setToolTip("Show Info");
    AboutAction->setStatusTip("Show Info about DLC application");
    connect(AboutAction, SIGNAL(triggered()), this, SLOT(showAboutDock()));

    TimeAction = new QAction (QIcon(":/icons/images/time-icon.png"),tr("time"), this);
    TimeAction->setShortcut(tr("Alt+T"));
    TimeAction->setToolTip("Show Time");
    TimeAction->setStatusTip("Show hiddem Time widget");
    connect(TimeAction, SIGNAL(triggered()), this, SLOT(showTimeDock()));

    RADARAction = new QAction(QIcon(":/icons/images/radar-icon.png"),tr("RADAR"),this);
    RADARAction->setShortcut(tr("ALT+R"));
    RADARAction->setToolTip("Show RADAR Window");
    RADARAction->setStatusTip("Show RADAR Window");
    connect(RADARAction, SIGNAL(triggered()), this, SLOT(showRADAR()));

    FileMenu = menuBar()->addMenu(tr("&File"));
    FileMenu->addAction(RADARAction);
    FileMenu->addAction(MetarAction);
    FileMenu->addAction(PostsAction);
    FileMenu->addAction(TimeAction);
    FileMenu->addAction(AboutAction);
    menuBar()->hide();
    ui->mainToolBar->addAction(AboutAction);
    ui->mainToolBar->addAction(MetarAction);
    ui->mainToolBar->addAction(TimeAction);
    ui->mainToolBar->addAction(PostsAction);
    ui->mainToolBar->addAction(RADARAction);
    ui->mainToolBar->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readSTRIP(const QString &fileName, const QString &CallSign)
{
    stripList.clear();
    QFile file(fileName);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }
    else
    {
        QString line;
        QStringList lineList;
        QTextStream stream(&file);

        while( !stream.atEnd())
        {
            line = stream.readLine();       // precita riadky postupne
            lineList = line.split("#");     // oddeli na CallSign a zbytok stripu

            if(lineList.at(0) == CallSign)  // hladam svoj CallSign
            {
                stripList = lineList.at(1).split(";");  // list celeho stripu pre danu CallSign
            }
        }
    }

    file.close();
}

void MainWindow::overwriteRAD(const QString &fileName, const QString &CallSign, const QString &rad)
{
    QStringList newList;
    QFile file(fileName);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }
    else
    {
        QString line;
        QStringList lineList;
        QTextStream stream(&file);
        QStringList stripLineList;

        while( !stream.atEnd())
        {
            line = stream.readLine();       // precita riadky postupne
            lineList = line.split("#");     // oddeli na CallSign a zbytok stripu

            if(lineList.at(0) == CallSign)  // hladam svoj CallSign
            {
                stripLineList = lineList.at(1).split(";");  // list celeho stripu pre danu CallSign
                stripLineList.replace(stripLineList.length()-2, rad);
                lineList.replace(1, stripLineList.join(";"));
            }
            line = lineList.join("#");
            newList.append(line);
        }
    }

    file.close();

    QFile file_2(fileName);
    if( !file_2.open( QIODevice::WriteOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file_2.fileName() << "for writing.";
    }
    else
    {
        QTextStream stream(&file_2);

        QListIterator<QString> iter(newList);
        while(iter.hasNext())
        {
            stream << iter.next() << "\n";
        }
    }

    file.close();
}

void MainWindow::overwriteFL(const QString &fileName, const QString &CallSign, const QString &FL)
{
    QStringList newList;
    QFile file(fileName);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }
    else
    {
        QString line;
        QStringList lineList;
        QTextStream stream(&file);
        QStringList stripLineList;

        while( !stream.atEnd())
        {
            line = stream.readLine();       // precita riadky postupne
            lineList = line.split("#");     // oddeli na CallSign a zbytok stripu

            if(lineList.at(0) == CallSign)  // hladam svoj CallSign
            {
                stripLineList = lineList.at(1).split(";");  // list celeho stripu pre danu CallSign
                stripLineList.replace(stripLineList.length()-3, FL);
                lineList.replace(1, stripLineList.join(";"));
            }
            line = lineList.join("#");
            newList.append(line);
        }
    }

    file.close();

    QFile file_2(fileName);
    if( !file_2.open( QIODevice::WriteOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file_2.fileName() << "for writing.";
    }
    else
    {
        QTextStream stream(&file_2);

        QListIterator<QString> iter(newList);
        while(iter.hasNext())
        {
            stream << iter.next() << "\n";
        }
    }

    file.close();
}

void MainWindow::overwriteLOGGED(const QString &fileName, const QString &CallSign, const QString &logged)
{
    QStringList newList;
    QFile file(fileName);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }
    else
    {
        QString line;
        QStringList lineList;
        QTextStream stream(&file);
        QStringList stripLineList;

        while( !stream.atEnd())
        {
            line = stream.readLine();       // precita riadky postupne
            lineList = line.split("#");     // oddeli na CallSign a zbytok stripu

            if(lineList.at(0) == CallSign)  // hladam svoj CallSign
            {
                stripLineList = lineList.at(1).split(";");  // list celeho stripu pre danu CallSign
                stripLineList.replace(stripLineList.length()-1, logged);
                lineList.replace(1, stripLineList.join(";"));
            }
            line = lineList.join("#");
            newList.append(line);
        }
    }

    file.close();

    QFile file_2(fileName);
    if( !file_2.open( QIODevice::WriteOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file_2.fileName() << "for writing.";
    }
    else
    {
        QTextStream stream(&file_2);

        QListIterator<QString> iter(newList);
        while(iter.hasNext())
        {
            stream << iter.next() << "\n";
        }
    }

    file.close();
}

QString MainWindow::getFLIGHTchar(const QStringList &StripList)
{
    QString FlightChar;
    if(!StripList.isEmpty())
    {
       FlightChar = StripList.at(0);
    }
    else
    {
       FlightChar = "NONE";
    }

    return FlightChar;
}

QString MainWindow::getARRPoint(const QStringList &StripList)
{
    QString ARRPoint;
    if(!StripList.isEmpty())
    {
       ARRPoint = StripList.at(1);
    }
    else
    {
       ARRPoint = "NONE";
    }

    return ARRPoint;
}

QString MainWindow::getARRFL(const QStringList &StripList)
{
    QString ARRFL;
    if(!StripList.isEmpty())
    {
       ARRFL = StripList.at(2);
    }
    else
    {
        ARRFL = "NONE";
    }

    return ARRFL;
}

QString MainWindow::getType(const QStringList &StripList)
{
    QString Type;
    if(!StripList.isEmpty())
    {
        Type = StripList.at(3);
    }
    else
    {
       Type = "NONE";
    }

    return Type;
}

QString MainWindow::getCruisingSpeed(const QStringList &StripList)
{
    QString CruisingSpeed;
    if(!StripList.isEmpty())
    {
       CruisingSpeed = StripList.at(4);
    }
    else
    {
       CruisingSpeed = "NONE";
    }

    return CruisingSpeed;
}

QString MainWindow::getDEP(const QStringList &StripList)
{
    QString DEP;
    if(!StripList.isEmpty())
    {
       DEP = StripList.at(5);
    }
    else
    {
       DEP = "NONE";
    }

    return DEP;
}

QString MainWindow::getARR(const QStringList &StripList)
{
    QString ARR;
    if(!StripList.isEmpty())
    {
       ARR = StripList.at(6);
    }
    else
    {
       ARR = "NONE";
    }

    return ARR;
}

QString MainWindow::getFL(const QStringList &StripList)
{
    QString FL;
    if(!StripList.isEmpty())
    {
       FL = StripList.at(StripList.length()-3);
    }
    else
    {
       FL = "NONE";
    }

    return FL;
}

QString MainWindow::getRADIAL(const QStringList &StripList)
{
    QString RADIAL;
    if(!StripList.isEmpty())
    {
       RADIAL = StripList.at(StripList.length()-2);
    }
    else
    {
       RADIAL = "NONE";
    }

    return RADIAL;
}

void MainWindow::showMETAR()
{
    QString callSign = ui->CallSignLineEdit->text();
    QString metarInfo = metar->getMetar(callSign);      // rovno aj zapise hodnoty QNH a Wind pomocou funkcie v metar.cpp

    metarDock->show();
}

void MainWindow::setInitTime(const QString &time)
{
    //qDebug() << time;
}

void MainWindow::changeCallSignColor(const QString &CallSign)
{
    //qDebug() << CallSign;

    for(int row=0; row<AtcListWidget->count(); row++)
    {
        QListWidgetItem *item = AtcListWidget->item(row);
        if(item->text() == CallSign)
            item->setBackground(Qt::red);
    }
    for(int row=0; row<PilotListWidget_inbound->count(); row++)
    {
        QListWidgetItem *item = PilotListWidget_inbound->item(row);
        if(item->text() == CallSign)
            item->setBackground(Qt::red);
    }
    for(int row=0; row<PilotsListWidget_overflight->count(); row++)
    {
        QListWidgetItem *item = PilotsListWidget_overflight->item(row);
        if(item->text() == CallSign)
            item->setBackground(Qt::red);
    }
    for(int row=0; row<PilotListWidget_outbound->count(); row++)
    {
        QListWidgetItem *item = PilotListWidget_outbound->item(row);
        if(item->text() == CallSign)
            item->setBackground(Qt::red);
    }
}

void MainWindow::updateMessage(const QString &message)
{
    QString newNewMessage = message;

    if(newNewMessage.contains("[RADIAL]"))
    {
        QRegExp rx("\\b(RADIAL)\\b");
        newNewMessage.replace(rx.indexIn(newNewMessage)-1, 8, RADIAL);
        ui->ATCSendLineEdit->setText(newNewMessage);
    }
    if(newNewMessage.contains("[POINT]"))
    {
        QRegExp rx("\\b(POINT)\\b");
        newNewMessage.replace(rx.indexIn(newNewMessage)-1, 7, POINT);
        ui->ATCSendLineEdit->setText(newNewMessage);
    }
    if(newMessage.contains("[ALTITUDE]"))
    {
        QRegExp rx("\\b(ALTITUDE)\\b");
        newNewMessage.replace(rx.indexIn(newNewMessage)-1, 10, ALTITUDE);
        ui->ATCSendLineEdit->setText(newNewMessage);
    }
    if(newNewMessage.contains("[VERTICALRATE]"))
    {
        QRegExp rx("\\b(VERTICALRATE)\\b");
        newNewMessage.replace(rx.indexIn(newNewMessage)-1, 14, VERTICALRATE);
        ui->ATCSendLineEdit->setText(newNewMessage);
    }
    if(newNewMessage.contains("[TIME]"))
    {
        QRegExp rx("\\b(TIME)\\b");
        newNewMessage.replace(rx.indexIn(newNewMessage)-1, 6, TIME);
        ui->ATCSendLineEdit->setText(newNewMessage);
    }
    if(newNewMessage.contains("[DISTANCE]"))
    {
        QRegExp rx("\\b(DISTANCE)\\b");
        newNewMessage.replace(rx.indexIn(newNewMessage)-1, 10, DISTANCE);
        ui->ATCSendLineEdit->setText(newNewMessage);
    }
    if(newNewMessage.contains("[TRACK]"))
    {
        QRegExp rx("\\b(TRACK)\\b");
        newNewMessage.replace(rx.indexIn(newNewMessage)-1, 7, TRACK);
        ui->ATCSendLineEdit->setText(newNewMessage);
    }
    if(newNewMessage.contains("[LEVEL]"))
    {
        QRegExp rx("\\b(LEVEL)\\b");
        newNewMessage.replace(rx.indexIn(newNewMessage)-1, 7, LEVEL);
        ui->ATCSendLineEdit->setText(newNewMessage);
    }

    if(QNHChecked_status == true)
    {
        //updateMessage(newMessage);
        ui->ATCSendLineEdit->setText(ui->ATCSendLineEdit->text() + " " + QNH);
    }
    else
    {
        //updateMessage(newMessage);
    }
}

void MainWindow::loginButton_clicked()
{
    socket->connectToHost(ui->HostNameLineEdit->text(), 4200);          // pripajam sa na port 4200
    QString loginMessage;
    QString callSign;

    if(ui->PilotRadioButton->isChecked())
    {
        loginMessage = "Pilot:";
    }
    else
    {
        loginMessage = "ATC:";
        StripDataFrom = ui->STRIPdataFrom->text();
    }

    callSign = ui->CallSignLineEdit->text();
    loginMessage += callSign;
    loginMessage = loginMessage + ":ALL Ready to communicate";          // vypise :ALL , teda posiela vsetkym, ale pilotovi by to zobrazit aj tak nemalo

    socket->write(loginMessage.toUtf8());
}

void MainWindow::ATCSendButton_clicked()
{    
    QString message = ui->ATCSendLineEdit->text().trimmed();

    QString TO = ui->ATCToLabel->text();
    QStringList TOList = TO.split(":");

    QString TOCallSign = TOList.at(1);
    QString ToPATC = TOList.at(0);

    QString FROMCallSign = ui->CallSignLineEdit->text();
    QString FromPATC = "ATC";

    QString loginMessage;

    if(ToPATC == "Pilot")
    {
        loginMessage = QString(FromPATC + ":" + FROMCallSign + ":" + TOCallSign);
    }
    else if (ToPATC == "ATC")
    {
        loginMessage = QString(FromPATC + ":" + FROMCallSign + ":" + TOCallSign);
    }
    else
    {
        loginMessage = QString(FromPATC + ":" + FROMCallSign + ":" + "ALL");
    }

    if(!message.isEmpty())
    {
        message = loginMessage + " " + message;
        socket->write(message.toUtf8());
        qDebug() << message;
    }

    ui->ATCSendLineEdit->clear();
    ui->ATCSendLineEdit->setFocus();

    RADIAL = "";
    POINT = "";
    ALTITUDE = "";
    VERTICALRATE = "";
    TIME = "";
    DISTANCE = "";
    TRACK = "";
    LEVEL = "";
}

void MainWindow::readyRead()
{
    QString ATCmessageColor = "<font color=\"White\">";
    QString PILOTmessageColor = "<font color=\"Lime\">";
    QString endHTML = "</font><br>";

    QSound sound("sound/CPDLC.wav");

    QString line = QString::fromUtf8(socket->readAll());        // prijata sprava
    QStringList messageList = line.split(" ");                  // rozdelim na volaci znak a spravu

    QRegExp usersRegex("^/users:(.*)$");
    if(usersRegex.indexIn(line) != -1)
    {
        QStringList users = usersRegex.cap(1).split(",");
        PilotsListWidget_overflight->clear();
        PilotListWidget_inbound->clear();
        PilotListWidget_outbound->clear();
        AtcListWidget->clear();
        ATCList.clear();

        CallSignListConnected.clear();

        foreach(QString user, users)
        {
            QStringList callSignList = user.split(":");
            QString CallSign = callSignList.at(1);

            //CallSignListConnected.append(CallSign);     // create list of connected users - pilot clients

            // not empty == check the content
            if(!callsignOld.isEmpty())
            {
                bool match = false;
                QListIterator<QString> iter(callsignOld);
                while(iter.hasNext())
                {
                    QString callsign = iter.next();
                    if(callsign == CallSign) // found match, do not open anything
                    {
                        match = true;
                    }
                }

                if(match == false)
                {
                    if(user.contains("Pilot"))
                    {
                        readSTRIP(StripDataFrom, CallSign);
                        QString flightChar = getFLIGHTchar(stripList);

                        if(ui->ATCRadioButton->isChecked())
                        {
                            if(flightChar == "INBOUND")
                                showStrip_inbound(CallSign);
                            if(flightChar == "OUTBOUND")
                                showStrip_outbound(CallSign);
                            if(flightChar == "OVERFLIGHT")
                                showStrip_overflight(CallSign);
                        }
                    }
                }
            }
            else
            {
                //qDebug() << "callSignOld by mal byt prazdny" << callsignOld;
                if(user.contains("Pilot"))
                {
                    readSTRIP(StripDataFrom, CallSign);
                    QString flightChar = getFLIGHTchar(stripList);

                    if(ui->ATCRadioButton->isChecked())
                    {
                        if(flightChar == "INBOUND")
                            showStrip_inbound(CallSign);
                        if(flightChar == "OUTBOUND")
                            showStrip_outbound(CallSign);
                        if(flightChar == "OVERFLIGHT")
                            showStrip_overflight(CallSign);
                    }
                }
            }

            bool CallsignMatch = false;
            QListIterator<QString> callsigniter(CallSignListConnected);
            qDebug() << CallSignListConnected;
            while(callsigniter.hasNext())
            {
                QString callsign = callsigniter.next();
                if(callsign == CallSign) // found match, do not open anything
                {
                    CallsignMatch = true;
                }
            }

            if(CallsignMatch == false)
            {
                CallSignListConnected.append(CallSign);

                if(user.contains("ATC"))
                {
                    new QListWidgetItem(QPixmap(":/icons/images/tower.png"),CallSign, AtcListWidget);
                    ATCList.append(CallSign);
                }
                else if(user.contains("Pilot"))
                {
                    readSTRIP(StripDataFrom, CallSign);
                    QString flightChar = getFLIGHTchar(stripList);

                    if(flightChar == "INBOUND")
                    {
                        new QListWidgetItem(QPixmap(":/icons/images/inbound.png"),CallSign, PilotListWidget_inbound);
                        //showStrip_inbound(CallSign);
                    }

                    if(flightChar == "OUTBOUND")
                    {
                        new QListWidgetItem(QPixmap(":/icons/images/outbound.png"),CallSign, PilotListWidget_outbound);
                        //showStrip_outbound(CallSign);
                    }

                    if(flightChar == "OVERFLIGHT")
                    {
                        new QListWidgetItem(QPixmap(":/icons/images/overflight.png"),CallSign, PilotsListWidget_overflight);
                        //showStrip_overflight(CallSign);
                    }
                }
            }
        }
        callsignOld = CallSignListConnected;

    }

    QStringList messageList2 = messageList.at(0).split(":");
    QString FROMCallSign = messageList2.at(1);
    QString TOCallSign = messageList2.at(2);
    QString FromPATC = messageList2.at(0);
    messageList.removeAt(0);

    QString message = messageList.join(" ");
    QStringList messageInitList;
    QString initMessage;
    if(message.contains("/users") && message.contains(":"))
    {
        messageInitList = message.split("/users");
        initMessage = messageInitList.at(0);
    }
    else
    {
        initMessage = message;
    }

    if(ui->PilotRadioButton->isChecked())
    {
        if((FromPATC == "Pilot") && (FROMCallSign == ui->CallSignLineEdit->text()))     // sprava pre pilota od pilota
        {

        }
        else if((FromPATC == "ATC") && (TOCallSign == ui->CallSignLineEdit->text()))    // sprava pre pilota od ATC
        {
            ATCFROMCALLSIGN = FROMCallSign;
            ui->pilotMenuButton->setEnabled(true);
            ui->pilotMessageButton->setEnabled(true);

            newMessageTimer->start(1000);
            ui->fmcLabel_L4->setText("NEW ATC MSG");
            if(STATUS == "VIEWMESSAGES")
                ui->pilotMessageButton->animateClick();
            int incomMessageLength = incomingMessageList.length();

            QString incomingTime = ui->FMCTimeLineEdit->text();

            if(incomMessageLength == 4)
            {
                incomingMessageList.removeFirst();
                incomingMessageList.append(initMessage);
                incomingMessageTimeList.removeFirst();
                incomingMessageTimeList.append(incomingTime);
            }
            else
            {
                incomingMessageList.append(initMessage);
                incomingMessageTimeList.append(incomingTime);
            }

            sound.play();

            if(initMessage.contains("AUTOMATED MESSAGE TO CONFIRM"))
            {
                QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
                QString secondPart = "/" + callSignList.at(1);
                QString whole = FROMCallSign + secondPart;
                ui->FMCCallSignLineEdit->setText(whole);
            }
        }
        else if((FromPATC == "ATC") && (TOCallSign == "ALL"))                           // sprava urcena vsetkym od ATC - zobrazi aj pilotovi
        {
            sound.play();

            if(initMessage.contains("TIME_SYNCHRONIZATION"))        // synchronizacia casu
            {
                QStringList timeList = initMessage.split(" ");
                QStringList time2List = timeList.at(1).split("#");
                QString hour = time2List.at(0);
                QString minute = time2List.at(1);
                QString second = time2List.at(2);
                TIMEstring = hour + ":" + minute + ":" + second;
                TIMEtime = QTime::fromString(TIMEstring, "h:mm:ss");
            }

            if(initMessage.contains("AUTOMATED MESSAGE TO CONFIRM"))
            {
                QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
                QString secondPart = "/" + callSignList.at(1);
                QString whole = FROMCallSign + secondPart;
                ui->FMCCallSignLineEdit->setText(whole);
            }
        }
    }
    else
    {
        differentiateMessages(FromPATC, FROMCallSign, TOCallSign, initMessage);

        QTextCursor cursor = ui->ATCTextEdit->textCursor();
        cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        ui->ATCTextEdit->setTextCursor(cursor);

        if((FromPATC == "ATC") && (TOCallSign == "ALL") && (FROMCallSign == ui->CallSignLineEdit->text()))
        {
            QString atcMessage = TOCallSign + ": " + QString(initMessage);
            QString htmlMessage = ATCmessageColor + atcMessage + endHTML;
            ui->ATCTextEdit->insertHtml(htmlMessage);

            ExportTimeList.append(TIMEstring);
            ExportMessageList.append(atcMessage);
            autosave();

            if(initMessage.contains("TIME_SYNCHRONIZATION"))
            {
                QStringList timeList = initMessage.split(" ");
                QStringList time2List = timeList.at(1).split("#");
                QString hour = time2List.at(0);
                QString minute = time2List.at(1);
                QString second = time2List.at(2);
                TIMEstring = hour + ":" + minute + ":" + second;
                TIMEtime = QTime::fromString(TIMEstring, "h:mm:ss");
            }
        }

        else if((FromPATC == "ATC") && (TOCallSign == "ALL") && (FROMCallSign != ui->CallSignLineEdit->text()))
        {
            QString atcMessage = TOCallSign + ": " + QString(initMessage);
            QString htmlMessage = PILOTmessageColor + atcMessage + endHTML;
            ui->ATCTextEdit->insertHtml(htmlMessage);

            ExportTimeList.append(TIMEstring);
            ExportMessageList.append(atcMessage);
            autosave();

            if(initMessage.contains("TIME_SYNCHRONIZATION"))
            {
                QStringList timeList = initMessage.split(" ");
                QStringList time2List = timeList.at(1).split("#");
                QString hour = time2List.at(0);
                QString minute = time2List.at(1);
                QString second = time2List.at(2);
                TIMEstring = hour + ":" + minute + ":" + second;
                TIMEtime = QTime::fromString(TIMEstring, "h:mm:ss");
            }
        }

        else if((FromPATC == "ATC") && (TOCallSign == ui->CallSignLineEdit->text()))           // sprava pre konkretne ATC od ATC
        {
            changeCallSignColor(FROMCallSign);
            QString atcMessage = FROMCallSign + ": " + QString(initMessage);
            QString htmlMessage = PILOTmessageColor + atcMessage + endHTML;
            ui->ATCTextEdit->insertHtml(htmlMessage);

            ExportTimeList.append(TIMEstring);
            ExportMessageList.append(atcMessage);
            autosave();

            if(initMessage.contains("TIME_SYNCHRONIZATION"))
            {
                QStringList timeList = initMessage.split(" ");
                QStringList time2List = timeList.at(1).split("#");
                QString hour = time2List.at(0);
                QString minute = time2List.at(1);
                QString second = time2List.at(2);
                TIMEstring = hour + ":" + minute + ":" + second;
                TIMEtime = QTime::fromString(TIMEstring, "h:mm:ss");
            }

        }

        else if((FromPATC == "ATC") && (FROMCallSign == ui->CallSignLineEdit->text()))           // sprava pre konkretne ATC od ATC
        {
            QString atcMessage = TOCallSign + ": " + QString(initMessage);
            QString htmlMessage = ATCmessageColor + atcMessage + endHTML;
            ui->ATCTextEdit->insertHtml(htmlMessage);

            ExportTimeList.append(TIMEstring);
            ExportMessageList.append(atcMessage);
            autosave();

            if(initMessage.contains("TIME_SYNCHRONIZATION"))
            {
                QStringList timeList = initMessage.split(" ");
                QStringList time2List = timeList.at(1).split("#");
                QString hour = time2List.at(0);
                QString minute = time2List.at(1);
                QString second = time2List.at(2);
                TIMEstring = hour + ":" + minute + ":" + second;
                TIMEtime = QTime::fromString(TIMEstring, "h:mm:ss");
            }
        }

        else if((FromPATC == "Pilot") && (TOCallSign == ui->CallSignLineEdit->text()))      // sprava pre ATC od pilota
        {
            changeCallSignColor(FROMCallSign);
            QString pilotMessage = FROMCallSign + ": " + initMessage;
            QString htmlMessage = PILOTmessageColor + pilotMessage + endHTML;
            ui->ATCTextEdit->insertHtml(htmlMessage);

            ExportTimeList.append(TIMEstring);
            ExportMessageList.append(pilotMessage);
            autosave();

            if(initMessage.contains("LOG ON"))
            {
                overwriteLOGGED(StripDataFrom, FROMCallSign, "LOGGED");
                emit(logon_clicked(FROMCallSign));
            }

            if(initMessage.contains("TERMINATE"))
            {
                overwriteLOGGED(StripDataFrom, FROMCallSign, "PLANNED");

                emit(terminate_clicked(FROMCallSign));
            }

            if(initMessage.contains("ESTABLISHED RAD") && !initMessage.contains("REPORT"))
            {
                QStringList radList = initMessage.split(" ");
                QString rad = radList.at(radList.length()-1);

                overwriteRAD(StripDataFrom, FROMCallSign, rad);
            }

            if((initMessage.contains("PRESENT LEVEL") || initMessage.contains("PRESENT ALTITUDE") || initMessage.contains("CROSSING") || initMessage.contains("MAINTAINING")) && !initMessage.contains("REPORT"))
            {
                QStringList flList = initMessage.split(" ");
                QString fl = flList.at(flList.length()-1);

                overwriteFL(StripDataFrom, FROMCallSign, fl);
                emit(actualFlightLevel_changed(FROMCallSign, fl));
                qDebug() << fl << FROMCallSign;
            }

            if(initMessage.contains("CLEARED") && (initMessage.contains("//WILCO") || initMessage.contains("//ROGER")))
            {
                emit(arrivalRoute_confirmed(FROMCallSign));
            }
        }
        else if((FromPATC == "Pilot") && (TOCallSign == "ALL"))
        {
            if(initMessage.contains("FLIGHTSIM_DATA"))  //data sent from Flight Simulator
            {
                QStringList messageList = initMessage.split("{");
                QString message = messageList.at(1);
                message = message.remove(message.length()-1,1);

                emit(messageFromFlightSim(FROMCallSign, message));
            }
        }
    }
}

void MainWindow::connected()
{
    QString callSign = ui->CallSignLineEdit->text().trimmed();
    if(ui->PilotRadioButton->isChecked())
    {
        ui->stackedWidget->setCurrentWidget(ui->PilotPage);
        setWindowTitle("Pilot Datalink (CPDLC) " + callSign);
        QString mainStyle = QString("#MainWindow {background: black;}");
        ui->FMCCallSignLineEdit->setText("/" + callSign);
        setStyleSheet(mainStyle);
        setFixedWidth(660);
        setFixedHeight(630);
    }
    else
    {
        setMaximumSize(QWIDGETSIZE_MAX,QWIDGETSIZE_MAX);        // cancel the setFixedSize = resizable again
        setMinimumSize(0,0);

        ui->mainToolBar->show();
        QPalette palette;
        palette.setBrush(QPalette::Background, QColor(Qt::white));
        qApp->setPalette(palette);

        ui->stackedWidget->setCurrentWidget(ui->ATCPage);
        ui->ATCSendLineEdit->setFocus();
        setWindowTitle("ATC Datalink (CPDLC) " + callSign);
        pilotListDock->show();
        timeDock->show();
        showMETAR();


        radarMainWindow->show(); // show MainWindow with RADAR map for ATCO
        if(radarMainWindow->isVisible())
        {
            emit sendSTRIPDataFrom(StripDataFrom);
        }


    }
}

void MainWindow::pilotListWidget_OF_clicked(QListWidgetItem *item)
{
    ui->ATCToLabel->setText("Pilot:" + PilotsListWidget_overflight->currentItem()->text());

    item->setBackground(Qt::white);

    ui->ATCTextEdit->clear();
    QStringList messageList = hashList.values(PilotsListWidget_overflight->currentItem()->text());
    QListIterator<QString> iter(messageList);
    iter.toBack();
    while(iter.hasPrevious())
    {
        QString message = iter.previous();
        ui->ATCTextEdit->insertHtml(message);
    }

    QTextCursor cursor = ui->ATCTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    ui->ATCTextEdit->setTextCursor(cursor);
}

void MainWindow::setCurrentTime()
{
    TIMEtime = TIMEtime.addMSecs(100);
    TIMEstring = TIMEtime.toString("hh:mm:ss");

    QString callSign = ui->CallSignLineEdit->text().trimmed();
    if(ui->PilotRadioButton->isChecked())
    {
        setWindowTitle("Pilot Datalink (CPDLC) " + callSign + "     " + TIMEstring);
        QStringList timeList = TIMEstring.split(":");
        QString fmcTime = timeList.at(0) + timeList.at(1) + "Z";
        ui->FMCTimeLineEdit->setText(fmcTime);
    }
    else
    {
        setWindowTitle("ATC Datalink (CPDLC) " + callSign + "     " + TIMEstring);
    }

    emit(timeToMetar(TIMEstring));
    emit(timeToTime(TIMEstring));
}

void MainWindow::newMessageTimeout()
{
    if(ui->FMCMsgLineEdit->text() != "MSG")
    {
        ui->FMCMsgLineEdit->setText("MSG");
    }
    else
    {
        ui->FMCMsgLineEdit->setText("");
    }
}

void MainWindow::sentMessageTimeout()
{
    if(ui->FMCMsgLineEdit->text() == "SENT")
        {
            ui->FMCMsgLineEdit->setText("");
            sentMessageTimer->stop();
        }
        else
        {
            sentMessageTimer->stop();
        }
}

void MainWindow::ATCListWidget_clicked(QListWidgetItem *item)
{
    ui->ATCToLabel->setText("ATC:" + AtcListWidget->currentItem()->text());

    item->setBackground(Qt::white);

    ui->ATCTextEdit->clear();
    QStringList messageList = hashList.values(AtcListWidget->currentItem()->text());
    QListIterator<QString> iter(messageList);
    iter.toBack();
    while(iter.hasPrevious())
    {
        QString message = iter.previous();
        ui->ATCTextEdit->insertHtml(message);
    }

    QTextCursor cursor = ui->ATCTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    ui->ATCTextEdit->setTextCursor(cursor);
}

void MainWindow::showStrip_OF()
{
    QString title = ui->ATCToLabel->text();
    QStringList titleList = title.split(":");
    QString PATC = titleList.at(0);
    QString CallSign = titleList.at(1);

    if(title.contains("ATC"))
    {

    }
    else
    {
        showStrip_overflight(CallSign);
    }
}

void MainWindow::showStrip_overflight(const QString &CallSign)
{
    if(!openedSTRIPList.contains(CallSign))
    {
        stripoverflight = new StripOverflight(this);

        connect(this, SIGNAL(terminate_clicked(const QString)), stripoverflight, SLOT(terminate_clicked_slot(const QString)));
        connect(this, SIGNAL(logon_clicked(const QString)), stripoverflight, SLOT(logon_clicked_slot(const QString)));
        connect(this, SIGNAL(actualFlightLevel_changed(QString,QString)), stripoverflight, SLOT(actualflightLevel_changed(QString,QString)));

        connect(radarMainWindow, SIGNAL(sendFlightPlan(QString,QString)), stripoverflight, SLOT(receiveFlightPlan(QString,QString)));
        connect(stripoverflight, SIGNAL(changeDirectWP(QString,QString)), this, SLOT(changeDirectWP_slot(QString,QString)));
        connect(stripoverflight, SIGNAL(changeDirectWP(QString,QString)), radarMainWindow, SLOT(changeDirectWP_slot(QString,QString)));
        connect(stripoverflight, SIGNAL(STRIP_closed(QString)), this, SLOT(STRIP_closed_slot(QString)));

        stripoverflight->setWindowTitle(CallSign);
        stripoverflight->setStripDataFileName(StripDataFrom);
        stripoverflight->setCallSign(CallSign);
        stripoverflight->update();
        stripoverflight->show();

        openedSTRIPList.append(CallSign);
    }
}

void MainWindow::showStrip_inbound(const QString &CallSign)
{
    if(!openedSTRIPList.contains(CallSign))
    {
        stripinbound = new StripInbound(this);

        connect(this, SIGNAL(terminate_clicked(const QString)), stripinbound, SLOT(terminate_clicked_slot(const QString)));
        connect(this, SIGNAL(logon_clicked(const QString)), stripinbound, SLOT(logon_clicked_slot(const QString)));
        connect(stripinbound, SIGNAL(arrivalRoute_change_signal(QString,QString)), this, SLOT(arrivalRoute_change_slot(QString,QString)));
        connect(this, SIGNAL(arrivalRoute_confirmed(QString)), stripinbound, SLOT(arrivalRoute_confirmed(QString)));
        connect(this, SIGNAL(actualFlightLevel_changed(QString,QString)), stripinbound, SLOT(actualflightLevel_changed(QString,QString)));

        connect(radarMainWindow, SIGNAL(sendFlightPlan(QString,QString)), stripinbound, SLOT(receiveFlightPlan(QString,QString)));
        connect(stripinbound, SIGNAL(changeDirectWP(QString,QString)), this, SLOT(changeDirectWP_slot(QString,QString)));
        connect(stripinbound, SIGNAL(changeDirectWP(QString,QString)), radarMainWindow, SLOT(changeDirectWP_slot(QString,QString)));
        connect(stripinbound, SIGNAL(STRIP_closed(QString)), this, SLOT(STRIP_closed_slot(QString)));

        stripinbound->setWindowTitle(CallSign);
        stripinbound->setStripDataFileName(StripDataFrom);
        stripinbound->setCallSign(CallSign);
        stripinbound->update();
        stripinbound->show();

        openedSTRIPList.append(CallSign);
    }
}

void MainWindow::showStrip_outbound(const QString &CallSign)
{
    if(!openedSTRIPList.contains(CallSign))
    {
        stripoutbound = new StripOutbound(this);

        connect(this, SIGNAL(terminate_clicked(const QString)), stripoutbound, SLOT(terminate_clicked_slot(const QString)));
        connect(this, SIGNAL(logon_clicked(const QString)), stripoutbound, SLOT(logon_clicked_slot(const QString)));
        connect(this, SIGNAL(actualFlightLevel_changed(QString,QString)), stripoutbound, SLOT(actualflightLevel_changed(QString,QString)));

        connect(radarMainWindow, SIGNAL(sendFlightPlan(QString,QString)), stripoutbound, SLOT(receiveFlightPlan(QString,QString)));
        connect(stripoutbound, SIGNAL(changeDirectWP(QString,QString)), this, SLOT(changeDirectWP_slot(QString,QString)));
        connect(stripoutbound, SIGNAL(changeDirectWP(QString,QString)), radarMainWindow, SLOT(changeDirectWP_slot(QString,QString)));
        connect(stripoutbound, SIGNAL(STRIP_closed(QString)), this, SLOT(STRIP_closed_slot(QString)));


        stripoutbound->setWindowTitle(CallSign);
        stripoutbound->setStripDataFileName(StripDataFrom);
        stripoutbound->setCallSign(CallSign);
        stripoutbound->update();
        stripoutbound->show();

        openedSTRIPList.append(CallSign);
    }
}

void MainWindow::arrivalRoute_change_slot(const QString &route, const QString &CallSign)
{
    ui->ATCToLabel->setText("Pilot:" + CallSign);
    ui->ATCSendLineEdit->setText("CLEARED " + route);
}

void MainWindow::createDockWindow()
{
    // label dock widget
    label = new Label(this);
    label->setWindowTitle("Label");

    dock = new QDockWidget("LABEL", this);
    dock->setWidget(label);
    dock->hide();
    //dock->setFloating(true);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    time = new Time(this);
    time->setWindowTitle("Time");

    timeDock = new QDockWidget("TIME", this);
    timeDock->setWidget(time);
    timeDock->hide();
    addDockWidget(Qt::RightDockWidgetArea, timeDock);
    timeDock->setFloating(true);

    QRect screenGeometry = QApplication::desktop()->availableGeometry();
    int screenWidth = screenGeometry.width();
    int w = 250;
    timeDock->setGeometry((screenWidth/2)-w/2,30,w,80);

    // list of pilots dock widget
    pilotListDock = new QDockWidget("POSTS", this);

    vertlayout_1 = new QVBoxLayout(this);
    vertlayout_1->addWidget(AtcListWidget);
    atcGroupBox = new QGroupBox("ATC", this);
    atcGroupBox->setLayout(vertlayout_1);

    vertlayout_2 = new QVBoxLayout(this);
    vertlayout_2->addWidget(PilotListWidget_inbound);
    inboundGroupBox = new QGroupBox("INBOUND", this);
    inboundGroupBox->setLayout(vertlayout_2);

    vertlayout_3 = new QVBoxLayout(this);
    vertlayout_3->addWidget(PilotsListWidget_overflight);
    overflightGroupBox = new QGroupBox("OVERFLIGHT", this);
    overflightGroupBox->setLayout(vertlayout_3);

    vertlayout_4 = new QVBoxLayout(this);
    vertlayout_4->addWidget(PilotListWidget_outbound);
    outboundGroupBox = new QGroupBox("OUTBOUND", this);
    outboundGroupBox->setLayout(vertlayout_4);


    QString boxStyle = QString("QGroupBox {font: bold kerning 18px 'MS Shell Dlg 2';"
                               "color: black;"
                               "background: lightgray;}");

    atcGroupBox->setStyleSheet(boxStyle);
    inboundGroupBox->setStyleSheet(boxStyle);
    outboundGroupBox->setStyleSheet(boxStyle);
    overflightGroupBox->setStyleSheet(boxStyle);

    pilotSplitter = new QSplitter(this);
    pilotSplitter->addWidget(atcGroupBox);
    pilotSplitter->addWidget(inboundGroupBox);
    pilotSplitter->addWidget(outboundGroupBox);
    pilotSplitter->addWidget(overflightGroupBox);
    pilotSplitter->setOrientation(Qt::Vertical);


    pilotListDock->setWidget(pilotSplitter);


    pilotListDock->hide();
    addDockWidget(Qt::LeftDockWidgetArea, pilotListDock);

    // metar dock widget
    metar = new Metar(this);
    metar->setWindowTitle("METAR");

    metarDock = new QDockWidget("METAR", this);
    metarDock->setWidget(metar);
    metarDock->hide();
    addDockWidget(Qt::LeftDockWidgetArea, metarDock);
}

void MainWindow::overwriteNextPointETE(const QString &fileName, const QString &callSign, const double &ETE)
{
    double hours = qFloor(ETE / 3600);
    double minutes = qFloor((ETE - hours*3600) / 60);
    double seconds = ETE - hours*3600 - minutes*60;

    QStringList timeList = TIMEstring.split(":");
    double s = timeList.at(2).toDouble() + seconds;
    double h = timeList.at(0).toDouble() + hours;
    double min = timeList.at(1).toDouble() + minutes;
    if(s >=60)
    {
        min = min+1;
        s = s - 60;
    }

    if(min >= 60)
    {
        h = h+1;
        min = min-60;
    }

    if(h >= 24)
    {
        h = h-24;
    }

    QString hour = QString::number(h);
    QString minute = QString::number(min);
    if(h < 10)
        hour = "0" + QString::number(h);
    if(min < 10)
        minute = "0" + QString::number(min);
    QString ETEtime = hour + minute;

    QStringList newList;
    QFile file(fileName);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }
    else
    {
        QString line;
        QStringList lineList;
        QTextStream stream(&file);
        QStringList stripLineList;

        while( !stream.atEnd())
        {
            line = stream.readLine();       // precita riadky postupne
            lineList = line.split("#");     // oddeli na CallSign a zbytok stripu

            if(lineList.at(0) == callSign)  // hladam svoj CallSign
            {
                stripLineList = lineList.at(1).split(";");  // list celeho stripu pre danu CallSign
                stripLineList.replace(2, ETEtime);
                lineList.replace(1, stripLineList.join(";"));
            }
            line = lineList.join("#");
            newList.append(line);
        }
    }

    file.close();

    QFile file_2(fileName);
    if( !file_2.open( QIODevice::WriteOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file_2.fileName() << "for writing.";
    }
    else
    {
        QTextStream stream(&file_2);

        QListIterator<QString> iter(newList);
        while(iter.hasNext())
        {
            stream << iter.next() << "\n";
        }
    }

    file.close();
}

void MainWindow::changeDirectWP_slot(const QString &callsign, const QString &point)
{
    QString FROMCallSign = ui->CallSignLineEdit->text();

    QString loginMessage = "ATC:" + FROMCallSign + ":" + callsign;
    QString directMessage = "PROCEED DIRECT TO " + point;

    QString message = loginMessage + " " + directMessage;
    socket->write(message.toUtf8());
}

void MainWindow::QNHChecked_slot(const bool qnhchecked)
{
    QNHChecked_status = qnhchecked;
    updateMessage(newMessage);
}

void MainWindow::getQNH(const QString &QNHdata)
{
    QNH = QNHdata;
}

void MainWindow::showMetarDock()
{
    metarDock->show();
}

void MainWindow::showPostsDock()
{
    pilotListDock->show();
}

void MainWindow::showAboutDock()
{
    QString info = QString("DLCSim is a Data Link simulator for ATC/Pilot procedural training\n\nLast Modified: 2015/04/01\n\nversion: 1.1.0");

    QMessageBox::information(this, "DLC Info", info);
}

void MainWindow::showTimeDock()
{
    timeDock->show();
}

void MainWindow::showRADAR()
{
    radarMainWindow->show();
}

void MainWindow::showLabel_OF()
{
    label->setStripDataName(StripDataFrom);
    dock->show();

    QString callsign = PilotsListWidget_overflight->currentItem()->text();

    label->setATCcallsign(ui->CallSignLineEdit->text());
    label->setCallSign(callsign);            // takto sa posielaju data do LABELu

    readSTRIP(StripDataFrom, callsign);

    label->setCurrentFL(getFL(stripList));
    label->setCurrentRadial(getRADIAL(stripList));
    label->updateCallSignColor();
}

void MainWindow::FLChange_pending(const QString &level)
{
    QString QNH;
    QString FL;

    QStringList levelList = level.split(" ");
    if(levelList.length() > 1)
    {
        QNH = levelList.at(1);
        FL = levelList.at(0);

        LEVEL = FL;
        updateMessage(newMessage + " " + QNH);
    }
    else
    {
        LEVEL = level;
        updateMessage(newMessage);
    }
}

void MainWindow::change_cancelled(const QString &message)
{
    RADIAL = "";
    POINT = "";
    ALTITUDE = "";
    VERTICALRATE = "";
    TIME = "";
    DISTANCE = "";
    TRACK = "";
    LEVEL = "";

    ui->ATCSendLineEdit->setText(message);
}

void MainWindow::TIMEchange_pending(const QString &time)
{
    TIME = time;
    updateMessage(newMessage);
}

void MainWindow::RATEchange_pending(const QString &rate)
{
    VERTICALRATE = rate + " ft/min";
    updateMessage(newMessage);
}

void MainWindow::RADIALChange_pending(const QString &radial)
{
    RADIAL = radial;
    updateMessage(newMessage);
}

void MainWindow::messageChange_slot(const QString &message)
{
    newMessage = message;
    ui->ATCSendLineEdit->setText(message);
}

void MainWindow::POINTchange_pending(const QString &point)
{
    POINT = point;
    updateMessage(newMessage);
}

void MainWindow::TRACKchange_pending(const QString &track)
{
    TRACK = track;

    if(TRACK.contains("ILS"))
    {
        TRACK.insert(3," RWY ");
        TRACK.append(", REPORT FAF");
    }

    updateMessage(newMessage);
}

void MainWindow::ALTITUDEchanged_pending(const QString &altitude)
{
    ALTITUDE = altitude;
    updateMessage(newMessage);
}

void MainWindow::DISTANCEchanged_pending(const QString &distance)
{
    DISTANCE = distance;
    updateMessage(newMessage);
}

void MainWindow::ATCPilotRadioButtonChanged()
{
    if(ui->ATCRadioButton->isChecked() == true)
    {
        ui->STRIPdataFrom->show();
        ui->STRIPdataFromLabel->show();
        ui->CallSignLineEdit->setText("LZKZ");
    }
    else
    {
        ui->STRIPdataFrom->hide();
        ui->STRIPdataFromLabel->hide();
        ui->CallSignLineEdit->setText("CSA900");
    }
}

void MainWindow::SpecialButtonClicked(const QString &message)
{
    ui->ATCSendLineEdit->setText(message);
}

void MainWindow::initTimeSync()
{
    timeSyncDialog->exec();

    /*
    bool ok;
    QString InitTime = QInputDialog::getText(this, tr("Set Initial Time"), "Time: ", QLineEdit::Normal, "12#10#34",&ok);

    if(ok && !InitTime.isEmpty())
    {
        ui->ATCSendLineEdit->setText("TIME_SYNCHRONIZATION " + initTime);


        QString message = ui->ATCSendLineEdit->text().trimmed();
        QString FROMCallSign = ui->CallSignLineEdit->text();
        QString FromPATC = "ATC";

        QString loginMessage;

        loginMessage = QString(FromPATC + ":" + FROMCallSign + ":" + "ALL");

        if(!message.isEmpty())
        {
            message = loginMessage + " " + message;
            socket->write(message.toUtf8());
            qDebug() << message;
        }

        ui->ATCSendLineEdit->clear();
        ui->ATCSendLineEdit->setFocus();
    }
    */
}

void MainWindow::getInitTime(const QString &init_time)
{
    initTime = init_time;

    if(timeSyncDialog->Accepted)
    {
        qDebug() << initTime;
        qDebug() << "ACCEPTED";

        ui->ATCSendLineEdit->setText("TIME_SYNCHRONIZATION " + initTime);

        QString message = ui->ATCSendLineEdit->text().trimmed();
        QString FROMCallSign = ui->CallSignLineEdit->text();
        QString FromPATC = "ATC";

        QString loginMessage;

        loginMessage = QString(FromPATC + ":" + FROMCallSign + ":" + "ALL");

        if(!message.isEmpty())
        {
            message = loginMessage + " " + message;
            socket->write(message.toUtf8());
            qDebug() << message;
        }

        ui->ATCSendLineEdit->clear();
        ui->ATCSendLineEdit->setFocus();
    }
}

void MainWindow::history_clicked()
{
    QString ATCmessageColor = "<font color=\"White\">";
    QString PILOTmessageColor = "<font color=\"Lime\">";
    QString endHTML = "</font><br>";

    ui->pilotTextEdit->clear();
    ui->pilotTextEdit->setEnabled(true);
    ui->pilotTextEdit->setReadOnly(false);

    QListIterator<QString> iter(historyList);
    int counter = 1;
    while(iter.hasNext())
    {
        counter++;
        QString next;
        if(counter - 2*qFloor(counter/2) == 1)
            next = ATCmessageColor + iter.next() + endHTML;
        else
            next = PILOTmessageColor + iter.next() + endHTML;
        ui->pilotTextEdit->insertHtml(next);
    }

    ui->fmcWILCObutton->hide();
    ui->fmcROGERbutton->hide();
    ui->fmcUNABLEbutton->hide();
    ui->fmcSTANDBYbutton->hide();
    ui->fmcOKbutton->hide();
    ui->fmcSENDbutton->hide();
    ui->fmcMODIFYbutton->hide();
    ui->fmcCANCELbutton->hide();
    ui->fmcDISCARDbutton->hide();
    ui->fmcWEATHERbutton->hide();
    ui->fmcPERFORMANCEbutton->hide();

    editable = false;
}

void MainWindow::CFLclicked_slot(const QString &callsign, const QString &CFL, const QString &actual_FL)
{      
    QString climb_descent;

    if(actual_FL.mid(2,-1).toInt() <= CFL.toInt())
    {
        climb_descent = "CLIMB";
    }
    else
    {
        climb_descent = "DESCENT";
    }

    QString new_CFL;
    if(CFL.length() == 3)
    {
        new_CFL = "FL" + CFL;
    }
    else if(CFL.length() == 2)
    {
        new_CFL = "FL0" + CFL;
    }
    else if(CFL.length() == 1)
    {
        new_CFL = "FL00" + CFL;
    }

    QString FROMCallSign = ui->CallSignLineEdit->text();

    QString loginMessage = "ATC:" + FROMCallSign + ":" + callsign;
    QString directMessage = climb_descent + " TO " + new_CFL;

    QString message = loginMessage + " " + directMessage;
    socket->write(message.toUtf8());
}

void MainWindow::STRIP_closed_slot(const QString &callsign)
{
    openedSTRIPList.removeOne(callsign);
}

void MainWindow::WILCObutton_clicked()
{
    QString ATCmessageColor = "<font color=\"White\">";
    QString PILOTmessageColor = "<font color=\"Lime\">";
    QString endHTML = "</font><br>";

    QString message = PILOTmessageColor + "//WILCO" + endHTML;
    ui->pilotTextEdit->insertHtml(message);

    ui->fmcWILCObutton->hide();
    ui->fmcROGERbutton->hide();
    ui->fmcDISCARDbutton->hide();
    ui->fmcSTANDBYbutton->hide();
    ui->fmcUNABLEbutton->hide();
    ui->fmcWEATHERbutton->hide();
    ui->fmcPERFORMANCEbutton->hide();
    ui->fmcSENDbutton->show();
    ui->fmcCANCELbutton->show();
    ui->fmcMODIFYbutton->show();

    editable = false;
}

void MainWindow::ROGERbutton_clicked()
{
    QString ATCmessageColor = "<font color=\"White\">";
    QString PILOTmessageColor = "<font color=\"Lime\">";
    QString endHTML = "</font><br>";

    QString message = PILOTmessageColor + "//ROGER" + endHTML;
    ui->pilotTextEdit->insertHtml(message);

    ui->fmcWILCObutton->hide();
    ui->fmcROGERbutton->hide();
    ui->fmcDISCARDbutton->hide();
    ui->fmcSTANDBYbutton->hide();
    ui->fmcUNABLEbutton->hide();
    ui->fmcWEATHERbutton->hide();
    ui->fmcPERFORMANCEbutton->hide();
    ui->fmcSENDbutton->show();
    ui->fmcCANCELbutton->show();
    ui->fmcMODIFYbutton->show();

    editable = false;
}

void MainWindow::UNABLEbutton_clicked()
{
    QString ATCmessageColor = "<font color=\"White\">";
    QString PILOTmessageColor = "<font color=\"Lime\">";
    QString endHTML = "</font><br>";

    QString message = PILOTmessageColor + "//UNABLE " + "</font>";
    ui->pilotTextEdit->insertHtml(message);

    ui->fmcWILCObutton->hide();
    ui->fmcROGERbutton->hide();
    ui->fmcDISCARDbutton->hide();
    ui->fmcSTANDBYbutton->hide();
    ui->fmcUNABLEbutton->hide();
    ui->fmcSENDbutton->show();
    ui->fmcCANCELbutton->show();
    ui->fmcMODIFYbutton->show();
    ui->fmcWEATHERbutton->show();
    ui->fmcPERFORMANCEbutton->show();

    editable = false;
}

void MainWindow::PERFORMANCEbutton_clicked()
{
    QString ATCmessageColor = "<font color=\"White\">";
    QString PILOTmessageColor = "<font color=\"Lime\">";
    QString endHTML = "</font><br>";

    QString message = PILOTmessageColor + " DUE TO PERFORMANCE" + endHTML;
    ui->pilotTextEdit->insertHtml(message);

    ui->fmcWILCObutton->hide();
    ui->fmcROGERbutton->hide();
    ui->fmcDISCARDbutton->hide();
    ui->fmcSTANDBYbutton->hide();
    ui->fmcUNABLEbutton->hide();
    ui->fmcSENDbutton->show();
    ui->fmcCANCELbutton->show();
    ui->fmcMODIFYbutton->show();
    ui->fmcWEATHERbutton->hide();
    ui->fmcPERFORMANCEbutton->hide();

    editable = false;
}

void MainWindow::WEATHERbutton_clicked()
{
    QString ATCmessageColor = "<font color=\"White\">";
    QString PILOTmessageColor = "<font color=\"Lime\">";
    QString endHTML = "</font><br>";

    QString message = PILOTmessageColor + " DUE TO WEATHER" + endHTML;
    ui->pilotTextEdit->insertHtml(message);

    ui->fmcWILCObutton->hide();
    ui->fmcROGERbutton->hide();
    ui->fmcDISCARDbutton->hide();
    ui->fmcSTANDBYbutton->hide();
    ui->fmcUNABLEbutton->hide();
    ui->fmcSENDbutton->show();
    ui->fmcCANCELbutton->show();
    ui->fmcMODIFYbutton->show();
    ui->fmcWEATHERbutton->hide();
    ui->fmcPERFORMANCEbutton->hide();

    editable = false;
}

void MainWindow::STANDBYbutton_clicked()
{
    QString ATCmessageColor = "<font color=\"White\">";
    QString PILOTmessageColor = "<font color=\"Lime\">";
    QString endHTML = "</font><br>";

    QString message = PILOTmessageColor + "//STANDBY" + endHTML;
    ui->pilotTextEdit->insertHtml(message);
    stbyclicked = true;

    ui->fmcWILCObutton->hide();
    ui->fmcROGERbutton->hide();
    ui->fmcDISCARDbutton->hide();
    ui->fmcSTANDBYbutton->hide();
    ui->fmcUNABLEbutton->hide();
    ui->fmcWEATHERbutton->hide();
    ui->fmcPERFORMANCEbutton->hide();
    ui->fmcSENDbutton->show();
    ui->fmcCANCELbutton->show();
    ui->fmcMODIFYbutton->show();

    editable = false;
}

void MainWindow::SENDbutton_clicked()
{
    QStringList atcToList = ui->FMCCallSignLineEdit->text().split("/");
    QString atcToString = atcToList.at(0);

    if(ATCFromChange == true)
        atcToString = ATCFROMCALLSIGN;
    ATCFromChange = false;

    QString message = ui->pilotTextEdit->toPlainText();

    QString loginMessage = "Pilot:" + ui->CallSignLineEdit->text() + ":" + atcToString + " ";
    QString wholeMessage = loginMessage + message;
    socket->write(wholeMessage.toUtf8());

    ui->fmcSENDbutton->hide();
    ui->fmcCANCELbutton->hide();
    ui->fmcMODIFYbutton->hide();
    ui->fmcDISCARDbutton->hide();
    ui->fmcWEATHERbutton->hide();
    ui->fmcPERFORMANCEbutton->hide();

    ui->pilotTextEdit->clear();

    if(messageClicked != "NONE")
    {
        if(stbyclicked == true)
        {
            setSTATUS("VIEWMESSAGES");
            stbyclicked = false;
        }
        else
        {
            int num = messageClicked.toInt();
            incomingMessageList.removeAt(num-1);
            setSTATUS("MAINPAGE");
        }
    }
    historyList.append(message);

    editable = false;
    sentMessageTimer->start(1500);
    ui->FMCMsgLineEdit->setText("SENT");
}

void MainWindow::DISCARDbutton_clicked()
{
    ui->fmcSENDbutton->hide();
    ui->fmcCANCELbutton->hide();
    ui->fmcMODIFYbutton->hide();
    ui->fmcDISCARDbutton->hide();
    ui->fmcWEATHERbutton->hide();
    ui->fmcPERFORMANCEbutton->hide();

    if(messageClicked != "NONE")
    {
        int num = messageClicked.toInt();
        incomingMessageList.removeAt(num-1);
        setSTATUS("VIEWMESSAGES");
        messageClicked = "NONE";
    }

    editable = false;
}

void MainWindow::CANCELbutton_clicked()
{
    ui->pilotTextEdit->clear();
    ui->fmcSENDbutton->hide();
    ui->fmcCANCELbutton->hide();
    ui->fmcMODIFYbutton->hide();
    ui->fmcDISCARDbutton->hide();
    ui->fmcWEATHERbutton->hide();
    ui->fmcPERFORMANCEbutton->hide();

    editable = false;

    setSTATUS("MAINPAGE");
}

void MainWindow::MODIFYbutton_clicked()
{
    ui->pilotTextEdit->setEnabled(true);
    ui->pilotTextEdit->setReadOnly(false);

    QTextCursor cursor = ui->pilotTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    ui->pilotTextEdit->setTextCursor(cursor);
    ui->pilotTextEdit->setFocus();

    editable = true;
}

void MainWindow::OKbutton_clicked()
{
    QString message = ui->pilotTextEdit->toPlainText();
    ui->pilotTextEdit->clear();
    ui->fmcOKbutton->hide();

    if(messageClicked != "NONE")
    {
        int num = messageClicked.toInt();
        incomingMessageList.removeAt(num-1);
        setSTATUS("MAINPAGE");
    }
    historyList.append(message);
    editable = false;
}

void MainWindow::setSTATUS(const QString &status)
{
    STATUS = status;

    if(status == "WELCOME")
    {
        messageClicked = "NONE";
        ui->pilotTextEdit->clear();
        ui->fmcLabel_main->setText("WELCOME");
        ui->fmcLabel_L1->setText("");
        ui->fmcLabel_L2->setText("");
        ui->fmcLabel_L3->setText("");
        ui->fmcLabel_L4->setText("");
        ui->fmcLabel_R1->setText("ATC LOG ON");
        ui->fmcLabel_R2->setText("");
        ui->fmcLabel_R3->setText("");
        ui->fmcLabel_R4->setText("");

        ui->pilotMenuButton->setEnabled(false);
        ui->pilotMessageButton->setEnabled(false);

        ui->fmcWILCObutton->hide();
        ui->fmcROGERbutton->hide();
        ui->fmcDISCARDbutton->hide();
        ui->fmcUNABLEbutton->hide();
        ui->fmcSTANDBYbutton->hide();
        ui->fmcOKbutton->hide();
        ui->fmcSENDbutton->hide();
        ui->fmcMODIFYbutton->hide();
        ui->fmcCANCELbutton->hide();
        ui->fmcWEATHERbutton->hide();
        ui->fmcPERFORMANCEbutton->hide();

        if(ui->fmcLabel_L4->text() != "NEW ATC MSG")
        {
            ui->fmcLabel_L4->setText("");
        }

        editable = false;
    }

    if(status == "MAINPAGE")
    {
        messageClicked = "NONE";
        ui->pilotTextEdit->clear();
        ui->fmcLabel_main->setText("MAIN PAGE");
        ui->fmcLabel_L1->setText("");
        ui->fmcLabel_L2->setText("FREE TEXT");
        ui->fmcLabel_L3->setText("HISTORY");
        ui->fmcLabel_R1->setText("REQUEST");
        ui->fmcLabel_R2->setText("REPORT");
        ui->fmcLabel_R3->setText("");
        ui->fmcLabel_R4->setText("TERMINATE");

        ui->fmcWILCObutton->hide();
        ui->fmcROGERbutton->hide();
        ui->fmcDISCARDbutton->hide();
        ui->fmcUNABLEbutton->hide();
        ui->fmcSTANDBYbutton->hide();
        ui->fmcOKbutton->hide();
        ui->fmcSENDbutton->hide();
        ui->fmcMODIFYbutton->hide();
        ui->fmcCANCELbutton->hide();
        ui->fmcWEATHERbutton->hide();
        ui->fmcPERFORMANCEbutton->hide();

        if(ui->fmcLabel_L4->text() != "NEW ATC MSG")
        {
            ui->fmcLabel_L4->setText("");
        }

        editable = false;
    }

    if(status == "LOGON")
    {
        messageClicked = "NONE";
        ui->fmcWILCObutton->hide();
        ui->fmcROGERbutton->hide();
        ui->fmcDISCARDbutton->hide();
        ui->fmcUNABLEbutton->hide();
        ui->fmcSTANDBYbutton->hide();
        ui->fmcOKbutton->hide();
        ui->fmcSENDbutton->hide();
        ui->fmcMODIFYbutton->hide();
        ui->fmcCANCELbutton->hide();
        ui->fmcWEATHERbutton->hide();
        ui->fmcPERFORMANCEbutton->hide();

        ui->pilotTextEdit->clear();
        ui->pilotTextEdit->setEnabled(false);
        ui->pilotTextEdit->setReadOnly(true);

        int atcLen = ATCList.length();

        if(atcLen == 0)
        {
            ui->fmcLabel_R1->setText("");
            ui->fmcLabel_R2->setText("");
            ui->fmcLabel_R3->setText("");
            ui->fmcLabel_R4->setText("");
        }
        else if(atcLen == 1)
        {
            ui->fmcLabel_R1->setText(ATCList.at(0));
            ui->fmcLabel_R2->setText("");
            ui->fmcLabel_R3->setText("");
            ui->fmcLabel_R4->setText("");
        }
        else if(atcLen == 2)
        {
            ui->fmcLabel_R1->setText(ATCList.at(0));
            ui->fmcLabel_R2->setText(ATCList.at(1));
            ui->fmcLabel_R3->setText("");
            ui->fmcLabel_R4->setText("");
        }
        else if(atcLen == 3)
        {
            ui->fmcLabel_R1->setText(ATCList.at(0));
            ui->fmcLabel_R2->setText(ATCList.at(1));
            ui->fmcLabel_R3->setText(ATCList.at(2));
            ui->fmcLabel_R4->setText("");
        }
        else if(atcLen >= 4)
        {
            ui->fmcLabel_R1->setText(ATCList.at(0));
            ui->fmcLabel_R2->setText(ATCList.at(1));
            ui->fmcLabel_R3->setText(ATCList.at(2));
            ui->fmcLabel_R4->setText(ATCList.at(3));
        }

        ui->fmcLabel_L1->setText("RETURN");

        editable = false;
    }

    if(status == "VIEWMESSAGES")
    {
        messageClicked = "NONE";
        ui->fmcWILCObutton->hide();
        ui->fmcROGERbutton->hide();
        ui->fmcDISCARDbutton->hide();
        ui->fmcUNABLEbutton->hide();
        ui->fmcSTANDBYbutton->hide();
        ui->fmcOKbutton->hide();
        ui->fmcSENDbutton->hide();
        ui->fmcMODIFYbutton->hide();
        ui->fmcCANCELbutton->hide();
        ui->fmcWEATHERbutton->hide();
        ui->fmcPERFORMANCEbutton->hide();

        ui->pilotTextEdit->clear();
        ui->pilotTextEdit->setEnabled(false);
        ui->pilotTextEdit->setReadOnly(true);
        newMessageTimer->stop();
        ui->FMCMsgLineEdit->setText("");
        int messLen = incomingMessageList.length();

        if(messLen == 0)
        {
            ui->fmcLabel_L1->setText("");
            ui->fmcLabel_L2->setText("");
            ui->fmcLabel_L3->setText("");
            ui->fmcLabel_L4->setText("");
        }
        else if(messLen == 1)
        {
            ui->fmcLabel_L1->setText(incomingMessageList.at(0));
            ui->fmcLabel_L2->setText("");
            ui->fmcLabel_L3->setText("");
            ui->fmcLabel_L4->setText("");
        }
        else if(messLen == 2)
        {
            ui->fmcLabel_L1->setText(incomingMessageList.at(0));
            ui->fmcLabel_L2->setText(incomingMessageList.at(1));
            ui->fmcLabel_L3->setText("");
            ui->fmcLabel_L4->setText("");
        }
        else if(messLen == 3)
        {
            ui->fmcLabel_L1->setText(incomingMessageList.at(0));
            ui->fmcLabel_L2->setText(incomingMessageList.at(1));
            ui->fmcLabel_L3->setText(incomingMessageList.at(2));
            ui->fmcLabel_L4->setText("");
        }
        else if(messLen == 4)
        {
            ui->fmcLabel_L1->setText(incomingMessageList.at(0));
            ui->fmcLabel_L2->setText(incomingMessageList.at(1));
            ui->fmcLabel_L3->setText(incomingMessageList.at(2));
            ui->fmcLabel_L4->setText(incomingMessageList.at(3));
        }

        ui->fmcLabel_main->setText("ATC MESSAGES");
        ui->fmcLabel_R1->setText("");
        ui->fmcLabel_R2->setText("");
        ui->fmcLabel_R3->setText("");
        ui->fmcLabel_R4->setText("MAIN PAGE");

        editable = false;
    }

    if(status == "REQUEST")
    {
        messageClicked = "NONE";
        ui->pilotTextEdit->clear();
        ui->fmcLabel_main->setText("REQUEST");
        ui->fmcLabel_L1->setText("CLB");
        ui->fmcLabel_L2->setText("DSC");
        ui->fmcLabel_L3->setText("RWY");
        ui->fmcLabel_R1->setText("");
        ui->fmcLabel_R2->setText("");
        ui->fmcLabel_R3->setText("");
        ui->fmcLabel_R4->setText("MAIN PAGE");

        if(ui->fmcLabel_L4->text() != "NEW ATC MSG")
        {
            ui->fmcLabel_L4->setText("");
        }

        editable = false;
    }

    if(status == "REPORT")
    {
        messageClicked = "NONE";
        ui->pilotTextEdit->clear();
        ui->fmcLabel_main->setText("REPORT");
        ui->fmcLabel_L1->setText("DISTANCE");
        ui->fmcLabel_L2->setText("");
        ui->fmcLabel_L3->setText("");
        ui->fmcLabel_R1->setText("ALT");
        ui->fmcLabel_R2->setText("FL");
        ui->fmcLabel_R3->setText("POINT");
        ui->fmcLabel_R4->setText("RAD");


        if(ui->fmcLabel_L4->text() != "NEW ATC MSG")
        {
            ui->fmcLabel_L4->setText("");
        }

        editable = false;
    }

    if(status == "RADIAL")
    {
        messageClicked = "NONE";
        ui->pilotTextEdit->clear();
        ui->fmcLabel_main->setText("REPORT RAD");
        ui->fmcLabel_L1->setText("");
        ui->fmcLabel_L2->setText("");
        ui->fmcLabel_L3->setText("");
        ui->fmcLabel_R1->setText("ESTABLISHED");
        ui->fmcLabel_R2->setText("PASSING");
        ui->fmcLabel_R3->setText("");
        ui->fmcLabel_R4->setText("MAIN PAGE");


        if(ui->fmcLabel_L4->text() != "NEW ATC MSG")
        {
            ui->fmcLabel_L4->setText("");
        }

        editable = false;
    }

    if(status == "REPORTDISTANCE")
    {
        messageClicked = "NONE";
        ui->pilotTextEdit->clear();
        ui->fmcLabel_main->setText("REPORT DISTANCE");
        ui->fmcLabel_L1->setText("");
        ui->fmcLabel_L2->setText("");
        ui->fmcLabel_L3->setText("");
        ui->fmcLabel_R1->setText("TO");
        ui->fmcLabel_R2->setText("FROM");
        ui->fmcLabel_R3->setText("");
        ui->fmcLabel_R4->setText("MAIN PAGE");

        if(ui->fmcLabel_L4->text() != "NEW ATC MSG")
        {
            ui->fmcLabel_L4->setText("");
        }

        editable = false;
    }

    if(status == "REPORTALT")
    {
        messageClicked = "NONE";
        ui->pilotTextEdit->clear();
        ui->fmcLabel_main->setText("REPORT ALT");
        ui->fmcLabel_L1->setText("");
        ui->fmcLabel_L2->setText("");
        ui->fmcLabel_L3->setText("");
        ui->fmcLabel_R1->setText("REACHING");
        ui->fmcLabel_R2->setText("CROSSING");
        ui->fmcLabel_R3->setText("MAINTAINING");
        ui->fmcLabel_R4->setText("MAIN PAGE");

        if(ui->fmcLabel_L4->text() != "NEW ATC MSG")
        {
            ui->fmcLabel_L4->setText("");
        }

        editable = false;
    }

    if(status == "REPORTFL")
    {
        messageClicked = "NONE";
        ui->pilotTextEdit->clear();
        ui->fmcLabel_main->setText("REPORT FL");
        ui->fmcLabel_L1->setText("");
        ui->fmcLabel_L2->setText("");
        ui->fmcLabel_L3->setText("");
        ui->fmcLabel_R1->setText("REACHING");
        ui->fmcLabel_R2->setText("CROSSING");
        ui->fmcLabel_R3->setText("MAINTAINING");
        ui->fmcLabel_R4->setText("MAIN PAGE");

        if(ui->fmcLabel_L4->text() != "NEW ATC MSG")
        {
            ui->fmcLabel_L4->setText("");
        }

        editable = false;
    }

    if(status == "TERMINATE")
    {
        ui->pilotTextEdit->clear();
        ui->fmcLabel_main->setText("TERMINATE");
        ui->fmcLabel_L1->setText("");
        ui->fmcLabel_L2->setText("");
        ui->fmcLabel_L3->setText("");
        ui->fmcLabel_R1->setText("");
        ui->fmcLabel_R2->setText("");
        ui->fmcLabel_R3->setText("CONFIRM");
        ui->fmcLabel_R4->setText("CANCEL");

        if(ui->fmcLabel_L4->text() != "NEW ATC MSG")
        {
            ui->fmcLabel_L4->setText("");
        }

        editable = false;
    }
}

void MainWindow::differentiateMessages(const QString fromPATC, const QString fromCallSign, const QString toCallSign, const QString message)
{
    QString ATCmessageColor = "<font color=\"White\">";
    QString PILOTmessageColor = "<font color=\"Lime\">";
    QString endHTML = "</font><br>";

    if(fromPATC == "Pilot")
    {
        if(!message.contains("FLIGHTSIM_DATA"))
        {
            QString htmlMessage = PILOTmessageColor + fromCallSign + ": " + message + endHTML;
            hashList.insertMulti(fromCallSign, htmlMessage);
        }
    }
    else if(fromPATC == "ATC")
    {
        QString htmlMessage = ATCmessageColor + toCallSign + ": " +message + endHTML;
        hashList.insertMulti(toCallSign, htmlMessage);
    }
}

void MainWindow::delay(const int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
        while( QTime::currentTime() < dieTime )
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
}

void MainWindow::fmcButtonL1clicked()
{
    if(STATUS == "LOGON")
    {
        setSTATUS("WELCOME");
    }

    if(STATUS == "REPORT")
    {
        setSTATUS("REPORTDISTANCE");
    }

    if(STATUS == "VIEWMESSAGES" && !ui->fmcLabel_L1->text().isEmpty())
    {        
        stbyclicked = false;
        messageClicked = "1";
        ui->fmcWILCObutton->show();
        ui->fmcROGERbutton->show();
        ui->fmcSTANDBYbutton->show();
        ui->fmcUNABLEbutton->show();
        ui->fmcSENDbutton->hide();
        ui->fmcCANCELbutton->hide();
        ui->fmcMODIFYbutton->hide();
        ui->fmcDISCARDbutton->show();
        ui->fmcWEATHERbutton->hide();
        ui->fmcPERFORMANCEbutton->hide();
        ui->fmcOKbutton->hide();

        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        if(ATCFROMCALLSIGN != ATCcallSign)
            ATCFromChange = true;
        else
            ATCFromChange = false;

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " FROM " + ATCFROMCALLSIGN + " CTL";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        QString rplMessage = PILOTmessageColor + "(REPLY TO " + incomingMessageTimeList.at(0) + " REQ)" + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        ui->pilotTextEdit->insertHtml(rplMessage);

        QString htmlMessage = ATCmessageColor + ui->fmcLabel_L1->text() + endHTML;

        if((ui->fmcLabel_L1->text().contains("AUTOMATED MESSAGE TO CONFIRM")) || (ui->fmcLabel_L1->text() == "ROGER") || (ui->fmcLabel_L1->text() == "NEGATIVE") || (ui->fmcLabel_L1->text() == "AFFIRM") || (ui->fmcLabel_L1->text() == "DISREGARD"))
        {
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcDISCARDbutton->hide();
            ui->fmcOKbutton->show();

            ui->pilotTextEdit->clear();
            ui->pilotTextEdit->insertHtml(initHtmlMessage);
            ui->pilotTextEdit->insertHtml(htmlMessage);
        }
        else if(ui->fmcLabel_L1->text().contains("EST TIME OVER"))
        {
            QStringList replyList = ui->fmcLabel_L1->text().split(" ");
            QString response = ATCmessageColor + replyList.at(replyList.length()-1) + " EST AT " + "</font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else if(ui->fmcLabel_L1->text().contains("REPORT DIST  TO/FROM"))
        {
            QStringList replyList = ui->fmcLabel_L1->text().split(" ");
            QString response = ATCmessageColor + "DIST " + replyList.at(replyList.length()-2) + " " + replyList.at(replyList.length()-1) + " </font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else if(ui->fmcLabel_L1->text().contains("PRESENT LEVEL"))
        {
            QString response = ATCmessageColor + "PRESENT LEVEL FL" + "</font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else if(ui->fmcLabel_L1->text().contains("PRESENT ALTITUDE"))
        {
            QString response = ATCmessageColor + "PRESENT ALTITUDE " + "</font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else
        {
            ui->pilotTextEdit->insertHtml(htmlMessage);
        }
    }

    else if(STATUS == "REQUEST")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "REQUEST CLB TO ";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    if(STATUS == "REPORTDISTANCE")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "DIST TO ";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    qDebug() << STATUS;
}

void MainWindow::fmcButtonL2clicked()
{
    if(STATUS == "VIEWMESSAGES" && !ui->fmcLabel_L2->text().isEmpty())
    {
        stbyclicked = false;
        messageClicked = "2";
        ui->fmcWILCObutton->show();
        ui->fmcROGERbutton->show();
        ui->fmcSTANDBYbutton->show();
        ui->fmcUNABLEbutton->show();
        ui->fmcSENDbutton->hide();
        ui->fmcCANCELbutton->hide();
        ui->fmcMODIFYbutton->hide();
        ui->fmcDISCARDbutton->show();
        ui->fmcWEATHERbutton->hide();
        ui->fmcPERFORMANCEbutton->hide();
        ui->fmcOKbutton->hide();

        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        if(ATCFROMCALLSIGN != ATCcallSign)
            ATCFromChange = true;
        else
            ATCFromChange = false;

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " FROM " + ATCFROMCALLSIGN + " CTL";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        QString rplMessage = PILOTmessageColor + "(REPLY TO " + incomingMessageTimeList.at(1) + " REQ)" + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        ui->pilotTextEdit->insertHtml(rplMessage);

        QString htmlMessage = ATCmessageColor + ui->fmcLabel_L2->text() + endHTML;

        if((ui->fmcLabel_L2->text().contains("AUTOMATED MESSAGE TO CONFIRM")) || (ui->fmcLabel_L2->text() == "ROGER") || (ui->fmcLabel_L2->text() == "NEGATIVE") || (ui->fmcLabel_L2->text() == "AFFIRM") || (ui->fmcLabel_L2->text() == "DISREGARD"))
        {
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcDISCARDbutton->hide();
            ui->fmcOKbutton->show();

            ui->pilotTextEdit->clear();
            ui->pilotTextEdit->insertHtml(initHtmlMessage);
            ui->pilotTextEdit->insertHtml(htmlMessage);
        }
        else if(ui->fmcLabel_L2->text().contains("EST TIME OVER"))
        {
            QStringList replyList = ui->fmcLabel_L2->text().split(" ");
            QString response = ATCmessageColor + replyList.at(replyList.length()-1) + " EST AT " + "</font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else if(ui->fmcLabel_L2->text().contains("REPORT DIST  TO/FROM"))
        {
            QStringList replyList = ui->fmcLabel_L2->text().split(" ");
            QString response = ATCmessageColor + "DIST " + replyList.at(replyList.length()-2) + " " + replyList.at(replyList.length()-1) + " </font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else if(ui->fmcLabel_L2->text().contains("PRESENT LEVEL"))
        {
            QString response = ATCmessageColor + "PRESENT LEVEL FL" + "</font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else if(ui->fmcLabel_L2->text().contains("PRESENT ALTITUDE"))
        {
            QString response = ATCmessageColor + "PRESENT ALTITUDE " + "</font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else
        {
            ui->pilotTextEdit->insertHtml(htmlMessage);
        }
    }

    else if(STATUS == "REQUEST")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "REQUEST DSC TO ";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    else if(STATUS == "MAINPAGE")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "<br></font>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    qDebug() << STATUS;
}

void MainWindow::fmcButtonL3clicked()
{
    if(STATUS == "VIEWMESSAGES" && !ui->fmcLabel_L3->text().isEmpty())
    {
        stbyclicked = false;
        messageClicked = "3";
        ui->fmcWILCObutton->show();
        ui->fmcROGERbutton->show();
        ui->fmcSTANDBYbutton->show();
        ui->fmcUNABLEbutton->show();
        ui->fmcSENDbutton->hide();
        ui->fmcCANCELbutton->hide();
        ui->fmcMODIFYbutton->hide();
        ui->fmcDISCARDbutton->show();
        ui->fmcWEATHERbutton->hide();
        ui->fmcPERFORMANCEbutton->hide();
        ui->fmcOKbutton->hide();

        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        if(ATCFROMCALLSIGN != ATCcallSign)
            ATCFromChange = true;
        else
            ATCFromChange = false;

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " FROM " + ATCFROMCALLSIGN + " CTL";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        QString rplMessage = PILOTmessageColor + "(REPLY TO " + incomingMessageTimeList.at(2) + " REQ)" + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        ui->pilotTextEdit->insertHtml(rplMessage);

        QString htmlMessage = ATCmessageColor + ui->fmcLabel_L3->text() + endHTML;

        if((ui->fmcLabel_L3->text().contains("AUTOMATED MESSAGE TO CONFIRM")) || (ui->fmcLabel_L3->text() == "ROGER") || (ui->fmcLabel_L3->text() == "NEGATIVE") || (ui->fmcLabel_L3->text() == "AFFIRM") || (ui->fmcLabel_L3->text() == "DISREGARD"))
        {
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcDISCARDbutton->hide();
            ui->fmcOKbutton->show();

            ui->pilotTextEdit->clear();
            ui->pilotTextEdit->insertHtml(initHtmlMessage);
            ui->pilotTextEdit->insertHtml(htmlMessage);
        }
        else if(ui->fmcLabel_L3->text().contains("EST TIME OVER"))
        {
            QStringList replyList = ui->fmcLabel_L3->text().split(" ");
            QString response = ATCmessageColor + replyList.at(replyList.length()-1) + " EST AT " + "</font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else if(ui->fmcLabel_L3->text().contains("REPORT DIST  TO/FROM"))
        {
            QStringList replyList = ui->fmcLabel_L3->text().split(" ");
            QString response = ATCmessageColor + "DIST " + replyList.at(replyList.length()-2) + " " + replyList.at(replyList.length()-1) + " </font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else if(ui->fmcLabel_L3->text().contains("PRESENT LEVEL"))
        {
            QString response = ATCmessageColor + "PRESENT LEVEL FL" + "</font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else if(ui->fmcLabel_L3->text().contains("PRESENT ALTITUDE"))
        {
            QString response = ATCmessageColor + "PRESENT ALTITUDE " + "</font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else
        {
            ui->pilotTextEdit->insertHtml(htmlMessage);
        }
    }

    else if(STATUS == "REQUEST")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "REQUEST RWY ";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    else if(STATUS == "MAINPAGE")
    {
        ui->pilotHistoryButton->animateClick();
    }

    qDebug() << STATUS;
}

void MainWindow::fmcButtonL4clicked()
{
    if(ui->fmcLabel_L4->text() == "NEW ATC MSG")
    {
        setSTATUS("VIEWMESSAGES");
    }

    else if(STATUS == "VIEWMESSAGES" && !ui->fmcLabel_L4->text().isEmpty())
    {
        stbyclicked = false;
        messageClicked = "4";
        ui->fmcWILCObutton->show();
        ui->fmcROGERbutton->show();
        ui->fmcSTANDBYbutton->show();
        ui->fmcUNABLEbutton->show();
        ui->fmcSENDbutton->hide();
        ui->fmcCANCELbutton->hide();
        ui->fmcMODIFYbutton->hide();
        ui->fmcDISCARDbutton->show();
        ui->fmcWEATHERbutton->hide();
        ui->fmcPERFORMANCEbutton->hide();
        ui->fmcOKbutton->hide();

        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        if(ATCFROMCALLSIGN != ATCcallSign)
            ATCFromChange = true;
        else
            ATCFromChange = false;

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " FROM " + ATCFROMCALLSIGN + " CTL";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        QString rplMessage = PILOTmessageColor + "(REPLY TO " + incomingMessageTimeList.at(3) + " REQ)" + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        ui->pilotTextEdit->insertHtml(rplMessage);

        QString htmlMessage = ATCmessageColor + ui->fmcLabel_L4->text() + endHTML;

        if((ui->fmcLabel_L4->text().contains("AUTOMATED MESSAGE TO CONFIRM")) || (ui->fmcLabel_L4->text() == "ROGER") || (ui->fmcLabel_L4->text() == "NEGATIVE") || (ui->fmcLabel_L4->text() == "AFFIRM") || (ui->fmcLabel_L4->text() == "DISREGARD"))
        {
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->hide();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcOKbutton->show();

            ui->pilotTextEdit->clear();
            ui->pilotTextEdit->insertHtml(initHtmlMessage);
            ui->pilotTextEdit->insertHtml(htmlMessage);
        }
        else if(ui->fmcLabel_L4->text().contains("EST TIME OVER"))
        {
            QStringList replyList = ui->fmcLabel_L4->text().split(" ");
            QString response = ATCmessageColor + replyList.at(replyList.length()-1) + " EST AT " + "</font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else if(ui->fmcLabel_L4->text().contains("REPORT DIST  TO/FROM"))
        {
            QStringList replyList = ui->fmcLabel_L4->text().split(" ");
            QString response = ATCmessageColor + "DIST " + replyList.at(replyList.length()-2) + " " + replyList.at(replyList.length()-1) + " </font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else if(ui->fmcLabel_L4->text().contains("PRESENT LEVEL"))
        {
            QString response = ATCmessageColor + "PRESENT LEVEL FL" + "</font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else if(ui->fmcLabel_L4->text().contains("PRESENT ALTITUDE"))
        {
            QString response = ATCmessageColor + "PRESENT ALTITUDE " + "</font>";
            ui->pilotTextEdit->insertHtml(response);
            ui->fmcWILCObutton->hide();
            ui->fmcROGERbutton->hide();
            ui->fmcDISCARDbutton->show();
            ui->fmcSTANDBYbutton->hide();
            ui->fmcUNABLEbutton->hide();
            ui->fmcWEATHERbutton->hide();
            ui->fmcPERFORMANCEbutton->hide();
            ui->fmcSENDbutton->show();
            ui->fmcCANCELbutton->show();
            ui->fmcMODIFYbutton->show();

            editable = true;
        }
        else
        {
            ui->pilotTextEdit->insertHtml(htmlMessage);
        }
    }

    qDebug() << STATUS;
}

void MainWindow::fmcButtonR1clicked()
{
    if(STATUS == "WELCOME")
    {
        setSTATUS("LOGON");
    }

    else if((STATUS == "LOGON") && (!ui->fmcLabel_R1->text().isEmpty()))
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";

        ui->pilotTextEdit->clear();
        QString logMessage = PILOTmessageColor + ui->FMCTimeLineEdit->text() + " LOG ON" + endHTML;
        ui->pilotTextEdit->insertHtml(logMessage);
        historyList.append(logMessage);

        QString logOnMessage = " LOG ON";
        QString loginMessage = "Pilot:" + ui->CallSignLineEdit->text() + ":" +ui->fmcLabel_R1->text() + " ";
        QString message = loginMessage + ui->FMCTimeLineEdit->text() + logOnMessage;
        socket->write(message.toUtf8());
    }

    else if(STATUS == "MAINPAGE")
    {
        setSTATUS("REQUEST");
    }

    else if(STATUS == "REPORT")
    {
        setSTATUS("REPORTALT");
    }

    else if(STATUS == "REPORTALT")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "REACHING ALT ";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    else if(STATUS == "REPORTFL")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "REACHING FL";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    else if(STATUS == "REPORTDISTANCE")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "DIST TO ";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    else if(STATUS == "RADIAL")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "ESTABLISHED RAD ";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    qDebug() << STATUS;
}

void MainWindow::fmcButtonR2clicked()
{
    if(STATUS == "MAINPAGE")
    {
        setSTATUS("REPORT");
    }

    else if((STATUS == "LOGON") && (!ui->fmcLabel_R2->text().isEmpty()))
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";

        ui->pilotTextEdit->clear();
        QString logMessage = PILOTmessageColor + ui->FMCTimeLineEdit->text() + " LOG ON" + endHTML;
        ui->pilotTextEdit->insertHtml(logMessage);
        historyList.append(logMessage);

        QString logOnMessage = " LOG ON";
        QString loginMessage = "Pilot:" + ui->CallSignLineEdit->text() + ":" +ui->fmcLabel_R2->text() + " ";
        QString message = loginMessage + ui->FMCTimeLineEdit->text() + logOnMessage;
        socket->write(message.toUtf8());
    }

    else if(STATUS == "REPORT")
    {
        setSTATUS("REPORTFL");
    }

    else if(STATUS == "REPORTALT")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "CROSSING ALT ";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    else if(STATUS == "REPORTFL")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "CROSSING FL";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();
        editable = true;
    }

    else if(STATUS == "REPORTDISTANCE")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "DIST FROM ";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    else if(STATUS == "RADIAL")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "PASSING RAD ";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    qDebug() << STATUS;
}

void MainWindow::fmcButtonR3clicked()
{
    if((STATUS == "LOGON") && (!ui->fmcLabel_R3->text().isEmpty()))
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";

        ui->pilotTextEdit->clear();
        QString logMessage = PILOTmessageColor + ui->FMCTimeLineEdit->text() + " LOG ON" + endHTML;
        ui->pilotTextEdit->insertHtml(logMessage);
        historyList.append(logMessage);

        QString logOnMessage = " LOG ON";
        QString loginMessage = "Pilot:" + ui->CallSignLineEdit->text() + ":" +ui->fmcLabel_R3->text() + " ";
        QString message = loginMessage + ui->FMCTimeLineEdit->text() + logOnMessage;
        socket->write(message.toUtf8());
    }

    else if(STATUS == "TERMINATE")
    {
        setSTATUS("WELCOME");
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString terminateMessage = PILOTmessageColor + "CONNECTION TERMINATED" + endHTML;
        ui->pilotTextEdit->insertHtml(terminateMessage);

        QString message = ui->pilotTextEdit->toPlainText();

        QString loginMessage = "Pilot:" + ui->CallSignLineEdit->text() + ":" + ATCcallSign + " ";
        QString wholeMessage = loginMessage + message;
        historyList.append(terminateMessage);
        socket->write(wholeMessage.toUtf8());

        ui->FMCCallSignLineEdit->setText("/" + callSignList.at(1));        
    }

    else if(STATUS == "REPORT")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "PASSING POINT ";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    else if(STATUS == "REPORTALT")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "MAINTAINING ALT ";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    else if(STATUS == "REPORTFL")
    {
        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "MAINTAINING FL";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    qDebug() << STATUS;
}

void MainWindow::fmcButtonR4clicked()
{
    if((STATUS == "VIEWMESSAGES") || (STATUS == "REQUEST") || (STATUS == "REPORTALT") || (STATUS == "REPORTFL") || (STATUS == "RADIAL") || (STATUS == "REPORTDISTANCE") || (STATUS == "TERMINATE"))
    {
        setSTATUS("MAINPAGE");
    }

    else if((STATUS == "LOGON") && (!ui->fmcLabel_R4->text().isEmpty()))
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";

        ui->pilotTextEdit->clear();
        QString logMessage = PILOTmessageColor + ui->FMCTimeLineEdit->text() + " LOG ON" + endHTML;
        ui->pilotTextEdit->insertHtml(logMessage);
        historyList.append(logMessage);

        QString logOnMessage = " LOG ON";
        QString loginMessage = "Pilot:" + ui->CallSignLineEdit->text() + ":" +ui->fmcLabel_R4->text() + " ";
        QString message = loginMessage + ui->FMCTimeLineEdit->text() + logOnMessage;
        socket->write(message.toUtf8());
    }

    else if(STATUS == "MAINPAGE")
    {
        setSTATUS("TERMINATE");
    }

    else if(STATUS == "REPORT")
    {
        setSTATUS("RADIAL");

        ui->pilotTextEdit->setEnabled(true);
        ui->pilotTextEdit->setReadOnly(false);
        QString ATCmessageColor = "<font color=\"White\">";
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font><br>";

        QStringList callSignList = ui->FMCCallSignLineEdit->text().split("/");
        QString ATCcallSign = callSignList.at(0);

        ui->pilotTextEdit->clear();
        QString initMessage = ui->FMCTimeLineEdit->text() + " TO " + ATCcallSign + " CTL ";
        QString initHtmlMessage = PILOTmessageColor + initMessage + endHTML;
        ui->pilotTextEdit->insertHtml(initHtmlMessage);
        QString altMessage = ATCmessageColor + "ESTABLISHED RAD ";
        ui->pilotTextEdit->insertHtml(altMessage);
        ui->pilotTextEdit->setFocus();

        ui->fmcSENDbutton->show();
        ui->fmcCANCELbutton->show();

        editable = true;
    }

    qDebug() << STATUS;
}

void MainWindow::pilotMenuButton_clicked()
{
    setSTATUS("MAINPAGE");
}

void MainWindow::pilotMSGButton_clicked()
{
    setSTATUS("VIEWMESSAGES");
}

void MainWindow::keyPad_1_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "A" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_2_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "B" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_3_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "C" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_4_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "D" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_5_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "E" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_6_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "F" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_7_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "G" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_8_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "H" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_9_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "I" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_10_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "J" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_11_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "K" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_12_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "L" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_13_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "M" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_14_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "N" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_15_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "O" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_16_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "P" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_17_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "Q" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_18_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "R" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_19_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "S" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_20_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "T" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_21_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "U" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_22_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "V" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_23_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "W" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_24_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "X" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_25_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "Y" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_26_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "Z" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_27_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "&nbsp;" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_28_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString orig = ui->pilotTextEdit->toPlainText();
        int len = orig.length();
        QString newMessage = PILOTmessageColor + orig.left(len-1) + endHTML;
        ui->pilotTextEdit->clear();
        ui->pilotTextEdit->insertHtml(newMessage);
    }
}

void MainWindow::keyPad_29_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "/" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::keyPad_30_clicked()
{
    if(editable == true)
    {
        ui->pilotTextEdit->clear();
        setSTATUS(STATUS);
        ui->fmcWILCObutton->hide();
        ui->fmcROGERbutton->hide();
        ui->fmcDISCARDbutton->hide();
        ui->fmcSTANDBYbutton->hide();
        ui->fmcUNABLEbutton->hide();
        ui->fmcWEATHERbutton->hide();
        ui->fmcPERFORMANCEbutton->hide();
        ui->fmcSENDbutton->hide();
        ui->fmcCANCELbutton->hide();
        ui->fmcMODIFYbutton->hide();
    }
}

void MainWindow::numPad_1_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "1" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::numPad_2_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "2" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::numPad_3_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "3" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::numPad_4_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "4" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::numPad_5_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "5" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::numPad_6_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "6" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::numPad_7_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "7" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::numPad_8_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "8" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::numPad_9_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "9" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::numPad_10_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "." + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::numPad_11_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString message = PILOTmessageColor + "0" + endHTML;
        ui->pilotTextEdit->insertHtml(message);
    }
}

void MainWindow::numPad_12_clicked()
{
    if(editable == true)
    {
        QString PILOTmessageColor = "<font color=\"Lime\">";
        QString endHTML = "</font>";
        QString orig = ui->pilotTextEdit->toPlainText();
        int len = orig.length();
        QString last = orig.right(1);

        if(last == "+")
        {
            QString newMessage = PILOTmessageColor + orig.left(len-1) + "-" + endHTML;
            ui->pilotTextEdit->clear();
            ui->pilotTextEdit->insertHtml(newMessage);
        }
        else if(last == "-")
        {
            QString newMessage = PILOTmessageColor + orig.left(len-1) + "+" + endHTML;
            ui->pilotTextEdit->clear();
            ui->pilotTextEdit->insertHtml(newMessage);
        }
        else
        {
            QString PILOTmessageColor = "<font color=\"Lime\">";
            QString endHTML = "</font>";
            QString message = PILOTmessageColor + "+" + endHTML;
            ui->pilotTextEdit->insertHtml(message);
        }
    }
}

void MainWindow::autosave()
{
    QString text = ui->ATCTextEdit->toPlainText();

    QFile file("autosave.txt");
    if( !file.open( QIODevice::WriteOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for writing.";
    }
    else
    {
        QTextStream stream(&file);
        stream << text;
    }

    file.close();

    QFile file_2("autosave_TIME.txt");
    if( !file_2.open( QIODevice::WriteOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file_2.fileName() << "for writing.";
    }
    else
    {
        QTextStream stream(&file_2);
        int Length = ExportTimeList.length();

        for(int i=0; i<Length; i++)
        {
            stream << ExportTimeList.at(i);
            stream << "::";
            stream << ExportMessageList.at(i) << "\n";
        }
    }

    file_2.close();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(ui->ATCRadioButton->isChecked())
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,"DLCSim","Do you really want to exit this application?"
                              ,QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            event->accept();
        }
        else
            event->ignore();
    }

    if(ui->PilotRadioButton->isChecked())
    {        
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,"DLCSim","Do you really want to exit this application?"
                              ,QMessageBox::Yes|QMessageBox::No);

        if(reply == QMessageBox::Yes)
        {
            emit(terminate_clicked(ui->CallSignLineEdit->text()));
            //delay(1000);

            overwriteLOGGED(StripDataFrom, ui->CallSignLineEdit->text(), "PLANNED");

            event->accept();
        }
        else
            event->ignore();
    }
}

void MainWindow::labelChange_pending(const QString &message)
{
    ui->ATCSendLineEdit->setText(message);
}

void MainWindow::pilotListWidget_IN_clicked(QListWidgetItem *item)
{
    ui->ATCToLabel->setText("Pilot:" + PilotListWidget_inbound->currentItem()->text());

    item->setBackground(Qt::white);

    ui->ATCTextEdit->clear();
    QStringList messageList = hashList.values(PilotListWidget_inbound->currentItem()->text());
    QListIterator<QString> iter(messageList);
    iter.toBack();
    while(iter.hasPrevious())
    {
        QString message = iter.previous();
        ui->ATCTextEdit->insertHtml(message);
    }

    QTextCursor cursor = ui->ATCTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    ui->ATCTextEdit->setTextCursor(cursor);
}

void MainWindow::showStrip_IN()
{
    QString title = ui->ATCToLabel->text();
    QStringList titleList = title.split(":");
    QString PATC = titleList.at(0);
    QString CallSign = titleList.at(1);


    if(title.contains("ATC"))
    {

    }
    else
    {
        showStrip_inbound(CallSign);
    }
}

void MainWindow::showLabel_IN()
{
    label->setStripDataName(StripDataFrom);
    dock->show();

    QString callsign = PilotListWidget_inbound->currentItem()->text();

    label->setATCcallsign(ui->CallSignLineEdit->text());
    label->setCallSign(callsign);            // takto sa posielaju data do LABELu


    readSTRIP(StripDataFrom, callsign);

    label->setCurrentFL(getFL(stripList));
    label->setCurrentRadial(getRADIAL(stripList));
    label->updateCallSignColor();
}

void MainWindow::pilotListWidget_OU_clicked(QListWidgetItem *item)
{
    ui->ATCToLabel->setText("Pilot:" + PilotListWidget_outbound->currentItem()->text());

    item->setBackground(Qt::white);

    ui->ATCTextEdit->clear();
    QStringList messageList = hashList.values(PilotListWidget_outbound->currentItem()->text());
    QListIterator<QString> iter(messageList);
    iter.toBack();
    while(iter.hasPrevious())
    {
        QString message = iter.previous();
        ui->ATCTextEdit->insertHtml(message);
    }

    QTextCursor cursor = ui->ATCTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    ui->ATCTextEdit->setTextCursor(cursor);
}

void MainWindow::showStrip_OU()
{
    QString title = ui->ATCToLabel->text();
    QStringList titleList = title.split(":");
    QString PATC = titleList.at(0);
    QString CallSign = titleList.at(1);

    if(title.contains("ATC"))
    {

    }
    else
    {
        showStrip_outbound(CallSign);
    }
}

void MainWindow::showLabel_OU()
{
    label->setStripDataName(StripDataFrom);
    dock->show();

    QString callsign = PilotListWidget_outbound->currentItem()->text();

    label->setATCcallsign(ui->CallSignLineEdit->text());
    label->setCallSign(callsign);            // takto sa posielaju data do LABELu

    readSTRIP(StripDataFrom, callsign);

    label->setCurrentFL(getFL(stripList));
    label->setCurrentRadial(getRADIAL(stripList));
    label->updateCallSignColor();
}









