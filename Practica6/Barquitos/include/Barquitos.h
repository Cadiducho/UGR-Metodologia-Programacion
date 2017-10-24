#ifndef BARQUITOS_H
#define BARQUITOS_H

const int WATER = 9;
enum Direction {
	HORIZONTAL,
	VERTICAL
};

class Barquitos {
	private:
		int filas;
		int columnas;
		int ** matrix;
		
		void PideMemoria(const int &fils, const int &cols);
		void LiberaMemoria();
		void Copia(const Barquitos &otro);
	public:
		Barquitos(int fil, int col);
		Barquitos(const Barquitos &otra);
		
		/**
		 * Devolver true si se ha puesto el barco correctamente
		 */
		bool setShip(int x, int y, int boatId, Direction direction);
		
		/**
		 * True o false si es agua dicha casilla
		 */
		bool isWater(int x, int y);
		
		/**
		 * Método de disparar. True si has acertado el disparo
		 */
		bool shot(int x, int y);
		
		/**
		 * Pintar toda el array
		 */
		void rawPrint();
		
		/**
		 * Pintar el mapa explorado, lo demás oculto
		 */
		void print();
		 
		Barquitos& operator=(const Barquitos &bar);
		
		~Barquitos();
};

#endif
