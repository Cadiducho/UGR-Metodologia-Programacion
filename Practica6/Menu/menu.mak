BIN=bin
SRC=src
CPP=g++ -std=c++11 -Wno-write-strings
EXE=Menu
SRCFILES=$(SRC)/main.cpp $(SRC)/Menu.cpp
INCFILES=$(SRC)/Menu.h

all: dir $(EXE)

clean:
	rm -r $(BIN)
	
mrproper: clean

dir:
	mkdir $(BIN)
	
$(EXE): $(SRCFILES) $(INCFILES)
	$(CPP) -o $(BIN)/$(EXE) $(SRCFILES)