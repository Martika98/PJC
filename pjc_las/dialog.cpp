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
    w = new MainWindow(krolik, this);
    w->show();
}
