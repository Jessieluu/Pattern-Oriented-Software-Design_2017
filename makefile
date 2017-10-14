all: hw2

hw2: main.o Atom.o Number.o Variable.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 main.o Atom.o Number.o Variable.o -lgtest
else
	g++ -o hw2 main.o Atom.o Number.o Variable.o -lgtest -lpthread
endif

main.o: main.cpp utTerm.h 
	g++ -std=gnu++0x -c main.cpp
Atom.o: atom.h Atom.cpp
	g++ -std=gnu++0x -c Atom.cpp
Number.o: number.h Number.cpp
	g++ -std=gnu++0x -c Number.cpp
Variable.o: variable.h Variable.cpp
	g++ -std=gnu++0x -c Variable.cpp


clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif


