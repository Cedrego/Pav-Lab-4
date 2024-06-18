#include"Profesor.h"
Profesor::Profesor(std::string institutoI, ICollection* IdiomasI, ICollection* CursosI){
    this->instituto=institutoI;
    this->Idiomas=IdiomasI;
    this->Cursos=CursosI;
};

Profesor::Profesor(){};

Profesor::~Profesor(){};

string Profesor::getinstituto(){
    return this->instituto;
};

ICollection* Profesor::getIdiomas(){
    return this->Idiomas;
};

ICollection* Profesor::getCursos(){
    return this->Cursos;
};