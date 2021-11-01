#include <iostream>
#include <utilidades.h>
#include <iomanip>
#define N1 100
#define N2 10
#define N3 5

using namespace std;

int main()
{
    string enter;
    MuelleDeSalida muelleDeSalidaNE("NE");
    MuelleDeSalida muelleDeSalidaNO("NO");
    MuelleDeSalida muelleDeSalidaSE("SE");
    MuelleDeSalida muelleDeSalidaSO("SO");
    int contadorNE = 0;
    int contadorNO = 0;
    int contadorSE = 0;
    int contadorSO = 0;
    int contadorGlobal = 0;
    Cola colaInicialPaquetes;
    //Generar 100 paquetes y meterlos en una cola.
    for(int i = 0; i < N1; ++i){
        Paquete paquete;
        colaInicialPaquetes.encolar(paquete);
    }
    utilidades utilidades;
    // Llamada al menu principal y muestreo de los datos de los paquetes generados de forma aleatoria.

    utilidades.menu_principal();
    for (int i = 1; i < N1; ++i){
        Paquete paquete = colaInicialPaquetes.desencolar();
        colaInicialPaquetes.encolar(paquete);
        string longitud = paquete.Coordenadas.longitud;
        string latitud = paquete.Coordenadas.latitud;
        string NIF = paquete.NIF.NIFCompleto;
        string ID = paquete.Identificador.ID;
        string zona = paquete.zona;
        cout << "|" << setw (11) << NIF << setw (7) << "|" << setw(18) << longitud << " , " << latitud << setw (7) << "|" << setw(13) << ID << setw (9) << "|" << setw(9) << zona << setw(6) << "|" << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;
    }
    cout << "Presiona enter para pasar 10 paquetes a las furgonetas" << endl;
    //Pasar de cola a pila
    while(contadorGlobal != 10){
        cin.ignore();
        for(int i = 0; i < N1; ++i){
            contadorNE = muelleDeSalidaNE.paquetesEnMuelle/5;
            contadorNO = muelleDeSalidaNO.paquetesEnMuelle/5;
            contadorSE = muelleDeSalidaSE.paquetesEnMuelle/5;
            contadorSO = muelleDeSalidaSO.paquetesEnMuelle/5;
            Paquete paquete = colaInicialPaquetes.desencolar();
            if(paquete.zona == "NE"){
                    //cout << "Paquete entrando en zona NE: " << paquete.zona<<endl;
                    muelleDeSalidaNE.arrayPila[contadorNE].apilar(paquete);
                    muelleDeSalidaNE.arrayPila[contadorNE].cantidadDePaquetes++;
                    muelleDeSalidaNE.paquetesEnMuelle++;

                }else if(paquete.zona == "NO"){
                    //cout << "Paquete entrando en zona NO: "<< paquete.zona<<endl;
                    muelleDeSalidaNO.arrayPila[contadorNO].apilar(paquete);
                    muelleDeSalidaNO.arrayPila[contadorNO].cantidadDePaquetes++;
                    muelleDeSalidaNO.paquetesEnMuelle++;

                }else if(paquete.zona == "SE"){
                    //cout << "Paquete entrando en zona SE: " << paquete.zona<<endl;
                    muelleDeSalidaSE.arrayPila[contadorSE].apilar(paquete);
                    muelleDeSalidaSE.arrayPila[contadorSE].cantidadDePaquetes++;
                    muelleDeSalidaSE.paquetesEnMuelle++;

                }else if(paquete.zona == "SO"){
                    //cout << "Paquete entrando en zona SO: " << paquete.zona<<endl;
                    muelleDeSalidaSO.arrayPila[contadorSO].apilar(paquete);
                    muelleDeSalidaSO.arrayPila[contadorSO].cantidadDePaquetes++;
                    muelleDeSalidaSO.paquetesEnMuelle++;
                }
        }
        utilidades.menu_carga(muelleDeSalidaNE, muelleDeSalidaNO, muelleDeSalidaSE, muelleDeSalidaSO);
        ++contadorGlobal;
    }


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



    /*MuelleDeSalida muelleDeSalidaNE("NE");
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

    }*/


    //Paquetes en muelle NE
    //Muestra todos los paquetes de un muelle de salida.


    /*
    cout<< "pito"<< endl;
    utilidades.menu_envio();
    cout << "pito" << endl;
    utilidades.menu_carga(muelleDeSalidaNE, muelleDeSalidaNO, muelleDeSalidaSE, muelleDeSalidaSO);
    cout << "pito" << endl;

    utilidades.menu_entregados();

    */
    //FIN DE ZONA DE PRUEBAS

    return 0;
}

