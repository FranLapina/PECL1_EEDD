#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Cliente pers, NodoArbol* izq, NodoArbol* der){
    cliente = pers;
    izquierda = izq;
    derecha = der;
}

