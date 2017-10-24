/*
	Localiza el primer espacio en blanco de la cadena, si existe
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
	const int TOPE = 100;
	char cad[TOPE];
	
	cout << "Introduzca cadena: " << endl;
	cin.getline(cad, TOPE);
	
	char * p = cad;
	while ((*p != ' ') && (*p != '\0')) p++; //Avanza el puntero hasta que haya un espacio en blanco o un fin de cadena
	
	cout << "posición del primer espacio en blanco:";
	if (*p != '\0')
		cout << p-cad;
	else
		cout << "No hay espacios";
	
	cout << endl;
	
	return (0);
}
