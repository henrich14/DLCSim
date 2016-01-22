#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QtCore>
#include <QtGui>

namespace Ui {
class Label;
}

class Label : public QWidget
{
    Q_OBJECT
    
public:
    explicit Label(QWidget *parent = 0);
    ~Label();
    void setCallSign(const QString &CallSign);
    void setRadial(const QString &Radial);
    void setNextPointAtTime(const QString &NextPointAtTime);
    void setARRDEPRoute(const QString &ARRDEPRoute);
    void setFreqChange(const QString &FreqChange);
    void setAircraftType(const QString &AircraftType);
    void setAircraftCategory(const QString &AircraftCategory);
    void setStripDataName(const QString &fileName);
    void setCurrentFL(const QString &level);
    void setCurrentRadial(const QString &radial);

    void showMessagecomboBox();
    void readSTRIP(const QString &fileName,const QString &CallSign);
    QStringList readFile(const QString &FileName);
    QStringList getINFOfromFile(const QStringList &stringList, const QString &info);
    void updateFreqList();
    void updatePointList();
    void updateTrackList();

    void setATCcallsign(const QString &ATCCallSign);
    void updateCallSignColor();

signals:
    void QNHChecked(const bool qnhClicked);
    void FLchange_pending(const QString &message);
    void change_cancelled(const QString &message);
    void change_uplink();
    void TIMEchange_pending(const QString &time);
    void RATEchange_pending(const QString &rate);
    void ALTITUDEchange_pending(const QString &altitude);
    void RADIALchange_pending(const QString &radial);
    void DISTANCEchange_pending(const QString &distance);

    void frequencyChange_pending(const QString &freq);
    void pointChange_pending(const QString &point);
    void trackChange_pending(const QString &track);

    void messageChanged(const QString &message);

    void roger_signal(const QString &message);
    void disregard_signal(const QString &message);
    void affirm_signal(const QString &message);
    void negative_signal(const QString &message);
    void contactRequest_signal(const QString &message);
    void contactRequestVoice_signal(const QString &message);
    void logOn_signal(const QString &message);
    void resumeOwnNavigation_signal(const QString &message);


    
private:
    Ui::Label *ui;
    QStringList stripList;
    QString StripDataFileName;
    QString callsign;
    QString QNH;
    QString METAR_data;

    QString ATCcallsign;

    QStringList CallSignList_selected;
    QStringList RadialList_selected;
    bool callSign_found;

    QHash<QString, int> radialHash;

private slots:
    void FLchange_slot();
    void canceled_slot();
    void uplink_slot();
    void radialButtonClicked_slot();
    void freqChangeClicked_slot(const QString &PostFreq);
    QString getCurrentFL(const QStringList &StripList);
    QString getCurrentRADIAL(const QStringList &StripList);
    void setFL();
    void getQNH(const QString &QNHdata);
    void ROGER_clicked();
    void DISREGARD_clicked();
    void AFFIRM_clicked();
    void NEGATIVE_clicked();
    void CONTACTrequest_clicked();
    void CONTACTrequestVoice_clicked();
    void logOnclicked_clicked();
    void RESUMEownNavigation_clicked();
    void messageREAD_slot();
    void currentMessageREAD_slot(const QString &message);
    void getMetarData(const QString &METAR_DATA);
};

#endif // LABEL_H
