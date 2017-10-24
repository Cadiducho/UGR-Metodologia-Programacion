BIN=bin
SRC=src
CPP=g++ -std=c++11
EXE=Polilinea
SRCFILES=$(SRC)/main.cpp $(SRC)/Punto.cpp $(SRC)/Polilinea.cpp
INCFILES=$(SRC)/Punto.h $(SRC)/Polilinea.h

all: dir $(EXE)

clean:
	rm -r $(BIN)
	
mrproper: clean

dir:
	mkdir $(BIN)
	
$(EXE): $(SRCFILES) $(INCFILES)
	$(CPP) -o $(BIN)/$(EXE) $(SRCFILES)