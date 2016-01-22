#ifndef MYTEXTITEM_H
#define MYTEXTITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include <QVariant>
#include <QObject>
#include <QCursor>
#include <QtGui>
#include <QtCore>

class MyTextItem : public QGraphicsObject
{
    Q_OBJECT

public:
    MyTextItem(QGraphicsObject *parent = NULL);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool Selected;
    bool Emergency;
    QString customText;
    QFont customFont;
    QPen customPen;

    void setCustomText(const QString &text, const QFont &font);
    void setTextPen(const QPen &pen);
    void emergency(const bool &status);

    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private slots:


signals:
    void textclicked(const QString &text);
    void deselectaircraft(const QString &text);
    void GSclicked();
    void CFLclicked(const QString &callsign, const QString &actual_CFL, const QString &actual_FL);
    void DirectWPclicked(const QString &callsign, const QString &actual_wp);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);





};

#endif // MYTEXTITEM_H
