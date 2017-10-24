#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "17_Ordena.h"

using namespace std;

int main() {
	const int TOPE = 50; // Capacidad
	int vector[TOPE]; // Array de datos
	int *ptr[TOPE]; // Indice al array "vector"
	
	//Relleno vector
	srand (time(NULL));
	cout << "Vector inicial: " << endl;
    for (int i = 0; i < TOPE; i++) {
        *(vector + i) = rand() % 100;
        cout << *(vector + i) << " ";
	}
	cout << endl;
	
	Ordena(vector, ptr, 0, TOPE-1);
	
	cout << "Vector ordenado: " << endl;
	for (int i = 0; i < TOPE; i++) {
		cout << *(*(ptr + i)) << " ";
	}
}

void Ordena(int *v, int **pv, int izda, int dcha) {
	int minimo;
	int pos_min;
	
	for (int i = izda; i < dcha + 1; i++) {
		pv[i] = &v[i];
	}
	
	int primera = 0;
	int ultima = dcha - izda;
	
	for (int tope = primera; tope < ultima; tope++) {	
		minimo = *(pv[tope]);
		pos_min = tope;
		for (int i = tope + 1; i <= ultima; i++) {
			if (*(pv[i]) < minimo) {
				pos_min = i;
				minimo = *(pv[i]);
			}
		}
		intercambia(&pv[tope], &pv[pos_min]);
	}
}

void intercambia(int **pi1, int **pi2) {
	int *swap;
	swap = *pi1;
	*pi1 = *pi2;
	*pi2 = swap;
}

