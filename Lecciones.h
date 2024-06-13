
#ifndef LECCIONES_H
#define LECCIONES_H
#include <string>
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
using namespace std;

class Lecciones : public ICollectible{
	private:
		string tema;
		string objetivo;
		IDictionary* deCompletar;
		IDictionary* deTraducir;
	public:
};

#endif