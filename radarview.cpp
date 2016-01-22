#include "radarview.h"

RadarView::RadarView(QWidget *parent) : QGraphicsView(parent)
{
    setMouseTracking(true);
}

void RadarView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;

    if(event->modifiers().testFlag(Qt::ControlModifier))
    {
        if(event->delta() > 0)
        {
            scale(scaleFactor, scaleFactor);
        }

        else
        {
            scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }
    }

    emit customContextMenuRequested(QPoint(0,0));
}

void RadarView::mousePressEvent(QMouseEvent *event)
{
    viewport()->setCursor(Qt::CrossCursor);

    if(event->button() == Qt::RightButton)
    {
        emit mousePos(QPointF(mapToGlobal(event->pos())));
    }
    else if(event->button() == Qt::LeftButton)
    {
        emit LeftMousePos(QPointF(mapToGlobal(event->pos())));
    }

    QGraphicsView::mousePressEvent(event);
}

void RadarView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
    viewport()->setCursor(Qt::CrossCursor);
}

void RadarView::enterEvent(QEvent *event)
{
    viewport()->setCursor(Qt::CrossCursor);
}


void RadarView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    //emit radarPos(event->pos().x(), event->pos().y());
}

