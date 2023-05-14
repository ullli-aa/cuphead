#pragma once

#include "Hero.h"
#include "Bullet.h"
#include "Boss.h"

class Model {
public:
    Model();
    Hero* hero_;
    std::vector<Bullet*> heroBullet;
    Boss* boss_;
    Bullet* bossBullet;

    void updateModel();
    void updateHeroBullet(int);
};
