#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Contact {
    string name;  // имя человека
    int prefix;  // префикс номера 3 цифры
    int number;  // номер телефона 7 цифр
    int calls;  // кол-во звонков
public:
    Contact();  // конструктор
    void setContact(const string &newName, int newPrefix, int newNumber);
    bool nameLike(const string & partOfName);
    bool numberLike(int numberSuffix);
    int getCalls();
    void newCall();
    void print();
};

Contact::Contact() : name("\0"), prefix(0), number(0), calls(0) {
}

void Contact::setContact(const string &newName, int newPrefix, int newNumber) {
    name = newName;
    prefix = newPrefix;
    number = newNumber;
}

bool Contact::nameLike(const string & partOfName) {
    if (partOfName.length() > name.length())
        return false;
    if (name.substr(0, partOfName.length()) == partOfName) {
        return true;
    }
    return false;
}

bool Contact::numberLike(int endOfNumber) {
    for (int powerOfTen = 10; powerOfTen <= endOfNumber * 10; powerOfTen *= 10) {
        if (number % powerOfTen == endOfNumber) {
            return true;
        }
    }
    return false;
}

int Contact::getCalls() {
    return calls;
}

void Contact::newCall() {
    calls++;
}

void Contact::print() {
    cout << setw(12) << name 
    << "       " << setw(3) << setfill ('0') << prefix
    << "   " << setw(7) << number
    << setw(6) << setfill(' ') << calls << endl;
}


class PhoneBook{
    static int abonentNumber;  // кол-во записей
    Contact names[10];
    void printHeader();
public:
    PhoneBook();
    void addAbonent(const string & name, int pref, int number);
    void callAbonent(const string & prefixOfName);
    void callAbonent(int suffixOfNumber);
    void print();
    void printTheMostCommon();
};

int PhoneBook::abonentNumber = 0;

PhoneBook::PhoneBook() {

}

void PhoneBook::printHeader() {
    cout << setw(12) <<"Name" << setw(10) << "Prefix" << setw(10)
            << "Number" << setw(6) << "Calls" << endl;
}


void PhoneBook::addAbonent(const string & name, int pref, int number){
    if ((name.length() > 10) or (pref / 1000 != 0) or
            (number / 10000000 != 0) or (abonentNumber == 10)) {
        cout << "FAIL:incorrect name of number format" << endl;
        return;
    }
    names[abonentNumber].setContact(name, pref, number);
    abonentNumber++;
    cout << "ADD: name phone" << endl;
}

void PhoneBook::callAbonent(const string & prefixOfName) {
    int numberOfResults = 0, idOfFirst = -1;
    for (int i = 0; i < abonentNumber; i++) {
        if (names[i].nameLike(prefixOfName)) {
            numberOfResults++;
            names[i].print();
            if (idOfFirst < 0)
                idOfFirst = i;
        }
    }
    if (numberOfResults > 1) {
        cout << "FAIL: choose unique" << endl;
        return;
    }
    if (numberOfResults == 0) {
        cout << "FAIL: no such abonent" << endl;
        return;
    }
    names[idOfFirst].newCall();
    cout << "CALL" << endl;
}

void PhoneBook::callAbonent(int suffixOfNumber) {
    if ((suffixOfNumber > 9999999) or (suffixOfNumber < 0))
        return;
    int numberOfResults = 0, idOfFirst = -1;
    for (int i = 0; i < abonentNumber; i++) {
        if (names[i].numberLike(suffixOfNumber)) {
            numberOfResults++;
            names[i].print();
            if (idOfFirst < 0)
                idOfFirst = i;
        }
    }
    if (numberOfResults > 1) {
        cout << "FAIL: choose unique" << endl;
        return;
    }
    if (numberOfResults == 0) {
        cout << "FAIL: no such abonent" << endl;
        return;
    }
    names[idOfFirst].newCall();
    cout << "CALL" << endl;
}

void PhoneBook::print() {
    printHeader();
    for (int i = 0; i < abonentNumber; i++) {
        names[i].print();
    }
}

void PhoneBook::printTheMostCommon() {
    printHeader();
    if (abonentNumber == 0) {
        cout << "FAIL: book is empty" << endl;
        return;
    }
    int idOfResult = 0;
    for (int i = 0; i < abonentNumber; i++) {
        if (names[i].getCalls() > names[idOfResult].getCalls())
            idOfResult = i;
    }
    for (int i = idOfResult; i < abonentNumber; i++) {
        if (names[idOfResult].getCalls() == names[i].getCalls())
            names[i].print();
    }
}

int main() {
    PhoneBook phonebook;
    while(1) {
        string action;
        cin >> action;
        if (action == "+") {
            string name;
            int pref, number;
            cin >> name >> pref >> number;
            phonebook.addAbonent(name, pref, number);
            continue;
        }
        if (action == "?") {
            phonebook.print();
            continue;
        }
        if (action == "#1") {
            string prefixOfName;
            cin >> prefixOfName;
            phonebook.callAbonent(prefixOfName);
            continue;
        }
        if (action == "#2") {
            int suffixOfNumber;
            cin >> suffixOfNumber;
            phonebook.callAbonent(suffixOfNumber);
            continue;
        }
        if (action == "*") {
            phonebook.printTheMostCommon();
            continue;
        }
        if (action == "-")
            break;
    }
    return 0;
}

