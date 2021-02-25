#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QVector>
#include "field.h"

#define NUMBER_OF_BOMBS 10
#define SIZE_OF_FIELD 8
class MainWindow : public QMainWindow {
    Q_OBJECT
    QWidget * centralWidget ;
    QGridLayout * layout ;
    QVector <QVector<Field *>> fields ;
    int notBombFound;  // ячейки-не-бомбы
public :
    bool isOpenable(int, int);
    void win();
    void lose();
    void openAround(int, int);
    void plantBombs();
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();
public slots :
    void movehandler (int row, int col);
};
