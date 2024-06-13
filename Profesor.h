
#ifndef PROFESOR_H
#define PROFESOR_H
#include "ICollection/interfaces/ICollection.h"

class Profesor : public Usuario{
	private:
		string instituto;
		ICollection* Idiomas;
		ICollection* Cursos;
	public:
};

#endif