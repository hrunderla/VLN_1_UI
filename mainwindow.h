#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "servicecomputer.h"
#include <list>
#include <computer.h>

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
    void displayAllComputers();
    void displayComputers(list <Computer> computers);
    ServiceComputer servicecomputer;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
