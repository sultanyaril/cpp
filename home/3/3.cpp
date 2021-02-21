#include <iostream>
#include <iomanip>
using namespace std;

class Weapon {
    enum type{
        ATTACK,
        PROTECTION,
        NONE
    } type;
    int value;
public:
    Weapon(const string & type = "NONE", const int & value = 0);
    bool operator>(const Weapon &) const;
    int getAttack() const;
    int getProtection() const;
};

class Hero {
    string name;
    int attack;
    int protection;
    Weapon weap;
public:
    Hero(const string & ="\0", const int=0, const int=0);
    void setHero(const string &, const int, const int);
    string getName() const;
    Weapon getWeapon() const;
    void setWeapon(Weapon &);
    bool operator>(const Hero &) const;
};

void Hero::setHero(const string & name_, const int attack_, const int protection_) {
    name = name_;
    attack = attack_;
    protection = protection_;
}

Hero::Hero(const string & name, const int attack, const int protect) : name(name),
    attack(attack), protection(protect), weap(Weapon()) {
}  // i spent 1 hour searching for a mistake, and figured out that i wrote "protection"
  // instead of "protect"
  // rip 13:00 - 14:00
void Hero::setWeapon(Weapon & w) {
    weap = w;
}

string Hero::getName() const{
    return name;
}

Weapon Hero::getWeapon() const{
    return weap;
}

bool Hero::operator>(const Hero & h) const{
    if ((attack + weap.getAttack()) > (h.protection + h.weap.getProtection()))
        return true;
    return false;
}

Weapon::Weapon(const string & type_, const int & value_) {
    if (type_ == "attack")
        Weapon::type = Weapon::ATTACK;
    else {
        if (type_ == "protect")
            Weapon::type = Weapon::PROTECTION;
        else
            Weapon::type = Weapon::NONE;
    }
    value = value_;
}

int Weapon::getAttack() const{
    if (type == Weapon::ATTACK)
        return value;
    return 0;
}

int Weapon::getProtection() const{
    if (type == Weapon::PROTECTION)
        return value;
    return 0;
}

bool Weapon::operator>(const Weapon & w) const{
    if (value > w.value)
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    Hero *heroes = new Hero[n];
    for(int i = 0; i < n; i++) {
        string name;
        int attack, protection;
        cin >> name >> attack >> protection;
        heroes[i].setHero(name, attack, protection);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int value;
        string type, name;
        cin >> value >> type >> name;
        Weapon w(type, value);
        for (int j = 0; j < n; j++) {
            if ((heroes[j].getName() == name) and (w > heroes[j].getWeapon())) {
                heroes[j].setWeapon(w);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i != j) and heroes[i] > heroes[j])
                cout << heroes[i].getName() << " win " << heroes[j].getName() << endl;
        }
    }

    delete[] heroes;
    return 0;
}
