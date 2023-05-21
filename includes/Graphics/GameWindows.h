#pragma once

#include "qwidget.h"
#include <QGraphicsScene>

class GameWindows : public QWidget {
Q_OBJECT;
private:
    QGraphicsScene *scene_;
public:
    GameWindows(QWidget *parent, QGraphicsScene *);

    void widgetFinishGame(int);

    void widgetStartGame();

    void widgetGuide();

    void widgetPause();

signals:
    void Start();
    void Replay();
    void Continue();
};