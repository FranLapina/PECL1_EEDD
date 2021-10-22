//
// Created by Daniel Villalobos del Baño on 16/11/2017.
//

#include "MiNodoLista.hpp"

MiNodoLista::MiNodoLista(Cliente persAux, MiNodoLista *sig, MiNodoLista *ant) {
    siguiente = sig;
    anterior = ant;
    cliente = persAux;
}
