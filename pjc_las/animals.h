#ifndef ANIMALS_H
#define ANIMALS_H
#include <QPainter>
#include "plant.h"
#include "object.h"



class animals : public Object
{
protected:
    double max_velocity, velocity, life, full_tummy;
    int stamina, fatigue, wounds;
    bool safety, visibility;

public:
    animals();
    virtual ~animals();
    void set_poz_x(int poz);
    void set_poz_y(int poz);
    double get_velocity();
    virtual void update(QList<Object *> &food);
    double get_full_tummy();
    virtual void eat(QList <Object *> &food);
    void set_full_tummy(double nt);
    //eat(QList <Object> &Object_list, animals *n, int p1, int p2, int p01, int p02, double temp, double dist, int j);
    void reproduction();
    bool get_safety();
    void run(QList<Object *> &Predator_list);
    double get_life();
    bool get_visibility();
    void set_visibility(bool v);
    void live();


};

#endif // ANIMALS_H
