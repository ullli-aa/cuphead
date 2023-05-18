#include "Boss.h"
#include <QPainter>

Boss::Boss() : Creatures(5) {
    speed_ = 10;
    coordinates_ = QPointF{1520, 515};
    setPos(coordinates_);
}

int Boss::getHp() const {
    return hp_;
}

void Boss::setHp(int hp) {
    hp_ = hp;
}

QPainterPath Boss::getPath() {
    return path;
}

void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen({Qt::transparent, 3});
    painter->drawRect(boundingRect());
}

QRectF Boss::boundingRect() const {
    return QRectF(-110, -100, 220, 200).normalized();
}
