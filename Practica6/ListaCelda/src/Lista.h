#ifndef LISTA_H
#define LISTA_H

#include "Celda.h"

class Lista {
	private: 
		Celda * contenido;
		void Copia(const Lista& otra);
	public:
		Lista();
		Lista(Celda& celda);
		Lista(const Lista& otra);
		~Lista();
		
		Lista& operator=(const Lista &otra);
		Lista operator+(const Lista &otra);
		void operator[](const int n);
		
		Celda* getPrimerContenido() const;
		void setPrimerContenido(Celda * celda);
		
		Celda& getCelda(int slot);
		void addCelda(Celda * celda);
		void print();
};

#endif