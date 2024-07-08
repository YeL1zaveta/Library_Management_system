#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    string name_of_book, author, genre;
    int year, number_of_pages;
    bool reserved;

public:
    Book(string nb, string na, string g, int y, int np, bool r = false) {
        name_of_book = nb;
        author = na;
        genre = g;
        year = y;
        number_of_pages = np;
        reserved = r;
    }
    Book() : name_of_book(""), author(""), genre(""), year(0), number_of_pages(0), reserved(false) {} //default constructor 

    string getName() {
        return name_of_book;
    }
    string getAuthor() {
        return author;
    }

    string getGenre() {
        return genre;
    }

    int getYear() {
        return year;
    }

    int getNumberOfPages() {
        return number_of_pages;
    }

    void setReserved(bool r) {
        reserved = r;
    }

    int getReserved() {
        return reserved;
    }

    void Add();
    void Delete();
    void Change();
    void Display();
};