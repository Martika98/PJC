#ifndef FOX_H
#define FOX_H
#include "animals.h"
#include <QRandomGenerator>
#include "mouse.h"
#include "tortoise.h"


class Fox : public animals{
public:
    Fox();
    int update (QList<Object *> &Object_list);
    void eat (QList<Object *> &Object_list);
    int reproduction(QList<Object *> &Object_list);
};


#endif // FOX_H
