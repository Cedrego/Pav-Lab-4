
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "DTFecha.h"
#include "Usuario.h"
#include "Lecciones.h"
#include "Curso.h"
#include "Inscripcion.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/OrderedKey.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/String.h"
#include "ICollection/Integer.h"

class Estudiante : public Usuario {
    private:
        DTFecha* fecNac;
        std::string Pais;
        IDictionary* Inscripciones; //la clave es el nomCurso
        Lecciones* UltimaLeccion;
        ICollection* EjerciciosAprov;
    public:
        Estudiante(std::string nicknameE, std::string descripcionE, std::string nombreE, std::string contraseniaE, DTFecha* fecNacE, std::string PaisE);
        Estudiante();
        virtual ~Estudiante();
        DTFecha* getfecNac();
        std::string getPais();
        IDictionary* getInscripciones();
        Lecciones* getUltimaLeccion();
        ICollection* getEjerciciosAprov();

        //CU: Eliminar Curso
        void olvidarInscripcion(Inscripcion* insc);
};

#endif