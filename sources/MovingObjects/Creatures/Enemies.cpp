#include "Enemies.h"
#include <QPainter>

Enemies::Enemies() : Creatures(1) {
    coordinates_ = {2125, coordinateY};
    setPos({2125, coordinateY});
    speed_ = 8;
    direction_ = {0, 0};
    items_ = {new QPixmap(":resources/Enemy_purple/Idle/b_blimp_enemy_idle_0001.png"),
              new QPixmap(":resources/Enemy_purple/Idle/b_blimp_enemy_idle_0002.png"),
              new QPixmap(":resources/Enemy_purple/Idle/b_blimp_enemy_idle_0003.png"),
              new QPixmap(":resources/Enemy_purple/Idle/b_blimp_enemy_idle_0004.png"),
              new QPixmap(":resources/Enemy_purple/Idle/b_blimp_enemy_idle_0005.png"),
              new QPixmap(":resources/Enemy_purple/Idle/b_blimp_enemy_idle_0006.png"),
              new QPixmap(":resources/Enemy_purple/Idle/b_blimp_enemy_idle_0007.png"),
              new QPixmap(":resources/Enemy_purple/Idle/b_blimp_enemy_idle_0008.png"),
              new QPixmap(":resources/Enemy_purple/Idle/b_blimp_enemy_idle_0009.png"),
              new QPixmap(":resources/Enemy_purple/Idle/b_blimp_enemy_idle_0010.png"),
              new QPixmap(":resources/Enemy_purple/Idle/b_blimp_enemy_idle_0011.png"),
              new QPixmap(":resources/Enemy_purple/Idle/b_blimp_enemy_idle_0012.png")};

    items_back = {new QPixmap{":resources/Enemy_purple/Idle_back/b_blimp_enemy_idle_back_0001.png"},
                  new QPixmap{":resources/Enemy_purple/Idle_back/b_blimp_enemy_idle_back_0002.png"},
                  new QPixmap{":resources/Enemy_purple/Idle_back/b_blimp_enemy_idle_back_0003.png"},
                  new QPixmap{":resources/Enemy_purple/Idle_back/b_blimp_enemy_idle_back_0004.png"},
                  new QPixmap{":resources/Enemy_purple/Idle_back/b_blimp_enemy_idle_back_0005.png"},
                  new QPixmap{":resources/Enemy_purple/Idle_back/b_blimp_enemy_idle_back_0006.png"},
                  new QPixmap{":resources/Enemy_purple/Idle_back/b_blimp_enemy_idle_back_0007.png"},
                  new QPixmap{":resources/Enemy_purple/Idle_back/b_blimp_enemy_idle_back_0008.png"},
                  new QPixmap{":resources/Enemy_purple/Idle_back/b_blimp_enemy_idle_back_0009.png"},
                  new QPixmap{":resources/Enemy_purple/Idle_back/b_blimp_enemy_idle_back_0010.png"},
                  new QPixmap{":resources/Enemy_purple/Idle_back/b_blimp_enemy_idle_back_0011.png"},
                  new QPixmap{":resources/Enemy_purple/Idle_back/b_blimp_enemy_idle_back_0012.png"}};
}

void Enemies::setCoordinatesY(double y) {
    setCoordinates({getCoordinates().x(), y});
    setPos({getCoordinates().x(), y});
}

std::vector<QPixmap*> Enemies::getItemsBack() {
    return items_back;
}

void Enemies::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen({Qt::transparent, 2});
    painter->drawEllipse(boundingRect());
}

QRectF Enemies::boundingRect() const {
    QRectF rect(QRectF(-50, -50, 100, 100));
    return rect;
}

