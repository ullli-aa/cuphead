#include "GameWindows.h"
#include <QDebug>
#include <QApplication>
#include <QLabel>
#include <QPushButton>

void GameWindows::widgetFinishGame(int n) {
    if (n != 0) {
        this->setStyleSheet("background-color: lavender;");
        this->setFixedSize(1200, 800);
        if (n == 1) {
            auto *label = new QLabel("You've lost", this);
            label->setFont(QFont("Courier New", 30));
            label->move(435, 385);
        }
        if (n == 2) {
            auto *label = new QLabel("You WIN!!!!", this);
            label->setFont(QFont("Courier New", 30));
            label->move(435, 385);
        }

        auto *exit = new QPushButton("Exit", this);
        exit->resize(160, 80);
        exit->setFont(QFont("Courier New", 20));
        exit->move(235, 600);

        connect(exit, &QPushButton::clicked, this, [&] {
            qApp->exit();
        });

        auto *replay = new QPushButton("Replay", this);
        replay->resize(160, 80);
        replay->setFont(QFont("Courier New", 20));
        replay->move(735, 600);

        connect(replay, &QPushButton::clicked, this, [&] {
            close();
            emit Replay();
        });
        show();
    }

}

void GameWindows::widgetStartGame() {
    this->setStyleSheet("background-color: #CCFFFF;");
    auto *label = new QLabel("Hello my friend", this);
    label->setFont(QFont("Courier New", 30));
    label->move(705, 400);

    auto *play = new QPushButton("Play", this);
    play->resize(250, 80);
    play->setFont(QFont("Courier New", 20));
    play->move(835, 600);


    auto *exit = new QPushButton("Exit", this);
    exit->resize(250, 80);
    exit->setFont(QFont("Courier New", 20));
    exit->move(835, 700);

    connect(play, &QPushButton::clicked, this, [&] {
        close();
        emit Start();
    });

    connect(exit, &QPushButton::clicked, this, [&] {
        qApp->exit();
    });
    showFullScreen();
}

GameWindows::GameWindows(QWidget *parent, QGraphicsScene* scene) : scene_(scene) {
}

