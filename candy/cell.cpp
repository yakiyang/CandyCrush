#include "cell.h"
int OriginRow ,OriginCol;
int map[81]={1 ,5 ,2 ,5 ,2 ,1 ,2 ,5 ,3 ,
             1 ,4 ,5 ,2 ,2 ,3 ,2 ,3 ,2 ,
             3 ,1 ,4 ,2 ,3 ,2 ,5 ,2 ,3 ,
             1 ,1 ,4 ,4 ,5 ,1, 2 ,4 ,2 ,
             2 ,4 ,2 ,1 ,2 ,4 ,1 ,2 ,4 ,
             1, 1 ,4 ,4 ,1 ,1 ,3 ,3 ,2 ,
             3, 2 ,4 ,3 ,1 ,3 ,2 ,4 ,1 ,
             3, 4, 2 ,5 , 3, 4, 4, 5, 5,
             2, 3, 3, 2, 4, 2, 4, 2, 5};
Cell::Cell(QWidget *parent, int Row, int Col) :
    QObject(parent)
{
    srand(time(NULL));
    row=Row;
    col=Col;
    check=0;
    sp=-1;
    button=new QPushButton(parent);
    button->setGeometry(70*col+30,70*row+40,60,60);
    button->setFlat(true);
    button->setIconSize(button->size());
    s=s.setNum(map[9*row+col]);
    connect(button,SIGNAL(clicked()),this,SLOT(click()));
    button->setText(s);
    if(map[9*row+col]==1)
        canPic();
    if(map[9*row+col]==2)
        cookiePic();
    if(map[9*row+col]==3)
        bellPic();
    if(map[9*row+col]==4)
        leftPic();
    if(map[9*row+col]==5)
        snowPic();
}
Cell::~Cell()
{
    delete button;
}
void Cell::Init()
{
    for(int i=0;i<45;i++)
        SantaClaus_str_start[i]=i;
    int k=0;
    for(int i=0;i<9;i++)
        for(int j=0;j<5;j++)
        {
            SantaClaus_hor_start[k]=9*i+j;
            k++;
        }
    for(int i=0;i<5;i++)
        SantaClaus_str_add[i]=9*i;
    for(int i=0;i<5;i++)
        SantaClaus_hor_add[i]=i;


    k=0;
    for(int i=2;i<9;i++)
        for(int j=0;j<7;j++)
        {
            Gift_ur_start[k]=9*i+j;
            k++;
        }
    k=0;
    for(int i=2;i<9;i++)
        for(int j=2;j<9;j++)
        {
            Gift_ul_start[k]=9*i+j;
            k++;
        }
    k=0;
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
        {
            Gift_dr_start[k]=9*i+j;
            k++;
        }
    k=0;
    for(int i=0;i<7;i++)
        for(int j=2;j<9;j++)
        {
            Gift_dl_start[k]=9*i+j;
            k++;
        }
    for(int i=0;i<3;i++)
        Gift_ur_add[i]=i;
    Gift_ur_add[3]=-9;
    Gift_ur_add[4]=-18;
    for(int i=0;i<3;i++)
        Gift_ul_add[i]=-i;
    Gift_ul_add[3]=-9;
    Gift_ul_add[4]=-18;
    for(int i=0;i<3;i++)
        Gift_dr_add[i]=i;
    Gift_dr_add[3]=9;
    Gift_dr_add[4]=18;
    for(int i=0;i<3;i++)
        Gift_dl_add[i]=-i;
    Gift_dl_add[3]=9;
    Gift_dl_add[4]=18;



    for(int i=0;i<54;i++)
        Special_str_start[i]=i;
    k=0;
    for(int i=0;i<9;i++)
        for(int j=0;j<6;j++)
        {
            Special_hor_start[k]=9*i+j;
            k++;
        }
    for(int i=0;i<4;i++)
        Special_str_add[i]=9*i;
    for(int i=0;i<4;i++)
        Special_hor_add[i]=i;



    for(int i=0;i<63;i++)
        Normal_str_start[i]=i;
    k=0;
    for(int i=0;i<9;i++)
        for(int j=0;j<7;j++)
        {
            Normal_hor_start[k]=9*i+j;
            k++;
        }
    for(int i=0;i<3;i++)
        Normal_str_add[i]=9*i;
    for(int i=0;i<3;i++)
        Normal_hor_add[i]=i;
}
void Cell::click()
{
    if(map[row*9+col]==99)
    {
        int r=rand()%81;
        map[row*9+col]=0;
        map[r]=0;
        emit Click(row ,col ,6);
    }
    if(row==OriginRow&&(col-OriginCol)==1)
    {
        OriginRow=-1;
        OriginCol=-1;
        emit Click(row ,col ,2);
    }
    else if(row==OriginRow&&(col-OriginCol)==-1)
    {
        OriginRow=-1;
        OriginCol=-1;
        emit Click(row ,col ,3);
    }
    else if(col==OriginCol&&(row-OriginRow)==1)
    {
        OriginRow=-1;
        OriginCol=-1;
        emit Click(row ,col ,4);
    }
    else if(col==OriginCol&&(row-OriginRow)==-1)
    {
        OriginRow=-1;
        OriginCol=-1;
        emit Click(row ,col ,5);
    }
    else
    {
        emit Click(row ,col ,1);
        OriginRow=row;
        OriginCol=col;
    }
}
void Cell::set1()
{
    s=s.setNum(map[9*row+col]);
    if(map[9*row+col]==1)
    button->setStyleSheet("border:1px;"
                          "background-color:  qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                          "image:url(:/xmas_tool01_d_01.png);");
    if(map[9*row+col]==2)
    button->setStyleSheet("border:1px;"
                          "background-color:  qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                          "image: url(:/xmas_tool01_d_02.png);");
    if(map[9*row+col]==3)
    button->setStyleSheet("border:1px;"
                          "background-color:  qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                          "image: url(:/xmas_tool02_d_01.png);");
    if(map[9*row+col]==4)
    button->setStyleSheet("border:1px;"
                          "background-color:  qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                          "image:url(:/xmas_tool02_d_02.png);");
    if(map[9*row+col]==5)
    button->setStyleSheet("border:1px;"
                          "background-color:  qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                          "image:url(:/xmas_tool02_d_03.png);");
    if(map[9*row+col]==6)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/xmas_tool01_d_03.png);"
                             );;
    if(map[9*row+col]==31)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/can3.png);"
                             );
    if(map[9*row+col]==32)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/cookie3.png);"
                             );
    if(map[9*row+col]==33)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/bell3.png);"
                             );
    if(map[9*row+col]==34)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/xmas_tool03_d_03.png);"
                             );
    if(map[9*row+col]==35)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/snow3.png);"
                             );
    if(map[9*row+col]==11)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/can1.png);"
                             );
    if(map[9*row+col]==12)
        button->setStyleSheet("border:1px;"
                              "background-color: rqradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/cookie1.png);"
                             );
    if(map[9*row+col]==13)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/bell1.png);"
                             );
    if(map[9*row+col]==14)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/lef1.png);"
                             );
    if(map[9*row+col]==15)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/snow1.png);"
                             );
    if(map[9*row+col]==21)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/can2.png);"
                             );
    if(map[9*row+col]==22)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/cookie2.png);"
                             );
    if(map[9*row+col]==23)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/bell2.png);"
                             );
    if(map[9*row+col]==24)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/lef2.png);"
                             );
    if(map[9*row+col]==25)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "image: url(:/snow2.png);"
                             );
    if(map[9*row+col]==99)
        button->setStyleSheet("border:1px;"
                              "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.263682 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 150));"
                              "border-image: url(:/xmas_tool02_d_05.png);"
                             );
    button->setText(s);

}
void Cell::set2(int row ,int col)
{
    s=s.setNum(map[9*row+col]);
    button->setText(s);
    if(map[9*row+col]==1)
        canPic();
    if(map[9*row+col]==2)
        cookiePic();
    if(map[9*row+col]==3)
        bellPic();
    if(map[9*row+col]==4)
        leftPic();
    if(map[9*row+col]==5)
        snowPic();
    if(map[9*row+col]==6)
        set_SantaClaus();
    if(map[9*row+col]==31)
        canGiftPic();
    if(map[9*row+col]==32)
        cookieGiftPic();
    if(map[9*row+col]==33)
        bellGiftPic();
    if(map[9*row+col]==34)
        leftGiftPic();
    if(map[9*row+col]==35)
        snowGiftPic();
    if(map[9*row+col]==11)
        canStrPic();
    if(map[9*row+col]==12)
        cookieStrPic();
    if(map[9*row+col]==13)
        bellStrPic();
    if(map[9*row+col]==14)
        leftStrPic();
    if(map[9*row+col]==15)
        snowStrPic();
    if(map[9*row+col]==21)
        canHorPic();
    if(map[9*row+col]==22)
        cookieHorPic();
    if(map[9*row+col]==23)
        bellHorPic();
    if(map[9*row+col]==24)
        leftHorPic();
    if(map[9*row+col]==25)
        snowHorPic();
    if(map[9*row+col]==99)
        icePic();
}
void Cell::set3()
{
    s=s.setNum(map[9*row+col]);
    button->setText(s);
    if(map[9*row+col]==1)
        canPic();
    if(map[9*row+col]==2)
        cookiePic();
    if(map[9*row+col]==3)
        bellPic();
    if(map[9*row+col]==4)
        leftPic();
    if(map[9*row+col]==5)
        snowPic();
    if(map[9*row+col]==6)
        set_SantaClaus();
    if(map[9*row+col]==31)
        canGiftPic();
    if(map[9*row+col]==32)
        cookieGiftPic();
    if(map[9*row+col]==33)
        bellGiftPic();
    if(map[9*row+col]==34)
        leftGiftPic();
    if(map[9*row+col]==35)
        snowGiftPic();
    if(map[9*row+col]==11)
        canStrPic();
    if(map[9*row+col]==12)
        cookieStrPic();
    if(map[9*row+col]==13)
        bellStrPic();
    if(map[9*row+col]==14)
        leftStrPic();
    if(map[9*row+col]==15)
        snowStrPic();
    if(map[9*row+col]==21)
        canHorPic();
    if(map[9*row+col]==22)
        cookieHorPic();
    if(map[9*row+col]==23)
        bellHorPic();
    if(map[9*row+col]==24)
        leftHorPic();
    if(map[9*row+col]==25)
        snowHorPic();
    if(map[9*row+col]==99)
        icePic();

}
void Cell::set4()
{
    nullPic();
}
void Cell::set5(int type)
{
    if(map[9*row+col]==type)
        nullPic();
}
void Cell::set_SantaClaus()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/xmas_tool01_d_03.png);"
                         );
    map[9*row+col]=6;
    s=s.setNum(map[9*row+col]);
    button->setText(s);

}
void Cell::set_Gift(int row ,int col ,int color)
{
    if(color==1)
    {   canGiftPic();map[9*row+col]=31;}
    if(color==2)
    {   cookieGiftPic();map[9*row+col]=32;}
    if(color==3)
    {   bellGiftPic();map[9*row+col]=33;}
    if(color==4)
    {   leftGiftPic();map[9*row+col]=34;}
    if(color==5)
    {   snowGiftPic();map[9*row+col]=35;}
    s=s.setNum(map[9*row+col]);
    button->setText(s);
}
void Cell::set_Special_S(int row ,int col ,int color)
{
    if(color==1)
    {    canStrPic();map[9*row+col]=11;}
    if(color==2)
    {   cookieStrPic();map[9*row+col]=12;}
    if(color==3)
    {    bellStrPic();map[9*row+col]=13;}
    if(color==4)
    {    leftStrPic();map[9*row+col]=14;}
    if(color==5)
    {    snowStrPic();map[9*row+col]=15;}
    s=s.setNum(map[9*row+col]);
    button->setText(s);
}
void Cell::set_Special_H(int row ,int col ,int color)
{
    if(color==1)
    {   canHorPic();map[9*row+col]=21;}
    if(color==2)
    {    cookieHorPic();map[9*row+col]=22;}
    if(color==3)
    {    bellHorPic();map[9*row+col]=23;}
    if(color==4)
    {    leftHorPic();map[9*row+col]=24;}
    if(color==5)
    {    snowHorPic();map[9*row+col]=25;}
    s=s.setNum(map[9*row+col]);
    button->setText(s);
}
void Cell::change(int OriginRow ,int OriginCol ,int row ,int col)
{
    int ch=map[9*OriginRow+OriginCol];
    map[9*OriginRow+OriginCol]=map[9*row+col];
    map[9*row+col]=ch;
}
void Cell::Delete(int row ,int col)
{
    checkDeleteType();
    checkDeletePossible(row ,col);
}
void Cell::checkDeletePossible(int row ,int col)
{
    int ch=0;
    for(int i=0;i<81;i++)
        if(map[i]==0)ch++;
    if(ch==0)
        returnChange(row ,col);
}
void Cell::checkDeleteType()
{
    Check_SantaClaus(45 ,5);
    Check_Gift(49 ,5);
    Check_Special(54 ,4);
    Check_Normal(63 ,3);
}
/*void Cell::checkDeleteType2(int all ,int num)
{
    for(int i=0;i<all;i++)
    {
        checkDeleteType3(SantaClaus_str_start ,SantaClaus_str_add ,'s' ,i ,num);
        checkDeleteType3(SantaClaus_hor_start ,SantaClaus_hor_add ,'h' ,i ,num);
    }

}*/
void Cell::Check_SantaClaus(int all ,int num)
{
    for(int i=0;i<all;i++)
    {
        Check1_SantaClaus(SantaClaus_str_start ,SantaClaus_str_add ,'s' ,i ,num);
        Check1_SantaClaus(SantaClaus_hor_start ,SantaClaus_hor_add ,'h' ,i ,num);
    }
}
void Cell::Check_Gift(int all ,int num)
{
    for(int i=0;i<all;i++)
    {
        Check1_Gift(Gift_ur_start ,Gift_ur_add ,'a' ,i ,num);
        Check1_Gift(Gift_ul_start ,Gift_ul_add ,'b' ,i ,num);
        Check1_Gift(Gift_dr_start ,Gift_dr_add ,'c' ,i ,num);
        Check1_Gift(Gift_dl_start ,Gift_dl_add ,'d' ,i ,num);
    }
}
void Cell::Check_Special(int all ,int num)
{
    for(int i=0;i<all;i++)
    {
        Check1_Special(Special_str_start ,Special_str_add ,'s' ,i ,num);
        Check1_Special(Special_hor_start ,Special_hor_add ,'h' ,i ,num);
    }
}
void Cell::Check_Normal(int all ,int num)
{
    for(int i=0;i<all;i++)
    {
        Check1_Normal(Normal_str_start ,Normal_str_add ,'s' ,i ,num);
        Check1_Normal(Normal_hor_start ,Normal_hor_add ,'h' ,i ,num);
    }
}
/*void Cell::checkDeleteType3(int *start ,int *add ,char type ,int sp ,int num)
{
    int ch=0 ,Type;
    if(map[start[sp]]!=0)
        for(int j=0;j<num;j++)
            if(map[start[sp]]%10==map[start[sp]+add[j]]%10||map[start[sp]+add[j]]==6)
                ch++;
    if(map[start[sp]]==6)
    {
        ch=2;
        if(map[start[sp]+add[1]]!=0)
        {
            for(int j=1;j<num-1;j++)
                if(map[start[sp]+add[j]]%10==map[start[sp]+add[j+1]]%10)
                   ch++;
            Type=start[sp]+add[j];
        }
    }
    int t=0

    for(int j=0;j<num;j++)
    {
        if(map[start[sp]+add[j]]/10!=0)
        {
              ts=map[start[sp]+add[j]]/10;
              break;
        }
        if(map[start[sp]+add[j]]==6){t=6;break;}
    }

}*/
void Cell::Check1_SantaClaus(int *start ,int *add ,char type ,int sp ,int num)
{
    int ch=0 ,Type;
    if(map[start[sp]]!=0)
        for(int j=0;j<num;j++)
            if(map[start[sp]]%10==map[start[sp]+add[j]]%10||map[start[sp]+add[j]]==6)
                ch++;
        if(map[start[sp]]==6)
        {
            ch=2;
            if(map[start[sp]+add[1]]!=0)
            {
                for(int j=1;j<num-1;j++)
                    if(map[start[sp]+add[j]]%10==map[start[sp]+add[j+1]]%10)
                       ch++;
                Type=start[sp]+add[1];
            }
        }
        if(ch==num)
        {
            int t=0 ,j;
            for(j=0;j<num;j++)
            {
                if(map[start[sp]+add[j]]/10!=0)
                {
                    t=map[start[sp]+add[j]]/10;
                    break;
                }
                if(map[start[sp]+add[j]]==6){t=6;break;}
            }


            if(t==1)
                delete_Special_S(start[sp]+add[j]);
            if(t==2)
                delete_Special_H(start[sp]+add[j]);
            if(t==3)
                delete_Gift(start[sp]+add[j]);
            if(t==6)
                delete_SantaClaus(Type);
            if(type=='s')
                SantaClaus(start[sp] ,'s');
            if(type=='h')
                SantaClaus(start[sp] ,'h');
        }
}
void Cell::Check1_Gift(int *start ,int *add ,char type ,int sp ,int num)
{
    int ch=0;
    for(int j=0;j<5;j++)
        if(map[start[sp]]==map[start[sp]+add[j]])
            ch++;
    if(ch==num)
    {
        if(type=='a')
            Gift(start[sp] ,'a' ,map[start[sp]]);
        if(type=='b')
            Gift(start[sp] ,'b' ,map[start[sp]]);
        if(type=='c')
            Gift(start[sp] ,'c' ,map[start[sp]]);
        if(type=='d')
            Gift(start[sp] ,'d' ,map[start[sp]]);
    }
}
void Cell::Check1_Special(int *start ,int *add ,char type ,int sp ,int num)
{
    int ch=0 ,Type;
    if(map[start[sp]]!=0)
        for(int j=0;j<num;j++)
            if(map[start[sp]]%10==map[start[sp]+add[j]]%10||map[start[sp]+add[j]]==6)
                ch++;
        if(map[start[sp]]==6)
        {
            ch=2;
            if(map[start[sp]+add[1]]!=0)
            {
                for(int j=1;j<num-1;j++)
                    if(map[start[sp]+add[j]]%10==map[start[sp]+add[j+1]]%10)
                       ch++;
                Type=start[sp]+add[1];
            }
        }
        if(ch==num)
        {
            int t=0 ,j;
            for(j=0;j<num;j++)
            {
                if(map[start[sp]+add[j]]/10!=0)
                {
                    t=map[start[sp]+add[j]]/10;
                    break;
                }
                if(map[start[sp]+add[j]]==6){t=6;break;}
            }


            if(t==1)
                delete_Special_S(start[sp]+add[j]);
            if(t==2)
                delete_Special_H(start[sp]+add[j]);
            if(t==3)
                delete_Gift(start[sp]+add[j]);
            if(t==6)
                delete_SantaClaus(Type);
            if(type=='s')
                Special(start[sp] ,'s' ,map[start[sp]]);
            if(type=='h')
                Special(start[sp] ,'h' ,map[start[sp]]);
        }
}
void Cell::Check1_Normal(int *start ,int *add ,char type ,int sp ,int num)
{
    int ch=0 ,Type;
    if(map[start[sp]]!=0)
        for(int j=0;j<num;j++)
            if(map[start[sp]]%10==map[start[sp]+add[j]]%10||map[start[sp]+add[j]]==6)
                ch++;
        if(map[start[sp]]==6)
        {
            ch=2;
            if(map[start[sp]+add[1]]!=0)
            {
                for(int j=1;j<num-1;j++)
                    if(map[start[sp]+add[j]]%10==map[start[sp]+add[j+1]]%10)
                       ch++;
                Type=start[sp]+add[1];
            }
        }
        if(ch==num)
        {
            int t=0 ,j;
            for(j=0;j<num;j++)
            {
                if(map[start[sp]+add[j]]/10!=0)
                {
                    t=map[start[sp]+add[j]]/10;
                    break;
                }
                if(map[start[sp]+add[j]]==6){t=6;break;}
            }


            if(t==1)
                delete_Special_S(start[sp]+add[j]);
            if(t==2)
                delete_Special_H(start[sp]+add[j]);
            if(t==3)
                delete_Gift(start[sp]+add[j]);
            if(t==6)
                delete_SantaClaus(Type);
            if(type=='s')
                Normal(start[sp] ,'s');
            if(type=='h')
                Normal(start[sp] ,'h');
        }
}
void Cell::changemap()
{
    for(int i=0;i<9;i++)
    {
       for(int j=8;j>=0;j--)
       {
           if(map[9*j+i]==0)
           {
               for(int k=j;k>=0;k--)
               {
                   if(map[9*k+i]!=0)
                   {
                       map[9*j+i]=map[9*k+i];
                       map[9*k+i]=0;
                       break;
                   }
               }
           }
       }
    }
    for(int i=0;i<81;i++)
        if(map[i]==0)
        {
            map[i]=rand()%5+1;
            if(i==0)
                map[i]=99;
        }
    setNewMap();
}
void Cell::canGiftPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/can3.png);"
                         );
}
void Cell::cookieGiftPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/cookie3.png);"
                         );
}
void Cell::bellGiftPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/bell3.png);"
                         );
}
void Cell::leftGiftPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/xmas_tool03_d_03.png);"
                         );
}
void Cell::snowGiftPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/snow3.png);"
                         );
}
void Cell::canStrPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/can1.png);"
                         );
}
void Cell::cookieStrPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/cookie1.png);"
                         );
}
void Cell::bellStrPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/bell1.png);"
                         );
}
void Cell::leftStrPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/lef1.png);"
                         );
}
void Cell::snowStrPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/snow1.png);"
                         );
}
void Cell::canHorPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/can2.png);"
                         );
}
void Cell::cookieHorPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/cookie2.png);"
                         );
}
void Cell::bellHorPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/bell2.png);"
                         );
}
void Cell::leftHorPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/lef2.png);"
                         );
}
void Cell::snowHorPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/snow2.png);"
                         );
}
void Cell::canPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image:url(:/xmas_tool01_d_01.png);");
}
void Cell::cookiePic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/xmas_tool01_d_02.png);");
}
void Cell::bellPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image: url(:/xmas_tool02_d_01.png);");
}
void Cell::leftPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image:url(:/xmas_tool02_d_02.png);");
}
void Cell::snowPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "image:url(:/xmas_tool02_d_03.png);");
}
void Cell::icePic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                          "border-image: url(:/xmas_tool02_d_05.png);"
                         );
}

void Cell::nullPic()
{
    button->setStyleSheet("border:1px;"
                          "background-color: rgba(255, 255, 255, 150);"
                         );
    map[9*row+col]=0;
    s=s.setNum(map[9*row+col]);
    button->setText(s);
}
