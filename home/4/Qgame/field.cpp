#include "field.h"

Field :: Field (int row, int col, QWidget *parent)
        : QPushButton(parent), row(row), col(col) {
    value = 0;
    closed = true;
    qDebug() << "CONSTRUCTOR";
    connect(this, SIGNAL(clicked()) ,
    this, SLOT (clickhandler()));
}

void Field :: clickhandler(){
    emit moved (row, col);
}

int Field :: getValue() {
    return value;
}

void Field::setValue(int a) {
    value = a;
}

bool Field::isClosed() {
    return closed;
}

void Field::showValue() {
    closed = false;
    setText(QString::number(value));
    setEnabled(false);
}
