#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addscientistdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllScientists();
    displayAllComputers();
    displayAllConnection();

    serviceScientist = Service() ;
    serviceComputer = ServiceComputer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllScientists()
{
    list<Scientist> scientist = list <Scientist>();
    scientist = serviceScientist.viewScientistAsc();
    displayScientists(scientist);
}

void MainWindow::displayAllComputers()
{
    list<Computer> computer = list <Computer>();
    computer = serviceComputer.viewComputerAsc();
    displayComputers(computer);
}

void MainWindow::displayAllConnection()
{
    list<Connected> scientistToComputer = list <Connected>();
    scientistToComputer = serviceConnected.viewSciToCom();
    displayConnection(scientistToComputer);
}

void MainWindow::displayScientists(list<Scientist> scientist)
{
    ui -> tableScientist -> clearContents();
    ui -> tableScientist -> setRowCount(scientist.size());

    int row = 0;

    for (list <Scientist>::iterator it = scientist.begin(); it != scientist.end(); it++)
    {
        Scientist currentLine = *it;

        QString nameOfScientist = QString::fromStdString(currentLine.getName());
        QString gender = QString::fromStdString(currentLine.getGender());
        QString yearOfBirth = QString::number(currentLine.getBirthYear());
        QString yearOfDeath;
        int yearOfDeathInt = currentLine.getDeathYear();
        if(yearOfDeathInt == 0)
        {
            yearOfDeath = "";
        }
        else
        {
            yearOfDeath = QString::number(yearOfDeathInt);
        }

        ui->tableScientist -> setItem(row, 0, new QTableWidgetItem(nameOfScientist));
        ui->tableScientist -> setItem(row, 1, new QTableWidgetItem(gender));
        ui->tableScientist -> setItem(row,2, new QTableWidgetItem(yearOfBirth));
        ui->tableScientist -> setItem(row,3, new QTableWidgetItem(yearOfDeath));

        row++;
    }
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

void MainWindow::displayConnection(list<Connected> scientistToComputer)
{
    ui -> tableSciToCom -> clearContents();
    ui -> tableSciToCom -> setRowCount(scientistToComputer.size());

    int row = 0;

    for (list <Connected>::iterator it = scientistToComputer.begin(); it != scientistToComputer.end(); it++)
        {
            Connected currentLine = *it;

            QString nameOfScientist = QString::fromStdString(currentLine.getNameOne());
            QString nameOfComputer = QString::fromStdString(currentLine.getNameTwo());

            ui->tableSciToCom->setItem(row, 0, new QTableWidgetItem(nameOfScientist));
            ui->tableSciToCom->setItem(row, 1, new QTableWidgetItem(nameOfComputer));

            row++;
        }
}

void MainWindow::on_pushButtonScientist_clicked()
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

void MainWindow::on_lineEditComputer_textChanged(const QString &arg1)
{
    list<Computer> computer = list <Computer>();
    computer = serviceComputer.findDataComp (arg1.toStdString());
    displayComputers(computer);
}

void MainWindow::on_lineEditScientist_textChanged(const QString &arg1)
{
    list<Scientist> scientist = list <Scientist>();
    scientist = serviceScientist.findData (arg1.toStdString());
    displayScientists(scientist);
}


void MainWindow::on_pushButtonSciToCom_clicked()
{
    DialogAddConnections dialogAddConnections;
    dialogAddConnections.exec();
}
