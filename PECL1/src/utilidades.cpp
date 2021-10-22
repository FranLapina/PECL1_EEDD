#include "utilidades.h"

utilidades::utilidades()
{
    //ctor
}

utilidades::~utilidades()
{
    //dtor
}

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

