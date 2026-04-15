#include <iostream>
using namespace std;

class Cola {
private:
    int frente, fin;
    int capacidad;
    int* arr;

public:
    Cola(int cap) {
        capacidad = cap;
        frente = 0;
        fin = -1;
        arr = new int[capacidad];
    }

    bool estaVacia() {
        return fin < frente;
    }

    bool estaLlena() {
        return fin == capacidad - 1;
    }

    void encolar(int x) {
        if (estaLlena()) {
            cout << "Error: Cola llena\n";
            return;
        }
        arr[++fin] = x;
        cout << "Cliente agregado a la fila\n";
    }

    void atender() {
        if (estaVacia()) {
            cout << "No hay clientes para atender\n";
            return;
        }
        cout << "Atendiendo cliente: " << arr[frente] << endl;
        frente++;
    }

    void verFrente() {
        if (estaVacia()) {
            cout << "No hay clientes en espera\n";
            return;
        }
        cout << "Proximo cliente: " << arr[frente] << endl;
    }
};

int main() {
    int opcion, valor;
    Cola cola(5); // tamaño de la cola

    do {
        cout << "\n===== MENU COLA =====\n";
        cout << "1. Encolar (llegar cliente)\n";
        cout << "2. Atender (dequeue)\n";
        cout << "3. Ver proximo en la fila (front)\n";
        cout << "4. Verificar si hay gente esperando\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese ID del cliente: ";
            cin >> valor;
            cola.encolar(valor);
            break;

        case 2:
            cola.atender();
            break;

        case 3:
            cola.verFrente();
            break;

        case 4:
            if (cola.estaVacia())
                cout << "No hay clientes en espera\n";
            else
                cout << "Hay clientes en la fila\n";
            break;

        case 0:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 0);

    return 0;
}
