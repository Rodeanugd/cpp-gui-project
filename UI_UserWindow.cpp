#include "UI_UserWindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <iostream>


UserWindow::UserWindow(QWidget *parent, ClientController* controller) :
 QWidget(parent)
 {
this->Controller = controller;
    //nullpointer exception?

 // Set size of the window
 setFixedSize(400, 500);

 // Buttons
 button_view_tolisten = new QPushButton("View 'to listen'", this);
 button_view_tolisten->setGeometry(100, 75, 200, 50);
 button_view_tolisten->setStyleSheet("QPushButton{font-size: 20px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 //button_view_tolisten->hide();

 button_view = new QPushButton("View books", this);
 button_view->setGeometry(100, 150, 200, 50);
 button_view->setStyleSheet("QPushButton{font-size: 20px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 //button_view->hide();

 field_genre = new QLineEdit("genre",this);
 field_genre->setGeometry(100, 225, 200, 37);
 field_genre->setStyleSheet("QLineEdit{font-size: 20px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 //field_genre->hide();

 label_genres = new QLabel("nonfiction \nfantasy \nthriller \ndrama \nother",this);
 label_genres->setGeometry(150,275,200,150);
 label_genres->setStyleSheet("QLabel{font-size: 20px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 label_genres->hide();

 label_title = new QLabel("Title:",this);
 label_title->setGeometry(15,25,200,50);
 label_title->setStyleSheet("QLabel{font-size: 24px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 label_title->hide();

 label_author = new QLabel("Author:",this);
 label_author->setGeometry(15,75,200,50);
 label_author->setStyleSheet("QLabel{font-size: 24px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 label_author->hide();

 label_genre = new QLabel("Genre:",this);
 label_genre->setGeometry(15,125,200,50);
 label_genre->setStyleSheet("QLabel{font-size: 24px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 label_genre->hide();

 label_publication_year = new QLabel("Publication Year:",this);
 label_publication_year->setGeometry(15,175,200,50);
 label_publication_year->setStyleSheet("QLabel{font-size: 24px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 label_publication_year->hide();

 label_description = new QLabel("Description:",this);
 label_description->setGeometry(15,225,200,50);
 label_description->setStyleSheet("QLabel{font-size: 24px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 label_description->hide();

 label_cover = new QLabel("Cover:",this);
 label_cover->setGeometry(15,350,200,50);
 label_cover->setStyleSheet("QLabel{font-size: 24px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 label_cover->hide();


 label_book_title = new QLabel("Default",this);
 label_book_title->setGeometry(69,25,200,50);
 label_book_title->setStyleSheet("QLabel{font-size: 24px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 label_book_title->hide();

 label_book_author = new QLabel("Default",this);
 label_book_author->setGeometry(92,75,200,50);
 label_book_author->setStyleSheet("QLabel{font-size: 24px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 label_book_author->hide();

 label_book_genre = new QLabel("Default",this);
 label_book_genre->setGeometry(83,125,200,50);
 label_book_genre->setStyleSheet("QLabel{font-size: 24px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 label_book_genre->hide();

 label_book_publication_year = new QLabel("Default",this);
 label_book_publication_year->setGeometry(183,175,200,50);
 label_book_publication_year->setStyleSheet("QLabel{font-size: 24px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 label_book_publication_year->hide();

 label_book_description = new QLabel("Default",this);
 label_book_description->setGeometry(15,250,200,50);
 label_book_description->setStyleSheet("QLabel{font-size: 18px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 label_book_description->hide();

 label_book_cover = new QLabel("Default",this);
 label_book_cover->setGeometry(83,350,200,50);
 label_book_cover->setStyleSheet("QLabel{font-size: 24px;font-family: Times New Roman;color: rgb(0, 0, 0);}");
 label_book_cover->hide();

 button_modify = new QPushButton("Add",this);
 button_modify->setGeometry(15,415,125,75);
 button_modify->hide();

 button_next = new QPushButton("Next",this);
 button_next->setGeometry(265,415,125,75);
 button_next->hide();
}


void UserWindow::displayBook(int index, ListType type){
        bool added = 0;
        std::string display;
        if (type == bookList)
            this->Controller->displayBook(&display, index);
        else {
            this->Controller->displayBookTL(&display, index);
            added = 1;

        }

}

void UserWindow::slotHandleView()
{
    while(bookNo < this->Controller->repo.vector.size()){
        bookNo ++;
        displayBook(bookNo,bookList);
    }

}

void UserWindow::slotHandleModify()
{

}

void UserWindow::slotHandleNext()
{

}



