#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllComputers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllComputers()
{
    list <Computer> computers = servicecomputer.getComputerList();
    displayComputers(computers);
}

void MainWindow::displayComputers(list<Computer> computers)
{
    ui->listComputers->clear();

//    ui->listComputers->addItem(QString::fromStdString();

   // ui->listComputers->addItem(QString::fromStdString("Test 123"));

    for (list <Computer>::iterator it = computers.begin(); it != computers.end(); it++)
        {
          Computer currentComputer = *it;
            ui->listComputers->addItem(QString::fromStdString(currentComputer.info()));
        }

//    for(unsigned int i = 0; i < computers.size(); i++)
//    {
//

//        ui->listComputers->addItem(QString::fromStdString(currentComputer.getName(),));
//    }
}
