
#ifndef DETRADUCIR_H
#define DETRADUCIR_H
#include <string>
#include "Ejercicio.h"
using namespace std;

class deTraduccion : public Ejercicio{
	private:
		string fraseT;
		string traduccion;
	public:
	virtual ~deTraducir();
	std::string getfraseT();
	std::string gettraduccion();
};


#endif