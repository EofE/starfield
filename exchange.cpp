#include "mainwindow.h"
#include"ui_mainwindow.h"
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
#include"numbergame.h"
#include"specline.h"
#include<QTime>
#include"be.h"
#include<ctime>
void MainWindow::changestart()
{
   if(chapexchange>0)
    {
       if(exchangestar==false)
       {
           exchangestar=true;
           for(int i=0;i<border*border-1;i++)
           if(box[i]->block==0&&i!=red&&goldt(i,go)&&greent(i,gr))
           {
               changes[0]=i;
               break;
           }
       changes[1]=-1;
       row[0]->show();
       row[0]->setClearColor(QColor(Qt::transparent));
       row[0]->setAttribute(Qt::WA_AlwaysStackOnTop);
       row[0]->setGeometry(box[changes[0]]->sitx()-box[changes[0]]->height()/2,box[changes[0]]->sity()-box[changes[0]]->height()/2,box[changes[0]]->height(),box[changes[0]]->height());
       }
       else
       {
           exchangestar=false;
           row[0]->hide();
           row[1]->hide();
       }
   }
}
void MainWindow::exchangetwo()
{
    openlight=false;
    update();
    exchanget(*box[changes[0]],*box[changes[1]]);
int x1=box[changes[0]]->pos().x(),y1=box[changes[0]]->pos().y(),x2=box[changes[1]]->pos().x(),y2=box[changes[1]]->pos().y();
    QPropertyAnimation *animation1=new QPropertyAnimation(box[changes[0]],"pos");
animation1->setDuration(1000);
animation1->setStartValue(QPoint(x1,y1));
animation1->setEndValue(QPoint(x2,y2));
QPropertyAnimation *animation2=new QPropertyAnimation(box[changes[1]],"pos");
animation2->setDuration(1000);
animation2->setStartValue(QPoint(x2,y2));
animation2->setEndValue(QPoint(x1,y1));
QPropertyAnimation *animation3=new QPropertyAnimation(box[changes[0]],"pos");
animation3->setDuration(0);
animation3->setStartValue(QPoint(x2,y2));
animation3->setEndValue(QPoint(x1,y1));
QPropertyAnimation *animation4=new QPropertyAnimation(box[changes[1]],"pos");
animation4->setDuration(0);
animation4->setStartValue(QPoint(x1,y1));
animation4->setEndValue(QPoint(x2,y2));
QParallelAnimationGroup *group1=new QParallelAnimationGroup;
group1->addAnimation(animation1);
group1->addAnimation(animation2);
QParallelAnimationGroup *group2=new QParallelAnimationGroup;
group2->addAnimation(animation3);
group2->addAnimation(animation4);
QSequentialAnimationGroup *group=new QSequentialAnimationGroup;
group->addAnimation(group1);
group->addAnimation(group2);
group->start();
chapexchange--;
    ui->exchange->setText(QString::number(chapexchange, 10));
exchangestar=false;
hs->changesp(7500,0);
ui->HP->setValue(hs->hp);
ui->SP->setValue(hs->sp);
row[0]->hide();
row[1]->hide();
}
void MainWindow::exchanget(pathbox &b1,pathbox&b2)
{
    int temph=b1.head,tempb=b1.bottom,templ=b1.left,tempr=b1.right;
    b1.head=b2.head,b1.bottom=b2.bottom,b1.left=b2.left,b1.right=b2.right;
    b2.head=temph,b2.bottom=tempb,b2.left=templ,b2.right=tempr;
}
