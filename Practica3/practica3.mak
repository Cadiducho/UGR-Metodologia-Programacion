BIN=bin
SRC=src

all: dir 16_PosMayor 17_Ordena 18_Calificaciones_ArrayStruct 19_Calificaciones_ArrayStruct_Ordenado

clean:
	rm -r $(BIN)
	
mrproper: clean

dir:
	mkdir $(BIN)
	
16_PosMayor: $(SRC)/16_PosMayor.cpp $(SRC)/16_PosMayor.h
	g++ -o $(BIN)/16_PosMayor $(SRC)/16_PosMayor.cpp
	
17_Ordena: $(SRC)/17_Ordena.cpp $(SRC)/17_Ordena.h
	g++ -o $(BIN)/17_Ordena $(SRC)/17_Ordena.cpp
	
18_Calificaciones_ArrayStruct: $(SRC)/18_Calificaciones_ArrayStruct.cpp
	g++ -o $(BIN)/18_Calificaciones_ArrayStruct $(SRC)/18_Calificaciones_ArrayStruct.cpp
	
19_Calificaciones_ArrayStruct_Ordenado: $(SRC)/19_Calificaciones_ArrayStruct_Ordenado.cpp $(SRC)/19_Calificaciones_ArrayStruct_Ordenado.h
	g++ -o $(BIN)/19_Calificaciones_ArrayStruct_Ordenado $(SRC)/19_Calificaciones_ArrayStruct_Ordenado.cpp