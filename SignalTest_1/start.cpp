#include "start.h"
#include "ui_start.h"

start::start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
    resDialog=new result;
    Game=new game(this,resDialog);
    connect(resDialog,SIGNAL(reset()),this,SLOT(resetGame()));
    this->setCentralWidget(Game);
}

start::~start()
{
    delete ui;
}

void start::resetGame()
{
    resDialog->hide();
    if(Game!=NULL){
        delete Game;
    }
    Game=new game(this,resDialog);
    this->setCentralWidget(Game);
}


