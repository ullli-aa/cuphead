#include "Presenter.h"
#include "cmath"
#include <QDebug>

Presenter::Presenter(QWidget *parent) : QWidget(parent), model(new Model()) {
}

Model Presenter::getModel() {
    return *model;
}

void Presenter::Tick() {
    ++attackTime;
    if (attackTime == 200) {
        attackTime = 0;
    }
}

int Presenter::getAttack() {
    return attackTime;
}

void Presenter::setAttack(int n) {
    attackTime = n;
}

void Presenter::collidesBossBullet() const {
    if (model->bossBullet->x() + 80 < 0) {
        model->bossBullet->setCoordinates(
                {model->boss_->getCoordinates().x() - 250, model->boss_->getCoordinates().y()});
    }

    if (model->bossBullet->collidesWithItem(model->hero_)) {
        model->hero_->setHp(model->hero_->getHp() - 20);
        model->bossBullet->setCoordinates(
                {model->boss_->getCoordinates().x() - 250, model->boss_->getCoordinates().y()});
    }
}

void Presenter::collidesHeroBullet() {
    for (int i = 0; i < model->heroBullet.size(); ++i) {
        if (model->heroBullet[i]->x() > 1918.0) {
            model->updateHeroBullet(i);
        }
        if (model->heroBullet[i]->collidesWithItem(model->boss_)) {
            model->boss_->setHp(model->boss_->getHp() - 2);
            model->updateHeroBullet(i);
        }
        if (model->heroBullet[i]->collidesWithItem(model->firstEnemyBullet)) {
            model->firstEnemyBullet->setCoordinates({2010, 100});
            model->firstEnemyBullet->setDirection({0, 0});
        }
        if (model->heroBullet[i]->collidesWithItem(model->secondEnemyBullet)) {
            model->secondEnemyBullet->setCoordinates({2010, 100});
            model->secondEnemyBullet->setDirection({0, 0});
        }
    }
}

void Presenter::collidesFirstEnemyBullet() const {
    if (model->firstEnemyBullet->collidesWithItem((model->hero_))) {
        model->hero_->setHp(model->hero_->getHp() - model->firstEnemyBullet->getDamage());
        model->firstEnemyBullet->setCoordinates({2010, 100});
        model->firstEnemyBullet->setDirection({0, 0});
    }
}

void Presenter::collidesSecondEnemyBullet() const {
    if (model->secondEnemyBullet->collidesWithItem((model->hero_))) {
        model->hero_->setHp(model->hero_->getHp() - model->secondEnemyBullet->getDamage());
        model->secondEnemyBullet->setCoordinates({2010, 100});
        model->secondEnemyBullet->setDirection({0, 0});
    }
}

void Presenter::collidesHero() {
    if(model->hero_->getCoordinates().x() < 0) {
        model->hero_->setCoordinates({0, model->hero_->getCoordinates().y()});
    } else if (model->hero_->getCoordinates().x() > 1918) {
        model->hero_->setCoordinates({1920, model->hero_->getCoordinates().y()});
    } else if (model->hero_->getCoordinates().y() < 0) {
        model->hero_->setCoordinates({model->hero_->getCoordinates().x(), 0});
    } else if (model->hero_->getCoordinates().y() > 1018) {
        model->hero_->setCoordinates({model->hero_->getCoordinates().x(), 1020});
    }

    for(auto enemy : model->enemies_) {
        if(model->hero_->collidesWithItem(enemy)) {
            model->hero_->setHp(model->hero_->getHp() - 10);
        }
    }
    if(model->hero_->collidesWithItem(model->boss_)) {
        model->hero_->setHp(0);
    }
}

void Presenter::bossMoving() const {
    if (attackTime / 25 == 0 || attackTime / 25 == 7) {
        model->boss_->setDirection({1, -1.5});
    } else if (attackTime / 25 == 1 || attackTime / 25 == 6) {
        model->boss_->setDirection({-1, -1.5});
    } else if (attackTime / 25 == 2 || attackTime / 25 == 5) {
        model->boss_->setDirection({-1, 1.5});
    } else {
        model->boss_->setDirection({1, 1.5});
    }
}

void Presenter::firstEnemyMoving() {
    if (attackTime / 45 == 0) {
        if(attackTime % 45 == 0) {
            model->enemies_[0]->setCoordinatesY(model->hero_->getCoordinates().y());
        }
        model->enemies_[0]->setDirection({-9, 0});
    } else if (attackTime / 45 == 2) {
        model->enemies_[0]->setDirection({9, 0});
    } else {
        model->enemies_[0]->setDirection({0, 0});
    }
}

void Presenter::secondEnemyMoving() {
    if (attackTime / 30 == 3) {
        if(attackTime % 30 == 0) {
            model->enemies_[1]->setCoordinatesY(model->hero_->getCoordinates().y());
        }
        model->enemies_[1]->setDirection({-11, 0});
    } else if (attackTime / 30 == 5) {
        model->enemies_[1]->setDirection({11, 0});
    } else {
        model->enemies_[1]->setDirection({0, 0});
    }
}

void Presenter::bulletFirstEnemyMoving() {
    if (attackTime == 45) {
        model->firstEnemyBullet->setCoordinates(
                {model->enemies_[0]->getCoordinates().x() - 60,
                 model->enemies_[0]->getCoordinates().y() + 20});
    }

    if (attackTime / 45 >= 1) {
        if (model->firstEnemyBullet->getCoordinates().x() != 2010) {
            double distance = sqrt(pow((model->hero_->getCoordinates().x() -
                                        model->firstEnemyBullet->getCoordinates().x()), 2) +
                                   pow(model->hero_->getCoordinates().y() -
                                       model->firstEnemyBullet->getCoordinates().y(), 2));

            model->firstEnemyBullet->setDirection(
                    {(model->hero_->getCoordinates().x() -
                      model->firstEnemyBullet->getCoordinates().x()) / distance,
                     (model->hero_->getCoordinates().y() -
                      model->firstEnemyBullet->getCoordinates().y()) / distance});
        }
    }
}

void Presenter::bulletSecondEnemyMoving() {
    if (attackTime == 120) {
        model->secondEnemyBullet->setCoordinates(
                {model->enemies_[1]->getCoordinates().x() - 60,
                 model->enemies_[1]->getCoordinates().y() + 20});
    }

    if (attackTime / 30 >= 4) {
        if (model->secondEnemyBullet->getCoordinates().x() != 2010) {
            double distance = sqrt(pow((model->hero_->getCoordinates().x() -
                                        model->secondEnemyBullet->getCoordinates().x()), 2) +
                                   pow(model->hero_->getCoordinates().y() -
                                       model->secondEnemyBullet->getCoordinates().y(), 2));

            model->secondEnemyBullet->setDirection(
                    {(model->hero_->getCoordinates().x() -
                      model->secondEnemyBullet->getCoordinates().x()) / distance,
                     (model->hero_->getCoordinates().y() -
                      model->secondEnemyBullet->getCoordinates().y()) / distance});
        }
    }
}

int Presenter::finishGame() const {
    if (model->hero_->death()) {
        return 1;
    }
    if (model->boss_->getHp() == 0) {
        return 2;
    }
    return 0;
}

void Presenter::replayModel() {
    model->hero_->setCoordinates({130, 500});
    model->hero_->setDirection({0, 0});
    model->boss_->setCoordinates({{1520, 515}});
    model->boss_->setDirection({0, 0});
    for (auto &i: model->heroBullet) {
        i->setCoordinates({-4, -4});
        i->setDirection({0, 0});
    }
    for (auto &enemy: model->enemies_) {
        enemy->setCoordinates({2025, 100});
        enemy->setDirection({0, 0});
    }
    model->bossBullet->setCoordinates({1520 - 250, 515});
    model->bossBullet->setDirection({0, 0});

    model->firstEnemyBullet->setCoordinates({2025, 100});
    model->firstEnemyBullet->setDirection({0, 0});

    model->secondEnemyBullet->setCoordinates({2025, 100});
    model->secondEnemyBullet->setDirection({0, 0});

    model->hero_->setHealth(5);
    model->hero_->setHp(300);
    model->boss_->setHp(1000);

    attackTime = 0;
}
