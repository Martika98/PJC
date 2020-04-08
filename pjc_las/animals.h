#ifndef ANIMALS_H
#define ANIMALS_H
#include <QPainter>


class animals
{
protected:
    QPixmap icon;
    int poz_x;
    int poz_y;
    int max_velocity, velocity, stamina, fatigue, life, full_tummy, wounds;
public:
    animals();
    QPixmap get_icon();
    int get_poz_x();
    int get_poz_y();
    void set_poz_x(int poz);
    void set_poz_y(int poz);

};
class hare : public animals
{
public:
    hare();
    ~hare();
};

#endif // ANIMALS_H
