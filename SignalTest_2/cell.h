#ifndef CELL_H
#define CELL_H

#include<QObject>
#include<QPushButton>
#include<QLabel>
#include<ctime>
#include<iostream>

class Cell : public QObject
{
    Q_OBJECT

public:
    explicit Cell(QWidget *parent, int Row, int Col);
    ~Cell();
    void Init();
    void set1();
    void set2(int row ,int col);
    void set3();
    void set4();
    void set5(int);
    void set_SantaClaus();
    void set_Gift(int ,int  ,int);
    void set_Special_S(int ,int ,int);
    void set_Special_H(int ,int ,int);
    void change(int OriginRow ,int OriginCol ,int row ,int col);
    void checkDeleteType();
    void checkDeletePossible(int ,int);
    void changemap();
    void Delete(int ,int);
    void Check_Gift(int ,int);
    void Check_Special(int ,int);
    void Check_Normal(int ,int);
    void Check_SantaClaus(int ,int);
    void Check1_SantaClaus(int* ,int* ,char ,int  ,int);
    void Check1_Gift(int* ,int* ,char ,int ,int );
    void Check1_Special(int* ,int* ,char ,int ,int);
    void Check1_Normal(int* ,int* ,char ,int ,int);
    void canGiftPic();
    void cookieGiftPic();
    void bellGiftPic();
    void leftGiftPic();
    void snowGiftPic();
    void canStrPic();
    void cookieStrPic();
    void bellStrPic();
    void leftStrPic();
    void snowStrPic();
    void canHorPic();
    void cookieHorPic();
    void bellHorPic();
    void leftHorPic();
    void snowHorPic();
    void canPic();
    void cookiePic();
    void bellPic();
    void leftPic();
    void snowPic();
    void icePic();
    void nullPic();
signals:
    void Click(int row,int col,int sp);
    void SantaClaus(int ,char);
    void Gift(int ,char ,int);
    void Special(int ,char ,int);
    void Normal(int ,char);
    void returnChange(int ,int);
    void setNewMap();
    void delete_Special_S(int);
    void delete_Special_H(int);
    void delete_Gift(int);
    void delete_SantaClaus(int);
public slots:
    void click();
private:
    QPushButton *button;
    //QLabel *score;
    int row,col,sp ,check;
    int SantaClaus_str_start[45];
    int SantaClaus_hor_start[45];
    int SantaClaus_str_add[5];
    int SantaClaus_hor_add[5];
    int Gift_ur_start[49];
    int Gift_ul_start[49];
    int Gift_dr_start[49];
    int Gift_dl_start[49];
    int Gift_ur_add[5];
    int Gift_ul_add[5];
    int Gift_dr_add[5];
    int Gift_dl_add[5];
    int Special_str_start[54];
    int Special_hor_start[54];
    int Special_str_add[4];
    int Special_hor_add[4];
    int Normal_str_start[63];
    int Normal_hor_start[63];
    int Normal_str_add[3];
    int Normal_hor_add[3];
    //int sc;
    QString s;

};

#endif // CELL_H
