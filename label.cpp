#include "label.h"
#include "ui_label.h"

Label::Label(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Label)
{
    ui->setupUi(this);

    QNH = "1013";
    METAR_data = "";

    QRegExp intRx("[0-9]+");
    QRegExpValidator *intValidator = new QRegExpValidator(intRx,this);
    ui->RATElineEdit->setValidator(intValidator);
    ui->ALTITUDElineEdit->setValidator(intValidator);
    ui->TIMElineEdit->setValidator(intValidator);
    ui->RADIALlineEdit->setValidator(intValidator);
    ui->DISTANCElineEdit->setValidator(intValidator);

    QString style = QString("QPushButton {background-color: QLinearGradient( x1: 0, y1: 1, x2: 1, y2: 1, stop: 0 #00ff00 stop: 0.2 #000000  stop: 0.8 #000000 stop: 1 #00ff00);"
                                "color: white;"
                                "border-style: outset;"
                                "border-width: 1px;"
                                "border-radius: 4px;"
                                "border-color: beige;"
                                "border-style: solid;"
                                "padding: 1px;"
                                "font: bold kerning 22px 'MS Shell Dlg 2';}"
                   "QPushButton:pressed {background-color: white;"
                                "border-style: inset;}"
                   "QPushButton:hover {background-color: QLinearGradient( x1: 0, y1: 1, x2: 1, y2: 1, stop: 0 #999999 stop: 0.5 #00ff00 stop: 1 #999999);"
                                "color: black;}"
                   "QPushButton:focus:pressed {background-color: yellow;}"
                   "QRadioButton {font: bold kerning 18px 'MS Shell Dlg 2';}"
                   "QLineEdit {background-color: white;"
                                "font: bold kerning 18px 'MS Shell Dlg 2';"
                                "color: black;"
                                "border-style: outset;"
                                "border-color: black;"
                                "border-width: 1px;"
                                "border-radius: 2px;}"
                   "QLabel {font: bold kerning 18px 'MS Shell Dlg 2';"
                                "color: black;}"
                   "QLabel#callSign {font: bold kerning 18px 'MS Shell Dlg 2';"
                                "color: black;}"
                   "QComboBox {background-color: QLinearGradient( x1: 0, y1: 1, x2: 1, y2: 1, stop: 0 #00ff00 stop: 0.2 #000000  stop: 0.8 #000000 stop: 1 #00ff00);"
                                "color: white;"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 4px;"
                                "border-color: beige;"
                                "border-style: solid;"
                                "padding: 3px;"
                                "font: bold kerning 18px 'MS Shell Dlg 2';}"
                    "QComboBox:pressed {border-style: inset;}"
                    "QComboBox:hover {background-color: QLinearGradient( x1: 0, y1: 1, x2: 1, y2: 1, stop: 0 #999999 stop: 0.5 #00ff00 stop: 1 #999999);"
                                "color: black;}"
                    "QComboBox QAbstractItemView {"
                                "border: 2px solid black;"
                                "selection-background-color: green;}"
                    "QGroupBox {font: bold kerning 18px 'MS Shell Dlg 2';"
                                "color: black;}"
                    "QCheckBox {font: bold kerning 18px 'MS Shell Dlg 2';"
                                "color: black;}");

    setStyleSheet(style);

    ui->callSign->setAlignment(Qt::AlignCenter);
    ui->RADIALlabel_current->setAlignment(Qt::AlignCenter);
    ui->FLlabel_current->setAlignment(Qt::AlignCenter);
    setFL();
    ui->FLQNH->setChecked(false);
    ui->freqNextUnit->setChecked(false);

    //ui->verticalLayout_4->setSpacing(0);
    ATCcallsign = "";

    ui->cancelButton->hide();
    ui->RATElineEdit->hide();
    ui->TIMElineEdit->hide();
    ui->pointComboBox->hide();
    ui->uplinkButton->hide();
    ui->RADIALlineEdit->hide();
    ui->ALTITUDElineEdit->hide();
    ui->DISTANCElineEdit->hide();
    ui->RADIALlabel->hide();
    ui->TIMElabel->hide();
    ui->RADIALlabel->hide();
    ui->ALTITUDElabel->hide();
    ui->DISTANCElabel->hide();
    ui->RATElabel->hide();
    ui->trackComboBox->hide();

    updateFreqList();

    connect(ui->FLcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(FLchange_slot()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(canceled_slot()));
    connect(ui->uplinkButton, SIGNAL(clicked()), this, SLOT(uplink_slot()));
    connect(ui->RADIALbutton, SIGNAL(clicked()), this, SLOT(radialButtonClicked_slot()));
    connect(ui->FreqComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(freqChangeClicked_slot(QString)));
    connect(ui->MessageComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(currentMessageREAD_slot(QString)));
    connect(ui->pointComboBox, SIGNAL(currentIndexChanged(QString)), this, SIGNAL(pointChange_pending(QString)));
    connect(ui->trackComboBox, SIGNAL(currentIndexChanged(QString)), this, SIGNAL(trackChange_pending(QString)));
    connect(ui->FLQNH, SIGNAL(clicked(bool)), this, SIGNAL(QNHChecked(bool)));

    connect(ui->TIMElineEdit, SIGNAL(textEdited(QString)), this, SIGNAL(TIMEchange_pending(QString)));
    connect(ui->RATElineEdit, SIGNAL(textEdited(QString)), this, SIGNAL(RATEchange_pending(QString)));
    connect(ui->ALTITUDElineEdit, SIGNAL(textEdited(QString)), this, SIGNAL(ALTITUDEchange_pending(QString)));
    connect(ui->RADIALlineEdit, SIGNAL(textEdited(QString)), this, SIGNAL(RADIALchange_pending(QString)));
    connect(ui->DISTANCElineEdit, SIGNAL(textEdited(QString)), this, SIGNAL(DISTANCEchange_pending(QString)));

    connect(ui->VRrb, SIGNAL(clicked()), this, SLOT(messageREAD_slot()));
    connect(ui->TMrb, SIGNAL(clicked()), this, SLOT(messageREAD_slot()));
    connect(ui->RADrb, SIGNAL(clicked()), this, SLOT(messageREAD_slot()));
    connect(ui->ALTrb, SIGNAL(clicked()), this, SLOT(messageREAD_slot()));
    connect(ui->PTrb, SIGNAL(clicked()), this, SLOT(messageREAD_slot()));
    connect(ui->FLrb, SIGNAL(clicked()), this, SLOT(messageREAD_slot()));
    connect(ui->ROUTErb, SIGNAL(clicked()) ,this, SLOT(messageREAD_slot()));

    connect(ui->rogerButton, SIGNAL(clicked()), this, SLOT(ROGER_clicked()));
    connect(ui->disregardButton, SIGNAL(clicked()), this, SLOT(DISREGARD_clicked()));
    connect(ui->affirmButton, SIGNAL(clicked()), this, SLOT(AFFIRM_clicked()));
    connect(ui->negativeButton, SIGNAL(clicked()), this, SLOT(NEGATIVE_clicked()));
    connect(ui->contactRequestButton, SIGNAL(clicked()), this, SLOT(CONTACTrequest_clicked()));
    connect(ui->contactRequestVoiceButton, SIGNAL(clicked()), this, SLOT(CONTACTrequestVoice_clicked()));
    connect(ui->logOnButton, SIGNAL(clicked()), this, SLOT(logOnclicked_clicked()));
    connect(ui->resumeOwnNavigationButton, SIGNAL(clicked()), this, SLOT(RESUMEownNavigation_clicked()));

    ui->MessageComboBox->show();
}

Label::~Label()
{
    delete ui;
}

void Label::setCallSign(const QString &CallSign)
{
    callsign = CallSign;
    ui->callSign->setText(CallSign);

    if(!radialHash.contains(CallSign))
    {
        radialHash.insert(CallSign, 999);
    }
    else
    {
        int rad = radialHash.value(CallSign);

        if(rad == 999)
        {
            ui->RADIALbutton->setText("RADIAL");
        }
        else
        {
            ui->RADIALbutton->setText(QString::number(rad));
        }
    }

    qDebug() << "CALLSIGNLIST_SELECTED" << radialHash;
}

QString Label::getCurrentFL(const QStringList &StripList)
{
    readSTRIP(StripDataFileName, callsign);

    QString FL;
    if(!StripList.isEmpty())
    {
       FL = StripList.at(13);
    }
    else
    {
       FL = "NONE";
    }

    return FL;
}

QString Label::getCurrentRADIAL(const QStringList &StripList)
{
    readSTRIP(StripDataFileName, callsign);

    QString RADIAL;
    if(!StripList.isEmpty())
    {
       RADIAL = StripList.at(14);
    }
    else
    {
       RADIAL = "NONE";
    }

    return RADIAL;
}

void Label::setFL()
{
    ui->FLcomboBox->clear();
    QStringList FLnumbers;

    int step = 10;
    int startFL = 0;
    for(int i=0; i<=40; i++)
    {
        int number = startFL + i*step;
        FLnumbers.append("FL" + QString::number(number));
    }

    ui->FLcomboBox->insertItems(0, FLnumbers);
}

void Label::setRadial(const QString &Radial)
{
    ui->RADIALbutton->setText(Radial);
}

void Label::readSTRIP(const QString &fileName, const QString &CallSign)
{
    qDebug() << fileName << CallSign;
    stripList.clear();
    QFile file(fileName);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }

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
    file.close();
}

QStringList Label::readFile(const QString &FileName)
{
    QFile file(FileName);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }

    QString line;
    QStringList lineList;
    QTextStream stream(&file);

    while( !stream.atEnd())
    {
        line = stream.readLine();       // precita riadky postupne
        lineList.append(line);     // postupne prida do listu riadkiv
    }
    file.close();

    return lineList;
}

QStringList Label::getINFOfromFile(const QStringList &stringList, const QString &info)
{
    QStringList infoList;

    QListIterator<QString> iter(stringList);
    while(iter.hasNext())
    {
        QString line = iter.next();
        if(line.contains(info))
        {
            QStringList lineList = line.split("#");
            infoList = lineList.at(1).split(";");
        }
    }

    return infoList;
}

void Label::updateFreqList()
{
    QStringList fileList = readFile("MESSAGESinfo.txt");
    QStringList POSTSlist = getINFOfromFile(fileList, "POSTS");
    QStringList POSTFREQlist = getINFOfromFile(fileList, "POSTFREQ");

    QStringList postfregList;
    for(int i=0; i<POSTSlist.length(); i++)
    {
        postfregList.append(POSTSlist.at(i) + " " + POSTFREQlist.at(i));
    }

    ui->FreqComboBox->insertItem(0,"FREQ CHANGE");
    ui->FreqComboBox->insertItems(0, postfregList);
}

// nacita body zo suboru a vlozi ich do POINT combo box
void Label::updatePointList()
{
    ui->pointComboBox->clear();
    QStringList fileList = readFile("MESSAGESinfo.txt");
    QStringList infoList = getINFOfromFile(fileList, "POINT");

    ui->pointComboBox->insertItems(0,infoList);
}

void Label::updateTrackList()
{
    ui->trackComboBox->clear();
    QStringList fileList = readFile("MESSAGESinfo.txt");
    QStringList infoList = getINFOfromFile(fileList, "TRACK");

    ui->trackComboBox->insertItems(0, infoList);
}

void Label::getQNH(const QString &QNHdata)
{
    QNH = QNHdata;
}

void Label::ROGER_clicked()
{
    canceled_slot();
    ui->cancelButton->show();
    ui->uplinkButton->show();
    QString message = "ROGER";
    emit(roger_signal(message));
}

void Label::DISREGARD_clicked()
{
    canceled_slot();
    ui->cancelButton->show();
    ui->uplinkButton->show();
    QString message = "DISREGARD";
    emit(disregard_signal(message));
}

void Label::AFFIRM_clicked()
{
    canceled_slot();
    ui->cancelButton->show();
    ui->uplinkButton->show();
    QString message = "AFFIRM";
    emit(affirm_signal(message));
}

void Label::NEGATIVE_clicked()
{
    canceled_slot();
    ui->cancelButton->show();
    ui->uplinkButton->show();
    QString message = "NEGATIVE";
    emit(negative_signal(message));
}

void Label::CONTACTrequest_clicked()
{
    canceled_slot();
    ui->cancelButton->show();
    ui->uplinkButton->show();
    QString message = "CONTACT REQUEST";
    emit(contactRequest_signal(message));
}

void Label::CONTACTrequestVoice_clicked()
{
    canceled_slot();
    ui->cancelButton->show();
    ui->uplinkButton->show();
    QString message = "CONTACT (REQUEST VOICE)";
    emit(contactRequestVoice_signal(message));
}

void Label::logOnclicked_clicked()
{
    canceled_slot();
    ui->cancelButton->show();
    ui->uplinkButton->show();
    QString message = "THIS IS AN AUTOMATED MESSAGE TO CONFIRM CPDLC CONTACT WITH " + ATCcallsign + " CENTRE";
    QString metarMessage;

    QStringList metarList = METAR_data.split(" ");
    if(metarList.length() > 2)
    {
        metarList.removeAt(1);
        metarMessage = "<br>METAR:" + metarList.join(" ");
    }


    message = message + metarMessage;

    emit(logOn_signal(message));
}

void Label::RESUMEownNavigation_clicked()
{
    canceled_slot();
    ui->cancelButton->show();
    ui->uplinkButton->show();
    QString message = "RESUME OWN NAVIGATION";
    emit(resumeOwnNavigation_signal(message));
}

void Label::FLchange_slot()
{
    if(ui->FLrb->isChecked() == true)
    {

    }
    else
    {
        //canceled_slot();
        //ui->FLrb->setChecked(true);
        //messageREAD_slot();
    }

    emit(FLchange_pending(ui->FLcomboBox->currentText()));
}

void Label::canceled_slot()
{
    int currentIndex = (ui->FLcomboBox->count() - 1) / 2;
    ui->FLcomboBox->setCurrentIndex(currentIndex);
    ui->cancelButton->hide();
    ui->RATElineEdit->hide();
    ui->TIMElineEdit->hide();
    ui->pointComboBox->hide();
    ui->RADIALlineEdit->hide();
    ui->ALTITUDElineEdit->hide();
    ui->DISTANCElineEdit->hide();
    ui->uplinkButton->hide();
    ui->RADIALlabel->hide();
    ui->TIMElabel->hide();
    ui->RADIALlabel->hide();
    ui->ALTITUDElabel->hide();
    ui->DISTANCElabel->hide();
    ui->RATElabel->hide();
    ui->trackComboBox->hide();

    QString message = "";
    emit(change_cancelled(message));

    ui->TIMElineEdit->clear();
    ui->RADIALlineEdit->clear();
    ui->DISTANCElineEdit->clear();
    ui->RADIALlineEdit->clear();
    ui->ALTITUDElineEdit->clear();
}

void Label::uplink_slot()
{
    emit(change_uplink());

    int rad;
    if(!ui->RADIALlineEdit->text().isEmpty())
    {
        rad = ui->RADIALlineEdit->text().toInt();
        radialHash[callsign] = rad;
    }

    qDebug() << radialHash;


    if(!ui->RADIALlineEdit->text().isEmpty())
        ui->RADIALbutton->setText(ui->RADIALlineEdit->text());

    ui->TIMElineEdit->clear();
    ui->RADIALlineEdit->clear();
    ui->DISTANCElineEdit->clear();
    ui->RADIALlineEdit->clear();
    ui->ALTITUDElineEdit->clear();
    ui->RATElineEdit->clear();
}

void Label::radialButtonClicked_slot()
{
    canceled_slot();
    ui->RADrb->setChecked(true);

    messageREAD_slot();
}

void Label::freqChangeClicked_slot(const QString &PostFreq)
{
    canceled_slot();
    ui->MessageComboBox->clear();

    if(PostFreq == "FREQ CHANGE")
    {
        emit(frequencyChange_pending(""));
        ui->uplinkButton->hide();
        ui->cancelButton->hide();
    }
    else
    {
        if(ui->freqNextUnit->isChecked() == true)
        {
            emit(frequencyChange_pending("REQUEST WITH NEXT UNIT CONTACT " + PostFreq));
            ui->uplinkButton->show();
            ui->cancelButton->show();
        }
        else
        {
            emit(frequencyChange_pending("CONTACT " + PostFreq));
            ui->uplinkButton->show();
            ui->cancelButton->show();
        }
    }
}

// podla toho co je oznacene v MESSAGE group box nacita spravy do MESSAGE combo box zo suboru sprav
void Label::messageREAD_slot()
{
    ui->MessageComboBox->clear();
    ui->cancelButton->hide();
    ui->RATElineEdit->hide();
    ui->TIMElineEdit->hide();
    ui->pointComboBox->hide();
    ui->RADIALlineEdit->hide();
    ui->ALTITUDElineEdit->hide();
    ui->DISTANCElineEdit->hide();
    ui->uplinkButton->hide();
    ui->RADIALlabel->hide();
    ui->TIMElabel->hide();
    ui->RADIALlabel->hide();
    ui->ALTITUDElabel->hide();
    ui->DISTANCElabel->hide();
    ui->RATElabel->hide();
    ui->trackComboBox->hide();

    QString fileName = "MESSAGES.txt";
    QFile file(fileName);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }

    QString line;
    QStringList lineList;
    QTextStream stream(&file);

    while( !stream.atEnd())
    {
        line = stream.readLine();       // precita riadky postupne

        if(ui->RADrb->isChecked() == true)
        {
            if(line.contains("[RADIAL]"))
            {
                lineList.append(line);
            }
        }
        if(ui->PTrb->isChecked() == true)
        {
            if(line.contains("[POINT]"))
            {
                lineList.append(line);
            }
        }
        if(ui->ALTrb->isChecked() == true)
        {
            if(line.contains("[ALTITUDE]"))
            {
                lineList.append(line);
            }
        }
        if(ui->VRrb->isChecked() == true)
        {
            if(line.contains("[VERTICALRATE]"))
            {
                lineList.append(line);
            }
        }
        if(ui->TMrb->isChecked() == true)
        {
            if(line.contains("[TIME]"))
            {
                lineList.append(line);
            }
        }
        if(ui->ROUTErb->isChecked() == true)
        {
            if(line.contains("[TRACK]"))
            {
                lineList.append(line);
            }
        }
        if(ui->FLrb->isChecked() == true)
        {
            if(line.contains("[LEVEL]"))
            {
                lineList.append(line);
            }
        }
    }

    file.close();
    if(ui->ALTrb->isChecked() == true)
    {
        lineList.append("REPORT PRESENT ALTITUDE");
    }
    if(ui->FLrb->isChecked() == true)
    {
        lineList.append("REPORT PRESENT LEVEL");
    }
    if(ui->VRrb->isChecked() == true)
    {
        lineList.append("CLB AT VR MIN");
        lineList.append("CLB AT VR MAX");
        lineList.append("DESC AT VR MIN");
        lineList.append("DESC AT VR MAX");
    }

    ui->MessageComboBox->insertItems(0,lineList);
    ui->MessageComboBox->show();
}

// podla toho aka sprava sa vyberie zo zoznamu tak ukaze polia ktore treba vyplnit + CANCEL a UPLINK
void Label::currentMessageREAD_slot(const QString &message)
{
    ui->RATElineEdit->hide();
    ui->TIMElineEdit->hide();
    ui->pointComboBox->hide();
    ui->RADIALlineEdit->hide();
    ui->ALTITUDElineEdit->hide();
    ui->DISTANCElineEdit->hide();
    ui->RADIALlabel->hide();
    ui->TIMElabel->hide();
    ui->RADIALlabel->hide();
    ui->ALTITUDElabel->hide();
    ui->DISTANCElabel->hide();
    ui->RATElabel->hide();
    ui->trackComboBox->hide();

    ui->cancelButton->show();
    ui->uplinkButton->show();

    if(message.contains("[RADIAL]"))
    {
        ui->RADIALlineEdit->show();
        ui->RADIALlabel->show();
    }
    if(message.contains("[POINT]"))
    {
        updatePointList();
        ui->pointComboBox->show();
    }
    if(message.contains("[ALTITUDE]"))
    {
        ui->ALTITUDElineEdit->show();
        ui->ALTITUDElabel->show();
    }
    if(message.contains("[VERTICALRATE]"))
    {
        ui->RATElineEdit->show();
        ui->RATElabel->show();
    }
    if(message.contains("[TIME]"))
    {
        ui->TIMElineEdit->show();
        ui->TIMElabel->show();
    }
    if(message.contains("[DISTANCE]"))
    {
        ui->DISTANCElineEdit->show();
        ui->DISTANCElabel->show();
    }
    if(message.contains("[TRACK]"))
    {
        updateTrackList();
        ui->trackComboBox->show();
    }
    if(message.contains("[LEVEL]"))
    {
        ui->FLcomboBox->setCurrentIndex(1);
    }

    emit(messageChanged(message));
}

void Label::getMetarData(const QString &METAR_DATA)
{
    METAR_data = METAR_DATA;
}

void Label::setATCcallsign(const QString &ATCCallSign)
{
    ATCcallsign = ATCCallSign;
}

void Label::updateCallSignColor()
{
    QString callSignString;
    readSTRIP(StripDataFileName, callsign);
    if(stripList.at(0) == "INBOUND")
    {
        callSignString = QString("QLabel#callSign {font: bold kerning 18px 'MS Shell Dlg 2';"
                                                    "color: red;}");
    }
    else if(stripList.at(0) == "OVERFLIGHT")
    {
        callSignString = QString("QLabel#callSign {font: bold kerning 18px 'MS Shell Dlg 2';"
                                                    "color: black;}");
    }
    else if(stripList.at(0) == "OUTBOUND")
    {
        callSignString = QString("QLabel#callSign {font: bold kerning 18px 'MS Shell Dlg 2';"
                                                    "color: blue;}");
    }
    ui->callSign->setStyleSheet(callSignString);
}

void Label::setStripDataName(const QString &fileName)
{
    StripDataFileName = fileName;
}

void Label::setCurrentFL(const QString &level)
{
    ui->FLlabel_current->setText(level);
}

void Label::setCurrentRadial(const QString &radial)
{
    ui->RADIALlabel_current->setText(radial);
}














