#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

void Book::Add() {
    cout << "Enter book name: ";
    cin.ignore();
    getline(cin, name_of_book);
    cout << "Enter author name: ";
    getline(cin, author);
    cout << "Enter genre: ";
    getline(cin, genre);
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter number of pages: ";
    cin >> number_of_pages;
}

void Book::Delete() {
    name_of_book = "";
    author = "";
    genre = "";
    year = 0;
    number_of_pages = 0;
}

void Book::Change() {
    cout << "Enter new book name: ";
    cin.ignore();
    getline(cin, name_of_book);
    cout << "Enter new author name: ";
    getline(cin, author);
    cout << "Enter new genre: ";
    getline(cin, genre);
    cout << "Enter new year: ";
    cin >> year;
    cout << "Enter new n umber of pages: ";
    cin >> number_of_pages;
}

void Book::Display() {
    cout << "Book Name: " << name_of_book << endl;
    cout << "Author: " << author << endl;
    cout << "Genre: " << genre << endl;
    cout << "Year: " << year << endl;
    cout << "Number of Pages: " << number_of_pages << endl;
    cout << "Reserved: " << (reserved ? "Yes" : "No") << endl;

}
