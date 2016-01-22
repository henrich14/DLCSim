#include "time.h"
#include "ui_time.h"

Time::Time(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Time)
{
    ui->setupUi(this);
    ui->timeLabel->setAlignment(Qt::AlignCenter);

     ui->timeLabel->setStyleSheet("QLabel {color : red; }");
     setStyleSheet("QFrame { border: 5px solid red; }");

}

Time::~Time()
{
    delete ui;
}

void Time::setTime(const QString &time)
{
    ui->timeLabel->setText(time);
}
