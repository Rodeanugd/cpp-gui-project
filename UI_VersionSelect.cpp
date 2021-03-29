#include "UI_VersionSelect.h"
#include <QPushButton>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <iostream>


VSWindow::VSWindow(QWidget *parent) :
 QWidget(parent)
 {
    this->Controller = new ClientController();
 // Set size of the window
 setFixedSize(400, 300);

 // Buttons
 button_admin = new QPushButton("Administrator", this);
 button_admin->setGeometry(25, 100, 150, 100);
 button_admin->setStyleSheet("QPushButton{font-size: 20px;font-family: Times New Roman;color: rgb(0, 0, 0);}");

 button_user = new QPushButton("User", this);
 button_user->setGeometry(225, 100, 150, 100);
 button_user->setStyleSheet("QPushButton{font-size: 20px;font-family: Times New Roman;color: rgb(0, 0, 0);}");

 connect(button_admin, SIGNAL (released()), this, SLOT (slotHandleAdmin()));
 connect(button_user, SIGNAL (released()), this, SLOT (slotHandleUser()));
}

VSWindow::~VSWindow()
{

}

void VSWindow::slotHandleAdmin(){
    this->adminWindow = new AdminWindow(0 ,this->Controller);
    this->adminWindow->show();
}

void VSWindow::slotHandleUser(){
    this->userWindow = new UserWindow(0, this->Controller);
    this->userWindow->show();
}

