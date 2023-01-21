#include "widget.h"

#include <QApplication>
#include "menuwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuWindow w;
    //display the menu
    w.show();
    return a.exec();
}
