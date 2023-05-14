#include "Enemies.h"
#include <QPainter>
Enemies::Enemies() : Creatures(1) {
    coordinates_ = {2000, coordinateY};
    setPos({2000, coordinateY});
    speed_ = 3;
    direction_ = {0, 0};
}

void Enemies::setCoordinatesY(double y) {
    setCoordinates({getCoordinates().x(), y});
    setPos({getCoordinates().x(), y});
}

void Enemies::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen({Qt::blue, 2});
    painter->drawEllipse(boundingRect());
}

QRectF Enemies::boundingRect() const {
    QRectF rect(QRectF(-70, -70, 140, 140));
    return rect;
}

