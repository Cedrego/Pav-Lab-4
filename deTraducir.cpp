#include "deTraducir.h"

deTraducir::deTraducir(std::string fraseTI, std::string traduccionI){
    this->fraseT=fraseTI;
    this->traduccion=traduccionI;
};

deTraducir::deTraducir(){};

deTraducir::~deTraducir(){};

string deTraducir::getfraseT(){
    return this->fraseT;
};

string deTraducir::gettraduccion(){
    return this->traduccion;
};