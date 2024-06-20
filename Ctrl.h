#ifndef CTRL_H
#define CTRL_H
#include "ICtrl.h"
#include "Curso.h"
#include <string>
#include <set>
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/OrderedKey.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/String.h"
#include "ICollection/Integer.h"
using namespace std;

class Ctrl: public ICtrl{
    private:
        Ctrl();
        static Ctrl* instance;
        IDictionary* Cursos;
    public:
        
        static ICtrl* getInstance();
        virtual ~Ctrl();
        IDictionary* getCursos();
        //CU: Agregar Ejercicio
        set<std::string> listarLecciones(std::string nCurso); 

        //Agregar Leccion
        Lecciones* ingresarLeccion(std::string NomTema, std::string Objetivo);//OK
        //set<std::string> ListarCursosNoHabilitados();//OK de Enzo
        Curso* SeleccionarCursoNoHabilitado(std::string nCurso);//OK
};

#endif