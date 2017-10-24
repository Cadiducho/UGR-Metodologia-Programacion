#ifndef BIGINT_H
#define BIGINT_H

#include <string>

class BigInt {
	private:
		int *array;
		int size;
		
		void PideMemoria(const int &longitud);
		void LiberaMemoria();
		void Copia(const BigInt &otro);
		void Redimensiona(int newSize);
	public:
		BigInt();
    	BigInt(long numero);
    	BigInt(const BigInt& b);
    	void print();
    	
    	BigInt& add(const BigInt &bar);
    	BigInt& operator+(const BigInt &bar);
    	BigInt& operator=(const BigInt &bar);
		~BigInt();
};

#endif
