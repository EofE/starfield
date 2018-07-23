#ifndef SPECLINE_H
#define SPECLINE_H
#include"pathbox.h"
class sline
{
public:
pathbox &b1, &b2;
int xc,yc,sit,vor;
    sline(pathbox &b1,pathbox &b2,int sit);
    ~sline();
    void calc();
};
#endif // SPECLINE_H
