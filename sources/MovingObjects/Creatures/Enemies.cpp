#include "Enemies.h"
#include <QPainter>
Enemies::Enemies() : Creatures(1) {
    auto item = new QPixmap(":resources/boss/Enemy_purple/b_blimp_enemy_idle_0005.png");
    *item = item->scaled(220, 130);
    auto enemy = new QGraphicsPixmapItem(*item, this);
    enemy->setPos(-110, -65);

    coordinates_ = {2125, coordinateY};
    setPos({2125, coordinateY});
    speed_ = 8;
    direction_ = {0, 0};
}

void Enemies::setCoordinatesY(double y) {
    setCoordinates({getCoordinates().x(), y});
    setPos({getCoordinates().x(), y});
}

void Enemies::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen({Qt::transparent, 2});
    painter->drawEllipse(boundingRect());
}

QRectF Enemies::boundingRect() const {
    QRectF rect(QRectF(-50, -50, 100, 100));
    return rect;
}

