#ifndef SNAKE_H
#define SNAKE_H
#include "animals.h"
#include <QRandomGenerator>
#include "mouse.h"

class Snake : public animals{
public:
    Snake();
    int update (QList<Object *> &Object_list);
    void eat(QList<Object *> &Object_list);
    int reproduction(QList<Object *> &Object_list);
    void hide (QList<Object *> &Object_list);
};

#endif // SNAKE_H
