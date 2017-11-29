all: hw6
 
hw6: main.o Atom.o

ifeq (${OS}, Windows_NT)
	g++ -o hw6 main.o Atom.o -lgtest
else
	g++ -o hw6 main.o Atom.o -lgtest -lpthread
endif

main.o: main.cpp number.h variable.h term.h list.h struct.h global.h parser.h node.h
	g++ -std=gnu++0x -c main.cpp
Atom.o: Atom.cpp atom.h 
	g++ -std=gnu++0x -c Atom.cpp

clean:
	rm -f *.o hw6
stat:
	wc *.h *.cpp
