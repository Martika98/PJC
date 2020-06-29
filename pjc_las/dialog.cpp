#include "dialog.h"
#include "ui_dialog.h"
using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    hide();
    int krolik = ui->lineEdit->text().toInt();//konwersja na int
    int wilk = ui->lineEdit_2->text().toInt();
    int mysz = ui->lineEdit_3->text().toInt();
    int lis = ui->lineEdit_4->text().toInt();
    int niedzwiedz = ui->lineEdit_5->text().toInt();
    int roslinka = ui->lineEdit_6->text().toInt();
    int waz = ui->lineEdit_7->text().toInt();
    int zolw = ui->lineEdit_8->text().toInt();
    w = new MainWindow(krolik, wilk, mysz, lis, niedzwiedz, roslinka, waz, zolw, this);
    w->show();
}
