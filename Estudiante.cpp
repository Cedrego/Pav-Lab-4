#include "Estudiante.h"
Estudiante::Estudiante(DTFecha* fecNacI, IDictionary* CursosI, Lecciones* UltimaLeccionI, ICollection* EjerciciosAprovI){
    this->fecNac=fecNacI;
    this->Cursos=CursosI;
    this->UltimaLeccion=UltimaLeccionI;
    this->EjerciciosAprov=EjerciciosAprovI;
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