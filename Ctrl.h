#ifndef CTRL_H
#define CTRL_H
#include "ICtrl.h"
#include <string>
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/OrderedKey.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/String.h"
#include "ICollection/Integer.h"
using namespace std;

class Ctrl: public ICtrl{
    private:
        Ctrl();
        static Ctrl* instance;
    public:
        
        static ICtrl* getInstance();
        virtual ~Ctrl();
};

#endif