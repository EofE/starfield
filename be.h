#ifndef BE_H
#define BE_H
class be
{
public:
    int hp;
    int sp;
    be(int hp,int sp);
    ~be();
    void changehp(int n);
    void changesp(int times,int number);
};
#endif // BE_H
