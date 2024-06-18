#include "Idiomas.h"

Idiomas::Idiomas(std::string NomIdiomaI){
    this->nomIdioma=NomIdiomaI;    
};

Idiomas::Idiomas(){};

Idiomas::~Idiomas(){};

string Idiomas::getnomIdioma(){
    return this->nomIdioma;
};