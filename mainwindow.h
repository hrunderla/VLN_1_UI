#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <list>
#include "connected.h"
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

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
