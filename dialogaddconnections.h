#ifndef DIALOGADDCONNECTIONS_H
#define DIALOGADDCONNECTIONS_H

#include <QDialog>

namespace Ui {
class DialogAddConnections;
}

class DialogAddConnections : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddConnections(QWidget *parent = 0);
    ~DialogAddConnections();

private:
    Ui::DialogAddConnections *ui;
};

#endif // DIALOGADDCONNECTIONS_H
