BIN=bin
SRC=src
CPP=g++ -std=c++11
EXE=ListaCelda
SRCFILES=$(SRC)/main.cpp $(SRC)/Celda.cpp $(SRC)/Lista.cpp
INCFILES=$(SRC)/Celda.h $(SRC)/Lista.h

all: dir $(EXE)

clean:
	rm -r $(BIN)
	
mrproper: clean

dir:
	mkdir $(BIN)
	
$(EXE): $(SRCFILES) $(INCFILES)
	$(CPP) -o $(BIN)/$(EXE) $(SRCFILES)