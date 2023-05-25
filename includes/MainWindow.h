#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimerEvent>
#include "Presenter.h"
#include "Graphics/GameWindows.h"
#include <QMouseEvent>
#include <QBasicTimer>
#include <QtMultimedia>

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

    std::vector<QPixmap*> sceneBckgrnd;

    QMediaPlayer * m_player;
    QMediaPlaylist * m_playlist;

    Presenter *presenter;
    GameWindows *menu;

    QSet<int> pressedKeys;

    int bckgr = 0;

    int attack = 9;
    QBasicTimer animation_timer_;
    int timerChange = 0;

    QGraphicsTextItem *bossHp = nullptr;
    QGraphicsTextItem *heroHealth = nullptr;
};


