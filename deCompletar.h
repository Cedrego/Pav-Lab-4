
#ifndef DECOMPLETAR_H
#define DECOMPLETAR_H
#include <string>
#include <set>
#include "ICollection/interfaces/ICollection.h"
#include "Ejercicio.h"
using namespace std;

class deCompletar : public Ejercicio{
	private:
		string fraseC;
		set<std::string> faltante;
	public:
	deCompletar(std::string fraseCI, ICollection* faltanteI);
	deCompletar();
	virtual ~deCompletar();
	std::string getfraseC();
	ICollection* getfaltante();
};

#endif