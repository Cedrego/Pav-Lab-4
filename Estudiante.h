
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "DTFecha.h"
#include "Usuario.h"
#include "Lecciones.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollection.h"

class Estudiante : public Usuario {
    private:
        DTFecha* fecNac;
        IDictionary* Cursos; //Son Inscripciones con la clave siendo el nomCurso
        Lecciones* UltimaLeccion;
        ICollection* EjerciciosAprov;
    public:
    Estudiante(DTFecha* fecNacDT, IDictionary* CursosDT, Lecciones* UltimaLeccionDT, ICollection* EjerciciosAprovDT);
    Estudiante();
    virtual ~Estudiante();
    DTFecha* getfecNac();
    IDictionary* getCursos();
    Lecciones* getUltimaLeccion();
    ICollection* getEjerciciosAprov();
};

#endif