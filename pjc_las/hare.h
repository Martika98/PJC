#ifndef HARE_H
#define HARE_H
#include "animals.h"
#include <QRandomGenerator>

class wolf;

class hare : public animals
{
public:
    hare();
//    using animals::eat;
    void eat(QList <Object *> &food);
    int update(QList <Object *> &food);
    void run (QList<Object*> &Predator_list);
    int reproduction(QList<Object *> &Object_list);
};

#endif // HARE_H
