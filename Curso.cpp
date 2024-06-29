#include "Curso.h"
#include "Profesor.h"

//constructor y getters
Curso::Curso(std::string nomCursoC, std::string desCursoC, DIFICULTAD dificultadC, bool habilitadoC, Idiomas* IdiomaC, Profesor* profesorC){
    this->nomCurso=nomCursoC;
    this->desCurso=desCursoC;
    this->dificultad=dificultadC;
    this->habilitado=habilitadoC;
    this->Idioma=IdiomaC;
    this->profesor=profesorC;
};

Curso::~Curso(){

};

std::string Curso::getNomCurso(){
    return this->nomCurso;
};

std::string Curso::getDesCurso(){
    return this->desCurso;
};

DIFICULTAD Curso::getDificultad(){
    return this->dificultad;
};

bool Curso::getHabilitado(){
    return this->habilitado;
};

Idiomas* Curso::getIdioma(){
    return this->Idioma;
};

Profesor* Curso::getProfesor(){
    return this->profesor;
};

ICollection* Curso::getMisPrevias(){
    return this->MisPrevias;
};

ICollection* Curso::getSoyPreviaDe(){
    return this->SoyPreviaDe;
};

ICollection* Curso::getLecciones(){
    return this->lecciones;
};
IDictionary* Curso::getInscripciones(){
    return this->Inscripciones;
};

//CU: Alta de Curso
void Curso::asignarIdiomaACurso(Idiomas* I){
    this->Idioma=I;
};

void Curso::esPrevia (Curso* CursoPrevia){
    (this->MisPrevias)->add((ICollectible*)CursoPrevia);
};

void Curso::miPrevia (Curso* CursoNuevo){
    (this->SoyPreviaDe)->add((ICollectible*)CursoNuevo);
};


//CU: Eliminar Curso
void Curso::desligarDePrevia(Curso* cursoBorrar){
    //remuevo el curso que quiero borrar de las previas de este curso (que es posterior al que quiero borrar)
    (this->MisPrevias)->remove((ICollectible*)cursoBorrar);
};

void Curso::DeleteALLforCurso(){

    //itero entre las lecciones y borro todos sus ejercicios
    IIterator* itLecciones=(this->lecciones)->getIterator();
    while(itLecciones->hasCurrent()){
        (((Lecciones*)itLecciones->getCurrent())->DeleteAllEjercicios());
        itLecciones->next();
    }
    
    //itero entre todos los estudiantes diciendoles que olviden sus inscripciones a este curso
    //y luego borro la inscripcion
    IIterator* itInscripciones=(this->Inscripciones)->getIterator();
    while(itInscripciones->hasCurrent()){
        (((Inscripcion*)itInscripciones->getCurrent())->desligarEstudiante());
        (((Inscripcion*)itInscripciones->getCurrent())->~Inscripcion());
        itInscripciones->next();
    }
    
    //le digo al profesor que se olvide del curso
    (this->profesor)->desligarProfesor(this);
    
    //itero entre las posteriores y les digo que olviden a este curso como previa
    IIterator* itSoyPrevia=(this->SoyPreviaDe)->getIterator();
    while(itSoyPrevia->hasCurrent()){
        (((Curso*)itSoyPrevia->getCurrent())->desligarDePrevia(this));
        itSoyPrevia->next();
    }

    //itero entre las previas de este curso y les digo que lo olviden como posterior 
    IIterator* itMisPrevias=(this->MisPrevias)->getIterator();
    while(itMisPrevias->hasCurrent()){
        ((((Curso*)itMisPrevias->getCurrent())->SoyPreviaDe)->remove((ICollectible*)this));
        itMisPrevias->next();
    }

    //borro todos los iteradores recien creados
    delete itLecciones;
    delete itInscripciones;
    delete itSoyPrevia;
    delete itMisPrevias;
};


//CU Agregar Ejercicio

set<std::string> Curso::conseguirLecciones(){
    set<std::string> leccionesCurso;
    ICollection* listaLecciones=this->getLecciones();
    IIterator* it=listaLecciones->getIterator();
    while(it->hasCurrent()){
        leccionesCurso.insert(((Lecciones*)it->getCurrent())->getTema());
        it->next();
    };
    return leccionesCurso;
};

//CU: Habilitar Curso

void Curso::habilitar(){
    this->habilitado=true;
};
//Agregar Leccion
Lecciones* Curso::CrearLeccion(string NomTema, string Objetivo){
    //Creamos la leccion
   Lecciones* leccion=new Lecciones( NomTema, Objetivo,NULL,NULL);
   //La leccion creada se agrega a la coleccion
    this->lecciones->add((ICollectible*) leccion);
    return leccion;
};//OK
void Curso::AgregarEjercicio(std::string NomEj, std::string tipo,std::string desc,std::string frase,std::string solucion, Lecciones* leccionNH){
    leccionNH->CrearEjer(NomEj,tipo,desc,frase,solucion);
};//OK

set<DataLeccion*> Curso::conseguirDataLeccion(){
    set<DataLeccion*> setRetornar;
    std::string temaLec;
    std::string objetivoLec;
    IIterator* it=this->lecciones->getIterator();
    while(it->hasCurrent()){
        temaLec=((Lecciones*)it->getCurrent())->getTema();
        objetivoLec=((Lecciones*)it->getCurrent())->getObjetivo();
        DataLeccion* datLec = new DataLeccion(temaLec,objetivoLec);
        setRetornar.insert(datLec);
        it->next();
    }
    delete it;
    return setRetornar;
};

set<DataInscripciones2> Curso::conseguirDataInsc2(){
    set<DataInscripciones2*> setRetornar;
    std::string nomEstu;
    DTFecha* fechaInsc;
    IIterator* it =this->Inscripciones->getIterator();
    while (it->hasCurrent()){
        nomEstu=((Inscripcion*)it->getCurrent())->devolverNomEstudiante();
        fechaInsc=((Inscripcion*)it->getCurrent())->getfechaInscr();
        DataInscripciones2* dataIncs = new DataInscripciones2(nomEstu,fechaInsc);
        setRetornar.insert(dataIncs);
        it->next();
    }
    delete it;
    return setRetornar;
};

//cargar datos
void Curso::aniadirInscripcionCurso(Inscripcion* insc){
    //consigo key de la inscripcion
    IKey* keyInsc = new String((insc->getestudiante())->getNickname().c_str());
    //la aniado a la coleccion
    this->Inscripciones->add(keyInsc, (ICollectible*)insc);

    delete keyInsc;
};