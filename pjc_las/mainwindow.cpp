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
    pen.drawPixmap(0, 0, *obrazki->picture_list[0]);
    for(int i = 0; i < mechanic->Object_list.length() ; i++){

        Mud *bl = dynamic_cast<Mud *>(mechanic->Object_list[i]);
        if(bl)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), *obrazki->picture_list[11]);

        hare *h = dynamic_cast<hare *>(mechanic->Object_list[i]);
        if(h)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), *obrazki->picture_list[1]);

        wolf *w = dynamic_cast<wolf *>(mechanic->Object_list[i]);
        if(w)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), *obrazki->picture_list[2]);

        Plant *p = dynamic_cast<Plant *>(mechanic->Object_list[i]);
        if(p)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), *obrazki->picture_list[3]);

        Mouse *m = dynamic_cast<Mouse *>(mechanic->Object_list[i]);
        if(m)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), *obrazki->picture_list[4]);

        Seeds *s = dynamic_cast<Seeds *>(mechanic->Object_list[i]);
        if(s)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), *obrazki->picture_list[5]);

        Fox *l = dynamic_cast<Fox *>(mechanic->Object_list[i]);
        if(l)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), *obrazki->picture_list[6]);

        Bear *b = dynamic_cast<Bear *>(mechanic->Object_list[i]);
        if(b)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), *obrazki->picture_list[7]);

        Snake *sn = dynamic_cast<Snake *>(mechanic->Object_list[i]);
        if(sn)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), *obrazki->picture_list[8]);

        Tortoise *t = dynamic_cast<Tortoise *>(mechanic->Object_list[i]);
        if(t){
            if(t->get_safety())
                pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), *obrazki->picture_list[10]);
            else
                pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), *obrazki->picture_list[9]);
        }
        Stones *st = dynamic_cast<Stones *>(mechanic->Object_list[i]);
        if(st)
            pen.drawPixmap(mechanic->Object_list[i]->get_poz_x(), mechanic->Object_list[i]->get_poz_y(), *obrazki->picture_list[12]);


//         for(int i = 0; i < mechanic->Object_list.length(); i++){
//             mechanic->Gobject_list[i]->draw(pen();
    //std::cout<< mechanic->Object_list.length()<<"\n";
}}
