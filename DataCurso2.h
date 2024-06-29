

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
		set<DataLeccion*> Leccion;
		set<DataEjeCompletar*> EjeComp;
		set<DataEjeTraduccion*> EjeTrad;
		set<DataInscripciones2*> Inscrip;
	public:
		DataCurso2(){};
		DataCurso2(std::string nomCursoDT, DIFICULTAD dificultadDT, std::string desCursoDT,std::string nomIdiomaDT, std::string nomProfDT, bool habilitadoDT, DataLeccion* LeccionDT, DataEjeCompletar* EjeCompDT, DataEjeTraduccion* EjeTradDT, DataInscripciones2* InscripDT);
		virtual ~DataCurso2();
		std::string getNomCurso();
		DIFICULTAD getDificultad();
		std::string getDesCurso();
		std::string getNomIdioma();
		std::string getNomProf();
		bool getHabilitado();
};


#endif