#include <iostream>

#include "Celda.h"

using namespace std;

Celda::Celda(){
	this->info = 0;
	this->siguiente = NULL;
}

Celda::Celda(const double& dato) {
	this->info = dato;
	this->siguiente = NULL;
}

Celda::Celda(const Celda& otra) {
	this->Copia(otra);
}


Celda& Celda::operator=(const Celda& otra) {
	if (this != &otra) {
        this->Copia(otra);
    }
    return (*this);
}

void Celda::Copia(const Celda& otra) {
	this->info = otra.info;
	this->siguiente = otra.siguiente;
}

Celda::~Celda() {
}

double Celda::getInfo() const {
	return this->info;
}

Celda * Celda::getSiguiente() const {
	this->siguiente;
}

void Celda::setSiguiente(Celda * celda) {
	this->siguiente = celda;
}

void Celda::print() {
	cout << "Celda(" << this->info << ")" << endl;;
}


