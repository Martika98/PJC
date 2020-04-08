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
    poz_x = rand()%1180;
    poz_y = rand()%620;
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
