#include <iostream>
using namespace std;
 
class Libro{
	public: 
	string nombre;
	string autor;
	int numeroPaginas;
	
	void mostrarDatos(){
		cout << "Nombre: " << nombre<< endl;
		cout << "Autor: " << autor<< endl;
		cout << "Número de páginas: " << numeroPaginas<< endl;
	}
};

int main(){
	Libro l1;
	l1.nombre="Boulevard";
	l1.autor="Flor M. Salvador";
	l1.numeroPaginas=365;
	l1.mostrarDatos();
	
	
	return 0;
	
}

