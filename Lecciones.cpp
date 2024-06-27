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

void Lecciones::CrearEjer(std::string NomEj, std::string tipo,std::string desc,std::string frase,std::string solucion){
   
    if(tipo=="Traducir"){
        deTraducir* Ejer=new deTraducir(NomEj,desc,frase,solucion);//Creamos el ejercicio de traducir
        IKey* Ej=new String(NomEj.c_str());//Creamos una llave
        this->DeTraducir->add(Ej,Ejer);//Agregamos el ejercicio al dicionario con su llave creada
    }else{
        std::stringstream ss(solucion);// Crea un stringstream inicializado con la cadena solucion
        std::vector<std::string> tokens;// Vector para almacenar los tokens
        std::string delimiter = "---";// Delimitador para dividir la cadena
        size_t pos = 0;  // Posición del delimitador
        std::string token; // Variable para almacenar cada token
         // Extraer tokens de la cadena solucion usando el delimitador "---"
        while ((pos = solucion.find(delimiter)) != std::string::npos) {
            token = solucion.substr(0, pos);// Extrae el token desde el inicio hasta pos
            tokens.push_back(token);// Añade el token al vector tokens
            solucion.erase(0, pos + delimiter.length());// Borra el token y el delimitador de solucion
        }
        // Añadir el último token
        tokens.push_back(solucion);

        std::set<std::string> Solc;// Conjunto para almacenar las soluciones únicas
        // Insertar todos los tokens en el conjunto Solc para garantizar que sean únicos
        for (const auto& Seg : tokens) {
            Solc.insert(Seg);
        }
        deCompletar* Ejer = new deCompletar(NomEj, desc, frase, Solc);//Creamos el ejercicio de completar
         IKey* Ej=new String(NomEj.c_str());//Creamos una llave
        this->DeCompletar->add(Ej,Ejer);//Agregamos el ejercicio al dicionario con su llave creada
    }
};//OK

//CU: Eliminar Curso
void Lecciones::DeleteAllEjercicios(){
    IIterator* itCompletar=(this->DeCompletar)->getIterator();
    IIterator* itTraducir=(this->DeTraducir)->getIterator();

    while(itCompletar->hasCurrent()){
        (((deCompletar*)itCompletar->getCurrent())->~deCompletar()); //REVISAR DESTROY DESPUES
        itCompletar->next();
    }
    while(itTraducir->hasCurrent()){
        (((deTraducir*)itTraducir->getCurrent())->~deTraducir()); //REVISAR DESTROY DESPUES
        itTraducir->next();
    }
};

//CU: Inscribirse Curso
int Lecciones::sumarEjercicio(){
    int Total=0;
    IIterator* itLC=(this->DeCompletar)->getIterator();
    while(itLC->hasCurrent()){//Sumara cada que alla un ejercicio de completar
        Total=Total+1;
    }
    delete itLC;
    IIterator* itLT=(this->DeTraducir)->getIterator();
    while(itLT->hasCurrent()){//Sumara cada que alla un ejercicio de traducir
        Total=Total+1;
    }
    delete itLT;
    return Total;
};
