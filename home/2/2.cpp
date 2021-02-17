#include <iostream>
#include <iomanip>
using namespace std;

class Vector {
    double x, y, z;
public:
    Vector(double = 0, double = 0, double = 0);
    Vector operator+ (const Vector &);
    Vector operator- (const Vector &);
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

Vector Vector::operator+ (const Vector & v) {
    return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator- (const Vector & v) {
    return Vector(x - v.x, y - v.y, z - v.z);
}

class Matrix {
    double m[3][3];
};

int main() {
    Vector a, b;
    cin >> a >> b;
    cout << a + b << endl << a - b << endl; 
    return 0;
}