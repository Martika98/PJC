#include "tortoise.h"
#include "Fox.h"

Tortoise::Tortoise() : animals(100, 2, 5){
    velocity = get_maxvelocity();
    full_tummy = 70;
    safety = true;
}
int Tortoise::update (QList<Object *> &Object_list){
    live();
    if(full_tummy > 90){
        hide();
        return 0;
    }
    else if(full_tummy <= 90 && full_tummy > 50){
        issafe(Object_list);
        if(safety){
            visibility = true;
            return reproduction (Object_list);
        }
        else{
            hide();
            return 0;
        }

    }
    else if (full_tummy <=  50) {
        visibility = true;
        eat(Object_list);
        return 0;
        }
}
void Tortoise::eat(QList<Object *> &Object_list){

    if (full_tummy < 40 && safety && visibility){
        bool seede = false; //czy istnieje jakieś nasionko
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        int j = -1;
        for (int i = 0; i < Object_list.length(); i++) {
            Plant *p = dynamic_cast<Plant *>(Object_list[i]);
            if(p){
                seede = true;
                dist = abs(poz_x - Object_list[i]->get_poz_x()) + abs(poz_y - Object_list[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
                if(dist < temp && dist > 0)
                {
                    distx = Object_list[i]->get_poz_x() - poz_x;
                    disty = Object_list[i]->get_poz_y() - poz_y;
                    temp = dist;
                    j = i;
                }}}
            if(seede){
                dist = sqrt(distx*distx + disty*disty);
                p1 = int(poz_x + velocity * distx/ dist);
                p2 = int(poz_y + velocity * disty/ dist);
                poz_x = p1;
                poz_y = p2;
                if (dist < 40){
                    set_full_tummy(100);
                    Object_list[j]->set_nexist();

}}}
}
int Tortoise::reproduction(QList<Object *> &Object_list){
    int l = 0;
    double distx = 0, disty = 0, dist =0;
    int p1, p2;
    if(fertility > 30 && full_tummy > 50 && partner == nullptr){
        for (int i = 0; i < Object_list.length(); i++){
            Tortoise *p = dynamic_cast<Tortoise *>(Object_list[i]);
            if(p){
                if((p->partner == nullptr || p->partner == this) && p != this && p->get_fertility() > 30){
                    p->partner = this;
                    partner = p;
                    break;
                }
            }
        }}
    if(partner != nullptr && full_tummy > 50 && fertility > 30){
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
            l = QRandomGenerator::system()->bounded(2, 3);
            fertility = 0;
            Tortoise *p = dynamic_cast<Tortoise *>(partner);
            p->set_fertility(0);
        }
    }
    return l;
}
void Tortoise::hide(){
    set_visibility(false);
}
void Tortoise::issafe(QList<Object *> &Object_list){
    bool predatore = false; //czy istnieje jakiś wilk
    safety = false;
    double dist = 0;
    double distx = 0;
    double disty = 0;
    double temp = 3000;
    for (int i = 0; i < Object_list.length(); i++) {
        Fox *p = dynamic_cast<Fox *>(Object_list[i]);
        if(p){
            predatore = true;
            dist = abs(poz_x - Object_list[i]->get_poz_x()) + abs(poz_y - Object_list[i]->get_poz_y());
            if(dist < temp && dist > 0)
            {
                distx = poz_x - Object_list[i]->get_poz_x();
                disty = poz_y - Object_list[i]->get_poz_y();
                temp = dist;
            }}}
    if(predatore && temp < 40)
        safety = false;
    else
        safety = true;
}

