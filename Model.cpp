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

void Model::addHeroBullet(int pos) {
    Bullet* bull(new Bullet);
    bull->setCoordinates({0, 0});
    heroBullet.push_back(bull);
    for (size_t i = heroBullet.size(); i > pos; --i) {
        std::swap(heroBullet[i], heroBullet[i - 1]);
    }
}

void Model::deleteHeroBullet(int pos) {
    for (size_t i = pos; i + 1 < heroBullet.size(); ++i) {
        std::swap(heroBullet[i + 1], heroBullet[i]);
    }
    heroBullet.pop_back();
}

void Model::updateHeroBullet() {
    for (int i = 0; i < heroBullet.size(); ++i) {
        if(heroBullet[i]->getCoordinates().x() > 1920) {
            deleteHeroBullet(i);
            addHeroBullet(i);
        }
    }
}
