#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Dialog w; //okno pozwalające wpisać ilość zwierząt
    w.show();

    return a.exec();
}
