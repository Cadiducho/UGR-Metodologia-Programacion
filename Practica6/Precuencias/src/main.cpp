#include <iostream>

#include "Pareja.h"
#include "Precuencias.h"

using namespace std;

int main(int argc, char** argv) {
	
	cout << "Se crea una lista de precuencias " << endl;
	Precuencias * precuenciaUno = new Precuencias();
	
	cout << "Se le agregan unos cuantos valores" << endl;
	precuenciaUno->agregarValor(1);
	precuenciaUno->agregarValor(2);
	precuenciaUno->agregarValor(3);
	precuenciaUno->agregarValor(1);
	precuenciaUno->agregarValor(2);
	
	precuenciaUno->print();
	
	cout << "Una nueva lista con el operador de asignacion" << endl;
	Precuencias * precuenciaCopia = precuenciaUno;
	
	precuenciaCopia->print();
	
	delete precuenciaUno;
	
	return 0;
}
