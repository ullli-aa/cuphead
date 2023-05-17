#pragma once

#include "QWidget.h"
#include <QGraphicsScene>

class GameWindows : public QWidget {
Q_OBJECT;
private:
    QGraphicsScene *scene_;
public:
    GameWindows(QWidget *parent, QGraphicsScene *);

    void widgetFinishGame(int);

    void widgetStartGame();

signals:
    void Start();
    void Replay();
};