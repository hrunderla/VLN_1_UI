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

    QString name = ui->input_scientist_name->text();
    string gender = "female";

    QString birthYear = ui->input_scientist_year_born->text();
    QString deathYear = ui->input_scientist_year_death->text();

    bool thereWasAnError = false;

    if (name.isEmpty())
    {
        ui->label_error_scientist_name->setText("<span style='color: #ED1C58'>Name cannot be empty</span>");

        thereWasAnError = true;
    }

    if (birthYear.isEmpty())
    {
        ui->label_error_scientist_year_born->setText("<span style='color: #ED1C58'>He has to be born</span>");
        thereWasAnError = true;
    }

    if (thereWasAnError)
    {
        return;
    }

    int answer = QMessageBox::question(this, "Confirm", "Are you sure?");

    if (answer == QMessageBox::No)
    {
        return;
    }

  Scientist(name.toStdString(), gender, birthYear.toInt(), deathYear.toInt());
//service.newScientist(scientist);

//   bool success = service.newScientist(Scientist(name.toStdString(), gender, birthYear.toInt(), deathYear.toInt()));

//    if (success)
//    {

//        ui->input_scientist_name->setText("");
//        gender = "female";
//        ui->input_scientist_year_born->setText("");
//        ui->input_scientist_year_death->setText("");


//        this->done(0);
//    }
//    else
//    {

//        this->done(-1);
//        // there was some error, tell the user
//    }
}

