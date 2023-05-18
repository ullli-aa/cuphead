#pragma once

#include "Creatures.h"
#include <QPainterPath>

class Boss : public Creatures{
private:
    int hp_ = 1000;
    QPainterPath path;
public:
    Boss();
    int getHp() const;
    void setHp(int);

    QPainterPath getPath();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const override;
};
