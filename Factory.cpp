#include "Factory.h"
#include "Ctrl.h"

Factory::Factory(){};

Factory::~Factory(){};

ICtrl* Factory::getICtrl(){
    return Ctrl::getInstance();
};

