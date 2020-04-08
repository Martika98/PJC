#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "animals.h"
#include "mechanics.h"
#include <QTimer>
#include <QPainter>
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Mechanics *mechanic;
};

#endif // MAINWINDOW_H
