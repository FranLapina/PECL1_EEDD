#include "utilidades.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
//Constructor
utilidades::utilidades(){}
//Destructor
utilidades::~utilidades(){}

//PILAS
//Destructor de la Pila
Pila::~Pila()
{
    while(cima) desapilar();
}
//Meter elemento en la Pila
void Pila::apilar(int v)
{
    pNodo nuevo; //Var aux para manipular el nuevo nodo
//Se crea un nodo nuevo
    nuevo = new Nodo(v, cima);
//El comienzo de la pila es el nuevo nodo
    cima = nuevo;
}
//Sacar elemento de la Pila
int Pila::desapilar()
{
    pNodo nodo; //Var aux para manipular el nodo
    int v; //Var aux para el retorno del valor del nodo
    if(!cima) return 0; // Si no hay nodos en la pila se devuelve 0
// Nodo apunta al primer elemento de la pila
    nodo = cima;
//Se asigna a pila toda la pila menos el primer elemento
    cima= nodo->siguiente;
//Se guarda el retorno del valor del nodo
    v = nodo->valor;
//Se borra el nodo
    delete nodo;
    return v;
}

//COLAS

//Destructor
Cola::~Cola()
{
    while(frente) desencolar();
}
//Añadir elemento en la cola
void Cola::encolar(int v)
{
    pNodo nuevo;
    nuevo = new Nodo(v); // Se crea un nodo nuevo
// Si cola no vacía, se añade el nuevo a continuación de ultimo
    if(final) final->siguiente = nuevo;
//El último elemento de la cola es el nuevo nodo
    final= nuevo;
// Si frente es NULL, la cola está vacía y el nuevo nodo pasa a ser el primero
    if(!frente) frente = nuevo;
}

//Leer elemento de la cola
int Cola::desencolar()
{
    pNodo nodo; //Var aux para manipular nodo
    int v; //Var aux para retorno del valor
// Nodo apunta al primer elemento de la pila
    nodo = frente;
    if(!nodo) return 0; // Si no hay nodos en la pila se devuelve 0
//Se asigna a frente la dirección del segundo nodo
    frente = nodo->siguiente;
//Se guarda el valor de retorno
    v = nodo->valor;
    delete nodo; // Se borra el nodo
// Si cola vacía, ultimo debe ser NULL también
    if(!frente) final = NULL;
    return v;
}

//PAQUETE::COORDENADAS

//Randomiza, con un maximo y un minimo, la longitud.
int Paquete::definirLongitud(){
    int lon_max = Paquete::Coordenadas.LON_MAX;
    int lon_min = Paquete::Coordenadas.LON_MIN;
    int longitud = (lon_min + rand() % (lon_max+1 - lon_min));
    return longitud;
}

//Randomiza, con un maximo y un minimo, la latitud.
int Paquete::definirLatitud(){
    int lat_max = Paquete::Coordenadas.LAT_MAX;
    int lat_min = Paquete::Coordenadas.LAT_MIN;
    int latitud = (lat_min + rand() % (lat_max+1 - lat_min));
    return latitud;
}
//Modela la longitud parseandola a string y colocando los numeros de la siguiente forma XXº XX' XX''
//mediante un bucle que añade espacios y caracteres en posiciones determinadas.
std::string Paquete::modelarLongitud(int longitudNumerica){
    std::string longitud = std::to_string(longitudNumerica);
    for(int i = 0; i <= 11; ++i){
        if(i == 3 || i == 7){
            longitud.insert(i," ");
        }else if(i == 2){
            longitud.insert(i,"*"); //al poner el caracter de los grados, sale otra cosa.
        }else if(i == 6 || i == 9 || i == 10){
            longitud.insert(i,"'");
        }
    }
    return longitud;


}
//Modela la latitud parseandola a string y colocando los numeros de la siguiente forma XXº XX' XX''
//mediante un bucle que añade espacios y caracteres en posiciones determinadas.
std::string Paquete::modelarLatitud(int latitudNumerica){
    std::string latitud = std::to_string(latitudNumerica);
    for(int i = 0; i <= 11; ++i){
        if(i == 3 || i == 7){
            latitud.insert(i," ");
        }else if(i == 2){
            latitud.insert(i,"*"); //al poner el caracter de los grados, sale otra cosa.
        }else if(i == 6 || i == 9 || i == 10){
            latitud.insert(i,"'");
        }
    }
    return latitud;
}

//PAQUETE::NIF
//Genera de forma aleatoria numeros del 100 al 99999999
int Paquete::generarNumerosNIF(){
        int maximo = Paquete::NIF.NIF_MAX;
        int minimo = Paquete::NIF.NIF_MIN;
        int numerosNIF;
        numerosNIF = (minimo + rand() % (maximo+1 - minimo));
        return numerosNIF;
}
//parsea el numero a string y completa el NIF añadiendole la letra que le corresponderia para los numeros que tiene
//Y si no llega a 9 digitos (letra incluida) añade 0s a la izquierda hasta completarlo.
std::string Paquete::NIFCompleto(int numerosNIF){
    char letras[] = {'T','R','W','A','G','M','Y',
            'F','P','D','X','B','N','J','Z','S',
            'Q','V','H','L','C','K','E'};
    std::string NIFCompleto;
    char letra;
    int posicion = numerosNIF%23;
    NIFCompleto = std::to_string(numerosNIF);
    NIFCompleto = NIFCompleto+letras[posicion];
    //Comprobar si el NIF tiene un tamaño de 9 caracteres, si no lo tiene se añaden 0s a la izquierda.
    if(NIFCompleto.length() < 9){
        int exceso = 9 - NIFCompleto.length();
        for(int i = 0; i < exceso; ++i){
            NIFCompleto = "0"+NIFCompleto;
        }
    }
    return NIFCompleto;
}



//ID PAQUETE

//Genera los números del ID con un random que va de 0 a 999999
int Paquete::generarNumerosID(){
    int maximo = 999999;
    int minimo = 0;
    int numerosID;
    numerosID = (minimo + rand() % (maximo+1 - minimo));
    return numerosID;
}

//Modela el ID introduciendo 0 a la izquierda en caso de que no cumpla el requisito de 6 cifras numericas
//Y en la posicion 2 introduce una letra generada con un random como 65 de minimo y 90 de maximo que
//acapara las mayusculas a nivel numerico dentro de la tabla ascii y las introduce.
std::string Paquete::modelarID(){
    std::string numerosID = std::to_string(Identificador.numerosID);
    while(numerosID.length() < 6){
        numerosID = "0"+numerosID;
    }
    int maximo = 90;
    int minimo = 65;
    std::string letraID;
    letraID = (minimo + rand() % (maximo+1 - minimo));
    numerosID.insert(2, letraID);
    return numerosID;
}

//ZONA

std::string Paquete::asignarZona(){
    int latitud = Coordenadas.latitudNumerica;
    int longitud = Coordenadas.longitudNumerica;
    if(longitud >= 40295 && latitud >= -3220){
        //NORESTE
        return "NE";
    }else if(longitud > 40295 && latitud < -3220){
        //NOROESTE
        return "NO";
    }else if(longitud <= 40295 && latitud <= -3220){
        //SURESTE
        return "SO";
    }else if(longitud < 40295 && latitud > -3220){
        //SUROESTE
        return "SE";
    }
    return "ERROR";
}

//MENUS


void utilidades::menu_principal(){
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw (52) << "Cola Paqueteria" << setw (40) << "|" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw (14) << "Identificador" << setw (4) << "|" << setw (23) << "Coordenadas" << setw (14) << "|" << setw (12) << "NIF" << setw (10) << "|" << setw(11) << "Zona de" << setw (4) << "|" << endl;
    cout << "|" << setw (11) << "Paquete" << setw (7) << "|" << setw (20) << "Envio" << setw (17) << "|" << setw(17) << "Destinatario" << setw (5) << "|" << setw(10) << "Envio" << setw (5) << "|"<< endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw (11) << "XXXXXXX" << setw (7) << "|" << setw(27) << "XX XX XX , XX XX XX" << setw (10) << "|" << setw(15) << "XXXXXXXXX" << setw (7) << "|" << setw(9) << "XX" << setw(6) << "|" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
}

void utilidades::menu_carga(){
    cout <<  "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(30) << "|" << setw (65) << "Puerto de carga" << setw (55) << "|" << endl;
    cout <<  "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(30) << "|" << setw(17) << "Zona NO" << setw(13) << "|" << setw(17) << "Zona NE" << setw(13) << "|" << setw(17) << "Zona SO" << setw(13) << "|" << setw(17) << "Zona SE" << setw(13) << "|" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw (19) << "Furgoneta 1" << setw (11) << "|" << setw (17) << "XXXXXXX" << setw (13) << "|" << setw (17) << "XXXXXXX" << setw (13) << "|" << setw (17) << "XXXXXXX" << setw (13) << "|"<< setw (17) << "XXXXXXX" << setw (13) << "|"<< endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void utilidades::menu_envio(){
    cout <<  "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(90) << "Envios en Progreso" << setw(70) << "|" << endl;
    cout <<  "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(22) << "Zona NO" << setw(18) << "|" << setw(22) << "Zona NE" << setw(18) << "|" << setw(22) << "Zona SO" << setw(18) << "|" << setw(22) << "Zona SE" << setw(18) << "|" << endl;
    cout <<  "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Furgoneta X" << setw(5) << "|" << setw(14) << "XXXXXXXX" << setw(6) << "|" << setw(15) << "Furgoneta X" << setw(5) << "|" << setw(14) << "XXXXXXXX" << setw(6) << "|" << setw(15) << "Furgoneta X" << setw(5) << "|" << setw(14) << "XXXXXXXX" << setw(6) << "|" << setw(15) << "Furgoneta X" << setw(5) << "|" << setw(14) << "XXXXXXXX" << setw(6) << "|" << endl;
    cout <<  "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void utilidades::menu_entregados(){
    cout << "-------------------------------------------" << endl;
    cout << "|" << setw(29) << "Paquetes entregados" << setw(13) << "|" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "|" << setw(24) << "XXXXXXX" << setw (18)<< "|" << endl;
    cout << "-------------------------------------------" << endl;

}

