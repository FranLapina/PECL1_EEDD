
#include "MiCola.hpp"

MiCola::MiCola() {
    genteEnCola = 0;

    primero = NULL;
    ultimo = NULL;
}

void MiCola::generarPersonas(bool registrado) {
    if (registrado){
        for (int i = 0; i < 15; i++){
            if (!this->primero) {
                Cliente clientePrimero(true, 0);
                insertar(clientePrimero);
            }
                else {
                Cliente cliente(true,((this->ultimo->cliente.gethoraLlegadaCola()) + (rand () % 6)));
                insertar(cliente);
            }
        }
    } else{
        for (int i = 0; i < 25; i++){
            if (!this->primero) {
                Cliente clientePrimero(false, 120);
                insertar(clientePrimero);
            }
            else {
                Cliente cliente(false,((this->ultimo->cliente.gethoraLlegadaCola()) + (rand () % 6)));
                insertar(cliente);
            }
        }
    }
}

void MiCola::insertar(Cliente cliente) {
    pnodoCola nuevoElemento;
    nuevoElemento = new MiNodoCola(cliente);

    if (ultimo)
        ultimo->siguiente = nuevoElemento;
    if (!primero)
        primero = nuevoElemento;
    ultimo = nuevoElemento;

    genteEnCola ++;
}

void MiCola::mostrarCola() {
    if (!this->primero)
        cout << "\n\tNo hay elementos en cola";
    else {
        MiNodoCola* auxPers;
        auxPers = this->primero;
        while (auxPers) {
            auxPers->cliente.mostrarDatos();
            auxPers = auxPers->siguiente;
        }
    }
}

int MiCola::getUsuarios() {
    return genteEnCola;
}

void MiCola::popFirst(){
    pnodoCola aux;
    aux = this->primero;
    primero = primero->siguiente;
    if (this->genteEnCola == 2)
        ultimo = primero;
    aux = NULL;
    this->genteEnCola--;
}

void MiCola::mostrarHora(int minuto) {
    int hora = 0;

    while (minuto >= 60){
        hora++;
        minuto -= 60;
    }
    if (hora < 10)
        cout << ("\n\n\n\t0");
    cout << hora << ":";
    if (minuto < 10)
        cout << ("0");
    cout << minuto << "\n\n" << endl;
}

void MiCola::mostrarServidor() {

    if (!this->primero)
        cout << "\n\tNo hay elementos en cola";
    else {
        pnodoCola auxPers;
        auxPers = this->primero;
        while (auxPers) {
            auxPers->cliente.mostrarDatos();
            auxPers = auxPers->siguiente;
        }
    }
}

void MiCola::mostrarLista() {
    pnodoCola auxPers;
    auxPers = this->primero;

    while (auxPers) {
        auxPers->cliente.mostrarDatos();
        auxPers->cliente.mostrarHoraInicioCompra();
        auxPers->cliente.mostrarHoraFinCompra();
        auxPers->cliente.mostrarId();
        auxPers = auxPers->siguiente;
    }
}

MiLista MiCola::simularCompra(bool registro, MiLista lista) {
    if (registro) {
        MiCola *servidor = new MiCola();
        MiCola *auxiliar = new MiCola();
        int minutoTotal = 0;

        while (this->primero || servidor->primero) {
            lista = servidor->usarServidor(lista, auxiliar, minutoTotal);
            while (this->genteEnCola && minutoTotal >= this->primero->cliente.gethoraLlegadaCola())
                this->seleccionarTiempo(servidor, minutoTotal);

                this->mostrarHora(minutoTotal);
                cout << "\n\n\n\n\n\tClientes en la cola: " << endl;
                if (this->primero)
                    this->mostrarCola();
                cout << "\n\n\tClientes en el servidor: " << endl;
                if (servidor->primero) {
                    servidor->mostrarServidor();
                }
                cout << "\n\n\tClientes en la lista: " << endl;
                if (auxiliar->primero) {
                    auxiliar->mostrarLista();
                }
                minutoTotal++;
                usleep(1000000);
            }
        delete servidor;
        delete auxiliar;
    }else{
        MiCola *servidor1 = new MiCola();
        MiCola *servidor2 = new MiCola();
        MiCola *servidor3 = new MiCola();
        MiCola *servidor4 = new MiCola();
        MiCola *auxiliar = new MiCola();
        int minutoTotal = 120;
        unsigned int servidorNumero = 0;

        while(this->primero || servidor1->primero || servidor2->primero ||servidor3->primero || servidor4->primero){
            lista = servidor1->usarServidor(lista, auxiliar, minutoTotal);
            lista = servidor2->usarServidor(lista, auxiliar, minutoTotal);
            lista = servidor3->usarServidor(lista, auxiliar, minutoTotal);
            lista = servidor4->usarServidor(lista, auxiliar, minutoTotal);

            while (this->genteEnCola && minutoTotal >= this->primero->cliente.gethoraLlegadaCola()) {
                if (servidor1->getUsuarios() == 0)
                    this->seleccionarTiempo(servidor1, minutoTotal);
                else if (servidor2->getUsuarios() == 0)
                    this->seleccionarTiempo(servidor2, minutoTotal);
                else if (servidor3->getUsuarios() == 0)
                    this->seleccionarTiempo(servidor3, minutoTotal);
                else if (servidor4->getUsuarios() == 0)
                    this->seleccionarTiempo(servidor4, minutoTotal);
                else{
                    servidorNumero = this->menosUsuarios(servidor1, servidor2, servidor3, servidor4);
                    switch (servidorNumero){
                        case 1:{
                            this->seleccionarTiempo(servidor1, minutoTotal);
                            break;
                        }
                        case 2:{
                            this->seleccionarTiempo(servidor2, minutoTotal);
                            break;
                        }
                        case 3:{
                            this->seleccionarTiempo(servidor3, minutoTotal);
                            break;
                        }
                        case 4: {
                            this->seleccionarTiempo(servidor4, minutoTotal);
                            break;
                        }
                    }
                }
            }
            this->mostrarHora(minutoTotal);
            cout << "\n\n\n\tClientes en la cola: " << endl;
            if (this->primero)
                this->mostrarCola();
            cout << "\n\n\tClientes en el servidor 1: " << endl;
            if (servidor1->primero) {
                servidor1->mostrarServidor();
            }
            cout << "\n\n\tClientes en el servidor 2: " << endl;
            if (servidor2->primero) {
                servidor2->mostrarServidor();
            }cout << "\n\n\tClientes en el servidor 3: " << endl;
            if (servidor3->primero) {
                servidor3->mostrarServidor();
            }
            cout << "\n\n\tClientes en el servidor 4: " << endl;
            if (servidor4->primero) {
                servidor4->mostrarServidor();
            }
            cout << "\n\n\tClientes en la lista: " << endl;
            if (auxiliar->primero) {
                auxiliar->mostrarLista();
            }

            minutoTotal++;
            usleep(1000000);
        }
        delete auxiliar; delete servidor1; delete servidor2; delete servidor3; delete servidor4;
    }
    return lista;
}

MiLista MiCola::usarServidor(MiLista lista, MiCola* auxiliar, int minutoTotal) {
    while (this->primero) {
        if (minutoTotal >= this->primero->cliente.getHoraFinCompra()) {
            lista.insertar(this->primero->cliente);
            auxiliar->insertar(this->primero->cliente);
            this->popFirst();
        } else
            break;
    }
    return lista;
}

void MiCola::seleccionarTiempo(MiCola *servidor, int minutoTotal) {

    if(!servidor->ultimo)
        this->primero->cliente.realizarCompra(minutoTotal);
    else
        this->primero->cliente.realizarCompra(minutoTotal > servidor->ultimo->cliente.getHoraFinCompra() ?
                                              minutoTotal : servidor->ultimo->cliente.getHoraFinCompra());
    servidor->insertar(this->primero->cliente);
    this->popFirst();
}

unsigned int MiCola::menosUsuarios(MiCola *servidor1, MiCola *servidor2, MiCola *servidor3, MiCola *servidor4) {

    if (servidor4->getUsuarios() < servidor3->getUsuarios() &&
        servidor4->getUsuarios() < servidor2->getUsuarios() &&
        servidor4->getUsuarios() < servidor1->getUsuarios())
        return 4;
    else if (servidor3->getUsuarios() < servidor2->getUsuarios() &&
             servidor3->getUsuarios() < servidor1->getUsuarios())
        return 3;
    else if (servidor2->getUsuarios() < servidor1->getUsuarios())
       return 2;
    else
        return 1;
}

void MiCola::especificarCliente(bool regis) {
    int numeroDNI = 0;
    char id[5];

    cout << "\n\tInserte el número del dni (-1 Para generar uno aleatorio): ";
    cin >> numeroDNI;
    cout << "\n\tInserte el ID de entrada (letra a letra): ";

    for (int i = 0; i < 4; i ++) {
        cin >> id[i];
    }
    Cliente cliente(regis, numeroDNI, id);
    insertar(cliente);
}
