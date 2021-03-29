#include "Window.h"
#include <QPushButton>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <iostream>


Window::Window(QWidget *parent) :
 QWidget(parent)
 {
 // Set size of the window
 setFixedSize(1024, 512);

 // Buttons
 button_add = new QPushButton("Add book", this);
 button_add->setGeometry(10, 50, 80, 30);

 button_remove = new QPushButton("Remove book", this);
 button_remove->setGeometry(10, 100, 80, 30);

 button_update = new QPushButton("Update book", this);
 button_update->setGeometry(10, 150, 80, 30);

 // Input box-things
 field_title_add = new QLineEdit("title",this);
 field_title_add->setGeometry(100,50,100,30);

 field_author_add = new QLineEdit("author",this);
 field_author_add->setGeometry(220,50,100,30);

 field_genre_add = new QLineEdit("genre",this);
 field_genre_add->setGeometry(340,50,100,30);

 field_description_add = new QLineEdit("description",this);
 field_description_add->setGeometry(460,50,100,30);

 field_publicationYear_add = new QLineEdit("publication year",this);
 field_publicationYear_add->setGeometry(580,50,100,30);

 field_cover_add = new QLineEdit("cover",this);
 field_cover_add->setGeometry(700,50,100,30);

 field_index_remove = new QLineEdit("index",this);
 field_index_remove->setGeometry(100,100,50,30);

 field_title_update = new QLineEdit("title",this);
 field_title_update->setGeometry(100,150,100,30);

 field_author_update = new QLineEdit("author",this);
 field_author_update->setGeometry(220,150,100,30);

 field_genre_update = new QLineEdit("genre",this);
 field_genre_update->setGeometry(340,150,100,30);

 field_description_update = new QLineEdit("description",this);
 field_description_update->setGeometry(460,150,100,30);

 field_publicationYear_update = new QLineEdit("publication year",this);
 field_publicationYear_update->setGeometry(580,150,100,30);

 field_cover_update = new QLineEdit("cover",this);
 field_cover_update->setGeometry(700,150,100,30);

 field_index_update = new QLineEdit("index",this);
 field_index_update->setGeometry(820,150,50,30);

 //List
 BookList = new QPlainTextEdit("",this);
 BookList->setGeometry(5, 250, 1009, 257);

 connect(button_add, SIGNAL (released()), this, SLOT (slotHandleAdd()));
 connect(button_remove, SIGNAL (released()), this, SLOT (slotHandleRemove()));
 connect(button_update, SIGNAL (released()), this, SLOT (slotHandleUpdate()));
}

void Window::slotHandleAdd(){
    std::string title;
    std::string author;
    Genre genre;
    std::string description;
    int publicationYear;
    std::string cover;
    int g;

    title = this->field_title_add->text().toStdString();
    author = this->field_author_add->text().toStdString();
    g = this->field_genre_add->text().toInt();
    genre = static_cast<Genre>(g);
    description = this->field_description_add->text().toStdString();
    publicationYear = this->field_publicationYear_add->text().toInt();
    cover = this->field_cover_add->text().toStdString();

    Book* book = new Book(title,author,genre,description,publicationYear,cover);
    this->ClientController.addBook(book);

    BookListUpdate();
}

void Window::slotHandleRemove(){
    int index;

    index = this->field_index_remove->text().toInt();

    this->ClientController.removeBook(index);

    BookListUpdate();
}

void Window::slotHandleUpdate(){
    std::string title;
    std::string author;
    Genre genre;
    std::string description;
    int publicationYear;
    std::string cover;
    int g;
    int index;

    title = this->field_title_update->text().toStdString();
    author = this->field_author_update->text().toStdString();
    g = this->field_genre_update->text().toInt();
    genre = static_cast<Genre>(g);
    description = this->field_description_update->text().toStdString();
    publicationYear = this->field_publicationYear_update->text().toInt();
    cover = this->field_cover_update->text().toStdString();
    index = this->field_index_update->text().toInt();

    Book* book = new Book(title,author,genre,description,publicationYear,cover);
    this->ClientController.updateBook(index,book);

    BookListUpdate();
}

void Window::BookListUpdate(){
    this->BookList->clear();
    int unsigned iterator = 0;
    std::string display;
    while (iterator < this->ClientController.repo.vector.size()) {
        this->ClientController.repo.vector.at(iterator)->toString(&display);
        QString Qdisplay = QString::fromStdString(display);
        this->BookList->appendPlainText(Qdisplay);
        iterator++;
    }
}
