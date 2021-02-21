#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Good {
    const int id;
    const string name;
    const int price;
    int number;
    static int counter;
    friend class Catalog;
public:
    void print();
    Good(string & name, int & price, int & number);
};

int Good::counter = 0;

Good::Good(string & name, int & price, int & number) : id(counter++), name(name),
price(price), number(number){

}

void Good::print() {
    cout << setw(2) << id << setw(8) << name << setw(8) << price
        << setw(8) << number << endl;
}

class Catalog {
    int numberOfGoods;
    Good ** list;
public:
    Catalog(int & n);
    ~Catalog();
    void add(string & name, int & price, int & number);
    void buy(string & name, int & number);
    void buy(int & id, int & number);
    void print() const;
};

Catalog::Catalog(int & n) {
    numberOfGoods = 0;
    list = new Good*[n];
}

void Catalog::add(string & name, int & price, int & number) {
    list[numberOfGoods++] = new Good(name, price, number);
}

Catalog::~Catalog() {
    for (int i = 0; i < numberOfGoods; i++)
        delete list[i];
    delete[] list;
}

void Catalog::buy(string & name, int & number) {
    for (int i = 0; i < numberOfGoods; i++) {
        if (list[i]->name == name) {
            cout << list[i]->name << " x " << number << " = ";
            if (list[i]->number >= number) {
                list[i]->number -= number;
                cout << list[i]->price * number << endl;
                return;
            } else {
                cout << "not enough" << endl;
                return;
            }
        }
    }
    cout << name << " = incorrect name" << endl;
}

void Catalog::buy(int & id, int & number) {
    for (int i = 0; i < numberOfGoods; i++) {
        if (list[i]->id == id) {
            cout << list[i]->name << " x " << number << " = ";
            if (list[i]->number >= number) {
                list[i]->number -= number;
                cout << list[i]->price * number << endl;
                return;
            } else {
                cout << "not enough" << endl;
                return;
            }
        }
    }
    cout << id << " = incorrect index" << endl;
}

void Catalog::print() const{
    cout << setw(2) << "#" << setw(8) << "name" << setw(8)
        << "price" << setw(8) << "number" << endl;
    for (int i = 0; i < numberOfGoods; i++) {
        list[i]->print();
    }
}

int main() {
    int n;
    cin >> n;
    Catalog catalog(n);
    for (int i = 0; i < n; i++) {
        string plus, name;
        int number, price;
        cin >> plus >> name >> price >> number;
        catalog.add(name, price, number);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string action;
        cin >> action;
        if (action == "#") {
            int id, number;
            cin >> id >> number;
            catalog.buy(id, number);
            continue;
        }
        if (action == "?") {
            string name; 
            int number;
            cin >> name >> number;
            catalog.buy(name, number);
        }
    }
    catalog.print();
}
