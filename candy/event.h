#ifndef EVENT_H
#define EVENT_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include <QKeyEvent>
#include<QTimer>


class Event : public QWidget
{
    Q_OBJECT

public:
    explicit Event(QWidget *parent = 0 );
    ~Event();
    void Timer(QWidget *parent);
    void timerUpDate();
signals:
    void bb(int);
protected:
    void keyPressEvent(QKeyEvent *event);
    QLabel* candy;
    QLabel* timelabel;
    QTimer* timer;
    int origin;
    int count;


};

#endif // EVENT_H
