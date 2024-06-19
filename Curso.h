
#ifndef DIFICULTAD_H
#define DIFICULTAD_H

enum DIFICULTAD{
	principiante,medio,avanzado
};

#endif

#ifndef CURSO_H
#define CURSO_H
#include "Lecciones.h"
#include "Idiomas.h"
#include "Profesor.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include <string>
using namespace std;

class Curso : public ICollectible{
	private:
		string nomCurso;
		string desCurso;
		DIFICULTAD dificultad;
		bool habilitado;
		Idiomas* Idioma;
		Profesor* Profesor;
		ICollection* MisPrevias;
		ICollection* SoyPreviaDe;
		ICollection* Lecciones;
		ICollection* Inscripciones;
	public:
};

#endif

