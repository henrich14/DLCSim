#include "stripinbound.h"
#include "ui_stripinbound.h"
#include <QDebug>
#include <QFile>

StripInbound::StripInbound(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StripInbound)
{
    ui->setupUi(this);

    FPcallsign = "";
    FlightPlan = "";
    FPcounter = 0;

    setFixedSize(740,80);

    QStringList trackList = readInfoFromFile("MESSAGESinfo.txt", "TRACK");
    ui->track_comboBox->insertItems(0,trackList);
    ui->track_comboBox->insertItem(0," ");
    ui->track_comboBox->setCurrentIndex(0);

    QStringList pointList = readInfoFromFile("MESSAGESinfo.txt", "POINT");
    ui->point1_comboBox->insertItems(0,pointList);
    ui->point1_comboBox->setCurrentIndex(0);

    pointList = readInfoFromFile("MESSAGESinfo.txt", "POINT");
    ui->point2_comboBox->insertItems(0,pointList);
    ui->point2_comboBox->setCurrentIndex(0);


    connect(qApp, SIGNAL(focusChanged(QWidget*,QWidget*)), this, SLOT(updateStrip_slot()));
    connect(ui->track_comboBox, SIGNAL(activated(QString)), this, SLOT(arrivalRoute_changed_slot(QString)));
    connect(ui->point1_comboBox, SIGNAL(activated(QString)), this, SLOT(point_1_changed(QString)));
    connect(ui->point2_comboBox, SIGNAL(activated(QString)), this, SLOT(point_2_changed(QString)));
    connect(ui->time1_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));
    connect(ui->time2_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));
    connect(ui->flightLevel1_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));
    connect(ui->flightLevel2_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));
    connect(ui->rwy_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));
    connect(ui->comment1_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));
    connect(ui->comment2_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));
    connect(ui->comment3_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeInStrip()));

    QString lineEditStyle = QString("QLineEdit {border: 0px solid black;}"
                                    "QLineEdit:hover {background-color: lightGreen;"
                                                "color: black;}"
                                    "QLineEdit:focus {background-color: lightGreen;}");

    ui->time1_lineEdit->setStyleSheet(lineEditStyle);
    ui->time2_lineEdit->setStyleSheet(lineEditStyle);
    ui->flightLevel1_lineEdit->setStyleSheet(lineEditStyle);
    ui->flightLevel2_lineEdit->setStyleSheet(lineEditStyle);
    ui->flightLevel_actual_label->setStyleSheet("border: 0px solid black;");
    ui->CallSign_label->setStyleSheet("border: 0px solid black;");
    ui->equipment_label->setStyleSheet("border: 0px solid black;");
    ui->squawk_label->setStyleSheet("border: 0px solid black;");
    ui->cruiseLevel_label->setStyleSheet("border: 0px solid black;");
    ui->aircraftType_label->setStyleSheet("border: 0px solid black;");
    ui->category_label->setStyleSheet("border: 0px solid black;");
    ui->depAirport_label->setStyleSheet("border: 0px solid black;");
    ui->destAirport_label->setStyleSheet("border: 0px solid black;");
    ui->rwy_lineEdit->setStyleSheet(lineEditStyle);
    ui->comment1_lineEdit->setStyleSheet(lineEditStyle);
    ui->comment2_lineEdit->setStyleSheet(lineEditStyle);
    ui->comment3_lineEdit->setStyleSheet(lineEditStyle);

    ui->track_comboBox->setStyleSheet("QComboBox {border: 0px solid black;"
                                      "font: bold kerning 15px 'MS Shell Dlg 2';"
                                      "color: black;}"
                          "QComboBox:pressed {border-style: inset;}"
                          "QComboBox:hover {background-color: lightGreen;"
                                      "color: black;}"
                          "QComboBox QAbstractItemView {"
                                      "selection-background-color: lightGreen;}");


    ui->point1_comboBox->setStyleSheet("QComboBox {border: 0px solid black;"
                                      "font: bold kerning 15px 'MS Shell Dlg 2';"
                                      "color: black;}"
                          "QComboBox:pressed {border-style: inset;}"
                          "QComboBox:hover {background-color: lightGreen;"
                                      "color: black;}"
                          "QComboBox QAbstractItemView {"
                                      "selection-background-color: lightGreen;}");

    ui->point2_comboBox->setStyleSheet("QComboBox {border: 0px solid black;"
                                      "font: bold kerning 15px 'MS Shell Dlg 2';"
                                      "color: black;}"
                          "QComboBox:pressed {border-style: inset;}"
                          "QComboBox:hover {background-color: lightGreen;"
                                      "color: black;}"
                          "QComboBox QAbstractItemView {"
                                      "selection-background-color: lightGreen;}");

    QRegExp rwInt("[0-9]{0,4}");
    QRegExp rwy("[0-9]{0,2}");
    QRegExp rwFL("[A-Z0-9]{0,5}");
    QRegExp rwCOMM("[A-Z0-9]{0,5}");
    QRegExpValidator *regExpValidatorInt = new QRegExpValidator(rwInt,this);
    QRegExpValidator *regExpValidatorFL = new QRegExpValidator(rwFL,this);
    QRegExpValidator *regExpValidatorRWY = new QRegExpValidator(rwy,this);
    QRegExpValidator *regExpValidatorCOMM = new QRegExpValidator(rwCOMM,this);
    ui->time1_lineEdit->setValidator(regExpValidatorInt);
    ui->time2_lineEdit->setValidator(regExpValidatorInt);
    ui->flightLevel1_lineEdit->setValidator(regExpValidatorFL);
    ui->flightLevel2_lineEdit->setValidator(regExpValidatorFL);
    ui->rwy_lineEdit->setValidator(regExpValidatorRWY);
    ui->comment1_lineEdit->setValidator(regExpValidatorCOMM);
    ui->comment2_lineEdit->setValidator(regExpValidatorCOMM);
    ui->comment3_lineEdit->setValidator(regExpValidatorCOMM);
}

StripInbound::~StripInbound()
{

    delete ui;
}

QStringList StripInbound::readStrip(const QString &FileName, const QString &CallSign)
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

void StripInbound::setCallSign(const QString &CallSign)
{
    callSign = CallSign;
}

void StripInbound::setStripDataFileName(const QString &dataFileName)
{
    stripDataFrom = dataFileName;
}

void StripInbound::update()
{
    ui->CallSign_label->setText(callSign);
    QStringList stripDataList = readStrip(stripDataFrom, callSign);

    if(stripDataList.at(stripDataList.length()-1) == "LOGGED")
    {
        ui->frame->setStyleSheet("border-image: url(:/icons/images/down_arrow.png);"
                                 "border: 2px solid black;"
                                 "background: red");

        QString framestyle = QString("background: red;"
                                     "border: 2px solid black;");

        ui->frame_2->setStyleSheet(framestyle);
        ui->frame_3->setStyleSheet(framestyle);
        ui->frame_4->setStyleSheet(framestyle);
        ui->frame_5->setStyleSheet(framestyle);
    }
    if(stripDataList.at(stripDataList.length()-1) == "PLANNED")
    {
        ui->frame->setStyleSheet("border-image: url(:/icons/images/down_arrow.png);"
                                 "border: 2px solid black;"
                                 "background: lime");

        QString framestyle = QString("background: lime;"
                                     "border: 2px solid black;");

        ui->frame_2->setStyleSheet(framestyle);
        ui->frame_3->setStyleSheet(framestyle);
        ui->frame_4->setStyleSheet(framestyle);
        ui->frame_5->setStyleSheet(framestyle);
    }

    // tu budem citat z textaku veci aby sa objavili v stripe
    ui->time1_lineEdit->setText(stripDataList.at(2));
    ui->time2_lineEdit->setText(stripDataList.at(5));
    ui->flightLevel1_lineEdit->setText(stripDataList.at(3));
    ui->flightLevel2_lineEdit->setText(stripDataList.at(6));
    ui->flightLevel_actual_label->setText(stripDataList.at(stripDataList.length()-3));

    ui->equipment_label->setText(stripDataList.at(7));
    ui->squawk_label->setText(stripDataList.at(8));
    ui->cruiseLevel_label->setText(stripDataList.at(9));
    ui->aircraftType_label->setText(stripDataList.at(10));
    ui->category_label->setText(stripDataList.at(11));
    ui->depAirport_label->setText(stripDataList.at(12));
    ui->destAirport_label->setText(stripDataList.at(13));
    ui->comment1_lineEdit->setText(stripDataList.at(16));
    ui->comment2_lineEdit->setText(stripDataList.at(17));
    ui->comment3_lineEdit->setText(stripDataList.at(18));

    QStringList trackList = readInfoFromFile("MESSAGESinfo.txt", "TRACK");
    QListIterator<QString> iter(trackList);
    int idx = 0;
    while(iter.hasNext())
    {
        if(iter.next() == stripDataList.at(14))
        {
            ui->track_comboBox->setCurrentIndex(idx+1);
        }
        idx++;
    }

    ui->rwy_lineEdit->setText(stripDataList.at(15));

    QStringList pointList = readInfoFromFile("MESSAGESinfo.txt", "POINT");

    if(callSign == FPcallsign)
    {
        pointList = FlightPlan.split("+");
    }

    QListIterator<QString> point_1_iter(pointList);
    idx = 0;
    while(point_1_iter.hasNext())
    {
        if(point_1_iter.next() == stripDataList.at(1))
        {
            ui->point1_comboBox->setCurrentIndex(idx);
        }
        idx++;
    }

    pointList = readInfoFromFile("MESSAGESinfo.txt", "POINT");

    QListIterator<QString> point_2_iter(pointList);
    idx = 0;
    while(point_2_iter.hasNext())
    {
        if(point_2_iter.next() == stripDataList.at(4))
        {
            ui->point2_comboBox->setCurrentIndex(idx);
        }
        idx++;
    }
}

void StripInbound::overwriteStrip(const QString &FileName, const QString &CallSignRow, const QString &callsign)
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

QString StripInbound::createLine(const QStringList &stringList, const QString &CallSign)
{
    QString line = stringList.join(";");
    QString completeLine = CallSign + "#" + line;

    return completeLine;
}

QStringList StripInbound::readInfoFromFile(const QString &FileName, const QString &info)
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

void StripInbound::updateStrip_slot()
{
    //qDebug() << "updateSTrip";
    update();
}

void StripInbound::terminate_clicked_slot(const QString &fromcallsign)
{
    if(callSign == fromcallsign)
    {
        QStringList stripDataList = readStrip(stripDataFrom, callSign);
        stripDataList.replace(14, "");
        stripDataList.replace(15, "");
        QString line = createLine(stripDataList, callSign);
        overwriteStrip(stripDataFrom, line, callSign);

        this->close();
    }
}

void StripInbound::logon_clicked_slot(const QString &fromcallsign)
{
    if(callSign == fromcallsign)
    {
        ui->frame->setStyleSheet("border-image: url(:/icons/images/down_arrow.png);"
                                 "border: 2px solid black;"
                                 "background: red");

        QString framestyle = QString("background: red;"
                                     "border: 2px solid black;");

        ui->frame_2->setStyleSheet(framestyle);
        ui->frame_3->setStyleSheet(framestyle);
        ui->frame_4->setStyleSheet(framestyle);
        ui->frame_5->setStyleSheet(framestyle);
    }
}

void StripInbound::arrivalRoute_changed_slot(const QString &route)
{
    if(route != " ")
    {
        emit(arrivalRoute_change_signal(route, callSign));

        ui->track_comboBox->setStyleSheet("QComboBox {border: 0px solid black;"
                                          "font: bold kerning 15px 'MS Shell Dlg 2';"
                                          "color: yellow;}"
                              "QComboBox:pressed {border-style: inset;}"
                              "QComboBox:hover {background-color: lightGreen;"
                                          "color: black;}"
                              "QComboBox QAbstractItemView {"
                                          "selection-background-color: lightGreen;}");
        ui->track_comboBox->update();

        if(ui->track_comboBox->itemData(0).toString() == "")
        {
            //ui->track_comboBox->removeItem(0);
        }

        QStringList trackList = readInfoFromFile("MESSAGESinfo.txt", "TRACK");
        //QStringList rwyList = readInfoFromFile("MESSAGESinfo.txt", "RWY");
        QListIterator<QString> iter(trackList);
        //QString rwy;
        //int idx = 0;
        //while(iter.hasNext())
        //{
        //    if(iter.next() == route)
        //    {
        //        rwy = rwyList.at(idx);
        //    }
        //    idx++;
        //}

        QStringList stripDataList = readStrip(stripDataFrom, callSign);
        //stripDataList.replace(15, rwy);
        //QString line = createLine(stripDataList, callSign);
        //overwriteStrip(stripDataFrom, line, callSign);
        //ui->rwy_lineEdit->setText(rwy);

        ui->rwy_lineEdit->setText(stripDataList.at(15));

        stripDataList.replace(14,ui->track_comboBox->currentText());
        QString lineComplete = createLine(stripDataList,callSign);
        //qDebug() << lineComplete;
        overwriteStrip(stripDataFrom,lineComplete,callSign);
    }

}

void StripInbound::point_1_changed(const QString &point1)
{
    emit changeDirectWP(callSign, point1);


    QStringList stripdataList = readStrip(stripDataFrom, callSign);

    stripdataList.replace(1, point1);
    QString stripLine = createLine(stripdataList, callSign);
    overwriteStrip(stripDataFrom, stripLine, callSign);
}

void StripInbound::point_2_changed(const QString &point2)
{
    QStringList stripdataList = readStrip(stripDataFrom, callSign);

    stripdataList.replace(4, point2);
    QString stripLine = createLine(stripdataList, callSign);
    overwriteStrip(stripDataFrom, stripLine, callSign);
}

void StripInbound::arrivalRoute_confirmed(const QString &fromCallSign)
{
    if(fromCallSign == callSign)
    {
        ui->track_comboBox->setStyleSheet("QComboBox {border: 0px solid black;"
                                          "font: bold kerning 15px 'MS Shell Dlg 2';"
                                          "color: black;}"
                              "QComboBox:pressed {border-style: inset;}"
                              "QComboBox:hover {background-color: lightGreen;"
                                          "color: black;}"
                              "QComboBox QAbstractItemView {"
                                          "selection-background-color: lightGreen;}");
    }
}

void StripInbound::actualflightLevel_changed(const QString &fromCallSign, const QString flightLevel)
{
    if(fromCallSign == callSign)
    {
        ui->flightLevel_actual_label->setText(flightLevel);
    }
}

void StripInbound::changeInStrip()
{
    QStringList stripdataList = readStrip(stripDataFrom, callSign);
    stripdataList.replace(2, ui->time1_lineEdit->text());
    stripdataList.replace(3, ui->flightLevel1_lineEdit->text());
    stripdataList.replace(5, ui->time2_lineEdit->text());
    stripdataList.replace(6, ui->flightLevel2_lineEdit->text());
    stripdataList.replace(15, ui->rwy_lineEdit->text());
    stripdataList.replace(16, ui->comment1_lineEdit->text());
    stripdataList.replace(17, ui->comment2_lineEdit->text());
    stripdataList.replace(18, ui->comment3_lineEdit->text());

    QString stripLine = createLine(stripdataList, callSign);

    overwriteStrip(stripDataFrom, stripLine, callSign);
}

void StripInbound::receiveFlightPlan(const QString &callsign, const QString &flightplan)
{
    FPcallsign = callsign;
    FlightPlan = flightplan;

    if(FPcounter == 0)
    {
        ui->point1_comboBox->clear();
        QStringList pointList = readInfoFromFile("MESSAGESinfo.txt", "POINT");
        if(callSign == FPcallsign)
        {
            pointList = FlightPlan.split("+");
        }
        ui->point1_comboBox->insertItems(0,pointList);
        ui->point1_comboBox->setCurrentIndex(0);

        FPcounter = 1;
    }
}

void StripInbound::closeEvent(QCloseEvent *event)
{
    emit STRIP_closed(callSign);
    event->accept();
}
