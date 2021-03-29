#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H


#include <QWidget>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QString>
#include "ClientController.h"
#include "BookRepo.h"
#include "Book.h"
#include <iostream>
#include <string>
#include<QShortcut>

class QPushButton;
class AdminWindow : public QWidget
{
    Q_OBJECT

 public:
  explicit AdminWindow(QWidget *parent = 0, ClientController* controller = nullptr);
 private:
    ClientController* Controller;

 QShortcut* shortcut_undo;
 QShortcut* shortcut_redo;
 QPushButton* button_add;
 QPushButton* button_remove;
 QPushButton* button_update;

 QPlainTextEdit* BookList;

 QLineEdit* field_title_add;
 QLineEdit* field_author_add;
 QLineEdit* field_genre_add;
 QLineEdit* field_description_add;
 QLineEdit* field_publicationYear_add;
 QLineEdit* field_cover_add;

 QLineEdit* field_index_remove;

 QLineEdit* field_index_update;
 QLineEdit* field_title_update;
 QLineEdit* field_author_update;
 QLineEdit* field_genre_update;
 QLineEdit* field_description_update;
 QLineEdit* field_publicationYear_update;
 QLineEdit* field_cover_update;

 void BookListUpdate();

private slots:
 void slotHandleAdd();
 void slotHandleRemove();
 void slotHandleUpdate();
 void slotHandleUndo();
 void slotHandleRedo();

};


#endif // ADMINWINDOW_H
