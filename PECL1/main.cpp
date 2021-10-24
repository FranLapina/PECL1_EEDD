#include <iostream>
#include <utilidades.h>

using namespace std;

int main()
{

    //ZONA DE PRUEBAS
    for(int i = 0; i <= 11; ++i){

        Paquete paquete;
        cout << "Coordenadas: " << paquete.longitud << " | " << paquete.latitud << " | "
         << "DNI: "<< paquete.var_NIF << endl;

    }


    //FIN DE ZONA DE PRUEBAS
    return 0;
}
