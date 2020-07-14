#include "bear.h"

Bear::Bear() : animals(90, 4, 15){
    velocity = get_maxvelocity();
    full_tummy = 70;
    safety = true;
}
int Bear::update (QList<Object *> &Object_list){
    live();
    eat(Object_list);
    return reproduction(Object_list);
}
void Bear::eat (QList<Object *> &food){
    if (full_tummy < 50 && food.length() != 0){
        bool foode = false; //czy istnieje jakiś wilk
        safety = true;
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        int j = -1;
        for (int i = 0; i < food.length(); i++) {
            Seeds *p = dynamic_cast<Seeds *>(food[i]);
            Snake *s = dynamic_cast<Snake *>(food[i]);
            //dodać jakieś żółwie czy coś
            if(p || (s && s->get_visibility())){
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
            if (dist < 40){
                int i = QRandomGenerator::system()->bounded(1, 17);
                if(Seeds *p = dynamic_cast<Seeds *>(food[j])){
                    set_full_tummy(20);
                    p->set_nexist();
                }
                if(Snake *s = dynamic_cast<Snake *>(food[j])){
                    if(i > 5)
                    {
                        set_full_tummy(40);
                        fatigue += 1;
                        s->set_nexist();
                    }
                    else
                    {
                        fatigue +=10;
                        if(i > 10){
                            s->set_wounds(i*2);
                        }
                    }

                }

        }}
}}
int Bear::reproduction(QList<Object *> &Object_list){
    int l = 0;
    double distx = 0, disty = 0, dist =0;
    int p1, p2;
    if(fertility > 40 && full_tummy > 70 && partner == nullptr){
        for (int i = 0; i < Object_list.length(); i++){
            Bear *p = dynamic_cast<Bear *>(Object_list[i]);
            if(p){
                if((p->partner == nullptr || p->partner == this) && p != this && p->get_fertility() > 40){
                    p->partner = this;
                    partner = p;
                    break;
                }
            }
        }}
    if(partner != nullptr && full_tummy > 70 && fertility > 40){
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
            l = QRandomGenerator::system()->bounded(1, 2);
            fertility = 0;
            Bear *p = dynamic_cast<Bear *>(partner);
            p->set_fertility(0);
        }
    }
    return l;
}
