#include "Idiomas.h"

Idiomas::Idiomas(std::string NomIdiomaDT){
    this->nomIdioma=NomIdiomaDT;    
};

Idiomas::Idiomas(){};

Idiomas::~Idiomas(){};

string Idiomas::getnomIdioma(){
    return this->nomIdioma;
};