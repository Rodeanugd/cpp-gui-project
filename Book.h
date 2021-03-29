#ifndef BOOK_H
#define BOOK_H

#include <string>

typedef enum {
    nonfiction,
    fantasy,
    thriller,
    drama,
    other,
    UNK
} Genre;

class Book{
private:
    std::string title;
    std::string author;
    Genre genre;
    std::string description;
    int publicationYear;
    std::string cover;

public:

    Book(std::string title, std::string author, Genre genre, std::string description, int publicationYear, std::string cover);
    Book();
    ~Book();

    bool operator==(const Book& other);



    std::string getTitle();
    std::string getAuthor();
    int getGenre();
    std::string getDescription();
    int getPublicationYear();
    std::string getCover();

    /*
    D: Gives a string representation of the object
    I: A string str
    O: The formatted text stored in the string str
    */
    void toString(std::string* str);
};

#endif // BOOK_H
