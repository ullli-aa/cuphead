#include "Boss.h"
#include <QPainter>

Boss::Boss() : Creatures(5) {
    speed_ = 3;
    coordinates_ = QPointF{1520, 515};
    setPos(coordinates_);
    items_ = {new QPixmap(":resources/boss/Idle/blimp_idle_0001.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0002.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0003.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0004.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0005.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0006.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0007.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0008.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0009.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0010.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0011.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0012.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0013.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0014.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0015.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0016.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0017.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0018.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0019.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0020.png"),
              new QPixmap(":resources/boss/Idle/blimp_idle_0021.png")};
}

int Boss::getHp() const {
    return hp_;
}

void Boss::setHp(int hp) {
    hp_ = hp;
}

void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen({Qt::transparent, 3});
    painter->drawRect(boundingRect());
}

QRectF Boss::boundingRect() const {
    return QRectF(-110, -100, 220, 200).normalized();
}
