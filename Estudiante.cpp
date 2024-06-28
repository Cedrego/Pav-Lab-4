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
};

//CU: Consultar Estadistica
set<DataCursoE*>Estudiante::cursosEstudiante(){
    IIterator* iti = this->Inscripciones->getIterator();
    set<DataCursoE*> DTCE;
    while(iti->hasCurrent()){
        float PCurso = ((Inscripcion*)iti->getCurrent())->getPromedio();
        string NCurso =(((Inscripcion*)iti->getCurrent())->getcurso())->getNomCurso();
        DTCE.insert(new DataCursoE(NCurso,PCurso));
    }
    delete iti;
    return DTCE;
}

//CU:Realizar Ejercicio
//Inscripcion*Estudiante::EncontrarInscripcion(std::string nCurso){
//    return (Inscripcion*)this->Inscripciones->find(new String(nCurso));
//};
set<std::string>Estudiante::PlantearProblemaE(std::string nomEjercicio, std::string nCurso){
    return ((Inscripcion*)this->Inscripciones->find(new String(nCurso.c_str())))->PlantearProblemaI(nomEjercicio);
};

bool Estudiante::IngresarSolucionE(std::string solucionDeUsuario,std::string nomEjercicio, std::string nCurso){
    return ((Inscripcion*)this->Inscripciones->find(new String(nCurso.c_str())))->IngresarSolucionI(solucionDeUsuario,nomEjercicio);
};