#include "Ctrl.h"

using namespace std;

Ctrl* Ctrl::instance = nullptr;

ICtrl* Ctrl::getInstance() {
    if (!instance) {
	    instance = new Ctrl();
    }
    return instance;
};

Ctrl::Ctrl() {};
Ctrl::~Ctrl() {};

//Agregar Leccion
Lecciones* ingresarLeccion(string NomTema, string Objetivo, Curso* c){
    //c es una instancia de Curso 
    return c->CrearLeccion(NomTema, Objetivo);

};
/*
set<std::string> Ctrl::ListarCursosNoHabilitados(){
    //Pedimos iterador de cursos a Controlador
    IIterator* itCurso=this->Cursos->getIterator();
    set<std::string> NombreC;
    while(itCurso->hasCurrent()){
        Curso* c=(Curso*)itCurso->getCurrent();
        bool Habi=c->getHabilitado();
        if(Habi==false){
            NombreC.insert(c->getNomCurso());
        }
        itCurso->next();
    }
    delete itCurso;
    return NombreC;
};
*/
Curso* Ctrl::SeleccionarCursoNoHabilitado(string nCurso){
    IKey* IKC=new String(nCurso.c_str());
    return (Curso*)this->Cursos->find(IKC);
};//OK
void Ctrl::CrearEjercicio(std::string NomEj, std::string tipo,std::string desc,std::string frase,std::string solucion, Curso* cursoNH, Lecciones* leccionNH){
    cursoNH->AgregarEjercicio(NomEj,tipo,desc,frase,solucion,leccionNH);
};//OK
IDictionary* Ctrl::getProfesores(){
    return this->Profesores;
};


//CU: Alta de Curso
set<std::string> Ctrl::ListarProfesores(){
    //lista de strings
    set<std::string> Profesores;
    //consigo los profesores del ctrl
    IDictionary* profesoresCtrl=this->getProfesores();
    //consigo un iterador
    IIterator* it=profesoresCtrl->getIterator();

    //itero
    while(it->hasCurrent()){
        //casteo el iterador a profesor por cada instancia y guardo el nickname en la lista
        Profesores.insert(((Profesor*)it->getCurrent())->getNickname());
    };
    //saco la basura
    delete it;
    delete profesoresCtrl;
    //retorno la lista
    return Profesores;
};

Curso* Ctrl::IngresoCurso(std::string nickP , std::string nomCurso, std::string descCurso, DIFICULTAD difCurso){
    //consigo los profesores
    IDictionary* profesoresCtrl=this->getProfesores();
    //hago una IKey
    IKey* KeyProf = new String(nickP.c_str());
    //busco el profesor especifico
    Profesor * prof = (Profesor*)(profesoresCtrl->find(KeyProf));
    //creo un curso nuevo con los datos ingresados y el profesor encontrado, no tengo idioma asi que es NULL
    Curso* cursoNuevo = new Curso(nomCurso, descCurso, difCurso, false, NULL, prof);
    //llamo esta funcion para agregar el curso a la coleccion de cursos del profesor
    prof->asignarCursoAProfesor(cursoNuevo);
    //retorno el curso creado para usarlo en otras operaciones
    return cursoNuevo;
};

set<std::string> Ctrl::ListarIdiomas(Curso* cursoNuevo){
    set<std::string> IdiomasProf;
    Profesor* prof= (cursoNuevo->getProfesor());
    IdiomasProf=prof->buscarIdioma(prof);
    return IdiomasProf;
};

void Ctrl::SeleccionarIdiomaC(std::string idioma, Curso* cursoNuevo){
    IKey* KeyIdioma = new String(idioma.c_str());
    Idiomas* I= (Idiomas*)((this->idiomas)->find(KeyIdioma));
    cursoNuevo->asignarIdiomaACurso(I);
};

set<std::string> Ctrl::ListarCursosHabilitados(){
    //creo una lista de strings para retornar
    set<std::string> CursosH;
    //consigo todos los Cursos en el Ctrl y consigo un iterador en base a eso
    IIterator* it=(this->Cursos)->getIterator();
    
    //itero dentro del diccionario
    while(it->hasCurrent()){; 
        //casteo el iterador a Curso y pregunto si esta habilitado
        bool estaHabilitado=((Curso*)it->getCurrent())->getHabilitado();
        //si no esta habilitado, lo agrego a la lista
        if(estaHabilitado){
            CursosH.insert(((Curso*)it->getCurrent())->getNomCurso());
        };
        it->next();
    };
    //borro el iterador
    delete it;
    //retorno la lista
    return CursosH;
};

void Ctrl::SeleccionarPreviatura(std::string nCurso, Curso* cursoNuevo){
    //Creo una key del curso que quiero seleccionar como previa
    IKey* KeyCurso = new String(nCurso.c_str());
    //Busco el curso que quiero seleccionar como previa
    Curso* CursoPrevia = (Curso*)((this->Cursos)->find(KeyCurso));
    //Asigno el curso previo como previa del curso nuevo
    cursoNuevo->esPrevia(CursoPrevia);
    //Asigno el curso nuevo como posterior del curso previo
    CursoPrevia->miPrevia(cursoNuevo);
};

/* REVISAR DESPUES CON ENZO Y THIAGO
Leccion* ingresarLeccion(NomTema string, Objetivo string){

};
*/

//CU: Alta de Usuario
void Ctrl::IngresoE(DTFecha* fecNac, std::string Nick , std::string Contrasenia , std::string Nom , std::string Desc , std::string Pais){
    //creo una key para identificar al estudiante
    IKey* KeyEstudiante = new String(Nick.c_str());
    //creo una instancia de estudiante
    Estudiante* estudianteNuevo = new Estudiante(Nick,Desc,Nom,Contrasenia,fecNac,Pais);
    //la agrego a la coleccion del controlador
    (this->estudiantes)->add(KeyEstudiante,(ICollectible*)estudianteNuevo);
};


Profesor* Ctrl::IngresoP(std::string Nick , std::string Contrasenia, std::string Nom, std::string Desc, std::string Instituto){
    //creo una key para identificar al profesor
    IKey* KeyProfesor = new String(Nick.c_str());
    //creo una instancia de profesor
    Profesor* profesorNuevo = new Profesor(Nick,Desc,Nom,Contrasenia,Instituto);
    //la agrego a la coleccion del controlador
    (this->Profesores)->add(KeyProfesor,(ICollectible*)profesorNuevo);
    //retorno el puntero para usar despues
    return profesorNuevo;
};

set<std::string> Ctrl::LisIdioma(){
    //creo una lista
    set<std::string> idiomasCtrl;
    //consigo un iterador para los idiomas
    IIterator* it=(this->idiomas)->getIterator();
    //itero
    while(it->hasCurrent()){
        //por cada idioma inserto su nombre en la lista
        idiomasCtrl.insert(((Idiomas*)it->getCurrent())->getNomIdioma());
        //siguiente en la iteracion
        it->next();
    }
    //borro el iterador
    delete it;
    //retorno la lista
    return idiomasCtrl;
};

void Ctrl::SelecIdioma(std::string idioma, Profesor* profesorNuevo){
    //hago una key para el idioma
    IKey* KeyIdioma = new String(idioma.c_str());
    //busco el idioma en el diccionario del controlador
    Idiomas* idiom = (Idiomas*)(this->idiomas)->find(KeyIdioma);
    //uso esta funcion para agregar el puntero del idioma al profesorNuevo
    profesorNuevo->aniadirIdioma(idiom);
};



//CU: Eliminar Curso
set<std::string> Ctrl::ListCurso(){
    //creo una lista
    set<std::string> cursosCtrl;
    //consigo un iterador para los cursos
    IIterator* it=(this->Cursos)->getIterator();
    //itero
    while(it->hasCurrent()){
        //por cada curso inserto su nombre en la lista
        cursosCtrl.insert(((Curso*)it->getCurrent())->getNomCurso());
        //siguiente en la iteracion
        it->next();
    }
    //borro el iterador
    delete it;
    //retorno la lista
    return cursosCtrl;
};

void Ctrl::EliminarCurso(std::string NomCurso){
    //hago una key para el idioma
    IKey* KeyCurso = new String(NomCurso.c_str());
    //busco el idioma en el diccionario del controlador
    Curso* curso = (Curso*)(this->Cursos)->find(KeyCurso);
    curso->DeleteALLforCurso();
};

//CU: Agregar Ejercicio
set<std::string> Ctrl::ListarCursosNoHabilitados(){
    //creo una lista de strings para retornar
    set<std::string> CursosNH;
    //consigo todos los Cursos en el Ctrl y consigo un iterador en base a eso
    IIterator* it=(this->Cursos)->getIterator();
    
    //itero dentro del diccionario
    while(it->hasCurrent()){; 
        //casteo el iterador a Curso y pregunto si esta habilitado
        bool estaHabilitado=((Curso*)it->getCurrent())->getHabilitado();
        //si no esta habilitado, lo agrego a la lista
        if(!estaHabilitado){
            CursosNH.insert(((Curso*)it->getCurrent())->getNomCurso());
        };
        it->next();
    };
    //borro el iterador
    delete it;
    //retorno la lista
    return CursosNH;
};

set<std::string> Ctrl::listarLecciones(std::string nCurso){
    //creo una lista para retornar
    set<std::string> Lecciones;
    //guardo el diccionario de los cursos del ctrl
    IDictionary* Cursos=this->getCursos();
    //declaro su IKey
    IKey* KeyCurso=new String(nCurso.c_str());
    //busco el curso mediante la IKey 
    Curso* curso=(Curso*)(Cursos->find(KeyCurso));
    //llamo a conseguirLecciones() y guardo su resultado en Lecciones
    Lecciones=curso->conseguirLecciones();

    //borro lo que no es necesario
    delete curso;
    delete Cursos;

    //retorno la lista
    return Lecciones;
}; 

//CU: Habilitar Curso
void Ctrl::HabilitarCurso(std::string nCurso){
    //guardo el diccionario de los cursos del ctrl
    IDictionary* Cursos=this->getCursos();
    //declaro su IKey
    IKey* KeyCurso=new String(nCurso.c_str());
    //busco el curso mediante la IKey 
    Curso* curso=(Curso*)(Cursos->find(KeyCurso));
    //llamo a habilitar
    curso->habilitar();
    //borro lo que sobra
    delete Cursos;
    delete curso;
};


//CU: Alta de Idioma
void Ctrl::IngresaIdioma(std::string stringIdioma){
    //creo una instancia de idioma
    Idiomas* idiom = new Idiomas(stringIdioma);
    //creo una key en base a lo que ingresa
    IKey* KeyIdioma = new String(stringIdioma.c_str());
    //agrego el idioma casteado como ICollectible junto a su key
    (this->idiomas)->add(KeyIdioma,(ICollectible*)idiom);
};
//CU: Inscribirse Curso
set<DataCurso3*> Ctrl::ListarCursosDisponibles(std::string Nickname,Estudiante* &E ){
    std::set<DataCurso3*> dataCursos;//Data que retornaremos
    //Creamos la llave para Estudiante
    IKey* IKE = new String(Nickname.c_str());
    IDictionary* Estudian= this->getEstudiantes();
    //Estud tiene la instancia del estudiante con Nickname
    Estudiante* Estud=(Estudiante*)(Estudian->find(IKE));//Punto 1
    E=Estud;
    //consigo todos los Cursos en el Ctrl y consigo un iterador en base a eso
    IIterator* itC=(this->Cursos)->getIterator();
    while(itC->hasCurrent()){//Punto 2
        Curso* C= (Curso*)itC->getCurrent();
        std::string nomCurso=C->getNomCurso();//Punto 3 Del DC
        bool curzado=Estud->haCursado(nomCurso);//Punto 4
        if(!curzado){
            set<std::string> Previas=C->DamePrevias();//Punto 5
           bool Disponibles=Estud->estanDisponibles(Previas);//Punto 6
            if(Disponibles){
                
                 // Obtener el DataCurso3 del curso actual
                DataCurso3* dataCurso = C->getDataCurso3(); // Asumiendo que getDataCurso3 devuelve un puntero a DataCurso3

                 // Insertar el DataCurso3 en el conjunto
                dataCursos.insert(dataCurso); // Insertar el objeto apuntado por dataCurso en el conjunto

                 // Liberar la memoria del objeto dataCurso si es necesario
                delete dataCurso;
            }
        }
        itC->next();
    }
    delete IKE;
   return dataCursos;

}
void Ctrl::SeleccionarCurso(std::string nomCurso,Estudiante* E){
    IKey* IKC=new String(nomCurso.c_str());
    IDictionary* cursos=this->getCursos();
    Curso* C=(Curso*)(cursos->find(IKC));
    Inscripcion* I=new Inscripcion(NULL,NULL,E,C);

    C->agregarInscripcionCurso(I);//Falta arreglar
    E->agregarInscripcionEstudiante(I);

};
//CU: Consultar Estadisticas
set<std::string>Ctrl::ListEstudiantes(){
    set<std::string> Est;
    IIterator* ite = this->estudiantes->getIterator();
    while(ite->hasCurrent()){
        Est.insert(((Estudiante*)ite->getCurrent())->getNickname());
        ite->next();
    }
    delete ite;
    return Est;
};

set<DataCursoE*>Ctrl::ListCursosE(std::string Nick){
    IKey* ike = new String(Nick.c_str());
    Estudiante* est = (Estudiante*)this->estudiantes->find(ike);
    set<DataCursoE*> listaCursos = est->cursosEstudiante();
    delete ike;
    return listaCursos;
}

set<DataCursoP*>Ctrl::ListCursosP(std::string Nick){
    IKey* ikp = new String(Nick.c_str());
    Profesor* prof = (Profesor*)this->Profesores->find(ikp);
    delete ikp;
    return prof->cursosProfesor();
}

set<std::string>Ctrl::ListCursos(){
    set<std::string> Curs;
    IIterator* itc = this->Cursos->getIterator();
    while(itc->hasCurrent()){
        Curs.insert(((Curso*)itc->getCurrent())->getNomCurso());
        itc->next();
    }
    delete itc;
    return Curs;
}

DataCurso*Ctrl::verInfoCurso(std::string NomCurso){
    
    return ((Curso*)this->Cursos->find(new String(NomCurso.c_str())))->getDataCurso();
}

//CU: Consultar Idioma
set<std::string> Ctrl::muestroIdioma(){
    set<std::string> nomIdomas;
    IIterator* itI=this->idiomas->getIterator();
    Idiomas* Idi;
    while(itI->hasCurrent()){
        Idi=(Idiomas*)itI->getCurrent();
        nomIdomas.insert(Idi->getNomIdioma());
        itI->next();
    }
    return nomIdomas;
};