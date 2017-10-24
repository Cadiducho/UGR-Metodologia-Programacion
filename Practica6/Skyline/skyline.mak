BIN=bin
SRC=src
CPP=g++ -std=c++11
EXE=Skyline
SRCFILES=$(SRC)/main.cpp $(SRC)/Skyline.cpp
INCFILES=$(SRC)/Skyline.h

all: dir $(EXE)

clean:
	rm -r $(BIN)
	
mrproper: clean

dir:
	mkdir $(BIN)
	
$(EXE): $(SRCFILES) $(INCFILES)
	$(CPP) -o $(BIN)/$(EXE) $(SRCFILES)