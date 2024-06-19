#include "DTFecha.h"

DTFecha::DTFecha(){};

DTFecha::DTFecha(int diaDT, int mesDT, int anioDT){
    this->dia=diaDT;
    this->mes=mesDT;
    this->anio=anioDT;
};
DTFecha::~DTFecha(){};

int DTFecha::getdia(){
    return this->dia;
};

int DTFecha::getmes(){
    return this->mes;
};

int DTFecha::getanio(){
    return this->anio;
};