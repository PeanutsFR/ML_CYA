#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QImage>
#include <QFileDialog>
#include <QFile>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#include <string>
#include "ardrone/ardrone.h"
#include "mldata.h"
#include "traintestsplit.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //init des pointeurs
    fen_ctrl = NULL;

    ui->setupUi(this);
    status = new QLabel(tr("Drone GUI"));
    statusBar()->addWidget(status);
    camera = 0;

    //capWebcam.open(0);

    //if(capWebcam.isOpened() == false){
    //  status->setText("Erreur ouverture flux video");
    // return;
    // }

    std::string face_cascade_name = "haarcascade_frontalface_alt.xml";
    face_cascade.load(face_cascade_name);

}

void MainWindow::on_actionTest4_triggered(){
    this->close();
}

void MainWindow::on_actionTest4_hovered(){
    status->setText(tr("Exit program"));
}

void MainWindow::on_btn_takeoff_clicked(){
    status->setText("Taking-off");
    ardrone.setFlatTrim();
    ardrone.takeoff();
    ardrone.setCalibration();
}

void MainWindow::on_btn_land_clicked(){
    status->setText("Landing");
    ardrone.landing();
}

void MainWindow::on_btn_goup_pressed(){
    if(!ardrone.onGround()){
        ardrone.move3D(0.0,0.0,1.0,0.0);
    }
    status->setText("Going up");
}

void MainWindow::on_btn_goup_released(){
    if(!ardrone.onGround()){
        ardrone.move3D(0.0,0.0,0.0,0.0);
    }
    status->setText("Stationary");
}

void MainWindow::on_btn_godown_pressed(){
    if(!ardrone.onGround()){
        ardrone.move3D(0.0,0.0,-1.0,0.0);
    }
    status->setText("Going down");
}

void MainWindow::on_btn_godown_released(){
    if(!ardrone.onGround()){
        ardrone.move3D(0.0,0.0,0.0,0.0);
    }
    status->setText("Stationary");
}

void MainWindow::on_btn_rotleft_pressed(){
    if(!ardrone.onGround()){
        ardrone.move3D(0.0,0.0,0.0,1.0);
    }
    status->setText("Rotating left");
}

void MainWindow::on_btn_rotleft_released(){
    if(!ardrone.onGround()){
        ardrone.move3D(0.0,0.0,0.0,0.0);
    }
    status->setText("Stationary");
}

void MainWindow::on_btn_rotright_pressed(){
    if(!ardrone.onGround()){
        ardrone.move3D(0.0,0.0,0.0,-1.0);
    }
    status->setText("Rotationg right");
}

void MainWindow::on_btn_rotright_released(){
    if(!ardrone.onGround()){
        ardrone.move3D(0.0,0.0,0.0,0.0);
    }
    status->setText("Stationary");
}

void MainWindow::on_btn_keyctrl_clicked(){
    fen_ctrl = new Dialog(&ardrone,this);
}

void MainWindow::on_btn_chgCam_clicked(){
    if (camera == 1)
        camera = 0;
    else
        camera = 1;
}

void MainWindow::on_btn_anim_clicked(){
    //ardrone.setAnimation(ui->txt_anim->text().toInt());
    ardrone.setAnimation(ui->txt_anim->text().toInt());
}

void MainWindow::on_btn_parcourir_clicked(){
    QString chemin = QFileDialog::getOpenFileName(this,tr("Select data file"),tr(""),tr("Data files (*.data)"));
    ui->txt_path->setText(chemin);
}

void MainWindow::on_btn_drone_connect_clicked(){
    if(!ardrone.open()){
        status->setText("Conexion error");
        return;
    }
    else{
        tm = new QTimer(this);
        connect(tm,SIGNAL(timeout()),this,SLOT(updateGUI()));
        tm->start(20);
        status->setText("Conected !");
    }
}

void MainWindow::on_btn_drone_disconnect_clicked(){
    tm->stop();
    ardrone.close();
    ui->lbl_cam->setText(tr("Connexion to the drone required"));
    ui->lbl_rendu->setText(tr("Connexion to the drone required"));
    status->setText("Deconnecté");
}

void MainWindow::on_btn_load_clicked(){
    QString fichier = ui->txt_path->text();
    QFile file(fichier);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
   // ui->rtf_edit->appendPlainText(file.readAll());
    test(fichier);
}

void MainWindow::updateGUI(){
    //Webcam
    //capWebcam.read(matOriginal);

    //Drone
    ardrone.setCamera(camera);
    matOriginal = ardrone.getImage();
    if(matOriginal.empty() == true) return;
    cv::resize(matOriginal,matOriginal,cv::Size(400,280));

    cv::cvtColor(matOriginal,matGrey,CV_BGR2GRAY);
    cv::equalizeHist(matGrey,matGrey);

    std::vector<cv::Rect> faces;

    face_cascade.detectMultiScale(matGrey,faces,1.1,3,CV_HAAR_FIND_BIGGEST_OBJECT|CV_HAAR_SCALE_IMAGE,cv::Size(30,30));

    for(size_t i=0;i<faces.size();i++){
        cv::Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
        cv::Point pt2(faces[i].x, faces[i].y);
        cv::rectangle(matOriginal,faces[i],cv::Scalar(0,255,0,0),1,8,0);
    }

    cv::cvtColor(matOriginal,matOriginal,CV_BGR2RGB);
    cv::cvtColor(matGrey,matGrey,CV_GRAY2RGB);
    QImage qimgOriginal((uchar*)matOriginal.data,matOriginal.cols,matOriginal.rows,matOriginal.step,QImage::Format_RGB888);
    QImage qimgGrey((uchar*)matGrey.data,matGrey.cols,matGrey.rows,matGrey.step,QImage::Format_RGB888);
    ui->lbl_cam->setPixmap(QPixmap::fromImage(qimgOriginal));
    ui->lbl_rendu->setPixmap(QPixmap::fromImage(qimgGrey));
    ui->progressBar->setValue(ardrone.getBatteryPercentage());
    ui->lcd_alt->display(ardrone.getAltitude());
}


void MainWindow::test(QString fichier){

    MLData data;

    data.set_delimiter(',');
    data.read_csv(fichier);
    //data.set_response_idx(0);
    data.set_response_idx(data.get_values()->cols -1);

    struct TrainTestSplit spl(100, true);

    data.set_train_test_split(&spl);

    std::cout << "--- TRAIN SAMPLE --- " << std::endl;
    std::cout << "rows x cols = " << (data.get_train_sample_idx())->rows << " x " << (data.get_train_sample_idx())->cols << "\n" << std::endl;
    //std::cout << *(data.get_train_sample_idx()) << std::endl;

    std::cout << "--- TEST SAMPLE --- " << std::endl;
    std::cout << "rows x cols = " << (data.get_test_sample_idx())->rows << " x " << (data.get_test_sample_idx())->cols << std::endl;
    std::cout << *(data.get_test_sample_idx()) << std::endl;
    std::cout << "Variables idx : " << *(data.get_var_idx()) << std::endl;

    //Intialisation
    const cv::Mat* samples = data.get_values(); // samples
    const cv::Mat* responses = data.get_responses();
    const cv::Mat* train_sample = data.get_train_sample_idx();
    const cv::Mat* test_sample = data.get_test_sample_idx();
    const cv::Mat* vars = data.get_var_idx();

    //Classifier params
    CvSVMParams params;
    params.svm_type    = CvSVM::C_SVC;
    params.kernel_type = CvSVM::LINEAR;
    params.term_crit   = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);

    //Classifier
    CvSVM svm;

    //Training
    svm.train(*samples,*responses,*vars,*train_sample,params);

    cv::Mat predicted(test_sample->rows,1,CV_32FC1);
    for(int i=0;i<predicted.rows;i++){
        cv::Mat sample = samples->row(test_sample->at<int>(i,0));
        predicted.at<float>(i,0) = svm.predict(sample);
    }

    std::cout << "Predictions : " << predicted << std::endl;

}

MainWindow::~MainWindow()
{
    delete ui;
    if(fen_ctrl != NULL) delete fen_ctrl;
}
