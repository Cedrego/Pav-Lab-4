
#ifndef INSCRIPCION_H
#define INSCRIPCION_H
#include "ICollection/interfaces/ICollectible.h"
#include "DTFecha.h"
#include "Curso.h"
#include "Estudiante.h"

class Inscripcion : public ICollectible {
	private:
		DTFecha* fechaInscr;
		bool aprovado;
		Estudiante* Estudiante;
		Curso* Curso;
	public:
		bool getAprovado;
};

#endif