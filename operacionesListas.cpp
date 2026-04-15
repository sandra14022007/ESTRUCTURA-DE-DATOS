#include <iostream>   
#include <vector>     
using namespace std;  

int main(){
	
	vector <int> datos;
	datos.push_back(12);
	datos.push_back(18);
	datos.push_back(25);
	//recorrer el vector 
	for (int i=0;i<datos.size(); i++){
		cout<<datos[i]<<endl;
	}
	//buscar el 18 
	for (int i=0;i<datos.size(); i++){
		if (datos)
		cout<<datos[i]<<endl;
	}
	//insertar 
	bool insertar(int pos, int valor){
		if(n>MAX || )
	}
	// eliminar 
	bool eliminar(int pos){
		if (pos <0 || pos>=n){
			
			return false
		}
		for (int i=pos:i<n-1;i++){
			datos[i]=datos[i+1];
		}
		n--;
		return true; 
	}
}
