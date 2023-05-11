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
}

void MainWindow::setUpScene() {
    scene_->addItem(presenter->getModel().hero_);
    for (int i = 0; i < 5; ++i) {
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

    if (event->type() == QEvent::KeyPress) {
        if (pressedKeys.count() < 2) {
            pressedKeys += ((QKeyEvent *) event)->key();
        }

        if (pressedKeys.contains(Qt::Key_A) || pressedKeys.contains(Qt::Key_S) || pressedKeys.contains(Qt::Key_D) ||
            pressedKeys.contains(Qt::Key_W)) {
            presenter->getModel().updateModel(presenter->getModel().heroBullet[attack]);
            pressedKeys -= ((QKeyEvent *) event)->key();
        }
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
    if (event->key() == Qt::Key_A) {
        presenter->getModel().hero_->move(1.5, {-1, 0});
    }
    if (event->key() == Qt::Key_S) {
        presenter->getModel().hero_->move(1.5, {0, 1});
    }
    if (event->key() == Qt::Key_D) {
        presenter->getModel().hero_->move(1.5, {1, 0});
    }
    if (event->key() == Qt::Key_W) {
        presenter->getModel().hero_->move(1.5, {0, -1});
    }
    if (event->key() == Qt::Key_E) {
        presenter->getModel().hero_->move(4, {1, -1});
    }
    if (event->key() == Qt::Key_Q) {
        presenter->getModel().hero_->move(4, {-1, -1});
    }

    if (event->key() == Qt::Key_Space) {
        for (int i = attack; i < 5; ++i) {
            presenter->getModel().updateModel(presenter->getModel().heroBullet[i]);
        }
        qDebug() << presenter->getModel().heroBullet.size();
        presenter->getModel().heroBullet[attack]->move(1, {100, 0});
        attack++;
        if (attack == 5) {
            attack = 0;
        }
    }
}

//void MainWindow::keyReleaseEvent(QKeyEvent *event) {
//    qDebug() << 1;
//    if (event->key() == Qt::Key_A) {
//        presenter->getModel().hero_->move(10, {-1, 0});
//    }
//    if (event->key() == Qt::Key_S) {
//        presenter->getModel().hero_->move(10, {0, 1});
//    }
//    if (event->key() == Qt::Key_D) {
//        presenter->getModel().hero_->move(10, {1, 0});
//    }
//    if (event->key() == Qt::Key_W) {
//        presenter->getModel().hero_->move(10, {0, -1});
//    }
//}

//void MainWindow::timerEvent(QTimerEvent* event) {
//    if (event->timerId() == animation_timer_.timerId()) {
//        widget_.Tick();
//
//        current_rotate_ = widget_.getRotate();
//        repaint();
//    }
//}