#ifndef FACTORY_H
#define FACTORY_H
#include "ICtrl.h"
#include "Ctrl.h"

class Factory {
    private:
    public:
        Factory();
        virtual ~Factory();
        ICtrl* getICtrl();
        Factory(const Factory& orig);
};

#endif