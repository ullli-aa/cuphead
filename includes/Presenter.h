#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "Model.h"
#include "Animation.h"
#include <QMediaPlayer>

class Presenter : public QWidget {
public:
    Presenter(QWidget *parent);

    void Tick();

    Model getModel();

    int getAnimationTime() const;

    void setAnimationTime(int);

    void collidesBossBullet() const;

    void collidesHeroBullet();

    void collidesFirstEnemyBullet() const;

    void collidesSecondEnemyBullet() const;

    void collidesHero();

    void firstEnemyMoving();

    void secondEnemyMoving();

    void bossMoving() const;

    void bulletBossMoving();

    void bulletFirstEnemyMoving();

    void bulletSecondEnemyMoving();

    int finishGame() const;

    void replayModel();

    void updateAnimation();
protected:
    Model* model;
    int attackTime = 0;
    int animationTime = 0;
    Animation* animation;
    QMediaPlayer * m_player_hero_damage;
    QMediaPlayer * m_player_enemy_attack;
    QMediaPlayer * m_player_boss_attack;
};

