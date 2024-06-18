#include "DataCursoP.h"


DataCursoP::DataCursoP(std::string NomCursoPDT, float PromDT){
    this->nomCurso=NomCursoPDTP;
    this->Prom=PromDTP;
};

DataCursoP::~DataCursoP(){};

std::string DataCursoP::getNomCurso(){
    return this->NomCursoP;
};

float DataCursoP::getProm(){
    return this->Prom;
};