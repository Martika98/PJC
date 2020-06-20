#ifndef GOBJECT_H
#define GOBJECT_H
#include "object.h"
#include <QPainter>
#include "species.h"
#include "plant.h"



class Gobject
{
    Object *obiekt;
public:
    Gobject(Object *gobiekt);
    void draw(QPainter pen);
};

#endif // GOBJECT_H
