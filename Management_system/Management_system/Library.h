#include <iostream>
#include <string>
#include "Book.h"
#include "Reservation.h"

using namespace std;

class Library {
private:
    Book** books;
    int capacity;
    string filename;
    Reservation* reservations;
    int res_count;

public:
    Library(const string& filename) : books(nullptr), capacity(0), filename(filename) {
        read_from_file();
    }
    ~Library() {
        for (int i = 0; i < capacity; ++i) {
            delete books[i];
        }
        delete[] books;
    }
    void Display_menu();
    void read_from_file();
    void Display_books();
    void Add_book();
    void Delete_book();
    void Edit_book();
    void Find_book_by_name();
    void Find_book_by_genre();
    void save_to_file();
    void Reserve_book();
    void Cancel_reservation();
    void Display_reserved_books();
    void read_reservations();
    void write_reservations();

};