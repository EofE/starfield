#ifndef EXIT_H
#define EXIT_H

#include <QDialog>
#include<QAbstractButton>
namespace Ui {
class Exit;
}

class Exit : public QDialog
{
    Q_OBJECT

public:
    explicit Exit(QWidget *parent = 0);
    ~Exit();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    void paintEvent(QPaintEvent *);
    Ui::Exit *ui;
};

#endif // EXIT_H
