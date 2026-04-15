#include <iostream>
using namespace std;

// ================= NODO LISTA =================
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// ================= LISTA (HISTORIAL COMPLETO) =================
class Lista {
private:
    Nodo* cabeza;

public:
    Lista() {
        cabeza = NULL;
    }

    void insertar(int x) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = x;
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    void mostrar() {
        if (cabeza == NULL) {
            cout << "No hay historial\n";
            return;
        }

        Nodo* aux = cabeza;
        cout << "Historial completo:\n";
        while (aux != NULL) {
            cout << aux->dato << " -> ";
            aux = aux->siguiente;
        }
        cout << "NULL\n";
    }
};

// ================= PILA =================
class Pila {
private:
    int top;
    int arr[100];

public:
    Pila() {
        top = -1;
    }

    bool estaVacia() {
        return top == -1;
    }

    void push(int x) {
        if (top == 99) {
            cout << "Pila llena\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (estaVacia()) {
            cout << "Pila vacia\n";
            return;
        }
        top--;
    }

    int peek() {
        if (estaVacia()) return -1;
        return arr[top];
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "No hay atendidos\n";
            return;
        }

        cout << "Ultimos atendidos:\n";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

// ================= COLA =================
class Cola {
private:
    int frente, fin;
    int arr[100];

public:
    Cola() {
        frente = 0;
        fin = -1;
    }

    bool estaVacia() {
        return fin < frente;
    }

    void encolar(int x) {
        if (fin == 99) {
            cout << "Cola llena\n";
            return;
        }
        arr[++fin] = x;
    }

    int atender() {
        if (estaVacia()) {
            cout << "No hay solicitudes\n";
            return -1;
        }
        return arr[frente++];
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "No hay solicitudes en espera\n";
            return;
        }

        cout << "Solicitudes en espera:\n";
        for (int i = frente; i <= fin; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// ================= MAIN =================
int main() {
    Cola cola;
    Pila pila;
    Lista lista;

    int opcion, solicitud = 1, atendido;

    do {
        cout << "\n===== GESTOR DE SOLICITUDES =====\n";
        cout << "1. Nueva solicitud\n";
        cout << "2. Atender solicitud\n";
        cout << "3. Ver solicitudes en espera\n";
        cout << "4. Ver ultimos atendidos\n";
        cout << "5. Ver historial completo\n";
        cout << "0. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            cout << "Solicitud agregada con ID: " << solicitud << endl;
            cola.encolar(solicitud);
            solicitud++;
            break;

        
        case 2:
    atendido = cola.atender();
    if (atendido != -1) {
        cout << "Atendiendo solicitud: " << atendido << endl;

        lista.insertar(atendido); // historial correcto
        pila.push(atendido);      // recientes
    }
    break;

        case 3:
            cola.mostrar();
            break;

        case 4:
            pila.mostrar();
            break;

        case 5:
            lista.mostrar();
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
