
#ifndef PRACTICA1_1_COLA_HPP
#define PRACTICA1_1_COLA_HPP

#include "MiNodoCola.hpp"
#include "MiLista.hpp"
#include <unistd.h>
#include <string>



class MiCola {

public:
    MiCola();
    void generarPersonas(bool registrado);
    void insertar(Cliente cliente);
    void mostrarCola();
    int getUsuarios();
    void popFirst();
    void mostrarHora(int minuto);
    void mostrarServidor();
    void mostrarLista();
    MiLista simularCompra(bool registro, MiLista lista);
    MiLista usarServidor(MiLista lista, MiCola* auxiliar, int minutoTotal);
    void seleccionarTiempo(MiCola* servidor, int minutoTotal);
    unsigned int menosUsuarios(MiCola* servidor1, MiCola* servidor2, MiCola* servidor3, MiCola* servidor4);
    void especificarCliente(bool regis);


private:
    MiNodoCola* primero;
    pnodoCola ultimo;

    int genteEnCola;

    friend class Gestor;

};


#endif //PRACTICA1_1_COLA_HPP
