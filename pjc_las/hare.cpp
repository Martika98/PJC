#include "hare.h"
#include "wolf.h"
#include "fox.h"


hare::hare() : animals(70, 7, 10){
    velocity = get_maxvelocity();
    full_tummy = 60;
    safety = false;

}
void hare::eat(QList <Object *> &food){
    if (full_tummy < 50 && food.length() != 0 && safety && fatigue < 80){
        bool plante = false; //czy istnieje jakaś roślinka
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        int j = -1;
        for (int i = 0; i < food.length(); i++) {
            Plant *p = dynamic_cast<Plant *>(food[i]);
            if(p){
                plante = true;
                dist = abs(poz_x - food[i]->get_poz_x()) + abs(poz_y - food[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
                if(dist < temp && dist > 0)
                {
                    distx = food[i]->get_poz_x() - poz_x;
                    disty = food[i]->get_poz_y() - poz_y;
                    temp = dist;
                    j = i;
                }}}
        if(plante){
            dist = sqrt(distx*distx + disty*disty);
            p1 = int(poz_x + velocity * distx/ dist);
            p2 = int(poz_y + velocity * disty/ dist);
            poz_x = p1;
            poz_y = p2;
            if (dist < 40 && j > -1){
                set_full_tummy(30);
                food[j]->set_nexist();
            }
        }
    }
}
void hare::run(QList<Object *> &Predator_list){
        bool predatore = false; //czy istnieje jakiś wilk
        safety = false;
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        for (int i = 0; i < Predator_list.length(); i++) {
            wolf *p = dynamic_cast<wolf *>(Predator_list[i]);
            Fox *f = dynamic_cast<Fox *>(Predator_list[i]);
            if(p || f){
                predatore = true;
                dist = abs(poz_x - Predator_list[i]->get_poz_x()) + abs(poz_y - Predator_list[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
                if(dist < temp && dist > 0)
                {
                    distx = poz_x - Predator_list[i]->get_poz_x();
                    disty = poz_y - Predator_list[i]->get_poz_y();
                    temp = dist;
                }}}
        if(predatore && temp < 90){
            dist = sqrt(distx*distx + disty*disty);
            p1 = int(poz_x + velocity * distx/ dist);
            p2 = int(poz_y + velocity * disty/ dist);
            poz_x = p1;
            poz_y = p2;
            safety = false;
            }
        else {
            safety = true;
        }
}
int hare::reproduction(QList<Object *> &Object_list){
    int l = 0;
    double distx = 0, disty = 0, dist = 0;
    int p1, p2;
    if(fertility > 20 && full_tummy > 50 && partner == nullptr && safety){
        for (int i = 0; i < Object_list.length(); i++){
            hare *p = dynamic_cast<hare *>(Object_list[i]);
            if(p){
                if((p->partner == nullptr || p->partner == this) && p != this && p->get_fertility() > 20){
                    p->partner = this;
                    partner = p;
                    break;
                }
            }
        }}
    if(partner != nullptr && full_tummy > 50 && fertility > 20 && safety){
        distx = partner->get_poz_x() - poz_x;
        disty = partner->get_poz_y() - poz_y;
        dist = sqrt(distx*distx + disty*disty);
        if(dist > 10){
            p1 = int (poz_x + velocity * distx/dist);
            p2 = int (poz_y + velocity * disty/dist);
            poz_x = p1;
            poz_y = p2;
        }
        else if(dist <= 10){
            l = QRandomGenerator::system()->bounded(7, 11);
            fertility = 0;
            hare *p = dynamic_cast<hare *>(partner);
            p->set_fertility(0);
        }}
    return l;
}
int hare::update(QList <Object *> &food){
    if(full_tummy > 20)
        run(food);
    eat(food);
    live();
    return reproduction(food);
}
