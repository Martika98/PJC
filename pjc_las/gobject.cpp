#include "gobject.h"



Gobject::Gobject()
{
    QPixmap *picture1 = new QPixmap(":/ikonki/plansza.png");
    picture_list.append(picture1);

    QPixmap *picture2 = new QPixmap(":/ikonki/kurlik.png");
    picture_list.append(picture2);

    QPixmap *picture3 = new QPixmap(":/ikonki/wilk.png");
    picture_list.append(picture3);

    QPixmap *picture4 = new QPixmap(":/ikonki/plant.png");
    picture_list.append(picture4);

    QPixmap *picture5 = new QPixmap(":/ikonki/mysz.JPG");
    picture_list.append(picture5);

    QPixmap *picture6 = new QPixmap(":/ikonki/ziarenka.png");
    picture_list.append(picture6);

    QPixmap *picture7 = new QPixmap(":/ikonki/lis.png");
    picture_list.append(picture7);

    QPixmap *picture8 = new QPixmap(":/ikonki/misio.png");
    picture_list.append(picture8);

    QPixmap *picture9 = new QPixmap(":/ikonki/woz.png");
    picture_list.append(picture9);

    QPixmap *picture10 = new QPixmap(":/ikonki/żolw_hide.png");
    picture_list.append(picture10);

    QPixmap *picture11 = new QPixmap(":/ikonki/żolw_safe.png");
    picture_list.append(picture11);

    QPixmap *picture12 = new QPixmap(":/ikonki/bloto.png");
    picture_list.append(picture12);

    QPixmap *picture13 = new QPixmap(":/ikonki/glaz.png");
    picture_list.append(picture13);


}

Gobject::~Gobject()
{
    qDeleteAll(picture_list);
    picture_list.clear();
}
