#include "MainWindow.h"
#include <QStyleOptionGraphicsItem>
#include <iostream>
#include <QDebug>
#include <QShortcut>
#include "QAction"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent),
          widget_(new Presenter(this)),
          scene_(new QGraphicsScene(this)),
          view_(new QGraphicsView(this)),
          presenter(new Presenter(this)) {
    resize(maximumWidth(), maximumHeight());
    scene_->setSceneRect(1, 1, 1919, 1079);
    view_->setFixedSize(1920, 1080);
    view_->setScene(scene_);
    setUpScene();
    view_->setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);
    view_->viewport()->installEventFilter(this);
    this->installEventFilter(this);
    animation_timer_.start(50, this);
}

void MainWindow::setUpScene() {
    scene_->addItem(presenter->getModel().hero_);
    for (int i = 0; i < 20; ++i) {
        scene_->addItem(presenter->getModel().heroBullet[i]);
    }

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
        ++timerChange;
        if (timerChange % 5 == 0) {
            presenter->getModel().heroBullet[attack]->setCoordinates(presenter->getModel().hero_->getCoordinates());
            presenter->getModel().heroBullet[attack]->setDirection({20, 0});

            if (attack == 0) {
                attack = 20;
            }
            --attack;
            timerChange = 0;
        }
        repaint();
    }

    if (presenter->getModel().heroBullet[attack]->x() > 1918) {
        scene_->removeItem(presenter->getModel().heroBullet[attack]);
        presenter->getModel().updateHeroBullet();
        scene_->addItem(presenter->getModel().heroBullet[attack]);
    }

    presenter->getModel().updateModel();
}