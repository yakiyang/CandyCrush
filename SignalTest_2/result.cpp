#include "result.h"
#include "ui_result.h"

result::result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
}

result::~result()
{
    delete ui;
}
void result::setWinner(int sc)
{
        if(sc>1000)
            ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 0);"
                                     "border-image: url(:/xmas_tool02_d_04.png);");
        else
            ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 0);"
                                     "border-image: url(:/start1.png);");
        if(sc>1500)
            ui->label_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);"
                                     "border-image: url(:/xmas_tool02_d_04.png);");
        else
            ui->label_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);"
                                     "border-image: url(:/start1.png);");
        if(sc>2000)
            ui->label_3->setStyleSheet("background-color: rgba(255, 255, 255, 0);"
                                     "border-image: url(:/xmas_tool02_d_04.png);");
        else
            ui->label_3->setStyleSheet("background-color: rgba(255, 255, 255, 0);"
                                     "border-image: url(:/start1.png);");

        ui->label_4->setAlignment(Qt::AlignCenter);
        ui->label_4->setText(QString::number(sc));
}
void result::on_pushButton_clicked()
{
    emit reset();
}

