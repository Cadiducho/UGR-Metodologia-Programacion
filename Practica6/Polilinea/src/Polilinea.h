#ifndef POLILINEA_H
#define POLILINEA_H

#include "Punto.h"

class Polilinea {
	private:
		Punto *puntos;
		int num;
		
		void PideMemoria(const int &longitud);
		void LiberaMemoria();
		void Copia(const Polilinea& otra);
		void Redimensiona(int newSize);
	public:
		Polilinea();
		Polilinea(const Polilinea& otra);
		Polilinea& operator=(const Polilinea &otra);
		~Polilinea();
		
		void print();
		void addPoint(const Punto& punto);
		void addPoint(const int& x, const int& y);
};

#endif
