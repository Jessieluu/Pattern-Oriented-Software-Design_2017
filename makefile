all: hw3

# hw3: utAtom
# ifeq (${OS}, Windows_NT)
# 	g++ -o hw3 mainAtom.o mainVariable.o mainStruct.o -lgtest
# else
# 	g++ -o hw3 mainAtom.o mainVariable.o mainStruct.o -lgtest -lpthread
# endif
 
hw3: mainAtom.o
	g++ -o hw3 mainAtom.o -lgtest -lpthread
mainAtom.o: mainAtom.cpp utAtom.h atom.h utVariable.h variable.h utStruct.h struct.h number.h
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
