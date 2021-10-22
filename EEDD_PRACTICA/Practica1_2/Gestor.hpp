
#ifndef PRACTICA1_1_GESTOR_HPP
#define PRACTICA1_1_GESTOR_HPP

#include "Cliente.hpp"
#include "MiCola.hpp"
#include "Arbol.hpp"


class Gestor {
public:
    Gestor();
    int getUsuariosColas(bool registro);
    int getUsuariosLista();
    void simularCola(bool registro);
    void mostrarCola(bool registro);
    void borrarCola(bool registro);
    void simularCompra(bool registro);
    void mostrarLista();
    void reiniciar();
    void insertarCliente();
    void crearArbol();
    void arbolPreOrden();
    void arbolEnOrden();
    void arbolPostOrden();
    void dibujarArbol();

private:
    MiCola cola1; MiCola cola2;
    MiLista lista;
    Arbol abb;
    pnodoArbol ABB;
};


#endif //PRACTICA1_1_GESTOR_HPP
