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
    ui->rtf_edit->appendPlainText(file.readAll());
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
    data.read_csv(fichier);
    data.set_response_idx(0);

    //const cv::Mat* values = data.get_values();
    //const cv::Mat* responses = data.get_responses();

    //std::cout << *values << std::endl;
    //std::cout << *responses << std::endl;

    struct TrainTestSplit spl(0.666666667, true);

    data.set_train_test_split(&spl);

    std::cout << "--- TRAIN SAMPLE --- " << std::endl;
    std::cout << "rows x cols = " << (data.get_train_sample_idx())->rows << " x " << (data.get_train_sample_idx())->cols << "\n" << std::endl;
    //std::cout << *(data.get_train_sample_idx()) << std::endl;

    std::cout << "--- TEST SAMPLE --- " << std::endl;
    std::cout << "rows x cols = " << (data.get_test_sample_idx())->rows << " x " << (data.get_test_sample_idx())->cols << "\n" << std::endl;
    //std::cout << *(data.get_test_sample_idx()) << std::endl;


    const cv::Mat* mat_iris = data.get_values();
    const cv::Mat* responses = data.get_responses();


    // ----- PARAMS -----
    CvSVMParams params;
    params.svm_type    = CvSVM::C_SVC;    params.kernel_type = CvSVM::LINEAR;
    params.term_crit   = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);

    // ----- TRAIN -----
    CvSVM SVM;
    //SVM.train(data.get_train_sample_idx(), responses, cv::Mat(), cv::Mat(), params);
    const cv::Mat* train_sample_mat = data.get_train_sample_idx();
    SVM.train(*train_sample_mat, *responses, cv::Mat(), cv::Mat(), params);



    cv::Mat predicted(data.get_test_sample_idx()->rows,1, CV_32F);
    for(int i = 0; i < (data.get_test_sample_idx())->rows; i++) {
        cv::Mat sample = (data.get_test_sample_idx())->row(i);
        predicted.at<float>(i,0)= SVM.predict(sample);
        float p = predicted.at<float>(i,0);

        std::cout << "float p = " << p << std::endl;
        if (p == 1) {
            std::cout << "Iris-setosa" << std::endl;
        } else if (p == 2) {
            std::cout << "Iris-versicolor" << std::endl;
        } else if (p == 3) {
            std::cout << "Iris-virginica" << std::endl;
        }
    }


//Ouverture et chargement du fichier
//CvMLData data;
//data.read_csv("/home/emip/Drone/Drone/data/iris/iris.data");
//cv::Mat m = data.get_values();
//cv::Mat m;
//data.set_response_idx(4);
//m = data.get_values();
//std::cout << "Matrice = " << m << std::endl;

//Intialisation
//cv::Mat train_sample,test_sample,samples,responses,vars;
//samples = cv::Mat(data.get_values(),true); //samples
//data.set_response_idx(4);
/*
    std::map<std::string,int> results = data.get_class_labels_map();
    CvTrainTestSplit spl(100,true);
    data.set_train_test_split(&spl);

    //Matrices

    responses = cv::Mat(data.get_responses(),true);
    train_sample = data.get_train_sample_idx();
    test_sample = data.get_test_sample_idx();
    vars = data.get_var_idx();

    //Classifier params
    CvSVMParams params;
    params.svm_type    = CvSVM::C_SVC;
    params.kernel_type = CvSVM::LINEAR;
    params.term_crit   = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);

    //Classifier
    CvSVM svm;

    //Training
    svm.train(samples,responses,vars,train_sample,params);

    //Predict


    //svm.predict()


            //std::vector<float> e1, e2;
            // float f1 = bayes.calc_error(data,CV_TRAIN_ERROR,&e1); // train
            // float f2 = bayes.calc_error(data,CV_TEST_ERROR,&e2);//test

    ui->rtf_edit->appendPlainText(QString::number(results["Iris-setosa"]));
    ui->rtf_edit->appendPlainText(QString::number(results["Iris-versicolor"]));
    ui->rtf_edit->appendPlainText(QString::number(results["Iris-virginica"]));

    ui->rtf_edit->appendPlainText(QString::number(samples.rows));
    ui->rtf_edit->appendPlainText(QString::number(samples.cols));
    ui->rtf_edit->appendPlainText(QString::number(responses.rows));
    ui->rtf_edit->appendPlainText(QString::number(responses.cols));
    ui->rtf_edit->appendPlainText(QString::number(test_sample.size().width) + tr("x") + QString::number(test_sample.size().height) + tr(" : ensemble de test"));
    ui->rtf_edit->appendPlainText(QString::number(vars.cols));
    ui->rtf_edit->appendPlainText(QString::number(responses.at<float>(1,0)));

    double* Mi;
    QString ligne("");
    QString res;
    for(int i=0;i<test_sample.cols;i++){
        ligne = QString::number(test_sample.at<int>(0,i)) + tr(" :");
        samples.ptr<double>(test_sample.at<int>(0,i));
        for(int j=0;j<vars.cols;j++){
            res.setNum(Mi[j],'f');
            ligne = ligne + tr(" ") + res;
        }
        ui->rtf_edit->appendPlainText(ligne);
    }


    // ui->rtf_edit->appendPlainText(QString::number(f1) + tr(" % erreur en apprentissage"));
    // ui->rtf_edit->appendPlainText(QString::number(f2) + tr(" % erreur en test"));
*/

}

MainWindow::~MainWindow()
{
    delete ui;
    if(fen_ctrl != NULL) delete fen_ctrl;
}
