
#ifndef DATAEJECOMPLETAR_H
#define DATAEJECOMPLETAR_H
#include <string>
#include "ICollection/interfaces/ICollection.h"
using namespace std;

class DataEjeCompletar {
	private:
		std::string nomEjercicio;
		std::string descripcion;
		std::string fraseC;
		ICollection* faltante;
	public:
		DataEjeCompletar(){};
		DataEjeCompletar(std::string nomEjercicioC, std::string descripcionC, std::string fraseCC, ICollection* faltanteC);
		virtual ~DataEjeCompletar();
		std::string getNomEjercicio();
		std::string getDescripcion();
		std::string getFraseC();
		ICollection* getFaltante();
};

#endif