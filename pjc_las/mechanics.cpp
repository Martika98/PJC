#include "mechanics.h"

Mechanics::Mechanics()
{
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(snap()));
    timer->start(1000/60);
    zajac = new hare();

}

void Mechanics::snap()
{

}
int Mechanics::hare_get_poz_x()
{
    return zajac->get_poz_x();
}
int Mechanics::hare_get_poz_y()
{
    return zajac->get_poz_y();
}
QPixmap Mechanics::hare_get_icon()
{
    return zajac->get_icon();
}
