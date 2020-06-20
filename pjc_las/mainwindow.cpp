#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int k, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start(1000/60);
    resize(1280, 720);
    mechanic = new Mechanics(k);

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
    int liczbak = 0;
    for(int i = 0; i < mechanic->Object_list.length(); i++){

        hare *h = dynamic_cast<hare *>(mechanic->Object_list[i]);
        if(h){
            liczbak = liczbak + 1;
            std::cout<<liczbak<<"\n";
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), QPixmap(":/ikonki/kurik.png"));
        }
        wolf *w = dynamic_cast<wolf *>(mechanic->Object_list[i]);
        if(w)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), QPixmap(":/ikonki/wilk.jpeg"));
        Plant *p = dynamic_cast<Plant *>(mechanic->Object_list[i]);
        if(p)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), QPixmap(":/ikonki/plant.png"));
        Mouse *m = dynamic_cast<Mouse *>(mechanic->Object_list[i]);
        if(m)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), QPixmap(":/ikonki/mysz.JPG"));
        Seeds *s = dynamic_cast<Seeds *>(mechanic->Object_list[i]);
        if(s)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), QPixmap(":/ikonki/ziarenka.png"));
        // pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(),QPixmap(":/ikonki/kurik.png"));

//         for(int i = 0; i < mechanic->Object_list.length(); i++){
//             mechanic->Gobject_list[i]->draw(pen();
    //std::cout<< mechanic->Object_list.length()<<"\n";
}}
