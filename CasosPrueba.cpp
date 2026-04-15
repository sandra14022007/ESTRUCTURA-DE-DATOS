#include <iostream>
#include <string>
#include <limits> // para limpiar buffer
using namespace std;

// ---- STRUCT SOLICITUD ----
struct Solicitud {
    string cedula;
    string nombre;
    string motivo;
};

// =============================
// CLASE PILA (Stack)
// =============================
class Pila {
private:
    static const int TAM = 10;
    Solicitud datos[TAM];
    int sp;

public:
    Pila() : sp(0) {}

    bool estaVacia() { return sp == 0; }
    bool estaLlena() { return sp == TAM; }

    void apilar(Solicitud s) {
        if (estaLlena()) { cout << "Error: pila llena\n"; return; }
        datos[sp++] = s;
    }

    void mostrar() {
        if (estaVacia()) { cout << "Pila vacia\n"; return; }
        cout << "\n--- Ultimos atendidos ---\n";
        for (int i = sp - 1; i >= 0; i--) {
            cout << i + 1 << ". " << datos[i].nombre
                 << " (" << datos[i].cedula << ") - "
                 << datos[i].motivo << "\n";
        }
    }
};

// =============================
// CLASE COLA (Queue)
// =============================
class Cola {
private:
    static const int TAM = 10;
    Solicitud datos[TAM];
    int ini, fin, num;

public:
    Cola() : ini(0), fin(0), num(0) {}

    bool estaVacia() { return num == 0; }
    bool estaLlena() { return num == TAM; }

    void encolar(Solicitud s) {
        if (estaLlena()) { cout << "Error: cola llena\n"; return; }
        datos[fin] = s;
        fin = (fin + 1) % TAM;
        num++;
    }

    void desencolar() {
        if (estaVacia()) { cout << "Error: cola vacia\n"; return; }
        ini = (ini + 1) % TAM;
        num--;
    }

    Solicitud frente() { return datos[ini]; }

    void mostrar() {
        if (estaVacia()) { cout << "No hay pendientes\n"; return; }
        cout << "\n--- Pendientes ---\n";
        for (int i = 0; i < num; i++) {
            cout << i + 1 << ". " << datos[(ini + i) % TAM].nombre
                 << " (" << datos[(ini + i) % TAM].cedula << ") - "
                 << datos[(ini + i) % TAM].motivo << "\n";
        }
    }
};

// =============================
// CLASE LISTA (Historial)
// =============================
class Lista {
private:
    struct Nodo {
        Solicitud dato;
        Nodo* sig;
        Nodo(Solicitud s) : dato(s), sig(NULL) {}
    };
    Nodo* cabeza;

public:
    Lista() : cabeza(NULL) {}

    ~Lista() {
        Nodo* actual = cabeza;
        while (actual) {
            Nodo* temp = actual;
            actual = actual->sig;
            delete temp;
        }
    }

    bool estaVacia() { return cabeza == NULL; }

    void agregar(Solicitud s) {
        Nodo* nuevo = new Nodo(s);
        if (!cabeza) cabeza = nuevo;
        else {
            Nodo* actual = cabeza;
            while (actual->sig) actual = actual->sig;
            actual->sig = nuevo;
        }
    }

    void mostrar() {
        if (estaVacia()) { cout << "Historial vacio\n"; return; }
        cout << "\n--- Historial ---\n";
        Nodo* actual = cabeza;
        int i = 1;
        while (actual) {
            cout << i++ << ". " << actual->dato.nombre
                 << " (" << actual->dato.cedula << ") - "
                 << actual->dato.motivo << "\n";
            actual = actual->sig;
        }
    }
};

// =============================
// CLASE LABORATORIO
// =============================
class Laboratorio {
private:
    Cola  pendientes;
    Lista atendidos;
    Pila  recientes;

    Solicitud pedirDatos() {
        Solicitud s;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar buffer

        cout << "Cedula: ";
        getline(cin, s.cedula);

        cout << "Nombre: ";
        getline(cin, s.nombre);

        cout << "Motivo: ";
        getline(cin, s.motivo);

        return s;
    }

public:
    void agregarSolicitud() {
        Solicitud s = pedirDatos();
        pendientes.encolar(s);
        cout << "Solicitud registrada.\n";
    }

    void atenderSolicitud() {
        if (pendientes.estaVacia()) {
            cout << "No hay solicitudes pendientes.\n";
            return;
        }

        Solicitud actual = pendientes.frente();
        pendientes.desencolar();
        atendidos.agregar(actual);
        recientes.apilar(actual);

        cout << "Atendido: " << actual.nombre
             << " | Motivo: " << actual.motivo << "\n";
    }

    void verPendientes()  { pendientes.mostrar(); }
    void verHistorial()   { atendidos.mostrar(); }
    void verRecientes()   { recientes.mostrar(); }
};

// =============================
// MAIN
// =============================
int main() {
    Laboratorio lab;
    int op;

    do {
        cout << "\n=== LABORATORIO ===\n";
        cout << "1. Nueva solicitud\n";
        cout << "2. Atender siguiente\n";
        cout << "3. Ver pendientes\n";
        cout << "4. Ver historial\n";
        cout << "5. Ver recientes\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";

        cin >> op;

        switch (op) {
            case 1: lab.agregarSolicitud(); break;
            case 2: lab.atenderSolicitud(); break;
            case 3: lab.verPendientes(); break;
            case 4: lab.verHistorial(); break;
            case 5: lab.verRecientes(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida\n";
        }

    } while (op != 0);

    return 0;
}
