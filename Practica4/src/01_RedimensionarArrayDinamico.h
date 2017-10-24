#ifndef REDIMENSIONAR_H
#define REDIMENSIONAR_H

enum TipoRedimension {
	EnBloques,
	Duplicando,
	DeUnoEnUno
};
int * Redimensiona (int * p, TipoRedimension tipo, int & cap);

#endif
