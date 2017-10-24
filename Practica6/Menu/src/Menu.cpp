#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu() {
	this->PideMemoria(0);
}

Menu::Menu(const Menu& otro) {
	this->PideMemoria(otro.nopc);
	this->Copia(otro);
}

Menu::~Menu() {
	this->LiberaMemoria();
}

void Menu::LiberaMemoria() {
	delete[] this->opc;
	this->nopc = 0;
}

/*
 * Se copian los datos de otro menu en la primera instancia
 */
void Menu::Copia(const Menu &otra) {
	this->nopc = otra.nopc;
	
	for (int i = 0; i < this->nopc; i++) {
		this->opc[i] = otra.opc[i];
	}
}

/*
 * Si this no es el menu a copiar, se libera la memoria original y se copia el otro
 */
Menu& Menu::operator=(const Menu &otro) {
	if (this != &otro) {
        this->LiberaMemoria();
        this->Copia(otro);
    }

    return (*this);
}

void Menu::PideMemoria(const int &longitud) {
	this->nopc = longitud;
	this->opc = new char*[longitud];
}

/*
 * Aumenta en uno la memoria y retorna el nuevo puntero a memoria dinámica
 */
void Menu::IncrementaMemoria() {
	int newSize = this->nopc + 1;
	char ** nueva = new char*[newSize]; 

	// Copiamos los valores del vector antiguo al nuevo
	for (int i = 0; i < newSize; i++) {
		nueva[i] = this->opc[i];
	}
	
	// Liberamos el vector antiguo
	this->LiberaMemoria();

	// Devolvemos el resultado
	this->opc = nueva;
	this->nopc = newSize;
}

int Menu::getNumeroOpciones() const {
	return this->nopc;
}

void Menu::setTitulo(char * titulo) {
	this->titulo = titulo;
}

/*
 * Para agregar la opción se incrementa la memoria y se agrega char* en el slot válido
 */
void Menu::agregarOpcion(char * opcion) {
	IncrementaMemoria();
	this->opc[this->nopc - 1] = opcion;
}

void Menu::print() {
	cout << this->titulo << "(" << this->getNumeroOpciones() << ")" << endl;
	for (int i = 0; i < this->nopc; i++) {
		cout << "* " << this->opc[i] << endl;
	}
	cout << "===================" << endl;
}
