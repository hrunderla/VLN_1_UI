#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <list>
#include <string>
#include "scientist.h"
#include "computer.h"
#include "connected.h"
#include "service.h"
#include "servicecomputer.h"
#include "serviceconnected.h"
#include "addscientistdialog.h"
#include "dialogaddconnections.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonScientist_clicked();
    void on_lineEditComputer_textChanged(const QString &arg1);
    void on_lineEditScientist_textChanged(const QString &arg1);

//private:
//    void displayAllConnection();        merge conflict... læt þetta vera



private:
    Service serviceScientist;
    ServiceComputer serviceComputer;
    ServiceConnected serviceConnected;

    void displayAllScientists();
    void displayAllComputers();
    void displayAllConnection();
    void on_pushButtonSciToCom_clicked();

    void displayScientists(list <Scientist> scientist);
    void displayComputers(list <Computer> computer);
    void displayConnection(list<Connected> scientistToComputer);

    Service sci;
    ServiceComputer com;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
