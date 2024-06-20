
#ifndef LECCIONES_H
#define LECCIONES_H
#include <string>
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
using namespace std;

class Lecciones : public ICollectible{
	private:
		std::string tema;
		std::string objetivo;
		IDictionary* deCompletar;
		IDictionary* deTraducir;
	public:
		Lecciones(std::string temaI, std::string objetivoI, IDictionary* deCompletarI, IDictionary* deTraducirI);
		Lecciones();
		virtual~Lecciones();
		std::string getTema();
		std::string getObjetivo();
		IDictionary* getdeCompletar();
		IDictionary* getdeTraducir();
};

#endif