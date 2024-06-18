#include"DataLeccion.h"
DataLeccion::DataLeccion(std::string temaDT, std::string objetivoDT){
    this->tema=temaDT;
    this->objetivo=objetivoDT;
};

DataLeccion::DataLeccion(){};

DataLeccion::~DataLeccion(){};

string DataLeccion::gettema(){
    return this->tema;
};

string DataLeccion::getobjetivo(){
    return this->objetivo;
};