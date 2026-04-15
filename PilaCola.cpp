#include <iostream>
#include <string>
using namespace std;

// ================= PILA =================
class Pila {
private:
    int top;
    int capacidad;
    char* arr;

public:
    Pila(int cap) {
        capacidad = cap;
        top = -1;
        arr = new char[capacidad];
    }

    bool estaVacia() {
        return top == -1;
    }

    bool estaLlena() {
        return top == capacidad - 1;
    }

    void push(char x) {
        if (estaLlena()) {
            cout << "Error: Pila llena\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (estaVacia()) {
            cout << "Error: Pila vacía\n";
            return;
        }
        top--;
    }

    char cima() {
        if (estaVacia()) return '\0';
        return arr[top];
    }
};

// ================= COLA =================
class Cola {
private:
    int frente, fin, capacidad;
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
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Error: Cola vacía\n";
            return;
        }
        cout << "Atendiendo cliente: " << arr[frente] << endl;
        frente++;
    }

    int frenteCola() {
        if (estaVacia()) return -1;
        return arr[frente];
    }
};

// ================= PARÉNTESIS BALANCEADOS =================
bool parentesisBalanceados(string expr) {
    Pila pila(100);

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if (c == '(') {
            pila.push(c);
        } else if (c == ')') {
            if (pila.estaVacia()) return false;
            pila.pop();
        }
    }

    return pila.estaVacia();
}

// ================= MENÚ PRINCIPAL =================
int main() {
    int opcion;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Verificar parentesis balanceados\n";
        cout << "2. Simulacion de cola (ventanilla)\n";
        cout << "3. Probar pila manual\n";
        cout << "4. Probar cola manual\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string expr;
            cout << "Ingrese la expresion: ";
            cin >> expr;

            if (parentesisBalanceados(expr))
                cout << "Parentesis BALANCEADOS\n";
            else
                cout << "Parentesis NO balanceados\n";
            break;
        }

        case 2: {
            Cola cola(5);
            int op2, cliente = 1;

            do {
                cout << "\n--- Ventanilla ---\n";
                cout << "1. Llegar cliente\n";
                cout << "2. Atender cliente\n";
                cout << "0. Volver\n";
                cin >> op2;

                switch (op2) {
                case 1:
                    cola.encolar(cliente++);
                    break;
                case 2:
                    cola.desencolar();
                    break;
                }
            } while (op2 != 0);
            break;
        }

        case 3: {
            Pila pila(5);
            int op3;
            char dato;

            do {
                cout << "\n--- Pila ---\n";
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Ver cima\n";
                cout << "0. Volver\n";
                cin >> op3;

                switch (op3) {
                case 1:
                    cout << "Ingrese caracter: ";
                    cin >> dato;
                    pila.push(dato);
                    break;
                case 2:
                    pila.pop();
                    break;
                case 3:
                    cout << "Cima: " << pila.cima() << endl;
                    break;
                }
            } while (op3 != 0);
            break;
        }

        case 4: {
            Cola cola(5);
            int op4, dato;

            do {
                cout << "\n--- Cola ---\n";
                cout << "1. Encolar\n";
                cout << "2. Desencolar\n";
                cout << "3. Ver frente\n";
                cout << "0. Volver\n";
                cin >> op4;

                switch (op4) {
                case 1:
                    cout << "Ingrese numero: ";
                    cin >> dato;
                    cola.encolar(dato);
                    break;
                case 2:
                    cola.desencolar();
                    break;
                case 3:
                    cout << "Frente: " << cola.frenteCola() << endl;
                    break;
                }
            } while (op4 != 0);
            break;
        }

        }

    } while (opcion != 0);

    return 0;
}
