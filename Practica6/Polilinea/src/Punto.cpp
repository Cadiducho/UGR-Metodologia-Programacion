#include <iostream>

#include "Punto.h"

using namespace std;

Punto::Punto() {
	this->x = 0;
	this->y = 0;
}

Punto::Punto(int x, int y) {
	this->x = x;
	this->y = y;
}

Punto::Punto(const Punto& otro) {
	this->Copia(otro);
}

Punto& Punto::operator=(const Punto &otro) {
	if (this != &otro) {
		this->Copia(otro);
	}
	return (*this);
}

void Punto::Copia(const Punto& otro) {
	this->x = otro.x;
	this->y = otro.y;
}

Punto::~Punto() {}

void Punto::print() {
	cout << "Punto{" << this->x << ", " << this->y << "}" << endl;
}

int Punto::getX() {
	return this->x;
}

int Punto::getY() {
	return this->y;
}
