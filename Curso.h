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
		std::string nomCurso;
		std::string desCurso;
		DIFICULTAD dificultad;
		bool habilitado;
		Idiomas* Idioma;
		Profesor* profesor;
		ICollection* MisPrevias;
		ICollection* SoyPreviaDe;
		ICollection* Lecciones;
		ICollection* Inscripciones;
	public:
		//constructores y getters
		Curso(){};
		Curso(std::string nomCursoC, std::string desCursoC, DIFICULTAD dificultadC, bool habilitadoC, Idiomas* IdiomaC, Profesor* profesorC);
		virtual ~Curso();
		std::string getNomCurso();
		std::string getDesCurso();
		DIFICULTAD getDificultad();
		bool getHabilitado();
		Idiomas* getIdioma();
		Profesor* getProfesor();
		ICollection* getMisPrevias();
		ICollection* getSoyPreviaDe();
		ICollection* getLecciones();
		ICollection* getInscripciones();
		//

};

#endif

