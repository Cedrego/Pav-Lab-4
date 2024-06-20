#include "Ctrl.h"
#include <string>
using namespace std;

Ctrl* Ctrl::instance = nullptr;

ICtrl* Ctrl::getInstance() {
    if (!instance) {
	    instance = new Ctrl();
    }
    return instance;
};

Ctrl::Ctrl() {};
Ctrl::~Ctrl() {};

IDictionary* Ctrl::getCursos(){
    return this->Cursos;
}

IDictionary* Ctrl::getProfesores(){
    return this->Profesores;
};


//CU: Alta de Curso
set<std::string> Ctrl::ListarProfesores(){
    //lista de strings
    set<std::string> Profesores;
    //consigo los profesores del ctrl
    IDictionary* profesoresCtrl=this->getProfesores();
    //consigo un iterador
    IIterator* it=profesoresCtrl->getIterator();

    //itero
    while(it->hasCurrent()){
        //casteo el iterador a profesor por cada instancia y guardo el nickname en la lista
        Profesores.insert(((Profesor*)it->getCurrent())->getNickname());
    };
    //saco la basura
    delete it;
    delete profesoresCtrl;
    //retorno la lista
    return Profesores;
};

Curso* Ctrl::IngresoCurso(std::string nickP , std::string nomCurso, std::string descCurso, DIFICULTAD difCurso){
    //consigo los profesores
    IDictionary* profesoresCtrl=this->getProfesores();
    //hago una IKey
    IKey* KeyProf = new String(nickP.c_str);
    //busco el profesor especifico
    Profesor * prof = (Profesor*)(profesoresCtrl->find(KeyProf));
    //creo un curso nuevo con los datos ingresados y el profesor encontrado, no tengo idioma asi que es NULL
    Curso* cursoNuevo = new Curso::Curso(nomCurso, descCurso, difCurso, false, NULL, prof);
    //llamo esta funcion para agregar el curso a la coleccion de cursos del profesor
    prof->asignarCursoAProfesor(cursoNuevo);
    //retorno el curso creado para usarlo en otras operaciones
    return cursoNuevo;
};

//CU: Agregar Ejercicio
set<std::string> Ctrl::ListarCursosNoHabilitados(){
    //creo una lista de strings para retornar
    set<std::string> CursosNH;
    //consigo todos los Cursos en el Ctrl
    IDictionary* cursosTotal=this->getCursos();
    //y consigo un iterador en base a eso
    IIterator* it=cursosTotal->getIterator();
    
    //itero dentro del diccionario
    while(it->hasCurrent()){; 
        //casteo el iterador a Curso y pregunto si esta habilitado
        bool estaHabilitado=((Curso*)it->getCurrent())->getHabilitado();
        //si no esta habilitado, lo agrego a la lista
        if(!estaHabilitado){
            CursosNH.insert(((Curso*)it->getCurrent())->getNomCurso());
        };
        it->next();
    };
    //borro el iterador y el diccionario
    delete it;
    delete cursosTotal;
    //retorno la lista
    return CursosNH;
};

set<std::string> Ctrl::listarLecciones(std::string nCurso){
    //creo una lista para retornar
    set<std::string> Lecciones;
    //guardo el diccionario de los cursos del ctrl
    IDictionary* Cursos=this->getCursos();
    //declaro su IKey
    IKey* KeyCurso=new String(nCurso.c_str());
    //busco el curso mediante la IKey 
    Curso* curso=(Curso*)(Cursos->find(KeyCurso));
    //llamo a conseguirLecciones() y guardo su resultado en Lecciones
    Lecciones=curso->conseguirLecciones();

    //borro lo que no es necesario
    delete curso;
    delete Cursos;

    //retorno la lista
    return Lecciones;
}; 

//CU: Habilitar Curso
void Ctrl::HabilitarCurso(std::string nCurso){
    //guardo el diccionario de los cursos del ctrl
    IDictionary* Cursos=this->getCursos();
    //declaro su IKey
    IKey* KeyCurso=new String(nCurso.c_str());
    //busco el curso mediante la IKey 
    Curso* curso=(Curso*)(Cursos->find(KeyCurso));
    //llamo a habilitar
    curso->habilitar();
    //borro lo que sobra
    delete Cursos;
    delete curso;
};