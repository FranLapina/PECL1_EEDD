#include <iostream>
#include "Gestor.hpp"

using namespace std;

int main(int argc, char **argv) {
    Gestor *gestor = new Gestor();
    char opcion = '0';
    srand(time(NULL));
    do {
        cout << "\n\t-------------------------------------------------" << endl;
        cout << "\n\t                      MENU                       " << endl;
        cout << "\n\t-------------------------------------------------" << endl;
        cout << "\n\tNumero de clientes registrados: " << gestor->getUsuariosColas(true) << endl;
        cout << "\n\tNumero de clientes no registrados: " << gestor->getUsuariosColas(false) << endl;
        cout << "\n\tNumero de clientes en lista: " << gestor->getUsuariosLista() << endl;
        cout << "\n\tA. Generar solicitudes de clientes registrados" << endl;
        cout << "\n\tB. Mostrar la cola de solicitudes de clientes registrados" << endl;
        cout << "\n\tC. Borrar la cola de solicitudes de clientes registrados" << endl;
        cout << "\n\tD. Generar solicitudes de clientes no registrados" << endl;
        cout << "\n\tE. Mostrar la cola de solicitudes de clientes no registrados" << endl;
        cout << "\n\tF. Borrar la cola de solicitudes de clientes registrados" << endl;
        cout << "\n\tG. Simular el proceso de compra de usuarios registrados" << endl;
        cout << "\n\tH. Simular el proceso de compra de usuarios no registrados" << endl;
        cout << "\n\tI. Mostrar la lista de entradas vendidas" << endl;
        cout << "\n\tJ. Reiniciar programa" << endl;
        cout << "\n\tK. Crear arbol binario de busqueda ordenado por DNI" << endl;
        cout << "\n\tL. Buscar un usuario por DNI y mostrar sus datos" << endl;
        cout << "\n\tM. Mostrar ABB en preorden" << endl;
        cout << "\n\tN. Mostrar ABB en orden" << endl;
        cout << "\n\tO. Mostrar ABB en postorden" << endl;
        cout << "\n\tP. Dibujar el arbol" << endl;
        cout << "\n\tZ. Insertar cliente" << endl;

        cout << "\n\tS. Salir del programa" << endl;
        cout << "\n\tSeleccione una opcion: ";
        cin >> opcion;
        opcion = toupper (opcion);

        switch (opcion) {
            case 'A':{
                gestor->simularCola(true);
                break;
            }
            case 'B':{
                gestor->mostrarCola(true);
                break;
            }
            case 'C':{
                gestor->borrarCola(true);
                break;
            }
            case 'D':{
                gestor->simularCola(false);
                break;
            }
            case 'E':{
                gestor->mostrarCola(false);
                break;
            }
            case 'F':{
                gestor->borrarCola(false);
                break;
            }
            case 'G':{
                gestor->simularCompra(true);
                break;
            }
            case 'H':{
                gestor->simularCompra(false);
                break;
            }
            case 'I':{
                gestor->mostrarLista();
                break;
            }
            case 'J':{
                gestor->reiniciar();
                break;
            }
            case 'K':{
                gestor->crearArbol();
                break;
            }
            /*TODO*/
            /*
             case 'L':{
                gestor->buscar();
                break;
              }
            */
            case 'M':{
                gestor->arbolPreOrden();
                break;
            }
            case 'N':{
                gestor->arbolEnOrden();
                break;
            }
            case 'O':{
                gestor->arbolPostOrden();
                break;
            }
            case 'P':{
                gestor->dibujarArbol();
                break;
            }
            case 'Z':{
                gestor->insertarCliente();
                break;
            }
        }
    }while (opcion != 'S');
}
