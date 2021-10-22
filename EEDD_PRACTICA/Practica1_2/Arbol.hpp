#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "NodoArbol.hpp"
#include <iostream>

using namespace std;


class Arbol
{
public:
    Arbol();
    void insertar(Cliente persAux, pnodoArbol& ABB);
    void mostrar(int nodos, pnodoArbol& ABB);
    //void mostrarVertical(pnodo &ABB, int niveles);
    int getNiveles(pnodoArbol &ABB, int niveles);
    bool getGenteEnArbol();
    void preOrden(pnodoArbol& ABB);
    void enOrden(pnodoArbol& ABB);
    void postOrden(pnodoArbol& ABB);

private:
    pnodoArbol raiz;
    int genteEnArbol;
    //int niveles;

};

#endif // ARBOL_HPP
