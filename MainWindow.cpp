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
    resize(1120, 700);
    scene_->setSceneRect(0, 0, 1118, 698);
    view_->setFixedSize(1120, 700);
    view_->setScene(scene_);
    setUpScene();
    view_->setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);
    view_->viewport()->installEventFilter(this);
    this->installEventFilter(this);
    animation_timer_.start(70, this);

}

void MainWindow::setUpScene() {
    scene_->addItem(presenter->getModel().hero_);
    for (int i = 0; i < 15; ++i) {
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

//    if (event->type() == QEvent::KeyPress) {
//        if (pressedKeys.count() < 2) {
//            pressedKeys += ((QKeyEvent *) event)->key();
//        }

//        if (pressedKeys.contains(Qt::Key_A) && pressedKeys.contains(Qt::Key_S)) {
//            presenter->getModel().hero_->move(2, {-1, 1});
//        }
//        if (pressedKeys.contains(Qt::Key_D) && pressedKeys.contains(Qt::Key_S)) {
//            presenter->getModel().hero_->move(2, {1, 1});
//        }
//        if (pressedKeys.contains(Qt::Key_D) && pressedKeys.contains(Qt::Key_W)) {
//            presenter->getModel().hero_->move(2, {1, -1});
//        }

//        if (pressedKeys.count() == 2) {
//            presenter->getModel().updateModel();
//            pressedKeys -= ((QKeyEvent *) event)->key();
//        }
    }
    return false;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    auto xd = presenter->getModel().hero_->getDirection().x();
    auto yd = presenter->getModel().hero_->getDirection().y();
    if (event->key() == Qt::Key_A) {
        presenter->getModel().hero_->move(1.5, {-1, yd});
    }
    if (event->key() == Qt::Key_S) {
        presenter->getModel().hero_->move(1.5, {xd, 1});
    }
    if (event->key() == Qt::Key_D) {
        presenter->getModel().hero_->move(1.5, {1, yd});
    }
    if (event->key() == Qt::Key_W) {
        presenter->getModel().hero_->move(1.5, {xd, -1});
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    auto xd = presenter->getModel().hero_->getDirection().x();
    auto yd = presenter->getModel().hero_->getDirection().y();
    if (event->key() == Qt::Key_A || event-> key() == Qt::Key_D) {
        presenter->getModel().hero_->setDirection({0, yd});
    }
    if (event->key() == Qt::Key_W || event-> key() == Qt::Key_S) {
        presenter->getModel().hero_->setDirection({xd, 0});
    }
}

void MainWindow::timerEvent(QTimerEvent *event) {
    if (event->timerId() == animation_timer_.timerId()) {
        ++timerChange;
        if (timerChange % 5 == 0) {
            qDebug() << 2;
            widget_.Tick();
            for (int i = attack; i < 15; ++i) {
                presenter->getModel().updateModel(presenter->getModel().heroBullet[i]);
            }

            presenter->getModel().heroBullet[attack]->move(1, {100, 0});

            if (attack == 15) {
                attack = 0;
            }
            attack++;
            timerChange = 0;
        }
        repaint();
    }
}