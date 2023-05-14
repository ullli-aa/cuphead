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

QLineF Bullet::trajectory(QPointF begin, QPointF end) {
    QLineF line(begin, end);
    return line;
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen({Qt::red, 4});
    painter->drawRect(boundingRect());
}

QRectF Bullet::boundingRect() const {
    QRectF rect(-1 * getWidth() / 2, -1 * getHeight() / 2, getWidth(), getHeight());
    return rect;
}
