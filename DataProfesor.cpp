#include"DataProfesor.h"

DataProfesor::DataProfesor(std::string institutoDT, std::string nomIdiomaDT){
    this->instituto=institutoDT;
    this->nomIdioma=nomIdiomaDT;
};

DataProfesor::DataProfesor(){};

DataProfesor::~DataProfesor(){};

string DataProfesor::getinstituto(){
    return this->instituto;
};

string DataProfesor::getnomIdioma(){
    return this->nomIdioma;
};