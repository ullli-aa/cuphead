#pragma once

#include "qwidget.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QCheckBox>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class GameWindows : public QWidget {
Q_OBJECT;
private:
    QWidget* settingsWidget;
    bool check = false;
    QMediaPlayer * m_player;
    QMediaPlaylist * m_playlist;
public:
    GameWindows(QWidget *parent);

    void widgetFinishGame(int);

    void widgetStartGame();

    void widgetGuide();

    void widgetSettings();

    void widgetPause();

    bool getCheck() const;

signals:
    void Start();
    void Replay();
    void Continue();
    void Music();
    void First();
    void Second();
    void Third();
    void Menu();
    void Exit();
};