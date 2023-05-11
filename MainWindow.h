#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimerEvent>
#include <QWidget>
#include "Presenter.h"
#include <QPainter>
#include <QImage>
#include "Presenter.h"
#include <QMouseEvent>

class MainWindow : public QMainWindow {
Q_OBJECT;
public:
    MainWindow(QWidget *parent = nullptr);

    void setUpScene();

    bool eventFilter(QObject* obj, QEvent* event) override;

    void keyPressEvent(QKeyEvent *event) override;

//    void keyReleaseEvent(QKeyEvent *event) override;
//    void timerEvent(QTimerEvent* event);
private:
    Presenter widget_;

    QGraphicsScene *scene_;
    QGraphicsView *view_;

//    QWidget* bckgrnd_;

    Presenter *presenter;

    QSet<int> pressedKeys;

    int attack = 0;
};


