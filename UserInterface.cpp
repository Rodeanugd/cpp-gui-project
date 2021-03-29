#include "UserInterface.h"
#include <iostream>
#include <string>


UserInterface::UserInterface() {

}

UserInterface::~UserInterface() {

}

void UserInterface::uiStart() {
    this->uiSetMode();
}

void UserInterface::uiSetMode() {
    char op;
    std::cout << "Please select an option:" << '\n' << "a - start the application in administrator mode" << '\n' << "u - start the application in user mode" << '\n';
    while (true) {
        std::cin >> op;
        if (op == 'a')
            this->uiDisplayAdminUI();
        else if (op == 'u')
            this->uiDisplayClientUI();
    }
}
void UserInterface::uiAddBook(Book* book) {
    if (!this->ClientController.addBook(book))
        std::cout << "This book is already in the list";
}
void UserInterface::uiRemoveBook(int index) {
    if (!this->ClientController.removeBook(index))
        std::cout << "This book is not in the list";
}

void UserInterface::uiAddBookTL(Book* book) {
    if (!this->ClientController.addBookTL(book))
        std::cout << "This book is already in the list";
}
void UserInterface::uiRemoveBookTL(int index) {
    if (!this->ClientController.removeBookTL(index))
        std::cout << "This book is not in the list";
}

void UserInterface::uiAdminAddBook() {
    std::string title;
    std::string author;
    Genre genre;
    std::string description;
    int publicationYear;
    std::string cover;
    int g;


    std::cout << "Book title:"<<'\n';
    std::cin >> title;
    std::cout << "Book author:" << '\n';
    std::cin >> author;
    std::cout << "Book genre:" << '\n';
    std::cout << "1.nonfiction" << '\n' << "2.fantasy" << '\n' << "3.thriller" << '\n' << "4.drama" << '\n' << "5.other" << '\n';
    std::cin >> g;
    genre = static_cast<Genre>(g);
    std::cout << "Book description:" << '\n';
    std::cin >> description;
    std::cout << "Book publication year:" << '\n';
    std::cin >> publicationYear;
    std::cout << "Book cover:" << '\n';
    std::cin >> cover;

    Book *book = &Book(title, author, genre, description, publicationYear, cover);

    if (!this->ClientController.addBook(book)) {
        system("@cls||clear");
        std::cout << '\n' << "Incorrect Data!" << '\n';
    }
    else
        std::cout << "Operation completed succesfully!" << '\n';

}
void UserInterface::uiAdminRemoveBook() {
    int index;
    std::cout << "Please give the index of the book you want to remove: ";
    std::cin >> index;
    if (!this->ClientController.removeBook(index-1))
        std::cout << '\n' << "Operation failed!" << '\n';
    else
        std::cout << '\n' << "Operation succesful!" << '\n';
}
void UserInterface::uiAdminUpdateBook() {
    int index;
    std::string title;
    std::string author;
    Genre genre;
    std::string description;
    int publicationYear;
    std::string cover;
    int g;
    std::cout << "Please give the index of the book you want to update: ";
    std::cin >> index;
    std::cout << "Book title:" << '\n';
    std::cin >> title;
    std::cout << "Book author:" << '\n';
    std::cin >> author;
    std::cout << "Book genre:" << '\n';
    std::cout << "1.nonfiction" << '\n' << "2.fantasy" << '\n' << "3.thriller" << '\n' << "4.drama" << '\n' << "5.other" << '\n';
    std::cin >> g;
    genre = static_cast<Genre>(g);
    std::cout << "Book description:" << '\n';
    std::cin >> description;
    std::cout << "Book publication year:" << '\n';
    std::cin >> publicationYear;
    std::cout << "Book cover:" << '\n';
    std::cin >> cover;

    Book* book = &Book(title, author, genre, description, publicationYear, cover);
    if (!this->ClientController.updateBook(index-1, book))
        std::cout << "Operation failed!" << '\n';
    else
        std::cout << "Operation succesful!" << '\n';
}


void UserInterface::uiPrintClientMenu() {
    std::cout << "Please select an option: " << '\n' << "g - view books by genre" << '\n' << "l - view 'to listen' list"<<'\n'<<"e - exit" << '\n';
}

void UserInterface::uiPrintAdminMenu() {
    this->uiDisplayBooksAdmin();
    std::cout<< '\n' << "Please select an option: " << '\n' << "a - add a book" << '\n' << "r - remove a book" << '\n' << "u - update a book" << '\n' << "e - exit" << '\n';
}


bool UserInterface::uiDisplayBook(int index, ListType type) {
    bool added = 0;
    char op;
    std::string display;
    if (type == bookList)
        this->ClientController.displayBook(&display, index);
    else {
        this->ClientController.displayBookTL(&display, index);
        added = 1;
    }


    while (true) {
        system("@cls||clear");
        std::cout << display;
        if (!added) {
            std::cout << "Press A to add this book to your 'to listen' list" << '\n';
        }
        else {
            std::cout << "Press A to remove this book from your 'to listen' list" << '\n';
        }
        std::cout << "Press N to view the next book" << '\n';
        std::cin >> op;
        switch (op) {
        case 'a':
            added = !added;
            break;
        case 'n':
            break;
        default:
            std::cout << "Unknown option" << '\n';
            continue;
        }
        if (op == 'n')
            break;
    }
    if (type == bookList) {
        if (added) {
            this->uiAddBookTL(this->ClientController.repo.vector.at(index));
            return 1;
        }
        return 0;
    }
    else {
        if (!added) {
            this->uiRemoveBookTL(index);
            return 1;
        }
        return 0;
    }

}


void UserInterface::uiDisplayBooksAdmin() {
    int unsigned iterator = 0;
    std::string display;
    while (iterator < this->ClientController.repo.vector.size()) {
        this->ClientController.repo.vector.at(iterator)->toString(&display);
        std::cout << iterator + 1 << "." << display << '\n';
        iterator++;
    }

}

void UserInterface::uiDisplayBooksByGenre() {
    int gnr = 0;
    std::string genre;
    std::cout << "What genre of books would you like to see?" << '\n' << "1.nonfiction" << '\n' << "2.fantasy" << '\n' << "3.thriller" << '\n' << "4.drama" << '\n' << "5.other" << '\n';
    //std::getline(std::cin, genre);
    std::cin >> genre;
    char genreToString[7][25]{
    "nonfiction",
    "fantasy",
    "thriller",
    "drama",
    "other",
    "UNK"
    };

    for (gnr = 0; gnr < 6; gnr++)
        if (genre == genreToString[gnr])
            break;

    if (genre.empty())
        gnr = -1;


    int unsigned iterator = 0;
    while (iterator < this->ClientController.repo.vector.size()) {
        int i = (int)this->ClientController.repo.vector.at(iterator)->getGenre();
        if (genre == genreToString[i])
            uiDisplayBook(iterator, bookList);
        iterator++;
    }

}

void UserInterface::uiDisplayBooksTL() {
    int unsigned iterator = 0;
    while (iterator < this->ClientController.toListen.vector.size()) {
        int size = this->ClientController.toListen.vector.size();
        uiDisplayBook(iterator, TLList);
        iterator -= size - this->ClientController.toListen.vector.size();
        iterator++;
    }

}



void UserInterface::uiDisplayClientUI() {

    this->ClientController.LoadBooks();

    char op;
    while (true) {
        system("@cls||clear");
        this->uiPrintClientMenu();
        std::cin >> op;
        switch (op) {
        case 'g':
            this->uiDisplayBooksByGenre();
            break;

        case 'l':
            this->uiDisplayBooksTL();
            break;

        case 'e':
            exit(0);

        default:
            std::cout << "Unknown option" << '\n';
            continue;
        }
    }
}

void UserInterface::uiDisplayAdminUI() {

    this->ClientController.LoadBooks();



    char op;
    while (true) {
        system("@cls||clear");
        this->uiPrintAdminMenu();
        std::cin >> op;
        switch (op) {
        case 'a':
            this->uiAdminAddBook();
            break;

        case 'r':
            this->uiAdminRemoveBook();
            break;

        case 'u':
            this->uiAdminUpdateBook();
            break;

        case 'e':
            exit(0);

        default:
            std::cout << "Unknown option" << '\n';
            continue;
        }
    }
}
