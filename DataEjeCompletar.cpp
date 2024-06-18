#include "DataEjeCompletar.h"

DataEjeCompletar::DataEjeCompletar(std::string nomEjercicioC, std::string descripcionC, std::string fraseCC, ICollection* faltanteC){
    this->nomEjercicio=nomEjercicioC;
    this->descripcion=descripcionC;
    this->fraseC=fraseCC;
    this->faltante=faltanteC;
};
DataEjeCompletar::~DataEjeCompletar(){

};

std::string DataEjeCompletar::getNomEjercicio(){
    return this->nomEjercicio;
};

std::string DataEjeCompletar::getDescripcion(){
    return this->descripcion;
};

std::string DataEjeCompletar::getFraseC(){
    return this->fraseC;
};

ICollection* DataEjeCompletar::getFaltante(){
    return this->faltante;
};