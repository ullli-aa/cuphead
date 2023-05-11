#pragma once

#include "MovingObject.h"

class Creatures : public MovingObject {
protected:
    int health_;

    explicit Creatures(int);

public:
    Creatures();

    int getHealth() const;

    virtual void setHealth(int);

    bool death();

    bool isAlive();
};
