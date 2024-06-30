#include <iostream>
#include <string>
#include "ICtrl.h"
#include "Factory.h"

using namespace std;

int main(int argc, char *argv[]){

    Factory* fabric = new Factory();
	ICtrl* ctrl = fabric->getICtrl();

    int op;
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
        if(op<0 || op>14){
            std::cout<<"Error, ingrese una opcion valida"<<endl;
            op=69;//por las dudas
            std::cout<<"Presione enter para continuar..."<<endl;
            getchar();
        }
		getchar();
		
        switch(op){
            case 0:{
                std::cout<<"Cargando datos, espere..."<<endl;
                ctrl->UnlimitedVoid();
                std::cout<<"Datos default cargados, presione enter para continuar"<<endl;
                getchar();
                break;
            }
            case 1:{
                break;
            }
            case 2:{
                std::string nomIdioma; 
                bool esta;
                do{
                std::cout<<"Ingrese el nuevo Idioma"<<endl;
                cin>>nomIdioma;
                IKey* IKI=new String(nomIdioma.c_str());
                esta= ctrl->getIdiomas()->member(IKI);
                if(esta==true){
                    std::cout<<"Error, el Idioma ingresado ya existe"<<endl;
                    std::cout<<"Vuelva a Intentarlo"<<endl;
                    getchar();
                }
                }while(esta==true);
                ctrl->IngresaIdioma(nomIdioma);
                std::cout<<"Idioma ingresado correctamente"<<endl;
                std::cout<<"Precione enter para continuar"<<endl;
                getchar();
                break;
            }
            case 3:{
                //variables
                set<std::string> listaProfesores;
                std::string nickProf;
                std::string nomCurso;
                std::string descCurso;
                DIFICULTAD difCurso;
                int difC;
                set<std::string> listaIdiomas;
                std::string idiomaCurso;
                set<std::string> listaCursosHabilitados;
                std::string cursoPrevia;
                std::string temaLeccion;
                std::string objetivoLeccion;
                std::string nomEj;
                std::string tipoEj;
                std::string descEj;
                std::string fraseEj;
                std::string solEj;
                bool esta;
                char opcion;
                char quiere;
                char masEjer;
                char masLec;
                

                std::cout<<"Estos son los profesores disponibles:"<<endl<<endl;
                listaProfesores=ctrl->ListarProfesores();
                for(const auto& prof:listaProfesores){
                    std::cout<<prof<<endl;
                }
                
                do{
                std::cout<<"Ingrese el nickname del Profesor"<<endl;
                std::getline(std::cin,nickProf);
                IKey* keyProf = new String(nickProf.c_str());
                esta =ctrl->getProfesores()->member(keyProf);
                if(esta!=true){
                    std::cout<<"Error, ingrese un nickname valido"<<endl;
                    std::cout<<"Vuelva a intentar"<<endl;
                    getchar();
                };
                } while(esta!=true);

                do{
                std::cout<<"Ingrese el nombre del Curso a crear"<<endl;
                std::getline(std::cin,nomCurso);
                IKey* keyCurso = new String(nomCurso.c_str());
                esta =ctrl->getCursos()->member(keyCurso);
                if(esta==true){
                    std::cout<<"Error, ya existe un Curso con ese nombre"<<endl;
                    std::cout<<"Vuelva a intentar"<<endl;
                    getchar();
                };
                }while(esta==true);

                std::cout<<"Ingrese la descripcion del Curso a crear"<<endl;
                std::getline(std::cin,descCurso);

                do{
                std::cout<<"Ingrese la dificultad del Curso a crear"<<endl;
                std::cout<<"(0-principiante,1-medio,2-avanzado)"<<endl;
                cin>>difC;
                if(difC<0||difC>2){
                difCurso = static_cast<DIFICULTAD>(difC);
                }else{
                    std::cout<<"Error, dificultad invalida"<<endl;
                    std::cout<<"Vuelva a intentar"<<endl;
                    getchar();
                }
                }while(difC<0||difC>2);
                Curso* cursoNuevo = ctrl->IngresoCurso(nickProf,nomCurso,descCurso,difCurso);

                std::cout<<"Estos son los Idiomas disponibles para el Curso"<<endl;
                listaIdiomas=ctrl->ListarIdiomas(cursoNuevo);
                for(const auto& idi:listaIdiomas){
                    std::cout<<idi<<endl;
                }

                do{
                    std::cout<<"Seleccione un Idioma para el Curso"<<endl;
                    std::getline(std::cin,idiomaCurso);
                    IKey* keyIdioma = new String(idiomaCurso.c_str());
                    esta =ctrl->getIdiomas()->member(keyIdioma);
                    if(esta!=true){
                        std::cout<<"Error, no existe un Idioma con ese nombre" <<endl;
                        std::cout<<"Vuelva a intentar"<<endl;
                        getchar();
                    };
                }while(esta!=true);
                ctrl->SeleccionarIdiomaC(idiomaCurso,cursoNuevo);

                std::cout<<"Desea agregar previaturas a este Curso?   Y|N";
                cin>>opcion;
                if(opcion=='Y'||opcion=='y'){
                    std::cout<<"Estos son los Cursos que se encuentran disponibles:"<<endl;
                    listaCursosHabilitados=ctrl->ListarCursosHabilitados();
                for(const auto& ch:listaCursosHabilitados){
                    std::cout<<ch<<endl;
                }
                do{
                    std::cout<<"Seleccione un Curso:"<<endl;
                    std::getline(std::cin,cursoPrevia);
                    ctrl->SeleccionarPreviatura(cursoPrevia,cursoNuevo);
                    std::cout<<"Desea agregar otra?   Y|N"<<endl;
                    cin>>quiere;
                }while(quiere=='Y'||quiere=='y');
                }
                std::cout<<"Desea agregar una Leccion a este Curso?   Y|N";
                cin>>opcion;
                if(opcion=='Y'||opcion=='y'){
                    do{
                        std::cout<<"Ingrese un tema para la Leccion"<<endl;
                        std::getline(std::cin,temaLeccion);
                        std::cout<<"Ingrese un objetivo para la Leccion"<<endl;
                        std::getline(std::cin,objetivoLeccion);
                        Lecciones* leccionNueva = cursoNuevo->CrearLeccion(temaLeccion,objetivoLeccion);
                        std::cout<<"Desea agregar un Ejercicio para esta Leccion?   Y|N"<<endl;
                        cin>>quiere;
                        if(opcion=='Y'||opcion=='y'){
                            do{
                                std::cout<<"Ingrese el nombre del Ejercicio"<<endl;
                                std::getline(std::cin,nomEj);

                                std::cout<<"Ingrese el tipo del Ejercicio"<<endl;
                                std::cout<<"(Traducir|Completar)  MAYUS IMPORTANTE"<<endl;
                                std::getline(std::cin,tipoEj);
                                do{
                                if(tipoEj.compare("Traducir")!=0||tipoEj.compare("Completar")!=0){
                                    std::cout<<"Error, tipo invalido"<<endl;
                                    std::cout<<"Vuelva a intentar"<<endl;
                                    getchar();
                                };
                                }while(tipoEj.compare("Traducir")!=0||tipoEj.compare("Completar")!=0);

                                std::cout<<"Ingresar una descripcion:"<<endl;
                                std::getline(std::cin,descEj);
                                
                                std::cout<<"Ingrese el problema a solucionar:"<<endl;
                                std::cout<<"(En caso de ser de Completar, utilice --- en las secciones a completar)"<<endl;
                                std::getline(std::cin,fraseEj);
                            
                                std::cout<<"Ingrese la solucion"<<endl;
                                std::cout<<"(En caso de ser de Completar, separe las palabras con ---)"<<endl;
                                std::getline(std::cin,solEj);
                                leccionNueva->CrearEjer(nomEj,tipoEj,descEj,fraseEj,solEj);
                                std::cout<<"Desea agregar otro Ejercicio a esta Leccion?  Y|N"<<endl;
                                cin>>masEjer;
                            }while(masEjer=='Y'||masEjer=='y');
                        }
                        std::cout<<"Desea agregar otra Leccion a este Curso?   Y|N"<<endl;
                        cin>>masLec;
                    }while(masLec=='Y'||masLec=='y');
                }
                std::cout<<"Alta de Curso terminada, volviendo a menu principal"<<endl;
                std::cout<<"Presione enter para continuar"<<endl;
                getchar();
                break;
            }
            case 4:{
                set<std::string> cursoNH= ctrl->ListarCursosNoHabilitados();
                std::cout << "Cursos no Habilitados"<< endl;
                for (const auto& curso : cursoNH) {
                    std::cout << curso <<endl;
                }
                std::string nomCurso;
                bool esta;
                do{
                    std::cout << "Selecione un Curso"<< endl;
                    cin>>nomCurso;
                    esta=false;
                    for (const auto& curso : cursoNH){ 
                        if (curso == nomCurso){
                                esta=true;
                                break;
                        }
                    }
                    if(esta!=true){
                        std::cout<<"Error, el Nombre del Curso ingresado no es correcto"<<endl;
                        std::cout<<"Vuelva a Intentarlo"<<endl;
                        getchar();
                    }
                }while(esta!=true);
                Curso* C=ctrl->SeleccionarCursoNoHabilitado(nomCurso);
                std::string nomTema;
                std::cout<<"Ingrese el Nombre del tema de la Leccion"<<endl;
                cin>>nomTema;
                std::string objetivo;
                std::cout<<"Ingrese el Objetivo de la Leccion"<<endl;
                cin>>objetivo;
                Lecciones* L= ctrl->ingresarLeccion(nomTema,objetivo,C);
                std::string nomEj;
                std::string tipoEj;
                std::string descEj;
                std::string fraseEj;
                std::string solEj;
                char opcion;
                char masEjer;                
                        std::cout<<"Desea agregar un Ejercicio para esta Leccion?   Y|N"<<endl;
                        cin>>opcion;
                        if(opcion=='Y'||opcion=='y'){
                            do{
                                std::cout<<"Ingrese el nombre del Ejercicio"<<endl;
                                std::getline(std::cin,nomEj);
                                do{
                                    std::cout<<"Ingrese el tipo del Ejercicio"<<endl;
                                    std::cout<<"(Traducir|Completar)  MAYUS IMPORTANTE"<<endl;
                                    std::getline(std::cin,tipoEj);
                                    
                                    if(tipoEj.compare("Traducir")!=0||tipoEj.compare("Completar")!=0){
                                        std::cout<<"Error, tipo invalido"<<endl;
                                        std::cout<<"Vuelva a intentar"<<endl;
                                        getchar();
                                    };
                                }while(tipoEj.compare("Traducir")!=0||tipoEj.compare("Completar")!=0);

                                std::cout<<"Ingresar una descripcion:"<<endl;
                                std::getline(std::cin,descEj);
                                
                                std::cout<<"Ingrese el problema a solucionar:"<<endl;
                                std::cout<<"(En caso de ser de Completar, utilice --- en las secciones a completar)"<<endl;
                                std::getline(std::cin,fraseEj);
                            
                                std::cout<<"Ingrese la solucion"<<endl;
                                std::cout<<"(En caso de ser de Completar, separe las palabras con ---)"<<endl;
                                std::getline(std::cin,solEj);
                                ctrl->CrearEjercicio(nomEj,tipoEj,descEj,fraseEj,solEj,C,L);
                                std::cout<<"Desea agregar otro Ejercicio a esta Leccion?  Y|N"<<endl;
                                cin>>masEjer;
                            }while(masEjer=='Y'||masEjer=='y');
                        }
                        

                break;
            }
            case 5:{
                break;
            }
            case 6:{
                break;
            }
            case 7:{
                string nick;
                bool esta;
                do{
                std::cout<<"Ingrese el Nickname del Estudiante"<<endl;
                cin>>nick;
                IKey* IKN=new String(nick.c_str());
                esta= ctrl->getEstudiantes()->member(IKN);
                if(esta!=true){
                    std::cout<<"Error, el Nickname ingresado no existe"<<endl;
                    std::cout<<"Vuelva a Intentarlo"<<endl;
                    getchar();
                }
                }while(esta!=true);
                Estudiante* E=nullptr;
                set<DataCurso3*> DT= ctrl->ListarCursosDisponibles(nick,E);
                std::cout << "Cursos disponibles:"<<endl;
                for (const auto& curso : DT) {
                   std::cout << "Nombre del Curso: " << curso->getNomCurso() << ", Dificultad: " << curso->getDificultad()<<",Descripcion"<<curso->getDesCurso()<<",Cantidad de Lecciones"<<curso->getLecciones()<<",Cantidad de Ejercicios"<<curso->getEjercicios() <<endl;
                }
                string nomCurso;
                do{
                std::cout<<"Ingrese el Nombre del Curso al cual e desea inscribir: "<<endl;
                cin>>nomCurso;
                esta=false;
                for (const auto& curso : DT){ 
                   if (curso->getNomCurso() == nomCurso){
                        esta=true;
                        break;
                   }
                }
                if(esta!=true){
                    std::cout<<"Error, el Nombre del Curso ingresado no existe"<<endl;
                    std::cout<<"Vuelva a Intentarlo"<<endl;
                    getchar();
                }
                }while(esta!=true);
                ctrl->SeleccionarCurso(nomCurso,E);
                std::cout<<"Estudian Inscripto correctamente"<<endl;
                std::cout<<"Precione enter para continuar"<<endl;
                getchar();
                
                break;
            }
            case 8:{
                break;
            }
            case 9:{
                set<std::string> Idiomas= ctrl->muestroIdioma();
                std::cout << "Idiomas"<< endl;
                for (const auto& idioma : Idiomas) {
                    std::cout << idioma <<endl;
                }
                std::cout<<"Precione enter para continuar"<<endl;
                getchar();
                break;
            }
            case 10:{
                break;
            }
            case 11:{
                break;
            }
            case 12:{
                break;
            }
            case 13:{
                break;
            }
            case 14:{
                break;
            }
        };
    }while(op!=14);
    return 0;
}