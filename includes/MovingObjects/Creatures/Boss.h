#pragma once

#include "Creatures.h"

class Boss : public Creatures{
private:
    int hp_ = 1000;
public:
    Boss();
    int getHp() const;
    void setHp(int);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const override;
};
