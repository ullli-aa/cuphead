#include "Bullet.h"
#include <QPainter>

Bullet::Bullet(QPointF begin, QPointF end) : MovingObject(1, {90 + 30, 350}), attackBegin_(begin), attackEnd_(end) {}

Bullet::Bullet() : attackBegin_(), attackEnd_() {}

QPointF Bullet::getAttackBegin() {
    return attackBegin_;
}

void Bullet::setAttackBegin(QPointF begin) {
    attackBegin_ = begin;
}

QPointF Bullet::getAttackEnd() {
    return attackEnd_;
}

void Bullet::setAttackEnd(QPointF end) {
    attackEnd_ = end;
}

QLineF Bullet::trajectory(QPointF begin, QPointF end) {
    return QLineF(begin, end);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen({Qt::red, 4});
    painter->drawRect(boundingRect());
}

QRectF Bullet::boundingRect() const {
    return QRectF(-25, -2, 50, 4);
}
