#ifndef PAREJA_H
#define PAREJA_H

class Pareja {
	private:
		int dato; // valor
		int nveces; // numero de repeticiones
		
		void Copia(const Pareja& otra);
	public:
		Pareja();
		Pareja(int dato, int veces);
		Pareja(const Pareja& otra);
		Pareja& operator=(const Pareja &otra);
		~Pareja();
		
		int getDato();
		void setDato(int dato);
		int getNumVeces();
		void setNumVeces(int veces);
		void print();
};

#endif
