#ifndef SKYLINE_H
#define SKYLINE_H

class Skyline {
	private :
		double * abscisas ; // array de abscisas
		double * alturas ; // array de alturas (> 0, la ultima sera 0)
		int num; // tam. de los arrays anteriores
		
		void PideMemoria(const int &longitud);
		void LiberaMemoria();
		void Copia(const Skyline& otra);
	public:
		Skyline();
		Skyline(const Skyline& otra);
		Skyline& operator=(const Skyline &otra);
		Skyline(double & abcisaInicio, double & abcisaFinal, double & altura);
		Skyline(double * abscisas, double * alturas, int & n);
		~Skyline();
		
		void print();
};

#endif
