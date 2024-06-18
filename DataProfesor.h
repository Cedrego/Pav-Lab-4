
#ifndef DATAPROFESOR_H
#define DATAPROFESOR_H
#include <string>
using namespace std;

class DataProfesor {
	private:
		string instituto;
		string nomIdioma;
	public:
		DataProfesor(std::string institutoDT, std::string nomIdiomaDT);
		DataProfesor();
		virtual ~DataProfesor();
		std::string getinstituto();
		std::string getnomIdioma();
};

#endif