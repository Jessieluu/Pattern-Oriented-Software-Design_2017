all: hw3

# hw3: utAtom
# ifeq (${OS}, Windows_NT)
# 	g++ -o hw3 mainAtom.o mainStruct.o -lgtest
# else
# 	g++ -o hw3 mainAtom.o mainStruct.o -lgtest -lpthread
# endif

hw3: mainAtom.o
	g++ -o hw3 mainAtom.o -lgtest -lpthread
mainAtom.o: mainAtom.cpp utAtom.h atom.h utVariable.h variable.h #utStruct.h struct.h number.h
	g++ -std=c++11 -c mainAtom.cpp

# utVariable: mainVariable.o
# 	g++ -o utVariable mainVariable.o  -lgtest -lpthread
# mainVariable.o: mainVariable.cpp utVariable.h variable.h
# 	g++ -std=c++11 -c mainVariable.cpp

# utStruct: mainStruct.o
# 	g++ -o utStruct mainStruct.o  -lgtest -lpthread
# mainStruct.o: mainStruct.cpp utStruct.h struct.h
# 	g++ -std=c++11 -c mainStruct.cpp

#exp: mainExp.o
#	g++ -o exp mainExp.o -lgtest -lpthread
#mainExp.o: mainExp.cpp exp.h global.h
#	g++ -std=c++11 -c mainExp.cpp

#utScannerParser: mainScannerParser.o term.o struct.o var.o list.o
#	g++ -o utScannerParser mainScannerParser.o term.o var.o struct.o list.o -lgtest -lpthread
#mainScannerParser.o: mainScannerParser.cpp utScanner.h utParser.h scanner.h parser.h term.h var.h struct.h list.h global.h node.h
#		g++ -std=c++11 -c mainScannerParser.cpp

#utTerm: mainTerm.o term.o struct.o var.o list.o
#	g++ -o utTerm mainTerm.o term.o var.o struct.o list.o -lgtest -lpthread
#mainTerm.o: mainTerm.cpp utTerm.h term.h var.h utStruct.h struct.h list.h utList.h
#	g++ -std=c++11 -c mainTerm.cpp
#term.o: term.h term.cpp
#	g++ -std=c++11 -c term.cpp
#struct.o: struct.h struct.cpp
#	g++ -std=c++11 -c struct.cpp
#var.o: var.h var.cpp
#g++ -std=c++11 -c var.cpp
#list.o: list.h list.cpp term.h var.h
#	g++ -std=c++11 -c list.cpp
clean:
	rm -f *.o hw3
stat:
	wc *.h *.cpp
