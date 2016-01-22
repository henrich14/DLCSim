#ifndef DIRECTWIDGET_H
#define DIRECTWIDGET_H

#include <QWidget>
#include <QObject>
#include <QtGui>
#include <QtCore>

namespace Ui {
class DirectWidget;
}

class DirectWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit DirectWidget(QWidget *parent = 0);
    ~DirectWidget();

    void setFlightPlan(const QString &callsign, const QString &flightplan);

signals:
    void sendDirectWP(const QString &callsign, const QString &directWP);
    
private:
    Ui::DirectWidget *ui;

    QHash<QString, QString> flightplanHash;
    QString CallSign;

public slots:
    void directWPclicked_slot(const QString &callsign, const QString &actual_WP);
    void UPLINKclicked_slot();
    void CANCELclicked_slot();

protected:
    virtual void keyPressEvent(QKeyEvent *event);

};

#endif // DIRECTWIDGET_H
