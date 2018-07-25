#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QMovie>
#include<QAbstractButton>
#include<vector>
#include<QTimer>
#include<QPushButton>
#include<QGridLayout>
#include"piontstack.h"
#include"pathbox.h"
#include"specline.h"
#include<QQuickWidget>
#include<QTime>
#include"be.h"
#include"numbergame.h"
#include<QSound>
#include<QStackedWidget>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include<QSequentialAnimationGroup>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
     void keyPressEvent(QKeyEvent *event);
private slots:
        void drawline();
        void switchstar();
        void later(int center,int h,int b,int l,int r);
        void changestart();
        void exchangetwo();
        void clearbox();
        void chapter0();
        void chapter1();
        void chapter2();
        void chapter3();
        void chapter4();
        void chapter5();
        void chapter6();
        void chapterrand();
        void chapter6spec();
void endword();
private:
int hidetimecout;
bool restpart,onlyone1,onlyone2,onlyone3,onlyone4;
bool winlist[7],wintrue;
        QTimer *word;
                void chapterbackto0();
                void addchange();
                void turnred();
        QStackedWidget *uimanager;
        QWidget *cha6;
        QSound *bgm[2];
        QSound *warn;
        int chapexchange;
        void fini();
        bool fi;
        void outg();
        void ing();
        void gainmainwin();
        void numg(int gog);
        numbergame *ng;
        QPushButton *mitem[9];
        be *hs;
        void ingame();
        QPushButton *test;
        void commoncha();
        QTime *timec;
        QTimer *timer;
        QGridLayout *glayout;
        QGridLayout *tlayout;
        bool mw,gw;
        int chaptercoise;
        void killguard(int i);
        bool greent(int i,int gr);
            bool goldt(int i,int go);
        void exchanget(pathbox &b1,pathbox&b2);
        bool exchangestar;
        QQuickWidget *rog[4],*ror,*roy[4];
        QQuickWidget * row[2];
        int red,gold[4],border,green[4],gr,go,sln;
            std::vector<piontstack*> pst;
        bool openlight;
        std::vector<pathbox *> box;
        std::vector<pathbox *> redbox;
        std::vector<pathbox *> guardbox;
        int changes[2];
        sline *sl[4];
     double x1,y1,x2,y2;
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent *);
    void randborder(int red,int i);
};
#endif // MAINWINDOW_H

