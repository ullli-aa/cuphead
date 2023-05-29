#include "GameWindows.h"
#include <QDebug>
#include <fstream>
#include <iostream>

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
            m_player_finish->setMedia(QUrl("qrc:/resources/sounds/game_over.wav"));
            if (check) {
                m_player_finish->stop();
            } else {
                m_player_finish->play();
            }
        }
        if (n == 2) {
            auto *label = new QLabel("You WIN!!!!", widget);
            label->setFont(QFont("Courier New", 35));
            label->move(85, 85);
            m_player_finish->setMedia(QUrl("qrc:/resources/sounds/win.wav"));
            if (check) {
                m_player_finish->stop();
            } else {
                m_player_finish->play();
            }
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
            m_player_click->play();
            m_player_finish->stop();
            close();
            emit Replay();
        });

        connect(menu, &QPushButton::clicked, widget, [&] {
            m_player_click->play();
            m_player_finish->stop();
            close();
            widgetStartGame();
            emit Menu();
        });

        connect(exit, &QPushButton::clicked, widget, [&] {
            m_player_click->play();
            emit Exit();
            qApp->exit();
        });

        showFullScreen();
        widget->setFixedSize(600, 800);
        this->resize(600, 800);
        this->move(660, 140);
    }
}

void GameWindows::widgetStartGame() {
    if (check) {
        m_player->stop();
    } else {
        m_player->play();
    }

    auto *menu_widget = new QWidget(this);
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

    auto font = QFont("Courier New", 30);
    font.setWeight(QFont::ExtraBold);

    auto *play = new QPushButton("Play", menu_widget);
    play->resize(320, 80);
    play->setFont(font);
    play->move(315, 550);
    play->setStyleSheet("background-color: white;");

    auto *settings = new QPushButton("Settings", menu_widget);
    settings->resize(320, 80);
    settings->setFont(font);
    settings->move(315, 650);
    settings->setStyleSheet("background-color: white;");

    auto *Guide = new QPushButton("Guide", menu_widget);
    Guide->resize(320, 80);
    Guide->setFont(font);
    Guide->move(315, 750);
    Guide->setStyleSheet("background-color: white;");

    auto *exit = new QPushButton("Exit", menu_widget);
    exit->resize(320, 80);
    exit->setFont(font);
    exit->move(315, 850);
    exit->setStyleSheet("background-color: white;");

    connect(play, &QPushButton::clicked, menu_widget, [&] {
        m_player_click->play();
        close();
        emit Start();
        m_player->stop();
    });

    connect(settings, &QPushButton::clicked, menu_widget, [&] {
        m_player_click->play();
        GameWindows::widgetSettings();
    });

    connect(Guide, &QPushButton::clicked, menu_widget, [&] {
        m_player_click->play();
        widgetGuide();
    });

    connect(exit, &QPushButton::clicked, menu_widget, [&] {
        emit Exit();
        m_player_click->play();
        qApp->exit();
    });
    showFullScreen();
    menu_widget->resize(1920, 1080);
}

void GameWindows::widgetGuide() {
    auto bckgrnd = new QPixmap(":resources/game_windows/menu/Guide/background.png");
    *bckgrnd = bckgrnd->scaled(1920, 1080);
    auto *label = new QLabel(guideWidget);
    label->setPixmap(*bckgrnd);

    auto font = QFont("Courier New", 30);
    font.setWeight(QFont::DemiBold);

    auto *actions = new QLabel("ACTIONS", guideWidget);
    actions->setFont(font);
    actions->move(150, 150);
    actions->setStyleSheet("background-color: transparent");

    auto *move_up = new QLabel("Move up", guideWidget);
    move_up->setFont(font);
    move_up->move(150, 300);
    move_up->setStyleSheet("background-color: transparent");

    auto *move_down = new QLabel("Move down", guideWidget);
    move_down->setFont(font);
    move_down->move(150, 375);
    move_down->setStyleSheet("background-color: transparent");

    auto *move_right = new QLabel("Move right", guideWidget);
    move_right->setFont(font);
    move_right->move(150, 450);
    move_right->setStyleSheet("background-color: transparent");

    auto *move_left = new QLabel("Move left", guideWidget);
    move_left->setFont(font);
    move_left->move(150, 525);
    move_left->setStyleSheet("background-color: transparent");

    auto *move_diagonal = new QLabel("Move diagonal", guideWidget);
    move_diagonal->setFont(font);
    move_diagonal->move(150, 600);
    move_diagonal->setStyleSheet("background-color: transparent");

    auto *speed = new QLabel("Speedup", guideWidget);
    speed->setFont(font);
    speed->move(150, 675);
    speed->setStyleSheet("background-color: transparent");

    auto *keyboard = new QLabel("KEYBOARD", guideWidget);
    keyboard->setFont(font);
    keyboard->move(700, 150);
    keyboard->setStyleSheet("background-color: transparent");

    auto *up = new QPushButton("W", guideWidget);
    up->setFont(QFont("Courier New", 20));
    up->resize(500, 50);
    up->move(700, 300);
    up->setStyleSheet(("QPushButton::pressed"
                       "{"
                       "background-color : transparent;"
                       "}"
                      ));

    auto *down = new QPushButton("S", guideWidget);
    down->setFont(QFont("Courier New", 20));
    down->resize(500, 50);
    down->move(700, 375);
    down->setStyleSheet(("QPushButton::pressed"
                         "{"
                         "background-color : transparent;"
                         "}"
                        ));

    auto *right = new QPushButton("D", guideWidget);
    right->setFont(QFont("Courier New", 20));
    right->resize(500, 50);
    right->move(700, 450);
    right->setStyleSheet(("QPushButton::pressed"
                          "{"
                          "background-color : transparent;"
                          "}"
                         ));

    auto *left = new QPushButton("A", guideWidget);
    left->setFont(QFont("Courier New", 20));
    left->resize(500, 50);
    left->move(700, 525);
    left->setStyleSheet(("QPushButton::pressed"
                         "{"
                         "background-color : transparent;"
                         "}"
                        ));

    auto *diagonal = new QPushButton("A or D + W or S", guideWidget);
    diagonal->setFont(QFont("Courier New", 20));
    diagonal->resize(500, 50);
    diagonal->move(700, 600);
    diagonal->setStyleSheet(("QPushButton::pressed"
                             "{"
                             "background-color : transparent;"
                             "}"
                            ));

    auto *speedup = new QPushButton("Shift", guideWidget);
    speedup->setFont(QFont("Courier New", 20));
    speedup->resize(500, 50);
    speedup->move(700, 675);
    speedup->setStyleSheet(("QPushButton::pressed"
                            "{"
                            "background-color : transparent;"
                            "}"
                           ));

    auto *back = new QPushButton("<< back <<", guideWidget);
    back->setFont(QFont("Courier New", 20));
    back->resize(240, 50);
    back->move(170, 50);
    back->setStyleSheet("background-color: transparent");

    connect(back, &QPushButton::clicked, guideWidget, [&] {
        m_player_click->play();
        guideWidget->close();
    });
    guideWidget->resize(1920, 1080);
    guideWidget->showFullScreen();
}

void GameWindows::widgetSettings() {
    auto bckgrnd = new QPixmap(":resources/game_windows/menu/Guide/background.png");
    *bckgrnd = bckgrnd->scaled(1920, 1080);
    auto *label = new QLabel(settingsWidget);
    label->setPixmap(*bckgrnd);

    auto font = QFont("Courier New", 30);
    font.setWeight(QFont::DemiBold);

    auto *chooseBckgrnd = new QLabel("Choose your background", settingsWidget);
    chooseBckgrnd->setFont(font);
    chooseBckgrnd->move(120, 150);
    chooseBckgrnd->setStyleSheet("background-color: transparent");

    auto *firstB = new QPushButton("1", settingsWidget);
    QPixmap pixmap1(":resources/background.png");
    QIcon ButtonIcon1(pixmap1);
    firstB->setIcon(ButtonIcon1);
    firstB->setIconSize({710, 700});
    firstB->resize(540, 400);
    firstB->move(120, 230);

    auto *secondB = new QPushButton("2", settingsWidget);
    QPixmap pixmap2(":resources/background2.png");
    QIcon ButtonIcon2(pixmap2);
    secondB->setIcon(ButtonIcon2);
    secondB->setIconSize({710, 700});
    secondB->resize(540, 400);
    secondB->move(690, 230);

    auto *thirdB = new QPushButton("3", settingsWidget);
    QPixmap pixmap3(":resources/background3.png");
    QIcon ButtonIcon3(pixmap3);
    thirdB->setIcon(ButtonIcon3);
    thirdB->setIconSize({710, 700});
    thirdB->resize(540, 400);
    thirdB->move(1260, 230);

    auto chkButton = new QCheckBox("Stop music", settingsWidget);

    chkButton->setStyleSheet("""QCheckBox::indicator { width: 30px; height: 30px;}""");
    chkButton->setFont(font);
    chkButton->move(120, 730);

    chkButton->setChecked(check);

    connect(firstB, &QPushButton::clicked, this, [this] {
        m_player_click->play();
        emit First();
    });

    connect(secondB, &QPushButton::clicked, settingsWidget, [&] {
        m_player_click->play();
        emit Second();
    });

    connect(thirdB, &QPushButton::clicked, settingsWidget, [&] {
        m_player_click->play();
        emit Third();
    });

    connect(chkButton, &QCheckBox::clicked, settingsWidget, [&] {
        m_player_click->play();
        if (!check) {
            check = true;
            m_player->stop();
        } else {
            check = false;
            m_player->play();
        }
        emit Music();
    });

    auto *back = new QPushButton("<< back <<", settingsWidget);
    back->setFont(QFont("Courier New", 20));
    back->resize(240, 50);
    back->move(140, 50);
    back->setStyleSheet("background-color: transparent");

    connect(back, &QPushButton::clicked, settingsWidget, [&] {
        m_player_click->play();
        settingsWidget->close();
    });
    settingsWidget->resize(1920, 1080);
    settingsWidget->showFullScreen();
}

void GameWindows::widgetPause() {
    auto *widget = new QWidget(this);

    auto bckgrnd = new QPixmap(":resources/game_windows/pause/pause_background.png");
    *bckgrnd = bckgrnd->scaled(600, 800);
    auto *label_bckgrnd = new QLabel(widget);
    label_bckgrnd->setPixmap(*bckgrnd);

    auto hilda_logo = new QPixmap(":resources/game_windows/pause/hilda_logo.png");
    *hilda_logo = hilda_logo->scaled(200, 200);
    auto *label_hilda = new QLabel(widget);
    label_hilda->setPixmap(*hilda_logo);
    label_hilda->move(200, -6);

    auto c_shadowEffect = new QGraphicsDropShadowEffect(widget);
    c_shadowEffect->setColor(QColor(0, 0, 0, 190));
    c_shadowEffect->setXOffset(4);
    c_shadowEffect->setYOffset(4);
    c_shadowEffect->setBlurRadius(15);

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

    auto *cont = new QPushButton("Continue", widget);
    cont->resize(300, 100);
    cont->setGraphicsEffect(c_shadowEffect);
    cont->setFont(QFont("Courier New", 27));
    cont->setStyleSheet("background-color: transparent");
    cont->move(145, 300);

    auto *menu = new QPushButton("Menu", widget);
    menu->resize(300, 100);
    menu->setGraphicsEffect(m_shadowEffect);
    menu->setFont(QFont("Courier New", 27));
    menu->setStyleSheet("background-color: transparent");
    menu->move(145, 425);

    auto *exit = new QPushButton("Exit", widget);
    exit->resize(300, 100);
    exit->setGraphicsEffect(e_shadowEffect);
    exit->setFont(QFont("Courier New", 27));
    exit->setStyleSheet("background-color: transparent");
    exit->move(145, 550);

    connect(cont, &QPushButton::clicked, widget, [&] {
        m_player_click->play();
        close();
        emit Continue();
    });

    connect(menu, &QPushButton::clicked, widget, [&] {
        m_player_click->play();
        close();
        widgetStartGame();
        emit Menu();
    });

    connect(exit, &QPushButton::clicked, widget, [&] {
        m_player_click->play();
        emit Exit();
        qApp->exit();
    });

    showFullScreen();
    widget->setFixedSize(600, 800);
    this->resize(600, 800);
    this->move(660, 140);
}

bool GameWindows::getCheck() const {
    return check;
}

GameWindows::GameWindows(QWidget *parent) :
        m_player(new QMediaPlayer(this)),
        m_playlist(new QMediaPlaylist(m_player)),
        m_player_click(new QMediaPlayer(this)),
        m_player_finish(new QMediaPlayer(this)),
        guideWidget(new QWidget()),
        settingsWidget(new QWidget()) {
    m_player->setPlaylist(m_playlist);
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    m_playlist->addMedia(QUrl("qrc:/resources/sounds/Don't_Deal_With _The_Devil.wav"));

    m_player_click->setMedia(QUrl("qrc:/resources/sounds/click.wav"));

    std::ifstream file("..\\settings.txt");

    int n;
    file >> n;
    file >> check;
    file.close();
}

