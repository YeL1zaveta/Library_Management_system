#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Reservation {
public:
    Person person;
    string bookName;
    string status;

    Reservation(const Person& p, const string& bn = "", bool st = true) : person(p), bookName(bn) {
        status = st ? "Active" : "Cancelled";
    }

    Reservation() : person(Person("", "", "")), bookName(""), status("Active") {}

    void Display() {
        cout << "Reservation for book: " << bookName << endl;
        cout << "Reserved by: " << person.getName() << " " << person.getSurname() << endl;
        cout << "Phone number: " << person.getPhone() << endl;
        cout << "Status: " << status << endl;
    }
};