#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int NUM_NOTAS = 4;
const int TAM_NOMBRE = 100;
const int TAMANIO = 100;

struct RegAlumno {
	double notas[NUM_NOTAS];
	char apellido_nombre[TAM_NOMBRE];
} alumnos[TAMANIO], *puntero_alumno = alumnos;
int insertados = 0;

double calificacion_media[TAMANIO];
double pesos[NUM_NOTAS];

int main() {
	//Pido pesos
	cout << "Indica los pesos (porcentajes) de las " << NUM_NOTAS << " partes de la calificación total" << endl;
	for (int i = 0; i < NUM_NOTAS; i++) {
		cout << "Porcentaje " << (i + 1) << ": ";
		cin >> pesos[i];
	}
	
	//Compruebo pesos
	double pesoTotal = 0;
	for (int i = 0; i < NUM_NOTAS; i++) {
		pesoTotal += pesos[i];
	}
	if (pesoTotal != 100) {
		cout << "Has introducido mal algun porcentaje! El peso total introducido es " << pesoTotal << endl;
		return 1;
	}
	
	//Introducir datos de los alumnos
	const char keyStop[] = "*";
	
	fflush(stdin);
	char apellidos_insert[TAM_NOMBRE];
	cout << "Inserte apellidos y nombre: ";
	cin.getline(apellidos_insert, TAM_NOMBRE);
	
	while (strcmp (keyStop, apellidos_insert) != 0 && insertados < 100) {
		strcpy((puntero_alumno+insertados)->apellido_nombre, apellidos_insert);
		cout << "Introduzca notas validas (entre 0 y 10): " << endl;
		for (int i = 0; i < NUM_NOTAS; i++) {
			int nota; 
			do {
				cout << "Nota " << (i + 1) << ": ";
				cin >> nota;
			} while (nota < 0 || nota > 10);
			(puntero_alumno+insertados)->notas[i] = nota;
		}
		cout << endl;
		insertados++;
		fflush(stdin);
		
		cout << "Inserte apellidos y nombre: ";
		cin.getline(apellidos_insert, TAM_NOMBRE);
	}
	
	if (insertados == 0) {
		cout << "No se han insertado datos de alumnos" << endl;
		return 2;
	}
	
	//Calcular medias
	for (int alumId = 0; alumId < insertados; alumId++) {
		double media = 0.0;
		for (int notaId = 0; notaId < NUM_NOTAS; notaId++) {
			media += ((puntero_alumno+alumId)->notas[notaId] * pesos[notaId] / 100);
		}
		calificacion_media[alumId] = media;
	}
	
	//Mostrar
	cout << endl << "Alumnos detallados: " << endl << endl;
	for (int alumId = 0; alumId < insertados; alumId++) {
		cout << "Alumno: " << (puntero_alumno+alumId)->apellido_nombre << endl;
		cout << "Nota Media: " << calificacion_media[alumId] << endl;
		cout << " ------------ " << endl;
	}
	
	return 0;
}


