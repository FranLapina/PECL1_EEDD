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
            //int latitud (lat_min + rand() % (lat_max+1 - lat_min));
        };

        int definirLongitud();
        int definirLatitud();
        std::string modelarLongitud(int longitudNumerica);
        std::string modelarLatitud(int latitudNumerica);
        //NIF
        struct NIF
        {
            char NIF[9];
        };
    //Variables de acceso publico:
    public:
        std::string longitud = modelarLongitud(definirLongitud());
        std::string latitud = modelarLatitud(definirLatitud());

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
