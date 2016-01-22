#include "metar.h"
#include "ui_metar.h"

Metar::Metar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Metar)
{
    ui->setupUi(this);
    METAR = "";
    QNH = "";
    WIND = "";
    ui->QNHLabel->setAlignment(Qt::AlignCenter);
    ui->WindLabel->setAlignment(Qt::AlignCenter);
    ui->TIMELabel->setAlignment(Qt::AlignCenter);

    setStyleSheet("QWidget {background-color: black;}"
                  "QLabel {font: bold 20px 'Courier';"
                  "color: lime;}");

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout_slot()));
    timer->start(5000);
}

Metar::~Metar()
{
    delete ui;
}

QString Metar::visibilityParse(QString visibility)
{
    QRegExp rx("^[0-9][0-9][0-9][0-9](N|NW|W|SW|S|SE|E|NE)?");
    int pos = rx.indexIn(visibility);
    QString text;

    QString vis = visibility.mid(0,4);
    int visInt = vis.toInt();

    if(pos != -1)
    {
        text = "Minimal surface visibility: " + visibility.mid(0,4) + " m";
        if(visibility.size() > 4)
        {
            text = text + visibility.right(5);
        }

        if(visInt == 9999)
        {
            text = "Minimal surface visibility: more than 10 km";
        }
    }

    return text;
}

QString Metar::verticalVisibilityParse(QString vertVis)
{
    QRegExp rx("^[V]{2,2}(\\d){3,3}");
    int pos = rx.indexIn(vertVis);
    QString text;

    if(pos != -1)
    {
        QString zero1 = vertVis.at(2);
        QString zero2 = vertVis.at(2);

        int visib = vertVis.mid(2,3).toInt();

        if(zero1 == "0")
        {
            visib = vertVis.mid(3,2).toInt();
            if(zero2 == "0")
                visib = vertVis.mid(4,1).toInt();
        }

        text = "Vertical visibility: " + QString::number(visib) + "00 ft";
    }

    return text;
}

QString Metar::RWYVsibilityParse(QString RWYvisibility)
{
    QRegExp rx("^[R](\\d){2,2}(\/)(\\d){2,2}(\//)(\\d){2,2}");
    int pos = rx.indexIn(RWYvisibility);
    QString text;
    int rwyNum = RWYvisibility.mid(1,2).toInt();

    if(pos != -1)
    {
        if(rwyNum == 88)
            text = "All RWY";
        if(rwyNum == 99)
            text = "Repetition of previous";
        if(rwyNum < 88 & rwyNum > 36)
            text = "RWY " + QString::number(rwyNum-50) + "R";
        if(rwyNum < 88 & rwyNum <=36)
            text = "RWY " + QString::number(rwyNum);
    }

    return text;
}

QString Metar::cloudsParse(QString clouds)
{
    QRegExp rx("^[A-Z][A-Z][A-Z]([0-9][0-9][0-9])?(CB|TCU)?");
    int pos = rx.indexIn(clouds);
    QString text;
    QString height;

    if(pos != -1)
    {
        if(clouds.contains("FEW"))
        {
            text = "Few clouds";
        }
        else if(clouds.contains("SCT"))
        {
            text = "Scattered clouds";
        }
        else if(clouds.contains("BKN"))
        {
            text = "Broken clouds";
        }
        else if(clouds.contains("OVC"))
        {
            text = "Overcast clouds";
        }
        else if(clouds.contains("SKC"))
        {
            text = "Sky clear";
        }
        else if(clouds.contains("NSC"))
        {
            text = "No significant clouds";
        }
        else if(clouds.contains("CLR"))
        {
            text = "No lcouds below 3600 m";
        }


        if(clouds.size() == 6)
        {
            height = clouds.mid(3,3);
            QString zero1 = height.at(0);
            QString zero2 = height.at(1);
            if(zero1 == "0")
            {
                height = clouds.mid(4,2);
                if(zero2 == "0")
                    height = clouds.at(5);
            }

            text = text + " at " + height + "00 ft above aerodrome level";

            if(clouds.contains("CB"))
                text = text + ", Cumulus Nimbus";
            if(clouds.contains("TCU"))
                text = text + ", Towering Cumulus";
        }
    }

    return text;
}

QString Metar::temperatureParse(QString temperature)
{
    QRegExp rx("^[M]?(\\d){2,2}(\/)[M]?(\\d){2,2}");
    int pos = rx.indexIn(temperature);
    QString text;
    QString temp;
    QString dew;
    QStringList list = temperature.split("\/");

    if(pos != -1)
    {
        if(list.at(0).contains("M"))
        {
            QString zero = list.at(0).at(1);
            if(zero == "0")
                temp = "-" + list.at(0).mid(2,1);
            else
                temp = "-" + list.at(0).mid(1,2);
        }
        else
        {
            QString zero = list.at(0).at(0);
            if(zero == "0")
                temp = list.at(0).mid(1,1);
            else
                temp = list.at(0).mid(0,2);
        }

        if(list.at(1).contains("M"))
        {
            QString zero = list.at(1).at(1);
            if(zero == "0")
                dew = "-" + list.at(1).mid(2,1);
            else
                dew = "-" + list.at(1).mid(1,2);
        }
        else
        {
            QString zero = list.at(1).at(0);
            if(zero == "0")
                dew = list.at(1).at(1);
            else
                dew = list.at(1).mid(0,2);
        }

        text = "Temperature: " + temp + "°C  dew point: " + dew + "°C";
    }

    return text;
}

QString Metar::pressureParse(QString pressure)
{
    QRegExp rx("^(Q|A)?(\\d){4,4}");
    int pos = rx.indexIn(pressure);
    QString text;
    QString press;
    QString unit;

    if(pos != -1)
    {
        unit = pressure.at(0);
        if(unit == "Q")
        {
            QString zero = pressure.at(1);
            if(zero == "0")
                press = pressure.mid(2,3);
            else
                press = pressure.mid(1,4);

            text = "QNH " + press + " hPa";
        }
        else if(unit == "A")
        {
            text = "QNH" + pressure.mid(1,2) + "," + pressure.mid(3,2) + " inch";
        }
        QNH = pressure;
        //qDebug() << "TLAK = " << QNH;
    }

    return text;
}

QString Metar::weatherParse(QString weather)
{
    QRegExp rx("^(\-+)?[A-Z]{2,}$");
    int pos = rx.indexIn(weather);
    QString text;

    if(pos != -1)
    {
        if(weather.contains("VC"))
            text = "In vicinity";
        else if(weather.contains("-"))
            text = "Light";
        else if(weather.contains("+"))
            text = "Heavy";

        if(weather.contains("MI"))
            text = text + " Shallow";
        else if(weather.contains("PR"))
            text = text + " Partial";
        else if(weather.contains("BC"))
            text = text + " Patches";
        else if(weather.contains("DR"))
            text = text + " Low drifting";
        else if(weather.contains("BL"))
            text = text + " Blowing";
        else if(weather.contains("SH"))
            text = text + " Showers";
        else if(weather.contains("TS"))
            text = text + " Thunderstorm";
        else if(weather.contains("FZ"))
            text = text + " Freezing";

        if(weather.contains("DZ"))
            text = text + " Drizzle";
        else if(weather.contains("RA"))
            text = text + " Rain";
        else if(weather.contains("SN"))
            text = text + " Snow";
        else if(weather.contains("SG"))
            text = text + " Snow grains";
        else if(weather.contains("IC"))
            text = text + " Ice crystals";
        else if(weather.contains("PL"))
            text = text + " Ice pellets";
        else if(weather.contains("GR"))
            text = text + " Hail";
        else if(weather.contains("GS"))
            text = text + " Small hail";
        else if(weather.contains("UP"))
            text = text + " Unknown";

        if(weather.contains("BR"))
            text = text + " Mist";
        else if(weather.contains("FG"))
            text = text + " Fog";
        else if(weather.contains("FU"))
            text = text + " Smoke";
        else if(weather.contains("VA"))
            text = text + " Volcanic ash";
        else if(weather.contains("DU"))
            text = text + " Widespread dust haze";
        else if(weather.contains("SA"))
            text = text + " Sand";
        else if(weather.contains("HZ"))
            text = text + " Haze";
        else if(weather.contains("PY"))
            text = text + " Spray";

        if(weather.contains("PO"))
            text = text + " Well developed dust/sand whirls";
        else if(weather.contains("SQ"))
            text = text + " Squalls";
        else if(weather.contains("FC"))
            text = text + " Funnel clouds, inc torandoes/waterspouts";
        else if(weather.contains("SS"))
            text = text + " Sandstorm";
        else if(weather.contains("DS"))
            text = text + " Duststorm";


        if(weather.contains("NCD"))
            text = text + "No cloud detected";

        text = "Weather: " + text;
    }

    return text;
}

QString Metar::getMetar(QString airportICAO)
{
    ICAOCallSign_METAR = airportICAO;
    QNetworkAccessManager *netManager = new QNetworkAccessManager();
    QString ICAOCode = airportICAO;
    QString URL = QString("http://aviationweather.gov/adds/metars/?station_ids=") + ICAOCode + QString("&std_trans=standard&chk_metars=on&hoursStr=most+recent+only&submitmet=Submit");

    QUrl url(URL);

    QNetworkRequest req(url);
    QNetworkReply *reply = netManager->get(req);
    QEventLoop loop;

    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));

    loop.exec();
    QString sourceCode = reply->readAll();
    // qDebug() << sourceCode;

    // write metar html source code to .txt file
    QFile file("metarhtml.txt");
    if( !file.open( QIODevice::ReadWrite | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for writing.";
    }
    QTextStream stream(&file);
    stream << sourceCode;
    file.close();

    // read from html code to parse the METAR from source code
    if( !file.open( QIODevice::ReadWrite | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for writing.";
    }

    QString line;
    QString metar;
    while( !stream.atEnd())
    {
        line = stream.readLine();
        int indstart = line.indexOf(ICAOCode);
        if(indstart != -1)
        {
            int indstop = line.indexOf("</");
            metar = line.mid(indstart,indstop-indstart);
        }
    }
    file.close();

    METAR = metar;
    QStringList metarList;
    metarList << metar.split(" ");

    QString metarLine;
    QStringListIterator iter(metarList);
    while(iter.hasNext())
    {
        metarLine = iter.next();
    }

    int K = 0;

    if(!metarList.isEmpty())
    {
        //parsing airport ICAO code
        QStringList airportListICAO;
        QString airportsICAO;

        QFile airportFile("airports.txt");
        if( !airportFile.open( QIODevice::ReadWrite | QIODevice::Text) )
        {
            qDebug() << "Could not open" << airportFile.fileName() << "for writing.";
        }
        QTextStream airportStream(&airportFile);

        while( !airportStream.atEnd())
        {
            airportsICAO = airportStream.readLine();

            if(airportsICAO.contains(metarList.at(K)))
            {
                airportListICAO << airportsICAO.split("=");
                //qDebug() << airportListICAO.at(1);           // letisko ktore najde zo suboru - zoznam letisk vsetkych
            }
        }
        airportFile.close();
        K++;


        if(metarList.size()>1)
        {
            //parsing Date and Time code
            QString dateTime = metarList.at(K);
            QString date = QString("Date: ") + dateTime.mid(0,2) + QString("\nTime: ") + dateTime.mid(2,2) + QString(":") + dateTime.mid(4,2) + " UTC";
            //qDebug() << date;       // datum
            K++;


            if(metarList.at(K).contains("AUTO"))
            {
                //qDebug() << "Report is fully automated, with no human intervention or oversight";
                K++;
            }

            // parsing wind
            QString wind = metarList.at(K);
            WIND = wind;
            //qDebug() << "WIND = " << WIND;
            QString Wind;
            if(wind.contains("G"))  //ak je narazovy vietor
            {
                QStringList windList;
                windList << wind.split("G");
                QString windS = windList.at(0).mid(0,3); //smer vetra
                QString windR = windList.at(0).mid(3,3); // rychlost vetra
                QString windSN = windList.at(1).mid(0,2); //rychlost narazoveho vetra
                QString unit = windList.at(1).mid(2,3); //jednotka rychlosti vetra

                Wind = QString("wind: ") + windS + QString("° ") + windR + QString(" ") + unit + QString(" gusty wind: ") + windSN + QString(" ") + unit;

                //qDebug() << Wind;
            }
            else if(wind.contains("00000")) //bezvetrie
            {
                Wind = "wind: No wind";
                //qDebug() << Wind;
            }
            else if(wind.contains("VRB"))   //premenlivy vietor
            {
                QString windR = wind.mid(3,2);
                QString unit = wind.mid(5,3);
                Wind = QString("wind: variable ") + windR + QString(" ") + unit;
                //qDebug() << Wind;
            }
            else
            {
                QString windS = wind.mid(0,3);
                int indofK = wind.indexOf("KT",0);
                int indofM = wind.indexOf("MPS",0);

                QString windR;
                QString unit;
                if(indofK != -1)
                {
                    windR = wind.mid(3,indofK-3);
                    unit = wind.mid(indofK,3);
                }
                else if(indofM != -1)
                {
                    windR = wind.mid(3,indofM-3);
                    unit = wind.mid(indofM,3);
                }

                Wind = QString("wind: ") + windS + QString("° ") + windR + QString(" ") + unit;
                //qDebug() << Wind;
            }


            K++;

            if(metarList.at(K).contains("V"))
            {
                if(metarList.at(K).contains("CAVOK"))
                {
                    //qDebug() << "Ceiling and visibility OK";
                }
                else
                {
                    QStringList windVList;
                    windVList << metarList.at(K).split("V");

                    //qDebug() << QString("wind variiable between: ") + windVList.at(0) + QString("° and ") + windVList.at(1) + QString("°");
                }

                K++;
            }

            do
            {
                QString visibility = visibilityParse(metarList.at(K));
                if(!visibility.isEmpty())
                {
                    //qDebug() << visibility;
                }

                QString vertVisib = verticalVisibilityParse(metarList.at(K));
                if(!vertVisib.isEmpty())
                {
                    //qDebug() << vertVisib;
                }

                QString clouds = cloudsParse(metarList.at(K));
                if(!clouds.isEmpty())
                {
                    //qDebug() << clouds;
                }

                QString temperature = temperatureParse(metarList.at(K));
                if(!temperature.isEmpty())
                {
                    //qDebug() << temperature;
                }

                QString pressure = pressureParse(metarList.at(K));
                if(!pressure.isEmpty())
                {
                    //qDebug() << pressure;
                }

                QString RWYvisibility = RWYVsibilityParse(metarList.at(K));
                if(!RWYvisibility.isEmpty())
                {
                    qDebug() << RWYvisibility;
                }

                QString weather = weatherParse(metarList.at(K));
                if(!weather.isEmpty())
                {
                    //qDebug() << weather;
                }

                if(metarList.at(K).contains("NOSIG"))
                {
                    //qDebug() << "No Singificant Change";
                }

                if(metarList.at(K).contains("TEMPO"))
                {
                    //qDebug() << "Temporarily";
                }

                K++;

            } while(K < metarList.size());
        }
    }
    ui->QNHLabel->setText(QNH);
    emit(sendQNH(QNH));
    ui->WindLabel->setText(WIND);
    return metar;
}

QString Metar::getQNH()
{
    return QNH;
}

QString Metar::getWind()
{
    return WIND;
}

void Metar::timeout_slot()
{
    getMetar(ICAOCallSign_METAR);
    emit(metarSend(METAR));
}

void Metar::setTime(const QString &time)
{
    QStringList timeList = time.split(":");
    QString newTime = timeList.at(0)+timeList.at(1)+"Z";

    ui->TIMELabel->setText(newTime);
}
