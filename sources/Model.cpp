#include "Model.h"
#include <QDebug>

Model::Model() : hero_(new Hero), boss_(new Boss), bossBullet(new Bullet) {
    for (int i = 0; i < 10; ++i) {
        heroBullet.push_back(new Bullet);
        heroBullet[i]->setCoordinates({0, 0});
        heroBullet[i]->setHeight(4);
        heroBullet[i]->setWidth(50);
    }

    for (int i = 0; i < 2; ++i) {
        enemies_.push_back(new Enemies);
    }
    bossBullet->setCoordinates({boss_->getCoordinates().x() - 250, boss_->getCoordinates().y()});
    bossBullet->setSpeed(2);
    bossBullet->setHeight(140);
    bossBullet->setWidth(160);
}

void Model::updateModel() {
    for (auto &bull: heroBullet) {
        if (bull->getCoordinates().y() != 0) {
            bull->move(1.2, bull->getDirection());
            bull->setAttackBegin(bull->getCoordinates());
            bull->setAttackEnd({bull->getCoordinates().x() + 10, bull->getCoordinates().y() + 10});
        }
    }
    bossBullet->move(bossBullet->getSpeed(), bossBullet->getDirection());
    hero_->move(hero_->getSpeed(), hero_->getDirection());
    boss_->move(boss_->getSpeed(), boss_->getDirection());

    for (auto & enemy : enemies_) {
        enemy->move(enemy->getSpeed(), enemy->getDirection());
    }
}

void Model::updateHeroBullet(int pos) {
    heroBullet[pos]->setCoordinates({-4, 0});
    heroBullet[pos]->setPos({-4, 0});
}
