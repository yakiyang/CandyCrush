#include "event.h"
#include "ui_event.h"

Event::Event(QWidget *parent) :
    QWidget(parent)
{
    candy=new QLabel(parent);
    candy->setGeometry(30,0,60,60);
    candy->setAlignment(Qt::AlignCenter);
    candy->setStyleSheet("background-color: rgba(255, 255, 255, 0);"
                         "border-image: url(:/xmas_tool06_d_14.png);");

    origin=0;
}
Event::~Event(){}
void Event::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()){
    case Qt::Key_Left:
        if(origin==0)
            origin=8;
        else
            origin=origin-1;
        candy->setGeometry(30+70*origin,0,60,60);
        candy->setStyleSheet("background-color: rgba(255, 255, 255, 0);"
                             "border-image: url(:/xmas_tool06_d_14.png);");
        break;
    case Qt::Key_Right:
        if(origin==8)
            origin=0;
        else
            origin=origin+1;
        candy->setGeometry(30+70*origin,0,60,60);
        candy->setStyleSheet("background-color: rgba(255, 255, 255, 0);"
                             "border-image: url(:/xmas_tool06_d_14.png);");
        break;
    case Qt::Key_Space:
        candy->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        emit bb(origin);
        break;
    default:
        break;
    }
}

