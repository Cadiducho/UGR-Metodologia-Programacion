#ifndef MATRIZ2D_2
#define MATRIZ2D_2
 
#include "Matriz2D-1.h"
 
typedef int ** Matriz2D_2;
 
Matriz2D_2 AleatorizaMatriz2D_2(int fils, int cols, int modulo);
Matriz2D_2 CreaMatriz2D_2   (int fils, int cols);
void LiberaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols);
void PintaMatriz2D_2  (Matriz2D_2 matriz, int fils, int cols);
 
Matriz2D_2 LlenarMatriz2D_2(Matriz2D_2 matriz, int fils, int cols);
Matriz2D_2 CopiaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols);
Matriz2D_2 SubMatriz2D_2 (Matriz2D_2 matriz, int fil_desde, int col_desde, int fil_hasta, int col_hasta);
 
Matriz2D_2 EliminaFilaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int filaborrar);
Matriz2D_2 EliminaColumnaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int columnaborrar);
Matriz2D_2 TraspuestaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols);
Matriz2D_2 InvierteMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols);
 
Matriz2D_1 InvierteMatriz2D_2_a_1 (Matriz2D_2 matriz, int fils, int cols);
Matriz2D_2 InvierteMatriz2D_1_a_2 (Matriz2D_1 matriz, int fils, int cols); 

#endif
