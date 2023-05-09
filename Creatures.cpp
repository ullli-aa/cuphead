#include "Creatures.h"

Creatures::Creatures(int health) : health_(health) {}

int Creatures::getHealth() const {
    return health_;
}

bool Creatures::death() {
    if (isAlive()) {
        return false;
    }
    return true;
}

bool Creatures::isAlive() {
    if (health_ > 0) {
        return true;
    }
    return false;
}

Creatures::Creatures() {}
