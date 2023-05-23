#include "MainWindow.h"
#include <QGraphicsProxyWidget>
#include <QDebug>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent),
          scene_(new QGraphicsScene(this)),
          view_(new QGraphicsView(this)),
          presenter(new Presenter(this)),
          menu(new GameWindows(this)),
          m_player(new QMediaPlayer(this)),
          m_playlist(new QMediaPlaylist(m_player)) {
    resize(maximumWidth(), maximumHeight());
    scene_->setSceneRect(1, 1, 1918, 1078);
    view_->setFixedSize(1920, 1080);
    view_->setScene(scene_);

    sceneBckgrnd = {new QPixmap(":resources/background.png"), new QPixmap(":resources/background2.png"),
                    new QPixmap(":resources/background3.png")};

    setUpScene();
    setFocusPolicy(Qt::StrongFocus);

    view_->viewport()->installEventFilter(this);
    showFullScreen();

    m_player->setPlaylist(m_playlist);
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    m_playlist->addMedia(QUrl("qrc:/resources/sounds/Hilda_berg.wav"));

    startGame();
}

void MainWindow::setUpScene() {
    *sceneBckgrnd[0] = sceneBckgrnd[0]->scaled(1920, 1080);
    scene_->setBackgroundBrush(*sceneBckgrnd[0]);

    scene_->addItem(presenter->getModel().hero_);
    for (int i = 0; i < 10; ++i) {
        scene_->addItem(presenter->getModel().heroBullet[i]);
    }
    scene_->addItem(presenter->getModel().boss_);
    scene_->addItem(presenter->getModel().bossBullet);

    for (int i = 0; i < presenter->getModel().enemies_.size(); ++i) {
        scene_->addItem(presenter->getModel().enemies_[i]);
    }

    scene_->addItem(presenter->getModel().firstEnemyBullet);
    scene_->addItem(presenter->getModel().secondEnemyBullet);

    bossHp = scene_->addText(QString::number(presenter->getModel().boss_->getHp()));
    bossHp->setDefaultTextColor(QColor(Qt::black));
    auto font = QFont("Courier New", 20);
    font.setWeight(QFont::ExtraBold);
    bossHp->setFont(font);
    bossHp->setPos(25, 25);

    heroHealth = scene_->addText(QString::number(presenter->getModel().hero_->getHealth()));
    heroHealth->setDefaultTextColor(QColor(Qt::darkRed));
    heroHealth->setFont(font);
    heroHealth->setPos(25, 60);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
//    if (obj == view_->viewport()) {
//        if (event->type() == QEvent::MouseMove) {
//            auto *mouseEvent = dynamic_cast<QMouseEvent *>(event);
//            presenter->getModel().hero_->setCoordinates(mouseEvent->pos());
//        }
//    }
    return false;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    auto xd = presenter->getModel().hero_->getDirection().x();
    auto yd = presenter->getModel().hero_->getDirection().y();
    if (event->key() == Qt::Key_A) {
        presenter->getModel().hero_->setDirection({-1, yd});
    }
    if (event->key() == Qt::Key_S) {
        presenter->getModel().hero_->setDirection({xd, 1});
    }
    if (event->key() == Qt::Key_D) {
        presenter->getModel().hero_->setDirection({1, yd});
    }
    if (event->key() == Qt::Key_W) {
        presenter->getModel().hero_->setDirection({xd, -1});
    }
    if (event->key() == Qt::Key_Shift) {
        presenter->getModel().hero_->setSpeed(16);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    auto xd = presenter->getModel().hero_->getDirection().x();
    auto yd = presenter->getModel().hero_->getDirection().y();
    if (event->key() == Qt::Key_A || event->key() == Qt::Key_D) {
        presenter->getModel().hero_->setDirection({0, yd});
    }
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_S) {
        presenter->getModel().hero_->setDirection({xd, 0});
    }
    if (event->key() == Qt::Key_Shift) {
        presenter->getModel().hero_->setSpeed(10);
    }
    if (event->key() == Qt::Key_Escape) {
        animation_timer_.stop();
        menu->widgetPause();
    }
}

struct {
    QUrl *devil = new QUrl("qrc:/resources/sounds/Don't_Deal_With _The_Devil.wav");
    QUrl *hilda = new QUrl("qrc:/resources/sounds/Hilda_berg.wav");
} soundManager;

void MainWindow::timerEvent(QTimerEvent *event) {
    if (event->timerId() == animation_timer_.timerId()) {
        presenter->Tick();
        if (timerChange % 8 == 0) {
            presenter->getModel().heroBullet[attack]->setCoordinates(
                    {presenter->getModel().hero_->getCoordinates().x() + 70,
                     presenter->getModel().hero_->getCoordinates().y()});
            presenter->getModel().heroBullet[attack]->setDirection({30, 0});

            if (attack == 0) {
                attack = 10;
            }
            --attack;
        }

        if (timerChange == 200) {
            timerChange = 0;
        }
        ++timerChange;
    }

    presenter->bossMoving();
    presenter->firstEnemyMoving();
    presenter->secondEnemyMoving();
    presenter->bulletFirstEnemyMoving();
    presenter->bulletSecondEnemyMoving();

    if (timerChange % 10 < 5) {
        presenter->getModel().bossBullet->setDirection({-8, -2});
    } else {
        presenter->getModel().bossBullet->setDirection({-8, 2});
    }

    presenter->collidesHeroBullet();
    presenter->collidesBossBullet();
    presenter->collidesFirstEnemyBullet();
    presenter->collidesSecondEnemyBullet();
    presenter->collidesHero();

    bossHp->setPlainText(QString::number(presenter->getModel().boss_->getHp()));

    presenter->getModel().hero_->setHealth(presenter->getModel().hero_->getHp() / 60 + 1);
    if (presenter->getModel().hero_->getHp() == 300) {
        presenter->getModel().hero_->setHealth(5);
    }
    if (presenter->getModel().hero_->getHp() == 0) {
        presenter->getModel().hero_->setHealth(0);
    }
    heroHealth->setPlainText(QString::number(presenter->getModel().hero_->getHealth()));

    if (presenter->finishGame() != 0) {
        animation_timer_.stop();
        menu = new GameWindows(this);
        menu->widgetFinishGame(presenter->finishGame());
    }

    connect(menu, &GameWindows::Replay, [this]() {
        if (chkButton) {
            m_player->stop();
        } else {
            m_player->play();
        }
        presenter->replayModel();
        animation_timer_.start(20, this);
        timerChange = 0;
    });

    connect(menu, &GameWindows::Start, [this]() {
        if (chkButton) {
            m_player->stop();
        } else {
            m_player->play();
        }
        animation_timer_.stop();
        presenter->replayModel();
        animation_timer_.start(20, this);
        timerChange = 0;
    });

    connect(menu, &GameWindows::First, this, [&] {
        *sceneBckgrnd[0] = sceneBckgrnd[0]->scaled(1920, 1080);
        scene_->setBackgroundBrush(*sceneBckgrnd[0]);
    });

    connect(menu, &GameWindows::Second, this, [&] {
        *sceneBckgrnd[1] = sceneBckgrnd[1]->scaled(1920, 1080);
        scene_->setBackgroundBrush(*sceneBckgrnd[1]);
    });

    connect(menu, &GameWindows::Third, this, [&] {
        *sceneBckgrnd[2] = sceneBckgrnd[2]->scaled(1920, 1080);
        scene_->setBackgroundBrush(*sceneBckgrnd[2]);
    });

    connect(menu, &GameWindows::Music, this, [&] {
        if (!chkButton) {
            chkButton = true;
        } else {
            chkButton = false;
        }
    });

    connect(menu, &GameWindows::Continue, [this]() {
        animation_timer_.start(20, this);
    });

    connect(menu, &GameWindows::Menu, this, [&] {
        m_player->stop();
    });

    if (presenter->getAnimationTime() == 84 * 3) {
        presenter->setAnimationTime(0);
    }

    if (chkButton) {
        m_player->stop();
    }

    presenter->setAnimationTime(presenter->getAnimationTime() + 1);
    presenter->getModel().updateModel();
    presenter->updateAnimation();
}

void MainWindow::startGame() {
    animation_timer_.stop();

    menu->widgetStartGame();
    connect(menu, &GameWindows::Start, [this]() {
        m_player->play();
        animation_timer_.start(20, this);
    });
    connect(menu, &GameWindows::First, this, [&] {
        *sceneBckgrnd[0] = sceneBckgrnd[0]->scaled(1920, 1080);
        scene_->setBackgroundBrush(*sceneBckgrnd[0]);
    });

    connect(menu, &GameWindows::Second, this, [&] {
        *sceneBckgrnd[1] = sceneBckgrnd[1]->scaled(1920, 1080);
        scene_->setBackgroundBrush(*sceneBckgrnd[1]);
    });

    connect(menu, &GameWindows::Third, this, [&] {
        *sceneBckgrnd[2] = sceneBckgrnd[2]->scaled(1920, 1080);
        scene_->setBackgroundBrush(*sceneBckgrnd[2]);
    });

    connect(menu, &GameWindows::Music, this, [&] {
        if (!chkButton) {
            chkButton = true;
        } else {
            chkButton = false;
        }
    });
}