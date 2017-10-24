#ifndef CELDA_H
#define CELDA_H

class Celda {
	private:
		double info;
		Celda * siguiente;
		void Copia(const Celda& otra);
	public:
		Celda();
		Celda(const double& dato);
		Celda(const Celda& otra);
		Celda& operator=(const Celda &otra);
		~Celda();
		
		Celda * getSiguiente() const;
		void setSiguiente(Celda * celda);
		double getInfo() const;
		void print();
};

#endif

