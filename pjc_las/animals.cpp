#include "animals.h"
animals::animals(double a, double b, int c){
    fertility = 0;
    life = a;
    max_velocity = b;
    stamina = c;
    fatigue = 0;
    visibility = true;
}
animals::~animals(){
    if(partner != nullptr)
        partner->partner = nullptr;
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
void animals::set_wounds(int a){
    wounds = a;
}
void animals::live(){
    full_tummy -= 0.35;
    fertility += 1.1;
    if(full_tummy < 20)
        life -= 0.5;
    life -= 0.1;
    if (life < 0)
        set_nexist();
    if(fatigue > 0){
        fatigue -= stamina;
        fatigue += wounds;
        if(fatigue < 0)
            fatigue = 0;
    }
    if (wounds < 0)
        wounds -= 1;
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
void animals::run(QList <Object *> & Predator_list){
}
bool animals::get_safety(){
    return safety;
}
double animals::get_life(){
    return life;
}






