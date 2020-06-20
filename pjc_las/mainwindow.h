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
    explicit MainWindow(int k, QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    Mechanics *mechanic;
    QPoint *point = new QPoint(20,20);
    QString *s = new QString;

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int kp;
};

#endif // MAINWINDOW_H
