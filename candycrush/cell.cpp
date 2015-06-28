#include "cell.h"
#include "ui_cell.h"

cell::cell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cell)
{
    ui->setupUi(this);
}

cell::~cell()
{
    delete ui;
}
