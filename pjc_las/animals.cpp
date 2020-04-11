#include "animals.h"

animals::animals()
{


}
int animals::get_poz_x(){
    return poz_x;
}
int animals::get_poz_y(){
    return poz_y;
}
hare::hare(){
    icon = QPixmap(":/ikonki/kurik.png");
    poz_x = rand()%1180 +20;
    poz_y = rand()%620 + 20;
    max_velocity = velocity = 10;
    full_tummy = 100;
}
void animals::set_poz_x(int poz){
    poz_x = poz;
}
void animals::set_poz_y(int poz){
    poz_y = poz;
}
QPixmap animals::get_icon(){
    return icon;
}
double animals::get_velocity(){
    return velocity;
}
void animals::live(){
    full_tummy -= 1;
}
void animals::set_full_tummy(int nt){
    full_tummy += nt;
    if(full_tummy > 100)
        full_tummy = 100;
}
double animals::get_full_tummy(){
    return full_tummy;
}
