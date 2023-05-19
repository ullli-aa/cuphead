#include "Animation.h"
#include <QDebug>

void Animation::bossAnimation(Boss * boss, int time, std::vector<QPixmap*> pic) {
    if (boss->childItems().size() == 1) {
        qDeleteAll(boss->childItems());
    }
    *pic[time % 21] = pic[time % 21]->scaled(500, 540);
    auto item = new QGraphicsPixmapItem(*pic[time % 21], boss);
    item->setPos(-240, -240);
}

void Animation::heroAnimation(Hero* hero, int time, std::vector<QPixmap *> pic) {
    if (hero->childItems().size() == 1) {
        qDeleteAll(hero->childItems());
    }
    *pic[time % 4] = pic[time % 4]->scaled(135, 135);
    auto item = new QGraphicsPixmapItem(*pic[time % 4], hero);
    item->setPos(-75, -70);
}

void Animation::enemyAnimation(Enemies* enemy, int time, std::vector<QPixmap *> pic) {
    if (enemy->childItems().size() > 0) {
        qDeleteAll(enemy->childItems());
    }
    *pic[time % 12] = pic[time % 12]->scaled(220, 130);
    auto item = new QGraphicsPixmapItem(*pic[time % 12], enemy);
    item->setPos(-110, -65);
}
