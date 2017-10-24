BIN=bin
SRC=src
CPP=g++ -std=c++11
EXE=Precuencias
SRCFILES=$(SRC)/main.cpp $(SRC)/Pareja.cpp $(SRC)/Precuencias.cpp
INCFILES=$(SRC)/Pareja.h $(SRC)/Precuencias.h

all: dir $(EXE)

clean:
	rm -r $(BIN)
	
mrproper: clean

dir:
	mkdir $(BIN)
	
$(EXE): $(SRCFILES) $(INCFILES)
	$(CPP) -o $(BIN)/$(EXE) $(SRCFILES)