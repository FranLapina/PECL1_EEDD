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
    Paquete paqueteAux;
    MuelleDeSalida muelleDeSalidaNE("NE");
    MuelleDeSalida muelleDeSalidaNO("NO");
    MuelleDeSalida muelleDeSalidaSE("SE");
    MuelleDeSalida muelleDeSalidaSO("SO");
    int contadorNE = 0;
    int contadorNO = 0;
    int contadorSE = 0;
    int contadorSO = 0;
    int contadorGlobal = 0;
    int furgonetasLlenasNE, furgonetasLlenasNO, furgonetasLlenasSE, furgonetasLlenasSO;
    Cola colaInicialPaquetes;
    Cola colaAux;
    Pila pilaAux;
    utilidades utilidades;
    //Generar 100 paquetes y meterlos en una cola y llamada al menu principal y muestreo de los datos de los paquetes generados de forma aleatoria.
    utilidades.menu_principal();
    for(int i = 0; i < N1; ++i){
        Paquete paquete;
        paquete.generarPaquete();
        //COLA Inicial Paquetes paquetes urgentes
        //ColaAux resto de paquetes
        //encolar cola aux a cola inicial para concatenar resto de paquetes a urgentes
        //random de 1 al 9, si sale 2 u 8 urgente, si sale otro numero normal.
        //urgente true o false.
        string urgencia;
        string longitud = paquete.Coordenadas.longitud;
        string latitud = paquete.Coordenadas.latitud;
        string NIF = paquete.NIF.NIFCompleto;
        string ID = paquete.Identificador.ID;
        string zona = paquete.zona;
        if(paquete.urgente){
            colaInicialPaquetes.encolar(paquete);
            urgencia = "SI";
        }else{
            colaAux.encolar(paquete);
            urgencia = "NO";
        }



        cout << "|" << setw (11) << ID << setw (7) << "|" << setw(18) << longitud << " , " << latitud << setw (5) << "|" << setw(15) << NIF
        << setw (7) << "|" << setw(8) << zona << setw(7) << "|" << setw(7)<< urgencia << setw(7)<< "|" <<endl;
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    }


    //encolar No urgentes al final de la cola;
    paqueteAux = colaAux.desencolar();
    while(paqueteAux.NIF.NIFCompleto != ""){
            colaInicialPaquetes.encolar(paqueteAux);
            paqueteAux = colaAux.desencolar();

    }

    //Pasar de cola a pila
    while(contadorGlobal < 10){
        cout << "Presiona enter para pasar 10 paquetes a las furgonetas" << endl;
        cin.ignore();
        for(int i = 0; i < N2; ++i){
            contadorNE = muelleDeSalidaNE.paquetesEnMuelle/5;
            contadorNO = muelleDeSalidaNO.paquetesEnMuelle/5;
            contadorSE = muelleDeSalidaSE.paquetesEnMuelle/5;
            contadorSO = muelleDeSalidaSO.paquetesEnMuelle/5;
            paqueteAux = colaInicialPaquetes.desencolar();
            cout << "---------------------------------------------------------------------" << endl;
            if(paqueteAux.zona == "NE"){
                if(paqueteAux.urgente){
                    ++muelleDeSalidaNE.cantidadUrgentes;
                }
                muelleDeSalidaNE.arrayPila[contadorNE].apilar(paqueteAux);
                muelleDeSalidaNE.arrayPila[contadorNE].cantidadDePaquetes++;
                muelleDeSalidaNE.paquetesEnMuelle++;
                cout << "Paquete entrando en zona NE: " << paqueteAux.Identificador.ID <<". Furgoneta: "<<contadorNE+1 << " Espacio libre: "<< 5-muelleDeSalidaNE.arrayPila[contadorNE].cantidadDePaquetes<<" | "<<endl;

            }else if(paqueteAux.zona == "NO"){
                if(paqueteAux.urgente){
                    ++muelleDeSalidaNO.cantidadUrgentes;
                }
                muelleDeSalidaNO.arrayPila[contadorNO].apilar(paqueteAux);
                muelleDeSalidaNO.arrayPila[contadorNO].cantidadDePaquetes++;
                muelleDeSalidaNO.paquetesEnMuelle++;
                cout << "Paquete entrando en zona NO: "<< paqueteAux.Identificador.ID <<". Furgoneta: "<<contadorNO+1<< " Espacio libre: "<< 5-muelleDeSalidaNO.arrayPila[contadorNO].cantidadDePaquetes<<" | "<<endl;


            }else if(paqueteAux.zona == "SE"){
                if(paqueteAux.urgente){
                    ++muelleDeSalidaSE.cantidadUrgentes;
                }
                muelleDeSalidaSE.arrayPila[contadorSE].apilar(paqueteAux);
                muelleDeSalidaSE.arrayPila[contadorSE].cantidadDePaquetes++;
                muelleDeSalidaSE.paquetesEnMuelle++;
                cout << "Paquete entrando en zona SE: " << paqueteAux.Identificador.ID <<". Furgoneta: "<<contadorSE+1 << " Espacio libre: "<< 5-muelleDeSalidaSE.arrayPila[contadorSE].cantidadDePaquetes<<" | "<<endl;


            }else if(paqueteAux.zona == "SO"){
                if(paqueteAux.urgente){
                    ++muelleDeSalidaSO.cantidadUrgentes;
                }
                muelleDeSalidaSO.arrayPila[contadorSO].apilar(paqueteAux);
                muelleDeSalidaSO.arrayPila[contadorSO].cantidadDePaquetes++;
                muelleDeSalidaSO.paquetesEnMuelle++;
                cout << "Paquete entrando en zona SO: " << paqueteAux.Identificador.ID <<". Furgoneta: "<< contadorSO+1 << " Espacio libre: "<< 5-muelleDeSalidaSO.arrayPila[contadorSO].cantidadDePaquetes<<" | "<<endl;

            }
        }
        cout << "---------------------------------------------------------------------" << endl;
        ++contadorGlobal;
        //Menu de carga
        cout <<  "----------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(17) << "Zona NE" << setw(14) << "|" << setw(17) << "Zona NO" << setw(14) << "|" << setw(17) << "Zona SO"
        << setw(14) << "|" << setw(17) << "Zona SE" << setw(14) << "|" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        furgonetasLlenasNE = (muelleDeSalidaNE.paquetesEnMuelle/5);
        furgonetasLlenasNO = (muelleDeSalidaNO.paquetesEnMuelle/5);
        furgonetasLlenasSE = (muelleDeSalidaSE.paquetesEnMuelle/5);
        furgonetasLlenasSO = (muelleDeSalidaSO.paquetesEnMuelle/5);
        int furgonetasMinimo;
        if((furgonetasLlenasNE < furgonetasLlenasNO) && (furgonetasLlenasNE < furgonetasLlenasSE) && (furgonetasLlenasNE < furgonetasLlenasSO)){
            furgonetasMinimo = furgonetasLlenasNE;
        }else if((furgonetasLlenasNO < furgonetasLlenasSE) && (furgonetasLlenasNO < furgonetasLlenasSO)){
            furgonetasMinimo = furgonetasLlenasNO;
        }else if((furgonetasLlenasSE < furgonetasLlenasSO)){
            furgonetasMinimo = furgonetasLlenasSE;
        }else{
            furgonetasMinimo = furgonetasLlenasSO;
        }

        for(int i = furgonetasMinimo; i < 10; ++i){

            if(furgonetasLlenasNE == 9){
                cout << setw (19) << "Furgoneta: "<< furgonetasLlenasNE+1 << setw (10) << "|";
                ++furgonetasLlenasNE;
            }else if(furgonetasLlenasNE < 9){
                cout << setw (19) << "Furgoneta: "<< furgonetasLlenasNE+1 << setw (11) << "|";
                ++furgonetasLlenasNE;
            }else{
                cout << setw (19) << "------------"<< setw (12) << "|";
            }


            if(furgonetasLlenasNO == 9){
                cout << setw (19) << "Furgoneta: "<< furgonetasLlenasNO+1 << setw (10) << "|";
                ++furgonetasLlenasNO;
            }else if(furgonetasLlenasNO < 9){
                cout << setw (19) << "Furgoneta: "<< furgonetasLlenasNO+1 << setw (11) << "|";
                ++furgonetasLlenasNO;
            }else{
                cout << setw (19) << "------------"<< setw (12) << "|" ;
            }

            if(furgonetasLlenasSO == 9){
                cout << setw (19) << "Furgoneta: "<< furgonetasLlenasSO+1 << setw (10) << "|";
                ++furgonetasLlenasSO;
            }else if (furgonetasLlenasSO < 9){
                cout << setw (19) << "Furgoneta: "<< furgonetasLlenasSO+1 << setw (11) << "|";
                ++furgonetasLlenasSO;
            }else{
                cout << setw (19) << "------------"<< setw (12) << "|" ;
            }

            if(furgonetasLlenasSE == 9){
                cout << setw (19) << "Furgoneta: "<< furgonetasLlenasSE+1 << setw (10) << "|" << endl;
                ++furgonetasLlenasSE;
            }else if(furgonetasLlenasSE < 9){
                cout << setw (19) << "Furgoneta: "<< furgonetasLlenasSE+1 << setw (11) << "|" << endl;
                ++furgonetasLlenasSE;
            }else{
                cout << setw (19) << "------------"<< setw (12) << "|" << endl;
            }
            cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }

    //Reorganizar furgonetas con paquetes urgentes y no urgentes
    muelleDeSalidaNE.arrayPila[muelleDeSalidaNE.cantidadUrgentes/5].invertir();
    muelleDeSalidaNO.arrayPila[muelleDeSalidaNO.cantidadUrgentes/5].invertir();
    muelleDeSalidaSE.arrayPila[muelleDeSalidaSE.cantidadUrgentes/5].invertir();
    muelleDeSalidaSO.arrayPila[muelleDeSalidaSO.cantidadUrgentes/5].invertir();



    Cola colaNE,colaNO,colaSE,colaSO;
    //Pilas a colas
    //Muelle NE

    while(contadorGlobal >= 0){

        int posicion = 9 - contadorGlobal;
        for(int i = 1; i <= 5; ++i){
            if(muelleDeSalidaNE.arrayPila[posicion].cantidadDePaquetes >= i && muelleDeSalidaNE.arrayPila[posicion].cantidadDePaquetes < 6){
                colaNE.encolar(muelleDeSalidaNE.arrayPila[posicion].desapilar());

            }
            if(muelleDeSalidaNO.arrayPila[posicion].cantidadDePaquetes >= i && muelleDeSalidaNO.arrayPila[posicion].cantidadDePaquetes < 6){
                colaNO.encolar(muelleDeSalidaNO.arrayPila[posicion].desapilar());

            }
            if(muelleDeSalidaSE.arrayPila[posicion].cantidadDePaquetes >= i && muelleDeSalidaSE.arrayPila[posicion].cantidadDePaquetes < 6){
                colaSE.encolar(muelleDeSalidaSE.arrayPila[posicion].desapilar());
            }
            if(muelleDeSalidaSO.arrayPila[posicion].cantidadDePaquetes >= i && muelleDeSalidaSO.arrayPila[posicion].cantidadDePaquetes < 6){
                colaSO.encolar(muelleDeSalidaSO.arrayPila[posicion].desapilar());
            }

        }
        --contadorGlobal;
    }
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(59) << "Zona Noreste" << setw(47) << "|" << endl;
    utilidades.menu_enviados();
    do{

        paqueteAux = colaNE.desencolar();
        if(paqueteAux.NIF.NIFCompleto != ""){
            string urgencia;
            if(paqueteAux.urgente){urgencia = "SI";}else urgencia = "NO";
            string longitud = paqueteAux.Coordenadas.longitud;
            string latitud = paqueteAux.Coordenadas.latitud;
            string NIF = paqueteAux.NIF.NIFCompleto;
            string ID = paqueteAux.Identificador.ID;
            string zona = paqueteAux.zona;
            cout << "|" << setw (11) << ID << setw (7) << "|" << setw(18) << longitud << " , " << latitud << setw (5) << "|" << setw(15) << NIF
            << setw (7) << "|" << setw(8) << zona << setw(7) << "|" << setw(7)<< urgencia << setw(7)<< "|" <<endl;
            cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        }

    }while(paqueteAux.NIF.NIFCompleto != "");
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(59) << "Zona Noroeste" << setw(47) << "|" << endl;
    utilidades.menu_enviados();
    do{

        paqueteAux = colaNO.desencolar();
        if(paqueteAux.NIF.NIFCompleto != ""){
            string urgencia;
            if(paqueteAux.urgente){urgencia = "SI";}else urgencia = "NO";
            string longitud = paqueteAux.Coordenadas.longitud;
            string latitud = paqueteAux.Coordenadas.latitud;
            string NIF = paqueteAux.NIF.NIFCompleto;
            string ID = paqueteAux.Identificador.ID;
            string zona = paqueteAux.zona;
            cout << "|" << setw (11) << ID << setw (7) << "|" << setw(18) << longitud << " , " << latitud << setw (5) << "|" << setw(15) << NIF
            << setw (7) << "|" << setw(8) << zona << setw(7) << "|" << setw(7)<< urgencia << setw(7)<< "|" <<endl;
            cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        }


    }while(paqueteAux.NIF.NIFCompleto != "");
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(59) << "Zona Sureste" << setw(47) << "|" << endl;
    utilidades.menu_enviados();
    do{

        paqueteAux = colaSE.desencolar();
        if(paqueteAux.NIF.NIFCompleto != ""){
            string urgencia;
            if(paqueteAux.urgente){urgencia = "SI";}else urgencia = "NO";
            string longitud = paqueteAux.Coordenadas.longitud;
            string latitud = paqueteAux.Coordenadas.latitud;
            string NIF = paqueteAux.NIF.NIFCompleto;
            string ID = paqueteAux.Identificador.ID;
            string zona = paqueteAux.zona;
            cout << "|" << setw (11) << ID << setw (7) << "|" << setw(18) << longitud << " , " << latitud << setw (5) << "|" << setw(15) << NIF
            << setw (7) << "|" << setw(8) << zona << setw(7) << "|" << setw(7)<< urgencia << setw(7)<< "|" <<endl;
            cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        }


    }while(paqueteAux.NIF.NIFCompleto != "");
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(59) << "Zona Suroeste" << setw(47) << "|" << endl;
    utilidades.menu_enviados();
    do{

        paqueteAux = colaSO.desencolar();
        if(paqueteAux.NIF.NIFCompleto != ""){
            string urgencia;
            if(paqueteAux.urgente){urgencia = "SI";}else urgencia = "NO";
            string longitud = paqueteAux.Coordenadas.longitud;
            string latitud = paqueteAux.Coordenadas.latitud;
            string NIF = paqueteAux.NIF.NIFCompleto;
            string ID = paqueteAux.Identificador.ID;
            string zona = paqueteAux.zona;
            cout << "|" << setw (11) << ID << setw (7) << "|" << setw(18) << longitud << " , " << latitud << setw (5) << "|" << setw(15) << NIF
            << setw (7) << "|" << setw(8) << zona << setw(7) << "|" << setw(7)<< urgencia << setw(7)<< "|" <<endl;
            cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        }

    }while(paqueteAux.NIF.NIFCompleto != "");




    //TODO: MOSTRAR COLAS DE CADA ZONA POR PANTALLA Y PAQUETES URGENTES
    //Mostrar colas de cada zona por pantalla
    //Paquetes urgentes:

        /*


            Meter paquetes urgentes en una pila de urgentes, recorrer esa pila metiendolos en los muelles correspondientes los primeros.
            USAR colaAux;



        */

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





    return 0;
}

