#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "Model.h"

class Presenter : public QWidget {
public:
    Presenter(QWidget *parent);

    void Tick();

//    QWidget* getWidget();

    Model getModel();

    int getAttack();

    void setAttack(int);

    void collidesBossBullet() const;

    void collidesHeroBullet();

    void collidesFirstEnemyBullet() const;

    void collidesSecondEnemyBullet() const;

    void firstEnemyMoving();

    void secondEnemyMoving();

    void bossMoving() const;

    void bulletFirstEnemyMoving();

    void bulletSecondEnemyMoving();

    int finishGame() const;

    int startGame() const;

    void replayModel();
protected:
    Model* model;
    int attackTime = 0;
};

