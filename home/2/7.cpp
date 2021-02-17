#include <iostream>
#include <iomanip>
using namespace std;

class Vector {
    double x, y, z;
public:
    Vector();
    Vector(double, double, double);
    friend istream& operator>> (istream &, Vector &);
    friend ostream & operator<< (ostream &, const Vector &);
};

Vector::Vector() {
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(double x_, double y_, double z_) {
    x = x_;
    y = y_;
    z = z_;
}

istream& operator>>(istream & in, Vector & v) {
    in >> v.x >> v.y >> v.z;
    return in;
}

ostream& operator<<(ostream & out, const Vector & v) {
    out << "(" << fixed << setprecision (2) << v.x << "; " << v.y << "; "<< v.z << ")";
    return out;
}

class Matrix {
    double m[3][3];
public:
    Matrix(double = 1);
    Matrix(double[3][3]);
    friend istream& operator>> (istream&, Matrix&);
    friend ostream& operator<< (ostream&, Matrix&);
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
    int i;
    in >> i;
    if (i == 0)
        mtr = Matrix();
    else if (i == 1) {
        double k;
        in >> k;
        mtr = Matrix(k);
    } else {
        double tmp[3][3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                in >> tmp[i][j];
        mtr = Matrix(tmp);
    }
    return in;
}

ostream& operator<< (ostream& out, Matrix & mtr) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            out << fixed << setprecision(2) << mtr.m[i][j] << ' ';
        out << endl;
    }
    return out;
}

int main() {
    Matrix a;
    cin >> a;
    cout << a;
    return 0;
}