#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct vector {
    double x, y;
    void scan();
    void print();
    double dot(const vector & tmp);
};

void vector::scan() {
    cout << "Введите значения вектора через пробел (x y) ";
    cin >> x >> y;
    return;
}

void vector::print() {
    cout <<'('<< fixed << setprecision(2) << x << "; " << fixed << setprecision(2) << y << ')'<< endl;
}

double vector::dot(const vector & tmp) {
    return x * tmp.x + y * tmp.y;
}

int main() {
    vector a, b;
    a.scan();
    b.scan();
    cout << fixed << setprecision(2) << a.dot(b) << endl;
    return 0;
}