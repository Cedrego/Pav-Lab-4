
#ifndef PROFESOR_H
#define PROFESOR_H
#include "ICollection/interfaces/ICollection.h"
#include"Usuario.h"
#include "Curso.h"
#include <set>
class Profesor : public Usuario{
	private:
		string instituto;
		ICollection* idiomas;
		ICollection* cursos; //IDictionary?
	public:
	Profesor(std::string institutoI, ICollection* IdiomasI, ICollection* CursosI); //IDictionary curso?
	Profesor();
	virtual ~Profesor();
	std::string getinstituto();
	ICollection* getIdiomas();
	ICollection* getCursos();//IDictionary?

	//CU: Alta de Curso
	void asignarCursoAProfesor(Curso* cursoNuevo);
	set<std::string> buscarIdioma(Profesor* prof);
};

#endif