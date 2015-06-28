#include "game.h"
#include "ui_game.h"
game::game(QWidget *parent, result *res) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    Start(parent);
    Score(parent);
    Timer(parent);
    Connect();
    OriginRow=0;
    OriginCol=0;
    resWindow=res;

    ev=new Event(this);
    ev->setFont(QFont("Courier New", 25, QFont::Bold));
    ev->setFocus();
    connect(ev,SIGNAL(bb(int)),this,SLOT(bb(int)));
}
game::~game()
{
    delete ui;
}
void game::Start(QWidget *parent)
{
    for(int i=0;i<3;i++)
    {
        start[i]=new QLabel(parent);
        start[i]->setGeometry(670+i*75,260,60,60);
        start[i]->setAlignment(Qt::AlignCenter);
        start[i]->setStyleSheet("background-color: rgba(255, 255, 255, 0);"
                                "border-image: url(:/start1.png);");
    }
}
void game::Score(QWidget *parent)
{
    sc=0;
    score=new QLabel(parent);
    score->setGeometry(750,340,100,60);
    score->setAlignment(Qt::AlignLeft);
    score->setStyleSheet("font-size : 28px;"
                         "background-color: rgba(255, 255, 255, 0);"
                         "selection-color: rgb(255, 255, 255);"
                         "color: rgb(255, 255, 255);");
    s = s.setNum(sc);
    score->setText(s);
}
void game::Timer(QWidget *parent)
{
    count=295;
    timelabel=new QLabel(parent);
    timelabel->setGeometry(620,25,200,40);
    timelabel->setAlignment(Qt::AlignRight);
    timelabel->setStyleSheet("font-size : 24px;"
                             "background-color: rgba(255, 255, 255, 0);"
                             "selection-color: rgb(255, 255, 255);"
                             "color: rgb(255, 255, 255);");
    timer = new QTimer(parent);//新建定时器
    timer->start(1000);//定时器开始计时，其中1000表示1000ms即1秒
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));//关联定时器计满信号和相应的槽函数

}
void game::timerUpDate()
{
    if(count==300)
    {
        resWindow->setWinner(sc);
        resWindow->show();
    }
    count++;
    timelabel->setText(QString::number(count));
}
void game::Connect()
{
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cell[i][j]=new Cell(this,i,j);
            connect(cell[i][j],SIGNAL(Click(int,int,int)),this,SLOT(check(int,int,int)));
            connect(cell[i][j],SIGNAL(SantaClaus(int ,char)),this,SLOT(SantaClaus(int ,char)));
            connect(cell[i][j],SIGNAL(Gift(int ,char ,int)),this,SLOT(Gift(int ,char ,int)));
            connect(cell[i][j],SIGNAL(Special(int ,char ,int)),this,SLOT(Special(int ,char ,int)));
            connect(cell[i][j],SIGNAL(Normal(int ,char)),this,SLOT(Normal(int ,char)));
            connect(cell[i][j],SIGNAL(returnChange(int ,int)),this,SLOT(returnChange(int ,int )));
            connect(cell[i][j],SIGNAL(delete_Special_S(int)),this,SLOT(delete_Special_S(int)));
            connect(cell[i][j],SIGNAL(delete_Special_H(int)),this,SLOT(delete_Special_H(int)));
            connect(cell[i][j],SIGNAL(delete_Gift(int)),this,SLOT(delete_Gift(int)));
            connect(cell[i][j],SIGNAL(delete_SantaClaus(int)),this,SLOT(delete_SantaClaus(int)));
            connect(cell[i][j],SIGNAL(setNewMap()),this,SLOT(setNewMap()));
            cell[i][j]->Init();
        }
    }
}
void game::check(int row,int col ,int sp)
{
    if(sp==6)
        sc=sc+row*3;
    for(int i=0;i<3;i++)
        if(sc>=(i+2)*500)
            start[i]->setStyleSheet("background-color: rgba(255, 255, 255, 0);"
                                    "border-image: url(:/xmas_tool02_d_04.png);");
    if(sp==1)
    {
        cell[OriginRow][OriginCol]->set3();
        OriginRow=row;
        OriginCol=col;
        cell[row][col]->set1();
    }
    else
    {
        cell[row][col]->set2(OriginRow ,OriginCol);
        cell[OriginRow][OriginCol]->set2(row ,col);
        cell[row][col]->change(OriginRow ,OriginCol ,row ,col);
        cell[row][col]->Delete(row ,col);
        cell[row][col]->changemap();
        cell[row][col]->Delete(row ,col);
        cell[row][col]->changemap();
        cell[row][col]->Delete(row ,col);
        cell[row][col]->changemap();
        cell[row][col]->Delete(row ,col);
        cell[row][col]->changemap();
        cell[row][col]->Delete(row ,col);
        cell[row][col]->changemap();
    }
}
void game::returnChange(int row ,int col)
{
    cell[row][col]->set2(row ,col);
    cell[OriginRow][OriginCol]->set2(OriginRow ,OriginCol);
    cell[row][col]->change(row ,col ,OriginRow ,OriginCol);
}
void game::SantaClaus(int sp ,char type)
{
    int row=sp/9;
    int col=sp%9;
    if(type=='s')
    {
        for(int i=0;i<5;i++)
            cell[row+i][col]->set4();
        cell[row+2][col]->set_SantaClaus();
    }
    if(type=='h')
    {
        for(int i=0;i<5;i++)
            cell[row][col+i]->set4();
        cell[row][col+2]->set_SantaClaus();
    }
    sc=sc+20;
    s = s.setNum(sc);
    score->setText(s);
}
void game::Gift(int sp ,char type ,int color)
{
    int row=sp/9;
    int col=sp%9;
    if(type=='a')
    {
        for(int i=0;i<3;i++)
            cell[row-i][col]->set4();
        for(int i=1;i<3;i++)
            cell[row][col+i]->set4();
        cell[row][col]->set_Gift(row ,col ,color);
    }
    if(type=='b')
    {
        for(int i=0;i<3;i++)
            cell[row-i][col]->set4();
        for(int i=1;i<3;i++)
            cell[row][col-i]->set4();
        cell[row][col]->set_Gift(row ,col ,color);
    }
    if(type=='c')
    {
        for(int i=0;i<3;i++)
            cell[row+i][col]->set4();
        for(int i=1;i<3;i++)
            cell[row][col+i]->set4();
        cell[row][col]->set_Gift(row ,col ,color);
    }
    if(type=='d')
    {
        for(int i=0;i<3;i++)
            cell[row+i][col]->set4();
        for(int i=1;i<3;i++)
            cell[row][col-i]->set4();
        cell[row][col]->set_Gift(row ,col ,color);
    }
    sc=sc+15;
    s = s.setNum(sc);
    score->setText(s);
}
void game::Special(int sp ,char type ,int color)
{
    int row=sp/9;
    int col=sp%9;
    if(type=='s')
    {
        for(int i=0;i<4;i++)
            cell[row+i][col]->set4();
        cell[row+1][col]->set_Special_S(row+1 ,col ,color);
    }
    if(type=='h')
    {
        for(int i=0;i<4;i++)
            cell[row][col+i]->set4();
        cell[row][col+1]->set_Special_H(row ,col+1 ,color);
    }
    sc=sc+10;
    s = s.setNum(sc);
    score->setText(s);
}
void game::Normal(int sp ,char type)
{
    int row=sp/9;
    int col=sp%9;
    if(type=='s')
    {
        for(int i=0;i<3;i++)
            cell[row+i][col]->set4();
    }
    if(type=='h')
    {
        for(int i=0;i<3;i++)
            cell[row][col+i]->set4();
    }
    sc=sc+5;
    s = s.setNum(sc);
    score->setText(s);
}
void game::delete_Special_S(int sp)
{
    int col=sp%9;
    for(int i=0;i<9;i++)
        cell[i][col]->set4();
    sc=sc+10;
    s = s.setNum(sc);
    score->setText(s);
}
void game::delete_Special_H(int sp)
{
    int row=sp/9;
    for(int i=0;i<9;i++)
        cell[row][i]->set4();
    sc=sc+10;
    s = s.setNum(sc);
    score->setText(s);
}
void game::delete_Gift(int sp)
{
    int row=sp/9-1;
    int col=sp%9-1;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cell[row+i][col+j]->set4();
    sc=sc+15;
    s = s.setNum(sc);
    score->setText(s);
}
void game::delete_SantaClaus(int Type)
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cell[i][j]->set5(Type);
    sc=sc+20;
    s = s.setNum(sc);
    score->setText(s);
}
void game::setNewMap()
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cell[i][j]->set3();
}
void game::bb(int sp)
{
    for(int i=0;i<9;i++)
        cell[i][sp]->set4();
    sc=sc+50;
    s = s.setNum(sc);
    score->setText(s);
    cell[0][0]->changemap();
}

