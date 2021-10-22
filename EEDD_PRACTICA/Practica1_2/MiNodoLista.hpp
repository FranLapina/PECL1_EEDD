
#ifndef PRACTICA1_1_MINODOLISTA_HPP
#define PRACTICA1_1_MINODOLISTA_HPP

#include "Cliente.hpp"

class MiNodoLista {
public:
    MiNodoLista(Cliente persAux, MiNodoLista* sig = NULL, MiNodoLista* ant = NULL);

private:
    Cliente cliente;
    MiNodoLista* siguiente;
    MiNodoLista* anterior;

    friend class MiLista;
    friend class Gestor;


};


#endif //PRACTICA1_1_MINODOLISTA_HPP
