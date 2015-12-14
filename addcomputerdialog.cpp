#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

addcomputerdialog::addcomputerdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcomputerdialog)
{
    ui->setupUi(this);
}

addcomputerdialog::~addcomputerdialog()
{
    delete ui;
}
