#include <iostream>
#include <iomanip>
using namespace std;

class Vector {
    double x, y, z;
public:
    Vector(double = 0, double = 0, double = 0);
    Vector operator* (const double);
    Vector operator/ (const double);
    friend istream& operator>> (istream &, Vector &);
    friend ostream & operator<< (ostream &, const Vector &);
};

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
    out << '(' << fixed << setprecision (2) << v.x << "; " << v.y << "; "<< v.z << ')';
    return out;
}

Vector Vector::operator* (const double k) {
    return Vector(x * k, y * k, z * k);
}

Vector Vector::operator/ (const double k) {
    if (k == 0) {
        cout << "Error: division by zero" << endl;
        exit(-1);
    }
    return Vector(x / k, y / k, z / k);
}

class Matrix {
    double m[3][3];
};

int main() {
    Vector a;
    double k;
    cin >> a >> k;
    cout << a * k << endl << a / k << endl;
    return 0;
}