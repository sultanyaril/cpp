#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct vector {
    double x, y;
    void scan();
    void print();
    int quadrant();
};

void vector::scan() {
    cout << "Введите значения вектора через пробел (x y) ";
    cin >> x >> y;
    return;
}

void vector::print() {
    cout <<'('<< fixed << setprecision(2) << x << "; " << fixed << setprecision(2) << y << ')'<< endl;
}

int vector::quadrant() {
    if (x > 0 and y > 0)
        return 1;
    if (x < 0 and y > 0)
        return 2;
    if (x < 0 and y < 0)
        return 3;
    if (x > 0 and y < 0)
        return 4;
    return 0;  // случай (0; 0)
}

int main() {
    vector a;
    a.scan();
    cout << a.quadrant() << endl;
    return 0;
}