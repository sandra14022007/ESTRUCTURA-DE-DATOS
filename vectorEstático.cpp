#include <iostream>
using namespace std;

// CLASE PADRE
class Vehiculo {
public: 
    string marca;
    int anio;      // Tipo de dato primitivo
    float precio;  // Tipo de dato primitivo

    Vehiculo(string m, int a, float p) {
        marca = m;
        anio = a;
        precio = p;
    }

    // Método virtual para POLIMORFISMO
    virtual void mostrar() {
        cout << "Marca: " << marca << endl;
        cout << "Anio: " << anio << endl;
        cout << "Precio: " << precio << endl;
    }
};

// La clase Auto hereda de Vehiculo
class Auto : public Vehiculo {
public:
    int puertas; // Tipo de dato primitivo
//constructor con los datos de vehículo 
    Auto(string m, int a, float p, int pu) : Vehiculo(m,a,p) {
        puertas = pu;
    }

    // POLIMORFISMO
    // Se redefine el método mostrar() adaptado a la clase 
    void mostrar() {
        cout << "Tipo: Auto" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Anio: " << anio << endl;
        cout << "Precio: " << precio << endl;
        cout << "Puertas: " << puertas << endl;
        cout << "-------------------" << endl;
    }
};

// segunda clase hija 
class Moto : public Vehiculo {
public:
    int cilindrada;
//constructor con datos de la clase padre 
    Moto(string m, int a, float p, int c) : Vehiculo(m,a,p) {
        cilindrada = c;
    }

    // POLIMORFISMO
    void mostrar() {
        cout << "Tipo: Moto" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Anio: " << anio << endl;
        cout << "Precio: " << precio << endl;
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
        cout << "-------------------" << endl;
    }
};

// CLASE QUE REGISTRA VEHÍCULOS
// Aquí se usa un ARREGLO ESTÁTICO para almacenar los objetos
class RegistroVehiculos {
public: 
    Vehiculo* vehiculos[10]; // Arreglo estático
    int contador;

    RegistroVehiculos() {
        contador = 0;
    }

    // Método para registrar vehículos
    void registrarVehiculo(Vehiculo* v) {
        if(contador < 10) {//establecemos un limite de 10 registros 
            vehiculos[contador] = v;
            contador++;
        } else {
            cout << "Registro lleno" << endl;
        }
    }

    // Mostrar todos los vehículos registrados
    void mostrarVehiculos() {
        for(int i=0; i<contador; i++) {
            vehiculos[i]->mostrar(); // POLIMORFISMO
        }
    }
};

int main() {

    // INSTANCIACIÓN DE OBJETOS
    RegistroVehiculos sistema;

    // Se crean objetos de diferentes tipos
    Vehiculo* v1 = new Auto("Toyota",2020,20000,4);
    Vehiculo* v2 = new Moto("Yamaha",2022,5000,250);
    Vehiculo* v3 = new Auto("Chevrolet",2019,18000,2);

    // REGISTRO DE VEHÍCULOS
    sistema.registrarVehiculo(v1);
    sistema.registrarVehiculo(v2);
    sistema.registrarVehiculo(v3);

    // Mostrar la información registrada del sistema 
    sistema.mostrarVehiculos();

    return 0;
}
