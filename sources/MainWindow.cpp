#include "MainWindow.h"
#include <QDebug>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent),
          widget_(new Presenter(this)),
          scene_(new QGraphicsScene(this)),
          view_(new QGraphicsView(this)),
          presenter(new Presenter(this)) {
    resize(maximumWidth(), maximumHeight());
    scene_->setSceneRect(1, 1, 1918, 1078);
    view_->setFixedSize(1920, 1080);
    view_->setScene(scene_);
    setUpScene();
    setFocusPolicy(Qt::StrongFocus);
    view_->viewport()->installEventFilter(this);
    animation_timer_.start(25, this);
}

void MainWindow::setUpScene() {
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

    heroHp = scene_->addText(QString::number(presenter->getModel().hero_->getHp()));
    heroHp->setDefaultTextColor(QColor(Qt::darkRed));
    heroHp->setFont(QFont("Courier New", 20));
    heroHp->setPos(25, 25);

    heroHealth = scene_->addText(QString::number(presenter->getModel().hero_->getHealth()));
    heroHealth->setDefaultTextColor(QColor(Qt::darkRed));
    heroHealth->setFont(QFont("Courier New", 20));
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
}

void MainWindow::timerEvent(QTimerEvent *event) {
    if (event->timerId() == animation_timer_.timerId()) {
        if (timerChange % 8 == 0) {
            presenter->getModel().heroBullet[attack]->setCoordinates(
                    {presenter->getModel().hero_->getCoordinates().x() + 70,
                     presenter->getModel().hero_->getCoordinates().y()});
            presenter->getModel().heroBullet[attack]->setDirection({40, 0});

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

    bossMoving();
    firstEnemyMoving();
    secondEnemyMoving();
    bulletFirstEnemyMoving();
    bulletSecondEnemyMoving();

    if (timerChange % 10 < 5) {
        presenter->getModel().bossBullet->setDirection({-8, -2});
    } else {
        presenter->getModel().bossBullet->setDirection({-8, 2});
    }

    collidesHeroBullet();
    collidesBossBullet();
    collidesFirstEnemyBullet();
    collidesSecondEnemyBullet();

    heroHp->setPlainText(QString::number(presenter->getModel().hero_->getHp()));

    presenter->getModel().hero_->setHealth(presenter->getModel().hero_->getHp() / 60 + 1);
    if (presenter->getModel().hero_->getHp() == 0) {
        presenter->getModel().hero_->setHealth(0);
    }
    heroHealth->setPlainText(QString::number(presenter->getModel().hero_->getHealth()));

    presenter->getModel().updateModel();
}

void MainWindow::collidesBossBullet() {
    if (presenter->getModel().bossBullet->x() + 80 < 0) {
        scene_->removeItem(presenter->getModel().bossBullet);
        presenter->getModel().bossBullet->setCoordinates({presenter->getModel().boss_->getCoordinates().x() - 250,
                                                          presenter->getModel().boss_->getCoordinates().y()});
        scene_->addItem(presenter->getModel().bossBullet);
    }

    if (presenter->getModel().bossBullet->collidesWithItem(presenter->getModel().hero_)) {
        presenter->getModel().hero_->setHp(presenter->getModel().hero_->getHp() - 20);

        scene_->removeItem(presenter->getModel().bossBullet);
        presenter->getModel().bossBullet->setCoordinates({presenter->getModel().boss_->getCoordinates().x() - 250,
                                                          presenter->getModel().boss_->getCoordinates().y()});
        scene_->addItem(presenter->getModel().bossBullet);
    }
}

void MainWindow::collidesHeroBullet() {
    for (int i = 0; i < presenter->getModel().heroBullet.size(); ++i) {
        if (presenter->getModel().heroBullet[i]->x() > 1918.0) {
            scene_->removeItem(presenter->getModel().heroBullet[i]);
            presenter->getModel().updateHeroBullet(i);
            scene_->addItem(presenter->getModel().heroBullet[i]);
        }
        if (presenter->getModel().heroBullet[i]->collidesWithItem(presenter->getModel().boss_)) {
            presenter->getModel().boss_->setHp(presenter->getModel().boss_->getHp() - 2);
            scene_->removeItem(presenter->getModel().heroBullet[i]);
            presenter->getModel().updateHeroBullet(i);
            scene_->addItem(presenter->getModel().heroBullet[i]);
        }
        if (presenter->getModel().heroBullet[i]->collidesWithItem(presenter->getModel().firstEnemyBullet)) {
            presenter->getModel().firstEnemyBullet->setCoordinates({2010, 100});
            presenter->getModel().firstEnemyBullet->setDirection({0, 0});
        }
        if (presenter->getModel().heroBullet[i]->collidesWithItem(presenter->getModel().secondEnemyBullet)) {
            presenter->getModel().secondEnemyBullet->setCoordinates({2010, 100});
            presenter->getModel().secondEnemyBullet->setDirection({0, 0});
        }
    }
}

void MainWindow::firstEnemyMoving() {
    if (timerChange / 45 == 0) {
        presenter->getModel().enemies_[0]->setCoordinatesY(presenter->getModel().hero_->getCoordinates().y());
        presenter->getModel().enemies_[0]->setDirection({-9, 0});
    } else if (timerChange / 45 == 2) {
        presenter->getModel().enemies_[0]->setDirection({9, 0});
    } else {
        presenter->getModel().enemies_[0]->setDirection({0, 0});
    }
}

void MainWindow::secondEnemyMoving() {
    if (timerChange / 30 == 3) {
        presenter->getModel().enemies_[1]->setCoordinatesY(presenter->getModel().hero_->getCoordinates().y());
        presenter->getModel().enemies_[1]->setDirection({-11, 0});
    } else if (timerChange / 30 == 5) {
        presenter->getModel().enemies_[1]->setDirection({11, 0});
    } else {
        presenter->getModel().enemies_[1]->setDirection({0, 0});
    }
}

void MainWindow::bossMoving() {
    if (timerChange / 25 == 0 || timerChange / 25 == 7) {
        presenter->getModel().boss_->setDirection({1, -1.5});
    } else if (timerChange / 25 == 1 || timerChange / 25 == 6) {
        presenter->getModel().boss_->setDirection({-1, -1.5});
    } else if (timerChange / 25 == 2 || timerChange / 25 == 5) {
        presenter->getModel().boss_->setDirection({-1, 1.5});
    } else {
        presenter->getModel().boss_->setDirection({1, 1.5});
    }
}

void MainWindow::bulletFirstEnemyMoving() {
    if (timerChange == 45) {
        presenter->getModel().firstEnemyBullet->setCoordinates(
                {presenter->getModel().enemies_[0]->getCoordinates().x() - 60,
                 presenter->getModel().enemies_[0]->getCoordinates().y() + 60});
    }

    if (timerChange / 45 >= 1) {
        if (presenter->getModel().firstEnemyBullet->getCoordinates().x() != 2010) {
            double distance = sqrt(pow((presenter->getModel().hero_->getCoordinates().x() -
                                        presenter->getModel().firstEnemyBullet->getCoordinates().x()), 2) +
                                   pow(presenter->getModel().hero_->getCoordinates().y() -
                                       presenter->getModel().firstEnemyBullet->getCoordinates().y(), 2));

            presenter->getModel().firstEnemyBullet->setDirection(
                    {(presenter->getModel().hero_->getCoordinates().x() -
                      presenter->getModel().firstEnemyBullet->getCoordinates().x()) / distance,
                     (presenter->getModel().hero_->getCoordinates().y() -
                      presenter->getModel().firstEnemyBullet->getCoordinates().y()) / distance});
        }
    }
}

void MainWindow::bulletSecondEnemyMoving() {
    if (timerChange == 120) {
        presenter->getModel().secondEnemyBullet->setCoordinates(
                {presenter->getModel().enemies_[1]->getCoordinates().x() - 60,
                 presenter->getModel().enemies_[1]->getCoordinates().y() + 60});
    }

    if (timerChange / 30 >= 4) {
        if (presenter->getModel().secondEnemyBullet->getCoordinates().x() != 2010) {
            double distance = sqrt(pow((presenter->getModel().hero_->getCoordinates().x() -
                                        presenter->getModel().secondEnemyBullet->getCoordinates().x()), 2) +
                                   pow(presenter->getModel().hero_->getCoordinates().y() -
                                       presenter->getModel().secondEnemyBullet->getCoordinates().y(), 2));

            presenter->getModel().secondEnemyBullet->setDirection(
                    {(presenter->getModel().hero_->getCoordinates().x() -
                      presenter->getModel().secondEnemyBullet->getCoordinates().x()) / distance,
                     (presenter->getModel().hero_->getCoordinates().y() -
                      presenter->getModel().secondEnemyBullet->getCoordinates().y()) / distance});
        }
    }
}

void MainWindow::collidesFirstEnemyBullet() {
    if (presenter->getModel().firstEnemyBullet->collidesWithItem((presenter->getModel().hero_))) {
        presenter->getModel().hero_->setHp(presenter->getModel().hero_->getHp() - presenter->getModel().firstEnemyBullet->getDamage());
        presenter->getModel().firstEnemyBullet->setCoordinates({2010, 100});
        presenter->getModel().firstEnemyBullet->setDirection({0, 0});
    }
}

void MainWindow::collidesSecondEnemyBullet() {
    if (presenter->getModel().secondEnemyBullet->collidesWithItem((presenter->getModel().hero_))) {
        presenter->getModel().hero_->setHp(presenter->getModel().hero_->getHp() - presenter->getModel().secondEnemyBullet->getDamage());
        presenter->getModel().secondEnemyBullet->setCoordinates({2010, 100});
        presenter->getModel().secondEnemyBullet->setDirection({0, 0});
    }
}