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
