
#ifndef EJERCICIO_H
#define EJERCICIO_H
#include <string>
#include "ICollection/interfaces/ICollectible.h"
using namespace std;

class Ejercicio : public ICollectible{
	protected:
		string nomEjercicio;
		string descripcion;
	public:
	Ejercicio(std::string nomEjercicioDT, std::string descripcionDT);
	Ejercicio();
	virtual ~Ejercicio();
	std::string getnomEjercicio();
	std::string getdescripcion();
};

#endif