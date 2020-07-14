#ifndef TORTOISE_H
#define TORTOISE_H
#include "animals.h"
#include <QRandomGenerator>
#include "mouse.h"

class Fox;

class Tortoise : public animals{
public:
    Tortoise();
    int update (QList<Object *> &Object_list);
    void eat(QList<Object *> &Object_list);
    int reproduction(QList<Object *> &Object_list);
    void hide ();
    void issafe(QList<Object *> &Object_list);

};

#endif // TORTOISE_H
