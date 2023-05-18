#include "Boss.h"
#include <QPainter>

Boss::Boss() : Creatures(5) {
    auto item = new QPixmap(":resources/boss/blimp_shoot_0001.png");
    *item = item->scaled(500, 540, Qt::IgnoreAspectRatio);
    auto boss = new QGraphicsPixmapItem(*item, this);

    boss->setPos(-240, -240);

    speed_ = 3;
    coordinates_ = QPointF{1520, 515};
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
