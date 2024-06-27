
#ifndef INSCRIPCION_H
#define INSCRIPCION_H
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
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
		ICollection* EjerCompletados;
	public:
		Inscripcion(DTFecha* fechaInscrI, bool aprovadoI, Estudiante* estudianteI, Curso* cursoI);
		Inscripcion();
		virtual~Inscripcion();
		
		//getters
		DTFecha* getfechaInscr();
		bool getaprovado();
		Estudiante* getestudiante();
		Curso* getcurso();
		
		//CU: Eliminar Curso
		void desligarEstudiante();
		//CU: Inscribirse Curso
		bool verificarInscripcion(std::string NomCurso);

		//CU: Consultar Estadisticas
		float getPromedio();
};	

#endif