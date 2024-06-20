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


//CU: Alta de Curso
void Profesor::asignarCursoAProfesor(Curso* cursoNuevo){
    this->Cursos.add(cursoNuevo); //Si queda en ICollection
    
    //IKey* KeyCurso = new String((cursoNuevo->getNomCurso()).c_str()); //si lo cambio a IDictionary
    //this->Cursos.add(KeyCurso,cursoNuevo);
};