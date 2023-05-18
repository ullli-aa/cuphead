#include "Model.h"
#include <QDebug>

Model::Model() : hero_(new Hero), boss_(new Boss), bossBullet(new Bullet), firstEnemyBullet(new Bullet),
                 secondEnemyBullet(new Bullet) {
    for (int i = 0; i < 10; ++i) {
        heroBullet.push_back(new Bullet);
        heroBullet[i]->setCoordinates({-4, -4});
        heroBullet[i]->setWidth(40);
        heroBullet[i]->setHeight(16);
        auto item3 = new QPixmap(":resources/hero/chalice_shmup_3way_bullet_b_0001.png");
        *item3 = item3->scaled(80, 32);
        auto hrBull = new QGraphicsPixmapItem(*item3, heroBullet[i]);
        hrBull->setPos(-45, -16);
    }
    for (int i = 0; i < 2; ++i) {
        enemies_.push_back(new Enemies);
    }
    bossBullet->setCoordinates({boss_->getCoordinates().x() - 250, boss_->getCoordinates().y()});
    bossBullet->setSpeed(2);
    bossBullet->setWidth(180);
    bossBullet->setHeight(90);
    auto item = new QPixmap(":resources/boss/bossBullet/blimp_ha_0013.png");
    *item = item->scaled(200, 100);
    auto bossBull = new QGraphicsPixmapItem(*item, bossBullet);
    bossBull->setPos(-90, -45);

    firstEnemyBullet->setCoordinates({enemies_[0]->getCoordinates()});
    firstEnemyBullet->setSpeed(17);
    firstEnemyBullet->setWidth(30);
    firstEnemyBullet->setHeight(30);
    firstEnemyBullet->setDamage(2);
    auto item1 = new QPixmap(":resources/boss/Enemy_purple/blimp_enemy_bullet_a_0001.png");
    *item1 = item1->scaled(54, 27);
    auto frstBull = new QGraphicsPixmapItem(*item1, firstEnemyBullet);
    frstBull->setPos(-27, -13);

    secondEnemyBullet->setCoordinates({enemies_[1]->getCoordinates()});
    secondEnemyBullet->setSpeed(24);
    secondEnemyBullet->setWidth(16);
    secondEnemyBullet->setHeight(16);
    secondEnemyBullet->setDamage(4);
    auto item2 = new QPixmap(":resources/boss/Enemy_purple/blimp_enemy_bullet_a_0001.png");
    *item2 = item2->scaled(40, 20);
    auto scndBull = new QGraphicsPixmapItem(*item2, secondEnemyBullet);
    scndBull->setPos(-20, -10);
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
    heroBullet[pos]->setDirection({0,0});
}
