#include"Profesor.h"
#include "Idiomas.h"

Profesor::Profesor(std::string institutoI, ICollection* IdiomasI, ICollection* CursosI){
    this->instituto=institutoI;
    this->idiomas=IdiomasI;
    this->cursos=CursosI;
};

Profesor::Profesor(){};

Profesor::~Profesor(){};

string Profesor::getinstituto(){
    return this->instituto;
};

ICollection* Profesor::getIdiomas(){
    return this->idiomas;
};

ICollection* Profesor::getCursos(){
    return this->cursos;
};


//CU: Alta de Curso
void Profesor::asignarCursoAProfesor(Curso* cursoNuevo){
    (this->cursos)->add((ICollectible*)cursoNuevo); //Si queda en ICollection
    
    //IKey* KeyCurso = new String((cursoNuevo->getNomCurso()).c_str()); //si lo cambio a IDictionary
    //this->Cursos.add(KeyCurso,cursoNuevo);
};

set<std::string> Profesor::buscarIdioma(Profesor* prof){
    set<std::string> idiomas; 
    IIterator* it=(prof->getIdiomas())->getIterator();
    while (it->hasCurrent()){
        idiomas.insert(((Idiomas*)it->getCurrent())->getNomIdioma());
        it->next();
    }
    return idiomas;
};