
#ifndef DATALECCION_H
#define DATALECCION_H
#include <string>
using namespace std;

class DataLeccion {
	private:
		string tema;
		string objetivo;
	public:
		DataLeccion(std::string temaI, std::string objetivoI);
		DataLeccion();
		virtual ~DataLeccion();
		std::string gettema();
		std::string getobjetivo();
};

#endif