#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <cstddef>

class utilidades
{
    public:
        utilidades();
        virtual ~utilidades();

    protected:

    private:
};

/*
    CLASE ID
*/

class id
{
    struct Identificador
    {
        char ID[7];
        string latitud

    };
    struct coordenadas
    {
        int lat_max(-3190);
        int lat_min(-3250);
        int lon_max(40310);
        int lon_min(40280);
        int longitud(lon_min + rand() % (lon_max+1 - lon_min));
        int latitud (lat_min + rand() % (lat_max+1 - lat_min));
    };
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
