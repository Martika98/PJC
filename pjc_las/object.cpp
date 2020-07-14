#include "object.h"
#include "gobject.h"

Object::Object()
{
    poz_x = rand()%1700 +20;
    poz_y = rand()%820 + 20;
    nexist = false;


}
int Object::get_poz_x(){
    return poz_x;
}
int Object::get_poz_y(){
    return poz_y;
}

Object::~Object(){

}
void Object::set_nexist(){
    nexist = true;
}
bool Object::get_nexist(){
    return nexist;
}
