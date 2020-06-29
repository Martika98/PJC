#ifndef GOBJECT_H
#define GOBJECT_H
#include "object.h"
#include <QPainter>
#include "species.h"
#include "plant.h"




class Gobject
{

public:
    QList <QPixmap *> picture_list;
    Gobject();
    ~Gobject();
};

#endif // GOBJECT_H
