#ifndef PLANT_H
#define PLANT_H
#include <QPainter>
#include "object.h"


class Plant : public Object
{
    int nutrition = 20;

public:
    Plant();
    ~Plant();
    int get_nutrition();
    void update(QList <Object *> food);
};

class Seeds : public Object{
public:
    Seeds();
    ~Seeds();
    void update(QList <Object *> Object_list);
};

#endif // PLANT_H
