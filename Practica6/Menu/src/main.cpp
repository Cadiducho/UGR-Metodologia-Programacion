#include <iostream>

#include "Menu.h"

using namespace std;

int main() {
	
	cout << "Se crea menu y se asigna el titulo 'hola'" << endl;
	Menu * menu = new Menu();
	
	menu->setTitulo("hola");
	
	cout << "Se agregan 3 opciones por defecto " << endl;
	menu->agregarOpcion("Opcion 1");
	menu->agregarOpcion("Opcion 2");
	menu->agregarOpcion("Opcion 3");
	
	cout << "Menu creado: " << endl;
	menu->print();
	
	cout << "Se copia y se modifica el titulo del copiado " << endl;
	Menu * copia = menu;
	
	copia->setTitulo("Hola copiado");
	copia->print();
	
	delete menu;
	
	return 0;
}
