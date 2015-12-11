#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllConnection();
  //  displayAllComputers();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllConnection()
{
    list<Connected> scientistToComputer = list <Connected>();
    scientistToComputer = serviceConnected.viewSciToCom();
    displayConnection(scientistToComputer);
}

void MainWindow::displayConnection(list<Connected> scientistToComputer)
{
    ui -> table_sciToCom -> clearContents();
    ui -> table_sciToCom -> setRowCount(scientistToComputer.size());

    int row = 0;

    for (list <Connected>::iterator it = scientistToComputer.begin(); it != scientistToComputer.end(); it++)
        {
            Connected currentLine = *it;

            QString nameOfScientist = QString::fromStdString(currentLine.getNameOne());
            QString nameOfComputer = QString::fromStdString(currentLine.getNameTwo());
        //    ui->table_sciToCom->insertRow(row);
            ui->table_sciToCom->setItem(row, 0, new QTableWidgetItem(nameOfScientist));
            ui->table_sciToCom->setItem(row, 1, new QTableWidgetItem(nameOfComputer));

            row++;
        }
}
/*
void MainWindow::displayAllComputers()
{
    list<Connected> computer = list <Computer>();
    computer = serviceConnected.viewSciToCom();
    displayComputers(computer);
}

void MainWindow::displayComputers(list<Computer> computer)
{
    ui -> table_computers -> clearContents();
    ui -> table_computers -> setRowCount(scientistToComputer.size());

    int row = 0;

    for (list <Connected>::iterator it = scientistToComputer.begin(); it != scientistToComputer.end(); it++)
        {
            Connected currentLine = *it;

            QString nameOfScientist = QString::fromStdString(currentLine.getNameOne());
            QString nameOfComputer = QString::fromStdString(currentLine.getNameTwo());
        //    ui->table_sciToCom->insertRow(row);
            ui->table_sciToCom->setItem(row, 0, new QTableWidgetItem(nameOfScientist));
            ui->table_sciToCom->setItem(row, 1, new QTableWidgetItem(nameOfComputer));

            row++;
        }
}
/*
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
*/
