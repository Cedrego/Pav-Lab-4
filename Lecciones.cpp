#include"Lecciones.h"

Lecciones::Lecciones(std::string temaI, std::string objetivoI, IDictionary* deCompletarI, IDictionary* deTraducirI){
    this->tema=temaI;
    this->objetivo=objetivoI;
    this->deCompletar=deCompletarI;
    this->deTraducir=deTraducirI;
};

Lecciones::Lecciones(){};

Lecciones::~Lecciones(){};

string Lecciones::getTema(){
    return this->tema;
};

string Lecciones::getObjetivo(){
    return this->objetivo;
};

IDictionary* Lecciones::getdeCompletar(){
    return this->deCompletar;
};

IDictionary* Lecciones::getdeTraducir(){
    return this->deTraducir;
};