#ifndef MOUSE_H
#define MOUSE_H
#include "animals.h"
#include <QRandomGenerator>


class Mouse : public animals{
public:
    Mouse();
    int update (QList<Object *> &Object_list);
    void eat (QList<Object *> &Object_list);
    int reproduction(QList<Object *> &Object_list);
    void hide(QList<Object *> &Object_list);
};

#endif // MOUSE_H
