#include <iostream>
using namespace std;
class Complex;
class Rational;


class Pair {
protected:
    int a, b;
public:
    Pair(int = 0, int = 1);
    virtual void print();
};

class Complex : public Pair {
public:
    Complex(int = 0, int = 1);
    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
    Complex operator*(const Complex &);
    virtual void print();
};

class Rational : public Pair {
    void simplify();
public:
    Rational(int = 0, int = 1);
    Rational operator+(const Rational &);
    Rational operator-(const Rational &);
    Rational operator*(const Rational &);
    virtual void print();
};


Complex::Complex(int a_, int b_) : Pair(a_, b_) {
}

Complex Complex::operator+(const Complex & number) {
    return Complex(a + number.a, b + number.b);
}

Complex Complex::operator-(const Complex & number) {
    return Complex(a - number.a, b - number.b);
}

Complex Complex::operator*(const Complex & number) {
    return Complex(a * number.a - b * number.b, a * number.b + b * number.a);
}

void Complex::print() {
    cout << a << "+" << b << "i" << endl;
}

Rational::Rational(int a_, int b_) : Pair(a_, b_) {
}

Rational Rational::operator*(const Rational & number) {
    Rational answ = Rational(a * number.a, b * number.b);
    answ.simplify();
    return answ;
}

Rational Rational::operator+(const Rational & number) {
    Rational answ = Rational(a * number.b + b * number.a, b * number.b);
    answ.simplify();
    return answ;
}

Rational Rational::operator-(const Rational & number) {
    Rational answ = Rational(a * number.b - b * number.a, b * number.b);
    answ.simplify();
    return answ;
}

void Rational::simplify() {
    int copy_a = a, copy_b = b;
    while (copy_b) {
        copy_a %= copy_b;
        int tmp = copy_a;
        copy_a = copy_b;
        copy_b = tmp;
    }
    a /= copy_a;
    b /= copy_a;
}

void Rational::print() {
    cout << a << "/" << b << endl;
}

Pair::Pair(int a_, int b_) : a(a_), b(b_) {
}

void Pair::print() {
}

int main() {
    Complex c;
    Rational r;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int which_one;
        char operation;
        int a, b;
        cin >> which_one >> operation >> a >> b;
        if (which_one == 1) {
            if (operation == '+') {
                r = r + Rational(a, b);
                r.print();
                continue;
            }
            if (operation == '-') {
                r = r - Rational(a, b);
                r.print();
                continue;
            }
            if (operation == '*') {
                r = r * Rational(a, b);
                r.print();
                continue;
            }
            continue;
        }
        if (which_one == 2) {
            if (operation == '+') {
                c = c + Complex(a, b);
                c.print();
                continue;
            }
            if (operation == '-') {
                c = c - Complex(a, b);
                c.print();
                continue;
            }
            if (operation == '*') {
                c = c * Complex(a, b);
                c.print();
                continue;
            }
            continue;
        }

    }

}
