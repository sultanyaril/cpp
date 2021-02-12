#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct vector {
    double x, y;
    void scan();
    void print();
    void normalize();
    float len();
};

void vector::scan() {
    cout << "Введите значения вектора через пробел (x y) ";
    cin >> x >> y;
    return;
}

void vector::print() {
    cout <<'('<< fixed << setprecision(2) << x << "; " << fixed << setprecision(2) << y << ')'<< endl;
}

float vector::len() {
    return sqrt(x*x + y*y);
}

void vector::normalize() {
    int l = len();
    x /= l;
    y /= l;
    return;
}

int main() {
    vector a;
    a.scan();
    a.normalize();
    a.print();
    return 0;
}