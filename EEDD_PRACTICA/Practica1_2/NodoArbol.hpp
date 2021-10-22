#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include <iomanip>
#include "Cliente.hpp"
using namespace std;


class NodoArbol
{
public:
    NodoArbol(Cliente pers, NodoArbol* izq = NULL, NodoArbol* der = NULL);

private:
    NodoArbol* izquierda;
    NodoArbol* derecha;

    Cliente cliente;

    friend class Arbol;
};

typedef NodoArbol* pnodoArbol;

#endif // NODOARBOL_HPP
