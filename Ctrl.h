#ifndef CTRL_H
#define CTRL_H
#include "ICtrl.h"
#include "Curso.h"
#include "Profesor.h"
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
        IDictionary* Profesores;
    public:
        
        static ICtrl* getInstance();
        virtual ~Ctrl();
        IDictionary* getCursos();
        IDictionary* getProfesores();

        //CU: Alta de Curso
        set<std::string> ListarProfesores();
        Curso* IngresoCurso(std::string nickP , std::string nomCurso, std::string descCurso, DIFICULTAD difCurso);

        //CU: Agregar Ejercicio
        set<std::string> ListarCursosNoHabilitados();
        set<std::string> listarLecciones(std::string nCurso); 

        //CU: Habilitar Curso
        void HabilitarCurso(std::string nCurso);
};

#endif