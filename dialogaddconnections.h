#ifndef DIALOGADDCONNECTIONS_H
#define DIALOGADDCONNECTIONS_H

#include <QDialog>
#include <string>
#include <QString>
#include <list>

#include "scientist.h"
#include "computer.h"
//#include "connected.h"
#include "service.h"
#include "servicecomputer.h"
//#include "serviceconnected.h"
//#include "dialogaddconnections.h"



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
    void on_lineEditNameOfScientist_textChanged(const QString &arg1);


    void on_pushButton_clicked();

private:
    Ui::DialogAddConnections *ui;
    Service service;
};

#endif // DIALOGADDCONNECTIONS_H
