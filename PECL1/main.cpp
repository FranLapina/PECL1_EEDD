#include <iostream>
#include <utilidades.h>

using namespace std;

int main()
{

    //ZONA DE PRUEBAS
    utilidades utilidades;
    //utilidades.menu_principal();
    for(int i = 0; i <= 20; ++i)
    {

        Paquete paquete;
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
