
#ifndef PRACTICA1_1_NODOCOLA_HPP
#define PRACTICA1_1_NODOCOLA_HPP

#include "Cliente.hpp"

class MiNodoCola {


public:
    MiNodoCola (Cliente clienteAux, MiNodoCola* sig = NULL);


private:
    Cliente cliente;
    MiNodoCola* siguiente;

    friend class MiCola;
    friend class Gestor;

};

typedef MiNodoCola* pnodoCola;


#endif //PRACTICA1_1_NODOCOLA_HPP
