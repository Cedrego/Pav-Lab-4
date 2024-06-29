#include <iostream>
#include <string>
#include "ICtrl.h"
#include "Factory.h"

using namespace std;

int main(int argc, char *argv[]){

    Factory* fabric = new Factory();
	ICtrl* ctrl = fabric->getICtrl();

    char op;
    do{
		ctrl->clearSys();
        std::cout<<"Bienvenido al sistema [REDACTED]"<<endl;
        std::cout<<"0- Cargar Datos"<<endl;
        std::cout<<"1- Ingresar Usuario"<<endl;
        std::cout<<"2- Ingresar Idioma"<<endl;
        std::cout<<"3- Ingresar Curso"<<endl;
        std::cout<<"4- Ingresar Leccion"<<endl;
        std::cout<<"5- Ingresar Ejercicio"<<endl;
        std::cout<<"6- Habilitar Curso"<<endl;
        std::cout<<"7- Inscribirse a Curso"<<endl;
        std::cout<<"8- Realizar Ejercicio"<<endl;
        std::cout<<"9- Consultar Idioma"<<endl;
        std::cout<<"10- Consultar Estadisticas"<<endl;
        std::cout<<"11- Consultar Usuario"<<endl;
        std::cout<<"12- Consultar Curso"<<endl;
        std::cout<<"13- Eliminar Curso"<<endl;
        std::cout<<"14- Salir"<<endl;
		
		std::cin>>op;
		getchar();
		
        switch(op){
            case '0':{
                std::cout<<"Cargando datos, espere..."<<endl;
                ctrl->UnlimitedVoid();
                std::cout<<"Datos default cargados, presione enter para continuar"<<endl;
                getchar();
                break;
            }
            case '1':{
                break;
            }
            case '2':{
                break;
            }
            case '3':{
                break;
            }
            case '4':{
                break;
            }
            case '5':{
                break;
            }
            case '6':{
                break;
            }
            case '7':{
                break;
            }
            case '8':{
                break;
            }
            case '9':{
                break;
            }
            case '10':{
                break;
            }
            case '11':{
                break;
            }
            case '12':{
                break;
            }
            case '13':{
                break;
            }
            case '14':{
                break;
            }
        };
    }while(op!='14');
    return 0;
}