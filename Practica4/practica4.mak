BIN=bin
SRC=src

all: dir 01_RedimensionarArrayDinamico 02_Calificaciones_ArrayDinamicoStruct_ordenado

clean:
	rm -r $(BIN)
	
mrproper: clean

dir:
	mkdir $(BIN)
	
01_RedimensionarArrayDinamico: $(SRC)/01_RedimensionarArrayDinamico.cpp $(SRC)/01_RedimensionarArrayDinamico.h
	g++ -o $(BIN)/01_RedimensionarArrayDinamico $(SRC)/01_RedimensionarArrayDinamico.cpp
	
02_Calificaciones_ArrayDinamicoStruct_ordenado: $(SRC)/02_Calificaciones_ArrayDinamicoStruct_ordenado.cpp $(SRC)/02_Calificaciones_ArrayDinamicoStruct_ordenado.h
	g++ -o $(BIN)/02_Calificaciones_ArrayDinamicoStruct_ordenado $(SRC)/02_Calificaciones_ArrayDinamicoStruct_ordenado.cpp