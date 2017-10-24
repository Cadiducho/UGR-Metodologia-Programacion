#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#include "02_Calificaciones_ArrayDinamicoStruct_ordenado.h"

int main(int argc, char *argv[]) {
	int min_media = 0;
	int max_media = 10;
	if (argc == 3) {
		min_media = atoi(argv[1]);
		max_media = atoi(argv[2]);
		cout << "Se mostrar�n alumnos cuyas medias est�n entre " << min_media << " y " << max_media << endl;
	}

	int numNotas;
	cout << "Introduzca el numero de notas: "; cin >> numNotas;

	RegAlumno * p_alumnos = new RegAlumno[1];
	double * calificacion_media = new double[numNotas];
	double * pesos = new double[numNotas];

	//Pido pesos
	LeePesos(pesos, numNotas);

	//Compruebo pesos
	if (CorrectosPesos(pesos, numNotas)) {
		cout << "Has introducido mal algun porcentaje!";
		return 1;
	}

	//Muestro pesos
	MuestraPesos(pesos, numNotas);

	//Introducir datos de los alumnos
	int alumnos = LeerAlumnos(p_alumnos, numNotas);
	if (alumnos == 0) {
		cout << "No se han insertado datos de alumnos" << endl;
		return 2;
	}

	//Calcular medias
	CalculaCalificacionesMedias(calificacion_media, p_alumnos, alumnos, pesos, numNotas);

	//Ordenar los vectores
	OrdenaVectorAlumnos(p_alumnos, calificacion_media, alumnos);

	//Mostrar
	MuestraVectorAlumnos(p_alumnos, calificacion_media, alumnos, min_media, max_media);

	delete[] calificacion_media;
	delete[] pesos;

	delete[] p_alumnos;

	return 0;
}

int * Redimensiona (RegAlumno * p, int & cap) {
	RegAlumno * nuevo;
	nuevo = new RegAlumno[cap + 1];
	memcpy(nuevo, p, cap * sizeof(RegAlumno));
	cap++;
	p = nuevo;
	delete [] nuevo;
}

void LeePesos(double * ponderaciones, int num_pesos) {
	cout << "Indica los pesos (porcentajes) de las " << num_pesos << " partes de la calificaci�n total" << endl;
	for (int i = 0; i < num_pesos; i++) {
		cout << "Porcentaje " << (i + 1) << ": ";
		cin >> *(ponderaciones + i);
	}
}

bool CorrectosPesos(double * ponderaciones, int num_pesos) {
	double pesoTotal = 0;
	for (int i = 0; i < num_pesos; i++) {
		pesoTotal += *(ponderaciones + i);
	}
	return (pesoTotal != 100);
}

void MuestraPesos(double * ponderaciones, int num_pesos) {
	cout << "-----Pesos introducidos------" << endl;
	for (int i = 0; i < num_pesos; i++) {
		cout << "Peso " << (i + 1) << ": " << *(ponderaciones + i) << endl;
	}
	cout << "-----------------------------" << endl;
}

int LeerAlumnos(RegAlumno * datos, int num_casillas) {
	const char keyStop[] = "*";
	int insertados = 0;

	cin.ignore();
	char dni_insert[9];
	cout << "Inserte DNI: ";
	cin.getline(dni_insert, sizeof(dni_insert));

	while (strcmp (keyStop, dni_insert) != 0) {
		//Iniciamos todos los campos del alumno
		(datos+insertados)->DNI = new char[TAM_NOMBRE];
		(datos+insertados)->apellido_nombre = new char[TAM_NOMBRE];
		(datos+insertados)->notas = new double[num_casillas];

		//Copiamo y empezamos a dar valores
		strcpy((datos+insertados)->DNI, dni_insert);
		cout << "Inserte apellidos y nombre: ";
		cin.getline((datos+insertados)->apellido_nombre, TAM_NOMBRE);
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
		Redimensiona(datos, insertados);
		cin.ignore();

		cout << "Inserte DNI: ";
		cin.getline(dni_insert, sizeof(dni_insert));
	}

	return insertados;
}

void CalculaCalificacionesMedias(double * medias, RegAlumno *datos, int num_alumnos, double * ponderaciones, int num_notas) {
	for (int alumId = 0; alumId < num_alumnos; alumId++) {
		double media = 0.0;
		for (int notaId = 0; notaId < num_notas; notaId++) {
			media += ((datos+alumId)->notas[notaId] * *(ponderaciones + notaId) / 100);
		}
		*(medias + alumId)= media;
	}
}

void MuestraVectorAlumnos(RegAlumno *datos, double * medias, int num_alumnos, int min, int max) {
	cout << endl << "Alumnos detallados: " << endl << endl;
	for (int alumId = 0; alumId < num_alumnos; alumId++) {
		if (medias[alumId] >= min && medias[alumId] <= max) {
			cout << "DNI: " << (datos+alumId)->DNI << endl;
			cout << "Nombre: " << (datos+alumId)->apellido_nombre << endl;
			cout << "Nota Media: " << medias[alumId] << endl;
			cout << " ------------ " << endl;
		}
	}
}

void OrdenaVectorAlumnos(RegAlumno *datos, double *medias, int num_alumnos) {
		int intercambio;
		RegAlumno interAlumno;
		for (int i = 0 ; i < (num_alumnos - 1); i++) {
				for (int j = 0 ; j < (num_alumnos - i - 1); j++) {
			      if (*(medias+j) < *(medias+j+1)) {
			      		//Vector de medias
			        	intercambio = *(medias+j);
			        	*(medias+j) = *(medias+j+1);
			        	*(medias+j+1) = intercambio;

			        	//Puntero de alumnos;
			        	interAlumno = *(datos+j);
			        	*(datos+j) = *(datos+j+1);
			        	*(datos+j+1) = interAlumno;
	      		}
		  	}
	  }
}
