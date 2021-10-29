#include <iostream>
#include <utilidades.h>
#include <iomanip>

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
    MuelleDeSalida muelleDeSalidaNE("NE");
    MuelleDeSalida muelleDeSalidaNO("NO");
    MuelleDeSalida muelleDeSalidaSE("SE");
    MuelleDeSalida muelleDeSalidaSO("SO");
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 5; ++j){
            Paquete paquete;
            if(paquete.zona == "NE"){
                muelleDeSalidaNE.arrayPila[i].apilar(paquete);
            }else if(paquete.zona == "NO"){
                muelleDeSalidaNO.arrayPila[i].apilar(paquete);
            }else if(paquete.zona == "SE"){
                muelleDeSalidaSE.arrayPila[i].apilar(paquete);
            }else if(paquete.zona == "SO"){
                muelleDeSalidaSO.arrayPila[i].apilar(paquete);
            }

        }

    }


    // Llamada al menu principal y muestreo de los datos de los paquetes generados de forma aleatoria.
    utilidades.menu_principal();
    for(int i = 0; i < 10; ++i){

        while(muelleDeSalidaNE.arrayPila[i].desapilar().Identificador.ID == "NULL"){
            Paquete paquete = muelleDeSalidaNE.arrayPila[i].desapilar();
            string longitud = paquete.Coordenadas.longitud;
            string latitud = paquete.Coordenadas.latitud;
            string NIF = paquete.NIF.NIFCompleto;
            string ID = paquete.Identificador.ID;
            string zona = paquete.zona;
            cout << "|" << setw (11) << NIF << setw (7) << "|" << setw(18) << longitud << " , " << latitud << setw (7) << "|" << setw(13) << ID << setw (9) << "|" << setw(9) << zona << setw(6) << "|" << endl;
            cout << "---------------------------------------------------------------------------------------------" << endl;


        }


    }

    cout<< "pito"<< endl;
    utilidades.menu_envio();
    cout << "pito" << endl;
    utilidades.menu_carga();
    cout << "pito" << endl;

    utilidades.menu_entregados();

    //FIN DE ZONA DE PRUEBAS
    return 0;
}
