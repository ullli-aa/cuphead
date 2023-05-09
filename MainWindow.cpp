#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent),
          widget_(new Presenter(this)),
          scene_(new QGraphicsScene(this)),
          view_(new QGraphicsView(this)) {
    view_->setScene(scene_);
    resize(1120, 700);
}

void MainWindow::setUpScene() {
    scene_->addText("hi");
    view_->setScene(scene_);
    view_->resize(1120, 700);
}

void MainWindow::paintEvent(QPaintEvent *) {
    scene_->clear();
    setUpScene();

    QPainter painter(this);
    painter.drawLine(0, 0, 200, 200);
    view_->scene()->addLine(0, 0, 200, 200);

}

//void MainWindow::timerEvent(QTimerEvent* event) {
//    if (event->timerId() == animation_timer_.timerId()) {
//        widget_.Tick();
//
//        current_rotate_ = widget_.getRotate();
//        repaint();
//    }
//}