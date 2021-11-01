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
    int contadorNE = 0;
    int contadorNO = 0;
    int contadorSE = 0;
    int contadorSO = 0;
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j){
            Paquete paquete;
            if(paquete.zona == "NE"){
                //cout << "Paquete entrando en zona NE: " << paquete.zona<<endl;
                muelleDeSalidaNE.arrayPila[contadorNE].apilar(paquete);
                muelleDeSalidaNE.arrayPila[contadorNE].cantidadDePaquetes++;
                muelleDeSalidaNE.paquetesEnMuelle++;
                if(muelleDeSalidaNE.arrayPila[contadorNE].cantidadDePaquetes == 5){
                    contadorNE += 1;
                }
            }else if(paquete.zona == "NO"){
                //cout << "Paquete entrando en zona NO: "<< paquete.zona<<endl;
                muelleDeSalidaNO.arrayPila[contadorNO].apilar(paquete);
                muelleDeSalidaNO.arrayPila[contadorNO].cantidadDePaquetes++;
                muelleDeSalidaNO.paquetesEnMuelle++;
                if(muelleDeSalidaNO.arrayPila[contadorNO].cantidadDePaquetes == 5){
                    contadorNO += 1;

                }
            }else if(paquete.zona == "SE"){
                //cout << "Paquete entrando en zona SE: " << paquete.zona<<endl;
                muelleDeSalidaSE.arrayPila[contadorSE].apilar(paquete);
                muelleDeSalidaSE.arrayPila[contadorSE].cantidadDePaquetes++;
                muelleDeSalidaSE.paquetesEnMuelle++;
                if(muelleDeSalidaSE.arrayPila[contadorSE].cantidadDePaquetes == 5){
                    contadorSE += 1;

                }
            }else if(paquete.zona == "SO"){
                //cout << "Paquete entrando en zona SO: " << paquete.zona<<endl;
                muelleDeSalidaSO.arrayPila[contadorSO].apilar(paquete);
                muelleDeSalidaSO.arrayPila[contadorSO].cantidadDePaquetes++;
                muelleDeSalidaSO.paquetesEnMuelle++;
                if(muelleDeSalidaSO.arrayPila[contadorSO].cantidadDePaquetes  == 5){
                    contadorSO += 1;
                }
            }

        }

    }


    // Llamada al menu principal y muestreo de los datos de los paquetes generados de forma aleatoria.
    utilidades.menu_principal();
    //Paquetes en muelle NE
    int contador = 0;

    for(int i = 0; i < muelleDeSalidaNO.paquetesEnMuelle; ++i){
        Paquete paquete = muelleDeSalidaNO.arrayPila[contador].desapilar();
        string longitud = paquete.Coordenadas.longitud;
        string latitud = paquete.Coordenadas.latitud;
        string NIF = paquete.NIF.NIFCompleto;
        string ID = paquete.Identificador.ID;
        string zona = paquete.zona;
        cout << "|" << setw (11) << NIF << setw (7) << "|" << setw(18) << longitud << " , " << latitud << setw (7) << "|" << setw(13) << ID << setw (9) << "|" << setw(9) << zona << setw(6) << "|" << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;
        muelleDeSalidaNO.arrayPila[contador].cantidadDePaquetes--;
        if(muelleDeSalidaNO.arrayPila[contador].cantidadDePaquetes == 0){
            contador++;
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

