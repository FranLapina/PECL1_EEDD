#include <iostream>
#include <utilidades.h>

using namespace std;

int main()
{

    //ZONA DE PRUEBAS
    utilidades utilidades;
    //utilidades.menu_principal();
    for(int i = 0; i <= 11; ++i)
    {

        Paquete paquete;
        string longitud = paquete.Coordenadas.longitud;
        string latitud = paquete.Coordenadas.latitud;
        string NIF = paquete.NIF.NIFCompleto;
        string ID = paquete.Identificador.ID;
        cout << "Coordenadas: " << longitud << " | " << latitud << " | "
             << "DNI: "<< NIF << " | " << "Identificador: "<< ID <<endl;

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
