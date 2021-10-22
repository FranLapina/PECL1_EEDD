#ifndef PRACTICA1_1_CLIENTE_HPP
#define PRACTICA1_1_CLIENTE_HPP

#include "stdio.h"
#include "stdlib.h"
#include "iostream"


using namespace std;

class Cliente {
public:
    Cliente();
    Cliente(bool registro, int hora);
    Cliente (bool registro, int numeroDNI, char idEn[4]);
    Cliente (int numeroDni);
    void mostrarDatos();
    int gethoraLlegadaCola();
    void realizarCompra(int tiempoServidor);
    void mostrarHoraInicioCompra();
    void mostrarHoraFinCompra();
    void mostrarId();
    char* getValorId();
    int getHoraFinCompra();
    int especificarCliente();
    char* getDni();

private:
    bool registrado;
    int horaLlegadaCola;
    char dni[10];
    int horaInicioCompra;
    int horaFinCompra;
    char id[5];

};


#endif //PRACTICA1_1_CLIENTE_HPP
