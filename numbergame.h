#ifndef NUMBERGAME_H
#define NUMBERGAME_H

#include <QDialog>
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
namespace Ui {
class numbergame;
}

class numbergame : public QDialog
{
    Q_OBJECT
public:
    int nums;
    explicit numbergame(int gog,QWidget *parent = 0,bool zreo=false);
    ~numbergame();
protected:
     void keyPressEvent(QKeyEvent *event);
private slots:
    void changesy();
private:
        void paintEvent(QPaintEvent *);
    int gogg;
    QGridLayout *glayout;
    QLabel *gold,*num[4],*is,*ans;
    int numpart[4],sypart[3];
    QPushButton *sy[3];
    Ui::numbergame *ui;
};

#endif // NUMBERGAME_H
