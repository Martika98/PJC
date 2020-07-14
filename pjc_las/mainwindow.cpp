#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(int k, int w, int m, int l, int n, int roslinka, int waz, int zolw, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start(1000/60);
    resize(1280, 720);
    mechanic = new Mechanics(k, w, m, l, n, waz, zolw, roslinka);

}

MainWindow::~MainWindow()
{
    delete timer;
    delete mechanic;
    delete ui;

}
void MainWindow::paintEvent(QPaintEvent *){
    QPainter pen(this);
    pen.drawPixmap(0, 0, QPixmap(":/ikonki/plansza.png"));
    for(int i = 0; i < mechanic->Gobject_list.length() ; i++){
        mechanic->Gobject_list[i]->draw();
        pen.drawPixmap(mechanic->Gobject_list[i]->ob->get_poz_x(), mechanic->Gobject_list[i]->ob->get_poz_y(), * mechanic->Gobject_list[i]->current_picture);
}}
