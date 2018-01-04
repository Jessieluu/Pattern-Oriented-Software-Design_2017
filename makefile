all: hw8 shell

hw8: main.o atom.o struct.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o hw8 main.o atom.o struct.o list.o -lgtest
else
	g++ -o hw8 main.o atom.o struct.o list.o -lgtest -lpthread
endif

shell: shell.o atom.o struct.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o shell atom.o struct.o list.o shell.o -lgtest
else
	g++ -o shell atom.o struct.o list.o shell.o -lgtest -lpthread
endif

main.o: main.cpp expression.h variable.h parser.h scanner.h exp.h global.h iterator.h
	g++ --std=gnu++0x -c main.cpp
atom.o: atom.cpp atom.h
	g++ --std=gnu++0x -c atom.cpp
struct.o: struct.cpp struct.h
	g++ --std=gnu++0x -c struct.cpp
list.o: list.cpp list.h
	g++ --std=gnu++0x -c list.cpp
shell.o: shell.cpp expression.h variable.h parser.h scanner.h exp.h global.h iterator.h
	g++ --std=gnu++0x -c shell.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw8 shell
endif
