#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#include "01_RedimensionarArrayDinamico.h"

int main(int argc, char *argv[]) {
	TipoRedimension tipo;
	if (argc == 2) {
		switch (atoi(argv[1])) {
			case 2:
				tipo = EnBloques;
				break;
			case 3:
				tipo = Duplicando;
				break;
			default:
				tipo = DeUnoEnUno;
				break;
		}
	}
	
	int TAM = 5;
	int * array = new int[TAM];
	
	const char keyStop[] = "FIN";
	int insertados = 0;
	
	int nuevoNumero;
	char fraseEscrita[256];
	cout << "Inserte numero para el slot " << insertados << ": ";
	cin.getline(fraseEscrita, sizeof(fraseEscrita));
	
	while (strcmp (keyStop, fraseEscrita) != 0) {
		nuevoNumero = atoi(fraseEscrita);
		insertados++;

		if (insertados == TAM) {
			Redimensiona(array, tipo, TAM);
		}		
		*(array + insertados) = nuevoNumero;
		cout << "Inserte numero para el slot " << insertados << ": ";
		cin.getline(fraseEscrita, sizeof(fraseEscrita));
	}
	
	cout << "Se han insertado " << insertados << " numeros." << endl;
	delete [] array;
}

int * Redimensiona (int * p, TipoRedimension tipo, int & cap) {
	int * nuevo, nuevaCapacidad;
	switch (tipo) {
		case DeUnoEnUno:
			nuevaCapacidad = cap + 1;
			break;
		case EnBloques:
			nuevaCapacidad = cap + sizeof(int);
			break;			
		case Duplicando:
			nuevaCapacidad = cap + cap;
			break;
	}
	nuevo = new int[nuevaCapacidad];
	memcpy(nuevo, p, cap * sizeof(int) );
	cap = nuevaCapacidad;
	p = nuevo;
	delete [] nuevo;
}
