#include "plant.h"

Plant::Plant()
{
    icon = QPixmap(":/ikonki/plant.png");
    poz_x = rand()%1180;
    poz_y = rand()%620;


}
Plant::~Plant(){
}
int Plant::get_poz_x(){
    return poz_x;
}
int Plant::get_poz_y(){
    return poz_y;
}
QPixmap Plant::get_icon(){
    return icon;
}
int Plant::get_nutrition(){
    return nutrition;
}
