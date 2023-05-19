#pragma once

#include "Creatures.h"

class Enemies : public Creatures {
private:
    double coordinateY = 100;
    std::vector<QPixmap *> items_back;
public:
    Enemies();

    void setCoordinatesY(double);

    std::vector<QPixmap *> getItemsBack();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const override;
};

