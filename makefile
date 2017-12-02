all: hw7
 
hw7: main.o Atom.o List.o Struct.o

ifeq (${OS}, Windows_NT)
	g++ -o hw7 main.o Atom.o List.o Struct.o -lgtest
else
	g++ -o hw7 main.o Atom.o List.o Struct.o -lgtest -lpthread
endif

main.o: main.cpp number.h variable.h term.h global.h parser.h node.h
	g++ -std=gnu++0x -c main.cpp

Atom.o: Atom.cpp atom.h 
	g++ -std=gnu++0x -c Atom.cpp

List.o: List.cpp list.h 
	g++ -std=gnu++0x -c List.cpp

Struct.o: Struct.cpp struct.h 
	g++ -std=gnu++0x -c Struct.cpp	

clean:
	rm -f *.o hw7
stat:
	wc *.h *.cpp
