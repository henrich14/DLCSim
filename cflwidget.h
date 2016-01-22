#ifndef CFLWIDGET_H
#define CFLWIDGET_H

#include <QWidget>
#include <QObject>
#include <QtGui>
#include <QtCore>

namespace Ui {
class CFLWidget;
}

class CFLWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit CFLWidget(QWidget *parent = 0);
    ~CFLWidget();

    void setCallSign(const QString &callsign);
    void setActualFL(const QString &actual_FL);

signals:
    void CFLselection_clicked(const QString &callsign, const QString &CFL, const QString &actual_FL);

public slots:
    void plus_clicked_slot();
    void minus_clicked_slot();
    void five_clicked_slot();
    void FL1_clicked_slot();
    void FL2_clicked_slot();
    void FL3_clicked_slot();
    void FL4_clicked_slot();
    void FL5_clicked_slot();
    void FL6_clicked_slot();
    void FL7_clicked_slot();
    void FL8_clicked_slot();
    void FL9_clicked_slot();
    void FL10_clicked_slot();
    void FL11_clicked_slot();
    void FL12_clicked_slot();
    void FL13_clicked_slot();
    void UPLINKclicked_slot();
    void CANCELclicked_slot();
    
private:
    Ui::CFLWidget *ui;

    QString CallSign;
    QString act_FL;
    QString CFL;

protected:
    virtual void keyPressEvent(QKeyEvent *e);
};

#endif // CFLWIDGET_H
