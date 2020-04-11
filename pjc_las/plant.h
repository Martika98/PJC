#ifndef PLANT_H
#define PLANT_H
#include <QPainter>
#include <QList>

class Plant
{
    QPixmap icon;
    int nutrition = 2;
    int poz_x;
    int poz_y;


public:
    Plant();
    ~Plant();
    int get_poz_x();
    int get_poz_y();
    QPixmap get_icon();
    int get_nutrition();
};

#endif // PLANT_H
