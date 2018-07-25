#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include"numbergame.h"
#include"specline.h"
#include<QTime>
#include"be.h"
#include<ctime>
#include<QSound>
#include<QStackedWidget>
#include<cstdlib>
#include<ctime>
#include<QFontDatabase>
#include<QtConcurrent/QtConcurrent>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    for(int i=0;i<6;i++)
    winlist[i]=false;
    ui->setupUi(this);
    uimanager=new QStackedWidget(this);
    uimanager->addWidget(ui->centralWidget);
    cha6=new QWidget(this);
    uimanager->addWidget(cha6);
    setCentralWidget(uimanager);
    ror=ui->quickWidget_3;
    rog[0]=ui->quickWidget_2;
    rog[1]=ui->quickWidget_4;
    rog[2]=ui->quickWidget_5;
    rog[3]=ui->quickWidget_6;
    roy[0]=ui->go1;
    roy[1]=ui->go2;
    roy[2]=ui->go3;
    roy[3]=ui->go4;
    row[0]=ui->quickWidget_7;
    row[1]=ui->quickWidget_8;
    mitem[0]=ui->les;
    mitem[1]=ui->chap0;
    mitem[2]=ui->res;
    mitem[3]=ui->chap1;
    mitem[4]=ui->chap2;
    mitem[5]=ui->chap3;
    mitem[6]=ui->chap4;
    mitem[7]=ui->chap5;
    mitem[8]=ui->chap6;
    restpart=true;
    outg();
    chaptercoise=0;
    wintrue=false;
    bgm[0]=new QSound("Horizon.wav");
    bgm[0]->setLoops(QSound::Infinite);
    bgm[1]=new QSound("finalwar.wav");
        bgm[1]->setLoops(QSound::Infinite);
    bgm[0]->play();
    bool static ct=true;
    if(ct==true)
    {
        uimanager->addWidget(ui->backsys);
        uimanager->setCurrentWidget(ui->backsys);
        delete ui->centralWidget->layout();
        glayout=new QGridLayout();
        ui->backsys->setSource(QUrl("qrc:/bsys.qml"));
        ui->backsys->setClearColor(QColor(Qt::transparent));
        ui->backsys->setAttribute(Qt::WA_AlwaysStackOnTop);
        ui->backsys->setGeometry(0,0,width(),height());
        ct=false;
        for(int i=0;i<9;i++)
            mitem[i]->hide();
    word=new QTimer(this);
    ui->begin->setGeometry(width()*2/3,height()*2/3,width(),height()/10);
    int id = QFontDatabase::addApplicationFont( QString(":/font/FORTE.TTF"));
    QString msyh = QFontDatabase::applicationFontFamilies ( id ).at(0);
    QFont font(msyh,15,75);
    ui->begin->setFont(font);
            glayout->addWidget(ui->begin);
            ui->backsys->setLayout(glayout);
    connect(word,&QTimer::timeout,this,&MainWindow::endword);
    word->start(10000);
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        Exit wexit(this);
        wexit.setWindowTitle(tr("Exit"));
        if(wexit.exec()==QDialog::Accepted)
                exit(0);
    }
    if(event->key()==Qt::Key_W)
    {
        if(exchangestar==true)
        {
            if(changes[1]==-1)
            {
                int side=changes[0]-border;
                while(side>=0&&(box[side]->block==1||side==red||!goldt(side,go)||!greent(side,gr)))
                    side-=border;
                if(side>=0&&box[side]->guard==0&&box[side]->block==0&&side!=red&&goldt(side,go)&&greent(side,gr))
                    changes[0]=side;
                row[0]->show();
                row[0]->setClearColor(QColor(Qt::transparent));
                row[0]->setAttribute(Qt::WA_AlwaysStackOnTop);
                row[0]->setGeometry(box[changes[0]]->sitx()-box[changes[0]]->height()/2,box[changes[0]]->sity()-box[changes[0]]->height()/2,box[changes[0]]->height(),box[changes[0]]->height());
            }
            else
            {
                int side=changes[1]-border;
                while(side>=0&&(box[side]->block==1||side==red||!goldt(side,go)||!greent(side,gr)))
                    side-=border;
                if(side>=0&&box[side]->guard==0&&box[side]->block==0&&side!=red&&goldt(side,go)&&greent(side,gr))
                    changes[1]=side;
                row[1]->show();
                row[1]->setClearColor(QColor(Qt::transparent));
                row[1]->setAttribute(Qt::WA_AlwaysStackOnTop);
                row[1]->setGeometry(box[changes[1]]->sitx()-box[changes[1]]->height()/2,box[changes[1]]->sity()-box[changes[1]]->height()/2,box[changes[0]]->height(),box[changes[0]]->height());
            }
        }
    }
    if(event->key()==Qt::Key_S)
    {
        if(exchangestar==true)
        {
            if(changes[1]==-1)
            {
                int side=changes[0]+border;
                while(side<=border*border-1&&(box[side]->block==1||side==red||!goldt(side,go)||!greent(side,gr)))
                    side+=border;
              if(side<=border*border-1&&box[side]->guard==0&&box[side]->block==0&&side!=red&&goldt(side,go)&&greent(side,gr))
                    changes[0]=side;
                row[0]->show();
                row[0]->setClearColor(QColor(Qt::transparent));
                row[0]->setAttribute(Qt::WA_AlwaysStackOnTop);
                row[0]->setGeometry(box[changes[0]]->sitx()-box[changes[0]]->height()/2,box[changes[0]]->sity()-box[changes[0]]->height()/2,box[changes[0]]->height(),box[changes[0]]->height());
            }
            else
            {
                int side=changes[1]+border;
                while(side<=border*border-1&&(box[side]->block==1||side==red||!goldt(side,go)||!greent(side,gr)))
                    side+=border;
              if(side<=border*border-1&&box[side]->guard==0&&box[side]->block==0&&side!=red&&goldt(side,go)&&greent(side,gr))
                    changes[1]=side;
                row[1]->show();
                row[1]->setClearColor(QColor(Qt::transparent));
                row[1]->setAttribute(Qt::WA_AlwaysStackOnTop);
                row[1]->setGeometry(box[changes[1]]->sitx()-box[changes[1]]->height()/2,box[changes[1]]->sity()-box[changes[1]]->height()/2,box[changes[0]]->height(),box[changes[0]]->height());
        }
        }
    }
    if(event->key()==Qt::Key_D)
    {
        if(exchangestar==true)
        {
            if(changes[1]==-1)
            {
                int  side=changes[0]+1;
                while(side<=border*border-1&&(box[side]->block==1||side==red||!goldt(side,go)||!greent(side,gr)))
                    side+=1;
              if(side<=border*border-1&&box[side]->guard==0&&box[side]->block==0&&side!=red&&goldt(side,go)&&greent(side,gr))
                    changes[0]=side;
                row[0]->show();
                row[0]->setClearColor(QColor(Qt::transparent));
                row[0]->setAttribute(Qt::WA_AlwaysStackOnTop);
                row[0]->setGeometry(box[changes[0]]->sitx()-box[changes[0]]->height()/2,box[changes[0]]->sity()-box[changes[0]]->height()/2,box[changes[0]]->height(),box[changes[0]]->height());
            }
            else
            {
                int  side=changes[1]+1;
                while(side<floor(changes[1]/border)*border+border&&(box[side]->block==1||side==red||!goldt(side,go)||!greent(side,gr)))
                    side+=1;
              if(side<floor(changes[1]/border)*border+border&&box[side]->guard==0&&box[side]->block==0&&side!=red&&goldt(side,go)&&greent(side,gr))
                    changes[1]=side;
                row[1]->show();
                row[1]->setClearColor(QColor(Qt::transparent));
                row[1]->setAttribute(Qt::WA_AlwaysStackOnTop);
                row[1]->setGeometry(box[changes[1]]->sitx()-box[changes[1]]->height()/2,box[changes[1]]->sity()-box[changes[1]]->height()/2,box[changes[0]]->height(),box[changes[0]]->height());
        }
    }
    }
    if(event->key()==Qt::Key_A)
    {
        if(exchangestar==true)
        {
            if(changes[1]==-1)
            {
                int  side=changes[0]-1;
                while(side>=0&&(box[side]->block==1||side==red||!goldt(side,go)||!greent(side,gr)))
                    side-=1;
              if(side>=0&&box[side]->guard==0&&box[side]->block==0&&side!=red&&goldt(side,go)&&greent(side,gr))
                    changes[0]=side;
                row[0]->show();
                row[0]->setClearColor(QColor(Qt::transparent));
                row[0]->setAttribute(Qt::WA_AlwaysStackOnTop);
                row[0]->setGeometry(box[changes[0]]->sitx()-box[changes[0]]->height()/2,box[changes[0]]->sity()-box[changes[0]]->height()/2,box[changes[0]]->height(),box[changes[0]]->height());
            }
            else
            {
                int  side=changes[1]-1;
                while(side>floor(changes[1]/border)*border-1&&(box[side]->block==1||side==red||!goldt(side,go)||!greent(side,gr)))
                    side-=1;
              if(side>floor(changes[1]/border)*border-1&&box[side]->guard==0&&box[side]->block==0&&side!=red&&goldt(side,go)&&greent(side,gr))
                    changes[1]=side;
                row[1]->show();
                row[1]->setClearColor(QColor(Qt::transparent));
                row[1]->setAttribute(Qt::WA_AlwaysStackOnTop);
                row[1]->setGeometry(box[changes[1]]->sitx()-box[changes[1]]->height()/2,box[changes[1]]->sity()-box[changes[1]]->height()/2,box[changes[0]]->height(),box[changes[0]]->height());
            }
        }
    }
    if(event->key()==Qt::Key_E)
    {
        if(exchangestar==true)
        {
            if(changes[1]==-1)
               {
                changes[1]=changes[0];
                row[1]->show();
                row[1]->setClearColor(QColor(Qt::transparent));
                row[1]->setAttribute(Qt::WA_AlwaysStackOnTop);
                row[1]->setGeometry(box[changes[1]]->sitx()-box[changes[1]]->height()/2,box[changes[1]]->sity()-box[changes[1]]->height()/2,box[changes[1]]->height(),box[changes[1]]->height());
            }
            else
                exchangetwo();

        }
    }
}
void MainWindow::paintEvent(QPaintEvent *)
{
    if(mw==false)
ingame();
    else
    {
        QPixmap back = QPixmap(":/img/starfield").scaled(this->size());
        QPainter painter(this);
        painter.drawPixmap(this->rect(), back);
    }

}
void MainWindow::switchstar()
{
   if(exchangestar==true||gw==true)
       return;
   pathbox *box=dynamic_cast<pathbox*>(sender());
   box->switchbox();
   openlight=!openlight;
   drawline();
   if(hs->hp<=0)
       return;

}
void MainWindow::drawline()
{
    restpart=false;
    if(exchangestar==true||gw==true)
        return;
        openlight=!openlight;
    while(!pst.empty())
    {
        int i=static_cast<int>(pst.size()-1);
                piontstack *ps=pst[i];
        pst.pop_back();
        delete ps;

    }
    for(int i=0;i<border*border;i++)
        box[i]->inlines=0;
    box[red]->inlines=1;
    int side=red-border;
   while(box[red]->head==1&&side>=0&&box[side]->block==1)
       side-=border;
   if(box[red]->head==1&&side>=0&&box[side]->bottom==1&&(box[side]->guard==0||box[side]->guard==2))
      {
       piontstack *ps=new piontstack(box[red]->sitx(),box[red]->sity(),box[side]->sitx(),box[side]->sity());
       pst.push_back(ps);
       killguard(side);
       if(hs->hp<=0)
           return;
       box[side]->inlines=1;
       later(side,1,0,1,1);
       if(hs->hp<=0)
           return;
   }
   side=red+border;
     while(box[red]->bottom==1&&side<=border*border-1&&box[side]->block==1)
         side+=border;
   if(box[red]->bottom==1&&side<=border*border-1&&box[side]->head==1&&(box[side]->guard==0||box[side]->guard==1))
   {
       piontstack *ps=new piontstack(box[red]->sitx(),box[red]->sity(),box[side]->sitx(),box[side]->sity());
    pst.push_back(ps);
    killguard(side);
    if(hs->hp<=0)
        return;
    box[side]->inlines=1;
    later(side,0,1,1,1);
    if(hs->hp<=0)
        return;
}
   side=red-1;
     while(box[red]->left==1&&side>floor(red/border)*border-1&&box[side]->block==1)
         side-=1;
   if(box[red]->left==1&&side>floor(red/border)*border-1&&box[side]->right==1&&(box[side]->guard==0||box[side]->guard==4))
   {
       piontstack *ps=new piontstack(box[red]->sitx(),box[red]->sity(),box[side]->sitx(),box[side]->sity());
    pst.push_back(ps);
    killguard(side);
    if(hs->hp<=0)
        return;
    box[side]->inlines=1;
    later(side,1,1,1,0);
    if(hs->hp<=0)
        return;
}
   side=red+1;
     while(box[red]->right==1&&side<floor(red/border)*border+border&&box[side]->block==1)
         side+=1;
   if(box[red]->right==1&&side<floor(red/border)*border+border&&box[side]->left==1&&(box[side]->guard==0||box[side]->guard==3))
   {
       piontstack *ps=new piontstack(box[red]->sitx(),box[red]->sity(),box[side]->sitx(),box[side]->sity());
    pst.push_back(ps);
    killguard(side);
    if(hs->hp<=0)
        return;
    box[side]->inlines=1;
    later(side,1,1,0,1);
    if(hs->hp<=0)
        return;
}
   update();
}
void MainWindow::later(int center,int h,int b,int l,int r)
{
    restpart=false;
        int side=center-border;
    while(box[center]->head==1&&h==1&&side>=0&&box[side]->block==1)
        side-=border;
     if(box[center]->head==1&&h==1&&side>=0&&box[side]->bottom==1&&(box[side]->guard==0||box[side]->guard==2))
      {
       piontstack *ps=new piontstack(box[center]->sitx(),box[center]->sity(),box[side]->sitx(),box[side]->sity());
       pst.push_back(ps);
       killguard(side);
       if(hs->hp<=0)
           return;
       if(box[side]->inlines==0)
         {  box[side]->inlines=1;
       later(side,1,0,1,1);
       if(hs->hp<=0)
           return;}
   }
     side=center+border;
         while(box[center]->bottom==1&&b==1&&side<=border*border-1&&box[side]->block==1)
             side+=border;
   if(box[center]->bottom==1&&b==1&&side<=border*border-1&&box[side]->head==1&&(box[side]->guard==0||box[side]->guard==1))
   {
       piontstack *ps=new piontstack(box[center]->sitx(),box[center]->sity(),box[side]->sitx(),box[side]->sity());
    pst.push_back(ps);
    killguard(side);
    if(hs->hp<=0)
        return;
    if(box[side]->inlines==0)
    { box[side]->inlines=1;
    later(side,0,1,1,1);
    if(hs->hp<=0)
        return;}
}
   side=center-1;
       while(box[center]->left==1&&l==1&&side>floor(center/border)*border-1&&box[side]->block==1)
           side-=1;
   if(box[center]->left==1&&l==1&&side>floor(center/border)*border-1&&box[side]->right==1&&(box[side]->guard==0||box[side]->guard==4))
   {
       piontstack *ps=new piontstack(box[center]->sitx(),box[center]->sity(),box[side]->sitx(),box[side]->sity());
    pst.push_back(ps);
    killguard(side);
    if(hs->hp<=0)
        return;
    if(box[side]->inlines==0)
    { box[side]->inlines=1;
    later(side,1,1,1,0);
    if(hs->hp<=0)
        return;}
}
   side=center+1;
       while(box[center]->right==1&&r==1&&side<floor(center/border)*border+border&&box[side]->block==1)
           side+=1;
   if(box[center]->right==1&&r==1&&side<floor(center/border)*border+border&&box[side]->left==1&&(box[side]->guard==0||box[side]->guard==3))
   {
       piontstack *ps=new piontstack(box[center]->sitx(),box[center]->sity(),box[side]->sitx(),box[side]->sity());
    pst.push_back(ps);
    killguard(side);
    if(hs->hp<=0)
        return;
    if(box[side]->inlines==0)
    { box[side]->inlines=1;
    later(side,1,1,0,1);
    if(hs->hp<=0)
        return;}
}
   update();
}
bool MainWindow::goldt(int i,int go)
{
    bool out=true;
    for(int j=0;j<go;j++)
        if(i==gold[j])
            out=false;
    return out;
}
bool MainWindow::greent(int i,int gr)
{
    bool out=true;
    for(int j=0;j<gr;j++)
        if(i==green[j])
            out=false;
    return out;
}

void MainWindow::killguard(int i)
{
    if(box[i]->guard!=0)
       {
        numg(0);
        if(hs->hp<=0)
        {
            clearbox();
            return;
        }
        box[i]->guard=0;
        box[i]->setStyleSheet("QPushButton:pressed{border-image: url(:/img/star-w);}");
    connect(box[i],&pathbox::clicked,this,&MainWindow::switchstar);
    }
}
void MainWindow::commoncha()
{
    if(chaptercoise!=-1)
    {
        if(chaptercoise==-2)
        {
            bgm[0]->stop();
                bgm[1]->play();
            chapexchange=0;
            timer=new QTimer(this);
            connect(timer,&QTimer::timeout,this,&MainWindow::addchange);
            timer->start(10000);
            QIcon icon;
            icon.addFile(tr(":/img/star-y"));
            box[red]->setStyleSheet("QPushButton:pressed{border-image: url(:/img/star-y);}");
            box[red]->setIcon(icon);
            icon.addFile(tr(":/img/star-r"));
            for(int i=0;i<4;i++)
            {
                box[gold[i]]->setIcon(icon);
                box[gold[i]]->setStyleSheet("QPushButton:pressed{border-image: url(:/img/star-r);}");
                roy[i]->setSource(QUrl("qrc:/redring.qml"));
            }
            ror->setSource(QUrl("qrc:/yellowring.qml"));
        }
        else
        {
    chapexchange=chaptercoise;
                   for(int i=0;i<4;i++)
                roy[i]->setSource(QUrl("qrc:/yellowring.qml"));
                   ror->setSource(QUrl("qrc:/redring.qml"));
        }
    }
    else
    {
        chapexchange=border;
                       for(int i=0;i<4;i++)
                roy[i]->setSource(QUrl("qrc:/yellowring.qml"));
                       ror->setSource(QUrl("qrc:/redring.qml"));
    }
    hs=new be(100,24);
    ui->HP->setMaximum(100);
    ui->HP->setMinimum(0);
    ui->HP->setValue(hs->hp);
    ui->SP->setMaximum(100);
    ui->SP->setMinimum(0);
    ui->SP->setValue(hs->sp);
    ing();
    connect(box[red],&pathbox::clicked,this,&MainWindow::drawline);
    for(int i=0;i<=border*border-1;i++)
        if(i!=red&&goldt(i,go)&&greent(i,gr))
           connect(box[i],&pathbox::clicked,this,&MainWindow::switchstar);
    openlight=0;
    exchangestar=false;
    mw=false;
    fi=false;
}
void MainWindow::clearbox()
{
    for(int i=0;i<border*border;i++)
        glayout->removeWidget(box[i]);
    while(!box.empty())
    {
        int i=static_cast<int>(box.size()-1);
                pathbox *ps1=box[i];
        box.pop_back();
        delete ps1;
    }
    while(!pst.empty())
    {
        int i=static_cast<int>(pst.size()-1);
                piontstack *ps=pst[i];
        pst.pop_back();
        delete ps;
    }
    outg();
    if(chaptercoise==-2)
    {

    bgm[1]->stop();
    bgm[0]->play();
    delete timer;
    }
    update();
if(chaptercoise==-3)
        {
        chapterbackto0();
}
else
    chaptercoise=0;
}
void MainWindow::ingame()
{
    QPixmap back = QPixmap(":/img/starfield").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), back);
    for(int i=0;i<gr;i++)
    {
        if(box[green[i]]->guard!=0)
        rog[i]->show();
        else
            rog[i]->hide();
        rog[i]->setClearColor(QColor(Qt::transparent));
        rog[i]->setAttribute(Qt::WA_AlwaysStackOnTop);
        rog[i]->setGeometry(box[green[i]]->sitx()-box[green[i]]->height()/2,box[green[i]]->sity()-box[green[i]]->height()/2,box[green[i]]->height(),box[green[i]]->height());
    }
    if(onlyone1==false)
    {
        onlyone1=true;
        for(int i=0;i<go;i++)
    {
        roy[i]->show();
        roy[i]->setClearColor(QColor(Qt::transparent));
        roy[i]->setAttribute(Qt::WA_AlwaysStackOnTop);
        roy[i]->setGeometry(box[gold[i]]->sitx()-box[gold[i]]->height()/2,box[gold[i]]->sity()-box[gold[i]]->height()/2,box[gold[i]]->height(),box[gold[i]]->height());
    }
        ror->show();
        ror->setClearColor(QColor(Qt::transparent));
        ror->setAttribute(Qt::WA_AlwaysStackOnTop);
        ror->setGeometry(box[red]->sitx()-box[red]->height()/2,box[red]->sity()-box[red]->height()/2,box[red]->height(),box[red]->height());
       if(chaptercoise!=-2||chaptercoise==-3)
       { ui->quickWidget->show();
        ui->quickWidget->setClearColor(QColor(Qt::transparent));
        ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
        ui->quickWidget->setGeometry(box[red]->sitx()-50,box[red]->sity()-50,100,100);}
    }
    if(openlight==true)
    {
    for(int i=0;i<pst.size();i++)
    {
        QPen pen(Qt::red);
        if(chaptercoise==-2||chaptercoise==-3)
pen.setColor(Qt::green);
        pen.setWidth(2);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(pen);
        painter.drawLine(QPoint(pst[i]->x1(),pst[i]->y1()),QPoint(pst[i]->x2(),pst[i]->y2()));
    }
    for(int i=0;i<border*border;i++)
    {
        if(box[i]->head==1&&box[i]->block==0)
        {
            QPen pen(Qt::white);
             if(box[i]->guard!=0&&box[i]->guard!=1)
                 pen.setColor(Qt::green);
            pen.setWidth(2);
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setPen(pen);
            painter.drawLine(box[i]->sitp(),QPoint(box[i]->sitx(),box[i]->sity()-box[i]->height()/2));
        }
        if(box[i]->bottom==1&&box[i]->block==0)
        {
            QPen pen(Qt::white);
            if(box[i]->guard!=0&&box[i]->guard!=2)
                pen.setColor(Qt::green);
            pen.setWidth(2);
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setPen(pen);
            painter.drawLine(box[i]->sitp(),QPoint(box[i]->sitx(),box[i]->sity()+box[i]->height()/2));
        }
        if(box[i]->left==1&&box[i]->block==0)
        {
            QPen pen(Qt::white);
            if(box[i]->guard!=0&&box[i]->guard!=3)
                pen.setColor(Qt::green);
            pen.setWidth(2);
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setPen(pen);
            painter.drawLine(box[i]->sitp(),QPoint(box[i]->sitx()-box[i]->height()/2,box[i]->sity()));
        }
        if(box[i]->right==1&&box[i]->block==0)
        {
            QPen pen(Qt::white);
            if(box[i]->guard!=0&&box[i]->guard!=4)
                pen.setColor(Qt::green);
            pen.setWidth(2);
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setPen(pen);
            painter.drawLine(box[i]->sitp(),QPoint(box[i]->sitx()+box[i]->height()/2,box[i]->sity()));
        }
    }
    if(restpart==false)
    {
    for(int i=0;i<border*border;i++)
    {
           restpart=!restpart;
            if(box[i]->inlines==0&&i!=red&&goldt(i,go)&&box[i]->block==0&&box[i]->guard==0&&!(box[i]->head==0&&box[i]->bottom==0&&box[i]->left==0&&box[i]->right==0))
          {
            QIcon icon;
            icon.addFile(tr(":/img/star-w"));
            box[i]->setIcon(icon);
        }
        else
            if(i!=red&&goldt(i,go)&&box[i]->block==0&&box[i]->guard==0&&!(box[i]->head==0&&box[i]->bottom==0&&box[i]->left==0&&box[i]->right==0))
        {
                QIcon icon;
                icon.addFile(tr(":/img/star-sr"));
                if(chaptercoise==-2)
                    icon.addFile(tr(":/img/star-g"));
                box[i]->setIcon(icon);
        }
        }

    }
    bool tr=true;
    for(int j=0;j<go;j++)
   {
         if(box[gold[j]]->inlines!=1)
             tr=false;
    }
        if(tr)
    {
            if(chaptercoise==-2)
                timer->stop();
            if(gw==false)
            {
                gw=true;
                fi=false;
                fini();
                return;
            }
            if(hs->hp<=0)
            {
                clearbox();
                return;
            }
                    if(fi)
            {
           if(onlyone2==false)
           {
               onlyone2=true;
for(int i=0;i<border*border;i++)
{
    QIcon icon;
    if(box[i]->inlines==0)
    {
        icon.addFile(":/img/star-n");
        box[i]->setIcon(icon);
    }
    else
    {
         icon.addFile(":/img/star-r");
         if(chaptercoise==-2)
             icon.addFile(":/img/star-g");
         if(chaptercoise==-3)
             icon.addFile(":/img/star-y");
         box[i]->setIcon(icon);
    }
}
           }
        QPixmap back = QPixmap(":/img/starfield-r").scaled(this->size());
        painter.drawPixmap(this->rect(), back);
        QPen pen(Qt::red);
        if(chaptercoise==-2||chaptercoise==-3)
{
            back = QPixmap(":/img/starfield").scaled(this->size());
            painter.drawPixmap(this->rect(), back);
            pen.setColor(Qt::green);
            ui->quickWidget->hide();
            if(onlyone4==false)
            {
                onlyone4=true;
             QIcon icon;
             if(chaptercoise==-3)
            {
                 icon.addFile(":/img/star-g");
        box[7]->setIcon(icon);
                         ror->hide();}
             else
             {
                 icon.addFile(":/img/star-y");
                         box[112]->setIcon(icon);
             }
            }
        }
        pen.setWidth(2);
        QPainterPath path;
        for(int i=0;i<gr;i++)
            rog[i]->hide();
           if(chaptercoise==0)
           {
               ui->quickWidget->hide();
               ror->hide();
               for(int i=0;i<go;i++)
                   roy[i]->hide();
               if(onlyone3==false)
               {
                   onlyone3=true;
               for(int i=0;i<border*border;i++)
               {
                   QIcon icon;
                   icon.addFile(":/img/star-n");
                   box[i]->setIcon(icon);
               }
               }
               for(int i=0;i<sln;i++)
           {
               sl[i]->calc();
           path.moveTo(sl[i]->b1.sitx(),sl[i]->b1.sity());
           path.quadTo(sl[i]->xc,sl[i]->yc,sl[i]->b2.sitx(),sl[i]->b2.sity());
           painter.setPen(pen);
           painter.drawPath(path);
               }
               ui->tar->show();
               ui->tar->setGeometry(box[11]->sitx(),box[11]->sity()-box[16]->width()*2,box[16]->sity()-box[11]->sity()+box[16]->width()*3,box[22]->sitx()-box[16]->sitx());
               ui->ield->show();
               ui->ield->setGeometry(box[14]->sitx(),box[11]->sity()-box[16]->width()*2,box[16]->sity()-box[11]->sity()+box[16]->width()*3,box[22]->sitx()-box[16]->sitx());
           }
           painter.setPen(pen);
        for(int i=0;i<pst.size();i++)
        {
            painter.drawLine(QPoint(pst[i]->x1(),pst[i]->y1()),QPoint(pst[i]->x2(),pst[i]->y2()));
        }
        if(chaptercoise!=-2&&chaptercoise!=-3)
        {
            if(chaptercoise==0)
            ui->return_3->show();
            ui->victory->setClearColor(QColor(Qt::transparent));
            ui->victory->setAttribute(Qt::WA_AlwaysStackOnTop);
                    ui->victory->setGeometry(0,0,width(),height());
        ui->victory->show();
        }
            }
        }
    }

}
void MainWindow::outg()
{
    uimanager->setCurrentWidget(ui->centralWidget);
    ui->tar->hide();
    ui->ield->hide();
    ui->return_3->hide();
    ui->quickWidget->hide();
    ui->victory->hide();
    ror->hide();
    for(int i=0;i<4;i++)
        rog[i]->hide();
    for(int i=0;i<4;i++)
        roy[i]->hide();
    row[0]->hide();
    row[1]->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->HP->hide();
    ui->SP->hide();
    ui->exchange->hide();
    delete ui->centralWidget->layout();
    tlayout=new QGridLayout();
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            tlayout->addWidget(mitem[i*3+j],i,j,Qt::AlignCenter);
            mitem[i*3+j]->show();
        }
    ui->centralWidget->setLayout(tlayout);
    gw=false;
    mw=true;
    for(int i=0;i<6;i++)
    {
                    if(winlist[i]==false)
                    {
                        QIcon icon;
                        icon.addFile(":/img/"+QString::number((i+1), 10));
                        mitem[i+3]->setIcon(icon);
                    }
                        else
        if(winlist[i]==true&&wintrue!=true)
           {
            QIcon icon;
            QString temp=":/img/"+QString::number((i+1), 10);
            icon.addFile(temp+"a");
            mitem[i+3]->setIcon(icon);
        }
        else
        {
            QIcon icon;
            QString temp=":/img/"+QString::number((i+1), 10);
            icon.addFile(temp+"c");
            mitem[i+3]->setIcon(icon);
        }
    }
}
void MainWindow::ing()
{
    for(int i=0;i<9;i++)
        mitem[i]->hide();
     int h=width()/height()+3;
         glayout=new QGridLayout();
         for(int j=0;j<border;j++)
             for(int k=0;k<border;k++)
    glayout->addWidget(box[j*border+k],j,k,1,h,Qt::AlignCenter);
    glayout->setMargin(this->width()/10);
    delete ui->centralWidget->layout();
    ui->centralWidget->setLayout(glayout);
    ui->label->show();
    ui->label_2->show();
    ui->HP->show();
    ui->SP->show();
    ui->exchange->show();
    ui->exchange->setText(QString::number(chapexchange, 10));
    ui->exchange->setStyleSheet("QPushButton{border-image: url(:/img/exchange) 0 0 0 0;color:red;}"
                                "QPushButton:pressed{border-image:url(:/img/exchange2) 0 0 0 0;}");
    ui->return_3->setStyleSheet("QPushButton{border-image: url(:/img/return) 0 0 0 0;color:red;}"
                                "QPushButton:pressed{border-image:url(:/img/return2) 0 0 0 0;}");

    static bool first0=true;
    if(chaptercoise!=0||first0==false)
    ui->return_3->show();
    else
        first0=false;
    ui->HP->setStyleSheet("QProgressBar{border: 1px solid grey;text-align: center;color:#A39480;border-radius: 10px;backgroung-color: #FAF0E6}"
                          "QProgressBar::chunk{border-radius: 10px;background-color: #bc1717;}");
    ui->SP->setStyleSheet("QProgressBar{border: 1px solid grey;color:#A39480;text-align: center;background-color:#BDFCC9;border-radius: 10px;}"
                          "QProgressBar::chunk{background-color: green;border-radius: 10px;}");
    int id = QFontDatabase::addApplicationFont( QString(":/font/FORTE.TTF"));
    QString msyh = QFontDatabase::applicationFontFamilies ( id ).at(0);
    QFont font(msyh,8,75);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->HP->setFont(font);
    ui->SP->setFont(font);
    ui->return_3->setFont(font);
    ui->exchange->setFont(font);
    onlyone1=false;
    onlyone2=false;
    onlyone3=false;
    onlyone4=false;
}
void MainWindow::numg(int gog)
{
    if(chaptercoise!=0)
    ng=new numbergame(gog,this);
    else
        ng=new numbergame(gog,this,true);
    timec=new QTime;
    timec->start();
    ng->exec();
    if(ng->nums==0)
        hs->changesp(15000,0);
    else
    hs->changesp(timec->elapsed(),ng->nums);
    ui->HP->setValue(hs->hp);
    ui->SP->setValue(hs->sp);
    delete timec;
    delete ng;
}
void MainWindow::fini()
{
    if(chaptercoise!=-3&&chaptercoise!=-2)
                    numg(1);
    else
        numg(2);
                    if(hs->hp>0||chaptercoise==0)
                    {
                        fi=true;
                        if(chaptercoise!=0&&chaptercoise!=-3&&chaptercoise!=-1)
                        {if(chaptercoise!=-2)
                            winlist[chaptercoise-1]=true;
                        else
                            wintrue=true,winlist[5]=true;}
                    }
                    update();

}
void MainWindow::randborder(int red, int i)
{
    int add=0;
    if(red%border==0)
    {
        srand(time(0)+add++);
pathbox *b=new pathbox(4,i,this);
box.push_back(b);
    }
    else
            if((red-border+1)%border==0)
            {
                srand(time(0)+add++);
        pathbox *b=new pathbox(3,i,this);
        box.push_back(b);
            }
            else
                    if(red>-1&&red<border)
                    {
                        srand(time(0)+add++);
                pathbox *b=new pathbox(2,i,this);
                box.push_back(b);
                    }
    else
                        if(red>(border-1)*border-1&&red<(border-1)*border+border)
                        {
                            srand(time(0)+add++);
                    pathbox *b=new pathbox(1,i,this);
                    box.push_back(b);
                        }
                        else{
    srand(time(0)+add++);
pathbox *b=new pathbox(rand()%(4-1+1)+1,i,this);
box.push_back(b);
                        }
}
void MainWindow::addchange()
{
    hidetimecout++;
    if(hidetimecout>220)
        return;
    srand(time(0));
    chapexchange++;
    ui->exchange->setText(QString::number(chapexchange, 10));
    int turn=rand()%(border*border-1+1);
    while(turn==red||!goldt(turn,go)||(box[turn]->head==0&&box[turn]->bottom==0&&box[turn]->left==0&&box[turn]->right==0))
        turn=rand()%(border*border-1+1);
        box[turn]->head=0,box[turn]->bottom=0,box[turn]->left=0,box[turn]->right=0;
        QIcon icon;
        icon.addFile(tr(":/img/star-r"));
        box[turn]->setStyleSheet("QPushButton:pressed{border-image: url(:/img/star-r);}");
        box[turn]->setIcon(icon);
        ui->quickWidget->show();
                ui->quickWidget->setClearColor(QColor(Qt::transparent));
                ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
                ui->quickWidget->setGeometry(box[turn]->sitx()-50,box[turn]->sity()-50,100,100);
                warn->play();
                openlight=!openlight;
                drawline();

}
void MainWindow::chapter6spec()
{
    chaptercoise=-3;
    box[1]->inlines=1;
    box[7]->inlines=1;
    openlight=true;
    piontstack *ps=new piontstack(box[1]->sitx(),box[1]->sity(),box[7]->sitx(),box[7]->sity());
 pst.push_back(ps);
update();
}
void MainWindow::endword()
{
    word->stop();
    ui->begin->hide();
    ui->backsys->hide();
            delete ui->backsys->layout();
    uimanager->setCurrentWidget(ui->centralWidget);
    if(chaptercoise!=6)
    chapter0();
    else
chapter6();
}
