
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
		Estudiante* estudiante;
		Curso* curso;
	public:
		Inscripcion(DTFecha* fechaInscrI, bool aprovadoI, Estudiante* estudianteI, Curso* cursoI);
		Inscripcion();
		virtual~Inscripcion();
		DTFecha* getfechaInscr();
		bool getaprovado();
		Estudiante* getestudiante();
		Curso* getcurso();
		
		//CU: Eliminar Curso
		void desligarEstudiante();
};

#endif