#include "mechanics.h"


Mechanics::Mechanics()
{
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(snap()));
    timer->start(10000/60);
    zajac = new hare();
    for(int i = 0; i<30; i++)
    {
        Plant new_plant;
        plant_list.append(new_plant);
    }
}

void Mechanics::snap()
{
    zajac->live();

    if(zajac->get_full_tummy() < 50 && plant_list.length()!=0){
        temp = 0;
        temp_1 = 0;
        temp_3 = 3000;
        p1 = 0;
        p2 = 0;
        for(int i = 0; i < plant_list.length(); i++)
        {
            p1 = zajac->get_poz_x() - plant_list[i].get_poz_x();
            p2 = zajac->get_poz_y() - plant_list[i].get_poz_y() ;
            temp = abs(p1) + abs(p2);
            if (temp <temp_3)
            {
                temp_1 = i;
                temp_3 = temp;
                p11 = p1;
                p22 = p2;

    }}
    dist = sqrt(p11*p11 + p22*p22);
    p01 =int(zajac->get_poz_x() - zajac->get_velocity()*p11/dist);
    p02 = int(zajac->get_poz_y() - zajac->get_velocity()*p22/dist);
    zajac->set_poz_x(p01);
    zajac->set_poz_y(p02);
    if(dist<60){
        zajac->set_full_tummy(plant_list[temp_1].get_nutrition());
        plant_list.removeAt(temp_1);
    }
}
}
int Mechanics::hare_get_poz_x()
{
    return zajac->get_poz_x();
}
int Mechanics::hare_get_poz_y()
{
    return zajac->get_poz_y();
}
QPixmap Mechanics::hare_get_icon()
{
    return zajac->get_icon();
}
