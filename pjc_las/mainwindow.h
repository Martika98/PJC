#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "animals.h"
#include "mechanics.h"
#include <QTimer>
#include <QPainter>
#include <QMainWindow>
#include <iostream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int k, int w,int m,int l,int n, int roslinka, int waz, int zolw, QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    Mechanics *mechanic;
    Gobject *obrazki = new Gobject;
    QString *s = new QString;
    QList <QPixmap *> picture_list;

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int kp;
    int km, wm, mm, lm, nm, rm;
};

#endif // MAINWINDOW_H
