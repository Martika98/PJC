#ifndef OBJECT_H
#define OBJECT_H
#include <cmath>
#include <QString>
#include <QObject>

class Gobject;

class Object
{
private:
    bool nexist;
protected:
    int poz_x;
    int poz_y;
public:
    Object();
    virtual ~Object();
    int get_poz_x();
    int get_poz_y();
    virtual int update(QList <Object *> &food) = 0;
    void set_nexist();
    bool get_nexist();
};

#endif // OBJECT_H+
