#include "mytextitem.h"

const double LonScaleFactor = 250;
const double LatScaleFactor = 400;


MyTextItem::MyTextItem(QGraphicsObject *parent): QGraphicsObject(parent)
{  
    Emergency = false;
    customText = "";
    customFont = QFont("Times New Roman", 8);
    customPen = QPen(QColor(Qt::red));

    setCursor(Qt::PointingHandCursor);
}

QRectF MyTextItem::boundingRect() const
{
    QFontMetrics fm_2(customFont);
    QStringList textList = customText.split("\n");
    int h = fm_2.height() * textList.size();

    QFontMetrics fm_1(customFont);
    int w = fm_1.width(textList.at(0));

    for(int i=0; i<textList.size(); i++)
    {
        QFontMetrics fmet(customFont);
        int len = fmet.width(textList.at(i));
        if(len > w)
            w = len;
    }

    return QRectF(0,0,w,h);
}

void MyTextItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QFontMetrics fm_2(customFont);
    QStringList textList = customText.split("\n");
    int h = fm_2.height() * textList.size();

    QFontMetrics fm_1(customFont);
    int w = fm_1.width(textList.at(0));

    for(int i=0; i<textList.size(); i++)
    {
        QFontMetrics fmet(customFont);
        int len = fmet.width(textList.at(i));
        if(len > w)
            w = len;
    }

    QRectF rec = QRectF(0,0,w,h);
    QBrush brush(Qt::blue);

    //painter->fillRect(rec,brush);
    painter->setPen(customPen);
    painter->setFont(customFont);

    painter->drawText(rec, customText);
}

void MyTextItem::setCustomText(const QString &text, const QFont &font)
{
    customText = text;
    customFont = font;
}

void MyTextItem::setTextPen(const QPen &pen)
{
    customPen = pen;
}

QVariant MyTextItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if(change == QGraphicsItem::ItemSelectedChange && scene())
    {
        if(value == true)
        {
            setCustomText(customText, customFont);
            if(Emergency == true)
            {
                customPen = QPen(QColor(Qt::red));
            }
            else
            {
                customPen = QPen(QColor(255,102,0));
            }

            emit(textclicked(customText));
        }
        else
        {
            if(Emergency == true)
            {
                customPen = QPen(QColor(Qt::red));
            }
            else
            {
                customPen = QPen(QColor(Qt::green));
            }

            emit(deselectaircraft(customText));
        }
    }

    return QGraphicsItem::itemChange(change, value);
}

void MyTextItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();

    if(event->button() == Qt::RightButton)
    {
        QString CallSign = " ";
        QFontMetrics fm(customFont);
        QStringList rows = customText.split("\n");
        int h = fm.height(); // height of a single letter (font height)

        QString FLString_1 = " ";
        QString FLString_2 = " ";
        QString GSString = " ";
        QString DirectString = " ";
        int h_top, h_bottom, h_top_2, h_bottom_2, h_top_gs, h_bottom_gs, w_d, w_d2, h_top_d, h_bottom_d;
        if(rows.size() == 4)
        {
            CallSign = rows.at(1);

            FLString_1 = rows.at(2).split(" ").at(0); // find the first FL string
            FLString_2 = rows.at(3).split(" ").at(0); // find the second FL string
            h_top = h*2;
            h_bottom = h*3;
            h_top_2 = h*3;
            h_bottom_2 = h*4;

            GSString = rows.at(2).split(" ").at(1); // find the Ground Speed (GS) string
            h_top_gs = h*2;
            h_bottom_gs = h*3;

            DirectString = rows.at(3).split(" ").at(rows.at(3).split(" ").size()-1);   // find the NxtPoint of DirectPoint string
            h_top_d = h*3;
            h_bottom_d = h*4;
            w_d = fm.width(rows.at(3)) - fm.width(DirectString);
            w_d2 = fm.width(rows.at(3));
        }
        else if(rows.size() == 3)
        {
            CallSign = rows.at(0);

            FLString_1 = rows.at(1).split(" ").at(0); // find the first FL string
            FLString_2 = rows.at(2).split(" ").at(0); // find the second FL string
            h_top = h*1;
            h_bottom = h*2;
            h_top_2 = h*2;
            h_bottom_2 = h*3;

            GSString = rows.at(1).split(" ").at(1); // find the Ground Speed (GS) string
            h_top_gs = h*1;
            h_bottom_gs = h*2;

            DirectString = rows.at(2).split(" ").at(rows.at(2).split(" ").size()-1);   // find the NxtPoint of DirectPoint string
            h_top_d = h*2;
            h_bottom_d = h*3;
            w_d = fm.width(rows.at(2)) - fm.width(DirectString);
            w_d2 = fm.width(rows.at(2));
        }
        int w = fm.width(FLString_1); // width of FL string
        int w_2 = fm.width(FLString_2);
        int w_gs = fm.width(FLString_1 + " " + GSString);  // width of GS string

        if(event->pos().y() <= h_bottom && event->pos().y() >= h_top && event->pos().x() >=0 && event->pos().x() <= w)
        {
            // do something to choose CFL and overwrite STRIP.txt file
            emit CFLclicked(CallSign, FLString_2, FLString_1.mid(0,FLString_1.length()-1));
        }
        else if(event->pos().y() <= h_bottom_2 && event->pos().y() >= h_top_2 && event->pos().x() >=0 && event->pos().x() <= w_2)
        {
            // do something to choose CFL and overwrite STRIP.txt file
            emit CFLclicked(CallSign, FLString_2, FLString_1.mid(0,FLString_1.length()-1));
        }
        else if(event->pos().y() <= h_bottom_gs && event->pos().y() >= h_top_gs && event->pos().x() > w && event->pos().x() <= w_gs)
        {
            // do something with GS - show GS vector
            emit GSclicked();
        }
        else if(event->pos().y() <= h_bottom_d && event->pos().y() >= h_top_d && event->pos().x() > w_d && event->pos().x() <= w_d2)
        {
            emit DirectWPclicked(CallSign, DirectString);
        }

    }
    else
    {
       QGraphicsItem::mousePressEvent(event);
    }

}

void MyTextItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    if(event->button() == Qt::RightButton)
    {

    }
    else
    {
        QGraphicsItem::mouseReleaseEvent(event);
    }

}

void MyTextItem::emergency(const bool &status)
{
    Emergency = status;

    if(status == true)
    {
        customPen = QPen(QColor(Qt::red));
    }
    else
    {
        customPen = QPen(QColor(Qt::green));
    }
}

