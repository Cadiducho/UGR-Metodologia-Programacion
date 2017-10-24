#ifndef PUNTO_H
#define PUNTO_H

class Punto {
private:

    double x;
	
    double y;

public:

    Punto();
	
    Punto(double vx, double vy);
	
    double getX();
	
    double getY();
	
    void setX(double vx);
	
    void setY(double vy);
    
    void mostrar();

    void leerDatos();
};
#endif
