#ifndef ANIMALS_H
#define ANIMALS_H
#include <QPainter>


class animals
{
protected:
    QPixmap icon;
    int poz_x;
    int poz_y;
    double max_velocity, velocity;
    int stamina, fatigue, life, wounds;
    double full_tummy;
public:
    animals();
    QPixmap get_icon();
    int get_poz_x();
    int get_poz_y();
    void set_poz_x(int poz);
    void set_poz_y(int poz);
    double get_velocity();
    void live();
    void set_full_tummy(int nt);
    double get_full_tummy();

};
class hare : public animals
{
public:
    hare();
    ~hare();
};

#endif // ANIMALS_H
