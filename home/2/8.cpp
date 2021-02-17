#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
    double m[3][3];
public:
    Matrix(double = 1);
    Matrix(double[3][3]);
    Matrix operator+ (const Matrix&);
    friend istream& operator>> (istream&, Matrix&);
    friend ostream& operator<< (ostream&, const Matrix&);
};

Matrix::Matrix(double k) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j)
                m[i][j] = k;
            else
                m[i][j] = 0;
        }
    }
}

Matrix::Matrix(double a[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m[i][j] = a[i][j];
}

istream& operator>> (istream& in, Matrix & mtr) {
    double tmp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            in >> tmp[i][j];
    mtr = Matrix(tmp);
    return in;
}

ostream& operator<< (ostream& out, const Matrix & mtr) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            out << fixed << setprecision(2) << mtr.m[i][j] << ' ';
        out << endl;
    }
    return out;
}

Matrix Matrix::operator+ (const Matrix & mtr) {
    Matrix answ;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            answ.m[i][j] = mtr.m[i][j] + m[i][j];
    return answ;
}

int main() {
    Matrix a, b;
    cin >> a >> b;
    cout << a + b;
    return 0;
}