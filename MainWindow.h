#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimerEvent>
#include <QWidget>
#include "Presenter.h"
#include <QPainter>
#include <QImage>

class MainWindow : public QMainWindow {
Q_OBJECT;
public:
    MainWindow(QWidget *parent = nullptr);
    void setUpScene();
    void paintEvent(QPaintEvent*);
//    void timerEvent(QTimerEvent* event);
private:
    Presenter widget_;

    QGraphicsScene* scene_;
    QGraphicsView* view_;

    QImage bckgrnd_;
};


