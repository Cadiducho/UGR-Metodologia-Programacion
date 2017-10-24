#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo {
private:

    Punto centro;
    
    double radio; 
public:

    Circulo() {
        radio=0;
    } 
    
    Circulo(Punto vcentro, double vradio) {
        centro=vcentro;
        radio=vradio;
    } 

    Punto getCentro() const {
        return centro;
    }
	
    double getRadio() const {
        return radio;
    }
    
    void setCentro(Punto puntoCentro){
        centro=puntoCentro;
    }
    
    void setRadio(double valorRadio){
        radio=valorRadio;
    }
	
    void mostrar() const; 
    
    void leerDatos();

    double calcularArea() const;
};

#endif