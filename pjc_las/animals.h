#ifndef ANIMALS_H
#define ANIMALS_H
#include <QPainter>
#include "plant.h"
#include "object.h"



class animals : public Object
{
private:
    double max_velocity;
    double life;
    int stamina;

protected:
    double velocity, full_tummy, fatigue;
    int wounds;
    bool safety;
    bool visibility = true;
    int fertility;

public:
    animals *partner = nullptr;
    animals(double a, double b, int c);
    virtual ~animals();
    void set_poz_x(int poz);
    void set_poz_y(int poz);
    double get_velocity();
    double get_maxvelocity();
    void set_velocity(double v);
    virtual int update(QList<Object *> &food) = 0;
    double get_full_tummy();
    virtual void eat(QList <Object *> &food) = 0;
    void set_full_tummy(double nt);
    //eat(QList <Object> &Object_list, animals *n, int p1, int p2, int p01, int p02, double temp, double dist, int j);
    virtual int reproduction(QList<Object *> &Object_list) = 0;
    bool get_safety();
    void run(QList<Object *> &Predator_list);
    double get_life();
    bool get_visibility();
    void set_visibility(bool v);
    int get_fertility();
    void set_fertility(int a);
    void set_wounds(int a);
    void live();



};

#endif // ANIMALS_H
