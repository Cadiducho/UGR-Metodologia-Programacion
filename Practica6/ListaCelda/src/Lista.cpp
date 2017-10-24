#include <iostream>

#include "Lista.h"
#include "Celda.h"

using namespace std;

Lista::Lista(){
}

Lista::Lista(Celda& celda) {
	setPrimerContenido(&celda);
	getPrimerContenido()->setSiguiente(NULL);
}

Lista::Lista(const Lista& otra){
	this->Copia(otra);
}

void Lista::Copia(const Lista& otra) {
	Celda* sig = otra.getPrimerContenido();
	Celda* cp = new Celda(*sig);

	contenido = cp;
	while(sig->getSiguiente() != NULL){
		sig = sig->getSiguiente();
		cp->setSiguiente(new Celda(*sig));
		cp = cp->getSiguiente();
	}
}

void Lista::addCelda(Celda * celda) {
	Celda * last = getPrimerContenido();
	while (last->getSiguiente() != NULL) {
		last = last->getSiguiente();
	}
	last->setSiguiente(celda);
}

Lista::~Lista(){
	Celda* sig = contenido;
	Celda *aux;
	while(sig->getSiguiente() != NULL){
		aux = sig->getSiguiente();
		delete sig;
		sig = aux;
	}
}

Celda* Lista::getPrimerContenido() const {
	return contenido;
}

void Lista::setPrimerContenido(Celda* celda) {
	contenido = celda;
}

Lista Lista::operator+(const Lista &otra){
	Lista sumadas(*this);
	Celda *sig = sumadas.getPrimerContenido();
	while(sig->getSiguiente() != NULL){
		sig = sig->getSiguiente();
	}
	sig->setSiguiente(otra.getPrimerContenido());
	return sumadas;
}

Lista& Lista::operator=(const Lista &otra){
	if (this != &otra){
		this->Copia(otra);
	}
	return *this;
}

void Lista::operator[](const int n){
	int iteraciones = 1;
	Celda * next = contenido;
	Celda *auxiliar = next;
	if (n != 0) {
		while (iteraciones < n && next->getSiguiente()->getSiguiente() != NULL) {
			next = next->getSiguiente();
			iteraciones++;
		}
		auxiliar = next->getSiguiente();
		if (next->getSiguiente()->getSiguiente() != NULL) {
			next->setSiguiente(next->getSiguiente()->getSiguiente());
		} else {
			next->setSiguiente(NULL);
		}
	} else {
		setPrimerContenido(next->getSiguiente() == NULL ? NULL : next->getSiguiente());
	}
	delete auxiliar;
}

void Lista::print() {
	Celda *sig = contenido;
	sig->print();
	while (sig->getSiguiente() != NULL) {
		sig = sig->getSiguiente();
		sig->print();
	}
}