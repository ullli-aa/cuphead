#include "Hero.h"
#include <QPainter>

Hero::Hero() : Creatures(5) {
    auto item = new QPixmap(":resources/hero/Idle_straight/mugman_plane_idle_straight_0001.png");
    *item = item->scaled(135, 135);
    auto hero = new QGraphicsPixmapItem(*item, this);
    hero->setPos(-75, -70);
    speed_ = 17;
    coordinates_ = QPointF{130, 500};
    setPos(coordinates_);
}

int Hero::getHp() const {
    return hp_;
}

void Hero::setHp(int hp) {
    hp_ = hp;
}

void Hero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen({Qt::transparent, 2});
    painter->drawRect(boundingRect());
}

QRectF Hero::boundingRect() const {
    return QRectF(-60, -60, 120, 120);
}
