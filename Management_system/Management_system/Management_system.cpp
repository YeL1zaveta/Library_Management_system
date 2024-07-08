#include <iostream>
#include <fstream>
#include <string>
#include "Library.h"

int main() {
    Library library("book.txt");
    while (true) {
        library.Display_menu();
    }
    return 0;
}