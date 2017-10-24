#include <iostream>
#include "circulo.h"
#include "punto.h"

using namespace std;

void Circulo::mostrar() {
    cout << radio << " - (" << centro.getX() << ", " << centro.getY() << ")" << endl;
}

void Circulo::leerDatos() const {

    cout << "Introduzca radio: ";
    cin >> radio;
    
    // Se pide al usuario que introduzca las coordenadas del centro
    centro.leerDatos();	
}

void Circulo::calcularArea() const {
    // Se calcula el area
    double area=2*M_PI*pow(radio,2);
    
    // Se devuelve el resultado
    return area;
}