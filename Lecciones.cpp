#include"Lecciones.h"

Lecciones::Lecciones(std::string temaI, std::string objetivoI, IDictionary* deCompletarI, IDictionary* deTraducirI){
    this->tema=temaI;
    this->objetivo=objetivoI;
    this->DeCompletar=deCompletarI;
    this->DeTraducir=deTraducirI;
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
    return this->DeCompletar;
};

IDictionary* Lecciones::getdeTraducir(){
    return this->DeTraducir;
};


//CU: Eliminar Curso
void Lecciones::DeleteAllEjercicios(){
    IIterator* itCompletar=(this->DeCompletar)->getIterator();
    IIterator* itTraducir=(this->DeTraducir)->getIterator();

    while(itCompletar->hasCurrent()){
        (((deCompletar*)itCompletar->getCurrent())->~deCompletar()); //REVISAR DESTROY DESPUES
        itCompletar->next();
    }
    while(itTraducir->hasCurrent()){
        (((deTraducir*)itTraducir->getCurrent())->~deTraducir()); //REVISAR DESTROY DESPUES
        itTraducir->next();
    }
};