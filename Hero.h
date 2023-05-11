#pragma once

#include "Creatures.h"
#include <QRectF>

class Hero : public Creatures {
private:
    int points_;
public:
    Hero();

    int getPoints() const;

    void setPoints(int);

    void setHealth(int) override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;
};
