#ifndef MECHANICS_H
#define MECHANICS_H
#include <QObject>
#include <QTimer>
#include <animals.h>


class Mechanics : public QObject
{
    Q_OBJECT
public:
    Mechanics();
    int hare_get_poz_x();
    int hare_get_poz_y();
    QPixmap hare_get_icon();


private slots:
    void snap();
private:
    QTimer *timer;
    hare *zajac;

};

#endif // MECHANICS_H
