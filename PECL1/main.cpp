#include <iostream>
#include <utilidades.h>

using namespace std;

int main()
{

    //Codigo que crea una pila y lo pasa a una cola.
    /*Pila pila;
    Cola cola;
    int i = 0, k = 0;
    int MAX = 10;
    for (i=1;i<MAX;i++){
        pila.apilar(10*i);
        //cout << "Apilando: " << 10*i << " " << endl;
    }
    for (i = 1; i < MAX; i++){
        k = pila.desapilar();
        cola.encolar(k);
        //cout << "Encolando: " << k << endl;
    }*/

    //ZONA DE PRUEBAS
    utilidades utilidades;
    //utilidades.menu_principal();
    MuelleDeSalida muelleDeSalida;
    for(int i = 0; i <= 10; ++i)
    {

        Paquete paquete;
        muelleDeSalida.arrayPila[i].apilar(paquete);


    }
    for(int i = 0; i <= 10; ++i){
        Paquete paquete = muelleDeSalida.arrayPila[i].desapilar();
        string longitud = paquete.Coordenadas.longitud;
        string latitud = paquete.Coordenadas.latitud;
        string NIF = paquete.NIF.NIFCompleto;
        string ID = paquete.Identificador.ID;
        string zona = paquete.zona;
        cout << "Coordenadas: " << longitud << " | " << latitud << " | "
             << "DNI: "<< NIF << " | " << "Identificador: "<< ID << " | " << " Zona: " << zona <<endl;
    }




    utilidades.menu_principal();
    cout<< "pito"<< endl;
    utilidades.menu_envio();
    cout << "pito" << endl;
    utilidades.menu_carga();
    cout << "pito" << endl;

    utilidades.menu_entregados();

    //FIN DE ZONA DE PRUEBAS
    return 0;
}
