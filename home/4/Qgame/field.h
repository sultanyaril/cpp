#ifndef FIELD_H
#define FIELD_H
#include <QPushButton>
#include <QWidget>
#include <QDebug>
#include <string>
class Field : public QPushButton {
    Q_OBJECT
    int row ,col;
    int value;  // number of bombs around (-1) if its bomb
    bool closed;
public :
    Field(int row, int col, QWidget *parent = NULL);
    void setValue(int);
    int getValue();
    void showValue();
    bool isClosed();
signals :
    void moved (int row, int col);

public slots :
    void clickhandler();
};

#endif
