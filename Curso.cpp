#include "Curso.h"

//constructor y getters
Curso::Curso(std::string nomCursoC, std::string desCursoC, DIFICULTAD dificultadC, bool habilitadoC, Idiomas* IdiomaC, Profesor* profesorC){
    this->nomCurso=nomCursoC;
    this->desCurso=desCursoC;
    this->dificultad=dificultadC;
    this->habilitado=habilitadoC;
    this->Idioma=IdiomaC;
    this->profesor=profesorC;
};

Curso::~Curso(){

};

std::string Curso::getNomCurso(){
    return this->nomCurso;
};

std::string Curso::getDesCurso(){
    return this->desCurso;
};

DIFICULTAD Curso::getDificultad(){
    return this->dificultad;
};

bool Curso::getHabilitado(){
    return this->habilitado;
};

Idiomas* Curso::getIdioma(){
    return this->Idioma;
};

Profesor* Curso::getProfesor(){
    return this->profesor;
};

ICollection* Curso::getMisPrevias(){
    return this->MisPrevias;
};

ICollection* Curso::getSoyPreviaDe(){
    return this->SoyPreviaDe;
};

ICollection* Curso::getLecciones(){
    return this->lecciones;
};
ICollection* Curso::getInscripciones(){
    return this->Inscripciones;
};
//

//CU Agregar Ejercicio

set<std::string> Curso::conseguirLecciones(){
    set<std::string> leccionesCurso;
    ICollection* listaLecciones=this->getLecciones();
    IIterator* it=listaLecciones->getIterator();
    for (it->getCurrent(); it->hasCurrent(); it->next()){
        leccionesCurso.insert(((Lecciones*)it->getCurrent())->getTema());
    };
    return leccionesCurso;
};

//CU: Habilitar Curso

void Curso::habilitar(){
    this->habilitado=true;
};

