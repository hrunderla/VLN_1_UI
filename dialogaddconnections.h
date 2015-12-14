#ifndef DIALOGADDCONNECTIONS_H
#define DIALOGADDCONNECTIONS_H

#include <QDialog>
#include <string>
#include <QString>
#include <list>

#include "mainwindow.h"
#include "scientist.h"
#include "computer.h"
#include "connected.h"
#include "service.h"
#include "servicecomputer.h"
#include "serviceconnected.h"


namespace Ui {
class DialogAddConnections;
}

class DialogAddConnections : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddConnections(QWidget *parent = 0);
    ~DialogAddConnections();

private slots:
    //leitar að nafninu sem er slegið inn og birtir það
    void on_lineEditNameOfScientist_textChanged(const QString &arg1);

    //leitar að nafninu sem er slegið inn og birtir það
    void on_lineEditNameOfComputer_textChanged(const QString &arg1);

    void on_tableWidgetScientist_clicked(const QModelIndex &index);

    void on_tableWidgetComputer_clicked(const QModelIndex &index);

    void on_pushButtonAddConncetion_clicked();

    void on_pushButtonClose_clicked();

private:
    Scientist scientist;
    Computer computer;
    Connected connect;
    Service service;
    ServiceComputer serviceComputer;
    ServiceConnected serviceConnected;

    list<Scientist> scientistCurrentList;
    list<Computer> computerCurrentList;

    bool scientistSelected;
    bool computerSelected;

    void displayScientist(list<Scientist> scientist);
    void displayComputer(list<Computer> computer);
    void connectonsSelected();


    int checkScientistInDatabase();
    int checkComputerInDatabase();

    Ui::DialogAddConnections *ui;

};

#endif // DIALOGADDCONNECTIONS_H
