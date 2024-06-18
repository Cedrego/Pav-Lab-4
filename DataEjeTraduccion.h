
#ifndef DATAEJETRADUCCION_H
#define DATAEJETRADUCCION_H
#include <string>
using namespace std;

class DataEjeTraduccion {
	private:
		std::string nomEjercicio;
		std::string descripcion;
		std::string fraseT;
		std::string traduccion;
	public:
	DataEjeTraduccion(){};
	
		virtual ~DataEjeTraduccion;
		std::string getNomEjercicio;
		string getDescripcion;
		string getFraseT;
		string getTraduccion;
};

#endif