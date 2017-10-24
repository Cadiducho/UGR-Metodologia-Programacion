BIN=bin
SRC=src
OBJ=obj
INC=include
CPP=g++ -std=c++11
EXE=Barquitos
SRCFILES=$(SRC)/main.cpp $(SRC)/Barquitos.cpp
INCFILES=$(SRC)/Barquitos.h

all: dir $(EXE)

clean:
	rm -r $(BIN)
	
mrproper: clean

dir:
	mkdir $(BIN) $(OBJ)
	
#$(EXE): $(SRCFILES) $(INCFILES)
#	$(CPP) -o $(BIN)/$(EXE) $(SRCFILES)
	
Barquitos: $(OBJ)/main.o $(OBJ)/Barquitos.o
	$(CPP) $(OBJ)/main.o $(OBJ)/Barquitos.o -o $(BIN)/Barquitos
	
obj/main.o: $(SRC)/main.cpp $(INC)/Barquitos.h
	$(CPP) -c -g -Iinclude $(SRC)/main.cpp -o $(OBJ)/main.o

obj/Barquitos.o: $(SRC)/Barquitos.cpp $(INC)/Barquitos.h
	$(CPP) -c -g -Include $(SRC)/Barquitos.cpp -o $(OBJ)/Barquitos.o