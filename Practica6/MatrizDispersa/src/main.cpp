#include <iostream>

using namespace std;

#include "MatrizDispersa.h"

int main(int argc, char** argv) {
	int elementos;

	cout << "Valores a introducir: " << endl; 
	cin >> elementos; 

	int arrayfilas[elementos], arraycolumnas[elementos];
	double arrayvalores[elementos]; 

	for (int i = 0; i < elementos; i++) {
		cout << endl << "Elemento: " << i << endl; 
		cout << "Fila: ";
		cin >> arrayfilas[i];
		cout << "Columna: ";
		cin >> arraycolumnas[i]; 
		cout << "Valor: ";
		cin >> arrayvalores[i];
	}

	MatrizDispersa * md = new MatrizDispersa(arrayfilas, arraycolumnas, arrayvalores, elementos); 
	
	cout << md->getNumValores();
	
	cout << "Valores en matrix dispersa " << endl;
	md->muestraValores();
	
	MatrizDispersa * otra = md;
	
	cout << "Valores en copia " << endl;
	otra->muestraValores();
	
	delete md;
	
	return 0;
}
