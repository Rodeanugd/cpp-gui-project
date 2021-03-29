#include "Book.h"
#include <iostream>
#include <string>

Book::Book(std::string title, std::string author, Genre genre, std::string description, int publicationYear, std::string cover) {
    this->title = title;

    this->author.assign(author);

    this->genre = genre;

    this->description.assign(description);

    this->publicationYear = publicationYear;

    this->cover.assign(cover);

}

Book::Book() {
    this->title.assign("UNK");

    this->author.assign("UNK");

    this->genre = UNK;

    this->description.assign("UNK");

    this->publicationYear = 0;

    this->cover.assign("UNK");
}

Book::~Book() {

}


bool Book::operator==(const Book& other) {
    if (this->title == other.title)
        if (this->author == other.author)
            if (this->publicationYear == other.publicationYear)
                return true;
    return false;

}



void Book::toString(std::string* str) {
    std::string year;
    year = std::to_string(this->publicationYear);

    char genreToString[7][25]{
        "nonfiction",
        "fantasy",
        "thriller",
        "drama",
        "other",
        "UNK"
    };


    str->clear();
    //std::cout << this->title;
    //std::cout << this->getTitle();
    str->append("Title: ");
    str->append(this->title);
    //str->append(this->getTitle());
    //std::cout << this->getTitle();
    str->append("\n");
    str->append("Author: ");
    str->append(this->author);
    str->append("\n");
    str->append("Genre: ");
    str->append(genreToString[(int)this->genre]);
    str->append("\n");
    str->append("Description: ");
    str->append(this->description);
    str->append("\n");
    str->append("Publication year: ");
    str->append(year);
    str->append("\n");
    str->append("Cover: ");
    str->append(this->cover);
    str->append("\n");
}




std::string Book::getTitle() {
    return this->title;
}
std::string Book::getAuthor() {
    return this->author;
}
int Book::getGenre() {
    return this->genre;
}
std::string Book::getDescription() {
    return this->description;
}
int Book::getPublicationYear() {
    return this->publicationYear;
}
std::string Book::getCover() {
    return this->cover;
}
