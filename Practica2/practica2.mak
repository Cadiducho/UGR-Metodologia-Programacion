BIN=bin
SRC=src

all: dir PosicionPrimerBlanco SaltarPrimeraPalabra DemosCadenasClasicas

clean:
	rm -r $(BIN)
	
mrproper: clean

dir:
	mkdir $(BIN)
	
PosicionPrimerBlanco: $(SRC)/PosicionPrimerBlanco.cpp
	g++ -o $(BIN)/PosicionPrimerBlanco $(SRC)/PosicionPrimerBlanco.cpp
	
SaltarPrimeraPalabra: $(SRC)/SaltaPrimeraPalabra.cpp
	g++ -o $(BIN)/SaltaPrimeraPalabra $(SRC)/SaltaPrimeraPalabra.cpp
	
DemosCadenasClasicas: $(SRC)/DemosCadenasClasicas.cpp $(SRC)/MiCadenaClasica.cpp $(SRC)/MiCadenaClasica.h
	g++ -o $(BIN)/DemosCadenasClasicas $(SRC)/DemosCadenasClasicas.cpp $(SRC)/MiCadenaClasica.cpp