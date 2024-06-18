
#ifndef USUARIO_H
#define USUARIO_H
#include "ICollection/interfaces/ICollectible.h"
#include <string>
using namespace std;

class Usuario : public ICollectible{
	protected:
		string nickname;
		string descripcion;
		string nombre;
		string contrasenia;
	public:
	virtual ~Usuario();
	std::string getnickname();
	std::string getdescripcion();
	std::string getnombre();
	std::string getcontrasenia();
};

#endif