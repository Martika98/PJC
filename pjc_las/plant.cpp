#include "plant.h"
#include "animals.h"

Plant::Plant()
{

}
Plant::~Plant(){
}

int Plant::get_nutrition(){
    return nutrition;
}
int Plant::update(QList<Object *> &food){
    return 0;
}
Seeds::Seeds(){

}
int Seeds::update(QList <Object *> &Object_list){
    return 0;
}
Seeds::~Seeds(){

}
Mud::Mud(){
    center_x = poz_x + 150;
    center_y = poz_y + 150;
}
void Mud::change_velocity(QList <Object *> &Object_list){
    for (Object *anima : Object_list) {
        animals *animal = dynamic_cast<animals *>(anima);
        if(animal){
            if(abs(animal->get_poz_x() - center_x) < 140 && abs(animal->get_poz_y() - center_y) < 140){
                animal->set_velocity(animal->get_maxvelocity()/10);
            if((abs(animal->get_poz_x() - center_x) >= 140 || abs(animal->get_poz_y() - center_y) >= 140) && abs(animal->get_poz_x() - center_x) < 150 && abs(animal->get_poz_y() - center_y) < 150)
                animal->set_velocity(animal->get_maxvelocity());
    }}}}

int Mud::update(QList<Object *> &Object_list){
    change_velocity(Object_list);
    return 0;
}
Stones::Stones(){
    center_x = poz_x + 30;
    center_y = poz_y + 30;
}
int Stones::update(QList<Object *> &Object_list){
    change_visibility(Object_list);
    return 0;
}
void Stones::change_visibility(QList<Object *> &Object_list){
    for (Object *anima : Object_list) {
        animals *animal = dynamic_cast<animals *>(anima);
        if(animal){
            if(abs(animal->get_poz_x() - center_x) < 140 && abs(animal->get_poz_y() - center_y) < 140){
                animal->set_velocity(animal->get_maxvelocity()/2);
            if(abs(animal->get_poz_x() - center_x) >= 140 && abs(animal->get_poz_y() - center_y) >= 140 && abs(animal->get_poz_x() - center_x) < 150 && abs(animal->get_poz_y() - center_y) < 150)
                animal->set_velocity(animal->get_maxvelocity());
    }}}
}

