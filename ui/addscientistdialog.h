#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H

#include <QDialog>
#include <string>
#include "service.h"
#include "scientist.h"

namespace Ui {
class AddScientistDialog;
}

class AddScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientistDialog(QWidget *parent = 0);
    ~AddScientistDialog();

private slots:
    void on_button_add_scientist_clicked();

private:
    Ui::AddScientistDialog *ui;

    Service service;
    Scientist scientist;

};

#endif // ADDSTUDENTDIALOG_H
