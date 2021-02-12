#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct vector {
    double x, y;
    void scan();
    void print();
    double cross(const vector & tmp);
};

void vector::scan() {
    cout << "Введите значения вектора через пробел (x y) ";
    cin >> x >> y;
    return;
}

void vector::print() {
    cout <<'('<< fixed << setprecision(2) << x << "; " << fixed << setprecision(2) << y << ')'<< endl;
}

double vector::cross(const vector & tmp) {
    return x * tmp.y - y * tmp.x;
}

int main() {
    vector a, b;
    a.scan();
    b.scan();
    cout << fixed << setprecision(2) << a.cross(b) << endl;
    return 0;
}