#include "GameWindows.h"
#include <QDebug>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>

void GameWindows::widgetFinishGame(int n) {
    if (n != 0) {
        auto *widget = new QWidget(this);

        auto bckgrnd = new QPixmap(":resources/game_windows/finish/finish_background.png");
        *bckgrnd = bckgrnd->scaled(600, 800);
        auto *label_bckgrnd = new QLabel(widget);
        label_bckgrnd->setPixmap(*bckgrnd);
        if (n == 1) {
            auto *label = new QLabel("You've lost", widget);
            label->setFont(QFont("Courier New", 35));
            label->move(85, 85);
        }
        if (n == 2) {
            auto *label = new QLabel("You WIN!!!!", widget);
            label->setFont(QFont("Courier New", 35));
            label->move(85, 85);
        }

        auto r_shadowEffect = new QGraphicsDropShadowEffect(widget);
        r_shadowEffect->setColor(QColor(0, 0, 0, 190));
        r_shadowEffect->setXOffset(4);
        r_shadowEffect->setYOffset(4);
        r_shadowEffect->setBlurRadius(15);

        auto e_shadowEffect = new QGraphicsDropShadowEffect(widget);
        e_shadowEffect->setColor(QColor(0, 0, 0, 190));
        e_shadowEffect->setXOffset(4);
        e_shadowEffect->setYOffset(4);
        e_shadowEffect->setBlurRadius(15);

        auto m_shadowEffect = new QGraphicsDropShadowEffect(widget);
        m_shadowEffect->setColor(QColor(0, 0, 0, 190));
        m_shadowEffect->setXOffset(4);
        m_shadowEffect->setYOffset(4);
        m_shadowEffect->setBlurRadius(15);

        auto *replay = new QPushButton("Replay", widget);
        replay->resize(300, 100);
        replay->setFont(QFont("Courier New", 27));
        replay->setGraphicsEffect(r_shadowEffect);
        replay->setStyleSheet("background-color: transparent");
        replay->move(145, 300);

        auto *menu = new QPushButton("Menu", widget);
        menu->resize(300, 100);
        menu->setFont(QFont("Courier New", 27));
        menu->setGraphicsEffect(m_shadowEffect);
        menu->setStyleSheet("background-color: transparent");
        menu->move(145, 425);

        auto *exit = new QPushButton("Exit", widget);
        exit->resize(300, 100);
        exit->setFont(QFont("Courier New", 27));
        exit->setGraphicsEffect(e_shadowEffect);
        exit->setStyleSheet("background-color: transparent");
        exit->move(145, 550);

        connect(replay, &QPushButton::clicked, widget, [&] {
            close();
            emit Replay();
        });

        connect(menu, &QPushButton::clicked, widget, [&] {
            close();
            widgetStartGame();
        });

        connect(exit, &QPushButton::clicked, widget, [&] {
            qApp->exit();
        });

        showFullScreen();
        widget->setFixedSize(600, 800);
        this->resize(600, 800);
        this->move(660, 140);
    }
}

void GameWindows::widgetStartGame() {
    auto* menu_widget = new QWidget(this);
    this->resize(1920, 1080);
    this->move(10, 0);
    auto bckgrnd = new QPixmap(":resources/game_windows/menu/menu_background.png");
    *bckgrnd = bckgrnd->scaled(1920, 1080);
    auto *label = new QLabel(menu_widget);
    label->setPixmap(*bckgrnd);
    auto logo = new QPixmap(":resources/game_windows/menu/cuphead-logos.png");
    *logo = logo->scaled(900, 250);
    auto *label2 = new QLabel(menu_widget);
    label2->setPixmap(*logo);
    label2->move(10, 200);
    label2->setStyleSheet("background-color: transparent;");

    auto *play = new QPushButton("Play", menu_widget);
    play->resize(320, 80);
    auto font = QFont("Courier New", 30);
    font.setWeight(QFont::ExtraBold);
    play->setFont(font);
    play->move(315, 600);
    play->setStyleSheet("background-color: white;");

    auto *Guide = new QPushButton("Guide", menu_widget);
    Guide->resize(320, 80);
    Guide->setFont(font);
    Guide->move(315, 700);
    Guide->setStyleSheet("background-color: white;");


    auto *exit = new QPushButton("Exit", menu_widget);
    exit->resize(320, 80);
    exit->setFont(font);
    exit->move(315, 800);
    exit->setStyleSheet("background-color: white;");


    connect(play, &QPushButton::clicked, menu_widget, [&] {
        close();
        emit Start();
    });

    connect(Guide, &QPushButton::clicked, menu_widget, [&] {
        widgetGuide();
    });

    connect(exit, &QPushButton::clicked, menu_widget, [&] {
        qApp->exit();
    });
    showFullScreen();
    menu_widget->resize(1920, 1080);
}

void GameWindows::widgetGuide() {
    auto *widget = new QWidget;

    auto bckgrnd = new QPixmap(":resources/game_windows/menu/Guide/background.png");
    *bckgrnd = bckgrnd->scaled(1920, 1080);
    auto *label = new QLabel(widget);
    label->setPixmap(*bckgrnd);

    auto font = QFont("Courier New", 30);
    font.setWeight(QFont::DemiBold);

    auto *actions = new QLabel("ACTIONS", widget);
    actions->setFont(font);
    actions->move(150, 150);
    actions->setStyleSheet("background-color: transparent");

    auto *move_up = new QLabel("Move up", widget);
    move_up->setFont(font);
    move_up->move(150, 300);
    move_up->setStyleSheet("background-color: transparent");

    auto *move_down = new QLabel("Move down", widget);
    move_down->setFont(font);
    move_down->move(150, 375);
    move_down->setStyleSheet("background-color: transparent");

    auto *move_right = new QLabel("Move right", widget);
    move_right->setFont(font);
    move_right->move(150, 450);
    move_right->setStyleSheet("background-color: transparent");

    auto *move_left = new QLabel("Move left", widget);
    move_left->setFont(font);
    move_left->move(150, 525);
    move_left->setStyleSheet("background-color: transparent");

    auto *move_diagonal = new QLabel("Move diagonal", widget);
    move_diagonal->setFont(font);
    move_diagonal->move(150, 600);
    move_diagonal->setStyleSheet("background-color: transparent");

    auto *speed = new QLabel("Speedup", widget);
    speed->setFont(font);
    speed->move(150, 675);
    speed->setStyleSheet("background-color: transparent");

    auto *keyboard = new QLabel("KEYBOARD", widget);
    keyboard->setFont(font);
    keyboard->move(700, 150);
    keyboard->setStyleSheet("background-color: transparent");

    auto *up = new QPushButton("W", widget);
    up->setFont(QFont("Courier New", 20));
    up->resize(500, 50);
    up->move(700, 300);
    up->setStyleSheet(("QPushButton::pressed"
                       "{"
                       "background-color : transparent;"
                       "}"
                      ));

    auto *down = new QPushButton("S", widget);
    down->setFont(QFont("Courier New", 20));
    down->resize(500, 50);
    down->move(700, 375);
    down->setStyleSheet(("QPushButton::pressed"
                         "{"
                         "background-color : transparent;"
                         "}"
                        ));

    auto *right = new QPushButton("D", widget);
    right->setFont(QFont("Courier New", 20));
    right->resize(500, 50);
    right->move(700, 450);
    right->setStyleSheet(("QPushButton::pressed"
                          "{"
                          "background-color : transparent;"
                          "}"
                         ));

    auto *left = new QPushButton("A", widget);
    left->setFont(QFont("Courier New", 20));
    left->resize(500, 50);
    left->move(700, 525);
    left->setStyleSheet(("QPushButton::pressed"
                         "{"
                         "background-color : transparent;"
                         "}"
                        ));

    auto *diagonal = new QPushButton("A or D + W or S", widget);
    diagonal->setFont(QFont("Courier New", 20));
    diagonal->resize(500, 50);
    diagonal->move(700, 600);
    diagonal->setStyleSheet(("QPushButton::pressed"
                             "{"
                             "background-color : transparent;"
                             "}"
                            ));

    auto *speedup = new QPushButton("Shift", widget);
    speedup->setFont(QFont("Courier New", 20));
    speedup->resize(500, 50);
    speedup->move(700, 675);
    speedup->setStyleSheet(("QPushButton::pressed"
                            "{"
                            "background-color : transparent;"
                            "}"
                           ));

    auto *back = new QPushButton("<< back <<", widget);
    back->setFont(QFont("Courier New", 20));
    back->resize(240, 50);
    back->move(170, 50);
    back->setStyleSheet("background-color: transparent");

    connect(back, &QPushButton::clicked, [widget]() {
        widget->deleteLater();
    });
    widget->showFullScreen();
}

GameWindows::GameWindows(QWidget *parent, QGraphicsScene *scene) : scene_(scene) {}

