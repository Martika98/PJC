#include "wolf.h"



wolf::wolf() : animals(100, 8, 10){
    velocity = get_maxvelocity();
    full_tummy = 60;
    safety = true;
}
int wolf::update(QList<Object *> &food){
    eat(food);
    live();
    return reproduction(food);
}
void wolf::eat(QList <Object *> &food){
    if (full_tummy < 40 && food.length() != 0){
        bool foode = false; //czy istnieje jakiś wilk
        safety = true;
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        int j = -1;
        for (int i = 0; i < food.length(); i++) {
            hare *p = dynamic_cast<hare *>(food[i]);
            if(p){
                dist = abs(poz_x - food[i]->get_poz_x()) + abs(poz_y - food[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
                if(dist < temp && dist > 0)
                {
                    foode = true;
                    distx = food[i]->get_poz_x() - poz_x;
                    disty = food[i]->get_poz_y() - poz_y;
                    temp = dist;
                    j = i;
                }}}
        if(foode){
            dist = sqrt(distx*distx + disty*disty);
            p1 = int(poz_x + velocity * distx/ dist);
            p2 = int(poz_y + velocity * disty/ dist);
            poz_x = p1;
            poz_y = p2;
            fatigue +=1;
            int i = QRandomGenerator::system()->bounded(1, 19);
            if (dist < 40){
                if(i < 12){
                    set_full_tummy(60);
                    food[j]->set_nexist();
                    fatigue += 10;
                }
                else{
                    fatigue += 20;
                    if(i < 9){
                        animals *p = dynamic_cast<animals *>(food[j]);
                        p->set_wounds(i*2);
                    }}

        }}
}}
int wolf::reproduction(QList<Object *> &Object_list){
    int l = 0;
    double distx = 0, disty = 0, dist = 0;
    int p1, p2;
    if(fertility > 40 && full_tummy > 60 && partner == nullptr){
        for (int i = 0; i < Object_list.length(); i++){
            wolf *p = dynamic_cast<wolf *>(Object_list[i]);
            if(p){
                if((p->partner == nullptr || p->partner == this) && p != this && p->get_fertility() > 40){
                    p->partner = this;
                    partner = p;
                    break;
                }
            }
        }}
    if(partner != nullptr && full_tummy > 60 && fertility > 40){
        distx = partner->get_poz_x() - poz_x;
        disty = partner->get_poz_y() - poz_y;
        dist = sqrt(distx*distx + disty*disty);
        if(dist > 10){
            p1 = int (poz_x + velocity * distx/dist);
            p2 = int (poz_y + velocity * disty/dist);
            poz_x = p1;
            poz_y = p2;
        }
        else if(dist <= 10) {
            l = QRandomGenerator::system()->bounded(1, 3);
            fertility = 0;
            wolf *p = dynamic_cast<wolf *>(partner);
            p->set_fertility(0);
        }
    }
    return l;
}
