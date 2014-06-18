#include "mldata.h"
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QStringList>
#include <boost/lexical_cast.hpp>
#include <traintestsplit.h>

using boost::lexical_cast;
using boost::bad_lexical_cast;

MLData::MLData()
{
    this->col_resp = 0;
    this->separator=',';
    this->valeurs = NULL;
    this->responses = NULL;
    this->train_sample = NULL;
    this->test_sample = NULL;
}

MLData::~MLData(){
    if (valeurs != NULL) delete(valeurs);
    if (responses != NULL) delete(responses);
    if (train_sample != NULL) delete(train_sample);
    if (test_sample != NULL) delete(test_sample);
}

//set_response_idx
int MLData::set_response_idx(int val) {
	col_resp = val;
	return 0;
}

//get_values
const cv::Mat* MLData::get_values(void) {
    return valeurs;
}

//get reponses
const cv::Mat* MLData::get_responses(void) {
    // matrice colonne qui contient les classes
    responses = new cv::Mat(valeurs->rows, 1, CV_32FC1);

    for (int i=0; i<valeurs->rows; ++i) {
        responses->at<float>(i, 0) =valeurs->at<float>(i, col_resp);
    }
    return responses;
}


//set_train_test_split
void MLData::set_train_test_split(const struct TrainTestSplit * spl) {

    int train_count = spl->train_sample_part.count;

    train_sample = new cv::Mat(train_count, valeurs->cols, CV_32FC1);
    test_sample = new cv::Mat((valeurs->rows - train_count), valeurs->cols, CV_32FC1);

	// si mix est true, mélanger la matrice valeurs puis remplir train_sample et test_sample
	if (spl->mix == true) {

		// traitement du train_sample
        std::vector<int> seeds;
        for (int i=0; i < valeurs->rows; ++i)
            seeds.push_back(i);
        cv::randShuffle(seeds);

        for (int i=0; i < train_count; ++i)
            train_sample->row(i) = valeurs->row(seeds[i]);

        for (int i=train_count; i < valeurs->rows; ++i)
            test_sample->row(i - train_count) = valeurs->row(seeds[i]);
		
	// sinon, remplir sans mélanger
	} else { 

		for (int i=0; i < valeurs->rows; ++i) {
                if (i < train_count)
					train_sample->row(i) = valeurs->row(i);
				else
					test_sample->row(i) = valeurs->row(i);
        }
			
    }
}

//get_train_sample
const cv::Mat* MLData::get_train_sample_idx(void) {
    return train_sample;
}

//get_test_sample_idx
const cv::Mat* MLData::get_test_sample_idx(void) {
    return test_sample;
}


int MLData::read_csv(QString filepath){
    QString ligne,nombre;
    QFile file(filepath);
    QTextStream in(&file);
    QStringList l,l2,liste_classes;

    std::vector< std::vector< double > > mat;

    double val;
    int nbLignes = 0;

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    while(!in.atEnd()){
        ligne = file.readLine();
        nbLignes++;
        //Bstd::cout << ligne.toStdString() << std::endl;
        l2 = ligne.split('\n',QString::SkipEmptyParts);

        if (!l2.isEmpty())
            l = l2.at(0).split(separator,QString::SkipEmptyParts);


        if(nbLignes == 1)
            nb_col = l.size();

        std::vector< double> ligne(nb_col,0);

        if(!l.isEmpty() && l.size() == nb_col){
                for(int i=0;i<l.size();i++){
                    try{
                        val = lexical_cast<double>(l[i].toStdString());
                    }
                    catch(bad_lexical_cast &){
                        try{
                            val = lexical_cast<int>(l[i].toStdString());
                        }
                        catch(bad_lexical_cast &){
                               val = 0;
                        }
                    }

                    //std::cout << "col " << i << " = " << l[i].toStdString() << " / " << val << " , ";
                    if( val == 0 && l[i].compare("0.0") != 0 && l[i].compare("0") != 0 && l[i].compare("0.00") != 0){
                        if(!liste_classes.contains(l[i])){
                            //std::cout << "Nouvelle classe : " << l[i].toStdString() << " / " << (strtod(l[i].toStdString().c_str(),NULL)) << " / " << val  << " | ligne : " << nbLignes << std::endl;
                            liste_classes.append(l[i]);
                        }
                        ligne[i] = liste_classes.indexOf(l[i]) + 1;
                    }
                    else{
                        ligne[i] = val;
                    }
                }
        }
        mat.push_back(ligne);
        ligne.clear();
        l.clear();
    }

    nbLignes = nbLignes - 1; // Retire la derniere ligne
    nb_lignes = nbLignes;

    valeurs = new cv::Mat(nb_lignes,nb_col,CV_32FC1);
    for(int i=0;i<valeurs->rows;i++){
        for(int j=0;j<valeurs->cols;j++){
            valeurs->at<float>(i,j) = mat[i][j];
        }
    }

    std::cout << std::endl << " Matrice : " << nb_lignes << " x " << nb_col << std::endl;
    std::cout << std::endl << "Celle-ci contient " << liste_classes.size() << " classes : " << std::endl;
    std::cout << *valeurs << std::endl;

    std::map<std::string,int>::iterator it = correspondances.begin();
    for(int j=0;j<liste_classes.size();j++){
        std::cout << "classe " << j+1 << " : " << liste_classes[j].toStdString() << std::endl;
        correspondances.insert(it,std::pair<std::string,int>(liste_classes[j].toStdString(),j+1));
    }

    return 0;
}
