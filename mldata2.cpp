#include "mldata.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <boost/lexical_cast.hpp>

using boost::lexical_cast;
using boost::bad_lexical_cast;

MLData::MLData()
{
    this->col_resp = 0;
    this->separator=',';
    this->valeurs = NULL;
}

MLData::~MLData(){
    if(valeurs != NULL) delete valeurs;
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
