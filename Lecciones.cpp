#include"Lecciones.h"
#include <string>
#include "deTraducir.h"
#include "deCompletar.h"
#include "ICollection/String.h"
#include "ICollection/collections/OrderedDictionary.h"
#include <sstream> 
#include <vector> 
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

Ejercicio* Lecciones::CrearEjer(std::string NomEj, std::string tipo,std::string desc,std::string frase,std::string solucion){
   
    if(tipo=="Traducir"){
        deTraducir* Ejer=new deTraducir(NomEj,desc,frase,solucion);
        IKey* Ej=new String(NomEj.c_str());
        this->DeTraducir->add(Ej,Ejer);
        return Ejer;
    }else{
        std::stringstream ss(solucion); 
        std::vector<std::string> tokens;
        std::string delimiter = "---";
        size_t pos = 0;
        std::string token;
    
    while ((pos = solucion.find(delimiter)) != std::string::npos) {
        token = solucion.substr(0, pos);
        tokens.push_back(token);
        solucion.erase(0, pos + delimiter.length());
    }
    // Añadir el último token
    tokens.push_back(solucion);

    std::set<std::string> Solc;
    for (const auto& Seg : tokens) {
        Solc.insert(Seg);
    }

    deCompletar* Ejer = new deCompletar(NomEj, desc, frase, Solc);
    return Ejer;
    }
   
};	
