#include "MainWindow.h"

MainWindow :: MainWindow(QWidget * parent) :
        QMainWindow(parent) {
    notBombFound = 0;
    resize (500, 500);
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    layout = new QGridLayout(centralWidget);
    int size = SIZE_OF_FIELD;
    fields.resize(size);
    for(int i = 0; i < size ; ++i) {
        fields [i].resize(size);
        for (int j = 0; j < size ; ++j) {
            Field *newfield = new Field (i, j, this);
            newfield -> setText( "*" );
            fields [i][j] = newfield;
            layout -> addWidget(newfield, i, j);
            connect ( newfield , SIGNAL (moved(int, int )),
                    this, SLOT(movehandler(int, int )));
        }
    }
    plantBombs();
}

MainWindow :: ~MainWindow() {
    for (int i = 0; i < fields.size(); ++i ) {
        for (int j = 0; j < fields.size(); ++j ) {
            delete fields [i][j];
        }
        fields[i].clear();
    }
    fields.clear();
    delete layout;
    delete centralWidget;
}

void MainWindow :: lose() {
    for (int i = 0; i < fields.size(); i++) {
        for (int j = 0; j < fields.size(); j++) {
            fields[i][j] -> setText ("YOU LOST!");
            fields[i][j] -> setEnabled(false);
        }
    }
}

bool MainWindow::isOpenable(int row, int col) {
    if ((row == -1) or (col == -1))
        return false;
    if ((row == fields.size()) or (col == fields.size()))
        return false;
    if (fields[row][col] -> getValue() == -1)
        return false;
    if (fields[row][col] -> isClosed() == false)
        return false;
    return true;
}

void MainWindow::openAround(int row, int col) {
    if (fields[row][col] -> getValue() == -1)
        return;
    qDebug() << "I AM GROOT\n";
    if (isOpenable(row, col - 1)) {
        fields[row][col - 1]->showValue();
        if (fields[row][col - 1]->getValue() == 0)
            openAround(row, col - 1);
        notBombFound++;
    }

    if (isOpenable(row - 1, col - 1)) {
        fields[row - 1][col - 1]->showValue();
        if (fields[row - 1][col - 1]->getValue() == 0)
            openAround(row - 1, col - 1);
        notBombFound++;
    }

    if (isOpenable(row - 1, col)) {
        fields[row - 1][col]->showValue();
        if (fields[row - 1][col]->getValue() == 0)
            openAround(row - 1, col);
        notBombFound++;
    }
    if (isOpenable(row - 1, col + 1)) {
        fields[row - 1][col + 1]->showValue();
        if (fields[row - 1][col + 1]->getValue() == 0)
            openAround(row - 1, col + 1);
        notBombFound++;
    }
    if (isOpenable(row, col + 1)) {
        fields[row][col + 1]->showValue();
        if (fields[row][col + 1]->getValue() == 0)
            openAround(row, col + 1);
        notBombFound++;
    }
    if (isOpenable(row + 1, col + 1)) {
        fields[row + 1][col + 1]->showValue();
        if (fields[row + 1][col + 1]->getValue() == 0)
            openAround(row + 1, col + 1);
        notBombFound++;
    }
    if (isOpenable(row + 1, col)) {
        fields[row + 1][col]->showValue();
        if (fields[row + 1][col]->getValue() == 0)
            openAround(row + 1, col);
        notBombFound++;
    }
    if (isOpenable(row + 1, col - 1)) {
        fields[row + 1][col - 1]->showValue();
        if (fields[row + 1][col - 1]->getValue() == 0)
            openAround(row + 1, col - 1);
        notBombFound++;
    }
    if (notBombFound == fields.size() * fields.size() - NUMBER_OF_BOMBS)
        win();
}

void MainWindow :: win() {
     for (int i = 0; i < fields.size(); i++) {
        for (int j = 0; j < fields.size(); j++) {
            fields[i][j] -> showValue();
            fields[i][j] -> setText ("YOU WIN!");
            fields[i][j] -> setEnabled(false);
        }
    }
}

void MainWindow :: movehandler(int row, int col) {
    qDebug() << row << col << fields[row][col]->getValue() << notBombFound << endl;
    if (fields[row][col]->getValue() == -1)
        lose();
    openAround(row, col);
    notBombFound++;
    if (notBombFound == fields.size() * fields.size() - NUMBER_OF_BOMBS)
        win();
    fields[row][col] -> showValue();
}

void MainWindow :: plantBombs() {
    srand(time(NULL));
    int planted = 0;
    while(planted < NUMBER_OF_BOMBS) {
        int x = rand() % fields.size(), y = rand() % fields.size();
        if (fields[x][y]->getValue() != -1) {
            fields[x][y]->setValue(-1);
            planted++;
        }
    }
    int size = fields.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int n = 0;  // number of bombs arround
    		if (fields[i][j]->getValue() == -1) continue;
    		if ((j != 0) and (fields[i][j - 1]->getValue() == -1)) n++;
    		if ((j != 0) and (i != 0) and (fields[i - 1][j - 1]->getValue() == -1)) n++;
    		if ((i != 0) and (fields[i - 1][j]->getValue() == -1)) n++;
    		if ((i != 0) and (j != size - 1) and (fields[i - 1][j + 1]->getValue() == -1)) n++;
    		if ((j != size - 1) and (fields[i][j + 1]->getValue() == -1)) n++;
    		if ((i != size - 1) and (j != size - 1) and (fields[i + 1][j + 1]->getValue() == -1)) n++;
    		if ((i != size - 1) and (fields[i + 1][j]->getValue() == -1)) n++;
    		if ((i != size - 1) and (j != 0) and (fields[i + 1][j - 1]->getValue() == -1)) n++;
			fields[i][j]->setValue(n);
            qDebug() << i << ' ' << j << ' ' << n << endl;
        }
    }
    qDebug() << "VALUES CALCULATED";
}
