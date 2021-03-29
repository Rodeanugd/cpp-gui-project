#include "BookRepo.h"
#include <iostream>
#include <string>
BookRepo::BookRepo(std::vector<Book*> vector) {
    this->vector = vector;
}

BookRepo::BookRepo() {

}

BookRepo::~BookRepo() {

}

bool BookRepo::displayBook(std::string* display, int index) {
    if (index >= 0 && index < this->vector.size())
        this->vector.at(index)->toString(display);
    else
        return 0;
    return 1;
}

bool BookRepo::addBook(Book* book) {
    if (searchBook(book) == -1) {
        this->vector.push_back(book);
        //std::cout << "aaaaa";
        return 1;
    }
    else
        return 0;
}

bool BookRepo::removeBook(int index) {
    if (index >= 0 && index < this->vector.size()) {
        this->vector.erase(vector.begin() + index);
        return 1;
    }
    return 0;
}

bool BookRepo::updateBook(int index, Book* book) {
    if (index >= this->vector.size())
        return 0;
    this->vector.at(index) = book;
    return 1;
}

int BookRepo::searchBook(Book* book) {
    unsigned int i;
    for (i = 0; i < this->vector.size(); i++) {
        if (*book == *this->vector.at(i))
            return i;
    }
    return -1;

}
