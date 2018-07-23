#include"specline.h"
sline::sline(pathbox& b1, pathbox &b2, int sit):vor(0),b1(b1),b2(b2),sit(sit)
{
       xc=0,yc=0;
}
sline::~sline()
{}
void sline::calc()
{
    xc=(b1.sitx()+b2.sitx())/2,yc=(b1.sity()+b2.sity())/2;
if(sit==0)
{
        if((b1.sitx()-b2.sitx())*(b1.sity()-b2.sity())>=0)
            xc+=(b1.sitx()-b2.sitx())*(b1.sitx()-b2.sitx())/625,yc-=(b1.sity()-b2.sity())*(b1.sity()-b2.sity())/625;
        else
             xc-=(b1.sitx()-b2.sitx())*(b1.sitx()-b2.sitx())/625,yc-=(b1.sity()-b2.sity())*(b1.sity()-b2.sity())/625;
}
else
{

if((b1.sitx()-b2.sitx())*(b1.sity()-b2.sity())>=0)
    xc-=(b1.sitx()-b2.sitx())*(b1.sitx()-b2.sitx())/625,yc+=(b1.sity()-b2.sity())*(b1.sity()-b2.sity())/625;
else
     xc+=(b1.sitx()-b2.sitx())*(b1.sitx()-b2.sitx())/625,yc+=(b1.sity()-b2.sity())*(b1.sity()-b2.sity())/625;
}
}
