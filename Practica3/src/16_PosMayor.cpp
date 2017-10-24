#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "16_PosMayor.h"

using namespace std;

int main(int argc, char *argv[]) {
	const int TOPE = 100;
	int vector[TOPE];
	
	int n;
	int d;
	int i;
	switch (argc) {
		case 1:
			n = TOPE;
			i = 0;
			d = TOPE - 1;
			break;
		case 2:
			n = atoi(argv[1]);
			i = 0;
			d = TOPE - 1;
			break;
		case 3:
			n = atoi(argv[1]);
			i = 0;
			d = atoi(argv[2]);
			break;
		case 4:
			n = atoi(argv[1]);
			i = atoi(argv[3]);
			d = atoi(argv[2]);
			break;
		default:
			cout << "No se han introducido los parametros correctos" << endl;
			return 1;
	}

	//Relleno vector
	time_t t;
	srand ((int) time(&t));
    for (int i = 0; i < n; i++) {
        *(vector + i) = rand();
	}
	
	int *mayor = PosMayor(vector, i, d);
	cout << "El valor mayor es " << *mayor << " y ha sido encontrado en " << mayor << endl;
}

int * PosMayor (int *pv, int izda, int dcha) {
	int *p = pv;
	int *mayor = (p + izda);
	
	for (int i = izda; i < dcha; i++) {
		if (*(p + i) > *mayor) {
			mayor = (p + i);
		}
	}
	
	return mayor;
}

