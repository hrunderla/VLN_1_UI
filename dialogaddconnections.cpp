#include "dialogaddconnections.h"
#include "ui_dialogaddconnections.h"

DialogAddConnections::DialogAddConnections(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddConnections)
{
    ui->setupUi(this);

}

DialogAddConnections::~DialogAddConnections()
{
    delete ui;
}

void DialogAddConnections::on_lineEditNameOfScientist_textChanged(const QString &arg1)
{
    //leitar að nafninu sem er slegið inn og birtir það
    scientistSelected = false;
    ui -> pushButtonAddConncetion -> setEnabled(false);
    list<Scientist> scientist = list <Scientist>();
    scientist = service.findData (arg1.toStdString());
    displayScientist(scientist);
}

void DialogAddConnections::on_lineEditNameOfComputer_textChanged(const QString &arg1)
{
    //leitar að nafninu sem er slegið inn og birtir það
    computerSelected = false;
    ui -> pushButtonAddConncetion -> setEnabled(false);
    list<Computer> computer = list <Computer>();
    computer = serviceComputer.findDataComp(arg1.toStdString());
    displayComputer(computer);
}

void DialogAddConnections::displayScientist(list<Scientist> scientist)
{
    ui -> tableWidgetScientist -> clearContents();
    ui -> tableWidgetScientist -> setRowCount(scientist.size());

    int row = 0;

    for (list <Scientist>::iterator it = scientist.begin(); it != scientist.end(); it++)
    {
        Scientist currentLine = *it;
        QString idOfScientist = QString::number(currentLine.getId());
        QString nameOfScientist = QString::fromStdString(currentLine.getName());
        QString gender = QString::fromStdString(currentLine.getGender());
        QString yearOfBirth = QString::number(currentLine.getBirthYear());
        QString yearOfDeath;
        int yearOfDeathInt = currentLine.getDeathYear();
        if(yearOfDeathInt == 0)
        {
            yearOfDeath = ("NULL");
        }
        else
        {
            yearOfDeath = QString::number(yearOfDeathInt);
        }

        ui->tableWidgetScientist -> setItem(row, 0, new QTableWidgetItem(idOfScientist));
        ui->tableWidgetScientist -> setItem(row, 1, new QTableWidgetItem(nameOfScientist));
        ui->tableWidgetScientist -> setItem(row, 2, new QTableWidgetItem(gender));
        ui->tableWidgetScientist -> setItem(row, 3, new QTableWidgetItem(yearOfBirth));
        ui->tableWidgetScientist -> setItem(row, 4, new QTableWidgetItem(yearOfDeath));

        row++;
    }
    scientistCurrentList = scientist;
}

void DialogAddConnections::displayComputer(list<Computer> computer)
{
    ui -> tableWidgetComputer -> clearContents();
    ui -> tableWidgetComputer -> setRowCount(computer.size());

    int row = 0;

    for (list <Computer>::iterator it = computer.begin(); it != computer.end(); it++)
    {
        Computer currentLine = *it;

        QString idOfComputer = QString::number(currentLine.getId());
        QString nameOfComputer = QString::fromStdString(currentLine.getName());
        QString type = QString::fromStdString(currentLine.getType());
        QString year;
        int yearBuiltInt = currentLine.getYear();
        if(yearBuiltInt == 0)
        {
            year = ("NULL");
        }
        else
        {
            year = QString::number(yearBuiltInt);
        }

        ui->tableWidgetComputer -> setItem(row, 0, new QTableWidgetItem(idOfComputer));
        ui->tableWidgetComputer -> setItem(row, 1, new QTableWidgetItem(nameOfComputer));
        ui->tableWidgetComputer -> setItem(row, 2, new QTableWidgetItem(type));
        ui->tableWidgetComputer -> setItem(row, 3, new QTableWidgetItem(year));

        row++;
    }
    computerCurrentList = computer;
}

void DialogAddConnections::on_tableWidgetScientist_clicked(const QModelIndex &index)
{
    scientistSelected = true;
    connectonsSelected();
}

void DialogAddConnections::on_tableWidgetComputer_clicked(const QModelIndex &index)
{
    computerSelected = true;
    connectonsSelected();
}

bool DialogAddConnections::connectonsSelected()
{
    if(scientistSelected == true && computerSelected == true)
    {
        ui -> pushButtonAddConncetion -> setEnabled(true);
    }
}


void DialogAddConnections::on_pushButtonAddConncetion_clicked()
{
    int rowScientist = ui -> tableWidgetScientist -> currentIndex().row();
    int colScientist = 0;
    QTableWidgetItem* getscientistId = ui -> tableWidgetScientist -> item(rowScientist, colScientist);
    int scienstiId = getscientistId -> text().toInt();

    int rowComputer = ui -> tableWidgetComputer -> currentIndex().row();
    int colComputer = 0;
    QTableWidgetItem* getcomputerId = ui -> tableWidgetComputer -> item(rowComputer, colComputer);
    int computerId = getcomputerId -> text().toInt();
;
    if (serviceConnected.connectSciToCom(scienstiId, computerId))
    {
        //skilaboð að tenging hafi tekist
    }
    else
    {
        //hef ekki hugmynd
    }

}
