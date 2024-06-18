#include"DataLeccion.h"
DataLeccion::DataLeccion(std::string temaI, std::string objetivoI){
    this->tema=temaI;
    this->objetivo=objetivoI;
};

DataLeccion::DataLeccion(){};

DataLeccion::~DataLeccion(){};

string DataLeccion::gettema(){
    return this->tema;
};

string DataLeccion::getobjetivo(){
    return this->objetivo;
};