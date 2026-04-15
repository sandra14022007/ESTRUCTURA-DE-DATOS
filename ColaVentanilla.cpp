#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> cola;

    // Llegada de clientes
    cola.push("Ana");
    cola.push("Luis");
    cola.push("Pedro");
    cola.push("Maria");

    cout << "Clientes en espera..." << endl;

    // Atención en ventanilla
    while (!cola.empty()) {
        cout << "Atendiendo a: " << cola.front() << endl;
        cola.pop(); // Se atiende y se elimina
    }

    cout << "No hay mas clientes en la cola" << endl;

    return 0;
}
