#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Matriz2D-2.h"
 
using namespace std;
 
Matriz2D_2 CreaMatriz2D_2 (int fils, int cols) {

    Matriz2D_2 matriz = new  int * [fils];
    matriz[0] = new  int [fils*cols];
    
    for(int f=1; f<fils ; f++)
        matriz[f] = matriz[f-1] + cols;

    return matriz;
}

Matriz2D_2 AleatorizaMatriz2D_2 (int fils, int cols, int modulo) {
	Matriz2D_2 matrix = CreaMatriz2D_2(fils, cols);
		
	time_t t;
	srand ((int) time(&t));
	for (int f=0; f<fils; f++) {
        for (int c=0; c<cols; c++) {
 			matrix[f][c] = rand() % modulo;
		}
	}	
	return matrix;
}
 
void LiberaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) {
     delete [] matriz[0];
     delete [] matriz;
}
 
void PintaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) {
     for (int f=0; f<fils; f++) {
            for (int c=0; c<cols; c++)
                    cout << setw(4) << matriz[f][c];
            cout << endl;
        }
}

Matriz2D_2 LlenarMatriz2D_2(Matriz2D_2 matriz, int fils, int cols) {
    double value;
    cout << endl << "Rellenando matrices" << endl;

    for (int f=0; f<fils; f++) {
        for (int c=0; c<cols; c++) {

            cout << "Introduzca un valor para la coordenada (" << f << ", " << c << "): ";
            cin >> value;

            matriz[f][c] = value;
        }
    }  

    return matriz;
}

Matriz2D_2 CopiaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) {
    Matriz2D_2 matriznueva = CreaMatriz2D_2 (fils, cols);
 
    for (int f=0; f<fils; f++) {
        for (int c=0; c<cols; c++) {
 			matriznueva[f][c] = matriz[f][c];
        }
    }

    return matriznueva;
}

Matriz2D_2 SubMatriz2D_2 (Matriz2D_2 matriz, int fil_desde, int col_desde, int fil_hasta, int col_hasta) {
    int fils = fil_hasta - fil_desde;
    int cols = col_hasta - col_desde;
 
    Matriz2D_2 matriznueva = CreaMatriz2D_2 (fils, cols);

    for (int f=0; f<fils; f++) {
        for (int c=0; c<cols; c++) {
            matriznueva[f][c] = matriz[f + fil_desde][c + col_desde];
        }
    }

    return matriznueva;
}

Matriz2D_2 EliminaFilaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int filaborrar) {
    Matriz2D_2 matriznueva = CreaMatriz2D_2 (fils - 1, cols);

    if (filaborrar < fils) {
        for (int f=0, f2=0; f<fils - 1; f++, f2++) {
            if (f == filaborrar) {
                f2++;
            }
            for (int c=0; c<cols; c++) {
                matriznueva[f][c] = matriz[f2][c];
            }
        }
    }
 
    return matriznueva;
}
 
Matriz2D_2 EliminaColumnaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int columnaborrar) {
    Matriz2D_2 matriznueva = CreaMatriz2D_2 (fils, cols - 1);
 
    if (columnaborrar < cols) {
        for (int f=0; f<fils; f++) {
            for (int c=0, c2=0; c<cols - 1; c++, c2++) {
                if (c == columnaborrar) {
                    c2++;
                }
                matriznueva[f][c] = matriz[f][c2];
            }
        }
    }
 
    return matriznueva;
}

Matriz2D_2 TraspuestaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) {
    Matriz2D_2 matriznueva = CreaMatriz2D_2 (cols, fils);
 
    for (int f=0; f<cols; f++) {
        for (int c=0; c<fils; c++) {
            matriznueva[f][c] = matriz[c][f];
        }
    }
 
    return matriznueva;
}

Matriz2D_2 InvierteMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) {
    Matriz2D_2 matriznueva = CreaMatriz2D_2 (fils, cols);

    for (int f1=0,f2=fils-1; f1<fils; f1++,f2--) {
        for (int c=0; c<cols; c++) {
            matriznueva[f1][c] = matriz[f2][c];
        }
    }

    return matriznueva;
}

Matriz2D_1 InvierteMatriz2D_2_a_1 (Matriz2D_2 matriz, int fils, int cols) { 
    Matriz2D_1 matriznueva = CreaMatriz2D_1 (fils, cols);
 
    for (int f=0; f<fils; f++) {
        for (int c=0; c<cols; c++) {
            matriznueva[f][c] = matriz[f][c];
        }
    }

    return matriznueva;
}

Matriz2D_2 InvierteMatriz2D_1_a_2 (Matriz2D_1 matriz, int fils, int cols) { 
    Matriz2D_2 matriznueva = CreaMatriz2D_2 (fils, cols);
 
    for (int f=0; f<fils; f++) {
        for (int c=0; c<cols; c++) {
            matriznueva[f][c] = matriz[f][c];
        }
    }
    
    return matriznueva;
}
