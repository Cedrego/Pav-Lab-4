# Makefile para laboratorio 4: Brun, Cedrés, Da Costa, Molina, Nuñez
# ###Variables####
CC= g++
CFLAGS = -Wall -g

# ###Ejecutable###

main: DataCursoE.o DataCursoP.o DataCurso3.o DataCurso2.o DataCurso.o DataInscripciones2.o DataEjeTraduccion.o DataEjeCompletar.o DataLeccion.o DataEst.o DataProfesor.o DataUsuario.o DTFecha.o Inscripcion.o Idiomas.o deTraducir.o deCompletar.o Ejercicio.o Lecciones.o Curso.o Estudiante.o Profesor.o Usuario.o Ctrl.o Factory.o main.o
	$(CC) $(CFLAGS) DataCursoE.o DataCursoP.o DataCurso3.o DataCurso2.o DataCurso.o DataInscripciones2.o DataEjeTraduccion.o DataEjeCompletar.o DataLeccion.o DataEst.o DataProfesor.o DataUsuario.o DTFecha.o Inscripcion.o Idiomas.o deTraducir.o deCompletar.o Ejercicio.o Lecciones.o Curso.o Estudiante.o Profesor.o Usuario.o Ctrl.o Factory.o main.o -o programa

# ###Linkedicion de cada archivo necesario###
main.o: main.cpp ICtrl.h Factory.h DataCursoE.h DataCursoP.h DataCurso.h
	$(CC) $(CFLAGS) -c main.cpp

Factory.o: Factory.h ICtrl.o
	$(CC) $(CFLAGS) -c Factory.cpp

Ctrl.o: Ctrl.h ICtrl.h Curso.o Usuario.o Profesor.o Estudiante.o Lecciones.o Idiomas.o DataCurso2.o DataLeccion.o DataCurso3.o DataCursoE.o DataCursoP.o DataCurso.o DataUsuario.o 
	$(CC) $(CFLAGS) -c Ctrl.cpp Curso.cpp Usuario.cpp Profesor.cpp Estudiante.cpp Lecciones.cpp Idiomas.cpp DataCurso2.cpp DataLeccion.cpp DataCurso3.cpp DataCursoE.cpp DataCursoP.cpp DataCurso.cpp DataUsuario.cpp 

Usuario.o: Usuario.h
	$(CC) $(CFLAGS) -c Usuario.cpp 

Profesor.o: Profesor.h Usuario.o Curso.o DataCursoP.o
	$(CC) $(CFLAGS) -c Profesor.cpp Usuario.cpp Curso.cpp DataCursoP.cpp

Estudiante.o: Estudiante.h Usuario.o Lecciones.o DTFecha.o DataCursoE.o
	$(CC) $(CFLAGS) -c Estudiante.cpp Usuario.cpp Lecciones.cpp DTFecha.cpp DataCursoE.cpp

Curso.o: Curso.h Lecciones.o Idiomas.o DataCurso.o DataLeccion.o DataInscripciones2.o 
	$(CC) $(CFLAGS) -c Curso.cpp Lecciones.cpp Idiomas.cpp DataCurso.cpp DataLeccion.cpp DataInscripciones2.cpp 

Lecciones.o: Lecciones.h deCompletar.o deTraducir.o DataEjeCompletar.o DataEjeTraduccion.o
	$(CC) $(CFLAGS) -c Lecciones.cpp deCompletar.cpp deTraducir.cpp DataEjeCompletar.cpp DataEjeTraduccion.cpp

Ejercicio.o: Ejercicio.h
	$(CC) $(CFLAGS) -c Ejercicio.cpp

deCompletar.o: deCompletar.h Ejercicio.o
	$(CC) $(CFLAGS) -c deCompletar.cpp Ejercicio.cpp

deTraducir.o: deTraducir.h Ejercicio.o
	$(CC) $(CFLAGS) -c deTraducir.cpp Ejercicio.cpp

Idiomas.o: Idiomas.h
	$(CC) $(CFLAGS) -c Idiomas.cpp

Inscripcion.o: Inscripcion.h Estudiante.o Curso.o DTFecha.o
	$(CC) $(CFLAGS) -c Inscripcion.cpp Estudiante.cpp Curso.cpp DTFecha.cpp

DTFecha.o: DTFecha.h
	$(CC) $(CFLAGS) -c DTFecha.cpp

DataUsuario.o: DataUsuario.h DataProfesor.o DataEst.o
	$(CC) $(CFLAGS) -c DataUsuario.cpp DataProfesor.cpp DataEst.cpp

DataProfesor.o: DataProfesor.h
	$(CC) $(CFLAGS) -c DataProfesor.cpp

DataEst.o: DataEst.h DTFecha.o
	$(CC) $(CFLAGS) -c DataEst.cpp DTFecha.cpp

DataLeccion.o: DataLeccion.h DataEjeCompletar.o DataEjeTraduccion.o
	$(CC) $(CFLAGS) -c DataLeccion.cpp DataEjeCompletar.cpp DataEjeTraduccion.cpp

DataEjeCompletar.o: DataEjeCompletar.h
	$(CC) $(CFLAGS) -c DataEjeCompletar.cpp

DataEjeTraduccion.o: DataEjeTraduccion.h
	$(CC) $(CFLAGS) -c DataEjeTraduccion.cpp

DataInscripciones2.o: DataInscripciones2.h DTFecha.o
	$(CC) $(CFLAGS) -c DataInscripciones2.cpp DTFecha.cpp

DataCurso.o: DataCurso.h Curso.o
	$(CC) $(CFLAGS) -c DataCurso.cpp Curso.cpp

DataCurso2.o: DataCurso2.h Curso.o DataEjeTraduccion.o DataEjeCompletar.o DataInscripciones2.o DataLeccion.o 
	$(CC) $(CFLAGS) -c DataCurso2.cpp Curso.cpp DataEjeTraduccion.cpp DataEjeCompletar.cpp DataInscripciones2.cpp DataLeccion.cpp 

DataCurso3.o: DataCurso3.h Curso.o
	$(CC) $(CFLAGS) -c DataCurso3.cpp Curso.cpp

DataCursoP.o: DataCursoP.h 
	$(CC) $(CFLAGS) -c DataCursoP.cpp 

DataCursoE.o: DataCursoE.h 
	$(CC) $(CFLAGS) -c DataCursoE.cpp 