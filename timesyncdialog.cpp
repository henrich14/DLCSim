#include "timesyncdialog.h"
#include "ui_timesyncdialog.h"
#include <QDebug>

TimeSyncDialog::TimeSyncDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeSyncDialog)
{
    ui->setupUi(this);

    ui->hourSpinBox->setRange(0,23);
    ui->hourSpinBox->setWrapping(true);
    ui->minuteSpinBox->setRange(0,59);
    ui->minuteSpinBox->setWrapping(true);
    ui->secondSpinBox->setRange(0,59);
    ui->secondSpinBox->setWrapping(true);

    ui->hourSpinBox->setValue(12);
    ui->minuteSpinBox->setValue(33);
    ui->secondSpinBox->setValue(0);


    connect(ui->syncButton, SIGNAL(clicked()), this, SLOT(setTime_slot()));
    connect(ui->syncButton, SIGNAL(clicked()), this, SLOT(accept()));
}

TimeSyncDialog::~TimeSyncDialog()
{
    delete ui;
}

void TimeSyncDialog::setTime_slot()
{
    QString hour = QString::number(ui->hourSpinBox->value());
    QString minute = QString::number(ui->minuteSpinBox->value());
    if(minute.length() == 1)
    {
        minute = "0" + minute;
    }
    QString second = QString::number(ui->secondSpinBox->value());
    if(second.length() == 1)
    {
        second = "0" + second;
    }

    QString time = hour + "#" + minute + "#" + second;

    emit(setTime_signal(time));
}

