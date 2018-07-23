#include "exit.h"
#include "ui_exit.h"
#include<QPushButton>
#include<QPainter>
#include<QFontDatabase>
Exit::Exit(QWidget *parent) :
    QDialog(parent,Qt::FramelessWindowHint),
    ui(new Ui::Exit)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::No)->setFocus();
    int id = QFontDatabase::addApplicationFont( QString(":/font/FORTE.TTF"));
    QString msyh = QFontDatabase::applicationFontFamilies ( id ).at(0);
    QFont font(msyh,20,75);
     QFont font2(msyh,8,75);
     ui->label->setFont(font);
     ui->buttonBox->setFont(font2);
}

Exit::~Exit()
{
    delete ui;
}

void Exit::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button->text()==tr("Yes"))
    accept();
    else
    reject();
}
void Exit::paintEvent(QPaintEvent *)
{
    QPixmap back = QPixmap(":/img/exit").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), back);
}
