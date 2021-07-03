CC=g++
CCFLAG += -g
CCFLAG += -std=c++11
all: main
main: main.o pointers.o testPointers.o
	$(CC) $(CCFLAG) -o kindOfPointer  main.o testPointers.o 
main.o: main.cpp
	$(CC) -c main.cpp
testPointers.o: testPointers.h testPointers.cpp
	$(CC) -c testPointers.h testPointers.cpp	
pointers.o: pointers.h
	$(CC) -c pointers.h
.PHONY: clean
clean:
	rm -f *.o  *.gch kindOfPointer
