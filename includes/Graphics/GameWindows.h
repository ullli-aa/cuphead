#pragma once

#include "qwidget.h"
#include <QGraphicsScene>

class GameWindows : public QWidget {
Q_OBJECT;
public:
    GameWindows(QWidget *parent, QGraphicsScene *);

    void widgetFinishGame(int);

    void widgetStartGame();

    void widgetGuide();

    void widgetSettings();

    void widgetPause();

signals:
    void Start();
    void Replay();
    void Continue();
    void First();
    void Second();
    void Third();
};