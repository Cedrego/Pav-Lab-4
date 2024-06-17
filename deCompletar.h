
#ifndef DECOMPLETAR_H
#define DECOMPLETAR_H
#include <string>
#include "ICollection/interfaces/ICollection.h"
#include "Ejercicio.h"
using namespace std;

class deCompletar : public Ejercicio{
	private:
		string fraseC;
		ICollection* faltante;
	public:
	virtual ~deCompletar();
	std::string getfraseC();
	ICollection* getfaltante();
};

#endif