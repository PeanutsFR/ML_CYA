#include "dialog.h"
#include "ui_dialog.h"
#include "ardrone/ardrone.h"
#include <QKeyEvent>

Dialog::Dialog(ARDrone* ardrone, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    this->drone = ardrone;
    ui->setupUi(this);
    this->show();

    ui->btn_d->setEnabled(false);
    ui->btn_q->setEnabled(false);
    ui->btn_s->setEnabled(false);
    ui->btn_z->setEnabled(false);

    ui->btn_left->setEnabled(false);
    ui->btn_up->setEnabled(false);
    ui->btn_right->setEnabled(false);
    ui->btn_down->setEnabled(false);

    ui->btn_tkoff->setEnabled(false);
    ui->btn_quit->setEnabled(false);
}

void Dialog::keyPressEvent(QKeyEvent *event){

    switch(event->key()){
    case Qt::Key_Q:
        drone->move3D(0.0,1.0,0.0,0.0);
        break;

    case Qt::Key_Z:
        drone->move3D(1.0,0.0,0.0,0.0);
        break;

    case Qt::Key_S:
        drone->move3D(-1.0,0.0,0.0,0.0);
        break;

    case Qt::Key_D:
        drone->move3D(0.0,-1.0,0.0,0.0);
        break;

    case Qt::Key_Up:
        drone->move3D(0.0,0.0,1.0,0.0);
        break;

    case Qt::Key_Down:
        drone->move3D(0.0,0.0,-1.0,0.0);
        break;

    case Qt::Key_Left:
        drone->move3D(0.0,0.0,0.0,1.0);
        break;

    case Qt::Key_Right:
        drone->move3D(0.0,0.0,0.0,-1.0);
        break;

    case Qt::Key_Space:
        if(drone->onGround()){
            drone->setFlatTrim();
            drone->takeoff();
            drone->setCalibration();
        }
        else{
            drone->landing();
        }
        break;

    case Qt::Key_Escape:
        this->close();
        break;

    }
}

void Dialog::keyReleaseEvent(QKeyEvent *event){
    switch(event->key()){
    default:
        drone->move3D(0.0,0.0,0.0,0.0);
        break;
    }
}

Dialog::~Dialog()
{
    delete ui;
}
