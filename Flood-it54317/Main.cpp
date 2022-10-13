#include <iostream>
#include <QApplication>
#include "Controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller *controller = new Controller();
    controller->launch();
    return a.exec();
}
