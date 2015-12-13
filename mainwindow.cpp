#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui/addscientistdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllConnection();
    displayAllComputers();

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

void MainWindow::displayAllComputers()
{
    list<Computer> computer = list <Computer>();
    computer = serviceComputer.viewComputerAlphabetically();
    displayComputers(computer);
}

void MainWindow::displayComputers(list<Computer> computer)
{
    ui -> tableComputers -> clearContents();
    ui -> tableComputers -> setRowCount(computer.size());

    int row = 0;

    for (list <Computer>::iterator it = computer.begin(); it != computer.end(); it++)
        {
            Computer currentLine = *it;

            QString nameOfComputer = QString::fromStdString(currentLine.getName());
            QString type = QString::fromStdString(currentLine.getType());
            QString year = QString::number(currentLine.getYear());

            ui->tableComputers -> setItem(row, 0, new QTableWidgetItem(nameOfComputer));
            ui->tableComputers -> setItem(row, 1, new QTableWidgetItem(type));
            ui->tableComputers -> setItem(row,2, new QTableWidgetItem(year));

            row++;
        }
}


void MainWindow::on_AddButton_clicked()
{
    AddScientistDialog addSientistDialog;
    int addScientistReturnValue = addSientistDialog.exec();

    if (addScientistReturnValue == 0)
    {

       // ui->statusBar->showMessage("Successfully added scientist", 1500);
    }
    else
    {
        // there was an error
    }
}
