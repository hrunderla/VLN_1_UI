#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <list>
#include "scientist.h"
#include "computer.h"
#include "connected.h"
#include "service.h"
#include "servicecomputer.h"
#include "serviceconnected.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    void displayAllConnection();
    void displayConnection(list<Connected> scientistToComputer);

    ServiceConnected serviceConnected;

    void displayAllComputers();
    void displayComputers(list <Computer> computer);

    ServiceComputer serviceComputer;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
