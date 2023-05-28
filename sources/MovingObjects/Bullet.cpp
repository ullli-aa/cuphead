#include "Bullet.h"
#include <QPainter>

Bullet::Bullet(QPointF begin, QPointF end) : MovingObject(1, {90 + 30, 350}), attackBegin_(begin), attackEnd_(end) {}

Bullet::Bullet() : attackBegin_(), attackEnd_() {}

void Bullet::setAttackBegin(QPointF begin) {
    attackBegin_ = begin;
}

void Bullet::setAttackEnd(QPointF end) {
    attackEnd_ = end;
}

void Bullet::setWidth(double width) {
    width_ = width;
}

double Bullet::getWidth() const {
    return width_;
}

void Bullet::setHeight(double height) {
    height_ = height;
}

double Bullet::getHeight() const {
    return height_;
}

int Bullet::getDamage() const {
    return damage_;
}

void Bullet::setDamage(int damage) {
    damage_ = damage;
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen({Qt::transparent, 4});
    painter->drawRect(boundingRect());
}

QRectF Bullet::boundingRect() const {
    QRectF rect(-1 * getWidth() / 2, -1 * getHeight() / 2, getWidth(), getHeight());
    return rect;
}
