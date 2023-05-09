#pragma once

#include "MovingObject.h"
#include <QLineF>

class Bullet : public MovingObject {
protected:
    QPointF attackBegin_;
    QPointF attackEnd_;
    Bullet(QPointF, QPointF);
public:
    Bullet();
    QPointF getAttackBegin();
    void setAttackBegin(QPointF&);
    QPointF getAttackEnd();
    void setAttackEnd(QPointF&);
    QLineF trajectory(QPointF&, QPointF&);
};
