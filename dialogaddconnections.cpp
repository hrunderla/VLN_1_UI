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
