#ifndef GOBJECT_H
#define GOBJECT_H
#include "object.h"
#include <QPainter>
#include "plant.h"


class mechanics;

class Gobject
{
    QPixmap * picture;
    QPixmap * npicture;
public:
    Object * ob;
    QPixmap * current_picture;
    Gobject(Object *obi);
    ~Gobject();
    void draw();
};

#endif // GOBJECT_H
