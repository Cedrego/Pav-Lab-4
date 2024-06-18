#include "Factory.h"

Factory::Factory(){
};

Factory::~Factory(){
};

ICtrl* Factory::getICtrl(){
    return Ctrl::getInstance();
};

Factory::Factory(const Factory& orig) {
};
