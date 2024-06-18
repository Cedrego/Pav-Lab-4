
#ifndef DETRADUCIR_H
#define DETRADUCIR_H
#include <string>
#include "Ejercicio.h"
using namespace std;

class deTraducir : public Ejercicio{
	private:
		string fraseT;
		string traduccion;
	public:
	deTraducir(std::string fraseTDT, std::string traduccionDT);
	deTraducir();
	virtual ~deTraducir();
	std::string getfraseT();
	std::string gettraduccion();
};


#endif