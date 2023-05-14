#include "Hero.h"
#include <QPainter>

Hero::Hero() : Creatures(5), points_(0) {
    speed_ = 8;
    coordinates_ = QPointF{130, 500};
    setPos(coordinates_);
}

int Hero::getPoints() const {
    return points_;
}

void Hero::setPoints(int points) {
    points_ = points;
}

int Hero::getHp() const {
    return hp_;
}

void Hero::setHp(int hp) {
    hp_ = hp;
}

void Hero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen({Qt::black, 2});
    painter->drawRect(boundingRect());
}

QRectF Hero::boundingRect() const {
    return QRectF(-70, -70, 140, 140);
}
