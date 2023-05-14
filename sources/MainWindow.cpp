#include "MainWindow.h"
#include <iostream>
#include <QDebug>

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
    animation_timer_.start(20, this);
}

void MainWindow::setUpScene() {
    scene_->addItem(presenter->getModel().hero_);
    for (int i = 0; i < 10; ++i) {
        scene_->addItem(presenter->getModel().heroBullet[i]);
    }
    scene_->addItem(presenter->getModel().boss_);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (obj == view_->viewport()) {
        if (event->type() == QEvent::MouseMove) {
            auto *mouseEvent = dynamic_cast<QMouseEvent *>(event);
            presenter->getModel().hero_->setCoordinates(mouseEvent->pos());
        }
    }
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

        if (timerChange / 25 == 0 || timerChange / 25 == 7) {
            presenter->getModel().boss_->setDirection({1, -1.5});
        } else if (timerChange / 25 == 1 || timerChange / 25 == 6) {
            presenter->getModel().boss_->setDirection({-1, -1.5});
        } else if (timerChange / 25 == 2 || timerChange / 25 == 5) {
            presenter->getModel().boss_->setDirection({-1, 1.5});
        } else {
            presenter->getModel().boss_->setDirection({1, 1.5});
        }
        ++timerChange;
    }

    for (int i = 0; i < presenter->getModel().heroBullet.size(); ++i) {
        if (presenter->getModel().heroBullet[i]->x() > 1918.0) {
            scene_->removeItem(presenter->getModel().heroBullet[i]);
            presenter->getModel().updateHeroBullet(i);
            scene_->addItem(presenter->getModel().heroBullet[i]);
        }
        if (presenter->getModel().heroBullet[i]->collidesWithItem(presenter->getModel().boss_)) {
            scene_->removeItem(presenter->getModel().heroBullet[i]);
            presenter->getModel().updateHeroBullet(i);
            scene_->addItem(presenter->getModel().heroBullet[i]);
        }
    }
    presenter->getModel().updateModel();
}