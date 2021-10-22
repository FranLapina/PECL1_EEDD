
#include "MiNodoCola.hpp"

MiNodoCola::MiNodoCola(Cliente clienteAux, MiNodoCola *sig) {
    cliente = clienteAux;
    siguiente = sig;
}