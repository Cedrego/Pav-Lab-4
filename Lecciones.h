
#ifndef LECCIONES_H
#define LECCIONES_H
#include <string>
#include "deCompletar.h"
#include "deTraducir.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
using namespace std;

class Lecciones : public ICollectible{
	private:
		std::string tema;
		std::string objetivo;
		IDictionary* DeCompletar;
		IDictionary* DeTraducir;
	public:
		Lecciones(std::string temaI, std::string objetivoI, IDictionary* deCompletarI, IDictionary* deTraducirI);
		Lecciones();
		virtual~Lecciones();
		std::string getTema();
		std::string getObjetivo();
		IDictionary* getdeCompletar();
		IDictionary* getdeTraducir();

		//CU: Eliminar Curso
		void DeleteAllEjercicios();
};

#endif