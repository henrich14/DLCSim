#ifndef STRIP_H
#define STRIP_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QTimer>
#include <QTime>

namespace Ui {
class Strip;
}

class Strip : public QDialog
{
    Q_OBJECT
    
public:
    explicit Strip(QWidget *parent = 0);
    ~Strip();

    QStringList readStrip(const QString &FileName, const QString &CallSign);
    void setCallSign(const QString &CallSign);
    void setStripDataFileName(const QString &dataFileName);
    void update();
    
private:
    Ui::Strip *ui;

    QString callSign;
    QString stripDataFrom;
    QTimer *timer;

protected:
    bool eventFilter(QObject *target, QEvent *event);


private slots:
    void updateStrip_slot();
    void saveToSTRIP();
};

#endif // STRIP_H
