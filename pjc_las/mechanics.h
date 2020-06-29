#ifndef MECHANICS_H
#define MECHANICS_H
#include <QObject>
#include <QTimer>
#include "species.h"
#include "plant.h"
#include "gobject.h"

class Mechanics : public QObject
{
    Q_OBJECT
public:
    Mechanics(int k, int w, int m, int l, int n, int r, int wo, int z);
    QList <Object *> Object_list;
    QList <Gobject *> Gobject_list;
     int p1, p2, p01, p02, j;
     double temp, dist;

private slots:
    void snap();
    void growing_plants();
private:
    QTimer *timer, *timer_2;
    int number_h;
};

#endif // MECHANICS_H
