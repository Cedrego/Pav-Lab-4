#include "Estudiante.h"
Estudiante::Estudiante(DTFecha* fecNacDT, IDictionary* CursosDT, Lecciones* UltimaLeccionDT, ICollection* EjerciciosAprovDT){
    this->fecNac=fecNacDT;
    this->Cursos=CursosDT;
    this->UltimaLeccion=UltimaLeccionDT;
    this->EjerciciosAprov=EjerciciosAprovDT;
};

Estudiante::Estudiante(){};

Estudiante::~Estudiante(){};

DTFecha* Estudiante::getfecNac(){
    return this->fecNac;
};

IDictionary* Estudiante::getCursos(){
    return this->Cursos;
};

Lecciones* Estudiante::getUltimaLeccion(){
    return this->UltimaLeccion;
};

ICollection* Estudiante::getEjerciciosAprov(){
    return this->EjerciciosAprov;
};