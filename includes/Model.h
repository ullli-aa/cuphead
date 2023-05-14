#pragma once

#include "Hero.h"
#include "Bullet.h"
#include "Boss.h"
#include "Enemies.h"

class Model {
public:
    Model();
    Hero* hero_;
    std::vector<Bullet*> heroBullet;
    Boss* boss_;
    Bullet* bossBullet;
    std::vector<Enemies*> enemies_;

    void updateModel();
    void updateHeroBullet(int);
};
