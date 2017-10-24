#ifndef PUNTO_H
#define PUNTO_H

class Punto {
	private:
		int x;
		int y;
		
		void Copia(const Punto& otro);
	public:
		Punto();
		Punto(int x, int y);
		Punto(const Punto& otro);		
		Punto& operator=(const Punto &otro);
		~Punto();
		
		void print();
		int getX();
		int getY();
};

#endif
