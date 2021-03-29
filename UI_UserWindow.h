#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QString>
#include <QLabel>
#include "ClientController.h"
#include "BookRepo.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <QFont>

typedef enum {
    bookList,
    TLList
}ListType;

class QPushButton;
class UserWindow : public QWidget
{
    Q_OBJECT

 public:
  explicit UserWindow(QWidget *parent = 0, ClientController* controller = nullptr);
 private:
    ClientController* Controller;

 int bookNo = -1;
 QLabel* label_view_by_genre;
 QLabel* label_genres;
 QLabel* label_title;
 QLabel* label_author;
 QLabel* label_genre;
 QLabel* label_description;
 QLabel* label_publication_year;
 QLabel* label_cover;
 QLabel* label_book_title;
 QLabel* label_book_author;
 QLabel* label_book_genre;
 QLabel* label_book_description;
 QLabel* label_book_publication_year;
 QLabel* label_book_cover;


 QPushButton* button_view_tolisten;
 QPushButton* button_view;
 QPushButton* button_modify;
 QPushButton* button_next;

 QLineEdit* field_genre;

 void displayBook(int index, ListType type);

private slots:
 void slotHandleView();
 void slotHandleModify();
 void slotHandleNext();




};


#endif // UI_USERWINDOW_H
