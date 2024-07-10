#include <iostream>
#include <string>

using namespace std;

class Person {
    string name, surname;
    string phone_number;
public:
    Person(string n, string s, string sp) {
        name = n;
        surname = s;
        phone_number = sp;
    }

    string getName() {
        return name;
    }
    string getSurname() {
        return surname;
    }

    string getPhone() {
        return phone_number;
    }

    void setName(string n) {
        name = n;
    }

    void setSurname(string s) {
        surname = s;
    }

    void setPhone(string pn) {
        phone_number = pn;
    }
};