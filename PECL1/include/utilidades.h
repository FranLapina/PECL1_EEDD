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
        //--------------------Identificador
        struct estructuraIdentificador
        {
            std::string ID;
            int numerosID;
        };

        //--------------------Coordenadas
        struct estructuraCoordenadas
        {
            const static int LAT_MAX = -3190;
            const static int LAT_MIN  = -3250;
            const static int LON_MAX = 40310;
            const static int LON_MIN = 40280;
            int longitudNumerica;
            int latitudNumerica;
            std::string longitud;
            std::string latitud;
        };

        //------------NIF
        struct estructuraNIF
        {
            const static int NIF_MAX = 99999999;
            const static int NIF_MIN = 100;
            int numerosNIF;
            std::string NIFCompleto;
        };
        //---------Definicion de metodos referidos a coordenadas------------

        std::string modelarLongitud(int longitudNumerica);
        std::string modelarLatitud(int latitudNumerica);
        //-----------Definicion de metodos referidos a NIF-------------------
        std::string NIFCompleto(int numerosNIF);
    public:
        int definirLongitud();
        int definirLatitud();
        int generarNumerosNIF();
        int generarNumerosID();
        std::string modelarID();

        //----------Definicion de estructuras--------------------
        estructuraNIF NIF;
        estructuraCoordenadas Coordenadas;
        estructuraIdentificador Identificador;



        //-------------------------ID:

        //Inicializador:
        Paquete()
        {
            //--------------------Coordenadas
            Coordenadas.longitudNumerica = definirLongitud();
            Coordenadas.latitudNumerica = definirLatitud();
            Coordenadas.longitud = modelarLongitud(Coordenadas.longitudNumerica);
            Coordenadas.latitud = modelarLatitud(Coordenadas.latitudNumerica);
            //-----------------------NIF:
            NIF.NIFCompleto = NIFCompleto(generarNumerosNIF());
            //------------------------ID:
            Identificador.numerosID = generarNumerosID();
            Identificador.ID = modelarID();

        }



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
