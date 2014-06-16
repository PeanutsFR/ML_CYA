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
	/* float values[nb_lignes][nb_col];
	for (int i=0; i<nb_lignes; ++i) {
		for (int j=0; j<nb_col; ++j) {
			values[i][j] = matrice_readCSV[i][j];
		}
	}
	cv::Mat mat(nb_lignes, nb_col, CV_32FC1, values);
	return &mat; */
	return &matrice_readCSV;
}

//get reponses
const cv::Mat* get_responses(void);