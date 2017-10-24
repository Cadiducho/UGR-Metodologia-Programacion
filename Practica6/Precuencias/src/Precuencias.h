#ifndef PRECUENCIAS_H
#define PRECUENCIAS_H

#include "Pareja.h" 

class Precuencias {
	private:
		Pareja * parejas; // array de objetos de la clase Pareja
		int npares; // numero de objetos almacenados en el array
		
		void LiberaMemoria();
		void PideMemoria(const int &longitud);
		void Copia(const Precuencias& otra);
		void Redimensiona();
	public:
		Precuencias();
		Precuencias(const Precuencias &otra);
		~Precuencias();
		Precuencias& operator=(const Precuencias &otra);
		
		void agregarValor(int valor);
		void print();
};

#endif
