#include <iostream>
#include "BigInt.h"

using namespace std;

int main() {
	
	cout << "Big int vacio: " << endl;
	BigInt * i = new BigInt();
	i->print();
	
	cout << "Big int con valor 911" << endl;
	BigInt * o = new BigInt(911);
	o->print();
	
	cout << "Asignamos al primer bigint el valor del segundo" << endl;
	i = o;
	i->print();

	cout << "Sumamos los dos" << endl;
	BigInt suma = *o + *i;
	suma.print();

    delete i;
    
	return 0;
}
