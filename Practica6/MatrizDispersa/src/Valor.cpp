#include "Valor.h"
#include <iostream>

using namespace std;

Valor::Valor() {}

Valor::Valor(int fila, int columna, double valor) {
	if (fila >= 0 && columna >= 0){
    	this->fila = fila;
    	this->columna = columna;
    	this->valor = valor;
    }
}

int Valor::getFila() const {
	return this->fila;
}

int Valor::getColumna() const {
	return this->columna;
}

double Valor::getValor() const {
	return this->valor;
}

void Valor::print() {
	cout << "Valor{" << fila << ", " << columna << ", " << valor << "}" << endl;
}
