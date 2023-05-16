#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimerEvent>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "Presenter.h"
#include "GameWindows.h"
#include <QPainter>
#include <QImage>
#include "Presenter.h"
#include <QMouseEvent>
#include <QBasicTimer>

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget *parent = nullptr);

    void setUpScene();

    bool eventFilter(QObject *obj, QEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

    void timerEvent(QTimerEvent *event) override;

    void startGame();
private:
    QWidget* widget_ = nullptr;

    QGraphicsScene *scene_;
    QGraphicsView *view_;

    Presenter *presenter;
    GameWindows *menu;

    QSet<int> pressedKeys;

    int attack = 9;
    QBasicTimer animation_timer_;
    int timerChange = 0;

    QGraphicsTextItem *bossHp = nullptr;
    QGraphicsTextItem *heroHealth = nullptr;
};


