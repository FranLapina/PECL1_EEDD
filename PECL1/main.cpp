#include <iostream>
#include <utilidades.h>

using namespace std;

int main()
{

    //ZONA DE PRUEBAS
    utilidades utilidades;
    utilidades.menu_principal();
    for(int i = 0; i <= 11; ++i)
    {

        Paquete paquete;
        cout << "Coordenadas: " << paquete.longitud << " | " << paquete.latitud << " | "
             << "DNI: "<< paquete.var_NIF << endl;

    }

    utilidades.menu_carga();
    cout << "pito" << endl;

    utilidades.menu_entregados();

    //FIN DE ZONA DE PRUEBAS
    return 0;
}
