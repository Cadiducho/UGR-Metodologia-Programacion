#include <iostream>

#include "Polilinea.h"
#include "Punto.h"

using namespace std;

Polilinea::Polilinea() {
	this->PideMemoria(0);
}

Polilinea::Polilinea(const Polilinea& otra) {
	this->PideMemoria(otra.num);
	this->Copia(otra);
}

Polilinea&Polilinea::operator=(const Polilinea &otra) {
	if (this != &otra) {
        this->LiberaMemoria();
        this->Copia(otra);
    }

    return (*this);
}

void Polilinea::Copia(const Polilinea& otra) {
	this->num = otra.num;
	
	for (int i = 0; i < this->num; i++)
        this->puntos[i] = otra.puntos[i];
}

Polilinea::~Polilinea() {
	this->LiberaMemoria();
}

void Polilinea::PideMemoria(const int &longitud) {
	this->num = longitud;
	
	this->puntos = new Punto[longitud];
}

void Polilinea::LiberaMemoria() {
	delete [] puntos;
	this->num = 0;
}

/*
 * Aumenta en uno la memoria y retorna el nuevo puntero a memoria dinámica
 */
void Polilinea::Redimensiona(int newSize) {
	Punto * nuevo = new Punto[newSize]; 

	// Copiamos los valores del vector antiguo al nuevo
	for (int i = 0; i < this->num; i++) {
		nuevo[i] = this->puntos[i];
	}
	
	// Liberamos el vector antiguo
	this->LiberaMemoria();

	// Devolvemos el resultado
	this->puntos = nuevo;
	this->num = newSize;
}

void Polilinea::print() {
	cout << "Polilinea{";
	for (int i = 0; i < this->num; i++) {
		if (i != 0) cout << ", ";
		cout << "(" << this->puntos[i].getX() << ", " << this->puntos[i].getY() << ")";
	}
	cout << "}" << endl;
}

void Polilinea::addPoint(const int& x, const int& y) {
	this->addPoint(Punto(x, y));
}

void Polilinea::addPoint(const Punto& punto) {
	this->Redimensiona(this->num + 1);
	this->puntos[this->num - 1] = punto; //el tamaño redimensionado menos uno es el ultimo slot
}

