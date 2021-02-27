#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QTimerEvent>

#include "game.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

    QWidget *centralWidget;
    QGridLayout *layout;
    QLabel *label;
    QPixmap *pixmap;
    Game game;

    int timerid;

public:
    void timerEvent(QTimerEvent *event);
    void frame();
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();
};

#endif
