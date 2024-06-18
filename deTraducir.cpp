#include "deTraducir.h"

deTraducir::deTraducir(std::string fraseTDT, std::string traduccionDT){
    this->fraseT=fraseTDT;
    this->traduccion=traduccionDT;
};

deTraducir::deTraducir(){};

deTraducir::~deTraducir(){};

string deTraducir::getfraseT(){
    return this->fraseT;
};

string deTraducir::gettraduccion(){
    return this->traduccion;
};