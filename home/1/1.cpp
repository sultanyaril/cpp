#include <iostream>
#include <iomanip>
using namespace std;
struct vector {
    double x, y;
    void scan();
    void print();
};

void vector::scan() {
    cout << "Введите значения вектора через пробел (x y) ";
    cin >> x >> y;
    return;
}

void vector::print() {
    cout <<'('<< fixed << setprecision(2) << x << "; " << fixed << setprecision(2) << y << ')'<< endl;
}

int main() {
    vector a;
    a.scan();
    a.print();
    return 0;
}