#include "cflwidget.h"
#include "ui_cflwidget.h"

CFLWidget::CFLWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CFLWidget)
{
    ui->setupUi(this);

    connect(ui->plus_pushButton, SIGNAL(clicked()), this, SLOT(plus_clicked_slot()));
    connect(ui->minus_pushButton, SIGNAL(clicked()), this, SLOT(minus_clicked_slot()));
    connect(ui->five_pushButton, SIGNAL(clicked()), this, SLOT(five_clicked_slot()));
    connect(ui->FL1_pushButton, SIGNAL(clicked()), this, SLOT(FL1_clicked_slot()));
    connect(ui->FL2_pushButton, SIGNAL(clicked()), this, SLOT(FL2_clicked_slot()));
    connect(ui->FL3_pushButton, SIGNAL(clicked()), this, SLOT(FL3_clicked_slot()));
    connect(ui->FL4_pushButton, SIGNAL(clicked()), this, SLOT(FL4_clicked_slot()));
    connect(ui->FL5_pushButton, SIGNAL(clicked()), this, SLOT(FL5_clicked_slot()));
    connect(ui->FL6_pushButton, SIGNAL(clicked()), this, SLOT(FL6_clicked_slot()));
    connect(ui->FL7_pushButton, SIGNAL(clicked()), this, SLOT(FL7_clicked_slot()));
    connect(ui->FL8_pushButton, SIGNAL(clicked()), this, SLOT(FL8_clicked_slot()));
    connect(ui->FL9_pushButton, SIGNAL(clicked()), this, SLOT(FL9_clicked_slot()));
    connect(ui->FL10_pushButton, SIGNAL(clicked()), this, SLOT(FL10_clicked_slot()));
    connect(ui->FL11_pushButton, SIGNAL(clicked()), this, SLOT(FL11_clicked_slot()));
    connect(ui->FL12_pushButton, SIGNAL(clicked()), this, SLOT(FL12_clicked_slot()));
    connect(ui->FL13_pushButton, SIGNAL(clicked()), this, SLOT(FL13_clicked_slot()));
    connect(ui->UPLINK_pushButton, SIGNAL(clicked()), this, SLOT(UPLINKclicked_slot()));
    connect(ui->CANCEL_pushButton, SIGNAL(clicked()), this, SLOT(CANCELclicked_slot()));

    CallSign = "";
    act_FL = "";
    CFL = "";

    QString style1 = QString(
                "QPushButton {color: black;"
                            "font: 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
}

CFLWidget::~CFLWidget()
{
    delete ui;
}

void CFLWidget::setCallSign(const QString &callsign)
{
    CallSign = callsign;
}

void CFLWidget::setActualFL(const QString &actual_FL)
{
    act_FL = actual_FL;
}

void CFLWidget::plus_clicked_slot()
{
    QString style1 = QString(
                "QPushButton {color: black;"
                            "font: 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
    CFL = "";

    if(ui->five_pushButton->text().toInt() == 5)
    {
        ui->FL13_pushButton->setText(ui->FL12_pushButton->text());
        ui->FL12_pushButton->setText(ui->FL11_pushButton->text());
        ui->FL11_pushButton->setText(ui->FL10_pushButton->text());
        ui->FL10_pushButton->setText(ui->FL9_pushButton->text());
        ui->FL9_pushButton->setText(ui->FL8_pushButton->text());
        ui->FL8_pushButton->setText(ui->FL7_pushButton->text());
        ui->FL7_pushButton->setText(ui->FL6_pushButton->text());
        ui->FL6_pushButton->setText(ui->FL5_pushButton->text());
        ui->FL5_pushButton->setText(ui->FL4_pushButton->text());
        ui->FL4_pushButton->setText(ui->FL3_pushButton->text());
        ui->FL3_pushButton->setText(ui->FL2_pushButton->text());
        ui->FL2_pushButton->setText(ui->FL1_pushButton->text());

        ui->FL1_pushButton->setText(QString::number(ui->FL1_pushButton->text().toInt() + 10));
    }

    else
    {
        ui->FL13_pushButton->setText(ui->FL12_pushButton->text());
        ui->FL12_pushButton->setText(ui->FL11_pushButton->text());
        ui->FL11_pushButton->setText(ui->FL10_pushButton->text());
        ui->FL10_pushButton->setText(ui->FL9_pushButton->text());
        ui->FL9_pushButton->setText(ui->FL8_pushButton->text());
        ui->FL8_pushButton->setText(ui->FL7_pushButton->text());
        ui->FL7_pushButton->setText(ui->FL6_pushButton->text());
        ui->FL6_pushButton->setText(ui->FL5_pushButton->text());
        ui->FL5_pushButton->setText(ui->FL4_pushButton->text());
        ui->FL4_pushButton->setText(ui->FL3_pushButton->text());
        ui->FL3_pushButton->setText(ui->FL2_pushButton->text());
        ui->FL2_pushButton->setText(ui->FL1_pushButton->text());

        ui->FL1_pushButton->setText(QString::number(ui->FL1_pushButton->text().toInt() + 5));
    }


}

void CFLWidget::minus_clicked_slot()
{
    QString style1 = QString(
                "QPushButton {color: black;"
                            "font: 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);

    CFL = "";

    if(ui->five_pushButton->text().toInt() == 5)
    {
        if(ui->FL13_pushButton->text().toInt() != 10)
        {
            ui->FL1_pushButton->setText(ui->FL2_pushButton->text());
            ui->FL2_pushButton->setText(ui->FL3_pushButton->text());
            ui->FL3_pushButton->setText(ui->FL4_pushButton->text());
            ui->FL4_pushButton->setText(ui->FL5_pushButton->text());
            ui->FL5_pushButton->setText(ui->FL6_pushButton->text());
            ui->FL6_pushButton->setText(ui->FL7_pushButton->text());
            ui->FL7_pushButton->setText(ui->FL8_pushButton->text());
            ui->FL8_pushButton->setText(ui->FL9_pushButton->text());
            ui->FL9_pushButton->setText(ui->FL10_pushButton->text());
            ui->FL10_pushButton->setText(ui->FL11_pushButton->text());
            ui->FL11_pushButton->setText(ui->FL12_pushButton->text());
            ui->FL12_pushButton->setText(ui->FL13_pushButton->text());

            if(ui->FL13_pushButton->text().toInt() == 30)
            {
                ui->FL13_pushButton->setText("25");
            }
            else if(ui->FL13_pushButton->text().toInt() == 25)
            {
                ui->FL13_pushButton->setText("20");
            }
            else
            {
                ui->FL13_pushButton->setText(QString::number(ui->FL13_pushButton->text().toInt() - 10));
            }
        }
    }
    else
    {
        if(ui->FL13_pushButton->text().toInt() != 5)
        {
            ui->FL1_pushButton->setText(ui->FL2_pushButton->text());
            ui->FL2_pushButton->setText(ui->FL3_pushButton->text());
            ui->FL3_pushButton->setText(ui->FL4_pushButton->text());
            ui->FL4_pushButton->setText(ui->FL5_pushButton->text());
            ui->FL5_pushButton->setText(ui->FL6_pushButton->text());
            ui->FL6_pushButton->setText(ui->FL7_pushButton->text());
            ui->FL7_pushButton->setText(ui->FL8_pushButton->text());
            ui->FL8_pushButton->setText(ui->FL9_pushButton->text());
            ui->FL9_pushButton->setText(ui->FL10_pushButton->text());
            ui->FL10_pushButton->setText(ui->FL11_pushButton->text());
            ui->FL11_pushButton->setText(ui->FL12_pushButton->text());
            ui->FL12_pushButton->setText(ui->FL13_pushButton->text());

            ui->FL13_pushButton->setText(QString::number(ui->FL13_pushButton->text().toInt() - 5));
        }
    }
}

void CFLWidget::five_clicked_slot()
{
    QString style1 = QString(
                "QPushButton {color: black;"
                            "font: 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);

    CFL = "";

    if(ui->five_pushButton->text().toInt() == 5)
    {
        ui->five_pushButton->setText("0");

        ui->FL13_pushButton->setText("5");
        ui->FL12_pushButton->setText(QString::number(ui->FL13_pushButton->text().toInt() + 5));
        ui->FL11_pushButton->setText(QString::number(ui->FL12_pushButton->text().toInt() + 5));
        ui->FL10_pushButton->setText(QString::number(ui->FL11_pushButton->text().toInt() + 5));
        ui->FL9_pushButton->setText(QString::number(ui->FL10_pushButton->text().toInt() + 5));
        ui->FL8_pushButton->setText(QString::number(ui->FL9_pushButton->text().toInt() + 5));
        ui->FL7_pushButton->setText(QString::number(ui->FL8_pushButton->text().toInt() + 5));
        ui->FL6_pushButton->setText(QString::number(ui->FL7_pushButton->text().toInt() + 5));
        ui->FL5_pushButton->setText(QString::number(ui->FL6_pushButton->text().toInt() + 5));
        ui->FL4_pushButton->setText(QString::number(ui->FL5_pushButton->text().toInt() + 5));
        ui->FL3_pushButton->setText(QString::number(ui->FL4_pushButton->text().toInt() + 5));
        ui->FL2_pushButton->setText(QString::number(ui->FL3_pushButton->text().toInt() + 5));
        ui->FL1_pushButton->setText(QString::number(ui->FL2_pushButton->text().toInt() + 5));
    }
    else
    {
        ui->five_pushButton->setText("5");

        ui->FL13_pushButton->setText("10");
        ui->FL12_pushButton->setText(QString::number(ui->FL13_pushButton->text().toInt() + 10));
        ui->FL11_pushButton->setText(QString("25"));
        ui->FL10_pushButton->setText(QString("30"));
        ui->FL9_pushButton->setText(QString::number(ui->FL10_pushButton->text().toInt() + 10));
        ui->FL8_pushButton->setText(QString::number(ui->FL9_pushButton->text().toInt() + 10));
        ui->FL7_pushButton->setText(QString::number(ui->FL8_pushButton->text().toInt() + 10));
        ui->FL6_pushButton->setText(QString::number(ui->FL7_pushButton->text().toInt() + 10));
        ui->FL5_pushButton->setText(QString::number(ui->FL6_pushButton->text().toInt() + 10));
        ui->FL4_pushButton->setText(QString::number(ui->FL5_pushButton->text().toInt() + 10));
        ui->FL3_pushButton->setText(QString::number(ui->FL4_pushButton->text().toInt() + 10));
        ui->FL2_pushButton->setText(QString::number(ui->FL3_pushButton->text().toInt() + 10));
        ui->FL1_pushButton->setText(QString::number(ui->FL2_pushButton->text().toInt() + 10));
    }
}

void CFLWidget::FL1_clicked_slot()
{
    CFL = ui->FL1_pushButton->text();

    QString style1 = QString(
                "QPushButton {color: black;"
                             "font: 12px 'MS Shell Dlg 2';}"
                "QPushButton#FL1_pushButton { color: black;"
                             "font: bold 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
}

void CFLWidget::FL2_clicked_slot()
{
    CFL = ui->FL2_pushButton->text();

    QString style1 = QString(
                "QPushButton {color: black;"
                             "font: 12px 'MS Shell Dlg 2';}"
                "QPushButton#FL2_pushButton { color: black;"
                             "font: bold 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
}

void CFLWidget::FL3_clicked_slot()
{
    CFL = ui->FL3_pushButton->text();

    QString style1 = QString(
                "QPushButton {color: black;"
                             "font: 12px 'MS Shell Dlg 2';}"
                "QPushButton#FL3_pushButton { color: black;"
                             "font: bold 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
}

void CFLWidget::FL4_clicked_slot()
{
    CFL = ui->FL4_pushButton->text();

    QString style1 = QString(
                "QPushButton {color: black;"
                             "font: 12px 'MS Shell Dlg 2';}"
                "QPushButton#FL4_pushButton { color: black;"
                             "font: bold 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
}

void CFLWidget::FL5_clicked_slot()
{
    CFL = ui->FL5_pushButton->text();

    QString style1 = QString(
                "QPushButton {color: black;"
                             "font: 12px 'MS Shell Dlg 2';}"
                "QPushButton#FL5_pushButton { color: black;"
                             "font: bold 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
}

void CFLWidget::FL6_clicked_slot()
{
    CFL = ui->FL6_pushButton->text();

    QString style1 = QString(
                "QPushButton {color: black;"
                             "font: 12px 'MS Shell Dlg 2';}"
                "QPushButton#FL6_pushButton { color: black;"
                             "font: bold 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
}

void CFLWidget::FL7_clicked_slot()
{
    CFL = ui->FL7_pushButton->text();

    QString style1 = QString(
                "QPushButton {color: black;"
                             "font: 12px 'MS Shell Dlg 2';}"
                "QPushButton#FL7_pushButton { color: black;"
                             "font: bold 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
}

void CFLWidget::FL8_clicked_slot()
{
    CFL = ui->FL8_pushButton->text();

    QString style1 = QString(
                "QPushButton {color: black;"
                             "font: 12px 'MS Shell Dlg 2';}"
                "QPushButton#FL8_pushButton { color: black;"
                             "font: bold 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
}

void CFLWidget::FL9_clicked_slot()
{
    CFL = ui->FL9_pushButton->text();

    QString style1 = QString(
                "QPushButton {color: black;"
                             "font: 12px 'MS Shell Dlg 2';}"
                "QPushButton#F9_pushButton { color: black;"
                             "font: bold 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
}

void CFLWidget::FL10_clicked_slot()
{
    CFL = ui->FL10_pushButton->text();

    QString style1 = QString(
                 "QPushButton {color: black;"
                              "font: 12px 'MS Shell Dlg 2';}"
                 "QPushButton#FL10_pushButton { color: black;"
                              "font: bold 12px 'MS Shell Dlg 2';}");
     setStyleSheet(style1);
}

void CFLWidget::FL11_clicked_slot()
{
    CFL = ui->FL11_pushButton->text();

    QString style1 = QString(
                "QPushButton {color: black;"
                             "font: 12px 'MS Shell Dlg 2';}"
                "QPushButton#FL11_pushButton { color: black;"
                             "font: bold 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
}

void CFLWidget::FL12_clicked_slot()
{
    CFL = ui->FL12_pushButton->text();

    QString style1 = QString(
                "QPushButton {color: black;"
                             "font: 12px 'MS Shell Dlg 2';}"
                "QPushButton#FL12_pushButton { color: black;"
                             "font: bold 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
}

void CFLWidget::FL13_clicked_slot()
{
    CFL = ui->FL13_pushButton->text();

    QString style1 = QString(
                "QPushButton {color: black;"
                             "font: 12px 'MS Shell Dlg 2';}"
                "QPushButton#FL13_pushButton { color: black;"
                             "font: bold 12px 'MS Shell Dlg 2';}");
    setStyleSheet(style1);
}

void CFLWidget::UPLINKclicked_slot()
{
    if(CFL != "")
    {
        emit CFLselection_clicked(CallSign, CFL, act_FL);
        qDebug() << CFL;
        this->close();
    }
}

void CFLWidget::CANCELclicked_slot()
{
    this->close();
}

void CFLWidget::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape)
    {
        this->close();
    }
}
