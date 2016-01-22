#include "stripoutbound.h"
#include "ui_stripoutbound.h"
#include <QFile>
#include <QDebug>

StripOutbound::StripOutbound(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StripOutbound)
{
    ui->setupUi(this);

    FPcallsign = "";
    FlightPlan = "";
    FPcounter = 0;

    setFixedSize(840,80);

    QStringList pointList = readInfoFromFile("MESSAGESinfo.txt", "POINT");
    ui->point_comboBox->insertItems(0,pointList);
    ui->point_comboBox->setCurrentIndex(0);

    connect(qApp, SIGNAL(focusChanged(QWidget*,QWidget*)), this, SLOT(updateStrip_slot()));
    connect(ui->point_comboBox, SIGNAL(activated(QString)), this, SLOT(point_changed(QString)));
    connect(ui->time_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));
    connect(ui->flightLevel_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));
    connect(ui->ETD_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));
    connect(ui->comment1_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));
    connect(ui->comment2_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));
    connect(ui->comment3_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));

    QString lineEditStyle = QString("QLineEdit {border: 0px solid black;}"
                                    "QLineEdit:hover {background-color: lightGreen;"
                                                "color: black;}"
                                    "QLineEdit:focus {background-color: lightGreen;}");

    ui->time_lineEdit->setStyleSheet(lineEditStyle);
    ui->flightLevel_lineEdit->setStyleSheet(lineEditStyle);
    ui->flightLevel_actual_label->setStyleSheet("border: 0px solid black;");
    ui->CallSign_label->setStyleSheet("border: 0px solid black;");
    ui->equipment_label->setStyleSheet("border: 0px solid black;");
    ui->squawk_label->setStyleSheet("border: 0px solid black;");
    ui->cruiseLevel_label->setStyleSheet("border: 0px solid black;");
    ui->aircraftType_label->setStyleSheet("border: 0px solid black;");
    ui->category_label->setStyleSheet("border: 0px solid black;");
    ui->depAirport_label->setStyleSheet("border: 0px solid black;");
    ui->destAirport_label->setStyleSheet("border: 0px solid black;");
    ui->track_label->setStyleSheet("border: 0px solid black;");
    ui->rwy_label->setStyleSheet("border: 0px solid black;");
    ui->outboundPoint_label->setStyleSheet("border: 0px solid black;");
    ui->ETD_lineEdit->setStyleSheet("QLineEdit {border: 0px solid black;"
                                    "background-color: yellow;}"
                                    "QLineEdit:hover {background-color: lightGreen;"
                                                "color: black;}"
                                    "QLineEdit:focus {background-color: lightGreen;}");

    ui->comment1_lineEdit->setStyleSheet(lineEditStyle);
    ui->comment2_lineEdit->setStyleSheet(lineEditStyle);
    ui->comment3_lineEdit->setStyleSheet(lineEditStyle);

    ui->point_comboBox->setStyleSheet("QComboBox {border: 0px solid black;"
                                      "font: bold kerning 15px 'MS Shell Dlg 2';"
                                      "color: black;}"
                          "QComboBox:pressed {border-style: inset;}"
                          "QComboBox:hover {background-color: lightGreen;"
                                      "color: black;}"
                          "QComboBox QAbstractItemView {"
                                      "selection-background-color: lightGreen;}");


    QRegExp rwInt("[0-9]{0,4}");
    QRegExp rwFL("[A-Z0-9]{0,5}");
    QRegExp rwCOMM("[A-Z0-9]{0,5}");
    QRegExpValidator *regExpValidatorInt = new QRegExpValidator(rwInt,this);
    QRegExpValidator *regExpValidatorFL = new QRegExpValidator(rwFL,this);
    QRegExpValidator *regExpValidatorCOMM = new QRegExpValidator(rwCOMM,this);
    ui->time_lineEdit->setValidator(regExpValidatorInt);
    ui->ETD_lineEdit->setValidator(regExpValidatorInt);
    ui->flightLevel_lineEdit->setValidator(regExpValidatorFL);
    ui->comment1_lineEdit->setValidator(regExpValidatorCOMM);
    ui->comment2_lineEdit->setValidator(regExpValidatorCOMM);
    ui->comment3_lineEdit->setValidator(regExpValidatorCOMM);
}

StripOutbound::~StripOutbound()
{
    delete ui;
}

QStringList StripOutbound::readStrip(const QString &FileName, const QString &CallSign)
{
    QStringList stripList;
    QFile file(FileName);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";          //nevie co ma citat
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

    return stripList;
}

void StripOutbound::setCallSign(const QString &CallSign)
{
    callSign = CallSign;
}

void StripOutbound::setStripDataFileName(const QString &dataFileName)
{
    stripDataFrom = dataFileName;
}

void StripOutbound::update()
{
    ui->CallSign_label->setText(callSign);
    QStringList stripDataList = readStrip(stripDataFrom, callSign);

    if(stripDataList.at(stripDataList.length()-1) == "LOGGED")
    {
        ui->frame->setStyleSheet("border-image: url(:/icons/images/up_arrow.png);"
                                 "border: 2px solid black;"
                                 "background: cyan");

        QString framestyle = QString("background: cyan;"
                                     "border: 2px solid black;");

        ui->frame_2->setStyleSheet(framestyle);
        ui->frame_3->setStyleSheet(framestyle);
        ui->frame_4->setStyleSheet(framestyle);
        ui->frame_5->setStyleSheet(framestyle);
        ui->frame_6->setStyleSheet(framestyle);
    }
    if(stripDataList.at(stripDataList.length()-1) == "PLANNED")
    {
        ui->frame->setStyleSheet("border-image: url(:/icons/images/up_arrow.png);"
                                 "border: 2px solid black;"
                                 "background: lime");

        QString framestyle = QString("background: lime;"
                                     "border: 2px solid black;");

        ui->frame_2->setStyleSheet(framestyle);
        ui->frame_3->setStyleSheet(framestyle);
        ui->frame_4->setStyleSheet(framestyle);
        ui->frame_5->setStyleSheet(framestyle);
        ui->frame_6->setStyleSheet(framestyle);
    }

    // tu budem citat z textaku veci aby sa objavili v stripe
    ui->time_lineEdit->setText(stripDataList.at(2));
    ui->flightLevel_lineEdit->setText(stripDataList.at(3));
    ui->flightLevel_actual_label->setText(stripDataList.at(stripDataList.length()-3));

    ui->equipment_label->setText(stripDataList.at(4));
    ui->squawk_label->setText(stripDataList.at(5));
    ui->cruiseLevel_label->setText(stripDataList.at(6));
    ui->aircraftType_label->setText(stripDataList.at(7));
    ui->category_label->setText(stripDataList.at(8));
    ui->depAirport_label->setText(stripDataList.at(9));
    ui->destAirport_label->setText(stripDataList.at(10));
    ui->track_label->setText(stripDataList.at(11));
    ui->rwy_label->setText(stripDataList.at(12));
    ui->outboundPoint_label->setText(stripDataList.at(13));
    ui->ETD_lineEdit->setText(stripDataList.at(14));
    ui->comment1_lineEdit->setText(stripDataList.at(15));
    ui->comment2_lineEdit->setText(stripDataList.at(16));
    ui->comment3_lineEdit->setText(stripDataList.at(17));

    QStringList pointList = readInfoFromFile("MESSAGESinfo.txt", "POINT");

    if(callSign == FPcallsign)
    {
        pointList = FlightPlan.split("+");
    }

    QListIterator<QString> point_iter(pointList);
    int idx = 0;
    while(point_iter.hasNext())
    {
        if(point_iter.next() == stripDataList.at(1))
        {
            ui->point_comboBox->setCurrentIndex(idx);
        }
        idx++;
    }
}

void StripOutbound::overwriteStrip(const QString &FileName, const QString &CallSignRow, const QString &callsign)
{
    QStringList lineComplete;
    QFile file(FileName);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";          //nevie co ma citat
    }
    else
    {
        QString line;

        QStringList lineList;
        QTextStream stream(&file);

        while( !stream.atEnd())
        {
            line = stream.readLine();       // precita riadky postupne
            lineComplete.append(line);      // vyrobim list zo vsetkych riadkov
            lineList = line.split("#");     // oddeli na CallSign a zbytok stripu

            if(lineList.at(0) == callsign)  // nasiel som svoj CallSign ktory riadok chcem zamenit
            {
                lineComplete.replace(lineComplete.length()-1, CallSignRow);
            }
        }
    }

    file.close();

    QFile file_2(FileName);
    if( !file_2.open( QIODevice::WriteOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for writing.";          //nevie co ma citat
    }
    else
    {
        //qDebug() << lineComplete;
        QTextStream stream(&file_2);

        QListIterator<QString> iter(lineComplete);
        while(iter.hasNext())
        {
            stream << iter.next() << "\n";
        }
    }

    file_2.close();
}

void StripOutbound::updateStrip_slot()
{
    //qDebug() << "updateSTrip";
    update();
}

void StripOutbound::terminate_clicked_slot(const QString &fromcallsign)
{
    if(callSign == fromcallsign)
    {
        this->close();
    }
}

void StripOutbound::logon_clicked_slot(const QString &fromcallsign)
{
    if(callSign == fromcallsign)
    {
        ui->frame->setStyleSheet("border-image: url(:/icons/images/up_arrow.png);"
                                 "border: 2px solid black;"
                                 "background: cyan");

        QString framestyle = QString("background: cyan;"
                                     "border: 2px solid black;");

        ui->frame_2->setStyleSheet(framestyle);
        ui->frame_3->setStyleSheet(framestyle);
        ui->frame_4->setStyleSheet(framestyle);
        ui->frame_5->setStyleSheet(framestyle);
        ui->frame_6->setStyleSheet(framestyle);
    }
}

void StripOutbound::actualflightLevel_changed(const QString &fromCallSign, const QString flightLevel)
{
    if(fromCallSign == callSign)
    {
        ui->flightLevel_actual_label->setText(flightLevel);
    }
}

void StripOutbound::point_changed(const QString &point)
{
    // emit signal ze som zmenil bodd na Direct to a nech to potom posle spravu pilotovi na zmenu WP Proceed Direct to POINT
    emit changeDirectWP(callSign, point);

    QStringList stripdataList = readStrip(stripDataFrom, callSign);

    stripdataList.replace(1, point);
    QString stripLine = createLine(stripdataList, callSign);
    overwriteStrip(stripDataFrom, stripLine, callSign);
}

void StripOutbound::changeInStrip()
{
    QStringList stripdataList = readStrip(stripDataFrom, callSign);
    stripdataList.replace(2, ui->time_lineEdit->text());
    stripdataList.replace(3, ui->flightLevel_lineEdit->text());
    stripdataList.replace(14, ui->ETD_lineEdit->text());
    stripdataList.replace(15, ui->comment1_lineEdit->text());
    stripdataList.replace(16, ui->comment2_lineEdit->text());
    stripdataList.replace(17, ui->comment3_lineEdit->text());

    QString stripLine = createLine(stripdataList, callSign);

    overwriteStrip(stripDataFrom, stripLine, callSign);
}

void StripOutbound::receiveFlightPlan(const QString &callsign, const QString &flightplan)
{
    FPcallsign = callsign;
    FlightPlan = flightplan;

    if(FPcounter == 0)
    {
        ui->point_comboBox->clear();
        QStringList pointList = readInfoFromFile("MESSAGESinfo.txt", "POINT");
        if(callSign == FPcallsign)
        {
            pointList = FlightPlan.split("+");
        }
        ui->point_comboBox->insertItems(0,pointList);
        ui->point_comboBox->setCurrentIndex(0);

        FPcounter = 1;
    }
}

QStringList StripOutbound::readInfoFromFile(const QString &FileName, const QString &info)
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
        lineList.append(line);     // postupne prida do listu riadky
    }
    file.close();

    QStringList infoList;

    QListIterator<QString> iter(lineList);
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

QString StripOutbound::createLine(const QStringList &stringList, const QString &CallSign)
{
    QString line = stringList.join(";");
    QString completeLine = CallSign + "#" + line;

    return completeLine;
}

void StripOutbound::closeEvent(QCloseEvent *event)
{
    emit STRIP_closed(callSign);
    event->accept();
}
