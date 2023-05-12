#pragma once

#include "Hero.h"
#include "Bullet.h"

class Model {
public:
    Model();
    Hero* hero_;
    std::vector<Bullet*> heroBullet;

    void updateModel();
    void updateHeroBullet();
    void addHeroBullet(int pos);
    void deleteHeroBullet(int pos);
};
