
#ifndef PROFESOR_H
#define PROFESOR_H
#include "ICollection/interfaces/ICollection.h"
#include "Usuario.h"

class Profesor : public Usuario{
	private:
		string instituto;
		ICollection* Idiomas;
		ICollection* Cursos;
	public:
	Profesor(std::string institutoI, ICollection* IdiomasI, ICollection* CursosI);
	Profesor();
	virtual ~Profesor();
	std::string getinstituto();
	ICollection* getIdiomas();
	ICollection* getCursos();
};

#endif