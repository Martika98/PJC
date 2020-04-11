#ifndef MECHANICS_H
#define MECHANICS_H
#include <QObject>
#include <QTimer>
#include <animals.h>
#include <plant.h>
#include <cmath>



class Mechanics : public QObject
{
    Q_OBJECT
public:
    Mechanics();
    int hare_get_poz_x();
    int hare_get_poz_y();
    QPixmap hare_get_icon();
    double temp, temp_3, dist, p11, p22;
    int temp_1, p1, p2, p01, p02;
    QList <Plant> plant_list;



private slots:
    void snap();
private:
    QTimer *timer;
    hare *zajac;


};

#endif // MECHANICS_H
