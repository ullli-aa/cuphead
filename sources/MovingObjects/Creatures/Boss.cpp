#include "Boss.h"
#include <QPainter>

Boss::Boss() : Creatures(5) {
    speed_ = 3;
    coordinates_ = QPointF{1520, 515};
}

int Boss::getHp() const {
    return hp_;
}

void Boss::setHp(int hp) {
    hp_ = hp;
}

void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen({Qt::magenta, 3});
    painter->drawRect(boundingRect());
}

QRectF Boss::boundingRect() const {
    return QRectF(-250, -270, 500, 540);
}
