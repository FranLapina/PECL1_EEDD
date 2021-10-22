

#ifndef PRACTICA1_1_MILISTA_HPP
#define PRACTICA1_1_MILISTA_HPP


#include "MiNodoLista.hpp"

class MiLista {

public:
    MiLista();
    void insertar(Cliente pers);
    void mostar();
    int getGenteEnLista();
    void popFirst();

private:
    MiNodoLista* primero;
    MiNodoLista* ultimo;

    int genteEnLista;

    friend class Gestor;


};


#endif //PRACTICA1_1_MILISTA_HPP
