#ifndef TIME_H
#define TIME_H

#include <QWidget>

namespace Ui {
class Time;
}

class Time : public QWidget
{
    Q_OBJECT
    
public:
    explicit Time(QWidget *parent = 0);
    ~Time();
    
private:
    Ui::Time *ui;

private slots:
    void setTime(const QString &time);
};

#endif // TIME_H
