#include <iostream>
#include "punto.h"

using namespace std;

Punto::Punto() {
	x = 0;
	y = 0;
}

Punto::Punto(double vx, double vy) {
	x = vx;
	y = vy;
}

double Punto::getX() const {
	return x;
}

double Punto::getY() const {
	return y;
}

void Punto::setX(int vx) {
	x = vx;
}

void Punto::setY(int vy) {
	y = vy;
}

void Punto::mostrar() const {
    cout << "(" << x << ", " << y << ")" << endl;
}

void Punto::leerDatos() {
    cout << "Introduzca coordenadas del punto (x, y): ";
    cin >> x >> y;
}