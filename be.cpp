#include<be.h>
#include<QDebug>
be::be(int hp,int sp):hp(hp),sp(sp)
{
}
be::~be()
{}
void be::changehp(int n)
{
   hp+=n;
   if(hp>100)
       hp=100;
   if(hp<0)
       hp=0;
}
void be::changesp(int times, int number)
{
    if(number<=100)
            sp+=(number-times/500);
    else
    sp+=(number*100/(251)-times/500);
    if(sp>100)
        sp=100;
    if(sp<0)
    {changehp(sp);
    sp=0;}
}
