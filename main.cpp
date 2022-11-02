//LAS LIBRERIAS NECESARIAS PARA UTILIZAR TODOS LOS AGREGADOS NECESARIOS PARA QUE EL PROGRAMA FUNCIONE CORRECTAMENTE
#include <iostream>
#include <ctime>
#include <windows.h>

//PARA SER CAPACES DE UTILIZAR CIN>> Y COUT<<
using namespace std;

//AQUI SE ESTABLECE EL ENUM PARA QUE EL SWITCH CASE SEA MAS ENTENDIBLE
enum Juego{
Iniciar_Juego=0,
Numero_De_Jugadores=1,
Nombre_De_Jugadores=2,
Numero_De_Fichas=3,
Dificultad=4,
Poner_Ficha_Del_Jugador_Uno=5,
Poner_Ficha_Del_Jugador_Dos=6,
Poner_Ficha_Del_Computador=7,
Ganador_Jugador_Uno=8,
Ganador_Jugador_Dos=9,
Ganador_Computador=10,
Fin_De_La_Partida=11
};

//ESTA ES LA ESTRUCTURA QUE ALMACENARA EL NOMBRE Y EL SCORE DE LOS DOS JUGADORES
struct Jugadores{
string nombre;
int score;
}jugador_uno, jugador_dos;

//AQUI ESTAN TODOS LOS PROTOTIPOS DE LAS FUNCIONES NECESARIAS PARA QUE EL JUEGO FUNCIONE CORRECTAMENTE
void Menu(); //FUNCION ENCARGADA DE REALIZAR UN MENU INICIAL AGRADABLE
int NumeroJugadores(int num_juga); //FUNCION ENCARGADA DE PEDIRLE AL USUARIO LOS JUGADORES CON LOS QUE DESEA JUGAR
void NombreJugadores(int num_juga); //FUNCION ENCARGADA DE PEDIR LOS NOMBRES DE LOS JUGADORES QUE VAN A JUGAR
int NumeroFichas(int num_fichas); //FUNCION ENCARGADA DE PREGUNTAR EL NUMERO DE FICHAS QUE HAY QUE UNIR PARA GANAR
int DificultadJuego(int dific); //FUNCION ENCARGADA DE PREGUNTAR SI SE DESEA JUGAR EN EL MODO CLASICO O EN EL DIFICIL
void NombreScore(); //FUNCION ENCARGADA DE IR MOSTRANDO EL NOMBRE DEL JUGADOR CON SU SCORE RESPECTIVO
char TableroJuego(char Tablero[6][7]); //FUNCION ENCARGADA DE DISEÑAR E IMPRIMIR EL TABLERO DEL JUEGO
bool Temporizador(); //FUNCION ENCARGADA DE CONTROLAR EL TIEMPO EN EL QUE SE PONEN LAS FICHAS SOLO SI SE ESCOGIO EL MODO DIFICIL
int PonerFichas(); //FUNCION ENCARGADA DE PONER LAS FICHAS DEL JUGADOR RESPECTIVO EN EL TABLERO
bool GanadorRonda(); //FUNCION ENCARGADA DE DECIR CUAL ES EL GANADOR DE CADA RONDA
void RondaNueva(); //FUNCION ENCARGADA DE REINICIAR TODOS LOS VALORES NECESARIOS PARA INICIAR UNA NUEVA RONDA
string ResultadosFinales(string ganador_final); //FUNCION ENCARGADA DE MOSTRAR TODOS LOS RESULTADOS FINALES DE UNA MANERA AGRADABLE A LA VISTA
void ReinicioJuego(); //FUNCION ENCARGADA DE REINICIAR EL JUEGO SI ASI LO QUIERE EL USUARIO

//LA MATRIZ QUE HARA EL PAPEL DE TABLERO DE JUEGO
char Tablero[6][7];

//VARIABLES GLOBALES QUE CONSIDERO HACEN MAS ENTENDIBLE Y SENCILLO EL CODIGO PARA REALIZAR ESTE JUEGO
int opcion=0, num_juga=0, num_fichas=0, dific=0, pon_ficha=0, turno_jugador=0, ronda=1;
string ganador_final;
bool ganador=false, tardanza=false;

int main(){ //VARIABLE PRINCIPAL DE TODO EL CODIGO

    string jugar;

    //AQUI LLENAMOS LA MATRIZ TABLERO CON - PARA INDICAR CUALES SON LOS ESPACIOS VACIOS
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            Tablero[i][j]='-';
        }
    }

    Menu(); //LLAMAMOS LA FUNCION MENU QUE NOS MUEESTRA UNA PEQUEÑA EXPLICACION DEL JUEGO

    while(opcion<12){ //UN CICLO WHILE PARA REPETIR EL SWITCH CASE HASTA QUE TERMINE EL JUEGO (<12 PORQUE EL NUMERO DE CASES ES 11)
    switch(opcion){ //EL SWITCH CASE DE LA VARIABLE RESPUESTA QUE INICIA EN 0

        case Iniciar_Juego: //PRIMER CASE CON VALOR DE 0

            cout<<"QUIERES JUGAR CUATRO EN LINEA?: ";
            cin>>jugar;

            if(jugar=="si"||jugar=="SI"||jugar=="Si"){
                opcion=Numero_De_Jugadores; //ASIGNANDOLE EL NUEVO VALOR DE 1 A LA VARIABLE RESPUESTA PARA QUE SE DIRIJA AL CASE NUMERO_DE_JUGADORES
                cout<<endl;
                break; //EL BREAK QUE HARA QUE SE TERMINE EL SWITCH CASE PARA QUE SE VUELVA A REPETIR PERO CON EL NUEVO VALOR DE LA VARIABLE RESPUESTA
                }
            else{
                cout<<endl<<"GRACIAS POR PROBAR EL JUEGO!!"<<endl;
                opcion=12; //ASIGNANDOLE 12 A LA RESPUESTA PARA QUE EL SWITCH CASE NO SE VUELVA A REPETIR
                break; //EL BREAK QUE TERMINA EL JUEGO PORQUE EL USUARIO NO DECIDIO JUGAR
                }

        case Numero_De_Jugadores: //SEGUNDO CASE CON VALOR DE 1

            num_juga=NumeroJugadores(num_juga); //LLAMANDO LA FUNCION NUMEROJUGADORES

            if(num_juga==1||num_juga==2){
                opcion=Nombre_De_Jugadores; //ASIGNANDOLE EL NUEVO VALOR DE 2 A LA VARIABLE RESPUESTA PARA QUE SE DIRIJA AL CASE NOMBRE_DE_JUGADORES
                cout<<endl;
                break; //EL BREAK QUE HARA QUE SE TERMINE EL SWITCH CASE PARA QUE SE VUELVA A REPETIR PERO CON EL NUEVO VALOR DE LA VARIABLE RESPUESTA
            }
            else{
                cout<<endl<<".:INGRESASTE UN DATO ERRONEO, INTENTALO NUEVAMENTE:."<<endl;
                break; //EL BREAK QUE HACE QUE SE VUELVA A REPETIR EL MISMO CASE POR SI EL USUARIO INGRESO UN DATO ERRONEO
            }

        case Nombre_De_Jugadores: //TERCER CASE CON VALOR DE 2

            NombreJugadores(num_juga); //LLAMANDO LA FUNCION NOMBREJUGADORES

            opcion=Numero_De_Fichas; //ASIGNANDOLE EL NUEVO VALOR DE 3 A LA VARIABLE RESPUESTA PARA QUE SE DIRIJA AL CASE NUMERO_DE_FICHAS
            break; //EL BREAK QUE HARA QUE SE TERMINE EL SWITCH CASE PARA QUE SE VUELVA A REPETIR PERO CON EL NUEVO VALOR DE LA VARIABLE RESPUESTA

        case Numero_De_Fichas: //CUARTO CASE CON VALOR DE 3

            num_fichas=NumeroFichas(num_fichas); //LLAMANDO LA FUNCION NUMEROFICHAS

            if(num_fichas==3||num_fichas==4){
                opcion=Dificultad; //ASIGNANDOLE EL NUEVO VALOR DE 4 A LA VARIABLE RESPUESTA PARA QUE SE DIRIJA AL CASE DIFICULTAD
                break; //EL BREAK QUE HARA QUE SE TERMINE EL SWITCH CASE PARA QUE SE VUELVA A REPETIR PERO CON EL NUEVO VALOR DE LA VARIABLE RESPUESTA
            }
            else{
                cout<<endl<<".:INGRESASTE UN DATO ERRONEO, INTENTALO NUEVAMENTE:."<<endl;
                break; //EL BREAK QUE HACE QUE SE VUELVA A REPETIR EL MISMO CASE POR SI EL USUARIO INGRESO UN DATO ERRONEO
            }

        case Dificultad: //QUINTO CASE CON VALOR DE 4

            dific=DificultadJuego(dific); //LLAMANDO LA FUNCION DIFICULTADJUEGO

            if(dific==1||dific==2){
                opcion=Poner_Ficha_Del_Jugador_Uno; //ASIGNANDOLE EL NUEVO VALOR DE 5 A LA VARIABLE RESPUESTA PARA QUE SE DIRIJA AL CASE PONER_FICHA_DEL_JUGADOR_UNO
                break; //EL BREAK QUE HARA QUE SE TERMINE EL SWITCH CASE PARA QUE SE VUELVA A REPETIR PERO CON EL NUEVO VALOR DE LA VARIABLE RESPUESTA
            }
            else{
                cout<<endl<<".:INGRESASTE UN DATO ERRONEO, INTENTALO NUEVAMENTE:."<<endl;
                break; //EL BREAK QUE HACE QUE SE VUELVA A REPETIR EL MISMO CASE POR SI EL USUARIO INGRESO UN DATO ERRONEO
            }

        case Poner_Ficha_Del_Jugador_Uno: //SEXTO CASE CON VALOR DE 5

            system("CLS"); //LIMPIAMOS TODA LA PANTALLA PARA QUE TODO SE VEA MAS ORGANIZADO
            NombreScore(); //LLAMAMOS LA FUNCION NOMBRE SCORE QUE MOSTRARA UN RECUADRO CON EL NOMBRE Y EL SCORE RESPECTIVO DE CADA JUGADOR
            TableroJuego(Tablero); //LLAMAMOS LA FUNCION TABLEROJUEGO QUE MOSTRARA EL TABLERO PARA QUE LOS JUGADORES SEPAN DONDE HUBICAR SU FICHA
            if(dific==2){
            Temporizador(); //ESTE IF ESTA AQUI PARA QUE SOLO SE LLAME LA FUNCION TEMPORIZADOR SI EL USUARIO ELIJIO JUGAR EN MODO DIFICIL
            }
            PonerFichas(); //SE LLAMA A LA FUNCION QUE PERMITIRA AL JUGADOR PONER LA FICHA DONDE EL LO DESEE
            GanadorRonda(); //LLAMAMOS LA FUNCION GANADORRONDA PARA COMPROBAR SI EN EL ANTERIOR MOVIMIENTO EL JUGADOR #1 UNIO LAS FICHAS NECESARIAS PARA GANAR

            opcion=Ganador_Jugador_Uno; //ASIGNAMOS EL NUEVO VALOR A LA VARIABLE RESPUESTA PARA QUE SE DIRIJA AL SIGUIENTE CASE
            break; //EL BREAK PARA QUE SEA CAPAZ DE DIRIJIRSE AL NUEVO CASE ASIGNADO EN LA LINEA ANTERIOR

        case Poner_Ficha_Del_Jugador_Dos: //SEPTIMO CASE CON VALOR DE 6

            system("CLS"); //LIMPIAMOS TODA LA PANTALLA PARA QUE TODO SE VEA MAS ORGANIZADO
            NombreScore(); //LLAMAMOS LA FUNCION NOMBRE SCORE QUE MOSTRARA UN RECUADRO CON EL NOMBRE Y EL SCORE RESPECTIVO DE CADA JUGADOR
            TableroJuego(Tablero); //LLAMAMOS LA FUNCION TABLEROJUEGO QUE MOSTRARA EL TABLERO PARA QUE LOS JUGADORES SEPAN DONDE HUBICAR SU FICHA
            if(dific==2){
            Temporizador(); //ESTE IF ESTA AQUI PARA QUE SOLO SE LLAME LA FUNCION TEMPORIZADOR SI EL USUARIO ELIJIO JUGAR EN MODO DIFICIL
            }
            PonerFichas(); //SE LLAMA A LA FUNCION QUE PERMITIRA AL JUGADOR PONER LA FICHA DONDE EL LO DESEE
            GanadorRonda(); //LLAMAMOS LA FUNCION GANADORRONDA PARA COMPROBAR SI EN EL ANTERIOR MOVIMIENTO EL JUGADOR #1 UNIO LAS FICHAS NECESARIAS PARA GANAR

            opcion=Ganador_Jugador_Dos; //ASIGNAMOS EL NUEVO VALOR A LA VARIABLE RESPUESTA PARA QUE SE DIRIJA AL SIGUIENTE CASE
            break; //EL BREAK PARA QUE SEA CAPAZ DE DIRIJIRSE AL NUEVO CASE ASIGNADO EN LA LINEA ANTERIOR

        case Poner_Ficha_Del_Computador: //OCTAVO CASE CON VALOR DE 7

            system("CLS"); //LIMPIAMOS TODA LA PANTALLA PARA QUE TODO SE VEA MAS ORGANIZADO
            NombreScore(); //LLAMAMOS LA FUNCION NOMBRE SCORE QUE MOSTRARA UN RECUADRO CON EL NOMBRE Y EL SCORE RESPECTIVO DE CADA JUGADOR
            TableroJuego(Tablero); //LLAMAMOS LA FUNCION TABLEROJUEGO QUE MOSTRARA EL TABLERO PARA QUE LOS JUGADORES SEPAN DONDE HUBICAR SU FICHA
            PonerFichas(); //SE LLAMA A LA FUNCION QUE PERMITIRA AL JUGADOR PONER LA FICHA DONDE EL LO DESEE
            GanadorRonda(); //LLAMAMOS LA FUNCION GANADORRONDA PARA COMPROBAR SI EN EL ANTERIOR MOVIMIENTO EL JUGADOR #1 UNIO LAS FICHAS NECESARIAS PARA GANAR

            opcion=Ganador_Computador; //ASIGNAMOS EL NUEVO VALOR A LA VARIABLE RESPUESTA PARA QUE SE DIRIJA AL SIGUIENTE CASE
            break; //EL BREAK PARA QUE SEA CAPAZ DE DIRIJIRSE AL NUEVO CASE ASIGNADO EN LA LINEA ANTERIOR

        case Ganador_Jugador_Uno: //NOVENO CASE CON VALOR DE 8

            if(ganador==true){ //SE EVALUA POR MEDIO DE UNA VARIABLE BOOLEANA SI EL JUGADOR SI GANO
                system("CLS");
                TableroJuego(Tablero);
                jugador_uno.score+=10; //SE LE SUMAN LOS 10 PUNTOS RESPECTIVOS AL SCORE DEBIDO A QUE GANO LA RONDA
                cout<<"EL GANADOR DE LA RONDA "<<ronda<<" ES "<<jugador_uno.nombre<<". SU SCORE AHORA ES DE: "<<jugador_uno.score<<endl<<endl;
                RondaNueva(); //SE LLAMA LA FUNCION RONDA NUEVA QUE RESTABLECE TODOS LOS VALORES NECESARIOS PARA PODER VOLVER A JUGAR
                break;
            }
            else if(num_juga==1){
                opcion=Poner_Ficha_Del_Jugador_Dos; //SI NO GANO Y EL NUMERO DE JUGADORES ES 1, LA RESPUESTA SE LE ASIGNARA EL CASE PARA QUE EL JUGADOR #2 PONGA SU FICHA
            }
            else{
                opcion=Poner_Ficha_Del_Computador; //SI NO GANO Y EL NUMERO DE JUGADORES NO ES 1, A LA RESPUESTA SE LE ASIGNARA EL CASE PARA QUE EL PC PONGA SU FICHA
            }
            break; //EL BREAK PARA QUE SEA CAPAZ DE DIRIJIRSE AL NUEVO CASE ASIGNADO EN EL CONDICIONAL ANTERIOR

        case Ganador_Jugador_Dos: //DECIMO CASE CON VALOR DE 9

        if(ganador==true){ //SE EVALUA POR MEDIO DE UNA VARIABLE BOOLEANA SI EL JUGADOR SI GANO
                system("CLS");
                TableroJuego(Tablero);
                jugador_dos.score+=10; //SE LE SUMAN LOS 10 PUNTOS RESPECTIVOS AL SCORE DEBIDO A QUE GANO LA RONDA
                cout<<"EL GANADOR DE LA RONDA "<<ronda<<" ES "<<jugador_dos.nombre<<". SU SCORE AHORA ES DE: "<<jugador_dos.score<<endl<<endl;
                RondaNueva(); //SE LLAMA LA FUNCION RONDA NUEVA QUE RESTABLECE TODOS LOS VALORES NECESARIOS PARA PODER VOLVER A JUGAR
                break;
            }
        else{
            opcion=Poner_Ficha_Del_Jugador_Uno; //SI NO GANO, SE LE ASIGNA UN VALOR AL CASE PARA QUE EL JUGADOR #1 PONGA SU FICHA
        }
        break; //EL BREAK PARA QUE SEA CAPAZ DE DIRIJIRSE AL NUEVO CASE ASIGNADO EN CONDICIONAL ANTERIOR

        case Ganador_Computador: //ONCEAVO CASE CON VALOR DE 10

        if(ganador==true){ //SE EVALUA POR MEDIO DE UNA VARIABLE BOOLEANA SI EL GANADOR SI GANO
                system("CLS");
                TableroJuego(Tablero);
                jugador_dos.score+=10; //SE LE SUMAN LOS 10 PUNTOS RESPECTIVOS AL SCORE DEBIDO A QUE GANO LA RONDA
                cout<<"EL GANADOR DE LA RONDA "<<ronda<<" ES EL "<<jugador_dos.nombre<<". SU SCORE AHORA ES DE: "<<jugador_dos.score<<endl<<endl;
                RondaNueva(); //SE LLAMA LA FUNCION RONDA NUEVA QUE RESTABLECE TODOS LOS VALORES NECESARIOS PARA PODER VOLVER A JUGAR
                break;
            }
        else{
            opcion=Poner_Ficha_Del_Jugador_Uno; //SI NO GANO, SE LE ASIGNA UN VALOR AL CASE PARA QUE EL JUGADOR #1 PONGA SU FICHA
        }
        break; //EL BREAK PARA QUE SEA CAPAZ DE DIRIJIRSE AL NUEVO CASE ASIGNADO EN CONDICIONAL ANTERIOR

        case Fin_De_La_Partida: //DOCEAVO CASE CON VALOR DE 11

            system("CLS");
            ResultadosFinales(ganador_final); //SE LLAMA A LA FUNCION RESULTADOSFINALES
            ReinicioJuego(); //SE LLAMA A LA FUNCION REINICIO DEL JUEGO POR SI EL USUARIO DESEA REINICIAR Y JUGAR NUEVAMENTE
            break;

        }
    }
}

void Menu(){ //FUNCION ENCARGADA DE REALIZAR UN MENU INICIAL AGRADABLE

    cout<<"                                        -------------------------------------"<<endl;
    cout<<"                                        |BIENVENIDO AL JUEGO CUATRO EN LINEA|"<<endl;
    cout<<"                                        -------------------------------------"<<endl<<endl;
    cout<<"       .:ESTE JUEGO CONSISTE EN COLOCAR CUATRO O TRES FICHAS EN LINEA DE MANERA VERTICAL, HORIZONTAL O DIAGONAL:."<<endl;
    cout<<"                         .:PODRAS ELEGIR SI QUIERES JUGAR CON UN AMIGO O CONTRA EL COMPUTADOR:."<<endl;
    cout<<"                              .:PODRAS ELEGIR SI QUIERES QUE EL JUEGO SEA DIFICIL O NO:."<<endl;
    cout<<"                                            .:SIN MAS DILACION, EMPECEMOS:."<<endl<<endl<<endl;
    cout<<"CONFIGURANDO OPCIONES DE JUEGO..."<<endl<<endl<<endl<<endl;

}

int NumeroJugadores(int num_juga){ //FUNCION ENCARGADA DE PEDIRLE AL USUARIO LOS JUGADORES CON LOS QUE DESEA JUGAR

    cout<<"CON QUE JUGADORES QUIERES JUGAR? (1=TU vs AMIGO, 2=TU vs PC): ";
    cin>>num_juga; //NO SE DECLARA LA VARIABLE AL INICIO DE LA FUNCION YA QUE ES UNA VARIABLE GLOBAL

    return num_juga;

}

void NombreJugadores(int num_juga){ //FUNCION ENCARGADA DE PEDIR LOS NOMBRES DE LOS JUGADORES QUE VAN A JUGAR

    if(num_juga==1){ //NO SE DECLARA LA VARIABLE NUM_JUGA AL INICIO DE LA FUNCION YA QUE ES UNA VARIABLE GLOBAL
        cout<<"INGRESA EL NOMBRE DEL JUGADOR #1: ";
        cin>>jugador_uno.nombre;
        cout<<"INGRESA EL NOMBRE DEL JUGADOR #2: ";
        cin>>jugador_dos.nombre;
        cout<<endl;
    }
    else{
        cout<<"INGRESA EL NOMBRE DEL JUGADOR #1: ";
        cin>>jugador_uno.nombre;
        jugador_dos.nombre="PC"; //SE LE ASIGNA PC AL JUGADOR DOS SIN PREGUNTAR YA QUE EN ESTE CASO, EL USUARIO DECIDIO JUGAR CONTRA EL PC
        cout<<endl;
    }

}

int NumeroFichas(int num_fichas){ //FUNCION ENCARGADA DE PREGUNTAR EL NUMERO DE FICHAS QUE HAY QUE UNIR PARA GANAR

    cout<<"QUIERES QUE EL JUEGO SE GANE UNIENDO TRES O CUATRO FICHAS?: ";
    cin>>num_fichas; //NO SE DECLARA LA VARIABLE AL INICIO DE LA FUNCION YA QUE ES UNA VARIABLE GLOBAL
    cout<<endl;

    return num_fichas;

}

int DificultadJuego(int dific){ //FUNCION ENCARGADA DE PREGUNTAR SI SE DESEA JUGAR EN EL MODO CLASICO O EN EL DIFICIL

    cout<<"QUIERES JUGAR LA MODALIDAD CLASICA O LA DIFICIL? (EL MODO DIFICIL CONSISTE EN UN CONTRARELOJ) (1=CLASICA, 2=DIFICIL): ";
    cin>>dific; //NO SE DECLARA LA VARIABLE AL INICIO DE LA FUNCION YA QUE ES UNA VARIABLE GLOBAL

    return dific;

}

void NombreScore(){ //FUNCION ENCARGADA DE IR MOSTRANDO EL NOMBRE DEL JUGADOR CON SU SCORE RESPECTIVO

    if(ronda<=5){
    cout<<endl<<"--------------------------------"<<endl;
    cout<<"|ESTAS JUGANDO LA RONDA #"<<ronda<<" DE 5|"<<endl;
    }
    cout<<"--------------------------------"<<endl;
    cout<<"        "<<jugador_uno.nombre<<" - SCORE "<<jugador_uno.score<<endl;
    cout<<"        "<<jugador_dos.nombre<<" - SCORE "<<jugador_dos.score<<endl;
    cout<<"--------------------------------"<<endl;

}

char TableroJuego(char Tablero[6][7]){ //FUNCION ENCARGADA DE DISEÑAR E IMPRIMIR EL TABLERO DEL JUEGO

    cout<<endl<<endl<<"                                          .::TABLERO DE CUATRO EN LINEA::."<<endl<<endl;
    cout<<"                                    ___________________________________________"<<endl;

    for(int i=0;i<6;i++){
        cout<<"                                    |  ";
        for(int j=0;j<7;j++){
            cout<<Tablero[i][j]<<"  |  ";
        }
        cout<<endl;
    }

    cout<<"                                    -------------------------------------------"<<endl;
    cout<<"                                    |  1  |  2  |  3  |  4  |  5  |  6  |  7  |"<<endl<<endl;

}

bool Temporizador(){ //FUNCION ENCARGADA DE CONTROLAR EL TIEMPO EN EL QUE SE PONEN LAS FICHAS SOLO SI SE ESCOGIO EL MODO DIFICIL

    //LAS FUNCIONES AUX1 Y AUX2 TOMARAN EL VALOR MOMENTANEO DEL LUGAR EN EL QUE SE COLOCARA LA FICHA. LUEGO, SE ASIGNARAN DICHOS VALORES A LA VARIABLE CORRESPONDIENTE PON_FICHA
    int aux1, aux2, tiempo;
    double tiempo0, tiempo1;

    tardanza=false;
    pon_ficha=0;

    tiempo0=clock();

    if(turno_jugador==0){ //ESTO SUCEDERA CUANDO EL TURNO LO TENGA EL JUGADOR #1
    cout<<"EL TURNO ES DEL JUGADOR: "<<jugador_uno.nombre<<"."<<endl;
    cout<<"INGRESA EL NUMERO EN EL QUE QUIERES PONER LA FICHA (X): ";
    cin>>aux1;

    tiempo1=clock();

    tiempo=(double(tiempo1-tiempo0)/CLOCKS_PER_SEC);

    if(tiempo>2){ //SI EL TIEMPO ES MAYOR A DOS SEGUNDOS EL JUGADOR PERDERA EL TURNO
        cout<<endl<<endl;
        cout<<".:LO SIENTO, TARDASTE MAS DE DOS SEGUDOS EN INGRESAR LA FICHA. PIERDES EL TURNO:."<<endl;
        bool tardanza=true; //LA VARIABLE BOOLEANA DE TARDANZA PASARA A SER TRUE Y DEBIDO A ESTO, EL JUGADOR NO PODRA PONER LA FICHA EN LA FUNCION PONERFICHAS
        pon_ficha=aux1;
        Sleep(3000); //EL SLEEP PARA QUE EL USUARIO ALCANCE A LEER EL MENSAJE QUE LE INFORMA QUE PERDIO EL TURNO
    }
            else{
                bool tardanza=false; //SI NO TARDO MAS DE DOS SEGUNDOS EL BOOLEANO TARDANZA SERA FALSO PARA QUE EN LA FUNCION PONERFICHAS EL JUGADOR SI PUEDA PONER LA FICHA
                pon_ficha=aux1; //ADEMAS, A LA VARIABLE PON_FICHA SE LE ASIGNARA EL VALOR DE AUX1 COMO SE DIJO ANTERIORMENTE
            }
}

    else if(turno_jugador==1){ //ESTO SUCEDERA CUANDO EL TURNO LO TENGA EL JUGADOR #2
    cout<<"EL TURNO ES DEL JUGADOR: "<<jugador_dos.nombre<<"."<<endl;
    cout<<"INGRESA EL NUMERO EN EL QUE QUIERES PONER LA FICHA (O): ";
    cin>>aux2;

    tiempo1=clock();

    tiempo=(double(tiempo1-tiempo0)/CLOCKS_PER_SEC);

    if(tiempo>2){ //SI EL TIEMPO ES MAYOR A DOS SEGUNDOS EL JUGADOR PERDERA EL TURNO
        cout<<endl<<endl;
        cout<<".:LO SIENTO, TARDASTE MAS DE DOS SEGUDOS EN INGRESAR LA FICHA. PIERDES EL TURNO:."<<endl;
        bool tardanza=true; //LA VARIABLE BOOLEANA DE TARDANZA PASARA A SER TRUE Y DEBIDO A ESTO, EL JUGADOR NO PODRA PONER LA FICHA EN LA FUNCION PONERFICHAS
        pon_ficha=aux2;
        Sleep(3000); //EL SLEEP PARA QUE EL USUARIO ALCANCE A LEER EL MENSAJE QUE LE INFORMA QUE PERDIO EL TURNO
    }
    else{
        bool tardanza=false; //SI NO TARDO MAS DE DOS SEGUNDOS EL BOOLEANO TARDANZA SERA FALSO PARA QUE EN LA FUNCION PONERFICHAS EL JUGADOR SI PUEDA PONER LA FICHA
        pon_ficha=aux2; //ADEMAS, A LA VARIABLE PON_FICHA SE LE ASIGNARA EL VALOR DE AUX2 COMO SE DIJO ANTERIORMENTE
    }
}

}

int PonerFichas(){ //FUNCION ENCARGADA DE PONER LAS FICHAS DEL JUGADOR RESPECTIVO EN EL TABLERO

    int aleat=0; //ESTA VARIABLE SE CREA PARA GUARDAR EL NUMERO ALETORIO QUE GENERA EL SRAND POR SI SE DESEA JUGAR CONTRA EL PC

    //FICHA_JUGADOR==0 JUGADOR#1
    //FICHA_JUGADOR==1 JUGADOR#2
    //FICHA JUGADOR==2 COMPUTADOR

    if(tardanza==false){ //TARDANZA INICIALMENTE TIENE EL VALOR DE FALSE, PERO ESTA AQUI POR SI SE DECIDIO JUGAR EN EL MODO DIFICIL Y EL JUGADOR TARDO MAS DE DOS SEGUNDOS EN PONER LA FICHA
    if(turno_jugador==0){ //FICHA_JUGADOR==0 PORQUE ESTE VALOR INDICARA QUE SE EVALUARA LA COLOCACION DE LAS FICHAS DEL JUGADOR #1
    if(dific==1){ //ESTA PARTE SOLO SE REALIZARA SI NO HAY DIFCULTAD, PORQUE DE LO CONTRARIO, ESTO SE PREGUNTA EN LA FUNCION TEMPORIZADOR
        cout<<"EL TURNO ES DEL JUGADOR: "<<jugador_uno.nombre<<"."<<endl;
        cout<<"INGRESA EL NUMERO EN EL QUE QUIERES PONER LA FICHA (X): ";
        cin>>pon_ficha;
    }
        if(pon_ficha==1){ //DESDE LA LINEA 393 HASTA LA LINEA 580 SE EVALUA EL LUGAR EN EL QUE SE COLOCARA LA FICHA DEL JUGADOR #1
                if(Tablero[5][0]=='-'){
                    Tablero[5][0]='X';
                }
                    else if(Tablero[4][0]=='-'){
                        Tablero[4][0]='X';
                    }
                        else if(Tablero[3][0]=='-'){
                            Tablero[3][0]='X';
                        }
                            else if(Tablero[2][0]=='-'){
                                Tablero[2][0]='X';
                            }
                                else if(Tablero[1][0]=='-'){
                                    Tablero[1][0]='X';
                                }
                                    else if(Tablero[0][0]=='-'){
                                        Tablero[0][0]='X';
                                    }
                                        else{
                                            cout<<endl; //ESTE MENSAJE SE MUESTRA SI NO HAY ESPACIO EN LA COLUMNA DONDE SE QUERIA COLOCAR LA FICHA
                                            cout<<".:ESTA COLUMNA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000); //EL SLEEP HACE QUE EL PROGRAME SE CONGELE DURNTE DOS SEGUNDOS PARA QUE EL USUARIO ALCANCE A LEER EL MENSAJE ANTERIOR
                                        }
        }

        if(pon_ficha==2){
                if(Tablero[5][1]=='-'){
                    Tablero[5][1]='X';
                }
                    else if(Tablero[4][1]=='-'){
                        Tablero[4][1]='X';
                    }
                        else if(Tablero[3][1]=='-'){
                            Tablero[3][1]='X';
                        }
                            else if(Tablero[2][1]=='-'){
                                Tablero[2][1]='X';
                            }
                                else if(Tablero[1][1]=='-'){
                                    Tablero[1][1]='X';
                                }
                                    else if(Tablero[0][1]=='-'){
                                        Tablero[0][1]='X';
                                    }
                                        else{
                                            cout<<endl;
                                            cout<<".:ESTA COLUMNA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000);
                                        }
        }

        if(pon_ficha==3){
                if(Tablero[5][2]=='-'){
                    Tablero[5][2]='X';
                }
                    else if(Tablero[4][2]=='-'){
                        Tablero[4][2]='X';
                    }
                        else if(Tablero[3][2]=='-'){
                            Tablero[3][2]='X';
                        }
                            else if(Tablero[2][2]=='-'){
                                Tablero[2][2]='X';
                            }
                                else if(Tablero[1][2]=='-'){
                                    Tablero[1][2]='X';
                                }
                                    else if(Tablero[0][2]=='-'){
                                        Tablero[0][2]='X';
                                    }
                                        else{
                                            cout<<endl;
                                            cout<<".:ESTA COLUMNA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000);
                                        }
        }

        if(pon_ficha==4){
                if(Tablero[5][3]=='-'){
                    Tablero[5][3]='X';
                }
                    else if(Tablero[4][3]=='-'){
                        Tablero[4][3]='X';
                    }
                        else if(Tablero[3][3]=='-'){
                            Tablero[3][3]='X';
                        }
                            else if(Tablero[2][3]=='-'){
                                Tablero[2][3]='X';
                            }
                                else if(Tablero[1][3]=='-'){
                                    Tablero[1][3]='X';
                                }
                                    else if(Tablero[0][3]=='-'){
                                        Tablero[0][3]='X';
                                    }
                                        else{
                                            cout<<endl;
                                            cout<<".:ESTA COLUMNA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000);
                                        }
        }

        if(pon_ficha==5){
                if(Tablero[5][4]=='-'){
                    Tablero[5][4]='X';
                }
                    else if(Tablero[4][4]=='-'){
                        Tablero[4][4]='X';
                    }
                        else if(Tablero[3][4]=='-'){
                            Tablero[3][4]='X';
                        }
                            else if(Tablero[2][4]=='-'){
                                Tablero[2][4]='X';
                            }
                                else if(Tablero[1][4]=='-'){
                                    Tablero[1][4]='X';
                                }
                                    else if(Tablero[0][4]=='-'){
                                        Tablero[0][4]='X';
                                    }
                                        else{
                                            cout<<endl;
                                            cout<<".:ESTA COLUMNA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000);
                                        }
        }

        if(pon_ficha==6){
                if(Tablero[5][5]=='-'){
                    Tablero[5][5]='X';
                }
                    else if(Tablero[4][5]=='-'){
                        Tablero[4][5]='X';
                    }
                        else if(Tablero[3][5]=='-'){
                            Tablero[3][5]='X';
                        }
                            else if(Tablero[2][5]=='-'){
                                Tablero[2][5]='X';
                            }
                                else if(Tablero[1][5]=='-'){
                                    Tablero[1][5]='X';
                                }
                                    else if(Tablero[0][5]=='-'){
                                        Tablero[0][5]='X';
                                    }
                                        else{
                                            cout<<endl;
                                            cout<<".:ESTA COLUMNA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000);
                                        }
        }

        if(pon_ficha==7){
                if(Tablero[5][6]=='-'){
                    Tablero[5][6]='X';
                }
                    else if(Tablero[4][6]=='-'){
                        Tablero[4][6]='X';
                    }
                        else if(Tablero[3][6]=='-'){
                            Tablero[3][6]='X';
                        }
                            else if(Tablero[2][6]=='-'){
                                Tablero[2][6]='X';
                            }
                                else if(Tablero[1][6]=='-'){
                                    Tablero[1][6]='X';
                                }
                                    else if(Tablero[0][6]=='-'){
                                        Tablero[0][6]='X';
                                    }
                                        else{
                                            cout<<endl;
                                            cout<<".:ESTA COLUMNA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000);
                                        }
            }
        if(pon_ficha>7||pon_ficha<1){
            cout<<endl; //SI INGRESA UNA COLUMNA QUE NO ESTA DENTRO DEL TABLERO SE MOSTRARA ESTE MENSAJE
            cout<<".:INGRESASTE UNA COLUMNA INCORRECTA, PIERDES EL TURNO:.";
            Sleep(2000); //NUEVAMENTE UN SLEEP DE DOS SEGUNDOS PARA QUE EL USUARIO ALCANCE A LEER
        }
    }
}

    if(tardanza==false){ //TARDANZA INICIALMENTE TIENE EL VALOR DE FALSE, PERO ESTA AQUI POR SI SE DECIDIO JUGAR EN EL MODO DIFICIL Y EL JUGADOR TARDO MAS DE DOS SEGUNDOS EN PONER LA FICHA
    if(turno_jugador==1){ //FICHA_JUGADOR==1 PORQUE ESTE VALOR INDICARA QUE SE EVALUARA LA COLOCACION DE LAS FICHAS DEL JUGADOR #2
    if(dific==1){ //ESTA PARTE SOLO SE REALIZARA SI NO HAY DIFCULTAD, PORQUE DE LO CONTRARIO, ESTO SE PREGUNTA EN LA FUNCION TEMPORIZADOR
        cout<<"EL TURNO ES DEL JUGADOR: "<<jugador_dos.nombre<<"."<<endl;
        cout<<"INGRESA EL NUMERO EN EL QUE QUIERES PONER LA FICHA (O): ";
        cin>>pon_ficha;
    }
        if(pon_ficha==1){ //DESDE LA LINEA 589 HASTA LA LINEA 776 SE EVALUA EL LUGAR EN EL QUE SE COLOCARA LA FICHA DEL JUGADOR #2
                if(Tablero[5][0]=='-'){
                    Tablero[5][0]='O';
                }
                    else if(Tablero[4][0]=='-'){
                        Tablero[4][0]='O';
                    }
                        else if(Tablero[3][0]=='-'){
                            Tablero[3][0]='O';
                        }
                            else if(Tablero[2][0]=='-'){
                                Tablero[2][0]='O';
                            }
                                else if(Tablero[1][0]=='-'){
                                    Tablero[1][0]='O';
                                }
                                    else if(Tablero[0][0]=='-'){
                                        Tablero[0][0]='O';
                                    }
                                        else{
                                            cout<<endl; //ESTE MENSAJE SE MUESTRA SI NO HAY ESPACIO EN LA COLUMNA DONDE SE QUERIA COLOCAR LA FICHA
                                            cout<<".:ESTA FILA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000); //EL SLEEP PARA QUE EL USUARIO ALCANCE A LEER
                                        }
        }

        if(pon_ficha==2){
                if(Tablero[5][1]=='-'){
                    Tablero[5][1]='O';
                }
                    else if(Tablero[4][1]=='-'){
                        Tablero[4][1]='O';
                    }
                        else if(Tablero[3][1]=='-'){
                            Tablero[3][1]='O';
                        }
                            else if(Tablero[2][1]=='-'){
                                Tablero[2][1]='O';
                            }
                                else if(Tablero[1][1]=='-'){
                                    Tablero[1][1]='O';
                                }
                                    else if(Tablero[0][1]=='-'){
                                        Tablero[0][1]='O';
                                    }
                                        else{
                                            cout<<endl;
                                            cout<<".:ESTA FILA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000);
                                        }
        }

        if(pon_ficha==3){
                if(Tablero[5][2]=='-'){
                    Tablero[5][2]='O';
                }
                    else if(Tablero[4][2]=='-'){
                        Tablero[4][2]='O';
                    }
                        else if(Tablero[3][2]=='-'){
                            Tablero[3][2]='O';
                        }
                            else if(Tablero[2][2]=='-'){
                                Tablero[2][2]='O';
                            }
                                else if(Tablero[1][2]=='-'){
                                    Tablero[1][2]='O';
                                }
                                    else if(Tablero[0][2]=='-'){
                                        Tablero[0][2]='O';
                                    }
                                        else{
                                            cout<<endl;
                                            cout<<".:ESTA FILA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000);
                                        }
        }

        if(pon_ficha==4){
                if(Tablero[5][3]=='-'){
                    Tablero[5][3]='O';
                }
                    else if(Tablero[4][3]=='-'){
                        Tablero[4][3]='O';
                    }
                        else if(Tablero[3][3]=='-'){
                            Tablero[3][3]='O';
                        }
                            else if(Tablero[2][3]=='-'){
                                Tablero[2][3]='O';
                            }
                                else if(Tablero[1][3]=='-'){
                                    Tablero[1][3]='O';
                                }
                                    else if(Tablero[0][3]=='-'){
                                        Tablero[0][3]='O';
                                    }
                                        else{
                                            cout<<endl;
                                            cout<<".:ESTA FILA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000);
                                        }
        }

        if(pon_ficha==5){
                if(Tablero[5][4]=='-'){
                    Tablero[5][4]='O';
                }
                    else if(Tablero[4][4]=='-'){
                        Tablero[4][4]='O';
                    }
                        else if(Tablero[3][4]=='-'){
                            Tablero[3][4]='O';
                        }
                            else if(Tablero[2][4]=='-'){
                                Tablero[2][4]='O';
                            }
                                else if(Tablero[1][4]=='-'){
                                    Tablero[1][4]='O';
                                }
                                    else if(Tablero[0][4]=='-'){
                                        Tablero[0][4]='O';
                                    }
                                        else{
                                            cout<<endl;
                                            cout<<".:ESTA FILA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000);
                                        }
        }

        if(pon_ficha==6){
                if(Tablero[5][5]=='-'){
                    Tablero[5][5]='O';
                }
                    else if(Tablero[4][5]=='-'){
                        Tablero[4][5]='O';
                    }
                        else if(Tablero[3][5]=='-'){
                            Tablero[3][5]='O';
                        }
                            else if(Tablero[2][5]=='-'){
                                Tablero[2][5]='O';
                            }
                                else if(Tablero[1][5]=='-'){
                                    Tablero[1][5]='O';
                                }
                                    else if(Tablero[0][5]=='-'){
                                        Tablero[0][5]='O';
                                    }
                                        else{
                                            cout<<endl;
                                            cout<<".:ESTA FILA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000);
                                        }
        }

        if(pon_ficha==7){
                if(Tablero[5][6]=='-'){
                    Tablero[5][6]='O';
                }
                    else if(Tablero[4][6]=='-'){
                        Tablero[4][6]='O';
                    }
                        else if(Tablero[3][6]=='-'){
                            Tablero[3][6]='O';
                        }
                            else if(Tablero[2][6]=='-'){
                                Tablero[2][6]='O';
                            }
                                else if(Tablero[1][6]=='-'){
                                    Tablero[1][6]='O';
                                }
                                    else if(Tablero[0][6]=='-'){
                                        Tablero[0][6]='O';
                                    }
                                        else{
                                            cout<<endl;
                                            cout<<".:ESTA FILA YA ESTA LLENA, INTENTA CON OTRA EN TU PROXIMO TURNO:.";
                                            Sleep(2000);
                                        }
            }
        if(pon_ficha>7||pon_ficha<1){
            cout<<endl; //SI INGRESA UNA COLUMNA QUE NO ESTA DENTRO DEL TABLERO SE MOSTRARA ESTE MENSAJE
            cout<<".:INGRESASTE UNA COLUMNA INCORRECTA, PIERDES EL TURNO:.";
            Sleep(2000); //NUEVAMENTE UN SLEEP DE DOS SEGUNDOS PARA QUE EL USUARIO ALCANCE A LEER
        }
    }
}

    if(turno_jugador==2){ //FICHA_JUGADOR==2 PORQUE ESTE VALOR INDICARA QUE SE EVALUARA LA COLOCACION DE LAS FICHAS DEL COMPUTADOR

            srand(time(NULL)); //AQUI SE ASIGNA UN NUMERO ALEATORIO ENTRE EL 1 Y EL 7 PARA QUE EL PC PONGA SU FICHA
            aleat=1+rand()%(8-1);

        cout<<"EL TURNO ES DEL "<<jugador_dos.nombre<<"."<<endl;
        cout<<"PENSANDO...";
        Sleep(3000); //ESTO HACE QUE SE LE DE UNA ESPECIE DE "ANIMACION" AL JUEGO

        if(aleat==1){ //DESDE LA LINEA 787 HASTA LA LINEA 933 SE EVALUA EL LUGAR EN EL QUE SE COLOCARA LA FICHA DEL JUGADOR #2  QUE EN ESTE CASO SERIA EL PC
                if(Tablero[5][0]=='-'){
                    Tablero[5][0]='O';
                }
                    else if(Tablero[4][0]=='-'){
                        Tablero[4][0]='O';
                    }
                        else if(Tablero[3][0]=='-'){
                            Tablero[3][0]='O';
                        }
                            else if(Tablero[2][0]=='-'){
                                Tablero[2][0]='O';
                            }
                                else if(Tablero[1][0]=='-'){
                                    Tablero[1][0]='O';
                                }
                                    else if(Tablero[0][0]=='-'){
                                        Tablero[0][0]='O';
                                    }
        }

        if(aleat==2){
                if(Tablero[5][1]=='-'){
                    Tablero[5][1]='O';
                }
                    else if(Tablero[4][1]=='-'){
                        Tablero[4][1]='O';
                    }
                        else if(Tablero[3][1]=='-'){
                            Tablero[3][1]='O';
                        }
                            else if(Tablero[2][1]=='-'){
                                Tablero[2][1]='O';
                            }
                                else if(Tablero[1][1]=='-'){
                                    Tablero[1][1]='O';
                                }
                                    else if(Tablero[0][1]=='-'){
                                        Tablero[0][1]='O';
                                    }
        }

        if(aleat==3){
                if(Tablero[5][2]=='-'){
                    Tablero[5][2]='O';
                }
                    else if(Tablero[4][2]=='-'){
                        Tablero[4][2]='O';
                    }
                        else if(Tablero[3][2]=='-'){
                            Tablero[3][2]='O';
                        }
                            else if(Tablero[2][2]=='-'){
                                Tablero[2][2]='O';
                            }
                                else if(Tablero[1][2]=='-'){
                                    Tablero[1][2]='O';
                                }
                                    else if(Tablero[0][2]=='-'){
                                        Tablero[0][2]='O';
                                    }
        }

        if(aleat==4){
                if(Tablero[5][3]=='-'){
                    Tablero[5][3]='X';
                }
                    else if(Tablero[4][3]=='-'){
                        Tablero[4][3]='X';
                    }
                        else if(Tablero[3][3]=='-'){
                            Tablero[3][3]='X';
                        }
                            else if(Tablero[2][3]=='-'){
                                Tablero[2][3]='X';
                            }
                                else if(Tablero[1][3]=='-'){
                                    Tablero[1][3]='X';
                                }
                                    else if(Tablero[0][3]=='-'){
                                        Tablero[0][3]='X';
                                    }
        }

        if(aleat==5){
                if(Tablero[5][4]=='-'){
                    Tablero[5][4]='O';
                }
                    else if(Tablero[4][4]=='-'){
                        Tablero[4][4]='O';
                    }
                        else if(Tablero[3][4]=='-'){
                            Tablero[3][4]='O';
                        }
                            else if(Tablero[2][4]=='-'){
                                Tablero[2][4]='O';
                            }
                                else if(Tablero[1][4]=='-'){
                                    Tablero[1][4]='O';
                                }
                                    else if(Tablero[0][4]=='-'){
                                        Tablero[0][4]='O';
                                    }
        }

        if(aleat==6){
                if(Tablero[5][5]=='-'){
                    Tablero[5][5]='O';
                }
                    else if(Tablero[4][5]=='-'){
                        Tablero[4][5]='O';
                    }
                        else if(Tablero[3][5]=='-'){
                            Tablero[3][5]='O';
                        }
                            else if(Tablero[2][5]=='-'){
                                Tablero[2][5]='O';
                            }
                                else if(Tablero[1][5]=='-'){
                                    Tablero[1][5]='O';
                                }
                                    else if(Tablero[0][5]=='-'){
                                        Tablero[0][5]='O';
                                    }
        }

        if(aleat==7){
                if(Tablero[5][6]=='-'){
                    Tablero[5][6]='O';
                }
                    else if(Tablero[4][6]=='-'){
                        Tablero[4][6]='O';
                    }
                        else if(Tablero[3][6]=='-'){
                            Tablero[3][6]='O';
                        }
                            else if(Tablero[2][6]=='-'){
                                Tablero[2][6]='O';
                            }
                                else if(Tablero[1][6]=='-'){
                                    Tablero[1][6]='O';
                                }
                                    else if(Tablero[0][6]=='-'){
                                        Tablero[0][6]='O';
                                    }
            }
    }

    //SI TODO EL TABLERO SE LLENA (COSA QUE ES MUY POCO PROBABLE) ESTE IF IMPRIME UN MENSAJE DICIENDO QUE EL TABLERO SE LLENO Y VA A LIMPIAR EL TABLERO PARA COMENZAR OTRA VEZ
    if(Tablero[0][0]!='-'&&Tablero[0][1]!='-'&&Tablero[0][2]!='-'&&Tablero[0][3]!='-'&&Tablero[0][4]!='-'&&Tablero[0][5]!='-'&&Tablero[0][6]!='-'){
        cout<<endl<<endl;
        cout<<"EL TABLERO DE JUEGO ESTA LLENO Y NINGUN JUGADOR GANO, HUBO EN EMPATE"<<endl<<endl;
        ronda--;
        RondaNueva();
    }

    //EN ESTE ULTIMO IF SE CAMBIA EL VALOR DE LA VARIABLE FICHA_JUGADOR SEGUN EL ULTIMO JUGADOR QUE COLOCO LA FICHA
    if(turno_jugador==0||turno_jugador==1||turno_jugador==2){

        if(turno_jugador==0){
            if(num_juga==1){
                turno_jugador=1;
            }
                else{
                    turno_jugador=2;
                }
        }
            else if(turno_jugador==1){
                turno_jugador=0;
            }
                else if(turno_jugador==2){
                    turno_jugador=0;
                }
    }

}

bool GanadorRonda(){ //FUNCION ENCARGADA DE DECIR CUAL ES EL GANADOR DE CADA RONDA

    if(num_fichas==3){ //SE EVALUARA SI SE JUNTARON TRES FICHAS (COMO LO INDICO EL USUARIO AL INICIO) DE CUALQUIERA DE LOS DOS JUGADORES
            for(int i=5;i>=0;i--){
                for(int j=0;j<7;j++){
                    if(Tablero[i][j]=='X'&&Tablero[i-1][j]=='X'&&Tablero[i-2][j]=='X'){
                        ganador=true;
                    }
                        else if(Tablero[i][j]=='X'&&Tablero[i][j+1]=='X'&&Tablero[i][j+2]=='X'){
                            ganador=true;
                        }
                            else if(Tablero[i][j]=='X'&&Tablero[i-1][j+1]=='X'&&Tablero[i-2][j+2]=='X'){
                                ganador=true;
                            }
                                else if(Tablero[i][j]=='O'&&Tablero[i-1][j]=='O'&&Tablero[i-2][j]=='O'){
                                    ganador=true;
                                }
                                    else if(Tablero[i][j]=='O'&&Tablero[i][j+1]=='O'&&Tablero[i][j+2]=='O'){
                                        ganador=true;
                                    }
                                        else if(Tablero[i][j]=='O'&&Tablero[i-1][j+1]=='O'&&Tablero[i-2][j+2]=='O'){
                                            ganador=true;
                                        }
            }
        }
    }   //SI SE JUNTARON TRES FICHAS EN CUALQUIER DIRECCION, LA VARIABLE BOOLEANA GANADOR PASARA A SER TRUE (ESTA VARIABLE SE SEGUIRA UTILIZANDO EN EL MAIN)

    if(num_fichas==4){ //SE EVALUARA SI SE JUNTARON CUATRO FICHAS (COMO LO INDICO EL USUARIO AL INICIO) DE CUALQUIERA DE LOS DOS JUGADORES
            for(int i=5;i>=0;i--){
                for(int j=0;j<7;j++){
                    if(Tablero[i][j]=='X'&&Tablero[i-1][j]=='X'&&Tablero[i-2][j]=='X'&&Tablero[i-3][j]=='X'){
                        ganador=true;
                    }
                        else if(Tablero[i][j]=='X'&&Tablero[i][j+1]=='X'&&Tablero[i][j+2]=='X'&&Tablero[i][j+3]=='X'){
                            ganador=true;
                        }
                            else if(Tablero[i][j]=='X'&&Tablero[i-1][j+1]=='X'&&Tablero[i-2][j+2]=='X'&&Tablero[i-3][j+3]=='X'){
                                ganador=true;
                            }
                                else if(Tablero[i][j]=='O'&&Tablero[i-1][j]=='O'&&Tablero[i-2][j]=='O'&&Tablero[i-3][j]=='O'){
                                    ganador=true;
                                }
                                    else if(Tablero[i][j]=='O'&&Tablero[i][j+1]=='O'&&Tablero[i][j+2]=='O'&&Tablero[i][j+3]=='O'){
                                        ganador=true;
                                    }
                                        else if(Tablero[i][j]=='O'&&Tablero[i-1][j+1]=='O'&&Tablero[i-2][j+2]=='O'&&Tablero[i-3][j+3]=='O'){
                                            ganador=true;
                                        }
            }
        }
    } //SI SE JUNTARON CUATRO FICHAS EN CUALQUIER DIRECCION, LA VARIABLE BOOLEANA GANADOR PASARA A SER TRUE (ESTA VARIABLE SE SEGUIRA UTILIZANDO EN EL MAIN)

}

void RondaNueva(){ //FUNCION ENCARGADA DE REINICIAR TODOS LOS VALORES NECESARIOS PARA INICIAR UNA NUEVA RONDA

    //SE VUELVE A LLENAR LA MATRIZ TABLERO DE -
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            Tablero[i][j]='-';
        }
    }

    ganador=false;
    turno_jugador=0;
    ronda++;

    if(ronda<=5){ //SI LA RONDA ES MENOR A CINCO SE VOLVERAN A COLOCAR FICHAS EN EL TABLERO VACIO
        cout<<"ESPERA UN MOMENTO, ESTAMOS LIMPIANDO EL TABLERO...";
        Sleep(5000);
        opcion=Poner_Ficha_Del_Jugador_Uno;
    }
    else{ //SI LA RONDA NO ES MENOR A CINCO A LA VARIABLE RESPUESTA SE LE ASIGNARA EL CASE FIN_DE_LA_PARTIDA
        Sleep(5000);
        opcion=Fin_De_La_Partida;
    }

}

string ResultadosFinales(string ganador_final){ //FUNCION ENCARGADA DE MOSTRAR TODOS LOS RESULTADOS FINALES DE UNA MANERA AGRADABLE A LA VISTA

    //UN CONDICIONAL SENCILLO PARA EVALUAR QUIEN ES GANADOR DE TODO EL JUEGO
    if(jugador_uno.score>jugador_dos.score){
        ganador_final=jugador_uno.nombre;
    }
    else{
        ganador_final=jugador_dos.nombre;
    }

            TableroJuego(Tablero);
            cout<<"ESTOS SON LOS RESULTADOS FINALES DEL JUEGO:"<<endl; Sleep(3000);
            cout<<"PREPARADO?"<<endl<<endl; Sleep(3000);
            NombreScore(); Sleep(3000); cout<<endl;
            cout<<"EL GANADOR DEL JUEGO ES... "; Sleep(3000);
            cout<<ganador_final; Sleep(3000); cout<<endl;
            //SE UTILIZA MUCHO EL SLEEP PARA DAR UN MENSAJE AGRADABLE A LA VISTA Y HACER QUE PAREZCA UNA ANIMACION
            cout<<"                                             --------------------------"<<endl;
            cout<<"                                             |"; Sleep(300);
            cout<<"M"; Sleep(300); cout<<"U"; Sleep(300); cout<<"C"; Sleep(300); cout<<"H"; Sleep(300); cout<<"A"; Sleep(300); cout<<"S"; Sleep(300);
            cout<<" "; Sleep(300); cout<<"G"; Sleep(300); cout<<"R"; Sleep(300); cout<<"A"; Sleep(300); cout<<"C"; Sleep(300); cout<<"I"; Sleep(300);
            cout<<"A"; Sleep(300); cout<<"S"; Sleep(300); cout<<" "; Sleep(300); cout<<"P"; Sleep(300); cout<<"O"; Sleep(300); cout<<"R"; Sleep(300);
            cout<<" "; Sleep(300); cout<<"J"; Sleep(300); cout<<"U"; Sleep(300); cout<<"G"; Sleep(300); cout<<"A"; Sleep(300); cout<<"R"; Sleep(300);
            cout<<"|"; Sleep(300); cout<<endl; cout<<"                                             --------------------------"<<endl<<endl;

}

void ReinicioJuego(){ //FUNCION ENCARGADA DE REINICIAR EL JUEGO SI ASI LO PIDE EL USUARIO

    string reini;

    cout<<"DESEAS REINICIAR EL JUEGO?: ";
    cin>>reini;

        //SE VUELVE A RELLENAR LA MATRIZ TABLERO DE -
        if(reini=="SI"||reini=="Si"||reini=="si"){
            for(int i=0;i<6;i++){
                for(int j=0;j<7;j++){
                    Tablero[i][j]='-';
                }
            }

        //SE REINICIAN TODOS LOS VALORES PARA EMPEZAR A JUGAR DE NUEVO
            turno_jugador=0;
            ganador=false;
            ronda=1;
            jugador_uno.score=0;
            jugador_dos.score=0;
            system("CLS");
            opcion=Numero_De_Jugadores;
        }
        else{
            cout<<endl;
            cout<<"ESPERAMOS QUE VUELVAS PRONTO!!"<<endl;
            opcion=12;
        }
}
