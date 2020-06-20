#include "gobject.h"


Gobject::Gobject(Object *gobiekt)
{
    obiekt = gobiekt;
}
void Gobject:: draw(QPainter pen){
    hare *h = dynamic_cast<hare *>(obiekt);
    if(h)
        pen.drawPixmap(obiekt->get_poz_x(), obiekt->get_poz_y(), QPixmap(":/ikonki/kurik.png"));
    wolf *w = dynamic_cast<wolf *>(obiekt);
    if(w)
        pen.drawPixmap(obiekt->get_poz_x(), obiekt->get_poz_y(), QPixmap(":/ikonki/wilk.jpeg"));
    Plant *p = dynamic_cast<Plant *>(obiekt);
    if(p)
        pen.drawPixmap(obiekt->get_poz_x(), obiekt->get_poz_y(), QPixmap(":/ikonki/plant.png"));
}
