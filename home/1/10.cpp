#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct vector {
    double x, y;
    void scan();
    void print();
    vector rotate(const double & alpha);
};

void vector::scan() {
    cout << "Введите значения вектора через пробел (x y) ";
    cin >> x >> y;
    return;
}

void vector::print() {
    cout <<'('<< fixed << setprecision(2) << x << "; " << fixed << setprecision(2) << y << ')'<< endl;
}

vector vector::rotate(const double & alpha) {
    vector answ;
    answ.x = x * cos(alpha * M_PI / 180.0) 
        - y * sin(alpha * M_PI / 180.0);
    answ.y = x * sin(alpha * M_PI / 180.0)  
        + y * cos(alpha * M_PI / 180.0) ;
    return answ;
}

int main() {
    vector a;
    double alpha;
    a.scan();
    cout << "Введите угол: ";
    cin >> alpha;
    a.rotate(alpha).print();
    return 0;
}