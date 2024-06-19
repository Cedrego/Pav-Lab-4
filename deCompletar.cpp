#include "deCompletar.h"

deCompletar::deCompletar(std::string fraseCI, ICollection* faltanteI){
    this->fraseC=fraseCI;
    this->faltante=faltanteI;
};

deCompletar::~deCompletar(){};

deCompletar::deCompletar(){};

string deCompletar::getfraseC(){
    return this->fraseC;
};

ICollection* deCompletar::getfaltante(){
    return faltante;
};
