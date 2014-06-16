#include "mldata.h"
#include <iostream>
#include <QFile>

MLData::MLData()
{
    this->col_resp = 0;
    this->separator=',';
}

MLData::~MLData(){

}

int MLData::read_csv(QString filepath){
    QString ligne;
    QFile file(filepath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    ligne = file.readLine();
    std::cout << ligne.toStdString();
    return 0;
}

cv::Mat matrice_readCSV; // matrice remplie depuis le parsing du fichier

//set_response_idx
int set_response_idx(int val) {
	col_resp = val;
	return 0;
}

//get_values
const cv::Mat* get_values(void) {
	return &matrice_readCSV;
}

//get reponses
const cv::Mat* get_responses(void) {
	float responses[nb_lignes];
    for(int i = 0; i < nb_echantillons; ++i ) {
        responses[i] = matrice_readCSV.at<float>(i,col_resp); 
    }
    cv::Mat matResponses(nb_lignes, 1, CV_32FC1, responses);
    return &matResponses;
}

