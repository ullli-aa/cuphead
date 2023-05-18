#pragma once

#include "Creatures.h"
#include <QRectF>

class Hero : public Creatures {
private:
    int hp_ = 300;
public:
    Hero();

    int getHp() const;

    void setHp(int);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;
};
