#pragma once

#include <QPointF>
#include <QGraphicsItem>

class MovingObject : public QGraphicsItem {
protected:
    double speed_;
    QPointF coordinates_;
public:
    MovingObject(double, QPointF);

    MovingObject();

    double getSpeed();
    void setSpeed(double);
    void setCoordinates(QPointF);
    QPointF getCoordinates();

    void move();
    void move(double , QPointF);
};
