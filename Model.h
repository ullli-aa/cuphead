#pragma once

#include "Hero.h"
#include "Bullet.h"

class Model {
public:
    Model();
    Hero* hero_;
    std::vector<Bullet*> heroBullet;

    void updateModel(Bullet*);
    void changeHeroBullet(int);
    void deleteHeroBullet();
};
