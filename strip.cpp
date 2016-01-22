#include "strip.h"
#include "ui_strip.h"
#include <QDebug>

Strip::Strip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Strip)
{
    ui->setupUi(this);

    ui->strip_7->setReadOnly(true);

    ui->strip_1->installEventFilter(this);
    ui->strip_2->installEventFilter(this);
    ui->strip_3->installEventFilter(this);
    ui->strip_4->installEventFilter(this);
    ui->strip_5->installEventFilter(this);
    ui->strip_6->installEventFilter(this);
    ui->strip_8->installEventFilter(this);
    ui->strip_9->installEventFilter(this);
    ui->strip_10->installEventFilter(this);
    ui->strip_11->installEventFilter(this);
    ui->strip_12->installEventFilter(this);

    connect(ui->strip_1, SIGNAL(textChanged()), this, SLOT(saveToSTRIP()));
    connect(ui->strip_2, SIGNAL(textChanged()), this, SLOT(saveToSTRIP()));
    connect(ui->strip_3, SIGNAL(textChanged()), this, SLOT(saveToSTRIP()));
    connect(ui->strip_4, SIGNAL(textChanged()), this, SLOT(saveToSTRIP()));
    connect(ui->strip_5, SIGNAL(textChanged()), this, SLOT(saveToSTRIP()));
    connect(ui->strip_6, SIGNAL(textChanged()), this, SLOT(saveToSTRIP()));
    connect(ui->strip_8, SIGNAL(textChanged()), this, SLOT(saveToSTRIP()));
    connect(ui->strip_9, SIGNAL(textChanged()), this, SLOT(saveToSTRIP()));
    connect(ui->strip_10, SIGNAL(textChanged()), this, SLOT(saveToSTRIP()));
    connect(ui->strip_11, SIGNAL(textChanged()), this, SLOT(saveToSTRIP()));
    connect(ui->strip_12, SIGNAL(textChanged()), this, SLOT(saveToSTRIP()));

    connect(qApp, SIGNAL(focusChanged(QWidget*,QWidget*)), this, SLOT(updateStrip_slot()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateStrip_slot()));
    //timer->start(20000);
}

Strip::~Strip()
{
    delete ui;
}

bool Strip::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->strip_1 || target == ui->strip_2 || target == ui->strip_3 || target == ui->strip_4 || target == ui->strip_5 || target == ui->strip_6 ||
            target == ui->strip_8 || target == ui->strip_9 || target == ui->strip_10 || target == ui->strip_11 || target == ui->strip_12)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if(keyEvent->key() == Qt::Key_Escape)
            {
                // do your staff here
            }
        }
    }
    return QDialog::eventFilter(target, event);
}

void Strip::setCallSign(const QString &CallSign)
{
    QStringList stripDataList = readStrip(stripDataFrom, CallSign);
    QString flightType = stripDataList.at(0);

    if(flightType == "INBOUND")
        ui->strip_7->setTextColor(QColor("red"));
    if(flightType == "OUTBOUND")
        ui->strip_7->setTextColor(QColor("blue"));
    if(flightType == "OVERFLIGHT")
        ui->strip_7->setTextColor(QColor("black"));

    ui->strip_7->setText(CallSign);
    ui->strip_7->setAlignment(Qt::AlignCenter);
    callSign = CallSign;
}

void Strip::setStripDataFileName(const QString &dataFileName)
{
    stripDataFrom = dataFileName;
}

void Strip::update()
{
    QStringList stripDataList = readStrip(stripDataFrom, callSign);
    ui->strip_1->setText(stripDataList.at(1));
    ui->strip_2->setText(stripDataList.at(2));
    ui->strip_3->setText(stripDataList.at(3));
    ui->strip_4->setText(stripDataList.at(4));
    ui->strip_5->setText(stripDataList.at(5));
    ui->strip_6->setText(stripDataList.at(6));
    ui->strip_8->setText(stripDataList.at(7));
    ui->strip_9->setText(stripDataList.at(8));
    ui->strip_10->setText(stripDataList.at(9));
    ui->strip_11->setText(stripDataList.at(10));
    ui->strip_12->setText(stripDataList.at(11));
}

void Strip::saveToSTRIP()
{
    QStringList stripDataList = readStrip(stripDataFrom, callSign);
    QString info_0 = stripDataList.at(0);
    QString info_1 = stripDataList.at(12);
    QString info_2 = stripDataList.at(13);

    QString stripInfo_1 = ui->strip_1->toPlainText();
    QString stripInfo_2 = ui->strip_2->toPlainText();
    QString stripInfo_3 = ui->strip_3->toPlainText();
    QString stripInfo_4 = ui->strip_4->toPlainText();
    QString stripInfo_5 = ui->strip_5->toPlainText();
    QString stripInfo_6 = ui->strip_6->toPlainText();
    QString stripInfo_8 = ui->strip_8->toPlainText();
    QString stripInfo_9 = ui->strip_9->toPlainText();
    QString stripInfo_10 = ui->strip_10->toPlainText();
    QString stripInfo_11 = ui->strip_11->toPlainText();
    QString stripInfo_12 = ui->strip_12->toPlainText();

    QString stripInfo = info_0 + ";" + stripInfo_1 + ";" + stripInfo_2 + ";" + stripInfo_3 + ";" + stripInfo_4 + ";" + stripInfo_5 + ";" + stripInfo_6 + ";" + stripInfo_8
            + ";" + stripInfo_9 + ";" + stripInfo_10 + ";" + stripInfo_11 + ";" + stripInfo_12 + ";" + info_1 + + ";" + info_2;

    QString wholeStripInfo = callSign + "#" + stripInfo;

    if(wholeStripInfo.contains("\n"))
    {
        qDebug() << " Obsahuje novy riadok";

        QStringList tempList = wholeStripInfo.split("\n");
        wholeStripInfo = tempList.join(" ");
    }

    QStringList stripList;

    QFile file(stripDataFrom);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading and writing.";
    }
    else
    {
        QString line;
        QTextStream stream(&file);

        while( !stream.atEnd())
        {
            line = stream.readLine();       // precita riadky postupne
            stripList.append(line);
        }
    }
    file.close();

    QString newStripLine;
    QStringList newStripList;
    QListIterator<QString> iter(stripList);
    while(iter.hasNext())
    {
        QString stripLine = iter.next();
        QStringList lineList = stripLine.split("#");
        if(lineList.at(0) == callSign)
        {
            newStripLine = wholeStripInfo;
        }
        else
            newStripLine = stripLine;

        newStripList.append(newStripLine);      // mali by tu byt uz zmenene udaje v StringListe
    }

    QFile file_2(stripDataFrom);
    if( !file_2.open( QIODevice::WriteOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file_2.fileName() << "for reading and writing.";
    }
    else
    {
        QTextStream stream(&file_2);

        QListIterator<QString> iter(newStripList);
        while(iter.hasNext())
        {
            stream << iter.next() << "\n";
        }
    }
    file_2.close();
}

void Strip::updateStrip_slot()
{
    //QTextCursor prev_cursor;
    //if(qApp->focusWidget() == ui->strip_1)
    //{
    //    prev_cursor = ui->strip_1->textCursor();
    //}

    update();

    //if(qApp->focusWidget() == ui->strip_1)
    //{
    //    ui->strip_1->setTextCursor(prev_cursor);
    //}

}

QStringList Strip::readStrip(const QString &FileName, const QString &CallSign)
{
    QStringList stripList;
    QFile file(FileName);
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open" << file.fileName() << "for reading.";
    }
    else
    {
        QString line;
        QStringList lineList;
        QTextStream stream(&file);

        while( !stream.atEnd())
        {
            line = stream.readLine();       // precita riadky postupne
            lineList = line.split("#");     // oddeli na CallSign a zbytok stripu

            if(lineList.at(0) == CallSign)  // hladam svoj CallSign
            {
                stripList = lineList.at(1).split(";");  // list celeho stripu pre danu CallSign
            }
        }
    }

    file.close();

    return stripList;
}
