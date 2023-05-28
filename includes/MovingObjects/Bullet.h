#pragma once

#include "MovingObject.h"

class Bullet : public MovingObject {
protected:
    QPointF attackBegin_;
    QPointF attackEnd_;

    Bullet(QPointF, QPointF);

    double width_ = 4;
    double height_ = 4;
    double damage_;
public:
    Bullet();

    void setAttackBegin(QPointF);

    void setAttackEnd(QPointF);

    void setWidth(double);

    double getWidth() const;

    void setHeight(double);

    double getHeight() const;

    int getDamage() const;

    void setDamage(int);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    QRectF boundingRect() const;
};
