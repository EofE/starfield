#include<QMainWindow>
#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"pathbox.h"
#include"piontstack.h"
#include"specline.h"
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<ctime>
void MainWindow::chapterrand()
{
    chaptercoise=-1;
    pathbox *b;
    static int add=0;
    srand(time(0)+add++);
    border=rand()%(15-5+1)+5;
    srand(time(0)+add++);
red=rand()%(border*border-1-0+1);
srand(time(0)+add++);
gr=rand()%(4-0+1);
srand(time(0)+add++);
go=rand()%(4-1+1)+1;
sln=0;
for(int i=0;i<gr;i++)
{
    do {
        srand(time(0)+add++);
        green[i]=rand()%(border*border-1-0+1);
    }
    while(((green[i]>(border-1)*border-1&&green[i]<(border-1)*border+border)||(green[i]>-1&&green[i]<border)||(green[i]-border+1)%border==0||green[i]%border==0)||!(green[i]!=red&&greent(green[i],i-1)));
}
for(int i=0;i<go;i++)
{
    do {
        srand(time(0)+add++);
        gold[i]=rand()%(border*border-1-0+1);
    }
    while(!(gold[i]!=red&&greent(gold[i],gr)&&goldt(gold[i],i-1)));
}

for(int i=0;i<border*border;i++)
{
    if(i==red)
    {
        randborder(i,0);
    continue;
    }
    if(!greent(i,gr))
    {srand(time(0)+add++);
        if(rand()%3==0)
        {
            b=new pathbox(1,1,1,0,0,this);
            box.push_back(b);
        }
        else
            if(rand()%2==1)
            {
                b=new pathbox(1,1,0,1,0,this);
                box.push_back(b);
            }
        else
            {
pathbox *b=new pathbox(1,1,1,0,0,this);
box.push_back(b);
            }
        continue;
    }
    if(!goldt(i,go))
    {
        randborder(i,1);
        continue;
    }
    srand(time(0)+add++);
    if(rand()%7==0)
    {
        pathbox *b=new pathbox(this);
        box.push_back(b);
    }
    else{
        int nums=0,a[4];
        do{
            nums=0;
            for(int i=0;i<4;i++)
            {a[i]=rand()%2;
            if(a[i]==1)
                nums++;
            }
        }
        while(nums<2||nums>3);
    pathbox *b=new pathbox(a[0],a[1],a[2],a[3],this);
    box.push_back(b);
    }
}
commoncha();
}
void MainWindow::chapter0()
{
        chaptercoise=0;
red=15;
green[0]=5;
gr=1;//greenstar-number
go=3;//yellowstar-number
sln=2;//specialline-number
border=5;
gold[0]=9,gold[1]=14,gold[2]=18;
pathbox *b=new pathbox(this);//0
box.push_back(b);
b=new pathbox(0,1,0,1,this);//1
box.push_back(b);
b=new pathbox(1,0,1,0,this);//2
box.push_back(b);
b=new pathbox(this);//3
box.push_back(b);
b=new pathbox(this);//4
box.push_back(b);
b=new pathbox(4,1,0,0,1,this);//5
box.push_back(b);
b=new pathbox(1,1,0,0,this);//6
box.push_back(b);
b=new pathbox(0,0,1,1,this);//7
box.push_back(b);
b=new pathbox(1,0,1,1,this);//8
box.push_back(b);
b=new pathbox(3,1,this);//9
box.push_back(b);
b=new pathbox(1,0,0,1,this);//10
box.push_back(b);
b=new pathbox(1,0,1,1,this);//11
box.push_back(b);
b=new pathbox(this);//12
box.push_back(b);
b=new pathbox(1,1,1,0,this);//13
box.push_back(b);
b=new pathbox(3,1,this);//14
box.push_back(b);
b=new pathbox(4,0,this);//15
box.push_back(b);
b=new pathbox(1,0,1,0,this);//16
box.push_back(b);
b=new pathbox(1,1,0,0,this);//17
box.push_back(b);
b=new pathbox(1,1,this);//18
box.push_back(b);
b=new pathbox(this);//19
box.push_back(b);
b=new pathbox(this);//20
box.push_back(b);
b=new pathbox(1,0,1,0,this);//21
box.push_back(b);
b=new pathbox(1,0,1,0,this);//22
box.push_back(b);
b=new pathbox(this);//23
box.push_back(b);
b=new pathbox(this);//24
box.push_back(b);
sl[0]=new sline(*box[15],*box[11],1);
sl[1]=new sline(*box[10],*box[6],0);
commoncha();
}
void MainWindow::chapter1()
{
        chaptercoise=1;
        red=14;
        green[0]=17,green[1]=39;
        gr=2;
        go=4;
        border=7;
        sln=0;
        gold[0]=4,gold[1]=36,gold[2]=37,gold[3]=40;
        pathbox *b=new pathbox(this);//0
        box.push_back(b);
        b=new pathbox(this);//1
        box.push_back(b);
        b=new pathbox(0,0,1,1,this);//2
        box.push_back(b);
        b=new pathbox(1,0,1,1,this);//3
        box.push_back(b);
        b=new pathbox(3,1,this);//4
        box.push_back(b);
        b=new pathbox(this);//5
        box.push_back(b);
        b=new pathbox(this);//6
        box.push_back(b);
        b=new pathbox(this);//7
        box.push_back(b);
        b=new pathbox(this);//8
        box.push_back(b);
        b=new pathbox(1,1,0,1,this);//9
        box.push_back(b);
        b=new pathbox(1,0,1,1,this);//10
        box.push_back(b);
        b=new pathbox(0,1,1,0,this);//11
        box.push_back(b);
        b=new pathbox(this);//12
        box.push_back(b);
        b=new pathbox(this);//13
        box.push_back(b);
        b=new pathbox(4,0,this);//14
        box.push_back(b);
        b=new pathbox(0,1,1,1,this);//15
        box.push_back(b);
        b=new pathbox(1,1,1,0,this);//16
        box.push_back(b);
        b=new pathbox(4,1,0,1,1,this);//17
        box.push_back(b);
        b=new pathbox(1,1,0,1,this);//18
        box.push_back(b);
        b=new pathbox(0,1,1,1,this);//19
        box.push_back(b);
        b=new pathbox(0,0,1,1,this);//20
        box.push_back(b);
        b=new pathbox(0,1,0,1,this);//21
        box.push_back(b);
        b=new pathbox(0,1,1,1,this);//22
        box.push_back(b);
        b=new pathbox(0,1,1,0,this);//23
        box.push_back(b);
        b=new pathbox(1,1,0,0,this);//24
        box.push_back(b);
        b=new pathbox(0,1,0,1,this);//25
        box.push_back(b);
        b=new pathbox(1,1,1,0,this);//26
        box.push_back(b);
        b=new pathbox(0,1,1,0,this);//27
        box.push_back(b);
        b=new pathbox(1,0,0,1,this);//28
        box.push_back(b);
        b=new pathbox(0,1,1,1,this);//29
        box.push_back(b);
        b=new pathbox(1,0,1,0,this);//30
        box.push_back(b);
        b=new pathbox(1,1,0,0,this);//31
        box.push_back(b);
        b=new pathbox(1,0,0,1,this);//32
        box.push_back(b);
        b=new pathbox(1,1,0,1,this);//33
        box.push_back(b);
        b=new pathbox(1,0,1,0,this);//34
        box.push_back(b);
        b=new pathbox(this);//35
        box.push_back(b);
        b=new pathbox(1,1,this);//36
        box.push_back(b);
        b=new pathbox(4,1,this);//37
        box.push_back(b);
        b=new pathbox(0,1,1,1,this);//38
        box.push_back(b);
        b=new pathbox(3,0,0,1,1,this);//39
        box.push_back(b);
        b=new pathbox(1,1,this);//40
        box.push_back(b);
        b=new pathbox(this);//41
        box.push_back(b);
        b=new pathbox(this);//42
        box.push_back(b);
        b=new pathbox(this);//43
        box.push_back(b);
        b=new pathbox(this);//44
        box.push_back(b);
        b=new pathbox(this);//45
        box.push_back(b);
        b=new pathbox(this);//46
        box.push_back(b);
        b=new pathbox(this);//47
        box.push_back(b);
        b=new pathbox(this);//48
        box.push_back(b);
    commoncha();
}
void MainWindow::chapter2()
{
        chaptercoise=2;
        red=21;
           green[0]=18,green[1]=38;
           gr=2;//greenstar-number
           go=2;//yellowstar-number
           sln=0;
           border=7;
           gold[0]=8,gold[1]=48;
           pathbox *b=new pathbox(this);//0
           box.push_back(b);
           b=new pathbox(1,0,0,1,this);//1
           box.push_back(b);
           b=new pathbox(1,1,1,0,this);//2
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//3
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//4
           box.push_back(b);
           b=new pathbox(this);//5
           box.push_back(b);
           b=new pathbox(this);//6
           box.push_back(b);
           b=new pathbox(this);//7
           box.push_back(b);
           b=new pathbox(1,1,this);//8
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//9
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//10
           box.push_back(b);
           b=new pathbox(0,1,1,0,this);//11
           box.push_back(b);
           b=new pathbox(1,1,1,0,this);//12
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//13
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//14
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//15
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//16
           box.push_back(b);
           b=new pathbox(1,0,1,1,this);//17
           box.push_back(b);
           b=new pathbox(4,0,1,0,1,this);//18
           box.push_back(b);
           b=new pathbox(0,1,1,0,this);//19
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//20
           box.push_back(b);
           b=new pathbox(4,0,this);//21
           box.push_back(b);
           b=new pathbox(1,1,1,0,this);//22
           box.push_back(b);
           b=new pathbox(0,1,0,1,this);//23
           box.push_back(b);
           b=new pathbox(1,0,0,1,this);//24
           box.push_back(b);
           b=new pathbox(1,0,1,1,this);//25
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//26
           box.push_back(b);
           b=new pathbox(0,1,1,0,this);//27
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//28
           box.push_back(b);
           b=new pathbox(0,1,0,1,this);//29
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//30
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//31
           box.push_back(b);
           b=new pathbox(0,1,0,1,this);//32
           box.push_back(b);
           b=new pathbox(this);//33
           box.push_back(b);
           b=new pathbox(this);//34
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//35
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//36
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//37
           box.push_back(b);
           b=new pathbox(3,0,1,1,0,this);//38
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//39
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//40
           box.push_back(b);
           b=new pathbox(this);//41
           box.push_back(b);
           b=new pathbox(0,1,0,1,this);//42
           box.push_back(b);
           b=new pathbox(1,1,1,0,this);//43
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//44
           box.push_back(b);
           b=new pathbox(1,0,0,1,this);//45
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//46
           box.push_back(b);
           b=new pathbox(0,1,0,1,this);//47
           box.push_back(b);
           b=new pathbox(3,1,this);//48
           box.push_back(b);
    commoncha();
}

void MainWindow::chapter3()
{
        chaptercoise=3;
        red=0;
        green[0]=18,green[1]=30,green[2]=40;
        gr=3;//greenstar-number
        go=2;//yellowstar-number
        sln=0;
        border=7;
        gold[0]=14,gold[1]=47;
        pathbox *b=new pathbox(4,0,this);//0
        box.push_back(b);
        b=new pathbox(1,1,0,1,this);//1
        box.push_back(b);
        b=new pathbox(0,1,1,0,this);//2
        box.push_back(b);
        b=new pathbox(0,1,1,0,this);//3
        box.push_back(b);
        b=new pathbox(1,1,0,0,this);//4
        box.push_back(b);
        b=new pathbox(1,1,1,0,this);//5
        box.push_back(b);
        b=new pathbox(0,1,1,0,this);//6
        box.push_back(b);
        b=new pathbox(1,1,0,0,this);//7
        box.push_back(b);
        b=new pathbox(0,1,1,0,this);//8
        box.push_back(b);
        b=new pathbox(1,0,0,1,this);//9
        box.push_back(b);
        b=new pathbox(0,1,1,0,this);//10
        box.push_back(b);
        b=new pathbox(1,1,0,1,this);//11
        box.push_back(b);
        b=new pathbox(0,1,0,1,this);//12
        box.push_back(b);
        b=new pathbox(1,1,0,0,this);//13
        box.push_back(b);
        b=new pathbox(4,1,this);//14
        box.push_back(b);
        b=new pathbox(1,0,1,0,this);//15
        box.push_back(b);
        b=new pathbox(0,1,1,0,this);//16
        box.push_back(b);
        b=new pathbox(1,0,1,0,this);//17
        box.push_back(b);
        b=new pathbox(1,1,0,1,0,this);//18
        box.push_back(b);
        b=new pathbox(1,1,0,0,this);//19
        box.push_back(b);
        b=new pathbox(1,0,1,0,this);//20
        box.push_back(b);
        b=new pathbox(1,0,0,1,this);//21
        box.push_back(b);
        b=new pathbox(1,0,1,0,this);//22
        box.push_back(b);
        b=new pathbox(0,1,1,0,this);//23
        box.push_back(b);
        b=new pathbox(0,1,0,1,this);//24
        box.push_back(b);
        b=new pathbox(1,1,0,1,this);//25
        box.push_back(b);
        b=new pathbox(1,0,0,1,this);//26
        box.push_back(b);
        b=new pathbox(0,0,1,1,this);//27
        box.push_back(b);
        b=new pathbox(1,0,1,0,this);//28
        box.push_back(b);
        b=new pathbox(0,1,0,1,this);//29
        box.push_back(b);
        b=new pathbox(1,1,0,1,0,this);//30
        box.push_back(b);
        b=new pathbox(1,0,1,0,this);//31
        box.push_back(b);
        b=new pathbox(0,0,1,1,this);//32
        box.push_back(b);
        b=new pathbox(1,0,1,0,this);//33
        box.push_back(b);
        b=new pathbox(0,1,0,1,this);//34
        box.push_back(b);
        b=new pathbox(1,0,0,1,this);//35
        box.push_back(b);
        b=new pathbox(1,0,1,0,this);//36
        box.push_back(b);
        b=new pathbox(1,0,1,0,this);//37
        box.push_back(b);
        b=new pathbox(1,1,0,0,this);//38
        box.push_back(b);
        b=new pathbox(1,0,0,1,this);//39
        box.push_back(b);
        b=new pathbox(1,1,0,1,0,this);//40
        box.push_back(b);
        b=new pathbox(1,0,1,0,this);//41
        box.push_back(b);
        b=new pathbox(1,1,0,0,this);//42
        box.push_back(b);
        b=new pathbox(0,0,1,1,this);//43
        box.push_back(b);
        b=new pathbox(1,0,0,1,this);//44
        box.push_back(b);
        b=new pathbox(1,0,0,1,this);//45
        box.push_back(b);
        b=new pathbox(1,1,1,0,this);//46
        box.push_back(b);
        b=new pathbox(1,1,this);//47
        box.push_back(b);
        b=new pathbox(1,1,0,0,this);//48
        box.push_back(b);
    commoncha();
}
void MainWindow::chapter4()
{
    chaptercoise=4;
    red=29;
       green[0]=4,green[1]=32;
       gr=2;
       go=4;
       border=9;
       sln=0;
       gold[0]=0,gold[1]=17,gold[2]=38,gold[3]=69;
       pathbox *b=new pathbox(4,1,this);//0
       box.push_back(b);
       b=new pathbox(1,1,0,1,this);//1
       box.push_back(b);
       b=new pathbox(0,1,1,0,this);//2
       box.push_back(b);
       b=new pathbox(0,1,1,1,this);//3
       box.push_back(b);
       b=new pathbox(2,1,1,1,0,this);//4
       box.push_back(b);
       b=new pathbox(1,1,1,0,this);//5
       box.push_back(b);
       b=new pathbox(0,1,1,0,this);//6
       box.push_back(b);
       b=new pathbox(0,1,1,0,this);//7
       box.push_back(b);
       b=new pathbox(this);//8
       box.push_back(b);
       b=new pathbox(this);//9
       box.push_back(b);
       b=new pathbox(1,0,0,1,this);//10
       box.push_back(b);
       b=new pathbox(this);//11
       box.push_back(b);
       b=new pathbox(1,1,0,1,this);//12
       box.push_back(b);
       b=new pathbox(1,1,0,0,this);//13
       box.push_back(b);
       b=new pathbox(1,1,0,1,this);//14
       box.push_back(b);
       b=new pathbox(this);//15
       box.push_back(b);
       b=new pathbox(1,0,1,1,this);//16
       box.push_back(b);
       b=new pathbox(3,1,this);//17
       box.push_back(b);
       b=new pathbox(this);//18
       box.push_back(b);
       b=new pathbox(this);//19
       box.push_back(b);
       b=new pathbox(1,0,1,1,this);//20
       box.push_back(b);
       b=new pathbox(0,0,1,1,this);//21
       box.push_back(b);
       b=new pathbox(1,0,1,0,this);//22
       box.push_back(b);
       b=new pathbox(1,1,0,0,this);//23
       box.push_back(b);
       b=new pathbox(1,1,0,0,this);//24
       box.push_back(b);
       b=new pathbox(this);//25
       box.push_back(b);
       b=new pathbox(this);//26
       box.push_back(b);
       b=new pathbox(this);//27
       box.push_back(b);
       b=new pathbox(this);//28
       box.push_back(b);
       b=new pathbox(1,0,this);//29
       box.push_back(b);
       b=new pathbox(0,1,0,1,this);//30
       box.push_back(b);
       b=new pathbox(1,0,1,0,this);//31
       box.push_back(b);
       b=new pathbox(1,1,1,0,1,this);//32
       box.push_back(b);
       b=new pathbox(1,1,0,0,this);//33
       box.push_back(b);
       b=new pathbox(this);//34
       box.push_back(b);
       b=new pathbox(this);//35
       box.push_back(b);
       b=new pathbox(0,1,0,1,this);//36
       box.push_back(b);
       b=new pathbox(0,0,1,1,this);//37
       box.push_back(b);
       b=new pathbox(2,1,this);//38
       box.push_back(b);
       b=new pathbox(1,1,0,0,this);//39
       box.push_back(b);
       b=new pathbox(0,1,1,0,this);//40
       box.push_back(b);
       b=new pathbox(1,0,1,0,this);//41
       box.push_back(b);
       b=new pathbox(this);//42
       box.push_back(b);
       b=new pathbox(this);//43
       box.push_back(b);
       b=new pathbox(this);//44
       box.push_back(b);
       b=new pathbox(1,1,0,0,this);//45
       box.push_back(b);
       b=new pathbox(0,1,1,0,this);//46
       box.push_back(b);
       b=new pathbox(this);//47
       box.push_back(b);
       b=new pathbox(0,0,1,1,this);//48
       box.push_back(b);
       b=new pathbox(this);//49
       box.push_back(b);
       b=new pathbox(1,1,1,0,this);//50
       box.push_back(b);
       b=new pathbox(this);//51
       box.push_back(b);
       b=new pathbox(0,1,1,0,this);//52
       box.push_back(b);
       b=new pathbox(this);//53
       box.push_back(b);
       b=new pathbox(1,1,0,0,this);//54
       box.push_back(b);
       b=new pathbox(1,0,0,1,this);//55
       box.push_back(b);
       b=new pathbox(0,1,0,1,this);//56
       box.push_back(b);
       b=new pathbox(this);//57
       box.push_back(b);
       b=new pathbox(0,0,1,1,this);//58
       box.push_back(b);
       b=new pathbox(1,1,0,0,this);//59
       box.push_back(b);
       b=new pathbox(0,1,1,1,this);//60
       box.push_back(b);
       b=new pathbox(0,1,1,0,this);//61
       box.push_back(b);
       b=new pathbox(this);//62
       box.push_back(b);
       b=new pathbox(1,0,1,0,this);//63
       box.push_back(b);
       b=new pathbox(0,0,1,1,this);//64
       box.push_back(b);
       b=new pathbox(0,0,1,1,this);//65
       box.push_back(b);
       b=new pathbox(1,0,1,1,this);//66
       box.push_back(b);
       b=new pathbox(0,1,1,0,this);//67
       box.push_back(b);
       b=new pathbox(1,0,1,0,this);//68
       box.push_back(b);
       b=new pathbox(1,1,this);//69
       box.push_back(b);
       b=new pathbox(this);//70
       box.push_back(b);
       b=new pathbox(this);//71
       box.push_back(b);
       b=new pathbox(this);//72
       box.push_back(b);
       b=new pathbox(this);//73
       box.push_back(b);
       b=new pathbox(this);//74
       box.push_back(b);
       b=new pathbox(this);//75
       box.push_back(b);
       b=new pathbox(this);//76
       box.push_back(b);
       b=new pathbox(this);//77
       box.push_back(b);
       b=new pathbox(this);//78
       box.push_back(b);
       b=new pathbox(this);//79
       box.push_back(b);
       b=new pathbox(this);//80
       box.push_back(b);
    commoncha();
}
void MainWindow::chapter5()
{
        chaptercoise=5;
        red=86;
           green[0]=4,green[1]=59,green[2]=63,green[3]=79;
           gr=4;
           go=3;
           border=11;
           sln=0;
           gold[0]=19,gold[1]=35,gold[2]=102;
           pathbox *b=new pathbox(this);//0
           box.push_back(b);
           b=new pathbox(this);//1
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//2
           box.push_back(b);
           b=new pathbox(0,1,1,1,this);//3
           box.push_back(b);
           b=new pathbox(2,1,1,1,0,this);//4
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//5
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//6
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//7
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//8
           box.push_back(b);
           b=new pathbox(this);//9
           box.push_back(b);
           b=new pathbox(this);//10
           box.push_back(b);
           b=new pathbox(this);//11
           box.push_back(b);
           b=new pathbox(this);//12
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//13
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//14
           box.push_back(b);
           b=new pathbox(this);//15
           box.push_back(b);
           b=new pathbox(this);//16
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//17
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//18
           box.push_back(b);
           b=new pathbox(3,1,this);//19
           box.push_back(b);
           b=new pathbox(this);//20
           box.push_back(b);
           b=new pathbox(this);//21
           box.push_back(b);
           b=new pathbox(this);//22
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//23
           box.push_back(b);
           b=new pathbox(0,1,1,0,this);//24
           box.push_back(b);
           b=new pathbox(0,1,1,0,this);//25
           box.push_back(b);
           b=new pathbox(1,0,1,1,this);//26
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//27
           box.push_back(b);
           b=new pathbox(1,1,0,1,this);//28
           box.push_back(b);
           b=new pathbox(this);//29
           box.push_back(b);
           b=new pathbox(this);//30
           box.push_back(b);
           b=new pathbox(this);//31
           box.push_back(b);
           b=new pathbox(this);//32
           box.push_back(b);
           b=new pathbox(this);//33
           box.push_back(b);
           b=new pathbox(1,1,0,1,this);//34
           box.push_back(b);
           b=new pathbox(2,1,this);//35
           box.push_back(b);
           b=new pathbox(this);//36
           box.push_back(b);
           b=new pathbox(this);//37
           box.push_back(b);
           b=new pathbox(this);//38
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//39
           box.push_back(b);
           b=new pathbox(1,0,0,1,this);//40
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//41
           box.push_back(b);
           b=new pathbox(this);//42
           box.push_back(b);
           b=new pathbox(this);//43
           box.push_back(b);
           b=new pathbox(this);//44
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//45
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//46
           box.push_back(b);
           b=new pathbox(this);//47
           box.push_back(b);
           b=new pathbox(this);//48
           box.push_back(b);
           b=new pathbox(this);//49
           box.push_back(b);
           b=new pathbox(1,0,1,1,this);//50
           box.push_back(b);
           b=new pathbox(this);//51
           box.push_back(b);
           b=new pathbox(1,0,0,1,this);//52
           box.push_back(b);
           b=new pathbox(this);//53
           box.push_back(b);
           b=new pathbox(this);//54
           box.push_back(b);
           b=new pathbox(this);//55
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//56
           box.push_back(b);
           b=new pathbox(0,1,1,0,this);//57
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//58
           box.push_back(b);
           b=new pathbox(3,1,0,1,1,this);//59
           box.push_back(b);
           b=new pathbox(this);//60
           box.push_back(b);
           b=new pathbox(this);//61
           box.push_back(b);
           b=new pathbox(1,0,1,1,this);//62
           box.push_back(b);
           b=new pathbox(4,0,1,1,1,this);//63
           box.push_back(b);
           b=new pathbox(1,0,0,1,this);//64
           box.push_back(b);
           b=new pathbox(this);//65
           box.push_back(b);
           b=new pathbox(this);//66
           box.push_back(b);
           b=new pathbox(1,0,1,1,this);//67
           box.push_back(b);
           b=new pathbox(0,1,1,0,this);//68
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//69
           box.push_back(b);
           b=new pathbox(this);//70
           box.push_back(b);
           b=new pathbox(0,1,1,0,this);//71
           box.push_back(b);
           b=new pathbox(this);//72
           box.push_back(b);
           b=new pathbox(this);//73
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//74
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//75
           box.push_back(b);
           b=new pathbox(this);//76
           box.push_back(b);
           b=new pathbox(this);//77
           box.push_back(b);
           b=new pathbox(1,0,0,1,this);//78
           box.push_back(b);
           b=new pathbox(1,1,0,1,1,this);//79
           box.push_back(b);
           b=new pathbox(0,1,1,0,this);//80
           box.push_back(b);
           b=new pathbox(0,1,1,0,this);//81
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//82
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//83
           box.push_back(b);
           b=new pathbox(this);//84
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//85
           box.push_back(b);
           b=new pathbox(1,0,this);//86
           box.push_back(b);
           b=new pathbox(this);//87
           box.push_back(b);
           b=new pathbox(this);//88
           box.push_back(b);
           b=new pathbox(this);//89
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//90
           box.push_back(b);
           b=new pathbox(this);//91
           box.push_back(b);
           b=new pathbox(this);//92
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//93
           box.push_back(b);
           b=new pathbox(this);//94
           box.push_back(b);
           b=new pathbox(this);//95
           box.push_back(b);
           b=new pathbox(this);//96
           box.push_back(b);
           b=new pathbox(this);//97
           box.push_back(b);
           b=new pathbox(this);//98
           box.push_back(b);
           b=new pathbox(this);//99
           box.push_back(b);
           b=new pathbox(this);//100
           box.push_back(b);
           b=new pathbox(1,0,0,1,this);//101
           box.push_back(b);
           b=new pathbox(4,1,this);//102
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//103
           box.push_back(b);
           b=new pathbox(0,1,1,0,this);//104
           box.push_back(b);
           b=new pathbox(this);//105
           box.push_back(b);
           b=new pathbox(this);//106
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//107
           box.push_back(b);
           b=new pathbox(this);//108
           box.push_back(b);
           b=new pathbox(this);//109
           box.push_back(b);
           b=new pathbox(this);//110
           box.push_back(b);
           b=new pathbox(this);//111
           box.push_back(b);
           b=new pathbox(this);//112
           box.push_back(b);
           b=new pathbox(1,0,0,1,this);//113
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//114
           box.push_back(b);
           b=new pathbox(1,1,1,0,this);//115
           box.push_back(b);
           b=new pathbox(0,0,1,1,this);//116
           box.push_back(b);
           b=new pathbox(1,1,0,0,this);//117
           box.push_back(b);
           b=new pathbox(1,0,1,0,this);//118
           box.push_back(b);
           b=new pathbox(this);//119
           box.push_back(b);
           b=new pathbox(this);//120
           box.push_back(b);
    commoncha();
}
void MainWindow::chapter6()
{
    bool static ct=true;
    if(ct==true)
    {
        ui->backsys->show();
        uimanager->setCurrentWidget(ui->backsys);
            chaptercoise=6;
            delete ui->centralWidget->layout();
            glayout=new QGridLayout();
        ct=false;
        for(int i=0;i<9;i++)
            mitem[i]->hide();
    QFont font("Forte",15,75);
    ui->begin->setFont(font);
    ui->begin->setText(tr(" the city would rise again when the stars were right\nthe secret priests would take great Cthulhu from His tomb\nto revive His subjects and resume His rule of earth"));
        ui->begin->setGeometry(width()*2/3,height()*2/3,width(),height()/6);
        ui->begin->setStyleSheet("color:red");
    ui->begin->show();
    glayout->addWidget(ui->begin);
    ui->backsys->setLayout(glayout);
    word->start(10000);
    return;
    }
    chaptercoise=6;
    border=3;
    go=1;
    gr=0;
    red=7;
    sln=0;
    gold[0]=1;
    pathbox *b;
    for(int i=0;i<9;i++)
        if(i==1)
        {
            b=new pathbox(2,1,this);
            box.push_back(b);
            connect(box[i],&pathbox::clicked,this,&MainWindow::chapter6spec);
        }
    else
            if(i==7)
            {
                b=new pathbox(1,0,this);
                box.push_back(b);
            }
    else
            {
                b=new pathbox(this);
                box.push_back(b);
            }
    commoncha();
}
void MainWindow::chapterbackto0()
{
    warn=new QSound("warn.wav");
            srand(time(0));
    hidetimecout=0;
    border=15;
    go=4;
    gr=0;
    sln=0;
    chaptercoise=-2;
    red=112;
    gold[0]=0;gold[1]=14;gold[2]=210;gold[3]=224;
        pathbox *b;
    for(int i=0;i<225;i++)
    {
        if(i==red)
        {
            b=new pathbox(5,0,this);
            box.push_back(b);
            continue;
        }
if(i==0)
{
    b=new pathbox(2,1,this);
    box.push_back(b);
   continue;
}
if(i==14)
{
    b=new pathbox(3,1,this);
    box.push_back(b);
    continue;
}
if(i==210)
{
    b=new pathbox(4,1,this);
    box.push_back(b);
    continue;
}
if(i==224)
{
    b=new pathbox(1,1,this);
    box.push_back(b);
    continue;
}
        if(rand()%7==0)
        {
            b=new pathbox(this);
            box.push_back(b);
        }
        else{
            int nums=0,a[4];
            do{
                nums=0;
                for(int i=0;i<4;i++)
                {a[i]=rand()%2;
                if(a[i]==1)
                    nums++;
                }
            }
            while(nums<2||nums>3);
        b=new pathbox(a[0],a[1],a[2],a[3],this);
        box.push_back(b);
        }
        }
    commoncha();
}
