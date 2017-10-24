BIN=bin
SRC=src
CPP=g++ -g -std=c++11
EXE=BigInt
SRCFILES=$(SRC)/main.cpp $(SRC)/BigInt.cpp
INCFILES=$(SRC)/BigInt.h

all: dir $(EXE)

clean:
	rm -r $(BIN)
	
mrproper: clean

dir:
	mkdir $(BIN)
	
$(EXE): $(SRCFILES) $(INCFILES)
	$(CPP) -o $(BIN)/$(EXE) $(SRCFILES)