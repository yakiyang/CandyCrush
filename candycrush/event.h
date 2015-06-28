#ifndef EVENT_H
#define EVENT_H

#include <QWidget>

namespace Ui {
class event;
}

class event : public QWidget
{
    Q_OBJECT

public:
    explicit event(QWidget *parent = 0);
    ~event();

private:
    Ui::event *ui;
};

#endif // EVENT_H
