
#ifndef DATALECCION_H
#define DATALECCION_H
#include <string>
using namespace std;

class DataLeccion {
	private:
		string tema;
		string objetivo;
	public:
	DataLeccion(){};

		virtual ~DataLeccion();
		string getTema;
		string getObjetivo;
};

#endif