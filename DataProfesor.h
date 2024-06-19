
#ifndef DATAPROFESOR_H
#define DATAPROFESOR_H
#include <string>
using namespace std;

class DataProfesor {
	private:
		string instituto;
		string nomIdioma;
	public:
	DataProfesor(){};

		virtual ~DataProfesor();
		string getInstituto();
		string getNomIdioma();
};

#endif