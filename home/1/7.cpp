#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct vector {
    double x, y;
    void scan();
    void print();
    double cross(const vector & tmp);
    bool isCollinear(const vector & tmp);
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

bool vector::isCollinear(const vector & tmp) {
    if (cross(tmp)) 
        return false;
    return true;
}

int main() {
    vector a, b;
    a.scan();
    b.scan();
    if (a.isCollinear(b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}