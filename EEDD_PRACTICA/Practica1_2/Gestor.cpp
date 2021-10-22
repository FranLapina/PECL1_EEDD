
#include "Gestor.hpp"

Gestor::Gestor() {}

int Gestor::getUsuariosColas(bool registro){
    if (registro)
        return cola1.getUsuarios();
    else
        return cola2.getUsuarios();
}

int Gestor::getUsuariosLista() {
    return lista.getGenteEnLista();
}

void Gestor::simularCola(bool registro) {
    if (registro)
        cola1.generarPersonas(true);
    else
        cola2.generarPersonas(false);
}

void Gestor::mostrarCola(bool registro) {
    if (registro)
        cola1.mostrarCola();
    else
        cola2.mostrarCola();
}

void Gestor::borrarCola(bool registro) {
    if (registro)
        while (cola1.getUsuarios())
            cola1.popFirst();
    else
        while (cola2.getUsuarios())
            cola2.popFirst();
}

void Gestor::simularCompra(bool registro) {
    if (registro)
        lista = cola1.simularCompra(true, lista);
    else
        lista= cola2.simularCompra(false, lista);
}

void Gestor::mostrarLista() {
    lista.mostar();
}

void Gestor::reiniciar() {
    //borrar Cola1
    while (cola1.getUsuarios())
        cola1.popFirst();
    //borrar Cola2
    while (cola2.getUsuarios())
        cola2.popFirst();
    //borrar lista
    while (lista.getGenteEnLista())
        lista.popFirst();
}

void Gestor::insertarCliente() {
    int cantidad = 0;
    char registrado;
    cout << "\t¿Cantidad de clientes a insertar?: ";
    cin >> cantidad;
    for (int i = 0; i < cantidad; i++){
        cout << "Cliente registrado o Cliente no registrado (s/N): ";
        cin >> registrado;
        if (registrado == 'S' || registrado == 's')
            cola1.especificarCliente(true);
        else
            cola2.especificarCliente(false);
    }
}

void Gestor::crearArbol() {
    Cliente clienteRaiz(50000000);
    pnodoCola persAux;
    MiNodoLista* persAuxLista;
    if (!abb.getGenteEnArbol())
        abb.insertar(clienteRaiz, ABB);
    if(cola1.getUsuarios()) {
     persAux = cola1.primero;
        while (persAux) {
            abb.insertar(persAux->cliente, ABB);
            persAux = persAux->siguiente;
        }
    }
    if(cola2.getUsuarios()) {
        persAux = cola2.primero;
        while (persAux) {
            abb.insertar(persAux->cliente, ABB);
            persAux = persAux->siguiente;
        }
    }
    if(persAuxLista){
        persAuxLista = lista.primero;
        while (lista.getGenteEnLista()) {
            abb.insertar(persAuxLista->cliente, ABB);
            persAuxLista = persAuxLista->siguiente;
        }
    }

}

void Gestor::arbolPreOrden() {
    if (abb.getGenteEnArbol())
        abb.preOrden(ABB);
}

void Gestor::arbolEnOrden() {
    if (abb.getGenteEnArbol())
        abb.enOrden(ABB);
}

void Gestor::arbolPostOrden() {
    if (abb.getGenteEnArbol())
        abb.postOrden(ABB);
}

void Gestor::dibujarArbol() {
    if (abb.getGenteEnArbol())
        abb.mostrar(0, ABB);
}
