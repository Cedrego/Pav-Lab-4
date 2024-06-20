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
//Agregar Leccion
Lecciones* ingresarLeccion(string NomTema, string Objetivo, Curso* c){
    //c es una instancia de Curso 
    return c->CrearLeccion(NomTema, Objetivo);

};
/*
set<std::string> Ctrl::ListarCursosNoHabilitados(){
    //Pedimos iterador de cursos a Controlador
    IIterator* itCurso=this->Cursos->getIterator();
    set<std::string> NombreC;
    while(itCurso->hasCurrent()){
        Curso* c=(Curso*)itCurso->getCurrent();
        bool Habi=c->getHabilitado();
        if(Habi==false){
            NombreC.insert(c->getNomCurso());
        }
        itCurso->next();
    }
    delete itCurso;
    return NombreC;
};
*/
Curso* Ctrl::SeleccionarCursoNoHabilitado(string nCurso){
    IKey* IKC=new String(nCurso.c_str());
    return (Curso*)this->Cursos->find(IKC);
};//OK