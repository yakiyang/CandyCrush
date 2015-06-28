#ifndef START_H
#define START_H

#include <QMainWindow>
#include "game.h"
#include "result.h"
namespace Ui {
class start;
}

class start : public QMainWindow
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();
private slots:
    void resetGame();
private:
    Ui::start *ui;
    game *Game;
    result *resDialog;
};

#endif // START_H
