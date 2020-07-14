#include "mouse.h"

Mouse::Mouse() : animals(70, 6, 4){
    velocity = get_maxvelocity();
    full_tummy = 60;
    safety = true;
}

int Mouse::update (QList<Object *> &Object_list){
    eat(Object_list);
    live();

    if(fertility < 30 && visibility && full_tummy > 40)
        hide(Object_list);
    if(visibility == false && (fertility > 30 || full_tummy < 40))
        visibility = true;
    return reproduction(Object_list);
}

void Mouse::hide(QList<Object *> &Object_list){

    bool stonee = false; //czy istnieje jakiś kamień
    double dist = 0;
    double distx = 0;
    double disty = 0;
    double temp = 3000;
    int p1 = 0, p2 = 0;
    for (int i = 0; i < Object_list.length(); i++) {
        Stones *p = dynamic_cast<Stones *>(Object_list[i]);
        if(p){
            stonee = true;
            dist = abs(poz_x - Object_list[i]->get_poz_x()) + abs(poz_y - Object_list[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
            if(dist < temp && dist > 0)
            {
                distx = Object_list[i]->get_poz_x() - poz_x;
                disty = Object_list[i]->get_poz_y() - poz_y;
                temp = dist;
            }}}
        if(stonee){
            dist = sqrt(distx*distx + disty*disty);
            p1 = int(poz_x + velocity * distx/ dist);
            p2 = int(poz_y + velocity * disty/ dist);
            poz_x = p1;
            poz_y = p2;
            if(dist < 10)
            {
                set_visibility(false);
            }
        }
}
void Mouse::eat (QList<Object *> &Object_list){

    if (full_tummy < 50 && safety){
        bool seede = false; //czy istnieje jakieś nasionko
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        int j = -1;
        for (int i = 0; i < Object_list.length(); i++) {
            Seeds *p = dynamic_cast<Seeds *>(Object_list[i]);
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
                    set_full_tummy(60);
                    Object_list[j]->set_nexist();

}}}}
int Mouse::reproduction(QList<Object *> &Object_list){
    int l = 0;
    double distx = 0, disty = 0, dist =0;
    int p1, p2;
    if(fertility > 20 && full_tummy > 50 && partner == nullptr){
        for (int i = 0; i < Object_list.length(); i++){
            Mouse *p = dynamic_cast<Mouse *>(Object_list[i]);
            if(p){
                if((p->partner == nullptr || p->partner == this) && p != this && p->get_fertility() > 20){
                    p->partner = this;
                    partner = p;
                    break;
                }
            }
        }}
    if(partner != nullptr && full_tummy > 50 && fertility > 20){
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
            l = QRandomGenerator::system()->bounded(6, 11);
            fertility = 0;
            Mouse *p = dynamic_cast<Mouse *>(partner);
            p->set_fertility(0);
}}
    return l;
    }
