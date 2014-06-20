#include "dialog.h"
#include "ui_dialog.h"
#include "ardrone/ardrone.h"
#include <QKeyEvent>

static double v1 = 0;
static double v2 = 0;
static double v3 = 0;
static double v4 = 0;
static bool v1_active = false;
static bool v2_active = false;
static bool v3_active = false;
static bool v4_active = false;
static int deplacement = 0;

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
    ui->btn_alt->setEnabled(false);
    ui->btn_ctrl->setEnabled(false);
    ui->btn_left->setEnabled(false);
    ui->btn_up->setEnabled(false);
    ui->btn_right->setEnabled(false);
    ui->btn_down->setEnabled(false);
    ui->btn_tkoff->setEnabled(false);
    ui->btn_quit->setEnabled(false);

    command = COMMAND_NOTHING_V1;

    commands = new QTimer();
    connect(commands,SIGNAL(timeout()),this,SLOT(send_commands()));
    commands->start(30);
}

void Dialog::keyPressEvent(QKeyEvent *event){

    switch(event->key()){
    case Qt::Key_Q:
        command = COMMAND_STRAFE_LEFT;
        deplacement = 1;
        v2_active = true;
        break;

    case Qt::Key_Z:
        command = COMMAND_FORWARD;
        deplacement = 1;
        v1_active = true;
        break;

    case Qt::Key_S:
        command = COMMAND_BACKWARD;
        deplacement = 1;
        v1_active = true;
        break;

    case Qt::Key_D:
        command = COMMAND_STRAFE_RIGHT;
        deplacement = 1;
        v2_active = true;
        break;

    case Qt::Key_Up:
        command = COMMAND_LIFT;
        deplacement = 1;
        v3_active = true;
        break;

    case Qt::Key_Down:
        command = COMMAND_GO_DOWN;
        deplacement = 1;
        v3_active = true;
        break;

    case Qt::Key_Left:
        command = COMMAND_ROTATE_LEFT;
        deplacement = 1;
        v4_active = true;
        break;

    case Qt::Key_Right:
        command = COMMAND_ROTATE_RIGHT;
        v4_active = true;
        deplacement = 1;
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
        v2 = 1.0;
        // drone->move3D(0.0,1.0,0.0,0.0);
        break;

    case COMMAND_FORWARD:
        v1 = 1.0;
        // drone->move3D(1.0,0.0,0.0,0.0);
        break;

    case COMMAND_BACKWARD:
        v1 = -1.0;
        // drone->move3D(-1.0,0.0,0.0,0.0);
        break;

    case COMMAND_STRAFE_RIGHT:
        v2 = -1.0;
        // drone->move3D(0.0,-1.0,0.0,0.0);
        break;

    case COMMAND_LIFT:
        v3 = 1.0;
        //drone->move3D(0.0,0.0,1.0,0.0);
        break;

    case COMMAND_GO_DOWN:
        v3 = -1.0;
        // drone->move3D(0.0,0.0,-1.0,0.0);
        break;

    case COMMAND_ROTATE_LEFT:
        v4 = 1.0;
        // drone->move3D(0.0,0.0,0.0,1.0);
        break;

    case COMMAND_ROTATE_RIGHT:
        v4 = -1.0;

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

    case COMMAND_NOTHING_V1:
        if(!drone->onGround())
            v1 = 0.0;
        break;

    case COMMAND_NOTHING_V2:
        if(!drone->onGround())
            v2 = 0.0;
        break;

    case COMMAND_NOTHING_V3:
        if(!drone->onGround())
            v3 = 0.0;
        break;

    case COMMAND_NOTHING_V4:
        if(!drone->onGround())
            v4 = 0.0;
        break;

    }

    if(deplacement){
        drone->move3D(v1,v2,v3,v4);
    }
    else{
        drone->move3D(0.0,0.0,0.0,0.0);
    }

}

void Dialog::keyReleaseEvent(QKeyEvent *event){
    switch(event->key()){

    case Qt::Key_Z:
        command = COMMAND_NOTHING_V1;
        v1_active = false;
        break;

    case Qt::Key_S:
        command = COMMAND_NOTHING_V1;
        v1_active = false;
        break;

    case Qt::Key_Q:
        command = COMMAND_NOTHING_V2;
        v2_active = false;
        break;

    case Qt::Key_D:
        command = COMMAND_NOTHING_V2;
        v2_active = false;
        break;

    case Qt::Key_Up:
        command = COMMAND_NOTHING_V3;
        v3_active = false;
        break;

    case Qt::Key_Down:
        command = COMMAND_NOTHING_V3;
        v3_active = false;
        break;

    case Qt::Key_Left:
        command = COMMAND_NOTHING_V4;
        v4_active = false;
        break;

    case Qt::Key_Right:
        command = COMMAND_NOTHING_V4;
        v4_active = false;
        break;
    }

    if(!v1_active && !v2_active && !v3_active && !v4_active)
        deplacement = 0;
}

Dialog::~Dialog()
{
    delete ui;
}
