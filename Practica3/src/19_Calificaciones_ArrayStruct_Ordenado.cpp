#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#include "19_Calificaciones_ArrayStruct_Ordenado.h"

RegAlumno alumnos[TAMANIO], *puntero_alumno = alumnos;

double calificacion_media[TAMANIO];
double pesos[NUM_NOTAS];

int main(int argc, char *argv[]) {
	int min_media = 0;
	int max_media = 10;
	if (argc == 3) {
		min_media = atoi(argv[1]);
		max_media = atoi(argv[2]);
		cout << "Se mostrarán alumnos cuyas medias estén entre " << min_media << " y " << max_media << endl;
	}
	
	//Pido pesos
	LeePesos(pesos, NUM_NOTAS);
	
	//Compruebo pesos
	if (CorrectosPesos(pesos, NUM_NOTAS)) {
		cout << "Has introducido mal algun porcentaje!";
		return 1;
	}
	
	//Muestro pesos
	MuestraPesos(pesos, NUM_NOTAS);
	
	//Introducir datos de los alumnos
	int alumnos = LeerAlumnos(puntero_alumno, NUM_NOTAS);
	if (alumnos == 0) {
		cout << "No se han insertado datos de alumnos" << endl;
		return 2;
	}
	
	//Calcular medias
	CalculaCalificacionesMedias(calificacion_media, puntero_alumno, alumnos, pesos, NUM_NOTAS);
	
	//Ordenar los vectores
	OrdenaVectorAlumnos(puntero_alumno, calificacion_media, alumnos);
	
	//Mostrar
	MuestraVectorAlumnos(puntero_alumno, calificacion_media, alumnos, min_media, max_media);
	
	return 0;
}

void LeePesos(double ponderaciones[], int num_pesos) {
	cout << "Indica los pesos (porcentajes) de las " << num_pesos << " partes de la calificación total" << endl;
	for (int i = 0; i < num_pesos; i++) {
		cout << "Porcentaje " << (i + 1) << ": ";
		cin >> ponderaciones[i];
	}
}

bool CorrectosPesos(double ponderaciones[], int num_pesos) {
	double pesoTotal = 0;
	for (int i = 0; i < num_pesos; i++) {
		pesoTotal += ponderaciones[i];
	}
	return (pesoTotal != 100);
}

void MuestraPesos(double ponderaciones[], int num_pesos) {
	cout << "-----Pesos introducidos------" << endl;
	for (int i = 0; i < num_pesos; i++) {
		cout << "Peso " << (i + 1) << ": " << ponderaciones[i] << endl;
	}
	cout << "-----------------------------" << endl;
}

int LeerAlumnos(RegAlumno * datos, int num_casillas) {
	const char keyStop[] = "*";
	int insertados = 0;
	
	fflush(stdin);
	char apellidos_insert[TAM_NOMBRE];
	cout << "Inserte apellidos y nombre: ";
	cin.getline(apellidos_insert, TAM_NOMBRE);
	
	while (strcmp (keyStop, apellidos_insert) != 0 && insertados < 100) {
		strcpy((datos+insertados)->apellido_nombre, apellidos_insert);
		cout << "Introduzca notas validas (entre 0 y 10): " << endl;
		for (int i = 0; i < num_casillas; i++) {
			int nota; 
			do {
				cout << "Nota " << (i + 1) << ": ";
				cin >> nota;
			} while (nota < 0 || nota > 10);
			(datos+insertados)->notas[i] = nota;
		}
		cout << endl;
		insertados++;
		fflush(stdin);
		
		cout << "Inserte apellidos y nombre: ";
		cin.getline(apellidos_insert, TAM_NOMBRE);
	}
	
	return insertados;
}

void CalculaCalificacionesMedias(double medias[], RegAlumno *datos, int num_alumnos, double ponderaciones[], int num_notas) {
	for (int alumId = 0; alumId < num_alumnos; alumId++) {
		double media = 0.0;
		for (int notaId = 0; notaId < num_notas; notaId++) {
			media += ((datos+alumId)->notas[notaId] * ponderaciones[notaId] / 100);
		}
		medias[alumId] = media;
	}
}

void MuestraVectorAlumnos(RegAlumno *datos, double medias[], int num_alumnos, int min, int max) {
	cout << endl << "Alumnos detallados: " << endl << endl;
	for (int alumId = 0; alumId < num_alumnos; alumId++) {
		if (medias[alumId] >= min && medias[alumId] <= max) {
			cout << "Alumno: " << (datos+alumId)->apellido_nombre << endl;
			cout << "Nota Media: " << medias[alumId] << endl;
			cout << " ------------ " << endl;
		}
	}
}

void OrdenaVectorAlumnos(RegAlumno *datos, double medias[], int num_alumnos) {
	int intercambio;
	RegAlumno interAlumno;
	for (int i = 0 ; i < (num_alumnos - 1); i++) {
    	for (int j = 0 ; j < num_alumnos - i - 1; j++) {
      		if (medias[j] < medias[j+1]) {
      			//Vector de medias
        		intercambio = medias[j];
        		medias[j] = medias[j+1];
        		medias[j+1] = intercambio;
        		
        		//Puntero de alumnos;
        		interAlumno = *(datos+j);
        		*(datos+j) = *(datos+j+1);
        		*(datos+j+1) = interAlumno;
      		}
    	}
  	}
}
