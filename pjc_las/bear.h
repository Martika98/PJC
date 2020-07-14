#ifndef BEAR_H
#define BEAR_H
#include "animals.h"
#include <QRandomGenerator>
#include "snake.h"

class Bear : public animals{
public:
    Bear();
    int update (QList<Object *> &Object_list);
    void eat (QList<Object *> &Object_list);
    int reproduction(QList<Object *> &Object_list);
};

#endif // BEAR_H
