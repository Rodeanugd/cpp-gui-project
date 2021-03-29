#ifndef UI_VERSIONSELECT_H
#define UI_VERSIONSELECT_H


#include <QWidget>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QString>
#include "ClientController.h"
#include "BookRepo.h"
#include "Book.h"
#include <iostream>
#include <string>
#include "UI_AdminWindow.h"
#include "UI_UserWindow.h"

class QPushButton;
class VSWindow : public QWidget
{
    Q_OBJECT

 public:
  explicit VSWindow(QWidget *parent = 0);
  ~VSWindow();
 private:
    ClientController* Controller;
    AdminWindow* adminWindow;
    UserWindow* userWindow;
 QPushButton* button_admin;
 QPushButton* button_user;


 void BookListUpdate();

private slots:
 void slotHandleAdmin();
 void slotHandleUser();

};


#endif // UI_VERSIONSELECT_H
