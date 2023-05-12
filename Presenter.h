#pragma once

#include <QWidget>
#include "Model.h"

class Presenter : public QWidget {
Q_OBJECT
public:
    Presenter(QWidget* parent);
    void Tick();
    void setModelHero(Hero*);
    Model getModel();
    int getAttack();
    void setAttack(int);

private:
    Model model;
    int attack = 0;
};

