#include"Inscripcion.h"

Inscripcion::Inscripcion(DTFecha* fechaInscrDT, bool aprovadoDT, Estudiante* estudianteDT, Curso* cursoDT){
    this->fechaInscr=fechaInscrDT;
    this->aprovado=aprovadoDT;
    this->estudiante=estudianteDT;
    this->curso=cursoDT;
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