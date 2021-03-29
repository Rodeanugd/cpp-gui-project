QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddWindow.cpp \
    Book.cpp \
    BookRepo.cpp \
    ClientController.cpp \
    IOException.cpp \
    PersistenceEngine.cpp \
    PersistenceEngineFromCsv.cpp \
    PersistenceEngineFromJson.cpp \
    UI_AdminWindow.cpp \
    UI_UserWindow.cpp \
    UI_VersionSelect.cpp \
    UserInterface.cpp \
    Window.cpp \
    main.cpp \
    mainwindow.cpp \
    test.cpp

HEADERS += \
    AddWindow.h \
    Book.h \
    BookRepo.h \
    ClientController.h \
    IOException.h \
    PersistenceEngine.h \
    PersistenceEngineFromCsv.h \
    PersistenceEngineFromJson.h \
    UI_AdminWindow.h \
    UI_UserWindow.h \
    UI_VersionSelect.h \
    UserInterface.h \
    Window.h \
    mainwindow.h \
    test.h

FORMS += \
    mainwindow.ui \
    setMode.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
