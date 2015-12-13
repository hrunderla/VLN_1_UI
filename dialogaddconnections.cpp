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
   // string scientistName = arg1.toStdString();
    list<Scientist> resultNameScientist = list<Scientist> ();
    resultNameScientist = service.findData(arg1.toStdString());
    if(resultNameScientist.empty() )
    {
         //error
    }
}

void DialogAddConnections::on_pushButton_clicked()
{

}
