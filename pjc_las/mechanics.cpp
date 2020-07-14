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

    int cmud = rand()%4;
    for(int i = 0; i < cmud; i++)
    {
        Mud *md = new Mud();
        Object_list.append(md);
        Gobject *new_gob = new Gobject(md);
        Gobject_list.append(new_gob);
    }

    for(int i = 0; i<r; i++)
    {
        Plant *new_plant = new Plant();
        Object_list.append(new_plant);
        Gobject *new_gob = new Gobject(new_plant);
        Gobject_list.append(new_gob);

        Seeds *new_seed = new Seeds();
        Object_list.append(new_seed);
        Gobject *new_gob1 = new Gobject(new_seed);
        Gobject_list.append(new_gob1);

        Stones *new_stone = new Stones();
        Object_list.append(new_stone);
        Gobject *new_gob2 = new Gobject(new_stone);
        Gobject_list.append(new_gob2);
;
    }
    for(int i = 0; i < number_h; i++){
        hare *new_hare = nullptr;
        new_hare = new hare();
        Object_list.append(new_hare);
        Gobject *new_ghare = new Gobject(new_hare);
        Gobject_list.append(new_ghare);
    }

    for(int i = 0; i < w; i++){
        wolf *wolf_ = nullptr;
        wolf_ = new wolf();
        Object_list.append(wolf_);
        Gobject *new_gwolf = new Gobject(wolf_);
        Gobject_list.append(new_gwolf);
    }

    for(int i = 0; i < m; i++){
        Mouse *mouse = nullptr;
        mouse = new Mouse();
        Object_list.append(mouse);
        Gobject *new_gob = new Gobject(mouse);
        Gobject_list.append(new_gob);
    }

    for(int i = 0; i < l; i++){
         Fox *fox = nullptr;
         fox = new Fox();
         Object_list.append(fox);
         Gobject *new_gf = new Gobject(fox);
         Gobject_list.append(new_gf);
    }
    for(int i = 0; i < n; i++){
         Bear *b = nullptr;
         b = new Bear();
         Object_list.append(b);
         Gobject *new_gob = new Gobject(b);
         Gobject_list.append(new_gob);
    }
    for(int i = 0; i < wo; i++){
         Snake *b = nullptr;
         b = new Snake();
         Object_list.append(b);
         Gobject *new_gob = new Gobject(b);
         Gobject_list.append(new_gob);
    }
    for(int i = 0; i < z; i++){
         Tortoise *b = nullptr;
         b = new Tortoise();
         Object_list.append(b);
         Gobject *new_gob = new Gobject(b);
         Gobject_list.append(new_gob);
    }

}
void Mechanics::snap()
{
    int j;
    Object *k = nullptr;
    Gobject *l = nullptr;
    for(int i = 0; i < Object_list.length(); i++){
        k = Object_list[i];
        l = Gobject_list[i];
        j = k->update(Object_list);
        while (j > 0){
            if(hare *b = dynamic_cast<hare *>(k))
            {
                hare *newl = new hare();
                Object_list.append(newl);
                Gobject *n = new Gobject(newl);
                Gobject_list.append(n);

            }
            if(Mouse *b = dynamic_cast<Mouse *>(k))
            {
                Mouse *newl = new Mouse();
                Object_list.append(newl);
                Gobject *n = new Gobject(newl);
                Gobject_list.append(n);
            }
            if(wolf *b = dynamic_cast<wolf *>(k))
            {
                wolf *newl = new wolf();
                Object_list.append(newl);
                Gobject *n = new Gobject(newl);
                Gobject_list.append(n);
            }
            if(Bear *b = dynamic_cast<Bear *>(k))
            {
                Bear *newl = new Bear();
                Object_list.append(newl);
                Gobject *n = new Gobject(newl);
                Gobject_list.append(n);
            }
            if(Snake *b = dynamic_cast<Snake *>(k))
            {
                Snake *newl = new Snake();
                Object_list.append(newl);
                Gobject *n = new Gobject(newl);
                Gobject_list.append(n);
            }
            if(Fox *b = dynamic_cast<Fox *>(k))
            {
                Fox *newl = new Fox();
                Object_list.append(newl);
                Gobject *n = new Gobject(newl);
                Gobject_list.append(n);
            }
            if(Tortoise *b = dynamic_cast<Tortoise *>(k))
            {
                Tortoise *newl = new Tortoise();
                Object_list.append(newl);
                Gobject *n = new Gobject(newl);
                Gobject_list.append(n);
            }
        j--;
        }
        if(k->get_nexist()){
            delete k;
            Object_list.removeAt(i);
            delete l;
            Gobject_list.removeAt(i);
            i = i - 1;
        }
    }

}
void Mechanics::growing_plants(){
    for (int i = 0; i < 6; i++) {
    Plant *new_plant = nullptr;
    new_plant = new Plant();
    Object_list.append(new_plant);
    Gobject *n = new Gobject(new_plant);
    Gobject_list.append(n);


    Seeds *new_seed = new Seeds();
    Object_list.append(new_seed);
    Gobject *nk = new Gobject(new_seed);
    Gobject_list.append(nk);
}}


