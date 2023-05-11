#include "Model.h"

Model::Model() : hero_(new Hero) {
    for (int i = 0; i < 5; ++i) {
        heroBullet.push_back(new Bullet);
        heroBullet[i]->setCoordinates({hero_->getCoordinates().x() + 25, hero_->getCoordinates().y() + 25});
    }
}

void Model::updateModel(Bullet* heroBull) {
            heroBull->setCoordinates({hero_->getCoordinates().x() + 25, hero_->getCoordinates().y() + 25});
    heroBull->setAttackBegin(heroBull->getCoordinates());
    heroBull->setAttackEnd({heroBull->getCoordinates().x() + 100, heroBull->getCoordinates().y() + 100});
}

void Model::changeHeroBullet(int pos) {
    heroBullet[pos]->setCoordinates({hero_->getCoordinates().x() + 25, hero_->getCoordinates().y() + 25});
}

void Model::deleteHeroBullet() {
    heroBullet.pop_back();
}
