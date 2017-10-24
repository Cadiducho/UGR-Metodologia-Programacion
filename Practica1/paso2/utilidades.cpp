#include "utilidades.h"
#include "punto.h"
#include <iostream>

using namespace std;

double calcularDistancia(Punto p1, Punto p2) {
    double distancia=sqrt(pow(p1.getX()-p2.getX(),2)+
                          pow(p1.getY()-p2.getY(),2));
}

/**
 * @brief Calcula el punto que está entre dos puntos dados con distancia 
 * mínima a ambos. Se trata de una funcion externa a la clase Punto. A
 * implementar
 * @param p1 primer punto
 * @param p2 segundo punto
 * @return un punto entre el punto @a p1 y el punto @a p2 con distancia
 * mínima a ambos
 */
Punto calcularPuntoMedio(Punto p1, Punto p2) {
    double xm, ym;
    
    // Se calculan las coordenadas del punto medio
    xm=(p1.getX()+p2.getY())/2;
    ym=(p1.getY()+p2.getY())/2;
    
    // Se crea el nuevo punto con estas coordenadas
    Punto pm(xm, ym);
    
    // Se devuelve el resultado
    return pm;
}