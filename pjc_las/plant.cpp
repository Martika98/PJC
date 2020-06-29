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
void Plant::update(QList<Object *> food){
}
Seeds::Seeds(){

}
void Seeds::update(QList <Object *> Object_list){

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
                animal->set_velocity(animal->get_maxvelocity()/2);
            if(abs(animal->get_poz_x() - center_x) >= 140 && abs(animal->get_poz_y() - center_y) >= 140 && abs(animal->get_poz_x() - center_x) < 150 && abs(animal->get_poz_y() - center_y) < 150)
                animal->set_velocity(animal->get_maxvelocity());
    }}}}

void Mud::update(QList<Object *> &Object_list){
    change_velocity(Object_list);

}
Stones::Stones(){

}
