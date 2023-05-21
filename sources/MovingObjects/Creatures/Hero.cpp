#include "Hero.h"
#include <QPainter>

Hero::Hero() : Creatures(5) {
    speed_ = 14;
    coordinates_ = QPointF{130, 500};
    setPos(coordinates_);
    items_ = {new QPixmap(":resources/hero/Idle_straight/mugman_plane_idle_straight_0001.png"),
              new QPixmap(":resources/hero/Idle_straight/mugman_plane_idle_straight_0002.png"),
              new QPixmap(":resources/hero/Idle_straight/mugman_plane_idle_straight_0003.png"),
              new QPixmap(":resources/hero/Idle_straight/mugman_plane_idle_straight_0004.png")};

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
