#ifndef STRIPOUTBOUND_H
#define STRIPOUTBOUND_H

#include <QDialog>
#include <QObject>
#include <QtGui>

namespace Ui {
class StripOutbound;
}

class StripOutbound : public QDialog
{
    Q_OBJECT
    
public:
    explicit StripOutbound(QWidget *parent = 0);
    ~StripOutbound();

    QStringList readStrip(const QString &FileName, const QString &CallSign);
    void setCallSign(const QString &CallSign);
    void setStripDataFileName(const QString &dataFileName);
    void update();
    void overwriteStrip(const QString &FileName, const QString &CallSignRow, const QString &callsign);
    QString createLine(const QStringList &stringList, const QString &CallSign);

    QStringList readInfoFromFile(const QString &FileName, const QString &info);
    
private:
    Ui::StripOutbound *ui;

    QString callSign;
    QString stripDataFrom;
    QString FPcallsign;
    QString FlightPlan;
    int FPcounter;

private slots:
    void updateStrip_slot();
    void terminate_clicked_slot(const QString &fromcallsign);
    void logon_clicked_slot(const QString &fromcallsign);
    void actualflightLevel_changed(const QString &fromCallSign, const QString flightLevel);
    void point_changed(const QString &point);
    void changeInStrip();
    void receiveFlightPlan(const QString &callsign, const QString &flightplan);

signals:
    void changeDirectWP(const QString &callsign, const QString &point);
    void STRIP_closed(const QString &callsign);

protected:
    void closeEvent(QCloseEvent * event);
};

#endif // STRIPOUTBOUND_H
