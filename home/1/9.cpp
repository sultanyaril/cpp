#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct vector {
    double x, y;
    void scan();
    void print();
    vector mult(const double & k);
};

void vector::scan() {
    cout << "Введите значения вектора через пробел (x y) ";
    cin >> x >> y;
    return;
}

void vector::print() {
    cout <<'('<< fixed << setprecision(2) << x << "; " << fixed << setprecision(2) << y << ')'<< endl;
}

vector vector::mult(const double & k) {
    vector answ;
    answ.x = x * k;
    answ.y = y * k;
    return answ;
}

int main() {
    vector a;
    double k;
    a.scan();
    cout << "Введите k: ";
    cin >> k;
    a.mult(k).print();
    return 0;
}