#ifndef CTRL_H
#define CTRL_H
#include "ICtrl.h"
#include "Lecciones.h"
#include "Curso.h"
#include <string>
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
        ICollection* Cursos;
    public:
        
        static ICtrl* getInstance();
        virtual ~Ctrl();
        //Agregar Leccion
        Lecciones* ingresarLeccion(string NomTema, string Objetivo, Curso* c);
        set<std::string> ListarCursosNoHabilitados();
};

#endif