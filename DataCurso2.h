

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
		std::string nomCurso;
		DIFICULTAD dificultad;
		std::string desCurso;
		std::string nomIdioma;
		std::string nomProf;
		bool habilitado;
		DataLeccion* Leccion;
		DataEjeCompletar* EjeComp;
		DataEjeTraduccion* EjeTrad;
		DataInscripciones2* Inscrip;
	public:
		DataCurso2(){};
		//constructor con parametros
		virtual ~DataCurso2();
		std::string getNomCurso();
		DIFICULTAD getDificultad();
		std::string getDesCurso();
		std::string getNomIdioma();
		std::string getNomProf();
		bool getHabilitado();
};


#endif