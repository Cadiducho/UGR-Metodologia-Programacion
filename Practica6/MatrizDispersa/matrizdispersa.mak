BIN=bin
SRC=src
CPP=g++ -std=c++11
EXE=MatrizDispersa
SRCFILES=$(SRC)/main.cpp $(SRC)/Valor.cpp $(SRC)/MatrizDispersa.cpp
INCFILES=$(SRC)/Valor.h $(SRC)/MatrizDispersa.h

all: dir $(EXE)

clean:
	rm -r $(BIN)
	
mrproper: clean

dir:
	mkdir $(BIN)
	
$(EXE): $(SRCFILES) $(INCFILES)
	$(CPP) -o $(BIN)/$(EXE) $(SRCFILES)