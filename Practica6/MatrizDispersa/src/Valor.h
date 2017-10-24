#ifndef VALOR_H
#define VALOR_H

#include <iostream>
using namespace std;

class Valor {
	private:
	    int fila;
	    int columna;
	    double valor;
	public:
		Valor();
		Valor(int fila, int columna, double valor);
		int getFila() const;
		int getColumna() const;
		double getValor() const;
		
		void print();
};

#endif
