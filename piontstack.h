#ifndef PIONTSTACK_H
#define PIONTSTACK_H
#include<QPushButton>
class piontstack
{
public:
    QPushButton *b1,*b2;
    double xo,xt,yo,yt;
    piontstack(QPushButton *b1,QPushButton *b2):b1(b1),b2(b2){
        xo=(b1->pos().x()+10);
        xt=(b2->pos().x()+10);
        yo=(b2->pos().x()+10);
        yt=(b2->pos().y()+10);
    }
    piontstack(double xo,double yo,double xt,double yt):xo(xo),xt(xt),yo(yo),yt(yt){}
    ~piontstack(){}
    int x1() const
    {
        return xo;
    }
    int x2() const
    {
        return xt;
    }
    int y1() const
    {
        return yo;
    }
    int y2() const
    {
        return yt;
    }
    bool operator ==(const piontstack & rp)
    {
      if((x1()==rp.x1()&&y1()==rp.y1()&&x2()==rp.x2()&&y2()==rp.y2())||(x1()==rp.x2()&&y1()==rp.y2()&&x2()==rp.y1()&&y2()==rp.y1()))
           return true;
      else
          return false;
    }
};
#endif // PIONTSTACK_H
