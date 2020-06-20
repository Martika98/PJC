#include "mechanics.h"


Mechanics::Mechanics(int k)
{
    timer = new QTimer;
    timer_2 = new QTimer;

    connect(timer, SIGNAL(timeout()), this, SLOT(snap()));
    timer->start(10000/60);
    connect(timer_2, SIGNAL(timeout()), this, SLOT(growing_plants()));
    timer_2->start(5000);

    number_h = k;

    for(int i = 0; i<30; i++)
    {
        Plant *new_plant = new Plant();
        Object_list.append(new_plant);

        Seeds *new_seed = new Seeds();
        Object_list.append(new_seed);
//        Gobject *new_gplant = new Gobject(new_plant);
//        Gobject_list.append(new_gplant);
    }
    for(int i = 0; i < number_h; i++){
        hare *new_hare = nullptr;
        new_hare = new hare();
        Object_list.append(new_hare);
//        Gobject *new_ghare = new Gobject(new_hare);
//        Gobject_list.append(new_ghare);
    }

    for(int i = 0; i < 3; i++){
        wolf *wolf_ = nullptr;
        wolf_ = new wolf();
        Object_list.append(wolf_);
    }

    for(int i = 0; i < 10; i++){
        Mouse *mouse = nullptr;
        mouse = new Mouse();
        Object_list.append(mouse);

//        Gobject *new_gwolf = new Gobject(wolf_);
//        Gobject_list.append(new_gwolf);
    }
}
void Mechanics::snap()
{
    Object *k = nullptr;
    for(int i = 0; i < Object_list.length(); i++){
        k = Object_list[i];
        k->update(Object_list);

//        hare_list[i].run(Object_list, p1, p2, p01, p02, temp, dist);

//        if(hare_list[i].get_safety()){
//            hare_list[i].eat(Object_list, p1, p2, p01, p02, temp, dist, j);
//            //if(hare_list[i].get_life()<70)
//              //  hare_list[i].reproduction();
//        }
//        if(hare_list[i].live() <= 0){
//            hare_list.removeAt(i);
//            i--;
//        }
//    }
//    for(int i = 0; i < wolf_list.length(); i++){

//        wolf_list[i].find_prey(hare_list, wolf_list[i], p1, p2, p01, p02, temp, dist, j);
//        if(wolf_list[i].live() == 0){
//            wolf_list.removeAt(i);
//            i--;
//        }

//    }
    }
}
void Mechanics::growing_plants(){
    Plant *new_plant = nullptr;
    new_plant = new Plant();
    Object_list.append(new_plant);

    Seeds *new_seed = new Seeds();
    Object_list.append(new_seed);
}


