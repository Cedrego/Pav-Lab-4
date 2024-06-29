
#ifndef INSCRIPCION_H
#define INSCRIPCION_H
#include "ICollection/interfaces/ICollectible.h"
#include "DTFecha.h"
class Curso;
#include "Estudiante.h"
/*
class Estudiante;

*/
class Inscripcion : public ICollectible {
	private:
		DTFecha* fechaInscr;
		bool aprovado;
		Estudiante* estudiante;
		Curso* curso;
		ICollection* ejerCompletados;
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

		//CU: Consultar Curso
		std::string devolverNomEstudiante();

		//cargar datos
		void aprobadoAutomatico(deTraducir* DT, deCompletar* DC);
		void aprobarInsc();
};

#endif