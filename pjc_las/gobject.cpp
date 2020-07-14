#include "gobject.h"
#include "mechanics.h"



Gobject::Gobject(Object * obi)
{
    ob = obi;

    Mud *bl = dynamic_cast<Mud *>(ob);
    if(bl){
            this->picture = new QPixmap(":/ikonki/bloto.png");
            npicture = picture;
    }
    hare *h = dynamic_cast<hare *>(ob);
    if(h){
        this->picture = new QPixmap(":/ikonki/kurlik.png");
        npicture = picture;
    }
    wolf *w = dynamic_cast<wolf *>(ob);
    if(w){
        this->picture = new QPixmap(":/ikonki/wilk.png");
        npicture = picture;
    }
    Plant *p = dynamic_cast<Plant *>(ob);
    if(p){
        this->picture = new QPixmap(":/ikonki/plant.png");
        npicture = picture;
    }
    Mouse *m = dynamic_cast<Mouse *>(ob);
    if(m){
        this->picture = new QPixmap(":/ikonki/mouse.png");
        npicture = picture;
    }
    Seeds *s = dynamic_cast<Seeds *>(ob);
    if(s){
        this->picture = new QPixmap(":/ikonki/ziarenka.png");
        npicture = picture;
    }
    Fox *l = dynamic_cast<Fox *>(ob);
    if(l){
        this->picture = new QPixmap(":/ikonki/lis.png");
        npicture = picture;
    }
    Bear *b = dynamic_cast<Bear *>(ob);
    if(b){
        this->picture = new QPixmap(":/ikonki/misio.png");
        npicture = picture;
    }
    Snake *sn = dynamic_cast<Snake *>(ob);
    if(sn){
        this->picture = new QPixmap(":/ikonki/woz.png");
        npicture = picture;
    }
    Tortoise *t = dynamic_cast<Tortoise *>(ob);
    if(t){
            this->picture = new QPixmap(":/ikonki/zolw.png");
            npicture = new QPixmap(":/ikonki/zolws.png");
    }
    Stones *st = dynamic_cast<Stones *>(ob);
    if(st){
        this->picture = new QPixmap(":/ikonki/glaz.png");
        npicture = picture;
    }
    current_picture = picture;

}

Gobject::~Gobject()
{
}
void Gobject :: draw(){
    animals *obk = dynamic_cast<animals *>(ob);
    if(obk){
        if(obk->get_visibility())
            current_picture = picture;
        else {
            current_picture = npicture;
        }
    }
}
