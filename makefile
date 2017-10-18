all: hw3
 
hw3: mainAtom.o

ifeq (${OS}, Windows_NT)
	g++ -o hw3 mainAtom.o -lgtest
else
	g++ -o hw3 mainAtom.o -lgtest -lpthread
endif

mainAtom.o: mainAtom.cpp term.h utAtom.h atom.h utVariable.h variable.h utStruct.h struct.h number.h 
	g++ -std=gnu++0x -c mainAtom.cpp

# utVariable: mainVariable.o
# 	g++ -o utVariable mainVariable.o  -lgtest -lpthread
# mainVariable.o: mainVariable.cpp utVariable.h variable.h
# 	g++ -std=c++11 -c mainVariable.cpp

# utStruct: mainStruct.o
# 	g++ -o utStruct mainStruct.o  -lgtest -lpthread
# mainStruct.o: mainStruct.cpp utStruct.h struct.h
# 	g++ -std=c++11 -c mainStruct.cpp


clean:
	rm -f *.o hw3 utAtom utStruct utVariable
stat:
	wc *.h *.cpp
