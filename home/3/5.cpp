#include <iostream>
#include <iomanip>
using namespace std;

class Quad {
protected:
    int a, b, c, d;
public:
    Quad(int=0, int=0, int=0, int=0);
    void virtual print() const;
    bool isParal() const;
    bool isSquare () const;
};

bool Quad::isParal() const {
    if (a == c && b == d)
        return true;
    return false;
}

bool Quad::isSquare() const {
    if (a == b && b == c && c == d)
        return true;
    return false;
}

Quad::Quad(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {

}

void Quad::print() const {
    cout << "Square: " <<a << ' ' << b << ' ' << c << ' ' << d << endl;
}

class Paral : public Quad {
public:
    Paral(int=0, int=0, int=0, int=0);
    void virtual print() const;
};

Paral::Paral(int a_, int b_, int c_, int d_) : Quad(a_, b_, c_, d_) {
}

void Paral::print() const {
    cout << "Parallelogram: " << a << ' ' << b << ' ' << endl;
}

class Square : public Paral {
public:
    Square(int=0, int=0, int=0, int=0);
    void virtual print() const;
};

Square::Square(int a_, int b_, int c_, int d_) : Paral(a_, b_, c_, d_) {
}

void Square::print() const {
    cout << "Square: " << a << endl;
}


int main() {
    int n;
    cin >> n;
    Quad **ptr = new Quad*[n];
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Quad tmp(a, b, c, d);
        if (tmp.isSquare()) {
            ptr[i] = new Square(a, b, c, d);
        } else {
            if (tmp.isParal()) {
                ptr[i] = new Paral(a, b, c, d);
            } else {
                ptr[i] = new Quad(a, b, c, d);
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        ptr[i] -> print();
        delete ptr[i];
    }
    delete[] ptr;
}
