#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayAllConnection();
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

