#include <iostream>
#include <iomanip>
using namespace std;

class Vector {
    double x, y, z;
public:
    Vector();
    Vector(double, double, double);
    double operator[](char);
    friend istream& operator>> (istream &, Vector &);
    friend ostream & operator<< (ostream &, const Vector &);
};

double Vector::operator[](char c) {
    if (c == 'x')
        return x;
    if (c == 'y')
        return y;
    if (c == 'z')
        return z;
    cout << "Incorrect index" << endl;
    exit(-1);
}

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
};

int main() {
    Vector a;
    char c;
    cin >> a >> c;
    cout << a[c] << endl;
    return 0;
}