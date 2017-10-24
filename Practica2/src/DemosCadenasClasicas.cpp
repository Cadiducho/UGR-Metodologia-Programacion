#include <iostream>
#include "MiCadenaClasica.h"

/*
	Ejercicios del 9 al 15
*/
using namespace std;

int main() {
    const int TAMANIO = 100;
    char cadena_1[TAMANIO];
    char cadena_2[TAMANIO];
    int longitud_1, longitud_2, comparacion, subcadena_i, subcadena_l;
	char *subcadena_p, *invertida;

    cout << "Introduzca primera cadena: ";
    cin.getline(cadena_1, TAMANIO);

    cout << "Introduzca segunda cadena: ";
    cin.getline(cadena_2, TAMANIO);
	
	cout << endl;
	
	// LONGITUD. Ejercicio 9
    longitud_1 = longitud_cadena(cadena_1);
    longitud_2 = longitud_cadena(cadena_2);

    cout << "\nLongitud de la primera cadena: " << longitud_1 << endl;
    cout << "Longitud de la segunda cadena: " << longitud_2 << endl;

	cout << endl;
	
	// PALINDROMO. Ejercicio 10
	
	cout << "La primera cadena" << (palindromo(cadena_1) ? "" : " no") << " es palindroma" << endl;
	cout << "La segunda cadena" << (palindromo(cadena_2) ? "" : " no") << " es palindroma" << endl;
	
	cout << endl;
	
	// COMPARACIÓN. Ejercicio 11
    comparacion = comparar_cadenas(cadena_1, cadena_2);

	cout << "Comparación por análisis lexicográfico: ";
    if (comparacion == 0)
        cout << "Las dos cadenas son iguales" << endl;
    else if (comparacion > 0)
        cout << "La primera cadena es mas grande " << endl;
    else
    	cout << "La segunda cadena es mas grande" << endl;  

	cout << endl;
	// COPIAR. Ejercicio 12
	copiar_cadena(cadena_1, cadena_2);
    cout << "Cadena copiada: " << cadena_1 << endl;

    cout << endl;
	
	// ENCADENAR. Ejercicio 13
    encadenar_cadena(cadena_1, cadena_2);
    cout << "Cadenas concatenadas: " << cadena_1 << endl;
	
	cout << endl;
	
	// SUBCADENA. Ejercicio 14
	cout << "Introduzca la posicion de inicio de la subcadena: ";
    cin >> subcadena_i;
	cout << "Introduzca longitud de la subcadena: ";
    cin >> subcadena_l;
	
	subcadena_p = subcadena(cadena_1, subcadena_i, subcadena_l);

    cout << "Subcadena obtenida: " << endl;
    cout << subcadena_p;
	
	cout << endl;
	
	// INVETIR. Ejercicio 15
	
	invertida = invertir_cadena(cadena_1);
	cout << "Cadena invertida: " << endl;
	
	cout << invertida;
}
