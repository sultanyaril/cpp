#include <iostream>
using namespace std;

class Computer {
    int clockRate;
    int RAM;
public:
    virtual ~Computer() = default;  // wtf it works??
    void virtual print();
    Computer(int, int);
    int getClockRate() const;
    int getRAM() const;
};

Computer::Computer(int cR_, int RAM_) : clockRate(cR_), RAM(RAM_) {
}

void Computer::print() {
     cout << "Computer " << clockRate << " GHz " << RAM
        << " Mb " << endl; 
}

int Computer::getClockRate() const {
    return clockRate;
}

int Computer::getRAM() const {
    return RAM;
}

class Notebook : public Computer {
    int Batery;
    string Vendor;
public:
    Notebook(int, int, int, string);
    void virtual print();
};

Notebook::Notebook (int cR_, int RAM_, int Batery_, string Vendor_) : Computer(cR_, RAM_) {
    Batery = Batery_;
    Vendor = Vendor_;
}

void Notebook::print() {
    cout << "Notebook " << getClockRate() << " GHz " << getRAM()
        << " Mb " << Batery << " hour " << Vendor << endl;
}

class Monoblock : public Computer {
    int Display;
public:
    Monoblock(int, int, int);
    void virtual print();
};

Monoblock::Monoblock (int cR_, int RAM_, int Display_) : Computer(cR_, RAM_){
    Display = Display_;
}

void Monoblock::print() {
    cout << "Monoblock " << getClockRate() << " GHz " << getRAM()
        << " Mb " << Display << "\"" << endl;
}

int main() {
    int n;
    cin >> n;
    Computer **list = new Computer*[n];
    for (int i = 0; i < n; i++) {
        string type;
        cin >> type;
        if (type == "N") {
            int clockRate, RAM, Batery;
            string Vendor;
            cin >> clockRate >> RAM >> Batery >> Vendor;
            list[i] = new Notebook(clockRate, RAM, Batery, Vendor);
            continue;
        }
        if (type == "?") {
            int clockRate, RAM;
            cin >> clockRate >> RAM;
            list[i] = new Computer(clockRate, RAM);
            continue;
        }
        if (type == "M") {
            int clockRate, RAM, Display;
            cin >> clockRate >> RAM >> Display;
            list[i] = new Monoblock(clockRate, RAM, Display);
            continue;
        }
    }
    
    cout << endl;

    int indexOfCr = 0, indexOfRAM = 0;
    for (int i = 1; i < n; i++) {
        if ((list[i]->getClockRate()) > (list[indexOfCr]->getClockRate()))
            indexOfCr = i;
        if (list[i]->getRAM() > list[indexOfRAM]->getRAM())
            indexOfRAM = i;
    }
    
    cout << "Maximum clockRate:" << endl;

    for (int i = indexOfCr; i < n; i++) {
        if (list[i]->getClockRate() == list[indexOfCr]->getClockRate())
            list[i]->print();
    }
    
    cout << endl << "Maximum RAM: "  << endl;

    for (int i = indexOfRAM; i < n; i++) {
        if (list[i]->getRAM() == list[indexOfRAM]->getRAM())
            list[i]->print();
    }

    for (int i = 0; i < n; i++)
        delete list[i];
    delete[] list;

    return 0;
}
