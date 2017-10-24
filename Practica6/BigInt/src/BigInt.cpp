#include <iostream>
#include <string>
#include <cmath>

#include "BigInt.h"

using namespace std;

BigInt::BigInt() {
	this->PideMemoria(1);
	
	this->array[0] = 0;
}

BigInt::BigInt(long numero) {
	int cifras = log10(numero) + 1;

	this->PideMemoria(cifras);
	
	for (int i = 0; i < this->size; ++i) {
		this->array[i] = numero % 10;
		numero /= 10;
	}
}

BigInt::BigInt(const BigInt &otro) {
    this->PideMemoria(otro.size);
	this->Copia(otro);
}

void BigInt::PideMemoria(const int &longitud) {
	this->size = longitud;
	
	array = new int[longitud];
}

BigInt::~BigInt() {	
	this->LiberaMemoria();
}

void BigInt::LiberaMemoria() {
	delete [] array;
	this->size = 0;
}

void BigInt::Copia(const BigInt &otro) {
    this->size = otro.size;

    for (int i = 0; i < this->size; i++)
        this->array[i] = otro.array[i];
}

BigInt& BigInt::operator=(const BigInt &otro) {
	if (this != &otro) {
        this->LiberaMemoria();
        this->Copia(otro);
    }

    return (*this);
}

BigInt& BigInt::add(const BigInt &otro) {
	
	//Buscamos maximo de iteraciones
	int max = this->size;
	if (otro.size > max) max = otro.size;
	
	//Redimensionamos el sumando al maximo
	if (this->size < max) Redimensiona(max);
	
	int acarreo = 0;
	for (int i = 0; i < max; i++) {
		//Comprobamos si uno de los dos BigInts está fuera de memoria, en ese caso sumar 0
		int addA = (i < this->size ? this->array[i] : 0);
		int addB = (i < otro.size ? otro.array[i] : 0);
		
		//Partimos los digitos y nos llevamos algo de acarreo si supera 10
		int toAdd = addA + addB + acarreo;
		if (toAdd > 10) {
			acarreo = 1;
			toAdd %= 10;
		}
		
		//Se coloca en ese slot la suma de ambos (correcta) y el posible acarreo
		this->array[i] = toAdd;
		
		//Redimensionar una vez más si es la última iteración y hay acarreo
		if ((i + 1) == max && acarreo) {
			Redimensiona(max + 1);
			this->array[max] = acarreo;
		}
	}
	return (*this);
}

BigInt& BigInt::operator+(const BigInt &otro) {
	return (add(otro));
}

/*
 * Aumenta en uno la memoria y retorna el nuevo puntero a memoria dinámica
 */
void BigInt::Redimensiona(int newSize) {
	int * nueva = new int[newSize]; 

	// Copiamos los valores del vector antiguo al nuevo
	for (int i = 0; i < this->size; i++) {
		nueva[i] = this->array[i];
	}
	
	// Liberamos el vector antiguo
	this->LiberaMemoria();

	// Devolvemos el resultado
	this->array = nueva;
	this->size = newSize;
}

void BigInt::print() {
	for (int i = (this->size - 1); i >= 0; --i) {
		cout << this->array[i];
	}
	cout << endl << endl;
}
