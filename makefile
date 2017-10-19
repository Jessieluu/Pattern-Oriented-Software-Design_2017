all: hw3
 
hw3: mainAtom.o

ifeq (${OS}, Windows_NT)
	g++ -o hw3 mainAtom.o -lgtest
else
	g++ -o hw3 mainAtom.o -lgtest -lpthread
endif

mainAtom.o: mainAtom.cpp utVariable.h utStruct.h 
	g++ -std=gnu++0x -c mainAtom.cpp

clean:
	rm -f *.o hw3 utStruct utVariable
stat:
	wc *.h *.cpp
