#include "MovingObject.h"

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
}

QPointF MovingObject::getCoordinates() {
    return coordinates_;
}

void MovingObject::move() {
    move(speed_, coordinates_);
}

void MovingObject::move(double speed, QPointF direction) {
    double lengthX = coordinates_.x() - direction.x();
    double lengthY = coordinates_.y() - direction.y();

    setCoordinates({coordinates_.x() + speed * lengthX, coordinates_.y() + speed * lengthY});
}

