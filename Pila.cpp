#include <iostream>
using namespace std;

class Pila {
private:
    int top;
    int capacidad;
    int* arr;

public:
    Pila(int cap) {
        capacidad = cap;
        top = -1;
        arr = new int[capacidad];
    }

    bool estaVacia() {
        return top == -1;
    }

    bool estaLlena() {
        return top == capacidad - 1;
    }

    void push(int x) {
        if (estaLlena()) {
            cout << "Error: Pila llena\n";
            return;
        }
        arr[++top] = x;
        cout << "Elemento insertado\n";
    }

    void pop() {
        if (estaVacia()) {
            cout << "Error: Pila vacia\n";
            return;
        }
        cout << "Elemento eliminado: " << arr[top] << endl;
        top--;
    }

    void peek() {
        if (estaVacia()) {
            cout << "Pila vacia\n";
            return;
        }
        cout << "Elemento en la cima: " << arr[top] << endl;
    }
};

int main() {
    int opcion, valor;
    Pila pila(5); // tamaño de la pila

    do {
        cout << "\n===== MENU PILA =====\n";
        cout << "1. Push (Insertar)\n";
        cout << "2. Pop (Retirar)\n";
        cout << "3. Peek (Ver cima)\n";
        cout << "4. Verificar si esta vacia\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese valor: ";
            cin >> valor;
            pila.push(valor);
            break;

        case 2:
            pila.pop();
            break;

        case 3:
            pila.peek();
            break;

        case 4:
            if (pila.estaVacia())
                cout << "La pila esta vacia\n";
            else
                cout << "La pila NO esta vacia\n";
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
