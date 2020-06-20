#include "object.h"

Object::Object()
{
    poz_x = rand()%1180 +20;
    poz_y = rand()%620 + 20;

}
int Object::get_poz_x(){
    return poz_x;
}
int Object::get_poz_y(){
    return poz_y;
}

Object::~Object(){
}
void Object::update(QList<Object *> &food){
}
