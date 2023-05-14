#pragma once

#include "Creatures.h"

class Enemies : public Creatures {
private:
    double coordinateY = 100;
public:
    Enemies();

    void setCoordinatesY(double);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const override;
};

