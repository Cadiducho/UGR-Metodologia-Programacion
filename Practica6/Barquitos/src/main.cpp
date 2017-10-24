#include <iostream>

using namespace std;

#include "Barquitos.h"

int main() {
	
	int filas = 10;
	int columnas = 10;
	cout << "Creando tablero de 10x10 " << endl;
	
	Barquitos * barquitos = new Barquitos(filas, columnas);
	
	barquitos->setShip(4, 4, 3, VERTICAL);
	barquitos->setShip(3, 3, 5, VERTICAL);
	barquitos->setShip(3, 3, 7, HORIZONTAL);
	barquitos->setShip(2, 3, 8, HORIZONTAL);
	
	barquitos->shot(4,4);
	barquitos->shot(2,1);
	
	cout << "Vista del jugador: " << endl;
	barquitos->print();
	
	cout << "Vista de la matrix: " << endl;
	barquitos->rawPrint();
	
	delete barquitos;
	return 0;
}
