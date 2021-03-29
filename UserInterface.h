#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#pragma once
#include "ClientController.h"
#include "BookRepo.h"
#include "Book.h"
#include <iostream>
#include <string>

typedef enum {
    bookList,
    TLList
}ListType;



class UserInterface{
private:
    ClientController ClientController;
public:

    UserInterface();
    ~UserInterface();


    /*


    */
    void uiStart();

    /*
    D: Adds a book to the controller's repo repository
    I: A pointer to the book to be added
    O: A message stating if the operation was succesful or not
    */
    void uiAddBook(Book* book);

    /*
    D: Removes a book from the controller's repo repository
    I: The index of the book to be removed
    O: A message stating if the operation was succesful or not
    */
    void uiRemoveBook(int index);

    /*
    D: Adds a book to the controller's toListen repository
    I: A pointer to the book to be added
    O: A message stating if the operation was succesful or not
    */
    void uiAddBookTL(Book* book);

    /*
    D: Removes a book from the controller's toListen repository
    I: The index of the book to be removed
    O: A message stating if the operation was succesful or not
    */
    void uiRemoveBookTL(int index);

    /*



    */
    void uiAdminAddBook();

    /*



    */
    void uiAdminRemoveBook();

    /*



    */
    void uiAdminUpdateBook();





    /*
    D: Displays a menu that lets the user choose which mode he wants to start the application in
    I: A character representing the user's choice of action
    O: Displays the two operaiton modes
    */
    void uiSetMode();

    /*
    D: Prints the client's options
    I: -
    O: Prints the client's options
    */
    void uiPrintClientMenu();

    /*
    D: Prints the admin's options
    I: -
    O: Prints the admin's options
    */
    void uiPrintAdminMenu();

    /*
    D: Prints the client's options and checks for the user's input
    I: A character representing the user's choice of action
    O: Prints the client's options via uiPrintClientMenu()
    */
    void uiDisplayClientUI();

    /*
    D: Prints the admin's options and checks for the user's input
    I: A character representing the user's choice of action
    O: Prints the admin's options via uiPrintAdminMenu()
    */
    void uiDisplayAdminUI();

    /*
    D: Displays the book at the index 'index' from the list 'type' and lets the user add/remove it from his toListen list
    I: A character representing the user's choice of action
    O: Displays the book at the index 'index' from the list 'type'
    */
    bool uiDisplayBook(int index, ListType type);

    /*
    D: Displays the books from the controller's repo repository filtered by the client's choice of genre
    I: A string representing the client's choice of genre
    O: Displays the books from the controller's repo repository filtered by the client's choice of genre
    */
    void uiDisplayBooksByGenre();

    /*



    */
    void uiDisplayBooksAdmin();

    /*
    D: Displays the books from the controller's toListen repository
    I: -
    O: Displays the books from the controller's toListen repository
    */
    void uiDisplayBooksTL();


};


#endif // USERINTERFACE_H
