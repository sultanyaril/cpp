#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct vector {
    double x, y;
    void scan();
    void print();
    vector sum(const vector & tmp);
};

void vector::scan() {
    cout << "Введите значения вектора через пробел (x y) ";
    cin >> x >> y;
    return;
}

void vector::print() {
    cout <<'('<< fixed << setprecision(2) << x << "; " << fixed << setprecision(2) << y << ')'<< endl;
}

vector vector::sum(const vector & tmp) {
    vector answ;
    answ.x = x + tmp.x;
    answ.y = y + tmp.y;
    return answ;
}

int main() {
    vector a, b;
    a.scan();
    b.scan();
    a.sum(b).print();
    return 0;
}