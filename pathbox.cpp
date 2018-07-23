#include"pathbox.h"
#include<QWidget>
#include<QIcon>
#include<QPoint>
#include<QApplication>
pathbox::pathbox(int head,int bottom,int left,int right,QWidget *parent):guard(0),block(0),inlines(0),head(head),bottom(bottom),left(left),right(right),QPushButton(parent)
{
    setFlat(true);
    setCursor(Qt::PointingHandCursor);
    QIcon icon(tr(":/img/star-w"));
    setIcon(icon);
    setStyleSheet("QPushButton:pressed{border-image: url(:/img/star-w);}");
}
pathbox::pathbox(int direct,int boe,QWidget *parent):guard(0),block(0),inlines(0),QPushButton(parent)
{
    setFlat(true);
     setCursor(Qt::PointingHandCursor);
    switch(direct)
    {
    case 0:head=0,bottom=0,left=0,right=0;break;
    case 5:head=1,bottom=1,left=1,right=1;break;
    case 1:head=1,bottom=0,left=0,right=0;break;
    case 2:head=0,bottom=1,left=0,right=0;break;
    case 3:head=0,bottom=0,left=1,right=0;break;
    case 4:head=0,bottom=0,left=0,right=1;break;
    }
    QIcon icon;
    if(boe==0)
    icon.addFile(tr(":/img/star-r")),setStyleSheet("QPushButton:pressed{border-image: url(:/img/star-r);}");
    else
    icon.addFile(tr(":/img/star-y")),setStyleSheet("QPushButton:pressed{border-image: url(:/img/star-y);}");
    setIcon(icon);
}
pathbox::pathbox(QWidget *parent):guard(0),inlines(0),block(1),head(0),bottom(0),left(0),right(0),QPushButton(parent)
{
    setFlat(true);
    QIcon icon(tr(":/img/star-n"));
    setIcon(icon);
    setStyleSheet("QPushButton:pressed{border-image: url(:/img/star-n);}");
}
pathbox::pathbox(int guard,int head,int bottom,int left,int right, QWidget *parent):block(0),guard(guard),head(head),bottom(bottom),left(left),right(right),QPushButton(parent)
{
    setFlat(true);
    setCursor(Qt::PointingHandCursor);
    QIcon icon(tr(":/img/star-g"));
    setIcon(icon);
    setStyleSheet("QPushButton:pressed{border-image: url(:/img/star-g);}");
}
pathbox::~pathbox(){}
void pathbox::switchbox()
{
    int temp=head;
    head=left;
    left=bottom;
    bottom=right;
    right=temp;
}
int pathbox::sitx()
{
   return  pos().x()+width()/2;
}
int pathbox::sity()
{
   return  pos().y()+height()/2;
}
QPoint pathbox::sitp()
{
   return  QPoint(pos().x()+width()/2,pos().y()+height()/2);
}

