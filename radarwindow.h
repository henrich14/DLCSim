#ifndef RADARWINDOW_H
#define RADARWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QtCore>
#include <QtGui>
#include <QTimer>
#include <QTime>
#include <QPen>
#include <QSound>

#include "mytextitem.h"
#include "cflwidget.h"
#include "directwidget.h"

namespace Ui {
class RadarWindow;
}

class RadarWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit RadarWindow(QWidget *parent = 0);
    ~RadarWindow();

    QVector<double> loadLatFromMap(const QString &filename);
    QVector<double> loadLonFromMap(const QString &filename);
    QStringList loadNavPoints(const QString &filename);
    void drawMap(const QString &filename);
    void drawMapSection(const QString &filename);
    void drawNavPoints(const QStringList &navPointList, const double &scale);
    void drawRWY(const QString &filename);
    void drawCTR(const QString &filename);
    void drawTMA(const QString &filename);
    void drawAircraft(const QHash<QString, QStringList> &flightsimhash, const double &scale);
    QVector<double> prediction_calculation(const double &init_LON, const double &init_LAT, const double &init_HDG, const double &seconds, const double &GS);
    double BCOtoDEC(const double &code);
    void drawCollisonPoint(const QString &aircraft_1, const QString &aircraft_2);
    double calculateDistance(const double &LAT_1, const double &LON_1, const double &LAT_2, const double &LON_2);
    void drawSTCAPoint(const QString &aircraft_1, const QString &aircraft_2);
    bool determineSTCAPoint(const QString &aircraft_1, const QString &aircraft_2);
    void testSTCA();
    double getAlpha(const double &HDG);
    double ROCD(const QHash<QString, QStringList> &flightsimhash, const QString CallSign);
    QStringList readSTRIP(const QString &fileName, const QString &CallSign);
    void overwriteSQUAWK(const QString &fileName, const QString &CallSign, const QString &squawk);
    void overwriteNxtPoint(const QString &fileName, const QString &CallSign, const QString &NxtPoint);
    void overwriteCFL(const QString &fileName, const QString &CallSign, const QString &CFL);

private slots:
    void update_drawing();
    void dataFromFlightSim(const QString &callSign, const QString &message);
    void update_flightHistoryNum(const int &number);
    void changeselection();
    void aircraftClicked(const QString &text);
    void deselectAircraft_slot(const QString &text);
    void getSTRIPDataFrom(const QString &dataFrom);
    void GSclicked_slot();
    void CFLclicked_slot(const QString &callsign, const QString &actual_CFL, const QString &actual_FL);
    void DirectWPcliked_slot(const QString &callsign, const QString &actual_WP);
    void CFLselection_slot(const QString &callsign, const QString &selected_cfl, const QString &actual_FL);
    void changeDirectWP_slot(const QString &callsign, const QString &point);
    void getDirectWP(const QString &callsign, const QString &point);
    void getMousePos(const QPointF &mousepos);
    void getLeftMousePos(const QPointF &leftMousePos);

signals:
    void changeEmergencyStatus(const bool &);
    void closed_connection(const QString &callsign);
    void CFLclicked(const QString &callsign, const QString &CFL, const QString &actual_FL);
    void NextPointETE(const QString &fileName, const QString &callSign, const double &ETE);
    void sendFlightPlan(const QString &CallSign, const QString &flightPlan);
    void directWP_clicked(const QString &callsign, const QString &actual_WP);
    void sendDirectWP(const QString &callsign, const QString &point);
    
private:
    Ui::RadarWindow *ui;

    QGraphicsScene *scene;
    MyTextItem *mytextitem;
    CFLWidget *cflwidget;
    DirectWidget *directwidget;

    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QPolygonF polygon;
    QPolygonF poly;
    QGraphicsLineItem *line;
    QGraphicsPolygonItem *polygonItem;
    QGraphicsTextItem *pointText;

    QPainterPath *path;

    QStringList MessageList;
    QStringList SelectedAircraftList;

    QHash<QString, QStringList> FlightSimHash;
    QHash<QString, QString> directHash;

    QTimer *update_timer;

    int FlightHistory_num;

    int FROM;
    int TO;

    bool visibility;
    bool HOMEpressed;

    QStringList OnlineAircraftList;
    QHash<QString, bool> STCAhash;
    QString StripDataFrom;
    QPointF mousePos;

protected:
    //virtual void wheelEvent(QWheelEvent *event);
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // RADARWINDOW_H
