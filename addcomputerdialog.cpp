#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

#include <QMessageBox>

AddComputerDialog::AddComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerDialog)
{
    ui->setupUi(this);
}

AddComputerDialog::~AddComputerDialog()
{
    delete ui;
}

void AddComputerDialog::on_button_add_computer_clicked()
{
    ui->label_error_computer_name->setText("");
    ui->label_error_computer_year_build->setText("");

    QString name = ui->input_computer_name->text();

    string type;
    if(ui->radioButton_electronic->isChecked())
    {
        type = "electronic";
    }
    if(ui->radioButton_mechanical->isChecked())
    {
        type = "mechanical";
    }
    if(ui->radioButton_transistor->isChecked())
    {
        type = "transistor";
    }

    QString yearbuild;
    int wasitbuilt;
    if(ui->ComputerBuilt->isChecked())
    {
        yearbuild = ui->input_computer_year_build->text();
        wasitbuilt = 1;
    }
    else
    {
        yearbuild = "";
        wasitbuilt =0;
    }

    bool thereWasAnError = false;

    if (name.isEmpty())
    {
        ui->label_error_computer_name->setText("<span style='color: #ED1C58'>Name cannot be empty</span>");
        thereWasAnError = true;
    }

//    if (.isEmpty())
//    {
//        ui->label_error_scientist_year_born->setText("<span style='color: #ED1C58'>Please enter a birth year</span>");
//        thereWasAnError = true;
//    }
//    if(birthYear.isSimpleText())
//    {
//        ui->label_error_scientist_year_born->setText("<span style='color: #ED1C58'>Please enter a valid year of birth</span>");
//        thereWasAnError = true;
//    }
//    if(deathYear.isSimpleText())
//    {
//        ui->label_error_scientist_year_death->setText("<span style='color: #ED1C58'>Please enter a valid year of death</span>");
//        thereWasAnError = true;
//    }
    if (thereWasAnError)
    {
        return;
    }

    int answer = QMessageBox::question(this, "Confirm", "Are you sure?");

    if (answer == QMessageBox::No)
    {
        return;
    }

   servicecomputer.newComputer(Computer(name.toStdString(), yearbuild.toInt(), type, wasitbuilt));

        ui->input_computer_name->setText("");
        ui->input_computer_year_build->setText("");


}

