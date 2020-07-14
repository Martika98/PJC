#include "snake.h"


Snake::Snake() : animals(100, 7, 7){
    velocity = get_maxvelocity();
    full_tummy = 100;
    safety = true;
}
int Snake:: update (QList<Object *> &Object_list){
    live();
    if(full_tummy > 80 && visibility)
        hide(Object_list);

    if(full_tummy < 80) {
        visibility = true;
        eat(Object_list);
        return reproduction (Object_list);
    }
    else
        return 0;
}
void Snake::eat(QList<Object *> &food){

    if (full_tummy < 350 && food.length() != 0){
        bool foode = false; //czy istnieje jakiś wilk
        safety = true;
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        int j = -1;
        for (int i = 0; i < food.length(); i++) {
            Mouse *p = dynamic_cast<Mouse *>(food[i]);
            //dodać jakieś żółwie czy coś
            if(p && p->get_visibility()){
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
                set_full_tummy(100);
                food[j]->set_nexist();

        }}
}}
int Snake::reproduction(QList<Object *> &Object_list){
    int l = 0;
    double distx = 0, disty = 0, dist =0;
    int p1, p2;
    if(fertility > 50 && full_tummy > 70 && partner == nullptr){
        for (int i = 0; i < Object_list.length(); i++){
            Snake *p = dynamic_cast<Snake *>(Object_list[i]);
            if(p){
                if((p->partner == nullptr || p->partner == this) && p != this && p->get_fertility() > 50){
                    p->partner = this;
                    partner = p;
                    break;
                }
            }
        }}
    if(partner != nullptr && full_tummy > 70 && fertility > 50){
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
            l = QRandomGenerator::system()->bounded(2, 5);
            fertility = 0;
            Snake *p = dynamic_cast<Snake *>(partner);
            p->set_fertility(0);
        }
    }
    return l;
}
void Snake::hide(QList<Object *> &Object_list){

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
