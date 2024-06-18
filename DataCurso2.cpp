#include "DataCurso2.h"

/*
DataCurso2::DataCurso2(parametros){
    this->x=xDT2;
    this->y=yDT2;
    this->z=zDT2;
};
*/

DataCurso2::~DataCurso2(){};

string DataCurso2::getNomCurso(){
    return this->nomCurso;
};

DIFICULTAD DataCurso2::getDificultad(){
    return this->dificultad;

};

string DataCurso2::getDesCurso(){
    return this->desCurso;    
};

std::string DataCurso2::getNomIdioma(){
    return this->nomIdioma;
};

std::string DataCurso2::getNomProf(){
    return this->nomProf;
};

bool DataCurso2::getHabilitado(){
    return this->habilitado;
};

