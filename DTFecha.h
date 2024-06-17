
#ifndef DTFECHA_H
#define DTFECHA_H

class DTFecha {
	private:
		int dia;
		int mes;
		int anio;
	public:
	DTFecha();
	DTFecha(int diaDT, int mesDT, int anioDT);
	virtual ~DTFecha();
	int getdia();
	int getmes();
	int getanio();
};

#endif