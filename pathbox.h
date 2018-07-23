#ifndef PATHBOX_H
#define PATHBOX_H
#include<QWidget>
#include<QPushButton>
#include<QPoint>
class pathbox:public QPushButton
{
public:
    explicit pathbox(int head, int bottom, int left, int right, QWidget *parent = 0);
    explicit pathbox(int direct,int boe,QWidget *parent);
     explicit pathbox(QWidget *parent);
         explicit pathbox(int guard,int head,int bottom,int left,int right, QWidget *parent);
    ~pathbox();
   void switchbox();
   QPoint sitp();
   int sitx();
   int sity();
    int head,bottom,left,right,inlines,block,guard;
};
#endif // PATHBOX_H
