#include "Ctrl.h"
#include <string>
using namespace std;

Ctrl* Ctrl::instance = NULL;

ICtrl* Ctrl::getInstance() {
    if (!instance) {
	    instance = new Ctrl();
    }
    return instance;
};

Ctrl::Ctrl() {};
Ctrl::~Ctrl() {};
Ctrl::Ctrl(const Ctrl& orig) {};

