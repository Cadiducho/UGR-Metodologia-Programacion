#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

#include "Barquitos.h"

using namespace std;

Barquitos::Barquitos(int filas, int columnas) {
	this->PideMemoria(filas, columnas);
	
	//Iniciar todo a agua
	for (int i = 0; i < filas; ++i) {	
    	for (int j = 0; j < columnas; ++j) {
    		matrix[i][j] = WATER;
		}
    }
}

Barquitos::Barquitos(const Barquitos &otro) {
    this->PideMemoria(otro.filas, otro.columnas);
	this->Copia(otro);
}

void Barquitos::PideMemoria(const int &filas, const int &columnas) {
	this->filas = filas;
	this->columnas = columnas;
	
	matrix = new int*[filas];
	for (int i = 0; i < filas; ++i) {
    	matrix[i] = new int[columnas];
    }
}

Barquitos::~Barquitos() {	
	this->LiberaMemoria();
}

void Barquitos::LiberaMemoria() {
    for (int i = 0; i < filas; ++i)
	    delete [] this->matrix[i];
	delete [] matrix;
}

void Barquitos::Copia(const Barquitos &otro) {
    this->filas = otro.filas;
    this->columnas = otro.columnas;

    for (int i = 0; i < this->filas; i++)
        for (int j = 0; j < this->columnas; j++)
            this->matrix[i][j] = otro.matrix[i][j];
}

Barquitos& Barquitos::operator=(const Barquitos &otro) {
	if (this != &otro) {
        this->LiberaMemoria();
        this->Copia(otro);
    }

    return (*this);
}

bool Barquitos::isWater(int x, int y) {
	return abs(matrix[x][y]) == WATER;
}

bool Barquitos::setShip(int x, int y, int boatId, Direction direction) {
	if (boatId < 0 ||  boatId > 8) { //Id invalida
		return false;
	}
	if (y > filas || x > columnas) return false; //No poner barcos fuera del tablero
	
	switch (direction) {
		case VERTICAL:
			if (y + boatId > filas) return false; //No salirse del tablero
			for (int i = x; i < (x + boatId); ++i) {
				if (!isWater(i, y)) { //Comprobar que todas las casillas que ocuparía el barco están libres
					cout << i << ", " << y << " no es agua asi que el barco " << boatId << " no se pone" << endl;
					return false;
				}
			}
			
			//Pasados los filtros, poner el barco
			for (int i = x; i < (x + boatId); ++i) {
				matrix[i][y] = boatId;				
			}				
			break;
		case HORIZONTAL:
			if (x + boatId > columnas) return false;
			for (int i = y; i < (y + boatId); ++i) {
				if (!isWater(x, i)) {
					cout << i << ", " << y << " no es agua asi que el barco " << boatId << " no se pone" << endl;
					return false;
				}
			}
			for (int i = y; i < (y + boatId); ++i) {
				matrix[x][i] = boatId;
			}			
			break;
	}	
}

bool Barquitos::shot(int x, int y) {
	if (y > filas || x > columnas) return false; //Disparar dentro del tablero
	if (isWater(x, y)) {
		cout << "(" << x << ", " << y << ") Agua!" << endl;
		matrix[x][y] = -WATER;
		return false;
	}
	
	cout << "(" << x << ", " << y << ") Tocado!" << endl;
	matrix[x][y] = (-matrix[x][y]);
	return true;
}

void Barquitos::rawPrint() {
	for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j)
        	cout << setw(4) << matrix[i][j];
      	cout << endl;
    }	
}

void Barquitos::print() {
	for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
        	cout << setw(4) << (matrix[i][j] < 0 ? to_string(matrix[i][j]) : "X");
        }
      	cout << endl;
	}
}
