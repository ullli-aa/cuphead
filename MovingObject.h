#pragma once

#include <QPointF>
#include <QGraphicsItem>

class MovingObject : public QGraphicsItem {
protected:
    double speed_;
    QPointF coordinates_;
    QPointF direction_;
public:
    MovingObject(double, QPointF);

    MovingObject();

    double getSpeed();
    void setSpeed(double);
    void setCoordinates(QPointF);
    QPointF getCoordinates();
    void setDirection(QPointF);
    QPointF getDirection();

    void move(double , QPointF);
};
