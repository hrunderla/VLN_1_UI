#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"

#include <QMessageBox>

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    ui->setupUi(this);
}

AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

void AddScientistDialog::on_button_add_scientist_clicked()
{
    ui->label_error_scientist_name->setText("");
    ui->label_error_scientist_year_born->setText("");
    ui->label_error_scientist_year_death->setText("");

    QString name = ui->input_scientist_name->text();

    string gender;
    if(ui->radioButton_Female->isChecked())
    {
        gender = "female";
    }
    if(ui->radioButton_Male->isChecked())
    {
        gender = "male";
    }

    QString birthYear = ui->input_scientist_year_born->text();

    QString deathYear;
    if(ui->ScientistIsDead->isChecked())
    {
        deathYear = ui->input_scientist_year_death->text();
    }
    else
    {
        deathYear = "";
    }

    bool thereWasAnError = false;

    if (name.isEmpty())
    {
        ui->label_error_scientist_name->setText("<span style='color: #ED1C58'>Name cannot be empty</span>");
        thereWasAnError = true;
    }

    if (birthYear.isEmpty())
    {
        ui->label_error_scientist_year_born->setText("<span style='color: #ED1C58'>Please enter a birth year</span>");
        thereWasAnError = true;
    }
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

   service.newScientist(Scientist(name.toStdString(), gender, birthYear.toInt(), deathYear.toInt()));

        ui->input_scientist_name->setText("");
        ui->input_scientist_year_born->setText("");
        ui->input_scientist_year_death->setText("");


}

