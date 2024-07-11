#include <iostream>
#include <fstream>
#include <string>
#include "Library.h"

using namespace std;

void Library::Display_menu() {
    cout << "Library Management System" << endl;
    cout << "1. Add book:" << endl;
    cout << "2. Delete book:" << endl;
    cout << "3. Edit book:" << endl;
    cout << "4. Find book by genre:" << endl;
    cout << "5. Find book by name:" << endl;
    cout << "6. Display all books:" << endl;
    cout << "7. Reserve book:" << endl;
    cout << "8. Cancel reservation:" << endl;
    cout << "9. Display all reserved books:" << endl;
    cout << "10. Exit" << endl;


    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        Add_book();
        save_to_file();
        break;
    case 2:
        Delete_book();
        save_to_file();
        break;
    case 3:
        Edit_book();
        save_to_file();
        break;
    case 4:
        Find_book_by_genre();
        break;
    case 5:
        Find_book_by_name();
        break;
    case 6:
        Display_books();
        break;
    case 7:
        Reserve_book();
        save_to_file();
        write_reservations();
        break;
    case 8:
        Cancel_reservation();
        save_to_file();
        write_reservations();
        break;
    case 9:
        Display_reserved_books();
        break;
    case 10:
        exit(0);
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}


void Library::read_from_file() {
    ifstream file(filename);
    if (file.is_open()) {
        string nb, na, g;
        int y, np;
        bool r;
        while (getline(file, nb)) {
            getline(file, na);
            getline(file, g);
            file >> y;
            file.ignore();
            file >> np;
            file.ignore();
            file >> r;
            file.ignore();

            Book** temp = new Book * [capacity + 1];
            for (int i = 0; i < capacity; ++i) {
                temp[i] = books[i];
            }
            temp[capacity] = new Book(nb, na, g, y, np, r);
            delete[] books;
            books = temp;
            capacity++;
        }
        file.close();
    }
    else {
        cout << "Error: Could not open the file " << filename << endl;
    }
}

void Library::save_to_file() {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < capacity; ++i) {
            file << books[i]->getName() << endl;
            file << books[i]->getAuthor() << endl;
            file << books[i]->getGenre() << endl;
            file << books[i]->getYear() << endl;
            file << books[i]->getNumberOfPages() << endl;
            file << books[i]->getReserved() << endl;

        }
        file.close();
    }
    else {
        cout << "Error: Could not open the file!" << endl;
    }
}
void Library::Display_books() {
    if (capacity == 0) {
        cout << "No books available in the library." << endl;
        return;
    }

    for (int i = 0; i < capacity; ++i) {
        books[i]->Display();
        cout << "---------------------------" << endl;
    }
}

void Library::Add_book() {
    Book* newBook = new Book();
    newBook->Add();
    Book** temp = new Book * [capacity + 1];
    for (int i = 0; i < capacity; ++i) {
        temp[i] = books[i];
    }
    temp[capacity] = newBook;
    delete[] books;
    books = temp;
    capacity++;
}

void Library::Delete_book() {
    cout << "Enter the name of the book to delete: ";
    string name;
    cin.ignore();
    getline(cin, name);
    for (int i = 0; i < capacity; ++i) {
        if (books[i]->getName() == name) {
            delete books[i];
            for (int j = i; j < capacity - 1; ++j) {
                books[j] = books[j + 1];
            }
            capacity--;
            break;
        }
    }
}

void Library::Edit_book() {
    cout << "Enter the name of the book to edit: ";
    string name;
    cin.ignore();
    getline(cin, name);
    for (int i = 0; i < capacity; ++i) {
        if (books[i]->getName() == name) {
            books[i]->Change();
            break;
        }
    }
}

void Library::Find_book_by_name() {
    cout << "Enter the name of the book to find: ";
    string name;
    cin.ignore();
    getline(cin, name);
    for (int i = 0; i < capacity; ++i) {
        if (books[i]->getName() == name) {
            books[i]->Display();
            break;
        }
    }
}

void Library::Find_book_by_genre() {
    cout << "Enter the genre of the book to find: ";
    string genre;
    cin.ignore();
    getline(cin, genre);
    for (int i = 0; i < capacity; ++i) {
        if (books[i]->getGenre() == genre) {
            books[i]->Display();
            break;
        }
    }
}

void Library::read_reservations() {
    ifstream res_file("person_reservation.txt");
    if (res_file.is_open()) {
        string book, name, surname, phone, status;
        while (getline(res_file, book)) {
            getline(res_file, name);
            getline(res_file, surname);
            getline(res_file, phone);
            getline(res_file, status);
            Reservation* temp = new Reservation[res_count + 1];
            for (int i = 0; i < res_count; ++i) {
                temp[i] = reservations[i];
            }
            temp[res_count] = Reservation(Person(name, surname, phone), book, status == "Active");
            delete[] reservations;
            reservations = temp;
            res_count++;
        }
        res_file.close();
    }
}


void Library::write_reservations() {
    ofstream res_file("person_reservation.txt", ios::app); // Otwórz plik w trybie dodawania

    if (res_file.is_open()) {
        for (int i = 0; i < res_count; ++i) {
            res_file << reservations[i].bookName << endl;
            res_file << reservations[i].person.getName() << endl;
            res_file << reservations[i].person.getSurname() << endl;
            res_file << reservations[i].person.getPhone() << endl;
            res_file << reservations[i].status << endl;
        }
        res_file.close();
    }
}

void Library::Reserve_book() {
    cout << "Enter the name of the book to reserve: ";
    string book;
    cin.ignore();
    getline(cin, book);
    for (int i = 0; i < capacity; ++i) {
        if (books[i]->getName() == book) {
            if (books[i]->getReserved()) {
                cout << "Book is already reserved." << endl;
                return;
            }

            string name, surname, phone;
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter your surname: ";
            getline(cin, surname);
            cout << "Enter your phone number: ";
            getline(cin, phone);

            Person person(name, surname, phone);
            books[i]->setReserved(true);
            Reservation reservation(person, book);

            Reservation* temp = new Reservation[res_count + 1];
            for (int i = 0; i < res_count; ++i) {
                temp[i] = reservations[i];
            }
            temp[res_count] = reservation;
            delete[] reservations;
            reservations = temp;
            res_count++;

            cout << "Reservation made for book: " << book << endl;
            break;
        }
    }
}

void Library::Cancel_reservation() {
    cout << "Enter the name of the book to cancel reservation: ";
    string book;
    cin.ignore();
    getline(cin, book);
    for (int i = 0; i < capacity; ++i) {
        if (books[i]->getName() == book) {
            if (!books[i]->getReserved()) {
                cout << "Book is not reserved." << endl;
                return;
            }
            books[i]->setReserved(false);
            cout << "Reservation canceled for: " << books[i]->getName() << endl;

            for (int i = 0; i < res_count; ++i) {
                if (reservations[i].bookName == book && reservations[i].status == "Active") {
                    reservations[i].status = "Cancelled";
                    break;
                }
            }
            break;
        }
    }
}


void Library::Display_reserved_books() {
    for (int i = 0; i < capacity; ++i) {
        if (books[i]->getReserved()) {
            books[i]->Display();
            for (int j = 0; j < res_count; ++j) {
                if (reservations[j].bookName == books[i]->getName() && reservations[j].status == "Active") {
                    cout << "Reserved by: " << reservations[j].person.getName() << " " << reservations[j].person.getSurname() << endl;
                    cout << "Phone number: " << reservations[j].person.getPhone() << endl;
                    break;
                }
            }
            cout << "---------------------------" << endl;
        }
    }
}