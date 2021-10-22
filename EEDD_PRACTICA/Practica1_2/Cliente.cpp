#include "Cliente.hpp"

Cliente::Cliente(){}

Cliente::Cliente(bool registro, int hora) { //El constructor no vacío, asigna valor al bool registrado, la hora de entrada a la cola y un DNI
    char letras[23] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B',    /*El array que contiene*/
                       'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'};       /*las letras en función del número*/
    unsigned int aux, numAux = 0;

    registrado = registro;
    horaLlegadaCola = hora;

    for (int i = 0; i < 8; i++){
        aux = rand() % 9;
        numAux = numAux*10*i + aux;
        dni[i] = aux + 48;
    }
    dni[8] = letras [numAux %13];
    dni [9] = '\0';
}

Cliente::Cliente(bool registro, int numeroDNI, char *idEn) {
    int numAux = numeroDNI;
    registrado = registro;
    char letras[23] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B',    /*El array que contiene*/
                       'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'};       /*las letras en función del número*/

    for (int i = 0; i < 8; i++){
        dni[7-i] = (numAux % 10)+48;
        numAux /= 10;
    }
    dni[8] = letras [numeroDNI %13];
    dni [9] = '\0';
    for (int i = 0; i < 4; i++)
        id[i] = idEn[i];
    id[4] = '\0';

}

Cliente::Cliente(int numeroDni) {
    char letras[23] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B',    /*El array que contiene*/
                       'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'};       /*las letras en función del número*/
    int numAux = numeroDni;
    for (int i = 0; i < 8; i++){
        dni[7-i] = (numAux % 10)+48;
        numAux /= 10;
    }
    dni[8] = letras [numeroDni %13];
    dni [9] = '\0';
    for (int i = 0; i<= 3; i++)
        this->id[i] = (65 + rand()%26); //El caracter 65 se corresponde con 'A' mayuscula, por tanto generamos un rand() que varíe entre él y 'Z'
    this->id[4] = '\0';
}

void Cliente::mostrarDatos() { //Método que muestra los datos del cliente (DNI, registro, hora de llegada a cola)
    int auxHora = 0;
    int auxMinuto = this->horaLlegadaCola;
    cout << "\n\tDNI: " << this->dni;
    cout << "\tUsuario " ;
    if (this->registrado)
        cout << "registrado";
    else
        cout << "no registrado";
    while (auxMinuto >= 60){ //Mostramos la hora con formato Hh:Mm para que se vea más natural que solo en minutos
        auxMinuto -= 60;
        auxHora++;
    }
    while (auxHora >= 24)
        auxHora -= 24;

    cout << "\tHora llegada a cola: ";
    if (auxHora < 10)
        cout << ("0") << auxHora;
    else
        cout << auxHora;
    cout << ":";
    if (auxMinuto <10)
        cout << "0";
    cout << auxMinuto;
}

int Cliente::gethoraLlegadaCola() {
    return horaLlegadaCola;
}

void Cliente::realizarCompra(int tiempoServidor) { //Al realizar la compra se le asigna un ID al cliente, una hora de inicio de la compra y una de fin de la compra
    this->horaInicioCompra = tiempoServidor;

    for (int i = 0; i<= 3; i++)
        this->id[i] = (65 + rand()%26); //El caracter 65 se corresponde con 'A' mayuscula, por tanto generamos un rand() que varíe entre él y 'Z'
    this->id[4] = '\0';
    this->horaFinCompra = this->horaInicioCompra + rand () % 10 + 1; //Generamos un random entre 0 y 9 y le sumamos 1, por tanto podrá tener valores de 1 a 10. El 0 no tiene sentido
}

void Cliente::mostrarHoraInicioCompra() {
    int auxMinuto = this->horaInicioCompra;
    int auxHora = 0;

    while (auxMinuto >= 60){ //Mostramos la hora con formato Hh:Mm para que se vea más natural que solo en minutos
        auxMinuto -= 60;
        auxHora++;
    }
    cout << "\tHora de inicio de compra: ";
    if (auxHora < 10)
        cout << ("0") << auxHora;
    else
        cout << auxHora;
    cout << ":";
    if (auxMinuto <10)
        cout << "0";
    cout << auxMinuto<<endl;
}

void Cliente::mostrarHoraFinCompra(){
    int auxMinuto = this->horaFinCompra;
    int auxHora = 0;

    while (auxMinuto >= 60){ //Mostramos la hora con formato Hh:Mm para que se vea más natural que solo en minutos
        auxMinuto -= 60;
        auxHora++;
    }
    cout << "\tHora de fin de compra: ";
    if (auxHora < 10)
        cout << ("0") << auxHora;
    else
        cout << auxHora;
    cout << ":";
    if (auxMinuto <10)
        cout << "0";
    cout << auxMinuto;
}

void Cliente::mostrarId() {
    cout << "\t\tID: " << id << endl;
}

char* Cliente::getValorId() {
    return id;
}

int Cliente::getHoraFinCompra() {
    return this->horaFinCompra;
}

char* Cliente::getDni() {
    return dni;
}
