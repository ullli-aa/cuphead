#pragma once

#include <QGraphicsItem>

class Animation {
public:
    Animation() = default;

    void bossAnimation(QGraphicsItem*, int, std::vector<QPixmap*>);

    void heroAnimation(QGraphicsItem*, int, std::vector<QPixmap*>);
};