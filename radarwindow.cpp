#include "radarwindow.h"
#include "ui_radarwindow.h"

const double LonScaleFactor = 250;
const double LatScaleFactor = 400;
const double PI = 3.14159265359;

RadarWindow::RadarWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RadarWindow)
{
    ui->setupUi(this);
    visibility = false;

    cflwidget = new CFLWidget();
    connect(cflwidget, SIGNAL(CFLselection_clicked(QString,QString,QString)), this, SLOT(CFLselection_slot(QString,QString,QString)));

    directwidget = new DirectWidget();
    connect(this, SIGNAL(directWP_clicked(QString,QString)), directwidget, SLOT(directWPclicked_slot(QString,QString)));
    connect(directwidget, SIGNAL(sendDirectWP(QString,QString)), this, SLOT(getDirectWP(QString,QString)));

    ui->spinBox->setRange(0,3273);
    ui->spinBox_2->setRange(1,3274);
    ui->spinBox->setValue(100);
    ui->spinBox_2->setValue(200);

    ui->flightHistorySpinBox->setRange(3,10);
    ui->flightHistorySpinBox->setValue(5);

    ui->flightPredictionSpinBox->setRange(0,6);
    ui->flightPredictionSpinBox->setValue(0);

    FlightHistory_num = ui->flightHistorySpinBox->value();

    scene = new QGraphicsScene(this);
    ui->MapView->setScene(scene);

    QBrush blackBrush(Qt::black);
    ui->MapView->setBackgroundBrush(blackBrush);

    drawMap("slovakia_map.txt");
    drawMapSection("slovakia_map.txt");

    ui->navPointsCheckBox->setChecked(true);
    ui->RWYCheckBox->setChecked(true);
    ui->TMACheckBox->setChecked(false);
    ui->CTRCheckBox->setChecked(false);

    update_drawing();

    ui->MapView->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->MapView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->MapView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    update_timer = new QTimer(this);
    connect(update_timer, SIGNAL(timeout()), this, SLOT(update_drawing()));
    update_timer->start(1000);

    connect(ui->navPointsCheckBox, SIGNAL(stateChanged(int)), this, SLOT(update_drawing()));
    connect(ui->RWYCheckBox, SIGNAL(stateChanged(int)), this, SLOT(update_drawing()));
    connect(ui->TMACheckBox, SIGNAL(stateChanged(int)), this, SLOT(update_drawing()));
    connect(ui->CTRCheckBox, SIGNAL(stateChanged(int)), this, SLOT(update_drawing()));
    connect(ui->flightHistorySpinBox, SIGNAL(valueChanged(int)), this, SLOT(update_flightHistoryNum(int)));
    connect(ui->flightPredictionSpinBox, SIGNAL(valueChanged(int)), this, SLOT(update_drawing()));

    connect(ui->MapView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(update_drawing()));  // for determining changes in zooming
    connect(ui->MapView, SIGNAL(mousePos(QPointF)), this, SLOT(getMousePos(QPointF)));
    connect(ui->MapView, SIGNAL(LeftMousePos(QPointF)), this, SLOT(getLeftMousePos(QPointF)));

    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(changeselection()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(changeselection()));
}

RadarWindow::~RadarWindow()
{
    delete ui;
}

QVector<double> RadarWindow::loadLatFromMap(const QString &filename)
{
    QFile file(filename);
    if( !file.open( QIODevice::ReadOnly ) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }

    QVector<double> vector;
    QString line;
    QStringList lineList;
    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        line = stream.readLine();
        lineList = line.split("\t");
        vector.append(lineList.at(1).toDouble());
    }
    file.close();

    return vector;
}

QVector<double> RadarWindow::loadLonFromMap(const QString &filename)
{
    QFile file(filename);
    if( !file.open( QIODevice::ReadOnly ) )
    {
        qDebug()<< "Could not open" << file.fileName() << "for reading.";
    }

    QVector<double> vector;
    QString line;
    QStringList lineList;
    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        line = stream.readLine();
        lineList = line.split("\t");
        vector.append(lineList.at(0).toDouble());
    }
    file.close();

    return vector;
}

QStringList RadarWindow::loadNavPoints(const QString &filename)
{
    QFile file(filename);
    if( !file.open( QIODevice::ReadOnly ) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }

    QStringList navPointList;

    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        navPointList.append(stream.readLine());
    }

    return navPointList;
}

void RadarWindow::drawMap(const QString &filename)
{
    QPen whitePen(Qt::white);
    whitePen.setWidth(1);
    whitePen.setCosmetic(true);

    QVector<double> lonVector = loadLonFromMap(filename);
    QVector<double> latVector = loadLatFromMap(filename);

    int n = lonVector.size();

    polygon.clear();
    for(int i=0; i<n; i++)
    {
        polygon << QPointF(lonVector[i]*LonScaleFactor, latVector[i]*-LatScaleFactor);
    }

    polygonItem = scene->addPolygon(polygon,whitePen);
}

void RadarWindow::drawMapSection(const QString &filename)
{
    QPen redPen(Qt::red);
    redPen.setWidth(1);
    redPen.setCosmetic(true);

    QVector<double> lonVector = loadLonFromMap(filename);
    QVector<double> latVector = loadLatFromMap(filename);

    int n = lonVector.size();
    polygon.clear();
    for(int i=FROM; i<TO; i++)
    {
        polygon << QPointF(lonVector[i]*LonScaleFactor, latVector[i]*-LatScaleFactor);
    }

    polygonItem = scene->addPolygon(polygon,redPen);
}

void RadarWindow::drawNavPoints(const QStringList &navPointList, const double &scale)
{
    double Scale = scale* 1.5;

    QPen whitePen(Qt::white);
    whitePen.setWidth(1);
    whitePen.setCosmetic(true);

    QPen bluePen(Qt::blue);
    bluePen.setWidth(1);
    bluePen.setCosmetic(true);

    QListIterator<QString> iter(navPointList);
    while(iter.hasNext())
    {
        polygon.clear();
        QString line = iter.next();

        if(line != "")
        {
            QStringList lineList;
            lineList.append(line.split("\t"));

            double pointLON0 = lineList.at(1).toDouble();
            double pointLAT0 = lineList.at(2).toDouble();

            QString station; // VOR/DME/NDB identificator
            if(lineList.length() == 4)
            {
                station = lineList.at(3);
            }
            else
            {
                station = "NDB";
            }


            double pointLON1 = pointLON0 + 0.03/Scale;    //right bottom of triangle
            double pointLAT1 = pointLAT0 - 0.01/Scale;

            double pointLON2 = pointLON0 + 0;       // top of triangle
            double pointLAT2 = pointLAT0 + 0.02/Scale;

            double pointLON3 = pointLON0 - 0.03/Scale;    // left bottom of triangle
            double pointLAT3 = pointLAT0 - 0.01/Scale;

            polygon << QPointF(pointLON1*LonScaleFactor, pointLAT1*-LatScaleFactor);
            polygon << QPointF(pointLON2*LonScaleFactor, pointLAT2*-LatScaleFactor);
            polygon << QPointF(pointLON3*LonScaleFactor, pointLAT3*-LatScaleFactor);

            int fontScale = qRound(16 / Scale);
            if(fontScale < 1)
            {
                fontScale = 1;
            }

            pointText = scene->addText(lineList.at(0), QFont("Times New Roman", fontScale));
            pointText->setPos(pointLON0*LonScaleFactor, pointLAT0*-LatScaleFactor);

            if(station == "VOR/DME")
            {
                polygonItem = scene->addPolygon(polygon, bluePen);
                pointText->setDefaultTextColor(Qt::blue);
            }
            else if(station == "NDB")
            {
                polygonItem = scene->addPolygon(polygon, whitePen);
                pointText->setDefaultTextColor(Qt::white);
            }

            //pointText->setFlag(QGraphicsItem::ItemIsMovable);
        }
    }
}

void RadarWindow::drawRWY(const QString &filename)
{
    QFile file(filename);
    if( !file.open( QIODevice::ReadOnly ) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }

    QStringList RWYPointList;

    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        RWYPointList.append(stream.readLine());
    }

    QPen whitePen(Qt::white);
    whitePen.setWidth(1);
    whitePen.setCosmetic(true);

    double scale = ui->MapView->transform().m11();
    int fontScale = qRound(12 / scale);
    if(fontScale < 1)
    {
        fontScale = 1;
    }

    double LON1, LAT1, LON2, LAT2;

    QListIterator<QString> iter(RWYPointList);
    while(iter.hasNext())
    {
        QString pointsLine = iter.next();
        QStringList rwyPoints = pointsLine.split("\t");

        LON1 = rwyPoints.at(1).toDouble() * LonScaleFactor;
        LAT1 = rwyPoints.at(2).toDouble() * -LatScaleFactor;
        LON2 = rwyPoints.at(3).toDouble() * LonScaleFactor;
        LAT2 = rwyPoints.at(4).toDouble() * -LatScaleFactor;


        QString rwystring = rwyPoints.at(5).split("RWY").at(1);



        line = scene->addLine(LON1, LAT1, LON2, LAT2, whitePen);
        pointText = scene->addText(rwyPoints.at(0) + " " + rwystring, QFont("Times New Roman", fontScale));
        pointText->setPos(LON1, LAT1);
        pointText->setDefaultTextColor(Qt::white);
    }
}

void RadarWindow::drawCTR(const QString &filename)
{
    QPen bluePen(Qt::cyan);
    bluePen.setWidth(1);
    bluePen.setCosmetic(true);
    bluePen.setStyle(Qt::DashLine);

    QFile file(filename);
    if( !file.open( QIODevice::ReadOnly ) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }

    QStringList CTRList;

    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        CTRList.append(stream.readLine());
    }

    QListIterator<QString> iter(CTRList);   // iterate over every line = separate TMA coordinates
    while(iter.hasNext())
    {
        QString line = iter.next();
        QStringList lineList = line.split(" ");
        QString name = lineList.at(0);
        lineList.removeAt(0); // remove name from list

        int n = lineList.size();
        double CTR_LON[n];
        double CTR_LAT[n];
        int i = 0;

        QListIterator<QString> coordIter(lineList);
        while(coordIter.hasNext())
        {
            QString coordPair = coordIter.next();
            QStringList coordPairList = coordPair.split(";");
            CTR_LON[i] = coordPairList.at(0).toDouble();
            CTR_LAT[i] = coordPairList.at(1).toDouble();
            i++;
        }

        // draw each separate TMA region
        polygon.clear();
        for(int k=0; k<n; k++)
        {
            polygon << QPointF(CTR_LON[k]*LonScaleFactor, CTR_LAT[k]*-LatScaleFactor);
        }
        polygonItem = scene->addPolygon(polygon,bluePen);
    }

    // CTR 1 BRATISLAVA ARC
    qreal lon = 17.038088;//17.038088; // ARP = 17.212778;
    qreal lat = 48.279756;//48.286456; // ARP = 48.17;

    qreal w = 87.7;
    qreal h = 87.7;
    qreal angle = 24.78;
    path = new QPainterPath();
    path->arcMoveTo(lon*LonScaleFactor,lat *-LatScaleFactor,w,h,angle);
    path->arcTo(lon*LonScaleFactor,lat *-LatScaleFactor,w,h,angle,-47.16);
    scene->addPath(*path,bluePen);

    // CTR 1 PIESTANY ARC
    lon = 17.704059;//17.038088; // ARP = 17.828611;
    lat = 48.707367;//48.286456; // ARP = 48.625;

    w = 75.7;
    h = 75.7;
    angle = 24.78;
    path = new QPainterPath();
    path->arcMoveTo(lon*LonScaleFactor,lat *-LatScaleFactor,w,h,angle);
    path->arcTo(lon*LonScaleFactor,lat *-LatScaleFactor,w,w,angle,-360.16);
    scene->addPath(*path,bluePen);

}

void RadarWindow::drawTMA(const QString &filename)
{
    QPen bluePen(Qt::blue);
    bluePen.setWidth(1);
    bluePen.setCosmetic(true);

    QBrush brush(Qt::blue);

    QFile file(filename);
    if( !file.open( QIODevice::ReadOnly ) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }

    QStringList TMAList;

    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        TMAList.append(stream.readLine());
    }

    QListIterator<QString> iter(TMAList);   // iterate over every line = separate TMA coordinates
    while(iter.hasNext())
    {
        QString line = iter.next();
        QStringList lineList = line.split(" ");
        QString name = lineList.at(0);
        lineList.removeAt(0); // remove name from list

        int n = lineList.size();
        double TMA_LON[n];
        double TMA_LAT[n];
        int i = 0;

        QListIterator<QString> coordIter(lineList);
        while(coordIter.hasNext())
        {
            QString coordPair = coordIter.next();
            QStringList coordPairList = coordPair.split(";");
            TMA_LON[i] = coordPairList.at(0).toDouble();
            TMA_LAT[i] = coordPairList.at(1).toDouble();
            i++;
        }

        // draw each separate TMA region
        polygon.clear();
        for(int k=0; k<n; k++)
        {
            polygon << QPointF(TMA_LON[k]*LonScaleFactor, TMA_LAT[k]*-LatScaleFactor);
        }
        polygonItem = scene->addPolygon(polygon,bluePen);
    }


    // TMA 1 BRATISLAVA ARC
    qreal lon = 17.038088;//17.038088; // ARP = 17.212778;
    qreal lat = 48.279756;//48.286456; // ARP = 48.17;

    qreal w = 87.7;
    qreal h = 87.7;
    qreal angle = 24.78;
    path = new QPainterPath();
    path->arcMoveTo(lon*LonScaleFactor,lat *-LatScaleFactor,w,h,angle);
    path->arcTo(lon*LonScaleFactor,lat *-LatScaleFactor,w,h,angle,-47.16);
    scene->addPath(*path,bluePen);
}

void RadarWindow::drawAircraft(const QHash<QString, QStringList> &flightsimhash, const double &scale)
{
    QPen greenPen(Qt::green);
    greenPen.setWidth(1);
    greenPen.setCosmetic(true);

    if(visibility == true)
    {
        visibility = false;
    }
    else
    {
        visibility = true;
    }

    if(!flightsimhash.isEmpty())    // there are data to be drawn
    {
        QHashIterator<QString, QStringList> iter(flightsimhash);
        while(iter.hasNext())
        {
            iter.next();
            QString CallSign = iter.key();                   // actual callsign
            QStringList messageList = iter.value();          // list of data for that callsign


            if(messageList.size() < ui->flightHistorySpinBox->value())  // ak chcem zobrazit rovnaky pocet bodov ako mam nacitane uz, alebo menej
            {
                int i = 0;
                int max_data_length = messageList.size();

                QListIterator<QString> listIter(messageList);
                while(listIter.hasNext())
                {
                    i++;
                    QString message = listIter.next();   // each separate message of list for that callsign

                    QStringList dataList = message.split("\t");

                    double GPS_LAT, GPS_LON, TRANSPONDER_CODE;
                    TRANSPONDER_CODE = 0;
                    QListIterator<QString> iter(dataList);
                    while(iter.hasNext())
                    {
                        QString param = iter.next();

                        if(param.contains("GPS_LAT"))
                        {
                            QStringList paramList = param.split("=");
                            GPS_LAT = paramList.at(1).toDouble();
                        }

                        if(param.contains("GPS_LON"))
                        {
                            QStringList paramList = param.split("=");
                            GPS_LON = paramList.at(1).toDouble();
                        }

                        if(param.contains("TRANSP"))
                        {
                            QStringList paramList = param.split("=");
                            double TRANSP_CODE = paramList.at(1).toDouble();
                            TRANSPONDER_CODE = BCOtoDEC(TRANSP_CODE);
                        }
                    }

                    int size_big = 10;
                    int size_small = size_big / 2;

                    if((i < max_data_length) && (i >= 0))  // other small rectangles - history of flight
                    {
                        rectangle = scene->addRect(GPS_LON*LonScaleFactor-(size_small/scale)/(2), GPS_LAT*-LatScaleFactor-(size_small/scale)/(2), size_small/scale, size_small/scale,greenPen);
                    }
                    else if(i == max_data_length)    // big rectangle - actual position
                    {
                        rectangle = scene->addRect(GPS_LON*LonScaleFactor-(size_big/scale)/(2), GPS_LAT*-LatScaleFactor-(size_big/scale)/(2), size_big/scale, size_big/scale,greenPen);

                        if((TRANSPONDER_CODE == 7700) || (TRANSPONDER_CODE == 7600) || (TRANSPONDER_CODE == 7500))
                        {                          
                            if(visibility == true)
                            {
                                rectangle->setPen(QPen(Qt::red));
                            }
                            else
                            {
                                bool selected = false;
                                QListIterator<QString> aircraftiter(SelectedAircraftList);  // aby bolo lietadlo stale oznacene kym nekliknem niekde inde
                                while(aircraftiter.hasNext())
                                {
                                    QString selectedAircraft = aircraftiter.next();
                                    if(selectedAircraft == CallSign)
                                    {
                                        selected = true;
                                    }

                                    if(selected)
                                    {
                                        rectangle->setPen(QPen(QColor(255,102,0)));
                                    }
                                    else
                                    {
                                        rectangle->setPen(QPen(Qt::green));
                                    }
                                }
                            }
                        }
                        else
                        {
                            bool selected = false;
                            QListIterator<QString> aircraftiter(SelectedAircraftList);  // aby bolo lietadlo stale oznacene kym nekliknem niekde inde
                            while(aircraftiter.hasNext())
                            {
                                QString selectedAircraft = aircraftiter.next();
                                if(selectedAircraft == CallSign)
                                {
                                    selected = true;
                                }

                                if(selected)
                                {
                                    rectangle->setPen(QPen(QColor(255,102,0)));
                                }
                                else
                                {
                                    rectangle->setPen(QPen(Qt::green));
                                }
                            }

                            rectangle->setVisible(true);
                        }
                    }
                }
            }

            else if(messageList.size() >= ui->flightHistorySpinBox->value()) // ak chcem zobrazit viac bodov do historie ako mam aktualne nacitane a zvolene
            {
                for(int k=0; k<ui->flightHistorySpinBox->value(); k++)
                {
                    QStringList dataList = messageList.at(messageList.size() - k-1).split("\t");  // idem od konca

                    double GPS_LAT, GPS_LON, TRANSPONDER_CODE;
                    TRANSPONDER_CODE = 0;
                    QListIterator<QString> iter(dataList);
                    while(iter.hasNext())
                    {
                        QString param = iter.next();

                        if(param.contains("GPS_LAT"))
                        {
                            QStringList paramList = param.split("=");
                            GPS_LAT = paramList.at(1).toDouble();
                        }

                        if(param.contains("GPS_LON"))
                        {
                            QStringList paramList = param.split("=");
                            GPS_LON = paramList.at(1).toDouble();
                        }

                        if(param.contains("TRANSP"))
                        {
                            QStringList paramList = param.split("=");
                            double TRANSP_CODE = paramList.at(1).toDouble();
                            TRANSPONDER_CODE = BCOtoDEC(TRANSP_CODE);
                        }
                    }

                    int size_big = 10;
                    int size_small = size_big / 2;

                    if(k == 0)  // big rectangle - actual position
                    {
                        rectangle = scene->addRect(GPS_LON*LonScaleFactor-(size_big/scale)/(2), GPS_LAT*-LatScaleFactor-(size_big/scale)/(2), size_big/scale, size_big/scale,greenPen);

                        if((TRANSPONDER_CODE == 7700) || (TRANSPONDER_CODE == 7600) || (TRANSPONDER_CODE == 7500))
                        {
                            if(visibility == true)
                            {
                                rectangle->setPen(QPen(Qt::red));
                            }
                            else
                            {
                                bool selected = false;
                                QListIterator<QString> aircraftiter(SelectedAircraftList);  // aby bolo lietadlo stale oznacene kym nekliknem niekde inde
                                while(aircraftiter.hasNext())
                                {
                                    QString selectedAircraft = aircraftiter.next();
                                    if(selectedAircraft == CallSign)
                                    {
                                        selected = true;
                                    }

                                    if(selected)
                                    {
                                        rectangle->setPen(QPen(QColor(255,102,0)));
                                    }
                                    else
                                    {
                                        rectangle->setPen(QPen(Qt::green));
                                    }
                                }
                            }
                        }
                        else
                        {
                            bool selected = false;
                            QListIterator<QString> aircraftiter(SelectedAircraftList);  // aby bolo lietadlo stale oznacene kym nekliknem niekde inde
                            while(aircraftiter.hasNext())
                            {
                                QString selectedAircraft = aircraftiter.next();
                                if(selectedAircraft == CallSign)
                                {
                                    selected = true;
                                }

                                if(selected)
                                {
                                    rectangle->setPen(QPen(QColor(255,102,0)));
                                }
                                else
                                {
                                    rectangle->setPen(QPen(Qt::green));
                                }
                            }

                            rectangle->setVisible(true);
                        }
                    }
                    else    // other small rectangles - history of flight
                    {
                        rectangle = scene->addRect(GPS_LON*LonScaleFactor-(size_small/scale)/(2), GPS_LAT*-LatScaleFactor-(size_small/scale)/(2), size_small/scale, size_small/scale,greenPen);
                    }
                }
            }

            // aircraft label + prediction calculation
            QString message = messageList.at(messageList.size()-1);  // each separate message of list for that callsign
            QStringList dataList = message.split("\t");

            //g() << dataList;

            double GPS_LAT, GPS_LON, GPS_ALT, HDG,HDG_accurate, GS, GS_accurate, TAS, TAS_accurate, TRANSPONDER_CODE, WP_ETE;
            TRANSPONDER_CODE = 0;
            QString GPS_ALT_STRING, HDG_STRING, GS_string, WP_ID, FlightPlan;

            QListIterator<QString> iter(dataList);
            while(iter.hasNext())
            {
                QString param = iter.next();

                if(param.contains("GPS_ALT"))
                {
                    QStringList paramList = param.split("=");
                    GPS_ALT = qFloor(paramList.at(1).toDouble() / 100.0);

                    if(QString::number(GPS_ALT).length() == 2)
                    {
                        GPS_ALT_STRING = "0" + QString::number(GPS_ALT);
                    }
                    else if(QString::number(GPS_ALT).length() == 1)
                    {
                        GPS_ALT_STRING = "00" + QString::number(GPS_ALT);
                    }
                    else
                    {
                        GPS_ALT_STRING = QString::number(GPS_ALT);
                    }
                }

                if(param.contains("GS"))
                {
                    QStringList paramList = param.split("=");
                    GS_accurate = paramList.at(1).toDouble();
                    GS = qFloor(GS_accurate);
                    double GS_knots = qFloor(GS_accurate*1.94384449);

                    if(QString::number(GS_knots).length() == 2)
                    {
                        GS_string = "0" + QString::number(GS_knots);
                    }
                    else if(QString::number(GS_knots).length() == 1)
                    {
                        GS_string = "00" + QString::number(GS_knots);
                    }
                    else
                    {
                        GS_string = QString::number(GS_knots);
                    }
                }

                if(param.contains("TAS"))
                {
                    QStringList paramList = param.split("=");
                    TAS_accurate = paramList.at(1).toDouble();
                    TAS = qFloor(TAS_accurate);
                }

                if(param.contains("GPS_LAT"))
                {
                    QStringList paramList = param.split("=");
                    GPS_LAT = paramList.at(1).toDouble();
                }

                if(param.contains("GPS_LON"))
                {
                    QStringList paramList = param.split("=");
                    GPS_LON = paramList.at(1).toDouble();
                }

                if(param.contains("HDG"))
                {
                    QStringList paramList = param.split("=");
                    HDG_accurate = paramList.at(1).toDouble();
                    HDG = qFloor(HDG_accurate);

                    if(QString::number(HDG).length() == 2)
                    {
                        HDG_STRING = "0" + QString::number(HDG);
                    }
                    else if(QString::number(HDG).length() == 1)
                    {
                        HDG_STRING = "00" + QString::number(HDG);
                    }
                    else
                    {
                        HDG_STRING = QString::number(HDG);
                    }
                }

                if(param.contains("TRANSP"))
                {
                    QStringList paramList = param.split("=");
                    double TRANSP_CODE = paramList.at(1).toDouble();
                    TRANSPONDER_CODE = BCOtoDEC(TRANSP_CODE);
                }

                if(param.contains("WP_ETE"))
                {
                    QStringList paramList = param.split("=");
                    WP_ETE = paramList.at(1).toDouble();
                }

                if(param.contains("WP_ID"))
                {
                    QStringList paramList = param.split("=");
                    WP_ID = paramList.at(1);
                }

                if(param.contains("FlightPlan"))
                {
                    QStringList paramList = param.split("=");
                    FlightPlan = paramList.at(1);
                }
            }

            overwriteNxtPoint(StripDataFrom, CallSign, WP_ID);
            emit NextPointETE(StripDataFrom, CallSign, WP_ETE);

            int fontScale = qRound(12 / scale);
            if(fontScale < 1)
            {
                fontScale = 1;
            }

            QString CallSignText;

            QString WARNING = " ";
            bool Warning_bool = false;
            if(STCAhash.value(CallSign) == true)
            {
                CallSignText = "(STCA) " + CallSign;
                WARNING = "STCA";
                Warning_bool = true;
            }
            else
            {
                CallSignText = CallSign;
            }

            QString ALARM = " ";
            bool Alarm_bool = false;
            if(TRANSPONDER_CODE == 7700)  // EMERGENCY
            {
                ALARM = "EMG";
                Alarm_bool = true;
            }
            else if(TRANSPONDER_CODE == 7600)   // RADIO COMMUNICATION FAILURE
            {
                ALARM = "RCF";
                Alarm_bool = true;
            }
            else if(TRANSPONDER_CODE == 7500)   // HIJACK
            {
                ALARM = "HIJ";
                Alarm_bool = true;
            }


            // ROCD - Rate of Climb and Descent indicatior
            double rocd = ROCD(flightsimhash, CallSign);
            QString ROCDsign;
            if(rocd  == -1)
            {
                QByteArray text = QByteArray::fromHex("1F");
                ROCDsign = text.data();
            }
            else if(rocd == 0)
            {
                ROCDsign = "=";
            }
            else if(rocd == 1)
            {
                QByteArray text = QByteArray::fromHex("1E");
                ROCDsign = text.data();
            }

            QString transp;
            if(TRANSPONDER_CODE == 0) // transponder is not sending any information
            {
                transp = "INV";
            }
            else
            {
                transp = QString::number(TRANSPONDER_CODE);
            }

            QString CFL="", WTC="", AircraftType="", ExtFL="", ExtPoint="", NxtPoint="";
            if(StripDataFrom != "")
            {
                overwriteSQUAWK(StripDataFrom, CallSign, QString::number(TRANSPONDER_CODE));

                QStringList stripList = readSTRIP(StripDataFrom,CallSign);  // List of data read from STRIP.txt file for specific CallSign

                if(stripList.length() != 0)
                {
                    CFL = stripList.at(stripList.size()-3);
                    NxtPoint = stripList.at(1);

                    if(stripList.at(0) == "INBOUND")
                    {
                        WTC = stripList.at(11);
                        AircraftType = stripList.at(10);
                        ExtFL = stripList.at(6);
                        ExtPoint = stripList.at(4);
                    }
                    else if(stripList.at(0) == "OUTBOUND")
                    {
                        WTC = stripList.at(8);
                        AircraftType = stripList.at(7);
                        ExtPoint = stripList.at(13);
                    }
                    else if(stripList.at(0) == "OVERFLIGHT")
                    {
                        WTC = stripList.at(11);
                        AircraftType = stripList.at(10);
                        ExtPoint = stripList.at(14);
                    }
                }
            }

            QString SLabelText = CallSign + "\nFL" + GPS_ALT_STRING + ROCDsign + " " + GS_string + "\n" + CFL;
            QString ELabelText = CallSign + "\nFL" + GPS_ALT_STRING + ROCDsign + " " + GS_string  +  " " + WTC + " " + AircraftType + " " + transp + "\n" + CFL + " "
                    + ExtFL + " " + ExtPoint + " " + HDG_STRING + " " + NxtPoint;

            QString directWP;
            QStringList directList = directHash.keys();
            if(directList.contains(CallSign))
            {
                directWP = directHash.value(CallSign);
                if(directWP != NxtPoint)
                {
                    ELabelText = CallSign + "\nFL" + GPS_ALT_STRING + ROCDsign + " " + GS_string  +  " " + WTC + " " + AircraftType + " " + transp + "\n" + CFL + " "
                                        + ExtFL + " " + ExtPoint + " " + HDG_STRING + " " + NxtPoint + " " + directWP;
                }
                else
                {
                    directHash.remove(CallSign);
                }
            }

            QString first_line = "";
            if((Alarm_bool == true) || (Warning_bool == true))
            {
                if(Alarm_bool == true)
                    first_line = ALARM;
                if(Warning_bool == true)
                    first_line = WARNING;
                if(Alarm_bool == true && Warning_bool == true)
                    first_line = ALARM + " " + WARNING;

                SLabelText = first_line + "\n" + SLabelText;
                ELabelText = first_line + "\n" + ELabelText;
            }

            mytextitem = new MyTextItem();
            connect(mytextitem, SIGNAL(textclicked(const QString&)), this, SLOT(aircraftClicked(const QString&)));
            connect(mytextitem, SIGNAL(deselectaircraft(const QString&)), this, SLOT(deselectAircraft_slot(const QString&)));
            connect(mytextitem, SIGNAL(GSclicked()), this, SLOT(GSclicked_slot()));
            connect(mytextitem, SIGNAL(CFLclicked(QString,QString,QString)), this, SLOT(CFLclicked_slot(QString,QString,QString)));
            connect(mytextitem, SIGNAL(DirectWPclicked(QString,QString)), this, SLOT(DirectWPcliked_slot(QString,QString)));

            // emit signal s Letovym planom
            emit sendFlightPlan(CallSign, FlightPlan);
            directwidget->setFlightPlan(CallSign, FlightPlan);


            mytextitem->setPos(GPS_LON*LonScaleFactor, GPS_LAT*-LatScaleFactor);
            mytextitem->setCustomText(SLabelText, QFont("Arial", fontScale));
            mytextitem->setTextPen(QPen(QColor(Qt::green)));
            mytextitem->setFlag(QGraphicsItem::ItemIsSelectable);
            scene->addItem(mytextitem);

            //qDebug() << SelectedAircraftList;

            QListIterator<QString> aircraftiter(SelectedAircraftList);  // aby bolo lietadlo stale oznacene kym nekliknem niekde inde
            while(aircraftiter.hasNext())
            {
                QString selectedAircraft = aircraftiter.next();
                if(selectedAircraft == CallSign)
                {
                    mytextitem->setSelected(true);
                }
            }

            if((TRANSPONDER_CODE == 7700) || (TRANSPONDER_CODE == 7600) || (TRANSPONDER_CODE == 7500))
            {
                if(ui->flightPredictionSpinBox->value() < 1)    // forced gs_vector for EMG, RCF, HIJ ALARM
                {
                    ui->flightPredictionSpinBox->setValue(1);
                }

                if(visibility == false)
                {
                    if(mytextitem->isSelected())
                    {
                        mytextitem->setTextPen(QPen(QColor(255,102,0)));
                        mytextitem->setCustomText(ELabelText, QFont("Arial", fontScale));
                    }
                    else
                    {
                        mytextitem->setCustomText(SLabelText, QFont("Arial", fontScale));
                        mytextitem->setTextPen(QPen(Qt::green));
                    }
                }
                else
                {
                    if(mytextitem->isSelected())
                    {
                        mytextitem->setCustomText(ELabelText, QFont("Arial", fontScale));
                    }
                    else
                    {
                        mytextitem->setCustomText(SLabelText, QFont("Arial", fontScale));
                    }

                    mytextitem->emergency(true);
                }
            }
            else
            {
                if(mytextitem->isSelected())
                {
                    mytextitem->setTextPen(QPen(QColor(255,102,0)));
                    mytextitem->setCustomText(ELabelText, QFont("Arial", fontScale));
                }
                else
                {
                    mytextitem->setCustomText(SLabelText, QFont("Arial", fontScale));
                    mytextitem->emergency(false);
                }

                mytextitem->setVisible(true);
            }


            // flight prediction
            if(ui->flightPredictionSpinBox->value() != 0)
            {
                int seconds = ui->flightPredictionSpinBox->value() * 60;

                QVector<double> predVect = prediction_calculation(GPS_LON, GPS_LAT, HDG_accurate, seconds, GS_accurate);
                line = scene->addLine(GPS_LON*LonScaleFactor, GPS_LAT*-LatScaleFactor, predVect[0]*LonScaleFactor,predVect[1]*-LatScaleFactor, greenPen);

                QPen pen;
                pen.setWidth(1);
                pen.setCosmetic(true);
                //QVector<qreal> dashes;
                //qreal space = 5.0;
                //qreal konst = (line->line().length() - (pred_val-1)*space);
                //qreal lineL = (line->line().length() - (pred_val-1)*space) / (pred_val+1);

                //dashes << lineL*scale << space*scale;

                //pen.setDashPattern(dashes);
                //pen.setCapStyle(Qt::FlatCap);
                pen.setColor(Qt::green);

                //qDebug() << "LINE LENGTH: " << line->line().length() << scale << lineL << konst;

                if((TRANSPONDER_CODE == 7700) || (TRANSPONDER_CODE == 7600) || (TRANSPONDER_CODE == 7500))
                {                    
                    if(visibility == true)
                    {
                        pen.setColor(Qt::red);
                        line->setPen(pen);
                    }
                    else
                    {
                        if(mytextitem->isSelected())
                        {
                            pen.setColor(QColor(255,102,0));
                            line->setPen(pen);
                        }
                        else
                        {
                            pen.setColor(Qt::green);
                            line->setPen(pen);
                        }
                    }
                }
                else
                {
                    if(mytextitem->isSelected())
                    {
                        pen.setColor(QColor(255,102,0));
                        line->setPen(pen);
                    }
                    else
                    {
                        pen.setColor(Qt::green);
                        line->setPen(pen);
                    }

                    line->setVisible(true);
                }
            }
        }
    }
}

QVector<double> RadarWindow::prediction_calculation(const double &init_LON, const double &init_LAT, const double &init_HDG, const double &seconds, const double &GS)
{
    //double TAS_ms = 0.51444444444 * TAS;    // conversion from [knots] to [m/s]
    double s = GS * seconds;

    double a = 6378137, b = 6356752.314245, f = 1/298.257223563; //WGS84 parameters

    double lat1 = init_LAT * (PI/180);
    double lon1 = init_LON * (PI/180);
    double init_bearing = init_HDG * (PI/180);

    double sinAlpha1 = sin(init_bearing);
    double cosAlpha1 = cos(init_bearing);

    double tanU1 = (1-f) * tan(lat1);
    double cosU1 = 1 / (sqrt(1 + tanU1*tanU1));
    double sinU1 = tanU1 * cosU1;
    double sigma1 = atan2(tanU1,cosAlpha1);
    double sinAlpha = cosU1 * sinAlpha1;
    double cosSqAlpha = 1 - sinAlpha*sinAlpha;
    double uSq = cosSqAlpha * (a*a - b*b) / (b*b);
    double A = 1 + uSq/16384*(4096+uSq*(-768+uSq*(320-175*uSq)));
    double B = uSq/1024 * (256+uSq*(-128+uSq*(74-47*uSq)));

    double cos2SigmaM, sinSigma, cosSigma, deltaSigma;
    double sigma = s / (b*A), sigma_ap;

    double iteration = 0;

    do
    {
        cos2SigmaM = cos(2*sigma1 + sigma);
        sinSigma = sin(sigma);
        cosSigma = cos(sigma);
        deltaSigma = B*sinSigma*(cos2SigmaM+B/4*(cosSigma*(-1+2*cos2SigmaM*cos2SigmaM)-
                     B/6*cos2SigmaM*(-3+4*cosSigma*cosSigma)*(-3+4*cos2SigmaM*cos2SigmaM)));
        sigma_ap = sigma;
        sigma = s / (b*A) + deltaSigma;
    } while((qAbs(sigma - sigma_ap) > 1e-12) & (++iteration < 200));

    double x = sinU1*sinSigma - cosU1*cosSigma*cosAlpha1;
    double lat2 = atan2(sinU1*cosSigma + cosU1*sinSigma*cosAlpha1, (1-f)*sqrt(sinAlpha*sinAlpha + x*x));
    double lambda = atan2(sinSigma*sinAlpha1, cosU1*cosSigma - sinU1*sinSigma*cosAlpha1);
    double C = f/16*cosSqAlpha*(4+f*(4-3*cosSqAlpha));
    double L = lambda - (1-C) * f * sinAlpha *
            (sigma + C*sinSigma*(cos2SigmaM+C*cosSigma*(-1+2*cos2SigmaM*cos2SigmaM)));

    double tmp1 = (lon1+L+3*PI);
    double tmp2 = (2*PI);
    double lon2 = tmp1 - floor(tmp1/tmp2)*tmp2 - PI;

    lat2 = (lat2/PI) * 180;
    lon2 = (lon2/PI) * 180;

    QVector<double> predictionVector;
    predictionVector.append(lon2);
    predictionVector.append(lat2);

    return predictionVector;
}

double RadarWindow::BCOtoDEC(const double &code)
{
    double first_digit = qFloor(code / 4096.0);
    double second_digit = qFloor((code - first_digit*4096.0) / 256.0);
    double third_digit = qFloor((code - first_digit*4096.0 - second_digit*256.0) / 16);
    double fourth_digit = code - first_digit*4096.0 - second_digit*256.0 - third_digit*16.0;

    double transponder_code = (QString::number(first_digit) + QString::number(second_digit) + QString::number(third_digit) + QString::number(fourth_digit)).toDouble();

    return transponder_code;
}

void RadarWindow::drawCollisonPoint(const QString &aircraft_1, const QString &aircraft_2)
{
    QStringList aircraft_1_list;
    QStringList aircraft_2_list;

    aircraft_1_list = aircraft_1.split("\t");
    aircraft_2_list = aircraft_2.split("\t");


    double GPS_LAT_1, GPS_LON_1, HDG_1, TAS_1, GPS_LAT_2, GPS_LON_2, HDG_2, TAS_2;

    QListIterator<QString> iter(aircraft_1_list);
    while(iter.hasNext())
    {
        QString param = iter.next();

        if(param.contains("TAS"))
        {
            QStringList paramList = param.split("=");
            TAS_1 = paramList.at(1).toDouble();
        }

        if(param.contains("GPS_LAT"))
        {
            QStringList paramList = param.split("=");
            GPS_LAT_1 = paramList.at(1).toDouble();
        }

        if(param.contains("GPS_LON"))
        {
            QStringList paramList = param.split("=");
            GPS_LON_1 = paramList.at(1).toDouble();
        }

        if(param.contains("HDG"))
        {
            QStringList paramList = param.split("=");
            HDG_1 = paramList.at(1).toDouble();
        }
    }

    QListIterator<QString> iter_2(aircraft_2_list);
    while(iter_2.hasNext())
    {
        QString param = iter_2.next();

        if(param.contains("TAS"))
        {
            QStringList paramList = param.split("=");
            TAS_2 = paramList.at(1).toDouble();
        }

        if(param.contains("GPS_LAT"))
        {
            QStringList paramList = param.split("=");
            GPS_LAT_2 = paramList.at(1).toDouble();
        }

        if(param.contains("GPS_LON"))
        {
            QStringList paramList = param.split("=");
            GPS_LON_2 = paramList.at(1).toDouble();
        }

        if(param.contains("HDG"))
        {
            QStringList paramList = param.split("=");
            HDG_2 = paramList.at(1).toDouble();
        }
    }

    //qDebug() << GPS_LAT_1 << GPS_LON_1 << HDG_1 << TAS_1;
    //qDebug() << GPS_LAT_2 << GPS_LON_2 << HDG_2 << TAS_2;

    double alpha_1 = getAlpha(HDG_1);
    double alpha_2 = getAlpha(HDG_2);

    double a1 = qTan(alpha_1);
    double b1 = -1;
    double c1 = qTan(alpha_1) * GPS_LON_1 - GPS_LAT_1;
    double a2 = qTan(alpha_2);
    double b2 = -1;
    double c2 = qTan(alpha_2) * GPS_LON_2 - GPS_LAT_2;

    double GPS_LON = ((c1*b2) - (c2*b1)) / ((a1*b2) - (a2*b1));
    double GPS_LAT = ((a1*c2) - (a2*c1)) / ((a1*b2) - (a2*b1));

    //qDebug() << "vypocitane suradnice:: " << GPS_LON << GPS_LAT;

    QPen greenPen(Qt::green);
    greenPen.setWidth(3);
    greenPen.setCosmetic(true);

    line = scene->addLine(GPS_LON_1*LonScaleFactor, GPS_LAT_1*-LatScaleFactor,GPS_LON*LonScaleFactor, GPS_LAT*-LatScaleFactor, greenPen);
    line = scene->addLine(GPS_LON_2*LonScaleFactor, GPS_LAT_2*-LatScaleFactor,GPS_LON*LonScaleFactor, GPS_LAT*-LatScaleFactor, greenPen);
}

double RadarWindow::calculateDistance(const double &LAT_1, const double &LON_1, const double &LAT_2, const double &LON_2)
{
    double a = 6378137, b = 6356752.314245, f = 1/298.257223563; //WGS84 parameters
    double L = (LON_2 - LON_1) * (3.1415926535897/180);
    double U1 = atan((1-f) * tan(LAT_1 * (3.1415926535897/180)));
    double U2 = atan((1-f) * tan(LAT_2 * (3.1415926535897/180)));
    double sinU1 = sin(U1), cosU1 = cos(U1);
    double sinU2 = sin(U2), cosU2 = cos(U2);
    double sinLambda, sinSigma, cosSigma, sigma, sinAlfa;
    double cosSqAlfa, cos2SigmaM, C;

    double lambda = L, lambdaP;
    for(int j = 0;j < 150;j++)
    {
        sinLambda = sin(lambda); float cosLambda = cos(lambda);
        sinSigma = sqrt((cosU2*sinLambda)*(cosU2*sinLambda) + (cosU1*sinU2-sinU1*cosU2*cosLambda)*(cosU1*sinU2-sinU1*cosU2*cosLambda));
        cosSigma = sinU1*sinU2 + cosU1*cosU2*cosLambda;
        sigma = atan2(sinSigma,cosSigma);
        sinAlfa = cosU1*cosU2*sinLambda/sinSigma;
        cosSqAlfa = 1 - sinAlfa*sinAlfa;
        cos2SigmaM = cosSigma - 2*sinU1*sinU2/cosSqAlfa;
        C = f/16*cosSqAlfa*(4+f*(4-3*cosSqAlfa));
        lambdaP = lambda;
        lambda = L+(1-C)*f*sinAlfa*(sigma+C*sinSigma*(cos2SigmaM+C*cosSigma*(-1+2*cos2SigmaM*cos2SigmaM)));
    }

    double uSq = cosSqAlfa*(a*a - b*b)/(b*b);
    double A = 1+uSq/16384*(4096+uSq*(-768+uSq*(320-175*uSq)));
    double B = uSq/1024*(256+uSq*(-128+uSq*(74-47*uSq)));
    double deltaSigma = B*sinSigma*(cos2SigmaM+B/4*(cosSigma*(-1+2*cos2SigmaM*cos2SigmaM) - B/6*cos2SigmaM*(-3+4*sinSigma*sinSigma)*(-3+4*cos2SigmaM*cos2SigmaM)));

    double s = b*A*(sigma-deltaSigma);

    return s;
}

void RadarWindow::drawSTCAPoint(const QString &aircraft_1, const QString &aircraft_2)
{
    QStringList aircraft_1_list;
    QStringList aircraft_2_list;

    aircraft_1_list = aircraft_1.split("\t");
    aircraft_2_list = aircraft_2.split("\t");


    double GPS_LAT_1, GPS_LON_1, HDG_1, TAS_1, GPS_LAT_2, GPS_LON_2, HDG_2, TAS_2, GS_1, GS_2;

    QListIterator<QString> iter(aircraft_1_list);
    while(iter.hasNext())
    {
        QString param = iter.next();

        if(param.contains("GS"))
        {
            QStringList paramList = param.split("=");
            GS_1 = paramList.at(1).toDouble();
        }

        if(param.contains("TAS"))
        {
            QStringList paramList = param.split("=");
            TAS_1 = paramList.at(1).toDouble();
        }

        if(param.contains("GPS_LAT"))
        {
            QStringList paramList = param.split("=");
            GPS_LAT_1 = paramList.at(1).toDouble();
        }

        if(param.contains("GPS_LON"))
        {
            QStringList paramList = param.split("=");
            GPS_LON_1 = paramList.at(1).toDouble();
        }

        if(param.contains("HDG"))
        {
            QStringList paramList = param.split("=");
            HDG_1 = paramList.at(1).toDouble();
        }
    }

    QListIterator<QString> iter_2(aircraft_2_list);
    while(iter_2.hasNext())
    {
        QString param = iter_2.next();

        if(param.contains("GS"))
        {
            QStringList paramList = param.split("=");
            GS_2 = paramList.at(1).toDouble();
        }

        if(param.contains("TAS"))
        {
            QStringList paramList = param.split("=");
            TAS_2 = paramList.at(1).toDouble();
        }

        if(param.contains("GPS_LAT"))
        {
            QStringList paramList = param.split("=");
            GPS_LAT_2 = paramList.at(1).toDouble();
        }

        if(param.contains("GPS_LON"))
        {
            QStringList paramList = param.split("=");
            GPS_LON_2 = paramList.at(1).toDouble();
        }

        if(param.contains("HDG"))
        {
            QStringList paramList = param.split("=");
            HDG_2 = paramList.at(1).toDouble();
        }
    }

    //qDebug() << GPS_LAT_1 << GPS_LON_1 << HDG_1 << TAS_1;
    //qDebug() << GPS_LAT_2 << GPS_LON_2 << HDG_2 << TAS_2;

    double old_dist = 9999999;    // distance in [m]
    double new_dist = 9999998;
    double dist_counter = 0;
    QVector<double> predVect_1, predVect_2;
    QVector<double> old_predVect_1, old_predVect_2;
    double seconds;

    while((new_dist < old_dist) && (dist_counter < 500)) // until distance is closing and there is lower number of second of prediction to calculate
    {
        old_dist = new_dist;
        old_predVect_1 = predVect_1;
        old_predVect_2 = predVect_2;
        dist_counter++;
        seconds = dist_counter * 10;

        predVect_1 = prediction_calculation(GPS_LON_1, GPS_LAT_1, HDG_1, seconds, GS_1); // for first aircraft
        predVect_2 = prediction_calculation(GPS_LON_2, GPS_LAT_2, HDG_2, seconds, GS_2); // for second aircraft

        new_dist = calculateDistance(predVect_1[1], predVect_1[0], predVect_2[1], predVect_2[0]); // distance calculation from prediction
        //qDebug() << "distance counter: " << dist_counter << new_dist << old_dist;
    }

    QPen pen(QColor(255,102,0));
    pen.setWidth(1);
    pen.setCosmetic(true);

    line = scene->addLine(GPS_LON_1*LonScaleFactor, GPS_LAT_1*-LatScaleFactor, old_predVect_1[0]*LonScaleFactor,old_predVect_1[1]*-LatScaleFactor, pen);
    line = scene->addLine(GPS_LON_2*LonScaleFactor, GPS_LAT_2*-LatScaleFactor, old_predVect_2[0]*LonScaleFactor,old_predVect_2[1]*-LatScaleFactor, pen);

    old_dist = old_dist * 0.000539956803; // converison to NM;
    double scale = ui->MapView->transform().m11();
    int fontScale = qRound(16 / scale);
    if(fontScale < 1)
    {
        fontScale = 1;
    }

    pointText = scene->addText(QString::number(old_dist,'f',2) + " NM",QFont("Times New Roman", fontScale));
    pointText->setPos(old_predVect_1[0]*LonScaleFactor,old_predVect_1[1]*-LatScaleFactor);
    pointText->setDefaultTextColor(QColor(255,102,0));

    //qDebug() << old_predVect_1[0] << old_predVect_1[1];
    //qDebug() << old_predVect_2[0] << old_predVect_2[1];
}

bool RadarWindow::determineSTCAPoint(const QString &aircraft_1, const QString &aircraft_2)
{
    bool STCA = false;

    QStringList aircraft_1_list;
    QStringList aircraft_2_list;

    aircraft_1_list = aircraft_1.split("\t");
    aircraft_2_list = aircraft_2.split("\t");

    double GPS_LAT_1, GPS_LON_1, HDG_1, TAS_1, GPS_LAT_2, GPS_LON_2, HDG_2, TAS_2, GS_1, GS_2;

    QListIterator<QString> iter(aircraft_1_list);
    while(iter.hasNext())
    {
        QString param = iter.next();

        if(param.contains("GS"))
        {
            QStringList paramList = param.split("=");
            GS_1 = paramList.at(1).toDouble();
        }

        if(param.contains("TAS"))
        {
            QStringList paramList = param.split("=");
            TAS_1 = paramList.at(1).toDouble();
        }

        if(param.contains("GPS_LAT"))
        {
            QStringList paramList = param.split("=");
            GPS_LAT_1 = paramList.at(1).toDouble();
        }

        if(param.contains("GPS_LON"))
        {
            QStringList paramList = param.split("=");
            GPS_LON_1 = paramList.at(1).toDouble();
        }

        if(param.contains("HDG"))
        {
            QStringList paramList = param.split("=");
            HDG_1 = paramList.at(1).toDouble();
        }
    }

    QListIterator<QString> iter_2(aircraft_2_list);
    while(iter_2.hasNext())
    {
        QString param = iter_2.next();

        if(param.contains("GS"))
        {
            QStringList paramList = param.split("=");
            GS_2 = paramList.at(1).toDouble();
        }

        if(param.contains("TAS"))
        {
            QStringList paramList = param.split("=");
            TAS_2 = paramList.at(1).toDouble();
        }

        if(param.contains("GPS_LAT"))
        {
            QStringList paramList = param.split("=");
            GPS_LAT_2 = paramList.at(1).toDouble();
        }

        if(param.contains("GPS_LON"))
        {
            QStringList paramList = param.split("=");
            GPS_LON_2 = paramList.at(1).toDouble();
        }

        if(param.contains("HDG"))
        {
            QStringList paramList = param.split("=");
            HDG_2 = paramList.at(1).toDouble();
        }
    }

    double old_dist = 9999999;    // distance in [m]
    double new_dist = 9999998;
    double dist_counter = 0;
    QVector<double> predVect_1, predVect_2;
    QVector<double> old_predVect_1, old_predVect_2;
    double seconds;

    while((new_dist < old_dist) && (dist_counter < 10)) // until distance is closing and there is lower number of second of prediction to calculate
    {
        old_dist = new_dist;
        old_predVect_1 = predVect_1;
        old_predVect_2 = predVect_2;
        dist_counter++;
        seconds = dist_counter * 3;

        predVect_1 = prediction_calculation(GPS_LON_1, GPS_LAT_1, HDG_1, seconds, GS_1); // for first aircraft
        predVect_2 = prediction_calculation(GPS_LON_2, GPS_LAT_2, HDG_2, seconds, GS_2); // for second aircraft

        new_dist = calculateDistance(predVect_1[1], predVect_1[0], predVect_2[1], predVect_2[0]); // distance calculation from prediction
    }

    old_dist = old_dist * 0.000539956803; // converison to NM;
    //qDebug() << old_dist;

    if(old_dist <= 5)   // only draw line when STCA is less than 5 NM
    {
        STCA = true;
    }

    return STCA;
}

void RadarWindow::testSTCA()
{
    QSound sound("sound/STCA.wav");
    int hashSize = FlightSimHash.size();

    QListIterator<QString> iter(OnlineAircraftList);
    while(iter.hasNext())
    {
        QString callsign = iter.next();
        STCAhash.insert(callsign, false);
    }

    //qDebug() << "LIST " << OnlineAircraftList;

    if(hashSize > 1)
    {
        for(int i=0; i<hashSize-1; i++)
        {
            for(int j=i+1; j<hashSize; j++)
            {
                int len_1 = FlightSimHash.value(OnlineAircraftList.at(i)).size();
                int len_2 = FlightSimHash.value(OnlineAircraftList.at(j)).size();

                bool STCA = determineSTCAPoint(FlightSimHash.value(OnlineAircraftList.at(i)).at(len_1-1), FlightSimHash.value(OnlineAircraftList.at(j)).at(len_2-1));
                STCAhash.insert(OnlineAircraftList.at(i), STCA);
                STCAhash.insert(OnlineAircraftList.at(j), STCA);

                if(STCA == true)
                {
                    if(ui->flightPredictionSpinBox->value() < 1)
                    {
                        ui->flightPredictionSpinBox->setValue(1);
                    }

                    sound.play();
                }
            }
        }
    }

    //qDebug() << STCAhash;
}

double RadarWindow::getAlpha(const double &HDG)
{
    double alpha;

    if(HDG == 0)
    {
        alpha = 0.0000000001;
    }
    else if((HDG > 0) && (HDG <= 180))
    {
        alpha = (90 - HDG)*(PI/180);
    }
    else if((HDG > 180) && (HDG < 360))
    {
        alpha = (270- HDG)*(PI/180);
    }
    else if(HDG == 360)
    {
        alpha = 0.0000000001;
    }

    return alpha;
}

double RadarWindow::ROCD(const QHash<QString, QStringList> &flightsimhash, const QString CallSign)
{
    double rocd;
    QStringList valueList = flightsimhash.value(CallSign);

    if(valueList.size() <= 2)
    {
        rocd = 0;
    }
    else if(valueList.size() > 2)
    {
        QString lastString = valueList.at(valueList.size()-1);
        QString secondtolastString = valueList.at(valueList.size()-3);

        QStringList lastList = lastString.split("\t");
        QStringList secondtolastList = secondtolastString.split("\t");

        double GPS_ALT_1, GPS_ALT_2;

        QListIterator<QString> iter(lastList);
        while(iter.hasNext())
        {
            QString param = iter.next();

            if(param.contains("GPS_ALT"))
            {
                QStringList paramList = param.split("=");
                GPS_ALT_1 = (paramList.at(1).toDouble() / 100.0);
            }
        }

        QListIterator<QString> iter_2(secondtolastList);
        while(iter_2.hasNext())
        {
            QString param = iter_2.next();

            if(param.contains("GPS_ALT"))
            {
                QStringList paramList = param.split("=");
                GPS_ALT_2 = (paramList.at(1).toDouble() / 100.0);
            }
        }

        if(qAbs(GPS_ALT_1 - GPS_ALT_2) > 0.5)
        {
            if((GPS_ALT_1 - GPS_ALT_2) > 0)
            {
                rocd = 1;
            }
            else
            {
                rocd = -1;
            }

        }
        else
        {
            rocd = 0;
        }
    }

    return rocd;
}


QStringList RadarWindow::readSTRIP(const QString &fileName, const QString &CallSign)
{
    QStringList stripList;
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

        while(!stream.atEnd())
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

void RadarWindow::overwriteSQUAWK(const QString &fileName, const QString &CallSign, const QString &squawk)
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
                if(stripLineList.at(0) == "INBOUND")
                    stripLineList.replace(8, squawk);
                else if(stripLineList.at(0) == "OUTBOUND")
                    stripLineList.replace(5, squawk);
                else if(stripLineList.at(0) == "OVERFLIGHT")
                    stripLineList.replace(8, squawk);
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

void RadarWindow::overwriteNxtPoint(const QString &fileName, const QString &CallSign, const QString &NxtPoint)
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
                stripLineList.replace(1, NxtPoint);
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

void RadarWindow::overwriteCFL(const QString &fileName, const QString &CallSign, const QString &CFL)
{
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
                stripLineList.replace(stripLineList.size()-3, new_CFL);
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

void RadarWindow::update_drawing()
{
    scene->clear();

    double scale = ui->MapView->transform().m11();

    QBrush blackBrush(Qt::black);
    ui->MapView->setBackgroundBrush(blackBrush);

    drawMap("slovakia_map.txt");
    drawMapSection("slovakia_map.txt");

    if(ui->navPointsCheckBox->isChecked())
    {
        QStringList navPointList = loadNavPoints("nav_points.txt");    // load NAV Points List
        drawNavPoints(navPointList, scale);                                // draw NAV Points from List
    }

    if(ui->RWYCheckBox->isChecked())
    {
        drawRWY("airports_data.txt");
    }

    if(ui->TMACheckBox->isChecked())
    {
        drawTMA("slovakia_TMA.txt");
    }

    if(ui->CTRCheckBox->isChecked())
    {
        drawCTR("slovakia_CTR.txt");
    }

    QPen blackPen(Qt::black);
    blackPen.setCosmetic(true);
    blackPen.setWidth(1);
    line = scene->addLine(17.372778*LonScaleFactor, 48.216111*-LatScaleFactor, 17.375556*LonScaleFactor, 48.128611*-LatScaleFactor, blackPen);

    drawAircraft(FlightSimHash, scale);

    if(SelectedAircraftList.size() == 2)
    {
        int len_1 = FlightSimHash.value(SelectedAircraftList.at(0)).size();
        int len_2 = FlightSimHash.value(SelectedAircraftList.at(1)).size();

        drawSTCAPoint(FlightSimHash.value(SelectedAircraftList.at(0)).at(len_1-1), FlightSimHash.value(SelectedAircraftList.at(1)).at(len_2-1));
    }

    //test zblizenia STCA pre vsetky lietadla
    testSTCA();
}

// received data from Fligt Sim
void RadarWindow::dataFromFlightSim(const QString &callSign, const QString &message)
{
    if(FlightSimHash.value(callSign).isEmpty()) // first data transfer from aircraft
    {
        OnlineAircraftList.append(callSign);
        QStringList valueList;
        valueList.append(message);  // tu je iba jedna sprava od lietadla, to sa deje ak je ten list prazdny

        FlightSimHash.insert(callSign, valueList);
    }
    else    // add data for last 10 messages sent    // list nieje prazdny bude pridavat inak
    {
        QStringList valueList = FlightSimHash.value(callSign);

        if((valueList.size() < 10) && (valueList.size() >= 0))   // ak je velkost listu mensia ako pozadujem (10 dlzka), tak budem pridavat do listu dalsie spravy
        {
            valueList.append(message);
            FlightSimHash.insert(callSign, valueList);
        }

        else if(valueList.size() == 10)
        {
            for(int i=0; i<10-1; i++)
            {
                valueList.replace(i, valueList.at(i+1));
            }
            valueList.replace(10-1, message);

            FlightSimHash.insert(callSign, valueList);
        }
    }

    // remove from hash when status is CLOSED, won't do anything if status is OPENED -> remove aircraft from list and from scene
    QStringList messageList;
    messageList = message.split("\t");
    QString statusstring = messageList.at(0);
    QStringList splitList;
    splitList = statusstring.split("=");

    if(splitList.at(1) == "CLOSED")
    {
        FlightSimHash.remove(callSign);

        int counter_aircraft = 0;
        int index = 0;
        bool found = false;
        QListIterator<QString> iter(OnlineAircraftList);
        while(iter.hasNext())
        {
            QString actual = iter.next();
            if(actual == callSign)
            {
                index = counter_aircraft;
                found = true;
            }
            counter_aircraft++;
        }

        if(found == true)
        {
            OnlineAircraftList.removeAt(index);
        }

        // emit signal to close strip
        emit closed_connection(callSign);
    }
}

void RadarWindow::update_flightHistoryNum(const int &number)
{
    FlightHistory_num = number;
}

void RadarWindow::changeselection()
{
    FROM = ui->spinBox->value();
    TO = ui->spinBox_2->value();

    update_drawing();
}

void RadarWindow::aircraftClicked(const QString &text)
{
    QStringList selectedList;
    selectedList = text.split("\n");

    QString selected_callsign;
    if(selectedList.size() == 4)
    {
        selected_callsign = selectedList.at(1);
    }
    else if(selectedList.size() == 3)
    {
        selected_callsign = selectedList.at(0);
    }

    bool found = false;
    QListIterator<QString> iter(SelectedAircraftList);
    while(iter.hasNext())
    {
       QString callsign = iter.next();
       if(callsign == selected_callsign)
       {
           found = true;
       }
    }

    if(found == false)
    {
        SelectedAircraftList.append(selected_callsign);
    }
}

void RadarWindow::deselectAircraft_slot(const QString &text)
{
    if(HOMEpressed == true)
    {
        HOMEpressed = false;
    }
    else
    {
        SelectedAircraftList.clear();
        HOMEpressed = false;
    }
}


void RadarWindow::getSTRIPDataFrom(const QString &dataFrom)
{
    StripDataFrom = dataFrom;
}

void RadarWindow::GSclicked_slot()
{
    int GS_vect = ui->flightPredictionSpinBox->value();

    if(GS_vect < 6)
    {
        ui->flightPredictionSpinBox->setValue(GS_vect+1);
    }
}

void RadarWindow::CFLclicked_slot(const QString &callsign, const QString &actual_CFL, const QString &actual_FL)
{
    cflwidget->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::CustomizeWindowHint);
    cflwidget->setWindowTitle("CFL");
    cflwidget->setFixedSize(72,305);
    cflwidget->show();

    QPoint position = QPoint(mousePos.x(), mousePos.y());
    cflwidget->move(position);

    cflwidget->setCallSign(callsign);
    cflwidget->setActualFL(actual_FL);
}

void RadarWindow::DirectWPcliked_slot(const QString &callsign, const QString &actual_WP)
{
    directwidget->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::CustomizeWindowHint);
    directwidget->setWindowTitle("DIRECT");
    directwidget->show();

    QPoint position = QPoint(mousePos.x(), mousePos.y());
    directwidget->move(position);

    emit directWP_clicked(callsign, actual_WP);
}

void RadarWindow::CFLselection_slot(const QString &callsign, const QString &selected_cfl, const QString &actual_FL)
{
    overwriteCFL(StripDataFrom, callsign, selected_cfl);
    emit CFLclicked(callsign, selected_cfl, actual_FL);
}

void RadarWindow::changeDirectWP_slot(const QString &callsign, const QString &point)
{
    directHash.insert(callsign, point);
}

void RadarWindow::getDirectWP(const QString &callsign, const QString &point)
{
    directHash.insert(callsign, point);
    emit sendDirectWP(callsign, point);
}

void RadarWindow::getMousePos(const QPointF &mousepos)
{
    mousePos = mousepos;   
}

void RadarWindow::getLeftMousePos(const QPointF &leftMousePos)
{
    int boundaryTOPX = cflwidget->pos().x();
    int boundaryTOPY = cflwidget->pos().y();
    int boundaryBOTTOMX = boundaryTOPX + cflwidget->width();
    int boundaryBOTTOMY = boundaryTOPY + cflwidget->height();

    if((leftMousePos.x() < boundaryTOPX || leftMousePos.x() > boundaryBOTTOMX) || (leftMousePos.y() < boundaryTOPY || leftMousePos.y() > boundaryBOTTOMY))
    {
        cflwidget->close();
    }

    boundaryTOPX = directwidget->pos().x();
    boundaryTOPY = directwidget->pos().y();
    boundaryBOTTOMX = boundaryTOPX + directwidget->width();
    boundaryBOTTOMY = boundaryTOPY + directwidget->height();

    if((leftMousePos.x() < boundaryTOPX || leftMousePos.x() > boundaryBOTTOMX) || (leftMousePos.y() < boundaryTOPY || leftMousePos.y() > boundaryBOTTOMY))
    {
        directwidget->close();
    }
}

void RadarWindow::keyPressEvent(QKeyEvent *e)
{
    if((e->key() == Qt::Key_F) && QApplication::keyboardModifiers() && Qt::ControlModifier)
    {
            //qDebug() << "ctrl+F pressed";
    }
    if(e->key() == Qt::Key_Insert)
    {
        //qDebug() << "INSERT KEY pressed";
    }
    if(e->key() == Qt::Key_Home)
    {
        if(SelectedAircraftList.size() == 1)
        {
            HOMEpressed = true;
            //qDebug() << "HOME KEY pressed" << HOMEpressed;
        }
        else
        {
            HOMEpressed = false;
            //g() << "HOME KEY pressed" << HOMEpressed;
        }
    }
}

void RadarWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint mouse_pos = event->pos();
    //qDebug() << "SOMTU: " <<mapToGlobal(mouse_pos);
}
