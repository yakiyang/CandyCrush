#ifndef GAME_H
#define GAME_H

#include <QDate>
#include <QTime>
#include <QtCore>
#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include<cell.h>
#include "event.h"
#include "result.h"

namespace Ui {
class game;
}

class game : public QWidget
{
     Q_OBJECT
public:
    explicit game(QWidget *parent,result *res);
    ~game();
    void Start(QWidget *parent);
    void Score(QWidget *parent);
    void Timer(QWidget *parent);
    void Connect();
private slots:
    void check(int row,int col,int sp);
    void SantaClaus(int ,char);
    void Gift(int ,char ,int );
    void Special(int ,char ,int);
    void Normal(int ,char);
    void returnChange(int ,int);
    void setNewMap();
    void delete_Special_S(int );
    void delete_Special_H(int );
    void delete_Gift(int);
    void delete_SantaClaus(int);
    void timerUpDate();
    void bb(int);
signals:
    void Close(int);
private:
    Event *ev;
    Ui::game *ui;
    result *resWindow;
    Cell* cell[9][9];
    QLabel *start[3];
    QLabel *score;
    QLabel *timelabel;
    QTimer *timer;
    QDateTime startTime;
    int st[3] ,sc;
    int count;
    int OriginRow ,OriginCol;
    QString s;

};

#endif // GAME_H
