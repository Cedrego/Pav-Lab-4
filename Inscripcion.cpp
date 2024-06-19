#include"Inscripcion.h"

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