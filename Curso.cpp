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
    set<std::string> listaLecciones;

    for (Lecciones *leccion; this->lecciones){
        
    };

};

//CU: Habilitar Curso

void Curso::habilitar(){
    this->habilitado=true;
};

//Agregar Leccion
Lecciones* Curso::CrearLeccion(string NomTema, string Objetivo){
    //Creamos la leccion
   Lecciones* leccion=new Lecciones( NomTema, Objetivo,NULL,NULL);
   //La leccion creada se agrega a la coleccion
    this->lecciones->add((ICollectible*) leccion);
};