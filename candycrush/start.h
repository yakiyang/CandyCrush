#ifndef START_H
#define START_H

#include <QMainWindow>

namespace Ui {
class start;
}

class start : public QMainWindow
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();

private:
    Ui::start *ui;
};

#endif // START_H
