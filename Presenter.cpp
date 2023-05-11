#include "Presenter.h"

Presenter::Presenter(QWidget *parent) : QWidget(parent), model(Model()) {
}

void Presenter::setModelHero(Hero* hero) {
    model.hero_ = hero;
}

Model Presenter::getModel() {
    return model;
}

//void Presenter::Tick() {
//    current_rotate_ = (current_rotate_ + 1) % 360;
//}