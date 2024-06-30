#include <iostream>
#include <string>
#include "ICtrl.h"
#include "Factory.h"
#include "DataCursoE.h"
#include "DataCursoP.h"
#include "DataCurso.h"


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
                break;
            }
            case 5:{
                break;
            }
            case 6:{
                break;
            }
            case 7:{
                break;
            }
            case 8:{
                cout<<"Ingrese nick del Estudiante"<<endl<<"> ";
                std::string nick;
                std::string nCurso;
                std::string nomEjer;
                std::string solUsuario;
                getline(std::cin,nick);
                if(ctrl->getEstudiantes()->member(new String(nick.c_str()))){
                    set<DataCursoE*>Csos = ctrl->ListCursosE(nick);
                    for (DataCursoE* DTCE : Csos) {
                        cout<<"Curso: "<<DTCE->getNomCursoP()<<endl;
                        cout<<"(%)Avance: "<<DTCE->getPAvance();
                    }
                    cout<<"Ingrese nombre del Curso: "<<endl<<"> ";
                    getline(std::cin,nCurso);
                    if(ctrl->getCursos()->member(new String(nCurso.c_str()))){
                        set<std::string>Ejercicios = ctrl->ListarEjercicios(nCurso,(Estudiante*)ctrl->getEstudiantes()->find(new String(nick.c_str())));
                        for(const std::string& ejer : Ejercicios){
                            cout<<ejer<<endl;
                        }
                        cout<<"Ingrese nombre del Ejercicio: "<<endl<<"> ";
                        getline(std::cin,nomEjer);
                        ctrl->clearSys();
                        set<std::string>Problema = ctrl->PlantearProblema(nomEjer,nCurso,(Estudiante*)ctrl->getEstudiantes()->find(new String(nick.c_str())));
                        if(Problema.empty()==false){
                            for(const std::string& probE : Problema){
                                cout<<probE<<endl;
                            }
                            cout<<endl<<"Ingrese solucion: "<<endl<<"> ";
                            getline(std::cin,solUsuario);
                            if(ctrl->IngresarSolucion(solUsuario,nomEjer,nCurso,(Estudiante*)ctrl->getEstudiantes()->find(new String(nick.c_str())))){
                                cout<<"La solucion es CORRECTA!"<<endl;
                            }
                            else{
                                cout<<"La solucion es INCORRECTA!"<<endl;
                            }
                        }
                    }
                }
                else{
                    ctrl->clearSys();
                    cout<<"Opcion no valida"<<endl;
                    getchar();
                }
                break;
            }
            case 9:{
                break;
            }
            case 10:{
                char opt;
                string nick;
                cout<<"Que estadistica desea?:"<<endl;
                cout<<"1- Estudiantea"<<endl;
                cout<<"2- Profesores"<<endl;
                cout<<"3- Cursos"<<endl;
                cin>>opt;
                getchar();
                ctrl->clearSys();
                switch(opt){
                    case '1':{
                        cout<<"Estudiantes: "<<endl;
                        set<std::string>estu=ctrl->ListEstudiantes();
                        for (const std::string& palabra : estu) {
                            cout<<palabra<<endl;
                        }
                        cout<<"Selecione un estudiante: "<<endl;
                        getline(std::cin,nick);
                        ctrl->clearSys();
                        set<DataCursoE*>CursosE=ctrl->ListCursosE(nick);
                        for (DataCursoE* CE : CursosE) {
                            cout<<"Curso: "<<CE->getNomCursoP()<<endl;
                            cout<<"(%)Avance: "<<CE->getPAvance();
                        }
                        break;
                    }
                    case '2':{
                        cout<<"Profesores: "<<endl;
                        set<std::string>Profs=ctrl->ListarProfesores();
                        for (const std::string& palabra : Profs) {
                            cout<<palabra<<endl;
                        };
                        cout<<"Selecione un Profesor: "<<endl;
                        getline(std::cin,nick);
                        ctrl->clearSys();
                        set<DataCursoP*>CursosP=ctrl->ListCursosP(nick);
                        for (DataCursoP* CP : CursosP) {
                            cout<<"Curso: "<<CP->getNomCurso()<<endl;
                            cout<<"(%)Promedio de avance: "<<CP->getProm();
                        };
                        break;
                    }
                    case '3':{
                        cout<<"Cursos: "<<endl;
                        set<std::string>Curs=ctrl->ListCurso();
                        for (const std::string& palabra : Curs) {
                            cout<<palabra<<endl;
                        };
                        cout<<"Selecione un Curso: "<<endl;
                        getline(std::cin,nick);
                        ctrl->clearSys();
                        DataCurso* CI=ctrl->verInfoCurso(nick);
                            cout<<"Curso: "<<CI->getNomCurso()<<endl;
                            cout<<"Descripcion: "<<CI->getDesCurso()<<endl;
                            cout<<"habilitado?: "<<CI->getHabilitado();
                            cout<<"Dificultad: ";
                            switch(CI->getDificultad()){
                                case 0:{
                                    cout<<"principiante"<<endl;
                                    break;
                                }
                                case 1:{
                                    cout<<"medio"<<endl;
                                    break;
                                }
                                default:{
                                    cout<<"avanzado"<<endl;
                                }
                            };
                            cout<<"(%)Promedio de avance Total: "<<CI->getPromediT();
                        break;
                    }
                    default:{
                        cout<<"Opcion no valida"<<endl;
                        getchar();
                    }
                }
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