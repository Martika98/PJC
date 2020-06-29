#ifndef SPECIES_H
#define SPECIES_H
#include "animals.h"
#include <QRandomGenerator>



class hare : public animals
{
public:
    hare();
//    using animals::eat;
    void eat(QList <Object *> &food);
    void update(QList <Object *> &food);
    void run (QList<Object*> &Predator_list);
    void reproduction(QList<Object *> &Object_list);
};

class wolf : public animals{
public:
    wolf();
    void update(QList<Object *> &food);
    void eat(QList <Object *> &food);
    void reproduction(QList<Object *> &Object_list);

};
class Fox : public animals{
public:
    Fox();
    void update (QList<Object *> &Object_list);
    void eat (QList<Object *> &Object_list);
    void reproduction(QList<Object *> &Object_list);
};

class Mouse : public animals{
public:
    Mouse();
    void update (QList<Object *> &Object_list);
    void eat (QList<Object *> &Object_list);
    void reproduction(QList<Object *> &Object_list);
    void hide(QList<Object *> &Object_list);
};
class Bear : public animals{
public:
    Bear();
    void update (QList<Object *> &Object_list);
    void eat (QList<Object *> &Object_list);
    void reproduction(QList<Object *> &Object_list);
};

class Snake : public animals{
public:
    Snake();
    void update (QList<Object *> &Object_list);
    void eat(QList<Object *> &Object_list);
    void reproduction(QList<Object *> &Object_list);
    void hide (QList<Object *> &Object_list);
};
class Tortoise : public animals{
public:
    Tortoise();
    void update (QList<Object *> &Object_list);
    void eat(QList<Object *> &Object_list);
    void reproduction(QList<Object *> &Object_list);
    void hide ();

};

#endif // SPECIES_H
