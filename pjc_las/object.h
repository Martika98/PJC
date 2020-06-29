#ifndef OBJECT_H
#define OBJECT_H
#include <cmath>
#include <QString>
#include <QObject>

class Gobject;

class Object
{
protected:
    int poz_x;
    int poz_y;
public:
    Object();
    virtual ~Object();
    int get_poz_x();
    int get_poz_y();
    virtual void update(QList <Object *> &food);
    bool nexist; //czy zwierze już nie żyje lub obiekt znikł
};

#endif // OBJECT_H+
