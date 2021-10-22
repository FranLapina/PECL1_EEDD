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
