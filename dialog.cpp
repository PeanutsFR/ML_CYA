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

    command = COMMAND_NOTHING;

    commands = new QTimer();
    connect(commands,SIGNAL(timeout()),this,SLOT(send_commands()));
    commands->start(30);
}

void Dialog::keyPressEvent(QKeyEvent *event){

    switch(event->key()){
    case Qt::Key_Q:
        command = COMMAND_STRAFE_LEFT;
        break;

    case Qt::Key_Z:
        command = COMMAND_FORWARD;
        break;

    case Qt::Key_S:
        command = COMMAND_BACKWARD;
        break;

    case Qt::Key_D:
        command = COMMAND_STRAFE_RIGHT;
        break;

    case Qt::Key_Up:
        command = COMMAND_LIFT;
        break;

    case Qt::Key_Down:
        command = COMMAND_GO_DOWN;
        break;

    case Qt::Key_Left:
        command = COMMAND_ROTATE_LEFT;
        break;

    case Qt::Key_Right:
        command = COMMAND_ROTATE_RIGHT;
        break;

    case Qt::Key_Space:
        if(drone->onGround())
           command = COMMAND_TAKE_OFF;
        else
            command = COMMAND_LAND;
        break;

    case Qt::Key_Control:
        if(drone->onGround())
            command = COMMAND_CONFIG_TRIMM;
        break;

    case Qt::Key_Alt:
        if(!drone->onGround())
            command = COMMAND_CONFIG_MAGNETO;
        break;

    case Qt::Key_Escape:
        commands->stop();
        this->close();
        break;

    }
}

void Dialog::send_commands(){
    switch(command){
    case COMMAND_STRAFE_LEFT:
        drone->move3D(0.0,1.0,0.0,0.0);
        break;

    case COMMAND_FORWARD:
        drone->move3D(1.0,0.0,0.0,0.0);
        break;

    case COMMAND_BACKWARD:
        drone->move3D(-1.0,0.0,0.0,0.0);
        break;

    case COMMAND_STRAFE_RIGHT:
        drone->move3D(0.0,-1.0,0.0,0.0);
        break;

    case COMMAND_LIFT:
        drone->move3D(0.0,0.0,1.0,0.0);
        break;

    case COMMAND_GO_DOWN:
        drone->move3D(0.0,0.0,-1.0,0.0);
        break;

    case COMMAND_ROTATE_LEFT:
        drone->move3D(0.0,0.0,0.0,1.0);
        break;

    case COMMAND_ROTATE_RIGHT:
        drone->move3D(0.0,0.0,0.0,-1.0);
        break;

    case COMMAND_TAKE_OFF:
        if(drone->onGround())
            drone->takeoff();
        break;

    case COMMAND_LAND:
        if(!drone->onGround())
            drone->landing();
        break;

    case COMMAND_CONFIG_TRIMM:
        if(drone->onGround())
            drone->setFlatTrim();
        break;

    case COMMAND_CONFIG_MAGNETO:
        if(!drone->onGround())
            drone->setCalibration();
        break;

    case COMMAND_NOTHING:
        break;
    }
}

void Dialog::keyReleaseEvent(QKeyEvent *event){
    switch(event->key()){
    default:
        command = COMMAND_NOTHING;
        //drone->move3D(0.0,0.0,0.0,0.0);
        break;
    }
}

Dialog::~Dialog()
{
    delete ui;
}
