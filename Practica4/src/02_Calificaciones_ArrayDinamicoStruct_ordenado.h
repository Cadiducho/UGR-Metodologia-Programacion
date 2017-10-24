#ifndef CALIFICACIONES_ORDENADO_H
#define CALIFICACIONES_ORDENADO_H

const int NUM_NOTAS = 4;
const int TAM_NOMBRE = 100;
const int TAMANIO = 100;

struct RegAlumno {
	char * DNI;
	char * apellido_nombre;
	double * notas;
};

//Lee los pesos de las calificaciones y los guarda en el vector de pesos.
void LeePesos(double * ponderaciones, int num_pesos);

//Comprueba la validez de los pesos leidos: deben sumar 100.0.
bool CorrectosPesos(double * ponderaciones, int num_pesos);

//Muestra los pesos leídos para las ponderaciones de las calificaciones.
void MuestraPesos(double * ponderaciones, int num_pesos);

//Lee los datos de los alumnos y los guarda en un vector.
int LeerAlumnos(RegAlumno * datos, int num_casillas);

//Calcula las calificaciones medias de los alumnos.
void CalculaCalificacionesMedias(double * medias, RegAlumno *datos, int num_alumnos, double * ponderaciones, int num_notas);

//Mostrar la lista de los alumnos con todas las calificaciones y su media.
void MuestraVectorAlumnos(RegAlumno *datos, double * medias, int num_alumnos, int min, int max);

//Ordenar el vector de datos de alumnos en base a la nota media.
void OrdenaVectorAlumnos(RegAlumno *datos, double *medias, int num_alumnos);

#endif
