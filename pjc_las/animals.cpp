#include "animals.h"
animals::animals(){
    fertility = 0;
}
animals::~animals(){

}

bool animals::get_visibility(){
    return visibility;
}
void animals::set_visibility(bool v){
    visibility = v;
}

void animals::set_poz_x(int poz){
    poz_x = poz;
}
void animals::set_poz_y(int poz){
    poz_y = poz;
}
double animals::get_velocity(){
    return velocity;
}
double animals::get_maxvelocity(){
    return max_velocity;
}

void animals::set_velocity(double v){
    velocity = v;
}
void animals::live(){
    full_tummy -= 0.5;
    fertility += 1;
    if(full_tummy < 30)
        life -= 0.5;
    life -= 0.1;
    if (life < 0)
        nexist = true;
}
void animals::set_full_tummy(double nt){
    full_tummy += nt;
    if(full_tummy > 100)
        full_tummy = 100;
}
double animals::get_full_tummy(){
    return full_tummy;
}
int animals::get_fertility(){
    return fertility;
}
void animals:: set_fertility(int a){
    fertility = a;
}

void animals::reproduction(){
}

void animals::run(QList <Object *> & Predator_list){

}
bool animals::get_safety(){
    return safety;
}
double animals::get_life(){
    return life;
}
void animals::eat(QList <Object *> &food){
}
void animals::update(QList <Object *> &food){
}





