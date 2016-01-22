#ifndef RADARVIEW_H
#define RADARVIEW_H

#include <QGraphicsView>
#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <QObject>
#include <QGraphicsObject>

class RadarView : public QGraphicsView
{
    Q_OBJECT

public:
    RadarView(QWidget *parent = 0);

signals:
    //void radarPos(const double &posX, const double &posY);
    void mousePos(const QPointF &point);
    void LeftMousePos(const QPointF &point);

protected:
    virtual void wheelEvent(QWheelEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void enterEvent(QEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
};

#endif // RADARVIEW_H
