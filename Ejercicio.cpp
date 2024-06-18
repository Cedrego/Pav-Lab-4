#include "Ejercicio.h"
Ejercicio::Ejercicio(std::string nomEjercicioDT, std::string descripcionDT){
    this->descripcion=descripcionDT;
    this->nomEjercicio=nomEjercicioDT;
};

Ejercicio::Ejercicio(){};

Ejercicio::~Ejercicio(){};

string Ejercicio::getnomEjercicio(){
    return this->nomEjercicio;
};
string Ejercicio::getdescripcion(){
    return this->descripcion;
};