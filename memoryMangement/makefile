#CC=gcc
CC=g++
#CCFLAG=-std=c99
CCFLAG=-std=c++11
CCFLAG += -g
all: main standAlone
main: memoryMain.o memory.o
	$(CC) $(CCFLAG) -o memory memory.o memoryMain.o
main.o: memoryMain.cpp
	$(CC) -c memoryMain.cpp
memory.o: memory.h memory.cpp
	$(CC) -c memory.h memory.cpp
standAlone: dynamicMemory.cpp
	$(CC) $(CCFLAG) -o dynamicMemory dynamicMemory.cpp
.PHONY: clean
clean:
	rm *.o  *.gch memory dynamicMemory
