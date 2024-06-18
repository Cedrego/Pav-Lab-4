#include "deCompletar.h"

deCompletar::deCompletar(std::string fraseCDT, ICollection* faltanteDT){
    this->fraseC=fraseCDT;
    this->faltante=faltanteDT;
};

deCompletar::~deCompletar(){};

deCompletar::deCompletar(){};

string deCompletar::getfraseC(){
    return this->fraseC;
};

ICollection* deCompletar::getfaltante(){
    return faltante;
};
