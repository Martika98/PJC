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
    bool safety;
    bool visibility = true;
    int fertility;


public:
    Object *partner = nullptr;
    animals();
    virtual ~animals();
    void set_poz_x(int poz);
    void set_poz_y(int poz);
    double get_velocity();
    double get_maxvelocity();
    void set_velocity(double v);
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
    int get_fertility();
    void set_fertility(int a);
    void live();



};

#endif // ANIMALS_H
