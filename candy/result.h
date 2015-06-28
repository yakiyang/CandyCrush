#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include<QLabel>

namespace Ui {
class result;
}

class result : public QDialog
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = 0);
    ~result();
    void setWinner(int);
signals:
    void reset();
private slots:
    void on_pushButton_clicked();

private:
    Ui::result *ui;
    QWidget *mainWindow;
    QLabel *start[3];
};

#endif // RESULT_H
