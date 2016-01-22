#include "directwidget.h"
#include "ui_directwidget.h"

DirectWidget::DirectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DirectWidget)
{
    ui->setupUi(this);

    CallSign = "";

    connect(ui->UPLINK_pushButton, SIGNAL(clicked()), this, SLOT(UPLINKclicked_slot()));
    connect(ui->CANCEL_pushButton, SIGNAL(clicked()), this, SLOT(CANCELclicked_slot()));
}

DirectWidget::~DirectWidget()
{
    delete ui;
}

void DirectWidget::setFlightPlan(const QString &callsign, const QString &flightplan)
{
    flightplanHash.insert(callsign, flightplan);
}

void DirectWidget::directWPclicked_slot(const QString &callsign, const QString &actual_WP)
{
    ui->Point_comboBox->clear();

    CallSign = callsign;
    QStringList flightplanList = flightplanHash.value(callsign).split("+");
    ui->Point_comboBox->insertItems(0,flightplanList);

    int idx = 0;
    QListIterator<QString> iter(flightplanList);
    while(iter.hasNext())
    {
        if(iter.next() == actual_WP)
        {
            ui->Point_comboBox->setCurrentIndex(idx);
        }
        idx++;
    }
}

void DirectWidget::UPLINKclicked_slot()
{
    QString point = ui->Point_comboBox->currentText();

    emit sendDirectWP(CallSign, point);

    this->close();
}

void DirectWidget::CANCELclicked_slot()
{
    this->close();
}

void DirectWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        this->close();
    }
}
