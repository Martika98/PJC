#include "species.h"
#include "mainwindow.h"

hare::hare(){
    name = "hare";
    max_velocity = velocity = 10;
    full_tummy = 90;
    life = 80;
    safety = false;
}
void hare::eat(QList <Object *> &food){
    if (full_tummy < 40 && food.length() != 0 && safety){
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
                set_full_tummy(20);
                food.removeAt(j);
            }
        }
    }
}
void hare::run(QList<Object *> &Predator_list){
    for(int i = 0; i < Predator_list.length(); i++){
        bool predatore = false; //czy istnieje jakiś wilk
        safety = false;
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        for (int i = 0; i < Predator_list.length(); i++) {
            wolf *p = dynamic_cast<wolf *>(Predator_list[i]);
            if(p){
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
}
void hare::update(QList <Object *> &food){
    run(food);
    eat(food);
    live();
}

wolf::wolf(){
    name = "wolf";
    max_velocity = velocity = 20;
    full_tummy = 100;
    life = 100;
    safety = true;
}
void wolf::update(QList<Object *> &food){
    eat(food);
    live();
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
            if (dist < 40){
                set_full_tummy(80);
                food.removeAt(j);

        }}
}}

Fox::Fox(){
    max_velocity = velocity = 20;
    full_tummy = 100;
    life = 100;
    safety = true;
}

void Fox::update (QList<Object *> &Object_list){
    run(Object_list);
    eat(Object_list);
    live();

}
void Fox::eat (QList<Object *> &Object_list){

}
void Fox::reproduction(QList<Object *> &Object_list){

}

Mouse::Mouse(){
    max_velocity = velocity = 13;
    full_tummy = 100;
    life = 70;
    safety = true;
}

void Mouse::update (QList<Object *> &Object_list){
    eat(Object_list);
    live();

}
void Mouse::eat (QList<Object *> &Object_list){

    if (full_tummy < 40 && safety){
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
                    set_full_tummy(20);
                    Object_list.removeAt(j);

}}}}
void Mouse::reproduction(QList<Object *> &Object_list){

}
