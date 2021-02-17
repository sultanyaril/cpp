#include <iostream>
#include <iomanip>
using namespace std;

class Vector {
    double x, y, z;
public:
    Vector();
    Vector(double, double, double);
    Vector operator*(const Vector &);
    Vector operator*(const double);
    Vector operator/(const double);
    Vector operator+(const Vector &);
    Vector operator-(const Vector &);
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

Vector Vector::operator*(const Vector & v) {
    return Vector(y * v.z - v.y * z, - x * v.z + v.x * z, x * v.y - v.x * y);
}

Vector Vector::operator+ (const Vector & v) {
    return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator- (const Vector & v) {
    return Vector(x - v.x, y - v.y, z - v.z);
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
    Vector a, b;
    cin >> a >> b;
    cout << a * 2 - b / 3 + a * b << endl;
    return 0;
}