#include "MatrizDispersa.h"
#include <iostream>

using namespace std;

MatrizDispersa::MatrizDispersa() {
	this->nfilas = 0;
	this->ncolumnas = 0;
	this->valores = 0;
	this->numeroValores = 0;
}

int maximo(int * vec, int num){
	int max = vec[0];
	for(int i = 1 ; i < num; i++)
		if (vec[i] > max)
			max = vec[i]; 
	return max;
}

MatrizDispersa::MatrizDispersa(int* filas, int* columnas, double* numeros, int elementos) {
	this->numeroValores = elementos;
	this->nfilas = maximo(filas, numeroValores);
	this->ncolumnas = maximo(columnas, numeroValores);
	valores = new Valor[this->numeroValores];

	for (int i = 0; i < this->numeroValores; i++)
		valores[i] = Valor(filas[i], columnas[i], numeros[i]);
}

MatrizDispersa::~MatrizDispersa() {
	this->LiberaMemoria();
}

void MatrizDispersa::LiberaMemoria() {
	delete [] valores;
}

void MatrizDispersa::Copia(const MatrizDispersa &otra) {
	this->nfilas = otra.nfilas;
	this->ncolumnas = otra.ncolumnas;
	this->valores = otra.valores;
	this->numeroValores = otra.numeroValores;
}

MatrizDispersa& MatrizDispersa::operator=(const MatrizDispersa &otra) {
	if (this != &otra) {
        this->LiberaMemoria();
        this->Copia(otra);
    }

    return (*this);
}

int MatrizDispersa::getNumFilas() const {
	return this->nfilas;
}

int MatrizDispersa::getNumColumnas() const {
	return this->ncolumnas;
}

Valor * MatrizDispersa::getValores() const {
	return this->valores;
}

int MatrizDispersa::getNumValores() const {
	return this->numeroValores;
}
		
void MatrizDispersa::muestraValores() {
	for (int i = 0; i < numeroValores; i++)
		valores[i].print(); 
}
