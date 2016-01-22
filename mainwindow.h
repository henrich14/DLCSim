#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTimer>
#include <QTime>
#include <QtGui>
#include <QtCore>

#include "strip.h"
#include "stripoverflight.h"
#include "stripoutbound.h"
#include "stripinbound.h"
#include "label.h"
#include "metar.h"
#include "time.h"
#include "timesyncdialog.h"
#include "radarwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void readSTRIP(const QString &fileName, const QString &CallSign);
    void overwriteRAD(const QString &fileName, const QString &CallSign, const QString &rad);
    void overwriteFL(const QString &fileName, const QString &CallSign, const QString &FL);
    void overwriteLOGGED(const QString &fileName, const QString &CallSign, const QString &logged);
    QString getFLIGHTchar(const QStringList &StripList);
    QString getARRPoint(const QStringList &StripList);
    QString getARRFL(const QStringList &StripList);
    QString getType(const QStringList &StripList);
    QString getCruisingSpeed(const QStringList &StripList);
    QString getDEP(const QStringList &StripList);
    QString getARR(const QStringList &StripList);
    QString getFL(const QStringList &StripList);
    QString getRADIAL(const QStringList &StripList);
    QString getQNH(const QStringList &StripList);
    void showMETAR();
    void setInitTime(const QString &time);
    void changeCallSignColor(const QString &CallSign);

    void updateMessage(const QString &message);
    void setSTATUS(const QString &status);

    void differentiateMessages(const QString fromPATC, const QString fromCallSign, const QString toCallSign, const QString message);

    void delay(const int millisecondsToWait);

signals:
    void timeToMetar(const QString &current_time);
    void timeToTime(const QString &curretn_time);
    void terminate_clicked(const QString &fromcallsign);
    void logon_clicked(const QString &fromcallsign);
    void arrivalRoute_confirmed(const QString &fromcallsign);
    void actualFlightLevel_changed(const QString &fromcallsign, const QString &flightLevel);
    void messageFromFlightSim(const QString callSign, const QString &message);
    void sendSTRIPDataFrom(const QString &dataFrom);

private:
    Ui::MainWindow *ui;

    QTcpSocket *socket;
    QTimer *timer;
    QTimer *newMessageTimer;
    QTimer *sentMessageTimer;

    QListWidget *PilotsListWidget_overflight;
    QListWidget *PilotListWidget_inbound;
    QListWidget *PilotListWidget_outbound;
    QListWidget *AtcListWidget;
    QStringList stripList;
    QSplitter *pilotSplitter;
    QGroupBox *inboundGroupBox;
    QGroupBox *outboundGroupBox;
    QGroupBox *overflightGroupBox;
    QGroupBox *atcGroupBox;
    QVBoxLayout *vertlayout_1;
    QVBoxLayout *vertlayout_2;
    QVBoxLayout *vertlayout_3;
    QVBoxLayout *vertlayout_4;

    Strip *strip;
    StripOverflight *stripoverflight;
    StripOutbound *stripoutbound;
    StripInbound *stripinbound;
    Label *label;
    Metar *metar;
    Time *time;
    TimeSyncDialog *timeSyncDialog;
    QDockWidget *dock;
    QDockWidget *pilotListDock;
    QDockWidget *metarDock;
    QDockWidget *timeDock;

    RadarWindow *radarMainWindow;

    QString RADIAL;
    QString POINT;
    QString ALTITUDE;
    QString VERTICALRATE;
    QString TIME;
    QString DISTANCE;
    QString TRACK;
    QString LEVEL;
    QString QNH;

    QString STATUS;
    QString initTime;
    bool history;
    bool msg;
    bool stbyclicked;
    bool editable;
    QStringList CallSignListConnected;
    QStringList callsignOld;
    QStringList ExportTimeList;
    QStringList ExportMessageList;
    QStringList incomingMessageList;
    QStringList incomingMessageTimeList;
    QStringList historyList;
    QStringList ATCList;
    QString ATCFROMCALLSIGN;
    bool ATCFromChange;
    bool QNHChecked_status;

    QString StripDataFrom;

    QString newMessage;
    QString messageClicked;
    QString TIMEstring;
    QTime TIMEtime;

    QMenu *FileMenu;
    QAction *MetarAction;
    QAction *PostsAction;
    QAction *AboutAction;
    QAction *TimeAction;
    QAction *RADARAction;

    QHash<QString, QString> hashList;
    QStringList openedSTRIPList;

    void createDockWindow();

private slots:
    void overwriteNextPointETE(const QString &fileName, const QString &callSign, const double &ETE);
    void changeDirectWP_slot(const QString &callsign, const QString &point);
    void QNHChecked_slot(const bool qnhchecked);
    void getQNH(const QString &QNHdata);
    void showMetarDock();
    void showPostsDock();
    void showAboutDock();
    void showTimeDock();
    void showRADAR();
    void loginButton_clicked();
    void ATCSendButton_clicked();
    void readyRead();
    void connected();
    void setCurrentTime();
    void newMessageTimeout();
    void sentMessageTimeout();
    void ATCListWidget_clicked(QListWidgetItem *item);
    void pilotListWidget_OF_clicked(QListWidgetItem *item);
    void showStrip_OF();
    void showStrip_overflight(const QString &CallSign);
    void showStrip_inbound(const QString &CallSign);
    void showStrip_outbound(const QString &CallSign);
    void arrivalRoute_change_slot(const QString &route, const QString &CallSign);
    void showLabel_OF();
    void pilotListWidget_IN_clicked(QListWidgetItem *item);
    void showStrip_IN();
    void showLabel_IN();
    void pilotListWidget_OU_clicked(QListWidgetItem *item);
    void showStrip_OU();
    void showLabel_OU();
    void FLChange_pending(const QString &level);
    void labelChange_pending(const QString &message);
    void change_cancelled(const QString &message);
    void TIMEchange_pending(const QString &time);
    void RATEchange_pending(const QString &rate);
    void RADIALChange_pending(const QString &radial);
    void messageChange_slot(const QString &message);
    void POINTchange_pending(const QString &point);
    void TRACKchange_pending(const QString &track);
    void ALTITUDEchanged_pending(const QString &altitude);
    void DISTANCEchanged_pending(const QString &distance);
    void ATCPilotRadioButtonChanged();
    void SpecialButtonClicked(const QString &message);
    void initTimeSync();
    void getInitTime(const QString &init_time);
    void history_clicked();
    void CFLclicked_slot(const QString &callsign, const QString &CFL, const QString &actual_FL);
    void STRIP_closed_slot(const QString &callsign);

    void WILCObutton_clicked();
    void ROGERbutton_clicked();
    void UNABLEbutton_clicked();
    void PERFORMANCEbutton_clicked();
    void WEATHERbutton_clicked();
    void STANDBYbutton_clicked();
    void SENDbutton_clicked();
    void DISCARDbutton_clicked();
    void CANCELbutton_clicked();
    void MODIFYbutton_clicked();
    void OKbutton_clicked();

    void fmcButtonL1clicked();
    void fmcButtonL2clicked();
    void fmcButtonL3clicked();
    void fmcButtonL4clicked();
    void fmcButtonR1clicked();
    void fmcButtonR2clicked();
    void fmcButtonR3clicked();
    void fmcButtonR4clicked();
    void pilotMenuButton_clicked();
    void pilotMSGButton_clicked();
    void keyPad_1_clicked();
    void keyPad_2_clicked();
    void keyPad_3_clicked();
    void keyPad_4_clicked();
    void keyPad_5_clicked();
    void keyPad_6_clicked();
    void keyPad_7_clicked();
    void keyPad_8_clicked();
    void keyPad_9_clicked();
    void keyPad_10_clicked();
    void keyPad_11_clicked();
    void keyPad_12_clicked();
    void keyPad_13_clicked();
    void keyPad_14_clicked();
    void keyPad_15_clicked();
    void keyPad_16_clicked();
    void keyPad_17_clicked();
    void keyPad_18_clicked();
    void keyPad_19_clicked();
    void keyPad_20_clicked();
    void keyPad_21_clicked();
    void keyPad_22_clicked();
    void keyPad_23_clicked();
    void keyPad_24_clicked();
    void keyPad_25_clicked();
    void keyPad_26_clicked();
    void keyPad_27_clicked();
    void keyPad_28_clicked();
    void keyPad_29_clicked();
    void keyPad_30_clicked();
    void numPad_1_clicked();
    void numPad_2_clicked();
    void numPad_3_clicked();
    void numPad_4_clicked();
    void numPad_5_clicked();
    void numPad_6_clicked();
    void numPad_7_clicked();
    void numPad_8_clicked();
    void numPad_9_clicked();
    void numPad_10_clicked();
    void numPad_11_clicked();
    void numPad_12_clicked();

    void autosave();

protected:
    void closeEvent(QCloseEvent * event);

};

#endif // MAINWINDOW_H
