

#ifndef DATACURSO2_H
#define DATACURSO2_H
#include <string>
#include "DataEjeTraduccion.h"
#include "DataEjeCompletar.h"
#include "DataInscripciones2.h"
#include "Curso.h"
#include "DataLeccion.h"
using namespace std;

class DataCurso2 {
	private:
		string nomCurso;
		DIFICULTAD dificultad;
		string desCurso;
		string nomIdioma;
		string nomProf;
		bool habilitado;
		DataLeccion* Leccion;
		DataEjeCompletar* EjeComp;
		DataEjeTraduccion* EjeTrad;
		DataInscripciones2* Inscrip;
	public:
};


#endif