#ifndef STRIPINBOUND_H
#define STRIPINBOUND_H

#include <QDialog>
#include <QObject>
#include <QtGui>


namespace Ui {
class StripInbound;
}

class StripInbound : public QDialog
{
    Q_OBJECT
    
public:
    explicit StripInbound(QWidget *parent = 0);
    ~StripInbound();

    QStringList readStrip(const QString &FileName, const QString &CallSign);
    void setCallSign(const QString &CallSign);
    void setStripDataFileName(const QString &dataFileName);
    void update();
    void overwriteStrip(const QString &FileName, const QString &CallSignRow, const QString &callsign);
    QString createLine(const QStringList &stringList, const QString &CallSign);

    QStringList readInfoFromFile(const QString &FileName, const QString &info);

private:
    Ui::StripInbound *ui;

    QString callSign;
    QString stripDataFrom;
    int trackIdx;
    QString FPcallsign;
    QString FlightPlan;
    int FPcounter;

private slots:
    void updateStrip_slot();
    void terminate_clicked_slot(const QString &fromcallsign);
    void logon_clicked_slot(const QString &fromcallsign);
    void arrivalRoute_changed_slot(const QString &route);
    void point_1_changed(const QString &point1);
    void point_2_changed(const QString &point2);
    void arrivalRoute_confirmed(const QString &fromCallSign);
    void actualflightLevel_changed(const QString &fromCallSign, const QString flightLevel);
    void changeInStrip();
    void receiveFlightPlan(const QString &callsign, const QString &flightplan);

signals:
    void arrivalRoute_change_signal(const QString &route, const QString &CallSign);
    void changeDirectWP(const QString &callsign, const QString &point);
    void STRIP_closed(const QString &callsign);

protected:
    virtual void closeEvent(QCloseEvent *event);

};

#endif // STRIPINBOUND_H
