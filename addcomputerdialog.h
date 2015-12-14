#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include <string>
#include <QMessageBox>
#include "servicecomputer.h"
#include "computer.h"

namespace Ui {
class AddComputerDialog;
}

class AddComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerDialog(QWidget *parent = 0);
    ~AddComputerDialog();

private slots:
    void on_button_add_computer_clicked();

private:
    Ui::AddComputerDialog *ui;

    ServiceComputer servicecomputer;
    Computer computer;
};

#endif // ADDCOMPUTERDIALOG_H
