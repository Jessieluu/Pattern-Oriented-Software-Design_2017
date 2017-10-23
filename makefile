all: hw4
 
hw4: main.o Atom.o

ifeq (${OS}, Windows_NT)
	g++ -o hw4 main.o Atom.o -lgtest
else
	g++ -o hw4 main.o Atom.o -lgtest -lpthread
endif

main.o: main.cpp list.h struct.h number.h
	g++ -std=gnu++0x -c main.cpp
Atom.o: Atom.cpp atom.h variable.h
	g++ -std=gnu++0x -c Atom.cpp

clean:
	rm -f *.o hw4
stat:
	wc *.h *.cpp
