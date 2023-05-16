#include "GameWindows.h"
#include <QDebug>
#include <QApplication>

void GameWindows::widgetFinishGame(int n) {
    if (n != 0) {
        this->setStyleSheet("background-color: lavender;");
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
    }
}

void GameWindows::widgetStartGame() {
    this->setStyleSheet("background-color: aqua;");
    auto *label = new QLabel("Hello my friend", this);
    label->setFont(QFont("Courier New", 30));
    label->move(435, 385);
}

GameWindows::GameWindows(QWidget *parent) {}

