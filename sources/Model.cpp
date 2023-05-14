#include "Model.h"
#include <QDebug>

Model::Model() : hero_(new Hero), boss_(new Boss) {
    for (int i = 0; i < 10; ++i) {
        heroBullet.push_back(new Bullet);
        heroBullet[i]->setCoordinates({0, 0});
    }
}

void Model::updateModel() {
    for (auto &bull: heroBullet) {
        if (bull->getCoordinates().y() != 0) {
            bull->move(1.2, bull->getDirection());
            bull->setAttackBegin(bull->getCoordinates());
            bull->setAttackEnd({bull->getCoordinates().x() + 10, bull->getCoordinates().y() + 10});
        }
    }
    hero_->move(hero_->getSpeed(), hero_->getDirection());
    boss_->move(boss_->getSpeed(), boss_->getDirection());
}

void Model::addHeroBullet(int pos) {
//    auto *bull(new Bullet);
//    bull->setCoordinates({0, 0});
//    bull->setPos({0, 0});
//qDebug() << heroBullet[pos];
//    heroBullet.push_back(bull);
//    for (size_t i = heroBullet.size(); i + 1 > pos; --i) {
//        std::swap(heroBullet[i], heroBullet[i - 1]);
//    }
heroBullet[pos]->setCoordinates({-4, 0});
heroBullet[pos]->setPos({-4, 0});
}

void Model::deleteHeroBullet(int pos) {
    for (size_t i = pos; i + 1 < heroBullet.size(); ++i) {
        std::swap(heroBullet[i + 1], heroBullet[i]);
    }
    heroBullet.pop_back();
    delete heroBullet[heroBullet.size() - 1];
}

void Model::updateHeroBullet(int pos) {
//    deleteHeroBullet(pos);
    addHeroBullet(pos);
}
