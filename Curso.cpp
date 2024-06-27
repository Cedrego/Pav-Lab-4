#include "Curso.h"
#include "Profesor.h"

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
IDictionary* Curso::getInscripciones(){
    return this->Inscripciones;
};

//CU: Alta de Curso
void Curso::asignarIdiomaACurso(Idiomas* I){
    this->Idioma=I;
};

void Curso::esPrevia (Curso* CursoPrevia){
    (this->MisPrevias)->add((ICollectible*)CursoPrevia);
};

void Curso::miPrevia (Curso* CursoNuevo){
    (this->SoyPreviaDe)->add((ICollectible*)CursoNuevo);
};


//CU: Eliminar Curso
void Curso::DeleteALLforCurso(){
    IIterator* itLecciones=(this->lecciones)->getIterator();
    while(itLecciones->hasCurrent()){
        (((Lecciones*)itLecciones->getCurrent())->DeleteAllEjercicios());
        itLecciones->next();
    }
    
    IIterator* itInscripciones=(this->Inscripciones)->getIterator();
    while(itInscripciones->hasCurrent()){
        (((Inscripcion*)itInscripciones->getCurrent())->desligarEstudiante());
        itInscripciones->next();
    }
    //CONTINUAR
};


//CU Agregar Ejercicio

set<std::string> Curso::conseguirLecciones(){
    set<std::string> leccionesCurso;
    ICollection* listaLecciones=this->getLecciones();
    IIterator* it=listaLecciones->getIterator();
    while(it->hasCurrent()){
        leccionesCurso.insert(((Lecciones*)it->getCurrent())->getTema());
        it->next();
    };
    return leccionesCurso;
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
    return leccion;
};//OK
void Curso::AgregarEjercicio(std::string NomEj, std::string tipo,std::string desc,std::string frase,std::string solucion, Lecciones* leccionNH){
    leccionNH->CrearEjer(NomEj,tipo,desc,frase,solucion);
};//OK

//CU: Inscribirse Curse
set<std::string> Curso::DamePrevias(){
    set<std::string> Previas;
    IIterator* itMP=(this->MisPrevias)->getIterator();
    while(itMP->hasCurrent()){
        //Inserto en el set Previas los nombres de los cursos en la coleccion de MisPrevias
        Previas.insert(((Curso*)itMP->getCurrent())->getNomCurso());
        itMP->next();
    }
    return Previas;
};
