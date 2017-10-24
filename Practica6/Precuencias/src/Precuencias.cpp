#include "Precuencias.h"
#include <iostream>

using namespace std;

Precuencias::Precuencias() {
	parejas = 0;
	npares = 0;
}

Precuencias::Precuencias(const Precuencias& otra) {
	this->PideMemoria(otra.npares);
	this->Copia(otra);
}

Precuencias&Precuencias::operator=(const Precuencias &otra) {
	if (this != &otra) {
        this->LiberaMemoria();
        this->Copia(otra);
    }

    return (*this);
}

/**
 * Agrega valor nuevo si no existe o incrementa si ya existe
 */
void Precuencias::agregarValor(int valor) {
	cout << "Comprobando para el valor" << valor << endl;
	int existe = -1;
	for (int i = 0; i < npares && existe < 0; i++) {
		if (valor == parejas[i].getDato()) {
			existe = i;
		}
	}
	if (existe >= 0) {
		parejas[existe].setNumVeces(parejas[existe].getNumVeces() + 1);
		cerr << "Incrementado a " << valor << endl;
	} else {
		cerr << "agregando nuevo a " << valor << endl;
		Redimensiona();
		parejas[this->npares - 1] = Pareja(valor, 1);
	}
}

/**
 * Aumenta en uno la memoria y retorna el nuevo puntero a memoria dinámica
 */
void Precuencias::Redimensiona() {
	int newSize = this->npares + 1;
	Pareja * nueva = new Pareja[newSize]; 

	// Copiamos los valores del vector antiguo al nuevo
	for (int i = 0; i < this->npares; i++) {
		nueva[i] = this->parejas[i];
	}
	
	// Liberamos el vector antiguo
	this->LiberaMemoria();

	// Devolvemos el resultado
	this->parejas = nueva;
	this->npares = newSize;
}

Precuencias::~Precuencias() {
	this->LiberaMemoria();
}

void Precuencias::Copia(const Precuencias& otra) {
	this->npares = otra.npares;
	
	for (int i = 0; i < this->npares; i++) {
		this->parejas[i] = otra.parejas[i];
	}
}

void Precuencias::PideMemoria(const int &longitud) {
	this->npares = longitud;
	this->parejas = new Pareja[longitud];
}

void Precuencias::LiberaMemoria() {
	delete [] this->parejas;
	this->npares = 0;
}

void Precuencias::print() {
	cout << "Precuencia{";
	for (int i = 0; i < this->npares; i++) {
		if (i != 0) cout << ",";
		cout << "Pareja{" << (this->parejas + i)->getDato() << " se repite " << (this->parejas + i)->getNumVeces() << "}";
	}
	cout << "}" << endl;
}

