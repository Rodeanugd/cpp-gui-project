#ifndef BOOKREPO_H
#define BOOKREPO_H
#include "Book.h"
#include <vector>
#include <string>
class BookRepo{
public:
    std::vector<Book*> vector;

    BookRepo(std::vector<Book*> vector);
    BookRepo();
    ~BookRepo();




    /*
    D: Gives a string representation of the object found at a certain index in the list
    I: A string display and an integer index
    O: The formatted text stored in the string display; Returns false if the index is out of bounds, true otherwise
    */
    bool displayBook(std::string* display,int index);

    /*
    D: Adds a book to the repository
    I: A pointer to the book to be added
    O: True if the book was added succesfully, false if the book was already in the repository
    */
    bool addBook(Book* book);

    /*
    D: Removes a book from the repository
    I: The index of the book to be removed
    O: True if the book was removed succesfully, false if the book was not in the repository
    */
    bool removeBook(int index);

    /*
    D: Updates a book from the repository
    I: The index of the book to be updated, a book object with the updated values
    O: True if the book was updated succesfully, false if the book was not in the repository
    */
    bool updateBook(int index, Book* book);

    /*
    D: Searches for a book in the repository
    I: A pointer to the book to be searched for
    O: The index of the book, or -1 if the book was not in the repository
    */
    int searchBook(Book* book);
};


#endif // BOOKREPO_H
