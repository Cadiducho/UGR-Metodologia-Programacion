#include "MiCadenaClasica.h"

//Ejercicio 9
int longitud_cadena(char *ptr_cadena) {
    int contador = 0;

    while (*ptr_cadena != '\0') {
        ptr_cadena++;
        contador++;
    }

    return contador;
}

//Ejercicio 10
bool palindromo(char *primera) {
    char *ref = primera + longitud_cadena(primera) - 1;		
    bool palindromo = true;
    while (*primera != '\0') {
 
        if (*primera != *ref) palindromo = false;
        primera++;
        ref--;
    }
        
	return palindromo;
}

//Ejercicio 11
int comparar_cadenas(char *ptr_cadena_1, char *ptr_cadena_2) {
    int comparacion;

    while ((*ptr_cadena_1 == *ptr_cadena_2) && ((*ptr_cadena_1 != '\0') || (*ptr_cadena_2 != '\0'))) {
        ptr_cadena_1++;
        ptr_cadena_2++;
    }

    if (*ptr_cadena_1 == *ptr_cadena_2)
        comparacion = 0;
    else if (*ptr_cadena_1 < *ptr_cadena_2)
        comparacion = -1;
    else
        comparacion = 1;

    return comparacion;
}

//Ejercicio 12
char * copiar_cadena(char *ptr_cadena_1, char *ptr_cadena_2) {
    char *puntero = ptr_cadena_1;

    while (*ptr_cadena_2 != '\0') {
        *puntero = *ptr_cadena_2;
		
        puntero++;
        ptr_cadena_2++;
    }

    *puntero = '\0';

    return ptr_cadena_1;
}

//Ejercicio 13
char * encadenar_cadena(char *ptr_cadena_1, char *ptr_cadena_2) {
    char *puntero = ptr_cadena_1;

    while (*puntero != '\0')
        puntero++;

    *puntero = ' ';
    puntero++;

    while (*ptr_cadena_2 != '\0') {
        *puntero = *ptr_cadena_2;

        puntero++;
        ptr_cadena_2++;
    }

    *puntero = '\0';

    return ptr_cadena_1;
}

//Ejercicio 14
char * subcadena(char *cadena, int inicio, int longitud) {
    char *puntero;
    int tamanio = 0;

    for (puntero = cadena; *puntero != '\0'; puntero++)
        tamanio++;

    puntero = cadena;

    if ((cadena + tamanio) >= (cadena + inicio + longitud)) {
        puntero = puntero + inicio;
        *(puntero + longitud) = '\0';
    } else {
        puntero = puntero + inicio;
        *(puntero + tamanio) = '\0';
    }

    return puntero;
}

//Ejercicio 15
char * invertir_cadena(char *original) {
	char temp;
	int longitud = longitud_cadena(original);
	int mitad = longitud / 2;
	
	char *puntero = original;
	
	for(int i=0; i < mitad; i++) {
      	temp = *(puntero+i);
      	*(puntero+i) = *(puntero+longitud-1-i);
      	*(puntero+longitud-1-i) = temp;
    }
    return puntero;
}
 
