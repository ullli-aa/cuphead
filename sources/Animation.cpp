#include "Animation.h"

void Animation::bossAnimation(QGraphicsItem * boss, int time, std::vector<QPixmap*> pic) {
    if (boss->childItems().size() == 1) {
        qDeleteAll(boss->childItems());
    }
    *pic[time % 21] = pic[time % 21]->scaled(500, 540);
    auto item = new QGraphicsPixmapItem(*pic[time % 21], boss);
    item->setPos(-240, -240);
}

void Animation::heroAnimation(QGraphicsItem* hero, int time, std::vector<QPixmap *> pic) {
    if (hero->childItems().size() == 1) {
        qDeleteAll(hero->childItems());
    }
    *pic[time % 2] = pic[time % 2]->scaled(135, 135);
    auto item = new QGraphicsPixmapItem(*pic[time % 2], hero);
    item->setPos(-75, -70);
}