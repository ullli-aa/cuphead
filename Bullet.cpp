#include "Bullet.h"

Bullet::Bullet(QPointF begin, QPointF end) : attackBegin_(begin), attackEnd_(end) {}

Bullet::Bullet() : attackBegin_(), attackEnd_() {}

QPointF Bullet::getAttackBegin() {
    return attackBegin_;
}

void Bullet::setAttackBegin(QPointF& begin) {
    attackBegin_ = begin;
}

QPointF Bullet::getAttackEnd() {
    return attackEnd_;
}

void Bullet::setAttackEnd(QPointF& end) {
    attackEnd_ = end;
}

QLineF Bullet::trajectory(QPointF& begin, QPointF& end) {
    return QLineF(begin, end);
}
