#pragma once

#include <QGraphicsItem>
#include "Boss.h"
#include "Hero.h"
#include "Enemies.h"

class Animation {
public:
    Animation() = default;

    void bossAnimation(Boss*, int, std::vector<QPixmap*>);

    void heroAnimation(Hero*, int, std::vector<QPixmap*>);

    void enemyAnimation(Enemies*, int, std::vector<QPixmap*>);

};