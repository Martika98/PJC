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
    int update(QList <Object *> &food);
};

class Seeds : public Object{

    int nutrition = 20;
public:
    Seeds();
    ~Seeds();
    int update(QList <Object *> &Object_list);
};

class Mud : public Object{
    int center_x;
    int center_y;
public:
    Mud();
    void change_velocity(QList <Object *> &Object_list);
    int update(QList <Object *> &Object_list);

};
class Trees : public Object{
public:
    Trees();
    void change_visibility();
    void change_fatigue();
    int update(QList <Object *> &Object_list);

};
class Stones : public Object{
    int center_x;
    int center_y;
public:
    Stones();
    void change_visibility(QList <Object *> &Object_list);
    int update(QList <Object *> &Object_list);
};

#endif // PLANT_H
