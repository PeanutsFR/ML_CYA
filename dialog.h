#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ardrone/ardrone.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(ARDrone *ardrone, QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    ARDrone *drone;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // DIALOG_H
