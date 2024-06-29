#include"Inscripcion.h"
#include "Curso.h"

Inscripcion::Inscripcion(DTFecha* fechaInscrI, bool aprovadoI, Estudiante* estudianteI, Curso* cursoI){
    this->fechaInscr=fechaInscrI;
    this->aprovado=aprovadoI;
    this->estudiante=estudianteI;
    this->curso=cursoI;
};
Inscripcion::Inscripcion(){};

Inscripcion::~Inscripcion(){};

DTFecha* Inscripcion::getfechaInscr(){
    return this->fechaInscr;
};

bool Inscripcion::getaprovado(){
    return this->aprovado;
};

Estudiante* Inscripcion::getestudiante(){
    return this->estudiante;
};

Curso* Inscripcion::getcurso(){
    return this->curso;
};

void Inscripcion::desligarEstudiante(){
    //llamo a esta funcion para que el estudiante quite la inscripcion de su diccionario
    this->estudiante->olvidarInscripcion(this);
    //dejo el puntero al estudiante en NULL
    this->estudiante=NULL;
};

//CU: Consultar Curso
std::string Inscripcion::devolverNomEstudiante(){
    return (this->estudiante)->getNombre();
};


//cargar datos
void Inscripcion::aprobadoAutomatico(deTraducir* DT, deCompletar* DC){
    if(DT!=NULL){
        this->ejerCompletados->add((ICollectible*)DT);
    } else{
        this->ejerCompletados->add((ICollectible*)DC);
    }
};
void Inscripcion::aprobarInsc(){
    this->aprovado=true;
};