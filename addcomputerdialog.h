#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include <string>
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

private:
    Ui::AddComputerDialog *ui;
};

#endif // ADDCOMPUTERDIALOG_H
