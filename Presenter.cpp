#include "Presenter.h"

Presenter::Presenter(QWidget *parent) : QWidget(parent), model(Model()) {
}

void Presenter::setModelHero(Hero *hero) {
    model.hero_ = hero;
}

Model Presenter::getModel() {
    return model;
}

void Presenter::Tick() {
    ++attack;
    if(attack == 5) {
        attack = 0;
    }
}

int Presenter::getAttack() {
    return attack;
}

void Presenter::setAttack(int n) {
    attack = n;
}
