#include <iostream>

#include "Punto.h"
#include "Polilinea.h"

using namespace std;

int main(int argc, char** argv) {
	
	cout << "Se crea un punto por defecto (será 0,0) y otro con valor (1,1)" << endl;
	Punto *puntoUno = new Punto();
	Punto *puntoDos = new Punto(1, 1);
	
	cout << "Se crea la linea vacia" << endl;
	Polilinea * linea = new Polilinea();
	linea->print();
	
	cout << "Se agregan los dos puntos ya previamente creados y un tercero pasando ints por referencia" << endl;
	linea->addPoint(*puntoUno);
	linea->addPoint(*puntoDos);
	linea->addPoint(3, 3);
	linea->print();
	
	cout << "Se crea una nueva instancia de linea a traves del operador de asignacion" << endl;
	Polilinea otraLinea = *linea;
	cout << "Linea copiada: ";
	otraLinea.print();
	
	delete linea;
	delete puntoUno;
	delete puntoDos;
}
