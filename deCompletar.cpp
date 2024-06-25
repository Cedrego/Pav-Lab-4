#include "deCompletar.h"

deCompletar::deCompletar(std::string NomEj,std::string desc,std::string fraseCI, set<std::string> faltanteI){
    this->nomEjercicio=NomEj;
    this->descripcion=desc;
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
