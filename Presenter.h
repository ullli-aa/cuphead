#pragma once

#include <QWidget>
class Presenter : public QWidget{
Q_OBJECT
public:
    Presenter(QWidget* parent);
    void Tick();

};

