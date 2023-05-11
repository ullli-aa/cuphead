#include "Hero.h"
#include <QPainter>

Hero::Hero() : Creatures(5), points_(0){
    speed_ = 10;
    coordinates_ = QPointF{90, 350};
    setPos(coordinates_);
}

int Hero::getPoints() const {
    return points_;
}

void Hero::setPoints(int points) {
    points_ = points;
}

void Hero::setHealth(int) {
    health_ = health_ - 1;
}

void Hero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen({Qt::black, 2});
    painter->drawRect(boundingRect());
}

QRectF Hero::boundingRect() const {
    return QRectF(-25, -25, 50, 50);
}
