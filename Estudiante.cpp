#include "Estudiante.h"
#include "Inscripcion.h"
#include "Curso.h"

Estudiante::Estudiante(string nicknameE, string descripcionE, string nombreE, string contraseniaE, DTFecha* fecNacE, std::string PaisE){
    this->nickname=nicknameE;
    this->descripcion=descripcionE;
    this->nombre=nombreE;
    this->contrasenia=contraseniaE;
    this->fecNac=fecNacE;
    this->Pais=PaisE;
    this->Inscripciones=NULL;
    this->UltimaLeccion=NULL;
    this->EjerciciosAprov=NULL;
};

Estudiante::Estudiante(){};

Estudiante::~Estudiante(){};

DTFecha* Estudiante::getfecNac(){
    return this->fecNac;
};

std::string Estudiante::getPais(){
    return this->Pais;
};

IDictionary* Estudiante::getInscripciones(){
    return this->Inscripciones;
};

Lecciones* Estudiante::getUltimaLeccion(){
    return this->UltimaLeccion;
};

ICollection* Estudiante::getEjerciciosAprov(){
    return this->EjerciciosAprov;
};


//CU: Eliminar Curso
void Estudiante::olvidarInscripcion(Inscripcion* insc){
    //consigo key de la inscripcion
    IKey* keyInsc = new String((insc->getcurso())->getNomCurso().c_str());
    //la remuevo de la coleccion
    this->Inscripciones->remove(keyInsc);

    delete keyInsc;
};



//cargar datos
void Estudiante::aniadirInscripcion(Inscripcion* insc){
    //consigo key de la inscripcion
    IKey* keyInsc = new String((insc->getcurso())->getNomCurso().c_str());
    //la aniado a la coleccion
    this->Inscripciones->add(keyInsc, (ICollectible*)insc);

    delete keyInsc;
};