#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <cstddef>
#include <cstdlib>
#include <string>
class utilidades
{
    public:
        utilidades();
        virtual ~utilidades();
        void menu_principal();
        void menu_carga();
        void menu_envio();
        void menu_entregados();

    protected:

    private:
};

/*
    CLASE PAQUETE
*/

class Paquete
{
    private:
        //Identificador
        struct Identificador
        {
            char ID[7];

        };

        //Coordenadas
        struct Coordenadas
        {
            const static int LAT_MAX = -3190;
            const static int LAT_MIN  = -3250;
            const static int LON_MAX = 40310;
            const static int LON_MIN = 40280;
        };
        //Definicion de metodos referidos a coordenadas:
        int definirLongitud();
        int definirLatitud();
        std::string modelarLongitud(int longitudNumerica);
        std::string modelarLatitud(int latitudNumerica);
        //NIF
        struct NIF
        {
            const static int NIF_MAX = 99999999;
            const static int NIF_MIN = 100;
        };
        //Definicion de metodos referidos a NIF:
        std::string NIFCompleto(int numerosNIF);
        int generarNumerosNIF();
    //Variables de acceso publico:
    public:
        //Coordenadas
        int longitudNumerica = definirLongitud();
        int latitudNumerica = definirLatitud();
        std::string longitud = modelarLongitud(longitudNumerica);
        std::string latitud = modelarLatitud(latitudNumerica);
        //NIF:
        int numerosNIF = generarNumerosNIF();
        std::string var_NIF = NIFCompleto(numerosNIF);
        //ID:


};
/*
    CLASE NODO
*/

class Nodo
{
private:
    int valor;
    Nodo *siguiente;
    friend class Cola;
    friend class Pila;
public:
    Nodo(int v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef Nodo *pNodo;

/*
    CLASE PILA
*/

class Pila
{
private:
    pNodo cima;
public:
    Pila() : cima(NULL) {} //Constructor de la Pila
    ~Pila();
    void apilar(int v);
    int desapilar();
};


/*
    CLASE COLAS
*/
class Cola
{
public:
    Cola() : frente(NULL), final(NULL) {}
    ~Cola();
    void encolar(int v);
    int desencolar();
private:
    pNodo frente, final;
};

#endif // UTILIDADES_H
