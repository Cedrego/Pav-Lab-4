
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
		system("cls");
        std::cout<<"Bienvenido al sistema [REDACTED]"<<endl;
        std::cout<<"0-"<<endl;
        std::cout<<"1-"<<endl;
        std::cout<<"2-"<<endl;
        std::cout<<"3-"<<endl;
        std::cout<<"4-"<<endl;
        std::cout<<"5-"<<endl;
        std::cout<<"6-"<<endl;
        std::cout<<"7-"<<endl;
        std::cout<<"8-Finalizar programa"<<endl;
		
		std::cin>>op;
		getchar();
		
        switch(op){
            case '0':{
                
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
        };
    }while(op!='8');
    return 0;
}