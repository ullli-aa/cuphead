#include "Model.h"
#include <QDebug>

Model::Model() : hero_(new Hero) {
    for (int i = 0; i < 20; ++i) {
        heroBullet.push_back(new Bullet);
        heroBullet[i]->setCoordinates({0, 0});
    }
}

void Model::updateModel() {
    for (auto & bull : heroBullet) {
        if (bull->getDirection().x() != 0) {
            bull->move(2, bull->getDirection());

            bull->setAttackBegin(bull->getCoordinates());
            bull->setAttackEnd({bull->getCoordinates().x() + 10, bull->getCoordinates().y() + 10});
        }
    }
    hero_->move(hero_->getSpeed(), hero_->getDirection());
}

void Model::changeHeroBullet(int pos) {
    Bullet* bull = new Bullet;
    bull->setCoordinates({hero_->getCoordinates().x() + 25, hero_->getCoordinates().y() + 25});
    heroBullet.push_back(bull);
}

void Model::deleteHeroBullet() {
    heroBullet.pop_back();
}
