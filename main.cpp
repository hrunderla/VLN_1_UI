#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication program(argc, argv);
    MainWindow window;
    window.show();

    return program.exec();
}
