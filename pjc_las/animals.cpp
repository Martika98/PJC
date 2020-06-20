#include "animals.h"
animals::animals(){

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
void animals::live(){
    full_tummy -= 0.5;

    if(full_tummy < 30)
        life -= 0.5;
    life -= 0.1;
}
void animals::set_full_tummy(double nt){
    full_tummy += nt;
    if(full_tummy > 100)
        full_tummy = 100;
}
double animals::get_full_tummy(){
    return full_tummy;
}





//void animals::eat(QList <Object> &Prey_list, animals *n, int p1, int p2, int p01, int p02, double temp, double dist, int j){
//    if(n->get_full_tummy() < 40 && Prey_list.length() != 0){
//        p1 = 0;
//        p2 = 0;
//        p01 = 0;
//        p02 = 0;
//        temp = 3000;
//        dist = 0;
//        j = 0;
//        for(int i = 0; i < Prey_list.length(); i++){

//              dist = abs(n->get_poz_x() - Prey_list[i].get_poz_x()) + abs(n->get_poz_y() - Prey_list[i].get_poz_y());
//              if(dist < temp){
//                  p1 = Prey_list[i].get_poz_x() - n->get_poz_x();
//                  p2 = Prey_list[i].get_poz_y() - n->get_poz_y();
//                  temp = dist;
//                  j = i;
//              }
//        }
//        dist = sqrt(p1*p1 + p2*p2);
//        p01 = int(n->get_poz_x() + n->get_velocity()*p1/dist);
//        p02 = int(n->get_poz_y() + n->get_velocity()*p2/dist);
//        n->set_poz_x(p01);
//        n->set_poz_y(p02);
//        if(dist<50){
//            n->set_full_tummy(20); //daje tyle pełnego brzuszka ile sam ważył
//            Prey_list.removeAt(j);
//        }

//    }

//}
//void animals::eat(QList <Plant> & plant_list, animals & zajac, int p1, int p2, int p01, int p02, double temp, double dist, int j){
//    if(zajac.get_full_tummy() < 50 && plant_list.length()!=0){
//        p1 = 0;
//        p2 = 0;
//        p01 = 0;
//        p02 = 0;
//        temp = 3000;
//        dist = 0;
//        j = 0;
//        for(int i = 0; i < plant_list.length(); i++)
//        {
//            dist = abs(zajac.get_poz_y() - plant_list[i].get_poz_y())  + abs(zajac.get_poz_x() - plant_list[i].get_poz_x());
//            if (dist < temp)
//            {
//                j = i;
//                temp = dist;
//                p1 = plant_list[i].get_poz_x() - zajac.get_poz_x();
//                p2 = plant_list[i].get_poz_y() - zajac.get_poz_y();

//    }}
//    dist = sqrt(p1*p1 + p2*p2);
//    p01 =int(zajac.get_poz_x() + zajac.get_velocity()*p1/dist);
//    p02 = int(zajac.get_poz_y() + zajac.get_velocity()*p2/dist);
//    zajac.set_poz_x(p01);
//    zajac.set_poz_y(p02);
//    if(dist < 60){
//        zajac.set_full_tummy(plant_list[j].get_nutrition());
//        plant_list.removeAt(j);
//    }
//}

//}
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





