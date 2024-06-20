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