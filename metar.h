#ifndef METAR_H
#define METAR_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QDebug>
#include <QTimer>
#include <QTime>

namespace Ui {
class Metar;
}

class Metar : public QWidget
{
    Q_OBJECT
    
public:
    explicit Metar(QWidget *parent = 0);
    ~Metar();

    QString visibilityParse(QString visibility);
    QString verticalVisibilityParse(QString vertVis);
    QString RWYVsibilityParse(QString RWYvisibility);
    QString cloudsParse(QString clouds);
    QString temperatureParse(QString temperature);
    QString pressureParse(QString pressure);
    QString weatherParse(QString weather);

    QString getMetar(QString airportICAO);
    QString getQNH();
    QString getWind();

    QString WIND;
    QString QNH;
    QTimer *timer;
    QString ICAOCallSign_METAR;
    QString METAR;

signals:
    void sendQNH(const QString &QNHdata);
    void metarSend(const QString &metar);
    
private:
    Ui::Metar *ui;

private slots:
    void timeout_slot();
    void setTime(const QString &time);

};

#endif // METAR_H
