#include "numbergame.h"
#include "ui_numbergame.h"
#include"exit.h"
#include<QKeyEvent>
#include<QDialog>
#include<QPalette>
#include<QMovie>
#include<QPixmap>
#include<QPainter>
#include<QDebug>
#include<QPushButton>
#include<QTimer>
#include"piontstack.h"
#include<Qsize>
#include<Qicon>
#include<QQuickWidget>
#include<QGridLayout>
#include<cmath>
#include"pathbox.h"
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include<QSequentialAnimationGroup>
#include<QPainterPath>
#include<QTimer>
#include<QLabel>
#include"specline.h"
#include<cstdlib>
#include<ctime>
#include<QFont>
#include<QFontDatabase>
     void numbergame::keyPressEvent(QKeyEvent *event)
     {
                     nums=0;
                     close();
     }
numbergame::numbergame(int gog, QWidget *parent, bool zreo) :gogg(gog),
    QDialog(parent,Qt::FramelessWindowHint),
    ui(new Ui::numbergame)
{
    int id = QFontDatabase::addApplicationFont( QString(":/font/Let's go Digital Regular.ttf"));
    QString msyh = QFontDatabase::applicationFontFamilies ( id ).at(0);
    ui->setupUi(this);
    QFont font(msyh,100,75);
     QFont font2(msyh,24,75);
    glayout=new QGridLayout();
    gold=new QLabel(this);
    gold->setFont(font);
    gold->setAlignment(Qt::AlignHCenter);
    for(int i=0;i<4;i++)
    {
        num[i]=new QLabel(this);
        num[i]->setFont(font2);
    }
    for(int i=0;i<3;i++)
    {
        sy[i]=new QPushButton(this);
        sy[i]->setFont(font2);
        sy[i]->setFlat(true);
        sy[i]->setCursor(Qt::PointingHandCursor);
    }
    is=new QLabel(this);
    is->setFont(font2);
    ans=new QLabel(this);
    ans->setFont(font2);
    is->setText("=");
    ans->setText("------");
    glayout->addWidget(gold,0,0,1,14,Qt::AlignHCenter);
    for(int i=0;i<3;i++)
        glayout->addWidget(num[i],2,2*i,1,1,Qt::AlignHCenter),
                glayout->addWidget(sy[i],2,2*i+1,1,1,Qt::AlignHCenter);
    glayout->addWidget(num[3],2,6,1,1,Qt::AlignHCenter);
    glayout->addWidget(is,2,7,1,1,Qt::AlignHCenter);
    glayout->addWidget(ans,2,8,1,6,Qt::AlignHCenter);
    setLayout(glayout);
    srand(time(0));
    do{
    for(int i=0;i<4;i++)
    {
        numpart[i]=rand()%20+1;
        if(zreo==true)
            numpart[i]=1;
    num[i]->setText(QString::number(numpart[i], 10) );
    }
    int numt[4];
    for(int i=0;i<4;i++)
        numt[i]=numpart[i];
    for(int i=0;i<3;i++)
    {
        switch(rand()%4)
        {
        case 0:sypart[i]=0;sy[i]->setText(" ");break;
        case 1:sypart[i]=1;sy[i]->setText(" ");break;
        case 2:sypart[i]=0;sy[i]->setText(" ");numt[i+1]*=numt[i];numt[i]=0;break;
        case 3:sypart[i]=0;sy[i]->setText(" ");if(numt[i]%numt[i+1]==0){numt[i+1]=numt[i]/numt[i+1]; numt[i]=0;}else {i--;break;}
        }
    }
    nums=numt[0];
    for(int i=0;i<3;i++)
        if(sypart[i]!=1)
            nums+=numt[i+1];
    else
        {
            nums-=numt[i+1];
            if(numt[i+1]==0){i+1<3?sypart[i+1]=1:0;}
        }
    }
    while(nums<=0);
    if(zreo==true)
        nums=4;
    gold->setText(QString::number(nums, 10));
    for(int i=0;i<3;i++)
    connect(sy[i],&QPushButton::clicked,this,&numbergame::changesy);
    if(gog==0)
    {
        gold->setStyleSheet("color:green");
        for(int i=0;i<4;i++)
            num[i]->setStyleSheet("color:green");
        for(int i=0;i<3;i++)
            sy[i]->setStyleSheet("color:green");
        is->setStyleSheet("color:green");
        ans->setStyleSheet("color:green");
    }
    else
        if(gog==1)
    {
        gold->setStyleSheet("color:yellow");
        for(int i=0;i<4;i++)
            num[i]->setStyleSheet("color:yellow");
        for(int i=0;i<3;i++)
            sy[i]->setStyleSheet("color:yellow");
        is->setStyleSheet("color:yellow");
        ans->setStyleSheet("color:yellow");
    }
    else
        {
            gold->setStyleSheet("color:red");
            for(int i=0;i<4;i++)
                num[i]->setStyleSheet("color:red");
            for(int i=0;i<3;i++)
                sy[i]->setStyleSheet("color:red");
            is->setStyleSheet("color:red");
            ans->setStyleSheet("color:red");
        }
    update();
}
numbergame::~numbergame()
{
    delete ui;
    delete glayout;
}
void numbergame::changesy()
{
    QPushButton *button=qobject_cast<QPushButton*>(sender());
    if(button->text()== " ")button->setText("+");
    else
    if(button->text()== "+")button->setText("-");
    else
    if(button->text()== "-")button->setText("*");
    else
    if(button->text()== "*")button->setText("/");
    else
    if(button->text()== "/")button->setText("+");
    bool calc=true;
    for(int i=0;i<3;i++)
        if(sy[i]->text()==" ")
            calc=false;
    if(calc==true)
    {
        int numt[4];
        for(int i=0;i<4;i++)
            numt[i]=numpart[i];
        for(int i=0;i<3;i++)
        {
            if(sy[i]->text()=="+")sypart[i]=0;
            if(sy[i]->text()=="-")sypart[i]=1;
            if(sy[i]->text()=="*"){sypart[i]=0;numt[i+1]*=numt[i];numt[i]=0;}
            if(sy[i]->text()=="/"){sypart[i]=0;if(numt[i]%numt[i+1]==0){numt[i+1]=numt[i]/numt[i+1]; numt[i]=0;}}
        }
        int numa=numt[0];
        for(int i=0;i<3;i++)
            if(sypart[i]!=1)
                numa+=numt[i+1];
            else
                {
                    numa-=numt[i+1];
                    if(numt[i+1]==0){i+1<3?sypart[i+1]=1:0;}
                }
        ans->setText(QString::number(numa, 10));
        if(numa==nums)
            this->close();
    }
}
void numbergame::paintEvent(QPaintEvent *)
{
    if(gogg==0)
    {
    QPixmap back = QPixmap(":/img/numgg").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), back);
    }
    else
        if(gogg==1)
    {
        QPixmap back = QPixmap(":/img/numgy").scaled(this->size());
        QPainter painter(this);
        painter.drawPixmap(this->rect(), back);
    }
    else
        {
            QPixmap back = QPixmap(":/img/numgr").scaled(this->size());
            QPainter painter(this);
            painter.drawPixmap(this->rect(), back);
        }
}
