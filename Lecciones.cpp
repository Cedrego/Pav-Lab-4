#include"Lecciones.h"
#include <string>
#include "deTraducir.h"
#include "deCompletar.h"
#include "ICollection/String.h"
#include "ICollection/collections/OrderedDictionary.h"
Lecciones::Lecciones(std::string temaI, std::string objetivoI, IDictionary* deCompletarI, IDictionary* deTraducirI){
    this->tema=temaI;
    this->objetivo=objetivoI;
    this->DeCompletar=deCompletarI;
    this->DeTraducir=deTraducirI;
};

Lecciones::Lecciones(){};

Lecciones::~Lecciones(){};

string Lecciones::getTema(){
    return this->tema;
};

string Lecciones::getObjetivo(){
    return this->objetivo;
};

IDictionary* Lecciones::getdeCompletar(){
    return this->DeCompletar;
};

IDictionary* Lecciones::getdeTraducir(){
    return this->DeTraducir;
};

//Agregar  Leccion
/*
Ejercicio* Lecciones::CrearEjer(std::string NomEj, std::string tipo,std::string desc,std::string frase,std::string solucion){
   
    if(tipo=="Traducir"){
        deTraducir* Ejer=new deTraducir(NomEj,desc,frase,solucion);
        IKey* Ej=new String(NomEj.c_str());
        this->DeTraducir->add(Ej,Ejer);
        return Ejer;
    }else{
        deCompletar* Ejer=new deCompletar(NomEj,desc,frase,solucion);

    }
};	
*/