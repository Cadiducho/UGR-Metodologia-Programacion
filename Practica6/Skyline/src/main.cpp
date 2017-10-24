#include <iostream>
#include "Skyline.h"

using namespace std;

int main(int argc, char** argv) {
	
	cout << "Se crea un skyline de un edificio" << endl;
	double a = 0, b = 3, c = 5;
	Skyline * edificio = new Skyline(a, b, c);
	
	edificio->print();
	
	Skyline * copia = edificio;
	
	cout << "El edificio se copia" << endl;
	copia->print();
	
	cout << "Otro skyline es creado mediante arrays de valores" << endl;
	int tam = 11;
	double abscisas[] = {1, 1.5, 2.5, 3, 3.5, 4, 5, 6, 6.5, 7.8};
	double alturas[] = {1.5, 2.5, 2.0, 1.5, 1, 2.5, 1.5, 2, 1};
	Skyline * linea = new Skyline(abscisas, alturas, tam);
	
	linea->print();
	
	delete edificio;
	delete linea;
	
	return 0;
}
