#ifndef MENU_H
#define MENU_H

class Menu {
	private:
		char * titulo; // Titulo general del menu
		char ** opc; // Cadenas de longitud variable que describen cada una de las opciones
		int nopc; // Numero de opciones en el menú
		
		void LiberaMemoria();
		void Copia(const Menu& otro);
		void PideMemoria(const int &longitud);
		void IncrementaMemoria();
	public:
		Menu();
		Menu(const Menu& otro);
		~Menu();
		Menu& operator=(const Menu &otro);
		
		void setTitulo(char * titulo);
		int getNumeroOpciones() const;
		void agregarOpcion(char * opcion);
		void print();
};

#endif
