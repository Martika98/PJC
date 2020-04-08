#ifndef MACHANICS_H
#define MACHANICS_H
#include <QObject>


class Machanics : public QObject
{
    Q_OBJECT
public:
    Machanics();
private slots:
    void tick();
};

#endif // MACHANICS_H
