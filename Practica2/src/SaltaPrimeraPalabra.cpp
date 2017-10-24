/*
	Leer una cadena e imprimirla saltándose la primera palabra
	Buscará el primer espacio como en el ejercicio 7, e imprimirá la cadena a partir de ahí
*/
#include <iostream>

using namespace std;

int main() {
	const int TOPE = 100;
	char cad[TOPE];
	
	cout << "Introduzca cadena: " << endl;
	cin.getline(cad, TOPE);
	
	char * p = cad;
	while ((*p != ' ') && (*p != '\0')) p++; //Avanza el puntero hasta que haya un espacio en blanco o un fin de cadena
	
	if (*p != '\0')
		cout << p;
	else
		cout << "No hay espacios";
	
	cout << endl;
	
	return (0);
}
