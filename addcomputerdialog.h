#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>

namespace Ui {
class addcomputerdialog;
}

class addcomputerdialog : public QDialog
{
    Q_OBJECT

public:
    explicit addcomputerdialog(QWidget *parent = 0);
    ~addcomputerdialog();

private:
    Ui::addcomputerdialog *ui;
};

#endif // ADDCOMPUTERDIALOG_H
