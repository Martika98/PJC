#ifndef WOLF_H
#define WOLF_H
#include "animals.h"
#include <QRandomGenerator>
#include "hare.h"

class wolf : public animals{
public:
    wolf();
    int update(QList<Object *> &food);
    void eat(QList <Object *> &food);
    int reproduction(QList<Object *> &Object_list);

};

#endif // WOLF_H
