#ifndef MATRIZ2D_1
#define MATRIZ2D_1

typedef int ** Matriz2D_1;

Matriz2D_1 AleatorizaMatriz2D_1(int fils, int cols, int modulo);
Matriz2D_1 CreaMatriz2D_1(int fils, int cols);
void LiberaMatriz2D_1(Matriz2D_1 matriz, int fils, int cols);
void PintaMatriz2D_1(Matriz2D_1 matriz, int fils, int cols);

Matriz2D_1 LlenarMatriz2D_1(Matriz2D_1 matriz, int fils, int cols);
Matriz2D_1 CopiaMatriz2D_1(Matriz2D_1 matriz, int fils, int cols);
Matriz2D_1 SubMatriz2D_1(Matriz2D_1 matriz, int fil_desde, int col_desde, int fil_hasta, int col_hasta);

Matriz2D_1 EliminaFilaMatriz2D_1(Matriz2D_1 matriz, int fils, int cols, int filaborrar);
Matriz2D_1 EliminaColumnaMatriz2D_1(Matriz2D_1 matriz, int fils, int cols, int columnaborrar);
Matriz2D_1 TraspuestaMatriz2D_1(Matriz2D_1 matriz, int fils, int cols);
Matriz2D_1 InvierteMatriz2D_1(Matriz2D_1 matriz, int fils, int cols);

#endif
