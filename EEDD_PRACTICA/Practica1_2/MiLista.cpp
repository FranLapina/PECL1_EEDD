
#include "MiLista.hpp"

MiLista::MiLista() {
    primero = NULL;
    ultimo = NULL;
    genteEnLista=0;
}

void MiLista::insertar(Cliente pers) {
    MiNodoLista* nuevo = new MiNodoLista(pers);
    MiNodoLista* persAux;

    if (!primero){
        primero = nuevo;
        ultimo = nuevo;
    }
    else {
        persAux = primero;
        if ((strcmp(nuevo->cliente.getValorId(), persAux->cliente.getValorId())) <= 0) {
            primero = nuevo;
            nuevo->siguiente = persAux;
            persAux->anterior = nuevo;
        } else {
            while (persAux->siguiente != NULL && (strcmp(nuevo->cliente.getValorId(), persAux->cliente.getValorId()) > 0))
                persAux = persAux->siguiente;
            if (persAux->siguiente == NULL) {
                if ((strcmp(nuevo->cliente.getValorId(), persAux->cliente.getValorId()) <= 0)) {
                    nuevo->siguiente = persAux;
                    nuevo->anterior = persAux->anterior;
                    nuevo->anterior->siguiente = nuevo;
                    persAux->anterior = nuevo;
                } else {
                    ultimo = nuevo;
                    nuevo->anterior = persAux;
                    persAux->siguiente = nuevo;
                }
            } else {
                nuevo->siguiente = persAux;
                nuevo->anterior = persAux->anterior;
                nuevo->siguiente->anterior = nuevo;
                nuevo->anterior->siguiente = nuevo;
            }
        }
    }
    genteEnLista++;
}

void MiLista::mostar() {
    MiNodoLista* auxPers;
    auxPers = this->primero;
    while (auxPers) {
        auxPers->cliente.mostrarDatos();
        auxPers->cliente.mostrarHoraInicioCompra();
        auxPers->cliente.mostrarHoraFinCompra();
        auxPers->cliente.mostrarId();
        auxPers = auxPers->siguiente;
    }
}

int MiLista::getGenteEnLista() {
    return genteEnLista;
}

void MiLista::popFirst() {
    MiNodoLista* aux;
    aux = this->primero;
    primero = primero->siguiente;
    if (this->genteEnLista == 2)
        ultimo = primero;
    aux = NULL;
    this->genteEnLista--;
}