#include "species.h"


hare::hare(){
    max_velocity = velocity = 13;
    full_tummy = 70;
    life = 80;
    safety = false;
    
}
void hare::eat(QList <Object *> &food){
    if (full_tummy < 50 && food.length() != 0 && safety){
        bool plante = false; //czy istnieje jakaś roślinka
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        int j = -1;
        for (int i = 0; i < food.length(); i++) {
            Plant *p = dynamic_cast<Plant *>(food[i]);
            if(p){
                plante = true;
                dist = abs(poz_x - food[i]->get_poz_x()) + abs(poz_y - food[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
                if(dist < temp && dist > 0)
                {
                    distx = food[i]->get_poz_x() - poz_x;
                    disty = food[i]->get_poz_y() - poz_y;
                    temp = dist;
                    j = i;
                }}}
        if(plante){
            dist = sqrt(distx*distx + disty*disty);
            p1 = int(poz_x + velocity * distx/ dist);
            p2 = int(poz_y + velocity * disty/ dist);
            poz_x = p1;
            poz_y = p2;
            if (dist < 40 && j > -1){
                set_full_tummy(30);
                food.removeAt(j);
            }
        }
    }
}
void hare::run(QList<Object *> &Predator_list){
        bool predatore = false; //czy istnieje jakiś wilk
        safety = false;
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        for (int i = 0; i < Predator_list.length(); i++) {
            wolf *p = dynamic_cast<wolf *>(Predator_list[i]);
            Fox *f = dynamic_cast<Fox *>(Predator_list[i]);
            if(p || f){
                predatore = true;
                dist = abs(poz_x - Predator_list[i]->get_poz_x()) + abs(poz_y - Predator_list[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
                if(dist < temp && dist > 0)
                {
                    distx = poz_x - Predator_list[i]->get_poz_x();
                    disty = poz_y - Predator_list[i]->get_poz_y();
                    temp = dist;
                }}}
        if(predatore && temp < 90){
            dist = sqrt(distx*distx + disty*disty);
            p1 = int(poz_x + velocity * distx/ dist);
            p2 = int(poz_y + velocity * disty/ dist);
            poz_x = p1;
            poz_y = p2;
            safety = false;
            }
        else {
            safety = true;
        }
}
void hare::reproduction(QList<Object *> &Object_list){
    double distx = 0, disty = 0, dist = 0;
    int p1, p2;
    if(fertility > 20 && full_tummy > 60 && partner == nullptr && safety){
        for (int i = 0; i < Object_list.length(); i++){
            hare *p = dynamic_cast<hare *>(Object_list[i]);
            if(p){
                if((p->partner == nullptr || p->partner == this) && p != this && p->get_fertility() > 20){
                    p->partner = this;
                    partner = p;
                    break;
                }
            }
        }}
    if(partner != nullptr && full_tummy > 60 && fertility > 20 && safety){
        distx = partner->get_poz_x() - poz_x;
        disty = partner->get_poz_y() - poz_y;
        dist = sqrt(distx*distx + disty*disty);
        if(dist > 10){
            p1 = int (poz_x + velocity * distx/dist);
            p2 = int (poz_y + velocity * disty/dist);
            poz_x = p1;
            poz_y = p2;
        }
        else if(dist <= 10) {
            int i = QRandomGenerator::system()->bounded(6, 10);
            while (i != 0) {
                hare *m = new hare();
                Object_list.append(m);
                i--;
            }
            fertility = 0;
            hare *p = dynamic_cast<hare *>(partner);
            p->set_fertility(0);
        }
    }
}
void hare::update(QList <Object *> &food){
    run(food);
    eat(food);
    live();
    reproduction(food);
}

wolf::wolf(){
    max_velocity = velocity = 20;
    full_tummy = 60;
    life = 100;
    safety = true;
}
void wolf::update(QList<Object *> &food){
    eat(food);
    live();
    reproduction(food);
}
void wolf::eat(QList <Object *> &food){
    if (full_tummy < 40 && food.length() != 0){
        bool foode = false; //czy istnieje jakiś wilk
        safety = true;
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        int j = -1;
        for (int i = 0; i < food.length(); i++) {
            hare *p = dynamic_cast<hare *>(food[i]);
            if(p){
                dist = abs(poz_x - food[i]->get_poz_x()) + abs(poz_y - food[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
                if(dist < temp && dist > 0)
                {
                    foode = true;
                    distx = food[i]->get_poz_x() - poz_x;
                    disty = food[i]->get_poz_y() - poz_y;
                    temp = dist;
                    j = i;
                }}}
        if(foode){
            dist = sqrt(distx*distx + disty*disty);
            p1 = int(poz_x + velocity * distx/ dist);
            p2 = int(poz_y + velocity * disty/ dist);
            poz_x = p1;
            poz_y = p2;
            if (dist < 40){
                set_full_tummy(50);
                food.removeAt(j);

        }}
}}
void wolf::reproduction(QList<Object *> &Object_list){
    double distx = 0, disty = 0, dist = 0;
    int p1, p2;
    if(fertility > 40 && full_tummy > 60 && partner == nullptr){
        for (int i = 0; i < Object_list.length(); i++){
            wolf *p = dynamic_cast<wolf *>(Object_list[i]);
            if(p){
                if((p->partner == nullptr || p->partner == this) && p != this && p->get_fertility() > 40){
                    p->partner = this;
                    partner = p;
                    break;
                }
            }
        }}
    if(partner != nullptr && full_tummy > 60 && fertility > 40){
        distx = partner->get_poz_x() - poz_x;
        disty = partner->get_poz_y() - poz_y;
        dist = sqrt(distx*distx + disty*disty);
        if(dist > 10){
            p1 = int (poz_x + velocity * distx/dist);
            p2 = int (poz_y + velocity * disty/dist);
            poz_x = p1;
            poz_y = p2;
        }
        else if(dist <= 10) {
            int i = QRandomGenerator::system()->bounded(1, 3);
            while (i != 0) {
                wolf *m = new wolf();
                Object_list.append(m);
                i--;
            }
            fertility = 0;
            wolf *p = dynamic_cast<wolf *>(partner);
            p->set_fertility(0);
        }
    }
}
Fox::Fox(){
    max_velocity = velocity = 20;
    full_tummy = 65;
    life = 100;
    safety = true;
}

void Fox::update (QList<Object *> &Object_list){
    eat(Object_list);
    live();
    reproduction(Object_list);

}
void Fox::eat (QList<Object *> &food){
    if (full_tummy < 50 && food.length() != 0){
        bool foode = false; //czy istnieje jakiś wilk
        safety = true;
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        int j = -1;
        for (int i = 0; i < food.length(); i++) {
            Mouse *p = dynamic_cast<Mouse *>(food[i]);
            Tortoise *h = dynamic_cast<Tortoise *>(food[i]);
            if((h && h->get_visibility())  || p){
                dist = abs(poz_x - food[i]->get_poz_x()) + abs(poz_y - food[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
                if(dist < temp && dist > 0)
                {
                    foode = true;
                    distx = food[i]->get_poz_x() - poz_x;
                    disty = food[i]->get_poz_y() - poz_y;
                    temp = dist;
                    j = i;
                }}}
        if(foode){
            dist = sqrt(distx*distx + disty*disty);
            p1 = int(poz_x + velocity * distx/ dist);
            p2 = int(poz_y + velocity * disty/ dist);
            poz_x = p1;
            poz_y = p2;
            if (dist < 20){
                set_full_tummy(60);
                food.removeAt(j);

        }}
}}
void Fox::reproduction(QList<Object *> &Object_list){
    double distx = 0, disty = 0, dist = 0;
    int p1, p2;
    if(fertility > 40 && full_tummy > 60 && partner == nullptr){
        for (int i = 0; i < Object_list.length(); i++){
            Fox *p = dynamic_cast<Fox *>(Object_list[i]);
            if(p){
                if((p->partner == nullptr || p->partner == this) && p != this && p->get_fertility() > 40){
                    p->partner = this;
                    partner = p;
                    break;
                }
            }
        }}
    if(partner != nullptr && full_tummy > 60 && fertility > 40){
        distx = partner->get_poz_x() - poz_x;
        disty = partner->get_poz_y() - poz_y;
        dist = sqrt(distx*distx + disty*disty);
        if(dist > 10){
            p1 = int (poz_x + velocity * distx/dist);
            p2 = int (poz_y + velocity * disty/dist);
            poz_x = p1;
            poz_y = p2;
        }
        else if(dist <= 10) {
            int i = rand()%2 +1;
            while (i != 0) {
                Fox *m = new Fox();
                Object_list.append(m);
                i--;
            }
            fertility = 0;
            Fox *p = dynamic_cast<Fox *>(partner);
            p->set_fertility(0);
        }
    }
}
Mouse::Mouse(){
    max_velocity = velocity = 13;
    full_tummy = 60;
    life = 70;
    safety = true;
}

void Mouse::update (QList<Object *> &Object_list){
    eat(Object_list);
    live();
    reproduction(Object_list);
    if(fertility < 30 && visibility && full_tummy > 40)
        hide(Object_list);
    if(visibility == false && (fertility > 30 || full_tummy < 40)) {
        visibility = true;
}}

void Mouse::hide(QList<Object *> &Object_list){

    bool stonee = false; //czy istnieje jakiś kamień
    double dist = 0;
    double distx = 0;
    double disty = 0;
    double temp = 3000;
    int p1 = 0, p2 = 0;
    for (int i = 0; i < Object_list.length(); i++) {
        Stones *p = dynamic_cast<Stones *>(Object_list[i]);
        if(p){
            stonee = true;
            dist = abs(poz_x - Object_list[i]->get_poz_x()) + abs(poz_y - Object_list[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
            if(dist < temp && dist > 0)
            {
                distx = Object_list[i]->get_poz_x() - poz_x;
                disty = Object_list[i]->get_poz_y() - poz_y;
                temp = dist;
            }}}
        if(stonee){
            dist = sqrt(distx*distx + disty*disty);
            p1 = int(poz_x + velocity * distx/ dist);
            p2 = int(poz_y + velocity * disty/ dist);
            poz_x = p1;
            poz_y = p2;
            if(dist < 10)
            {
                set_visibility(false);
            }
        }
}
void Mouse::eat (QList<Object *> &Object_list){

    if (full_tummy < 50 && safety){
        bool seede = false; //czy istnieje jakieś nasionko
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        int j = -1;
        for (int i = 0; i < Object_list.length(); i++) {
            Seeds *p = dynamic_cast<Seeds *>(Object_list[i]);
            if(p){
                seede = true;
                dist = abs(poz_x - Object_list[i]->get_poz_x()) + abs(poz_y - Object_list[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
                if(dist < temp && dist > 0)
                {
                    distx = Object_list[i]->get_poz_x() - poz_x;
                    disty = Object_list[i]->get_poz_y() - poz_y;
                    temp = dist;
                    j = i;
                }}}
            if(seede){
                dist = sqrt(distx*distx + disty*disty);
                p1 = int(poz_x + velocity * distx/ dist);
                p2 = int(poz_y + velocity * disty/ dist);
                poz_x = p1;
                poz_y = p2;
                if (dist < 40){
                    set_full_tummy(20);
                    Object_list.removeAt(j);

}}}}
void Mouse::reproduction(QList<Object *> &Object_list){

    double distx = 0, disty = 0, dist =0;
    int p1, p2;
    if(fertility > 20 && full_tummy > 60 && partner == nullptr){
        for (int i = 0; i < Object_list.length(); i++){
            Mouse *p = dynamic_cast<Mouse *>(Object_list[i]);
            if(p){
                if((p->partner == nullptr || p->partner == this) && p != this && p->get_fertility() > 20){
                    p->partner = this;
                    partner = p;
                    break;
                }
            }
        }}
    if(partner != nullptr && full_tummy > 60 && fertility > 20){
        distx = partner->get_poz_x() - poz_x;
        disty = partner->get_poz_y() - poz_y;
        dist = sqrt(distx*distx + disty*disty);
        if(dist > 10){
            p1 = int (poz_x + velocity * distx/dist);
            p2 = int (poz_y + velocity * disty/dist);
            poz_x = p1;
            poz_y = p2;
        }
        else if(dist <= 10) {
            int i = QRandomGenerator::system()->bounded(6, 11);
            while (i != 0)
            {
                Mouse *m = new Mouse();
                Object_list.append(m);
                i--;
            }
            fertility = 0;
            Mouse *p = dynamic_cast<Mouse *>(partner);
            p->set_fertility(0);
        }
    }
}
Bear::Bear(){
    max_velocity = velocity = 9;
    full_tummy = 80;
    life = 100;
    safety = true;
}
void Bear::update (QList<Object *> &Object_list){
    live();
    eat(Object_list);
    reproduction(Object_list);
}
void Bear::eat (QList<Object *> &food){
    if (full_tummy < 50 && food.length() != 0){
        bool foode = false; //czy istnieje jakiś wilk
        safety = true;
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        int j = -1;
        for (int i = 0; i < food.length(); i++) {
            Seeds *p = dynamic_cast<Seeds *>(food[i]);
            Snake *s = dynamic_cast<Snake *>(food[i]);
            //dodać jakieś żółwie czy coś
            if(p || (s && s->get_visibility())){
                dist = abs(poz_x - food[i]->get_poz_x()) + abs(poz_y - food[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
                if(dist < temp && dist > 0)
                {
                    foode = true;
                    distx = food[i]->get_poz_x() - poz_x;
                    disty = food[i]->get_poz_y() - poz_y;
                    temp = dist;
                    j = i;
                }}}
        if(foode){
            dist = sqrt(distx*distx + disty*disty);
            p1 = int(poz_x + velocity * distx/ dist);
            p2 = int(poz_y + velocity * disty/ dist);
            poz_x = p1;
            poz_y = p2;
            if (dist < 40){
                set_full_tummy(40);
                food.removeAt(j);

        }}
}}
void Bear::reproduction(QList<Object *> &Object_list){

    double distx = 0, disty = 0, dist =0;
    int p1, p2;
    if(fertility > 40 && full_tummy > 70 && partner == nullptr){
        for (int i = 0; i < Object_list.length(); i++){
            Bear *p = dynamic_cast<Bear *>(Object_list[i]);
            if(p){
                if((p->partner == nullptr || p->partner == this) && p != this && p->get_fertility() > 40){
                    p->partner = this;
                    partner = p;
                    break;
                }
            }
        }}
    if(partner != nullptr && full_tummy > 70 && fertility > 40){
        distx = partner->get_poz_x() - poz_x;
        disty = partner->get_poz_y() - poz_y;
        dist = sqrt(distx*distx + disty*disty);
        if(dist > 10){
            p1 = int (poz_x + velocity * distx/dist);
            p2 = int (poz_y + velocity * disty/dist);
            poz_x = p1;
            poz_y = p2;
        }
        else if(dist <= 10) {
            int i = QRandomGenerator::system()->bounded(1, 2);
            while (i != 0) {
                Bear *m = new Bear();
                Object_list.append(m);
                i--;
            }
            fertility = 0;
            Bear *p = dynamic_cast<Bear *>(partner);
            p->set_fertility(0);
        }
    }
}
Snake::Snake(){
    max_velocity = velocity = 15;
    full_tummy = 100;
    life = 100;
    safety = true;
}
void Snake:: update (QList<Object *> &Object_list){
    live();
    if(full_tummy > 80 && visibility)
        hide(Object_list);

    if(full_tummy < 80) {
        visibility = true;
        eat(Object_list);
        reproduction (Object_list);
    }
}
void Snake::eat(QList<Object *> &food){

    if (full_tummy < 350 && food.length() != 0){
        bool foode = false; //czy istnieje jakiś wilk
        safety = true;
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        int j = -1;
        for (int i = 0; i < food.length(); i++) {
            Mouse *p = dynamic_cast<Mouse *>(food[i]);
            //dodać jakieś żółwie czy coś
            if(p && p->get_visibility()){
                dist = abs(poz_x - food[i]->get_poz_x()) + abs(poz_y - food[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
                if(dist < temp && dist > 0)
                {
                    foode = true;
                    distx = food[i]->get_poz_x() - poz_x;
                    disty = food[i]->get_poz_y() - poz_y;
                    temp = dist;
                    j = i;
                }}}
        if(foode){
            dist = sqrt(distx*distx + disty*disty);
            p1 = int(poz_x + velocity * distx/ dist);
            p2 = int(poz_y + velocity * disty/ dist);
            poz_x = p1;
            poz_y = p2;
            if (dist < 40){
                set_full_tummy(90);
                food.removeAt(j);

        }}
}}
void Snake::reproduction(QList<Object *> &Object_list){

    double distx = 0, disty = 0, dist =0;
    int p1, p2;
    if(fertility > 50 && full_tummy > 70 && partner == nullptr){
        for (int i = 0; i < Object_list.length(); i++){
            Snake *p = dynamic_cast<Snake *>(Object_list[i]);
            if(p){
                if((p->partner == nullptr || p->partner == this) && p != this && p->get_fertility() > 50){
                    p->partner = this;
                    partner = p;
                    break;
                }
            }
        }}
    if(partner != nullptr && full_tummy > 70 && fertility > 50){
        distx = partner->get_poz_x() - poz_x;
        disty = partner->get_poz_y() - poz_y;
        dist = sqrt(distx*distx + disty*disty);
        if(dist > 10){
            p1 = int (poz_x + velocity * distx/dist);
            p2 = int (poz_y + velocity * disty/dist);
            poz_x = p1;
            poz_y = p2;
        }
        else if(dist <= 10) {
            int i = QRandomGenerator::system()->bounded(2, 5);
            while (i != 0) {
                Snake *m = new Snake();
                Object_list.append(m);
                i--;
            }
            fertility = 0;
            Snake *p = dynamic_cast<Snake *>(partner);
            p->set_fertility(0);
        }
    }
}
void Snake::hide(QList<Object *> &Object_list){

    bool stonee = false; //czy istnieje jakiś kamień
    double dist = 0;
    double distx = 0;
    double disty = 0;
    double temp = 3000;
    int p1 = 0, p2 = 0;
    for (int i = 0; i < Object_list.length(); i++) {
        Stones *p = dynamic_cast<Stones *>(Object_list[i]);
        if(p){
            stonee = true;
            dist = abs(poz_x - Object_list[i]->get_poz_x()) + abs(poz_y - Object_list[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
            if(dist < temp && dist > 0)
            {
                distx = Object_list[i]->get_poz_x() - poz_x;
                disty = Object_list[i]->get_poz_y() - poz_y;
                temp = dist;
            }}}
        if(stonee){
            dist = sqrt(distx*distx + disty*disty);
            p1 = int(poz_x + velocity * distx/ dist);
            p2 = int(poz_y + velocity * disty/ dist);
            poz_x = p1;
            poz_y = p2;
            if(dist < 10)
            {
                set_visibility(false);
            }
        }


}
Tortoise::Tortoise(){
    max_velocity = velocity = 5;
    full_tummy = 70;
    life = 100;
    safety = true;
}
void Tortoise::update (QList<Object *> &Object_list){
    live();
    if(full_tummy > 90)
        hide();
    else {
        eat(Object_list);
        reproduction (Object_list);
    }
}
void Tortoise::eat(QList<Object *> &Object_list){

    if (full_tummy < 40 && safety && visibility){
        bool seede = false; //czy istnieje jakieś nasionko
        double dist = 0;
        double distx = 0;
        double disty = 0;
        double temp = 3000;
        int p1 = 0, p2 = 0;
        int j = -1;
        for (int i = 0; i < Object_list.length(); i++) {
            Plant *p = dynamic_cast<Plant *>(Object_list[i]);
            if(p){
                seede = true;
                dist = abs(poz_x - Object_list[i]->get_poz_x()) + abs(poz_y - Object_list[i]->get_poz_y()); //metryka miejska; odległość królika od rośliny
                if(dist < temp && dist > 0)
                {
                    distx = Object_list[i]->get_poz_x() - poz_x;
                    disty = Object_list[i]->get_poz_y() - poz_y;
                    temp = dist;
                    j = i;
                }}}
            if(seede){
                dist = sqrt(distx*distx + disty*disty);
                p1 = int(poz_x + velocity * distx/ dist);
                p2 = int(poz_y + velocity * disty/ dist);
                poz_x = p1;
                poz_y = p2;
                if (dist < 40){
                    set_full_tummy(20);
                    Object_list.removeAt(j);

}}}
}
void Tortoise::reproduction(QList<Object *> &Object_list){

    double distx = 0, disty = 0, dist =0;
    int p1, p2;
    if(fertility > 30 && full_tummy > 70 && partner == nullptr){
        for (int i = 0; i < Object_list.length(); i++){
            Tortoise *p = dynamic_cast<Tortoise *>(Object_list[i]);
            if(p){
                if((p->partner == nullptr || p->partner == this) && p != this && p->get_fertility() > 30){
                    p->partner = this;
                    partner = p;
                    break;
                }
            }
        }}
    if(partner != nullptr && full_tummy > 70 && fertility > 30){
        distx = partner->get_poz_x() - poz_x;
        disty = partner->get_poz_y() - poz_y;
        dist = sqrt(distx*distx + disty*disty);
        if(dist > 10){
            p1 = int (poz_x + velocity * distx/dist);
            p2 = int (poz_y + velocity * disty/dist);
            poz_x = p1;
            poz_y = p2;
        }
        else if(dist <= 10) {
            int i = QRandomGenerator::system()->bounded(2, 3);
            while (i != 0) {
                Tortoise *m = new Tortoise();
                Object_list.append(m);
                i--;
            }
            fertility = 0;
            Tortoise *p = dynamic_cast<Tortoise *>(partner);
            p->set_fertility(0);
        }
    }
}
void Tortoise::hide(){
    set_visibility(false);
}


