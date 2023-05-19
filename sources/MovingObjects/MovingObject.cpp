#include "MovingObject.h"

#include <utility>

MovingObject::MovingObject(double sp, QPointF coord) {
    speed_ = sp;
    coordinates_ = coord;
}

MovingObject::MovingObject() : speed_(), coordinates_() {}

double MovingObject::getSpeed() {
    return speed_;
}

void MovingObject::setSpeed(double speed) {
    speed_ = speed;
}

void MovingObject::setCoordinates(QPointF newCoordinates) {
    coordinates_ = newCoordinates;
    setPos(newCoordinates);
}

QPointF MovingObject::getCoordinates() {
    return coordinates_;
}

void MovingObject::setDirection(QPointF direction) {
    direction_ = direction;
}

QPointF MovingObject::getDirection() {
    return direction_;
}

std::vector<QPixmap *> MovingObject::getItems() {
    return items_;
}

void MovingObject::setItems(std::vector<QPixmap *> items) {
    items_ = std::move(items);
}

void MovingObject::move(double speed, QPointF direction) {
    setCoordinates(
            {coordinates_.x() + speed * direction.x(), coordinates_.y() + speed * direction.y()});
}

