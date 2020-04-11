#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start(1000/60);
    resize(1280, 720);
    mechanic = new Mechanics;

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
    pen.drawPixmap(mechanic->hare_get_poz_x(), mechanic->hare_get_poz_y(), mechanic->hare_get_icon());
    for(int i = 0; i < mechanic->plant_list.length(); i++)
         pen.drawPixmap(mechanic->plant_list[i].get_poz_x(), mechanic->plant_list[i].get_poz_y(), mechanic->plant_list[i].get_icon());

}
