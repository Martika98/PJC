#include "mechanics.h"


Mechanics::Mechanics(int k, int w, int m, int l, int n, int r, int wo, int z)
{

    timer = new QTimer;
    timer_2 = new QTimer;

    connect(timer, SIGNAL(timeout()), this, SLOT(snap()));
    timer->start(10000/60);
    connect(timer_2, SIGNAL(timeout()), this, SLOT(growing_plants()));
    timer_2->start(5000);

    number_h = k;

    for(int i = 0; i<r; i++)
    {
        Plant *new_plant = new Plant();
        Object_list.append(new_plant);

        Seeds *new_seed = new Seeds();
        Object_list.append(new_seed);

        Stones *new_stone = new Stones();
        Object_list.append(new_stone);
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

    for(int i = 0; i < w; i++){
        wolf *wolf_ = nullptr;
        wolf_ = new wolf();
        Object_list.append(wolf_);
//        Gobject *new_gwolf = new Gobject(wolf_);
//        Gobject_list.append(new_gwolf);
    }

    for(int i = 0; i < m; i++){
        Mouse *mouse = nullptr;
        mouse = new Mouse();
        Object_list.append(mouse);
    }

    for(int i = 0; i < l; i++){
         Fox *fox = nullptr;
         fox = new Fox();
         Object_list.append(fox);
//        Gobject *new_mouse = new Gobject(mouse);
//        Gobject_list.append(new_mouse);
    }
    for(int i = 0; i < n; i++){
         Bear *b = nullptr;
         b = new Bear();
         Object_list.append(b);
    }
    for(int i = 0; i < wo; i++){
         Snake *b = nullptr;
         b = new Snake();
         Object_list.append(b);
    }
    for(int i = 0; i < z; i++){
         Tortoise *b = nullptr;
         b = new Tortoise();
         Object_list.append(b);
    }
    int cmud = rand()%4;
    for(int i = 0; i < cmud; i++)
    {
        Mud *md = new Mud();
        Object_list.append(md);
    }
}
void Mechanics::snap()
{
    Object *k = nullptr;
    for(int i = 0; i < Object_list.length(); i++){
        k = Object_list[i];
        k->update(Object_list);
        if(k->nexist){
            k->~Object();
            Object_list.removeAt(i);

            i = i - 1;
        }

    }
}
void Mechanics::growing_plants(){
    for (int i = 0; i < 6; i++) {
    Plant *new_plant = nullptr;
    new_plant = new Plant();
    Object_list.append(new_plant);


    Seeds *new_seed = new Seeds();
    Object_list.append(new_seed);
}}


