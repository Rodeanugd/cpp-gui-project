#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H
#include "BookRepo.h"
#include "Book.h"
#include "PersistenceEngine.h"
#include "PersistenceEngineFromCsv.h"
#include "PersistenceEngineFromJson.h"
#include <vector>
#include <string>
#include <stack>

struct operation{
   int type;
   int position;
   Book* book;
   Book* former;
};

class ClientController{
private:
    std::stack<operation> undoStack;
    std::stack<operation> redoStack;

public:
    BookRepo repo;
    BookRepo toListen;

    ClientController();
    ClientController(BookRepo repo, BookRepo toListen);
    ~ClientController();

    void LoadBooks();

    /*
    D: Adds a book to the repo repository
    I: A pointer to the book to be added
    O: True if the book was added succesfully, false if the book was already in the repository
    */
    bool addBook(Book* book);

    /*
    D: Adds a book to the toListen repository
    I: A pointer to the book to be added
    O: True if the book was added succesfully, false if the book was already in the repository
    */
    bool addBookTL(Book* book);

    /*
    D: Removes a book from the repo repository
    I: The index of the book to be removed
    O: True if the book was removed succesfully, false if the book was not in the repository
    */
    bool removeBook(int index);

    /*
    D: Removes a book from the toListen repository
    I: The index of the book to be removed
    O: True if the book was removed succesfully, false if the book was not in the repository
    */
    bool removeBookTL(int index);

    /*
    D: Updates a book from the repo repository
    I: The index of the book to be updated, a book object with the updated values
    O: True if the book was updated succesfully, false if the book was not in the repository
    */
    bool updateBook(int index, Book* book);

    /*
    D: Gives a string representation of the object found at a certain index in the repo repository
    I: A string display and an integer index
    O: The formatted text stored in the string display; Returns false if the index is out of bounds, true otherwise
    */
    bool displayBook(std::string* display ,int index);

    /*
    D: Gives a string representation of the object found at a certain index in the repo toListen
    I: A string display and an integer index
    O: The formatted text stored in the string display; Returns false if the index is out of bounds, true otherwise
    */
    bool displayBookTL(std::string* display, int index);

    /*
    D:
    I:
    O:
    */
    bool load(std::string filepath);

    /*
    D:
    I:
    O:
    */
    bool save(std::string filepath);

    bool undo();

    bool redo();

    //void displayBooksByGenre(int genre);
    //void displayBooksInToListen();

};


#endif // CLIENTCONTROLLER_H
