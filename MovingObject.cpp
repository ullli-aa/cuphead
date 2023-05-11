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
    setPos(newCoordinates);
}

QPointF MovingObject::getCoordinates() {
    return coordinates_;
}

void MovingObject::move(double speed, QPointF direction) {
//    double lengthX = direction.x() - coordinates_.x() ;
//    double lengthY = direction.y() - coordinates_.y();

    setCoordinates(
            {coordinates_.x() + speed * direction.x(), coordinates_.y() + speed * direction.y()});
}

