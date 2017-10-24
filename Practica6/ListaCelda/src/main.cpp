#include <iostream>

#include "Celda.h"
#include "Lista.h"

using namespace std;

int main(int argc, char** argv) {
	
	cout << "Creamos celda con valor 1" << endl;
	Celda * celdaUno = new Celda(1);
	cout << "Otra celda con valor 22" << endl;
	Celda * celdaDos = new Celda(22);
	
	cout << "Lista con la primera celda" << endl;
	Lista * listaUno = new Lista(*celdaUno);
	listaUno->print();
	
	cout << "Agregamos la segunda a la lista" << endl;
	listaUno->addCelda(celdaDos);
	listaUno->print();
	
	cout << "Se crea una segunda lista copiando la primera" << endl;
	Lista * listaDos = new Lista(*listaUno);
	listaDos->print();
	
	cout << "Ambas listas se suman" << endl;
	Lista suma = *listaUno + *listaDos;
	suma.print();
	
	cout << "Se va a borrar el 2 slot" << endl;
	suma[2];
	suma.print();
	
	delete celdaUno;
	delete celdaDos;
	delete listaUno;
	delete listaDos;
	
	return 0;
}
