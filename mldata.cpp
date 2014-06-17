#include "mldata.h"
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>

MLData::MLData()
{
    this->col_resp = 0;
    this->separator=',';
}

MLData::~MLData(){

}

/* cv::Mat matrice_readCSV; // matrice remplie depuis le parsing du fichier

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
*/


//set_train_test_split
/* void set_train_test_split(const CvTrainTestSplit * spl) {
	
	// créer deux attributs pour stocker :
	// _ train sample
	// _ test sample
	// On a ensuite 2 getters pour y accéder
	int lignes = matrice_readCSV.rows;
	int colonnes = matrice_readCSV.cols;

	CvMat train_sample(spl->count);
	CvMat test_sample();

	std::vector <int> seeds;
	for (int cont = 0; cont < matrix.rows; cont++)
		seeds.push_back(cont);
	cv::randShuffle(seeds);

	cv::Mat output;
	for (int cont = 0; cont < matrix.rows; cont++)
		output.push_back(patternMatrix.row(seeds[cont]));
	return output;
}
*/


int MLData::read_csv(QString filepath){
    QString ligne,nombre;
    QFile file(filepath);
    QTextStream in(&file);
    QStringList l,liste_classes;
    int nbLignes = 0;

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    while(!in.atEnd()){
        ligne = file.readLine();
        nbLignes++;
        std::cout << ligne.toStdString() << std::endl;
        l = ligne.split(separator);



        if(nbLignes == 1)
            nb_col = l.size();

        if(!l.isEmpty())
        for(int i=0;i<l.size();i++){
            std::cout << "col " << i << " = " << l[i].toStdString() << " , ";
            if( (atof(l[i].toStdString().c_str())) == 0 && l[i].compare("0.0") != 0 && l[i].compare("0") != 0 ){
                if(!liste_classes.contains(l[i])){
                    std::cout << "Nouvelle classe :" << l[i].toStdString().c_str() << "/" << (atof(l[i].toStdString().c_str())) << " ligne : " << nbLignes << std::endl;
                    liste_classes.append(l[i]);
                }
            }
        }

        l.clear();
    }

    nbLignes = nbLignes - 1; // Retire la derniere ligne
    nb_lignes = nbLignes;

    std::cout << std::endl << " Matrice : " << nb_lignes << " x " << nb_col << std::endl;
    std::cout << std::endl << "Celle-ci contient " << liste_classes.size() << " classes : " << std::endl;
    for(int j=0;j<liste_classes.size();j++){
        std::cout << "classe " << j+1 << " : " << liste_classes[j].toStdString() << std::endl;
    }

    return 0;
}

