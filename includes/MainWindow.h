#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimerEvent>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "Presenter.h"
#include "Graphics/GameWindows.h"
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QBasicTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>

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
    QGraphicsScene *scene_;
    QGraphicsView *view_;

    QPixmap* sceneBckgrnd;

    QMediaPlayer * m_player;
    QMediaPlaylist * m_playlist;

    Presenter *presenter;
    GameWindows *menu;

    QSet<int> pressedKeys;

    int attack = 9;
    QBasicTimer animation_timer_;
    int timerChange = 0;

    QGraphicsTextItem *bossHp = nullptr;
    QGraphicsTextItem *heroHealth = nullptr;
};


