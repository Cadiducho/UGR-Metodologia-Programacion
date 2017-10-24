/*
	Leer una cadena e imprimirla salt�ndose la primera palabra
	Buscar� el primer espacio como en el ejercicio 7, e imprimir� la cadena a partir de ah�
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
