#include"DataLeccion.h"
DataLeccion::DataLeccion(std::string temaDT, std::string objetivoDT, set<DataEjeCompletar*> DataEjeCompDT, set<DataEjeTraduccion*> DataEjeTradDT){
    this->tema=temaDT;
    this->objetivo=objetivoDT;
    this->DataEjeComp=DataEjeCompDT;
    this->DataEjeTrad=DataEjeCompDT;
}

DataLeccion::DataLeccion(){};

DataLeccion::~DataLeccion(){};

string DataLeccion::gettema(){
    return this->tema;
};

string DataLeccion::getobjetivo(){
    return this->objetivo;
};