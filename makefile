INC_DIR = include

all: hw2

hw2: main.o Atom.o Number.o Variable.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 main.o Atom.o Number.o Variable.o -lgtest
else
	g++ -o hw2 main.o Atom.o Number.o Variable.o -lgtest -lpthread
endif

main.o: main.cpp utTerm.h 
	g++ -std=c++11 -c main.cpp
Atom.o: $(INC_DIR)/atom.h Atom.cpp
	g++ -std=c++11 -c Atom.cpp
Number.o: $(INC_DIR)/number.h Number.cpp
	g++ -std=c++11 -c Number.cpp
Variable.o: $(INC_DIR)/variable.h Variable.cpp
	g++ -std=c++11 -c Variable.cpp


clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif


