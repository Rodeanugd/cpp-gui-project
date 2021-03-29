#include <QApplication>
#include "Window.h"
#include "UI_VersionSelect.h"

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

// Window window;
// window.show();
VSWindow VSWindow;
VSWindow.show();

 return app.exec();
}
