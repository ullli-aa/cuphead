#pragma once

#include "Presenter.h"

class GameWindows : public QWidget {
public:
    GameWindows(QWidget *parent);

    void widgetFinishGame(int);

    void widgetStartGame();
};