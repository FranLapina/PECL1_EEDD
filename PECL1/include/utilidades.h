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
        //-----------Definicion de metodos referidos a Identificador-------------------
        std::string modelarID();
        //-----------Definicion de metodos referidos a zona-------------------
        std::string asignarZona();
    public:
        //metodos:
        int definirLongitud();
        int definirLatitud();
        int generarNumerosNIF();
        int generarNumerosID();

        //Variables:
        std::string zona;

        //----------Definicion de estructuras--------------------
        estructuraNIF NIF;
        estructuraCoordenadas Coordenadas;
        estructuraIdentificador Identificador;
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
            //------------------------Zona:
            zona = asignarZona();

        }



};
/*
    CLASE NODO
*/

class Nodo
{
private:
    Paquete paquete;
    Nodo *siguiente;
    friend class Cola;
    friend class Pila;
public:
    Nodo(Paquete p, Nodo *sig = NULL)
    {
        paquete = p;
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
    int cantidadDePaquetes;
    Pila() : cima(NULL) {} //Constructor de la Pila
    ~Pila();
    void apilar(Paquete paquete);
    Paquete desapilar();
};


/*
    CLASE COLAS
*/
class Cola
{
public:
    Cola() : frente(NULL), final(NULL) {}
    ~Cola();
    Paquete encolar(Paquete paquete);
    Paquete desencolar();
private:
    pNodo frente, final;
};

/*
    CLASE MUELLE
*/
class MuelleDeSalida{
    public:
        std::string zona;
        Pila arrayPila[10];
        muelleDeSalida(std::string zona){
            zona = zona;
            for(int i = 0; i < 10; ++i){
                Pila pila;
                arrayPila[i] = pila;
            }
        }
    };


#endif // UTILIDADES_H
