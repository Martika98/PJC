#ifndef PLANT_H
#define PLANT_H
#include <QPainter>
#include "object.h"

class animals;

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

class Mud : public Object{
    int center_x;
    int center_y;
public:
    Mud();
    void change_velocity(QList <Object *> &Object_list);
    void update(QList <Object *> &Object_list);

};
class Trees : public Object{
public:
    Trees();
    void change_visibility();
    void change_fatigue();

};
class Stones : public Object{
public:
    Stones();
    void change_visibility();
};

#endif // PLANT_H
