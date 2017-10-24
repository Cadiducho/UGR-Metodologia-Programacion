BIN=bin
SRC=src

all: dir Main-1D Main-2D

clean:
	rm -r $(BIN)
	
mrproper: clean

dir:
	mkdir $(BIN)
	
Main-1D: $(SRC)/Main-1D.cpp $(SRC)/Matriz2D-1.cpp $(SRC)/Matriz2D-1.h
	g++ -o $(BIN)/Main-1D $(SRC)/Main-1D.cpp $(SRC)/Matriz2D-1.cpp
	
Main-2D: $(SRC)/Main-2D.cpp $(SRC)/Matriz2D-1.cpp $(SRC)/Matriz2D-1.h $(SRC)/Matriz2D-2.cpp $(SRC)/Matriz2D-2.h
	g++ -o $(BIN)/Main-2D $(SRC)/Main-2D.cpp $(SRC)/Matriz2D-1.cpp $(SRC)/Matriz2D-2.cpp