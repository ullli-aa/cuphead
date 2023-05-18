#include "Model.h"
#include <QDebug>

Model::Model() : hero_(new Hero), boss_(new Boss), bossBullet(new Bullet), firstEnemyBullet(new Bullet),
                 secondEnemyBullet(new Bullet) {
    for (int i = 0; i < 10; ++i) {
        heroBullet.push_back(new Bullet);
        heroBullet[i]->setCoordinates({-4, -4});
        heroBullet[i]->setHeight(4);
        heroBullet[i]->setWidth(50);
    }
    for (int i = 0; i < 2; ++i) {
        enemies_.push_back(new Enemies);
    }
    bossBullet->setCoordinates({boss_->getCoordinates().x() - 250, boss_->getCoordinates().y()});
    bossBullet->setSpeed(2);
    bossBullet->setWidth(200);
    bossBullet->setHeight(100);
    auto item = new QPixmap(":resources/boss/bossBullet/blimp_ha_0013.png");
    *item = item->scaled(200, 100);
    auto hero = new QGraphicsPixmapItem(*item, bossBullet);
    hero->setPos(-100, -50);

    firstEnemyBullet->setCoordinates({enemies_[0]->getCoordinates().x(), enemies_[0]->getCoordinates().y()});
    firstEnemyBullet->setSpeed(13);
    firstEnemyBullet->setHeight(30);
    firstEnemyBullet->setWidth(30);
    firstEnemyBullet->setDamage(2);

    secondEnemyBullet->setCoordinates({enemies_[1]->getCoordinates().x(), enemies_[1]->getCoordinates().y()});
    secondEnemyBullet->setSpeed(24);
    secondEnemyBullet->setHeight(16);
    secondEnemyBullet->setWidth(16);
    secondEnemyBullet->setDamage(4);
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

    for (auto &enemy: enemies_) {
        enemy->move(enemy->getSpeed(), enemy->getDirection());
    }

    firstEnemyBullet->move(firstEnemyBullet->getSpeed(), firstEnemyBullet->getDirection());
    secondEnemyBullet->move(secondEnemyBullet->getSpeed(), secondEnemyBullet->getDirection());
}

void Model::updateHeroBullet(int pos) {
    heroBullet[pos]->setCoordinates({-4, -4});
    heroBullet[pos]->setPos({-4, -4});
}
